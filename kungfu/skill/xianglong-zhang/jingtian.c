#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

string query_name() { return " 惊天"ZJBR"一式 "; }
#define HUI "「" HIR "惊天一式" NOR "」"
#define HUIP "「" HIR "亢龙有悔" HIW "」"

inherit F_SSERVER;

int perform(object me, object target)
{
	int damage,ap, dp;
	string msg;

	if (! target) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail(HUI "只能对战斗中的对手使用。\n");
	if (me->is_busy()) 
		return notify_fail("你现在正忙着呢！\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail(HUI "只能空手使用。\n");
//	if (target && target->query_temp("apply/shade_vision")) 
//		return ("对方隐身了，你看不到"+target->query("name")+"。\n"); 	
	if ((int)me->query_skill("force",1) < 200)
		return notify_fail("你内功修为不够，难以施展" HUI "。\n");
	if ((int)me->query("max_neili") < 2000)
		return notify_fail("你内力修为不够，难以施展" HUI "。\n");
	if ((int)me->query("max_jingli") < 2000)								
		return notify_fail("你的精力修为不够。\n");
	if( (int)me->query("jingli") < 1000 )
		return notify_fail("你的精力不够。\n");	
	if ((int)me->query_skill("xianglong-zhang", 1) < 300)
		return notify_fail("你降龙十八掌火候不够，难以施展" HUI "。\n");
	if( (int)me->query_skill("huntian-qigong", 1) < 300 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");	
//	if ( !wizardp(me) && me->query_skill_mapped("force") != "huntian-qigong")
//		return ("不使用本门内功，如何使用本门绝学!\n");
//	if (me->query_skill_mapped("unarmed") != "xianglong-zhang")
//		return ("你没正确激发该技能 。\n");
	if ((int)me->query("neili") < 1000)
		return notify_fail("你现在真气不够，难以施展" HUI "。\n");
	if (target && !living(target))
		return notify_fail("对方都已经这样了，用不着这么费力吧？\n");
	if (me->query_temp("autolian"))
		return notify_fail("你正在发动自动连招！\n"); 	
	if ( me->query_temp("cooldown") )	//CD写法	2017.9.7添加
		return notify_fail("你处于技能冷却状态中，过会在使用吧。\n");

	me->set_temp("cooldown", 1);	//CD写法	2017.9.7添加
	call_out("del_cooldown", 3, me);	//CD写法1		
	ap = me->query("xyzx_sys/level") + me->query_skill("xianglong-zhang", 1) + me->query_skill("unarmed") + me->query_skill("force");
	dp = target->query("xyzx_sys/level") + target->query_skill("dodge") + target->query_skill("parry");
	ap = ap*((int)me->query("breakup")+(int)me->query("breakup")*(int)me->query("breakup")+100)/100;
	dp = dp*((int)target->query("breakup")+(int)target->query("breakup")*(int)target->query("breakup")+100)/100;
	msg = HIC "$N施展出降龙十八掌的绝学"HIY+"「惊天一击」"+HIC"，全身急速转动起来，越来越快，\n就犹如一股旋风，骤然间，$N已卷向正看得发呆的$n。\n"NOR;	
	message_vision(msg, me, target);
	if (random(ap) > dp/3)
	{
		damage = (int)me->query_skill("xianglong-zhang", 1)*2+(int)me->query_skill("force");
		damage = damage/2 + random(damage/2);
		damage = damage*(100-target->query_meridian())/100;
		target->receive_damage("qi", damage, me);
		target->receive_wound("qi", damage/2, me);
		me->add("neili", -200);
		me->add("jingli", -200);
		msg = HIR"$n只见一阵旋风影中陡然现出$N的双掌，根本来不及躲避，被重重击中，五脏六腑翻腾不休，口中鲜血如箭般喷出！！！\n"NOR;
		message_vision(msg, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
	}
	else
	{
		me->add("neili",-100);
		msg = HIG"$n看得分明，连忙提气纵身，以跳离了$N的掌力范围。\n"NOR;
		message_vision(msg, me, target);
	}	
	
if ((int)me->query_skill("xianglong-zhang", 1) > 1000 )
{	
	// 第一掌
	message_vision(HIW "\n忽然$N" HIW "身形激进，左手一划，右手呼的一掌"
	               "拍向$n" HIW "，正是降龙十八掌" HUIP "。\n力自掌生之际"
	               "说到便到，以排山倒海之势向$n" HIW "狂涌而去，当真石"
	               "破天惊，威力无比。\n" NOR, me, target);
		me->add("neili", -200);	
		me->add("jingli", -200);	
	if (random(ap) > dp/3)
	{
		damage = ap/3 + random(dp/3);
		damage = damage*(100-target->query_meridian())/100;
		target->receive_damage("qi",damage,me);
		target->receive_wound("qi",damage/2,me);
		msg =HIR "$P身形一闪，竟已晃至$p跟前，$p躲闪不及，顿被击个正中。\n" NOR;
		message_vision(msg, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
	}
	else
	{
		msg = HIC "却见$p气贯双臂，凝神应对，$P掌力如泥牛入海，尽数卸去。\n" NOR;
		message_vision(msg, me, target);
	}
}
if ((int)me->query_skill("xianglong-zhang", 1) > 1500 )
{
	// 第二掌
	message_vision(HIW "\n$N" HIW "一掌既出，身子已然抢到离$n" HIW "三"
	               "四丈之外，后掌推前掌两股掌力道合并，\n又是一招" HUIP
	               "攻出，掌力犹如怒潮狂涌，势不可当。霎时$p便觉气息窒"
	               "滞，立足不稳。\n" NOR, me, target);
		me->add("neili", -200);	
		me->add("jingli", -200);
	if (random(ap) > dp/3)
	{
		damage = ap/3 + random(dp/3);
		damage = damage*(100-target->query_meridian())/100;
		target->receive_damage("qi",damage,me);
		target->receive_wound("qi",damage/2,me);
		msg =HIR "$p一声惨嚎，被$P这一掌击中胸前，喀嚓喀嚓断了几根肋骨。\n" NOR;
		message_vision(msg, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
	}
	else
	{
		msg = HIC "可是$p全力抵挡招架，竟似游刃有余，将$P的掌力卸于无形。\n" NOR;
		message_vision(msg, me, target);
	}
}
if ((int)me->query_skill("xianglong-zhang", 1) > 2000 )
{
	// 第三掌
	message_vision(HIW "\n紧跟着$N" HIW "右掌斜挥，前招掌力未消，此招掌"
	               "力又到，竟然又攻出一招" HUIP "，\n掌夹风势，势如破竹，"
	               "便如一堵无形气墙，向前疾冲而去。$n" HIW "只觉气血翻"
	               "涌，气息沉浊。\n" NOR, me, target);
		me->add("neili", -200);	
		me->add("jingli", -200);
	if (random(ap) > dp/3)
	{
		damage = ap/3 + random(dp/3);
		damage = damage*(100-target->query_meridian())/100;
		target->receive_damage("qi",damage,me);
		target->receive_wound("qi",damage/2,me);
		msg =HIR "结果$p躲闪不及，$P掌劲顿时穿胸而过，顿时口中鲜血狂喷。\n" NOR;
		message_vision(msg, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
	}
	else
	{
		msg = HIC "$p眼见来势凶猛，身形疾退，瞬间飘出三丈，脱出掌力之外。\n" NOR;
		message_vision(msg, me, target);
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