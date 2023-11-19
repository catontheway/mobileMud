// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";
string query_name() { return " 降龙"ZJBR"无悔 "; }
#define HUI "「" HIR "降龙无悔" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon2;
	int damage,damage1,ap,dp;
	string *circle,msg;

	if (! target) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail(HUI "只能对战斗中的对手使用。\n");
	if (me->is_busy()) 
		return notify_fail("你现在正忙着呢！\n");
	if (objectp(me->query_temp("weapon")) || objectp(me->query_temp("secondary_weapon")))
		return notify_fail(HUI "只能空手使用。\n");			
	
	if ((int)me->query_skill("force",1) < 300)
		return notify_fail("你内功修为不够，难以施展" HUI "。\n");
	if ((int)me->query("max_neili") < 5000)
		return notify_fail("你内力修为不够，难以施展" HUI "。\n");
	if ((int)me->query("max_jingli") < 5000)
		return notify_fail("你精力修为不够，难以施展" HUI "。\n");			
	if ((int)me->query_skill("xianglong-zhang", 1) < 300)
		return notify_fail("你降龙十八掌火候不够，难以施展" HUI "。\n");
	if (me->query_skill_mapped("unarmed") != "xianglong-zhang")
		return notify_fail("你没有激发降龙十八掌，难以施展" HUI "。\n");
	if ((int)me->query_skill("huntian-qigong",1) < 300)
		return notify_fail("你的混天气功修为不够。\n");
	if ((int)me->query_skill("xiaoyaoyou",1) < 300)
		return notify_fail("你的逍遥游修为不够。\n");			
	if ( !wizardp(me) && me->query_skill_mapped("force") != "huntian-qigong")
		return notify_fail("不使用本门内功，如何使用本门绝学!\n");       
	if ((int)me->query("neili") < 5000)
		return notify_fail("你现在真气不够，难以施展" HUI "。\n");
	if ((int)me->query("jingli") < 5000)
		return notify_fail("你现在精力不够，难以施展" HUI "。\n");
	if (target && !living(target))
		return notify_fail("对方都已经这样了，用不着这么费力吧？\n");
	if (me->query_temp("autolian"))
		return notify_fail("你正在发动自动连招！\n"); 	
	if ( me->query_temp("cooldown") )	//CD写法	2017.9.7添加
		return notify_fail("你处于技能冷却状态中，过会在使用吧。\n");
		
	message_vision(HBWHT "$N贯通丐帮武学，使出了丐帮的绝学之精髓！\n" NOR, me,target);
	me->set_temp("cooldown", 1);	//CD写法	2017.9.7添加
	call_out("del_cooldown", 5, me);	//CD写法1
	ap = me->query("xyzx_sys/level") + me->query_skill("xianglong-zhang", 1)+me->query_skill("huntian-qigong",1) + me->query_skill("unarmed") + me->query_skill("force");
	dp = target->query("xyzx_sys/level") + target->query_skill("dodge") + target->query_skill("parry");
	ap = ap*((int)me->query("breakup")+(int)me->query("breakup")*(int)me->query("breakup")+100)/100;
	dp = dp*((int)target->query("breakup")+(int)target->query("breakup")*(int)target->query("breakup")+100)/100;
        // 第一掌      
        message_vision(HIW "\n忽然间$N" HIW "身形激进，左手一划，右手呼的一掌，便"
                     "向$n" HIW "击去，正是降龙十八掌「" NOR + HIY "潜龙勿用" NOR
                     + HIW "」一招，力自掌生之际说到便到，以排山倒海之势向$n" HIW
                     "狂涌而去，当真石破天惊，威力无比。\n" NOR, me, target);
        if (random(ap) > dp/3)
        {
                damage1 = me->query("xyzx_sys/level") + me->query_skill("xianglong-zhang", 1)+me->query_skill("huntian-qigong",1) + me->query_skill("unarmed") + me->query_skill("force");
				damage = damage1/3 + random(damage1/3);
				damage = damage*(100-target->query_meridian())/100;
				target->receive_damage("qi",damage,me);
				target->receive_wound("qi",damage/2,me);
				me->add("neili", -1000);
				me->add("jingli", -1000);
                msg =HIR "$p" HIR "一楞，只见$P" HIR "身形一闪，已晃至自己跟前，躲闪不及，被击个正中。\n" NOR;
                message_vision(msg, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//				if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
        } else
        {
                msg = HIC "$p" HIC "气贯双臂，凝神应对，游刃有余，$P"
                      HIC "掌力如泥牛入海，尽数卸去。\n" NOR;
                message_vision(msg, me, target);
				me->add("neili", -500);
        }

        // 第二掌
if ((int)me->query_skill("xianglong-zhang", 1) > 500 && (int)me->query_skill("xiaoyaoyou", 1) > 500)
{
        message_vision(HIW "\n$N" HIW "一掌既出，身子已然抢到离$n" HIW "三四丈之外"
                     "，后掌推前掌，两股掌力道合并，又是一招「" NOR + HIY "见龙在田" NOR 
					 + HIW "」攻出，掌力犹如怒潮狂涌，势不可当。霎时$n"
                     HIW "便觉气息窒滞，立足不稳。\n" NOR, me, target);
        if (random(ap) > dp/3)
        {
                damage1 = me->query("xyzx_sys/level") + me->query_skill("xianglong-zhang", 1)+me->query_skill("huntian-qigong",1) + me->query_skill("unarmed") + me->query_skill("force");
				damage = damage1/3 + random(damage1/3);
				damage = damage*(100-target->query_meridian())/100;
                target->receive_damage("qi",damage,me);
                target->receive_wound("qi",damage/2,me);
				me->add("neili", -2000);
				me->add("jingli", -2000);
                msg =HIR "只听$p" HIR "一声惨嚎，被$P" HIR"一掌击中胸前，“喀嚓喀嚓”断了几根肋骨。\n" NOR;
                message_vision(msg, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//				if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
        } else
        {
                msg = HIC "$p" HIC "气贯双臂，凝神应对，游刃有余，$P"
                      HIC "掌力如泥牛入海，尽数卸去。\n" NOR;
                message_vision(msg, me, target);
				me->add("neili", -500);
        }
}
        // 第三掌
if ((int)me->query_skill("xianglong-zhang", 1) > 800 && (int)me->query_skill("xiaoyaoyou", 1) > 800)
{	
        message_vision(HIW "\n紧跟着$N" HIW "一声暴喝，右掌斜斜挥出，前招掌力未消"
                     "，此招掌力又到，竟然又攻出一招「" NOR + HIY "亢龙有悔" NOR
                     + HIW "」，掌夹风势，势如破竹，便如一堵无形气墙，向前疾冲而"
                     "去。$n" HIW "只觉气血翻涌，气息沉浊。\n" NOR, me, target);
		if (me->query("jm/gaibang")) damage1 = me->query_skill("xianglong-zhang", 1)*me->query("str",1)*3/2 + me->query_skill("huntian-qigong", 1) + me->query_skill("unarmed", 1) + me->query_skill("force", 1);
		else damage1 = me->query_skill("xianglong-zhang", 1)*me->query("str",1) + me->query_skill("huntian-qigong", 1) + me->query_skill("unarmed", 1) + me->query_skill("force", 1);
       if (random(ap) > dp/3)
        {                
				damage = damage1/5 + random(damage1/5);
				damage = damage*(100-target->query_meridian())/100;
                target->receive_damage("qi",damage,me);
                target->receive_wound("qi",damage/2,me);
                me->add("neili", -2000);
				me->add("jingli", -2000);				
                msg =HIR "结果$p" HIR "躲闪不及，$P" HIR"的掌劲顿时穿胸而过，“哇”的喷出一大口鲜血。\n" NOR;
                message_vision(msg, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//				if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
        } else
        {
                msg = HIC "$p" HIC "见这招来势凶猛，身形疾退，瞬间飘出三"
                      "丈，脱出$P" HIC "掌力之外。\n" NOR;
                message_vision(msg, me, target);
                me->add("neili", -500);
        }

	if ( objectp(weapon2 = target->query_temp("weapon")))
	{
       msg = HIR "$N" HIR "暴喝一声，全身内劲迸发，气贯右臂奋力外扯，企图将$n"
              HIR "的" + weapon2->name() + HIR "吸入掌中。\n" NOR;
		message_vision(msg, me, target);
        ap = me->query_skill("xianglong-zhang",1) * me->query("str",1) ;
        dp = target->query_skill("force") * target->query("con",1) ;
		damage1 = me->query_skill("xianglong-zhang",1)+me->query_skill("unarmed",1)+me->query_skill("force",1)+me->query_skill("huntian-qigong",1)+target->query_skill("unarmed",1)+target->query_skill("force",1);
		damage = damage1/3 + random(damage1/3);
		damage = damage*(100-target->query_meridian())/100;
       if ( random(ap) > dp/3)
        {
                me->add("neili", -1000);
				me->add("jingli", -1000);
				weapon2->unequip();
                weapon2->move(environment(target));
				target->receive_damage("qi", damage,me);
				target->receive_wound("qi", damage/2,me);				
                msg = HIR "$n" HIR "只觉周围气流涌动，手中" + weapon2->name()+ HIR "竟然拿捏不住，向$N" HIR "掌心脱手飞去。\n" NOR;
				message_vision(msg, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//				if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);				
        } else
        {
                msg = CYN "$n" CYN "只觉周围气流涌动，慌忙中连将手中"
                       + weapon2->name() + CYN "挥舞得密不透风，使得$N"
                       CYN "无从下手。\n" NOR;
				message_vision(msg, me, target);
        }
	} else
	{
        circle = ({
                YEL"$N突然大喝一声，双掌齐出，向$p当胸猛击过去。\n"NOR,
                HIG"$N大步迈出，左手一划，右手呼的一掌，猛向$p击去。\n"NOR
        });

        msg = HIG"\n"+ circle[random(sizeof(circle))] +"\n" NOR;
		message_vision(msg, me, target);	
		damage1 = me->query_skill("xianglong-zhang",1)+me->query_skill("unarmed",1)+me->query_skill("force",1)+me->query_skill("huntian-qigong",1)+target->query_skill("unarmed",1)+target->query_skill("force",1);
		damage = damage1/3 + random(damage1/3);
		damage = damage*(100-target->query_meridian())/100;
        if ( random(ap) > dp/3)
		{
			circle = ({
                HIC"掌力未到，$p已感胸口呼吸不畅，顷刻之间，$N的掌力如怒潮般汹涌而至。"NOR,
                HIM"只一瞬之间，$p便觉气息窒滞，$N掌力竟如怒潮狂涌，势不可当，又如是一堵无形的高墙，向$p身前疾冲。"NOR
			});			
			me->add("neili", -1000);
			me->add("jingli", -1000);
			target->receive_damage("qi", damage,me);
			target->receive_wound("qi", damage/2,me);
			msg = HIG"\n"+ circle[random(sizeof(circle))] +"\n" NOR;			
			message_vision(msg, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//			if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
        } else 
		{
			message_vision(HIC "$n大惊之下，双掌连划三个半圆护住身前，同时足尖着力，飘身后退，避开了$N的一掌。\n" NOR, me, target);
        }
	}		
}

         // 第四掌
if ((int)me->query_skill("xianglong-zhang", 1) > 1200 && (int)me->query_skill("xiaoyaoyou", 1) > 1200)
{	
        message_vision(HIW "\n$N" HIC "身体急转，双掌蓄力缓缓推出，前招掌力未消"
                     "，此招掌力又到，竟然又攻出一招「" NOR + HIB "降龙有悔" NOR
                     + HIW "」，此招极为缓慢，但气势不可阻挡，向前疾冲而"
                     "去。$n" HIW "只觉得无法躲闪，只好硬拼。\n" NOR, me, target);
       if (random(ap) > dp/3)
        {
            if (me->query("jm/gaibang")) damage1 = me->query_skill("xianglong-zhang", 1)*me->query("str",1)*3/2 + me->query_skill("huntian-qigong", 1)*me->query("str",1)*3/2 + me->query_skill("xiaoyaoyou", 1)*me->query("int",1)*3/2 + me->query_skill("unarmed", 1) + me->query_skill("force", 1);
			else damage1 = me->query_skill("xianglong-zhang", 1)*me->query("str",1) + me->query_skill("huntian-qigong", 1)*me->query("str",1) + me->query_skill("xiaoyaoyou", 1)*me->query("int",1) + me->query_skill("unarmed", 1) + me->query_skill("force", 1);
				damage = damage1/3 + random(damage1/3) + target->query("qi")*5/100;
				damage = damage*(100-target->query_meridian())/100;
                target->receive_damage("qi",damage,me);
                target->receive_wound("qi",damage/2,me);
                me->add("neili", -3000);
				me->add("jingli", -3000);				
                msg =HIR "结果$p" HIR "硬拼一掌，$P" HIR"的掌劲顿时穿胸而过，浑身经脉断的七七八八。\n" NOR;
                message_vision(msg, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//				if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);

        } else
        {
				damage1 = me->query_skill("xianglong-zhang", 1)*me->query("str",1) + me->query_skill("huntian-qigong", 1) + me->query_skill("unarmed", 1) + me->query_skill("force", 1);
				damage = damage1/9 + random(damage1/9);
				damage = damage*(100-target->query_meridian())/100;
                target->receive_damage("qi",damage,me);
                target->receive_wound("qi",damage/2,me);
                msg = HIC "$p" HIC "见这招来势凶猛，只好运起全身功力与$P" HIC "硬拼一掌，双方势均力敌，各倒退五步。\n" NOR;
                message_vision(msg, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
				damage = damage1/9 + random(damage1/9);
				damage = damage*(100-me->query_meridian())/100;
                me->receive_damage("qi",damage,target);
                me->receive_wound("qi",damage/3,target);	
                me->add("neili", -500);				
                msg = HIC "$N" HIC "运起全身功力与$n" HIC "硬拼一掌，没想到$N功力深厚，$n被反震的后退五步。\n" NOR;
                message_vision(msg, target, me, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//				if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"，对自己气血的外伤为"+ damage/2 +"，内伤为"+ damage/3 +"。\n" NOR);
        }
		
		message_vision(HIR "$N气聚丹田，双掌自外向里转了个圆圈，缓缓的凝聚全身功力。\n\n" NOR, me,target);	
        msg = WHT "$N" WHT "施出降龙十八掌之「" HIW "排山倒海" NOR +
              WHT "」，全身真气鼓动，双掌如排山倒海般压向$n" WHT "。\n"NOR;  
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);      
        msg = HIY "$N" HIY "深吸一口气，跨前一步，双掌猛然翻滚，"
              "缤纷而出，宛如一条神龙攀蜒于九天之上！\n\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);  
        msg = HIC "$N" HIC "默运内功，施展出" HIY "雷霆一击" NOR "，全身急速转动起来，"
              "越来越快，就\n犹如一股旋风，骤然间，$N" HIC "已卷向正看"
              "得发呆的" HIC "$n。\n"NOR;  
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);  
        msg = YEL  "$N脚下一转，突然欺到$n身前，一式「龙战于野」直拍向$n面门" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW "$N突然飞起，双掌居高临下最后一式「龙啸九天」全力拍向$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		me->add("neili", -1000);
		me->add("jingli", -1000);
}

	me->start_busy(1);
	return 1;
}


void del_cooldown(object me)	//CD写法1
{ 
	if ( !objectp(me) ) return;
	if ( me->query_temp("cooldown") )	
	{
		me->delete_temp("cooldown");
		tell_object(me, HIM"你呼出一口气，缓缓的将内力收回丹田。\n"NOR);
	}	
}