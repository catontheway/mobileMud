// 腐尸毒
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#include <condition.h>

inherit F_SSERVER;
int perform(object me, object target)
{

	object co;
	int ap,dp,damage;

	if( !target ) target = offensive_target(me);
	if( !target ||	!target->is_character() ||	!me->is_fighting(target) )
		return notify_fail("「腐尸毒」只能在战斗中对对手使用。\n");
	if( objectp(me->query_temp("weapon")))
		return notify_fail("你必须空手才能使用这个绝技！\n");
	
    if(me->is_busy())
        return notify_fail("你现在正忙着！\n");
	if ((int)me->query("shen") > -100000)
		return notify_fail("心狠手辣之人才能使用如此歹毒招式！\n");	
	if( (int)me->query_skill("chousui-zhang", 1) < 500 )
		return notify_fail("你的星宿毒掌还不够娴熟，使不出「腐尸毒」绝技。\n");
	if( (int)me->query_skill("huagong-dafa",1) < 300 )
		return notify_fail("你的化功大法修为不够，不能使用「腐尸毒」。\n");
//	if ( !wizardp(me) && me->query_skill_mapped("force") != "huagong-dafa")
//		return ("不使用本门内功，如何使用本门绝学!\n");	
//	if ( me->query_skill_mapped("unarmed") != "chousui-zhang")
//		return ("你必须激发该技能才能使用!\n");	
	
	co=present("corpse",me);
	if (!co)
		return notify_fail("你身上没有尸体，如何使用腐尸毒!\n");
	if( (int)me->query("max_neili") < 1000)
		return notify_fail("你内力太弱，使不出「腐尸毒」。\n");
	if( (int)me->query("neili") < 1000)
		return notify_fail("你现在真气太弱，使不出「腐尸毒」。\n");
	if( (int)me->query("jingli") < 1000 )
		return notify_fail("你的精力不够。\n");	
	if (me->query_temp("autolian"))
		return notify_fail("你正在发动自动连招！\n"); 	
	if ( me->query_temp("cooldown") )	//CD写法	2017.9.7添加
		return notify_fail("你处于技能冷却状态中，过会在使用吧。\n");
		
	ap = me->query("xyzx_sys/level") + me->query_skill("chousui-zhang", 1) + me->query_skill("unarmed") + me->query_skill("force");
	dp = target->query("xyzx_sys/level") + target->query_skill("dodge") + target->query_skill("parry");	
	ap = ap*((int)me->query("breakup")+(int)me->query("breakup")*(int)me->query("breakup")+100)/100;
	dp = dp*((int)target->query("breakup")+(int)target->query("breakup")*(int)target->query("breakup")+100)/100;
	message_vision(BLU"\n$N一声阴笑，右手突出，挟起一具尸体掷出，一股死鱼烂肉的臭气弥漫四周，闻者欲呕！\n"NOR,me);
	me->set_temp("cooldown", 1);	//CD写法	2017.9.7添加
	call_out("del_cooldown", 3, me);	//CD写法1	
	me->add("neili", -300);
	if(random(ap)>dp/2)
	{
		damage = me->query_skill("chousui-zhang",1) + me->query_skill("huagong-dafa",1) + me->query_skill("force",1)+me->query_skill("duji",1);
		damage = damage/2 + random(damage/2);
		damage = damage*(100-target->query_meridian())/100;
		message_vision(HIB"\n$n见此怪异的招数，手足无措，躲闪无及，只见散发着恶臭的尸体，正击在自己身上。\n"NOR, me, target);
        target->receive_damage("jing",damage,me);
        target->receive_wound("jing",damage/2,me);
		target->apply_condition("sanxiao_poison",20);		
//		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人精神的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
		message_vision(CYN " 结果$n无力挣扎，$N的三笑逍遥散侵入$n体内！\n" NOR, me, target, damage, HBWHT+HIM"精神伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
	}
	else if(random(ap) > dp/3 && me->query_str(1) > (int)target->query_str(1)/2)
	{
		damage = me->query_skill("chousui-zhang",1) + me->query_skill("huagong-dafa",1) + me->query_skill("force",1)+me->query_skill("duji",1);
		damage = damage/2 + random(damage);
		damage = damage*(100-target->query_meridian())/100;
		message_vision(HIB"\n$n 见事不好，连忙纵身直起，腐尸从身下掠过，没有打中。\n"NOR,me,target);
		target->apply_condition("corpse_poison",20);
		target->apply_condition("sanpoison",20);
		target->apply_condition("xx_poison", 20);
		target->receive_damage("jing", damage,me);
		target->receive_wound("jing", damage/2,me);
//		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人精神的外伤为"+ damage*2 +"，内伤为"+ damage +"。\n" NOR);
		message_vision(HIB"\n 你虽然及时避开了毒尸，但一股腥臭气入鼻，你已中了剧毒了。\n"NOR,me,target, damage, HBWHT+HIM"精神伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
	}
	else
	{
		damage = me->query_skill("chousui-zhang",1) + me->query_skill("huagong-dafa",1) + me->query_skill("force",1);
		damage = damage/3 + random(damage/3);
		damage = damage*(100-me->query_meridian())/100;
		message_vision(HIB"\n$n 胸有成竹，一声长啸，双掌连环劈出，把毒尸毒气荡向来路。\n"NOR,me,target);
		me->apply_condition("xx_poison", 10);
		me->receive_damage("jing", damage,target);
		me->receive_wound("jing", damage/4,target);
		message_vision(HIB"\n 不好！毒尸反弹向$n，$n虽然躲开，但毒气已经侵入体内。\n"NOR,target,me, damage, HBWHT+HIM"精神伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对自己精神的外伤为"+ damage/2 +"，内伤为"+ damage/4 +"。\n" NOR);
	}
	destruct(co);	//换种写法
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

