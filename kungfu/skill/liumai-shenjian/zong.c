#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
//#include <condition.h>
inherit F_SSERVER;
string query_name() { return HIM"纵横"ZJBR"天下 "; }

#define ZONG "「" HIM "纵横天下" NOR "」"

int perform(object me, object target)
{
	string msg,force_skill;
	int ap, dp,skill,damage,damage1,extra;

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail(ZONG "只能对战斗中的对手使用。\n");
	if (me->is_busy()) 
		return notify_fail("你现在正忙着呢！\n");
	if (me->query_skill_mapped("finger") != "liumai-shenjian")
		return notify_fail("你没有准备使用六脉神剑，无法施展" ZONG "。\n");
	
	if ( me->query_skill("liumai-shenjian", 1) < 300)
		return notify_fail("你的六脉神剑修为有限，无法使用" ZONG "！\n");
	if ( me->query_skill("yiyang-zhi", 1) < 300)
		return notify_fail("你的一阳指修为有限，无法使用" ZONG "！\n");
	if (me->query_skill("force",1) < 300)
		return notify_fail("你的基本内功火候不够，难以施展" ZONG "！\n");
	if (me->query("max_neili") < 5000)
		return notify_fail("你的内力修为不够,无法施展" ZONG "！\n");
	if( (int)me->query("max_jingli") < 3000 )
		return notify_fail("你的精力修为还不够高。\n");
	if (me->query("neili") < 5000)
		return notify_fail("你的真气不够，现在无法施展" ZONG "！\n");
	if (me->query("jingli") < 3000)
		return notify_fail("你的精力不够，现在无法施展" ZONG "！\n");
	if (me->query_temp("weapon"))
		return notify_fail("你必须是空手才能施展" ZONG "！\n");
	
	if (target && !living(target))
		return notify_fail("对方都已经这样了，用不着这么费力吧？\n");
	if ( (int)me->query_skill("beiming-shengong",1) < 300)
		return notify_fail("你的内功似乎。。。。不够高！\n");
	if ( me->query_skill_mapped("force") != "beiming-shengong")	
		return notify_fail("不使用内功，如何能淋漓尽致的使用六脉!\n");	
	if (me->query_temp("autolian"))
		return notify_fail("你正在发动自动连招！\n"); 	
	if ( me->query_temp("cooldown") )	//CD写法	2017.9.7添加
		return notify_fail("你处于技能冷却状态中，过会在使用吧。\n");
        
	message_vision(HBWHT "$N贯通大理武学，使出了天龙寺的绝学之精髓！\n" NOR, me,target);	
	
    msg = HIM "$N" HIM "一声清啸，十指纷弹，顿觉六脉剑谱已涌上心头，此起"
              "彼伏、连绵不绝。霎时剑气如奔，连绵无尽的万道剑气豁然贯向$n" HIM 
              "！\n" NOR;
	message_vision(msg, me, target);
	me->set_temp("cooldown", 1);	//CD写法	2017.9.7添加
	call_out("del_cooldown", 5, me);	//CD写法1
	force_skill=me->query_skill_mapped("force");
	skill = (int)me->query_skill(force_skill, 1);
	ap = me->query("xyzx_sys/level") + me->query_skill("liumai-shenjian", 1) +me->query_skill("yiyang-zhi", 1)+ me->query_skill("finger") + me->query_skill("force");
	dp = target->query("xyzx_sys/level") + target->query_skill("dodge") + target->query_skill("parry");
	ap = ap*((int)me->query("breakup")+(int)me->query("breakup")*(int)me->query("breakup")+100)/100;
	dp = dp*((int)target->query("breakup")+(int)target->query("breakup")*(int)target->query("breakup")+100)/100;
	damage1 = me->query_skill("liumai-shenjian",1) + me->query_skill("yiyang-zhi", 1) + me->query_skill("kumu-shengong",1);
	extra = me->query_skill("liumai-shenjian",1)/10 + me->query_skill("yiyang-zhi", 1)/10;
		if (random(ap) > dp/3)
        {
				damage = damage1/2 + random(damage1/2);
				damage = damage*(100-target->query_meridian())/100;
                me->add("neili", -500);
				target->receive_damage("qi", damage,me);
				target->receive_wound("qi", damage/2,me);
	                msg =HIR "只听$n" HIR "一声惨叫，万道剑气已透体而过，伤口处鲜血顿时狂涌，痛苦难当！\n" NOR;
				message_vision(msg, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//				if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
        } else
        {
                me->add("neili", -400);
                msg = CYN "$n" CYN "见$N" CYN "来势汹涌，不敢轻易招架，急忙提气跃开。\n" NOR;
				message_vision(msg, me, target);
        }
	           

if ( me->query_skill("liumai-shenjian", 1) > 500 && me->query_skill("yiyang-zhi", 1) > 500)	
{	
		msg = HIY "$N" HIY "摊开双手，手指连弹，霎时间空气炙热，几欲沸腾，六道剑气分自六穴，一起杀向$n" HIY "！\n" NOR;
		message_vision(msg, me, target);
		damage1 = me->query_skill("liumai-shenjian",1) + me->query_skill("yiyang-zhi", 1) + me->query_skill("force") + me->query_skill("finger");
		damage = damage1/2 + random(damage1/2);
		damage = damage*(100-target->query_meridian())/100;
       if (random(ap)  > dp/3 )
        {
//        if (!target->is_busy()) target->start_busy(3);
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		me->add("neili", -1000);
		me->add("jingli", -1000);			
         msg = HIM "$n久闯江湖，六脉神剑也识得二三，但何曾见过如此神妙之用法，一愣神之间先机已失，只得任人宰割。霎时无数剑气穿身而出，全身上下无数血洞，鲜血狂喷不止，真气涣散之下，奄奄一息。" + "\n" NOR;
		 message_vision(msg, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
        } else
        {
			if (me->query("jm/dali"))
			{
				target->receive_damage("jing", damage,me);
				target->receive_wound("jing", damage/2,me);
				message_vision( HIR"$N凌空跃起，使出了六脉神剑的最高绝技［六脉归一］！！！\n" NOR,me,target, damage, HBWHT+HIM"精神伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//				if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人精神的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
			}				
			me->add("neili", -500);
			msg = NOR + CYN "$n哪曾见过六脉神剑如此用法，心道必死无疑，当即双眼一闭，仰头便倒，却恰好避过来招。" + "\n" NOR;
			message_vision(msg, me, target);
        }

}		
if ( me->query_skill("liumai-shenjian", 1) > 800 && me->query_skill("yiyang-zhi", 1) > 800)	
{	
		if (me->query("jm/dali")) damage1 = me->query_skill("liumai-shenjian",1)*me->query("int",1)/10 + me->query_skill("yiyang-zhi", 1)*me->query("con",1)/10 + me->query_skill("force") + me->query_skill("finger");		
		else damage1 = me->query_skill("liumai-shenjian",1)*me->query("int",1)/15 + me->query_skill("yiyang-zhi", 1)*me->query("con",1)/15 + me->query_skill("force") + me->query_skill("finger");		
		message_vision( HIR  "$N凌空跃起，使出了六脉神剑的最高绝技［六脉归宗］！！！\n$N杀红了眼，拼尽所有功力！！六道金光疾射而出，射向$n！" NOR,me,target);		
		if (random(ap)  > dp/3 )
		{
		damage = damage1/4 + random(damage1/4);
		damage = damage*(100-target->query_meridian())/100;
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/5,me);		
        msg = HIG  "━━━━「少泽剑」！\n$N右手小指连点，剑气到处，所向无敌。" NOR;
		message_vision(msg, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/5 +"。\n" NOR);		
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
		damage = damage1/4 + random(damage1/4);
		damage = damage*(100-target->query_meridian())/100;
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/5,me);
        msg = HIY  "━━━━━━「商阳剑」！\n$N食指伸处，商阳剑法随之展动。" NOR;	
		message_vision(msg, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/5 +"。\n" NOR);			
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
		damage = damage1/4 + random(damage1/4);
		damage = damage*(100-target->query_meridian())/100;
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/5,me);
        msg = HIB  "━━━━━━━━━「少冲剑」！\n$N左手小指一伸，一路剑气从少冲穴中激射而出。" NOR;		
//		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/5 +"。\n" NOR);	
		message_vision(msg, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
		damage = damage1/4 + random(damage1/4);
		damage = damage*(100-target->query_meridian())/100;
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/5,me);
        msg = HIM  "━━━━━━━━━━━━「中冲剑」！\n$N中指一竖，中冲剑猛的向前刺出。" NOR;		
//		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/5 +"。\n" NOR);
		message_vision(msg, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
		damage = damage1/4 + random(damage1/4);
		damage = damage*(100-target->query_meridian())/100;
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/5,me);
        msg = HIC  "━━━━━━━━━━━━━━━「少商剑」！\n$N拇指急出，虚虚实实的指向$n。" NOR;
		message_vision(msg, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法		
//		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/5 +"。\n" NOR);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
		damage = damage1/4 + random(damage1/4);
		damage = damage*(100-target->query_meridian())/100;
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/5,me);
        msg = HIW  "━━━━━━━━━━━━━━━━━「关冲剑」！\n$N无名指回收，随之一甩，一道极光刺向$n的风府穴。" NOR;
		message_vision(msg, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/5 +"。\n" NOR);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);

		me->add("neili", -1000);
		me->add("jingli", -1000);
		if (me->query_skill_mapped("force") == "beiming-shengong")	
		{
			damage = damage1/12 + random(damage1/12);
			damage = damage*(100-target->query_meridian())/100;
			target->add("neili", -damage/2);
			message_vision(HIC "$N催动北冥神功，噗的一声！击散了$n聚集的内力。\n" NOR, me,target);	
		}		
		}
		else 
		{
		damage = damage1/12 + random(damage1/12);
		damage = damage*(100-target->query_meridian())/100;
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);	
		me->add("neili", -1000);
//		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage/3 +"，内伤为"+ damage/5 +"。\n" NOR);		   
        msg = HIW "「少泽剑」「商阳剑」「少冲剑」「中冲剑」「少商剑」「关冲剑」！\n"HIC" $N内力难以为继，只好使出「一脉剑法」。\n" NOR;
		message_vision(msg, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
		me->add_temp("apply/attack",extra*2);
		me->add_temp("apply/damage",extra);		
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
		me->add_temp("apply/attack",-extra*2);
		me->add_temp("apply/damage",-extra);
	   }
}
if ( me->query_skill("liumai-shenjian", 1) > 1200 && me->query_skill("yiyang-zhi", 1) > 1200 )	
{	   
		if (me->query("jm/dali")) damage1 = me->query_skill("liumai-shenjian",1)*me->query("int",1)*3/2 + me->query_skill("yiyang-zhi", 1)*me->query("con",1)*3/2 + skill*me->query("con",1)*3/2 + me->query_skill("finger") + me->query_skill("force");	
		else damage1 = me->query_skill("liumai-shenjian",1)*me->query("int",1) + me->query_skill("yiyang-zhi", 1)*me->query("con",1) + skill*me->query("con",1) + me->query_skill("finger") + me->query_skill("force", 1);
		
		if (random(ap) > dp/3 )
		{
			damage = damage1/3 + random(damage1/3) + target->query("qi")*5/100;
			damage = damage*(100-target->query_meridian())/100;
			msg = HIW "「少泽剑」「商阳剑」「少冲剑」「中冲剑」「少商剑」「关冲剑」！\n"HIC" $N将六脉剑法融会贯通，一指点出，气势威猛无比，势不可当。\n" NOR;
			message_vision(msg,me,target);
			me->add_temp("apply/attack",extra*3);
			me->add_temp("apply/damage",extra);		
			COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
			me->add_temp("apply/attack",-extra*3);
			me->add_temp("apply/damage",-extra);
			
			target->receive_damage("qi", damage,me);
			target->receive_wound("qi", damage/3,me);			
			msg = RED  "$N潜运神功，六脉合一，又是六道剑光！！\n一阴一阳，一奇一正，一上一下地射向$n的气海穴。" NOR;
			message_vision(msg,me,target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//			if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/3 +"。\n" NOR);
			me->add("neili", -1000);
			me->add("jingli", -1000);
			if (me->query_skill_mapped("force") == "beiming-shengong")	
			{
				damage = damage1/3 + random(damage1/3) + target->query("neili")*5/100;
				damage = damage*(100-target->query_meridian())/100;
				target->add("neili", -damage);
				message_vision(HIC "$N催动北冥神功，噗的一声！击散了$n聚集的内力。\n" NOR, me,target);	
			}
			if (me->query("jm/dali"))
			{
				damage = damage1/3 + random(damage1/3) + target->query("qi")*5/100;
				damage = damage*(100-target->query_meridian())/100;
				target->receive_damage("jing", damage,me);
				target->receive_wound("jing", damage/2,me);
				target->apply_condition("no_perform", 10);
				message_vision( HIR"$N凌空跃起，使出了六脉神剑的最高绝技［六脉归一］！！！\n" NOR,me,target, damage, HBWHT+HIM"精神伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//				if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人追加精神的外伤为"+ damage/3 +"，内伤为"+ damage/5 +"。\n" NOR);
			}
		}
		else
        {
			damage = damage1/10 + random(damage1/10) + target->query("qi")*1/100;
			damage = damage*(100-target->query_meridian())/100;
			me->add("neili", -1000);
			target->receive_damage("qi", damage,me);
			target->receive_wound("qi", damage/3,me);
			msg = CYN "$n心力交瘁，至此已是有心无力，只好闭眼乱走一气，虽然中了几招但是好死不死的居然避开了绝杀的一指！。" + "\n" NOR;
			message_vision(msg,me,target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//			if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage/3 +"，内伤为"+ damage/5 +"。\n" NOR);
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
