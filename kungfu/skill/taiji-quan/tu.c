// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified
// in any form without the written permission from authors.

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

#include "/kungfu/skill/eff_msg.h";

inherit F_SSERVER;

#define TU "「" HIW "太极图" NOR "」"

int perform(object me, object target)
{
	object *obs;
	string msg;
	int damage,ap, dp, i;
//	int flag;

	if (!target ) target = offensive_target(me);
	if (!target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail(TU "只能对战斗中的对手使用。\n");
	if( objectp(me->query_temp("weapon")) )
		return notify_fail(TU "只能空手施展。\n");

	if( me->is_busy() )
		return notify_fail("你正忙着呢！\n");
	if ((int)me->query_skill("taiji-quan", 1) < 500)
		return notify_fail("你的太极拳不够娴熟，难以施展" TU "。\n");
	if ((int)me->query_skill("taiji-shengong", 1) < 500)
		return notify_fail("你的太极神功修为还不够高，难以施展" TU "。\n");
	
//	if (me->query_skill_mapped("unarmed") != "taiji-quan")
//		return ("你现在没有激发太极拳，难以施展" TU "。\n");
//	if (me->query_skill_mapped("parry") != "taiji-quan")
//		return ("你现在没有激发太极拳在招架上，难以施展" TU "。\n");
//	if (me->query_skill_mapped("force") != "taiji-shengong")
//		return ("你现在没有激发太极神功，难以施展" TU "。\n");
	if ((int)me->query("max_jingli") < 2000)
		return notify_fail("你现在精力修为不够，难以施展" TU "。\n");
	if ((int)me->query("max_neili") < 3000)
		return notify_fail("你现在真气修为不够，难以施展" TU "。\n");
	if ((int)me->query("jingli") < 1000)
		return notify_fail("你现在精力不够，难以施展" TU "。\n");
	if ((int)me->query("neili") < 1000)
		return notify_fail("你现在真气不够，难以施展" TU "。\n");
	if (me->query_temp("autolian"))
		return notify_fail("你正在发动自动连招！\n"); 	
	if ( me->query_temp("cooldown") )	//CD写法	2017.9.7添加
		return notify_fail("你处于技能冷却状态中，过会在使用吧。\n");
		
	//第一拳
	msg = HIM "$N" HIM "淡然一笑，双手轻轻划了数个圈子，顿时四周的气流波动，源源不断的被牵引进来。\n\n" NOR;
	message_vision(msg, me, target);
	me->set_temp("cooldown", 1);	//CD写法	2017.9.7添加
	call_out("del_cooldown", 3, me);	//CD写法1
	me->add("neili", -1000);
	me->add("jingli", -1000);
//	me->start_busy(4);	//放在后置busy
	ap = me->query("xyzx_sys/level") + me->query_skill("taiji-quan", 1) + me->query_skill("unarmed") + me->query_skill("force");
	dp = target->query_skill("xyzx_sys/level") + target->query_skill("force") + target->query_skill("parry");
	ap = ap*((int)me->query("breakup")+(int)me->query("breakup")*(int)me->query("breakup")+100)/100;
	dp = dp*((int)target->query("breakup")+(int)target->query("breakup")*(int)target->query("breakup")+100)/100;
	obs = me->query_enemy();
//	for (flag = 0, i = 0; i < sizeof(obs); i++)	//这里的flag何用？
	for (i = 0; i < sizeof(obs); i++)
	{
		dp = obs[i]->query_skill("xyzx_sys/level") + obs[i]->query_skill("force") + obs[i]->query_skill("parry");
		dp = dp*((int)obs[i]->query("breakup")+(int)obs[i]->query("breakup")*(int)obs[i]->query("breakup")+100)/100;
		if (random(ap) > dp/3)
		{
			switch (random(3))
			{
			case 0:
				tell_object(obs[i], HIY "恍惚之间你似乎回到了过去的世界，竟然再无法控制自我，忽然眼前的一切\n""又全然不见，你心头一乱，浑身一阵剧痛，内力紊乱难以控制！\n" NOR);
				break;
			case 1:
				tell_object(obs[i], HIW "你眼前一切渐渐的模糊起来，好像是到了仙境，然而你却觉得内息越来越乱，\n""四肢一阵酸痛，几乎要站立不住。\n" NOR);
				break;
			default:
				tell_object(obs[i], HIR "你耳边忽然响起一个霹雳，眼见雷神挥舞电锤向你打来，你不禁大吃一惊，\n""浑身上下都不听使唤，只有高声呼救。\n" NOR);
				break;
			}
			msg = MAG  "太极生两仪" NOR;
			COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
			switch (random(3))
			{
			case 0:
				msg = HIR "只见" + obs[i]->name() +HIR "手舞足蹈，忘乎所以，忽然大叫一声，吐血不止！\n" NOR;
				break;
			case 1:
				msg = HIR "却见" + obs[i]->name() +HIR "容貌哀戚，似乎想起了什么伤心之事，身子一晃，呕出数口鲜血！\n" NOR;
				break;
			default:
				msg = HIR + obs[i]->name() +HIR "呆立当场，一动不动，有如中邪，七窍都迸出鲜血来。\n" NOR;
				break;
			}
			damage = ap/2 + random(ap/2);
			obs[i]->receive_damage("qi", damage,me);
			obs[i]->receive_wound("qi", damage/2,me);			
			obs[i]->add("neili", -500);
//			flag = 1;			
//			message("vision", msg, environment(me), ( { obs[i] }));
			message_vision(msg, me, obs[i], damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//			if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
		}
		else
		{
			tell_object(obs[i], HIC "你发现眼前的景物似幻似真，连忙默运内功，不受困扰。\n" NOR);
			obs[i]->add("neili", -200);
		}
		if (obs[i]->query("neili") < 0) obs[i]->set("neili", 0);
	}

	//第二拳
if ((int)me->query_skill("taiji-quan", 1) >1000)
{	
	msg = HIW "$N" HIW "双手一圈，施出「引」字诀，如抱太极，一股雄浑无比的力道组成了一个旋涡，圈向四周四方。\n" NOR;
	message_vision(msg, me, target);

//	for (flag = 0, i = 0; i < sizeof(obs); i++)	//这里的flag何用？
	for (i = 0; i < sizeof(obs); i++)
	{
		dp = obs[i]->query_skill("xyzx_sys/level") + obs[i]->query_skill("force") + obs[i]->query_skill("parry");
		dp = dp*((int)obs[i]->query("breakup")+(int)obs[i]->query("breakup")*(int)obs[i]->query("breakup")+100)/100;
		if (random(ap) > dp/3)
		{
			msg = MAG  "两仪化四象" NOR;
			COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
//			flag = 1;			
			damage = ap/2 + random(ap/2);
			obs[i]->receive_damage("jing", damage,me);
			obs[i]->receive_wound("jing", damage/2,me);
			obs[i]->add("neili", -500);
			msg = HIR + obs[i]->name() +HIR "微微一楞，登时被这力道带得在原地急转七八下，如转陀螺，如旋纺锤。\n" NOR;
//			message("vision", msg, environment(me), ( { obs[i] }));
			message_vision(msg, me, obs[i], damage, HBWHT+HIM"精神伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//			if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对"+ i +"敌人精神的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);			
		}
		else
		{
			msg = CYN + obs[i]->name() +CYN "见状连忙使出“千斤坠”之力定住身形，摆脱了这股" CYN "的力道。\n" NOR;
			obs[i]->add("neili", -200);
			message("vision", msg, environment(me), ( { obs[i] }));
		}
		if (obs[i]->query("neili") < 0) obs[i]->set("neili", 0);
	}
}
	//第三拳
if ((int)me->query_skill("taiji-quan", 1) >2000)	
{
	msg = HIY "$N" HIY "默运神功，真气流转，双手左右连画，一个圆圈已将周围人"HIY "套住，\n太极拳中的震字诀信手使出，一道"HIY "浑厚的内力向四周" HIY "推去！\n" NOR;
	message_vision(msg, me, target);

//	for (flag = 0, i = 0; i < sizeof(obs); i++)	//这里的flag何用？
	for (i = 0; i < sizeof(obs); i++)
	{
		dp = obs[i]->query_skill("xyzx_sys/level") + obs[i]->query_skill("force") + obs[i]->query_skill("parry");
		dp = dp*((int)obs[i]->query("breakup")+(int)obs[i]->query("breakup")*(int)obs[i]->query("breakup")+100)/100;
		if (random(ap) > dp/3)
		{
			msg = MAG  "四象演八卦" NOR;
			COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
//			flag = 1;			
			damage = (ap+dp)/2 + random(ap+dp)/2;
			obs[i]->receive_damage("qi", damage,me);
			obs[i]->receive_wound("qi", damage/2,me);
			obs[i]->receive_damage("jing", damage,me);
			obs[i]->receive_wound("jing", damage/2,me);
			obs[i]->add("neili", -500);
			msg = HIC + obs[i]->name() + HIC "被"+ me->name() +"的太极内力压得透不过起来，只听得"HIC "“砰”的一声击中"+ obs[i]->name() +"" HIC "，"+ obs[i]->name() +"全身骨骼便似散了"HIC "架一般倒了下去。\n" NOR;
			message_vision(msg, me, obs[i], damage, HBWHT+HIM"精气伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//			if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"，精神的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
		}
		else
		{
			msg = "\n可"+ obs[i]->name() +"竟随手便把"+ me->name() +"汇聚全身功力的招数架开！\n" NOR;
			obs[i]->add("neili", -200);
			message("vision", msg, environment(me), ( { obs[i] }));
		}
		if (obs[i]->query("neili") < 0) obs[i]->set("neili", 0);
	}
}
//	if (! flag) message_vision(HIM "然而没有任何人受了$N 的影响。\n\n" NOR, me, obs);
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