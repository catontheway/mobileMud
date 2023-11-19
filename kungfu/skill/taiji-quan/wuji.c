// wuji 「太极无极」
// by suimeng 2015.4

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,damage,me_qi;
	int ap,dp;
	
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("这门绝学只能对战斗中的对手使用。\n");	
    if( objectp(me->query_temp("weapon")) )
        return notify_fail("耍太极拳必须空手才能使用「太极无极」!\n");  
//	if (target && target->query_temp("apply/shade_vision")) 
//		return ("对方隐身了，你看不到"+target->query("name")+"。\n"); 		
	if (me->is_busy())
		return notify_fail("你现在没空！！\n");	
	if( (int)me->query("neili") < 5000  ) 
		return notify_fail("你的内力不够。\n");
	
	if ((int)me->query("max_jingli")<1000)								
		return notify_fail("你的精力修为不够。\n");
	if( (int)me->query("jingli") < 1000 )
		return notify_fail("你的精力不够。\n");	
	if( (int)me->query("max_neili") < 5000 ) 
		return notify_fail("你的内力修为不够。\n");
    if( (int)me->query_skill("taiji-quan", 1) < 500 )
		return notify_fail("你的太极拳修为太低，不能贯通使用「太极无极」！\n");
    if( (int)me->query_skill("taiji-jian", 1) < 500 )
		return notify_fail("你的太极剑修为太低，不能贯通使用「太极无极」！\n");
	if((int)me->query_skill("taiji-shengong", 1) < 500 )
		return notify_fail("你的太极神功不够高！不能贯通使用「太极无极」！\n");
    if ( !wizardp(me) && me->query_skill_mapped("force") != "taiji-shengong")
        return notify_fail("不使用本门内功，如何使用「太极无极」!\n");
    if ( !wizardp(me) && me->query_skill_mapped("cuff") != "taiji-quan")
        return notify_fail("你未激发太极拳，如何使用「太极无极」!\n");
    if ( !wizardp(me) && me->query_skill_mapped("parry") != "taiji-quan")
        return notify_fail("你必须激发招架，才能使用「太极无极」!\n");	  
	if (me->query_temp("autolian"))
		return notify_fail("你正在发动自动连招！\n"); 	
	if ( me->query_temp("cooldown") )	//CD写法	2017.9.7添加
		return notify_fail("你处于技能冷却状态中，过会在使用吧。\n");
		
	ap = me->query("xyzx_sys/level") + me->query_skill("taiji-quan", 1)+me->query_skill("taiji-jian", 1) + me->query_skill("cuff") + me->query_skill("force");
	dp = target->query("xyzx_sys/level") + target->query_skill("dodge") + target->query_skill("parry");
	ap = ap*((int)me->query("breakup")+(int)me->query("breakup")*(int)me->query("breakup")+100)/100;
	dp = dp*((int)target->query("breakup")+(int)target->query("breakup")*(int)target->query("breakup")+100)/100;
	extra = me->query_skill("taiji-quan",1)/10 + me->query_skill("taiji-shengong",1)/10;			
    msg = WHT "$N贯通武当武学，使出了武当的绝学之精髓！\n" NOR;
	msg += MAG  "$N双手抱了个太极式的圆圈，纯以意行太极，已达形神合一，心动气动的境界，！\n"NOR;	
    message_vision(msg, me, target);
	me->set_temp("cooldown", 1);	//CD写法	2017.9.7添加
	call_out("del_cooldown", 5, me);	//CD写法1	

    msg = CYN "$N默运神功，使出太极拳「震」字诀，企图以内力震伤$n。\n"NOR;
	message_vision(msg, me, target);
    damage = (int)me->query_skill("taiji-shengong", 1) + (int)me->query_skill("taiji-quan", 1);
	damage = damage/2 + random(damage/2);
	damage = damage*(100-target->query_meridian())/100;
    if (random(ap) > dp/3 )
    {
        if( damage < 1000 )
		{
			msg = HIY"结果$n受到$N的内力反震，闷哼一声。\n"NOR;
		}
        else if( damage < 10000 )
		{
			msg = HIY"结果$n被$N以内力反震，「嘿」地一声退了两步。\n"NOR;
		}
        else if( damage < 50000 )
		{
			msg = RED"结果$n被$N以内力一震，胸口有如受到一记重锤，连退了五六步！\n"NOR;
		}
        else
		{
			msg = HIR"结果$n被$N的内力一震，眼前一黑，象一捆稻草一样飞出去好几丈远！\n"NOR;
		}
		                  
        target->receive_damage("qi", damage,me);
        target->receive_wound("qi", damage/2,me);
        me->add("neili", -200);
        message_vision(msg, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);

    }
    else 
    {     
        msg = CYN"可是$p看破了$P的企图，并没有上当。\n"NOR;
		message_vision(msg, me, target);
    }
	
	me->add_temp("apply/attack",extra);
	me->add_temp("apply/damage",extra);
	msg = MAG  "「乱环诀」！阳" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		
    msg = MAG  "「乱环诀」！阴" NOR;
        COMBAT_D->do_attack(target,target, target->query_temp("weapon"),TYPE_REGULAR,msg);		
	msg = WHT  "「阴阳诀」！阳" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = MAG  "「阴阳诀」！阴" NOR;
        COMBAT_D->do_attack(target,target, target->query_temp("weapon"),TYPE_REGULAR,msg);		
	msg = WHT  "「动静诀」！阴" NOR;
		COMBAT_D->do_attack(target,target, target->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = MAG  "「动静诀」！阳" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);		
	msg = WHT  "「两仪诀」！阴" NOR;
		COMBAT_D->do_attack(target,target, target->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = MAG  "「两仪诀」！阳" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);		
	msg = WHT  "「刚柔诀」！阴" NOR;
		COMBAT_D->do_attack(target,target, target->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = MAG  "「刚柔诀」！阳" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack",-extra);
        me->add_temp("apply/damage",-extra);
		me->add("neili", -2000);
		
		
if (me->query_skill("taiji-quan",1)>2000 && me->query_skill("taiji-jian",1)>2000)
{	
	damage = me->query_skill("taiji-quan",1) + me->query_skill("taiji-shengong",1)+me->query_skill("force",1)+me->query_skill("unarmed",1)+me->query_skill("sword",1); 
	msg = WHT"              阴阳双环           !!\n"NOR;
	message_vision(msg, me, target);
	if ( random(ap) > dp/3 )
	{ 
		me->add_temp("apply/attack",extra*2);
		me->add_temp("apply/damage",extra);
		msg = MAG"「沾黏诀」「挤字诀」「引字诀」「按字诀」!!\n"NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack",-extra*2);
        me->add_temp("apply/damage",-extra);
		
		damage = damage/2 + random(damage/2);
		damage = damage*(100-target->query_meridian())/100;
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		me->add("neili", -2000);
		msg = HIR"\n结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n"NOR;
		message_vision(msg, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法	
//		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);		
	} else
	{
		me->add("neili", -2000);
		msg = HIR"\n$n使出沾衣十八滚！！连滚带爬的居然躲开了这一招！！！\n"NOR;
		message_vision(msg, me, target);
	}
}	    

if (me->query_skill("taiji-quan",1)>3000 && me->query_skill("taiji-jian",1)>3000)
{	
	if (me->query("jm/wudang")) damage = me->query_skill("taiji-quan",1)* me->query("con",1)*3/2+me->query_skill("taiji-shengong",1)* me->query("con",1)*3/2+me->query_skill("taiji-jian",1)* me->query("int",1)*3/2+me->query_skill("force",1)+me->query_skill("unarmed",1)+me->query_skill("sword",1)+me->query("jiali")+target->query_str();
	else damage = me->query_skill("taiji-quan",1)* me->query("con",1)+me->query_skill("taiji-shengong",1)* me->query("con",1)+me->query_skill("taiji-jian",1)* me->query("int",1)+me->query_skill("force",1)+me->query_skill("unarmed",1)+me->query_skill("sword",1)+me->query("jiali")+target->query_str()/2;
	me_qi = me->query("max_qi")-me->query("eff_qi");
	if (me_qi < 1000) me_qi = 1000; 
	msg = HIM"              太极------------无极           !!\n"NOR;
	message_vision(msg, me, target);
	if ( random(ap) > dp/3 )
	{       
		damage = damage/3 + random(damage/3) + me_qi/3;
		damage = damage*(100-target->query_meridian())/100;
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		me->add("neili", -3000);
		msg = MAG"「太极生两仪」「两仪化四象」「四象变八卦」「八卦演天罡」!!\n"NOR;
		msg += HIR"\n结果只听见狂风暴雨般的响声，$n一声惨叫，像滩软泥般塌了下去！！\n"NOR;
		message_vision(msg, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);		
	} else
	{
		damage = damage/15 + random(damage/15);
		damage = damage*(100-target->query_meridian())/100;
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);		
		me->add("neili", -2000);
		msg = HIR"\n$n倒转阴阳，以身化混沌，由无极而太极，仅受到小部分伤害！！！\n"NOR;
		message_vision(msg, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage/3 +"，内伤为"+ damage/5 +"。\n" NOR);	
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