//qixing.c 七星耀日
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
//#include <condition.h>
#include "/kungfu/skill/eff_msg.h";
inherit F_SSERVER;
 string query_name() { return " 七星"ZJBR"耀日 "; }
int perform(object me, object target)
{
	int extra,ap,dp;
	int damage,damage1;
	object weapon,weapon2;

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("只能对战斗中的对手使用。\n");
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	
	if( (int)me->query("max_neili") < 5000  )
		return notify_fail("你的内力修为不够。\n");
	if( (int)me->query("max_jingli") < 2000  )
		return notify_fail("你的精力修为不够。\n");
	if( (int)me->query("neili") < 5000 )
		return notify_fail("你的内力不够。\n");
	if( (int)me->query("jingli") < 5000 )
		return notify_fail("你的精力不够。\n");
	
	if(!wizardp(me) && (int)me->query_skill("quanzhen-jian", 1) < 300 )
		return notify_fail("你的全真剑法不够高!不能贯通使用！\n");
	if(!wizardp(me) && (int)me->query_skill("jinyan-gong", 1) < 300 )
		return notify_fail("你的金雁功不够高!不能贯通使用！\n");
	if( me->query_skill_mapped("force",1) != "xiantian-gong")	
		return notify_fail("不使用本门内功，如何使用本门绝学!\n");
	if (me->query_skill_mapped("sword") != "quanzhen-jian")
		return notify_fail("你没正确激发该技能 。\n");	
	
	if (me->query_temp("autolian"))
		return notify_fail("你正在发动自动连招！\n"); 	
	if ( me->query_temp("cooldown") )	//CD写法	2017.9.7添加
		return notify_fail("你处于技能冷却状态中，过会在使用吧。\n");
		
	extra = (int)me->query_skill("quanzhen-jian",1)/10;		
	ap = me->query("xyzx_sys/level") + me->query_skill("quanzhen-jian", 1) +me->query_skill("jinyan-gong", 1)+ me->query_skill("sword") + me->query_skill("force");
	dp = target->query("xyzx_sys/level") + target->query_skill("dodge") + target->query_skill("parry");
	ap = ap*((int)me->query("breakup")+(int)me->query("breakup")*(int)me->query("breakup")+100)/100;
	dp = dp*((int)target->query("breakup")+(int)target->query("breakup")*(int)target->query("breakup")+100)/100;
	message_vision(HBWHT "$N贯通全真教武学，使出了全真教的绝学之精髓！\n" NOR, me, target);
	message_vision(HIM "$N脚踏七星，使出【七星耀日】的精髓，剑幕中飞出七朵寒星，如流星般射向$n！\n" NOR, me, target);
	me->set_temp("cooldown", 1);	//CD写法	2017.9.7添加
	call_out("del_cooldown", 5, me);	//CD写法1
	me->add_temp("apply/attack", extra);
	me->add_temp("apply/damage", extra);
	damage1 = me->query_skill("quanzhen-jian",1) + me->query_skill("jinyan-gong",1);
	if ( random(ap) > dp/3 ) 
	{
	message_vision(WHT "$N剑光一闪，身形瞬息位移，脚踩北斗七星，七剑下天山！\n" NOR, me, target);		
	damage = damage1/3 + random(damage1/3);
	damage = damage*(100-target->query_meridian())/100;
	target->receive_damage("qi",damage,me);
	target->receive_wound("qi",damage/2,me);
//	if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);	
	message_vision(HIR"天枢---贪狼星" NOR, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);

	damage = damage1/3 + random(damage1/3);
	damage = damage*(100-target->query_meridian())/100;
	target->receive_damage("qi",damage,me);
	target->receive_wound("qi",damage/2,me);
//	if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);	
	message_vision(HIR"天璇---巨门星" NOR, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);

	damage = damage1/3 + random(damage1/3);
	damage = damage*(100-target->query_meridian())/100;
	target->receive_damage("qi",damage,me);
	target->receive_wound("qi",damage/2,me);
//	if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);	
	message_vision(HIR"天玑---禄存星" NOR, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);

	damage = damage1/3 + random(damage1/3);
	damage = damage*(100-target->query_meridian())/100;
	target->receive_damage("qi",damage,me);
	target->receive_wound("qi",damage/2,me);
//	if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);	
	message_vision(HIR"天权---文曲星" NOR, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);

	damage = damage1/3 + random(damage1/3);
	damage = damage*(100-target->query_meridian())/100;
	target->receive_damage("qi",damage,me);
	target->receive_wound("qi",damage/2,me);
//	if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
	message_vision(HIY"玉衡---廉贞星" NOR, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);

	damage = damage1/3 + random(damage1/3);
	damage = damage*(100-target->query_meridian())/100;
	target->receive_damage("qi",damage,me);
	target->receive_wound("qi",damage/2,me);
//	if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);	
	message_vision(HIB"开阳---武曲星" NOR, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);

	damage = damage1/3 + random(damage1/3);
	damage = damage*(100-target->query_meridian())/100;
	target->receive_damage("qi",damage,me);
	target->receive_wound("qi",damage/2,me);
//	if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);	
	message_vision(HIW"摇光---破军星" NOR, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,);
	}
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->add("neili", -1000);
	
if(	me->query_skill("quanzhen-jian", 1) > 2000 && me->query_skill("jinyan-gong", 1) > 800)
{
	message_vision(HIM"紧跟着$N使出全真剑法中的绝招［七星耀日］，光芒大作！\n\n" NOR,me,target);	
	if( weapon2 = target->query_temp("weapon") )
	{
		if ( random(ap) >dp/3 )
		{
			damage1 = me->query_skill("xiantian-gong",1) + me->query_skill("quanzhen-jian",1)*5 + me->query_skill("jinyan-gong",1) + me->query_skill("sword",1) + me->query_skill("force") + me->query("jiali");
			damage = damage1/3 + random(damage1/3);
			damage = damage*(100-target->query_meridian())/100;
			target->receive_damage("qi", damage,me);
			target->receive_wound("qi", damage/2,me);
			me->add("neili", -2000);
			weapon2->unequip();	
			weapon2->move(environment(target));				
			message_vision(HIR"\n$p只觉得全身沐浴在日月光芒之下，双眼无法睁开，一口鲜血喷出，手中" +weapon2->query("name")+HIR"坠地而出。\n"NOR, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//			if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
		}
		else
		{
			me->add("neili", -200);
			message_vision("$p逆转七星，踏步直上，识破阵眼所在！。\n", me, target);
		}
	}
	else
	{
		if ( random(ap) >dp/3 )
		{
			damage1 = me->query_skill("xiantian-gong",1) + me->query_skill("quanzhen-jian",1) * 5 + me->query_skill("jinyan-gong",1);
			damage = damage1/3 + random(damage1/3);
			damage = damage*(100-target->query_meridian())/100;
			target->receive_damage("qi", damage,me);
			target->receive_wound("qi", damage/2,me);
			me->add("neili", -2000);
			message_vision(HIM"$n被七星光芒亮瞎了眼，只好喷血来阻挡星光！\n\n" NOR,me,target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//			if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
		}
		else
		{
			me->add("neili", -300);
			message_vision( CYN"\n$p逆转七星，踏步直上，识破阵眼所在！。\n" NOR, me, target);
		}

	}
}
if(	me->query_skill("quanzhen-jian", 1) > 1200 && me->query_skill("jinyan-gong", 1) > 1200 )
{
		message_vision(HIY "\n忽然天昏地暗，$N倒转七星，踏七星而上，一片星海浮现在地脚下，光芒点点，夺目耀眼！\n"NOR, me, target);
		message_vision(HIB "\n$N气势一步一积累，那片星辰图出现在脚下，它就像是在登天一般！\n"NOR, me, target);
		if (me->query("jm/quanzhen")) damage1 = me->query_skill("quanzhen-jian",1)*me->query("con",1)*3/2 + me->query_skill("xiantian-gong",1)*me->query("con",1)*3/2 +me->query_skill("tiangang-zhengqi",1)*me->query("con",1)/2+ me->query_skill("jinyan-gong",1)*me->query("con",1)*3/2 + me->query_skill("sword",1) + me->query_skill("force") + me->query("jiali");
		else damage1 = me->query_skill("quanzhen-jian",1)*me->query("con",1) + me->query_skill("xiantian-gong",1)*me->query("con",1) +me->query_skill("tiangang-zhengqi",1)*me->query("con",1)/2+ me->query_skill("jinyan-gong",1)*me->query("con",1) + me->query_skill("sword",1) + me->query_skill("force") + me->query("jiali");
	if (random(me->query("neili")) > target->query("neili")/3)
	{
		message_vision(HIC"当第七步踏出，神鬼辟易！一道巨大的剑芒从$N身上冲天而起，一瞬间穿透$n！\n"NOR, me, target);		
		damage = damage1/4 + random(damage1/4) + target->query("qi")*4/100;
		damage = damage*(100-target->query_meridian())/100;
		me->add("neili", -3000);
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		target->apply_condition("no_exert", 20);
		target->add("neili", -damage);
		message_vision(HIR"这一剑万古以来从来没有人能避开！$n大吐一口鲜血！\n"NOR, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"，杀内力为"+damage+"。\n" NOR);
	} else
	{
		message_vision(HIR"$N第七步踏出，正当一道巨大的剑芒从身上冲天而起时，全身内力突然运转不畅，顿时从北斗位置跌落下来！\n"NOR, me, target);	
		damage = damage1/6 + random(damage1/6);
		damage = damage*(100-target->query_meridian())/100;
		me->add("neili", -5000);
		me->receive_damage("qi", damage,target);
		me->receive_wound("qi", damage/2,target);
		message_vision(HIB"$n踏七步酝酿的气势瞬间消散，经脉紊乱，内力反噬，大吐一口鲜血！\n"NOR, target, me, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对自己气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);	
	}
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