// sui.c 太极剑法 [随]字决
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
string query_name() { return " 随"ZJBR"决 "; }
int perform(object me, object target)
{
    object weapon;
    int skill,damage;
    string msg;
	
    if( !target ) target = offensive_target(me);
   if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("太极剑法「随」字诀只能在战斗中使用。\n");
   if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你需要装备sword类武器才能使用「随」字诀。\n");

    if( (int)me->query_skill("taiji-jian", 1) < 200 )
        return notify_fail("你的太剑法极不够娴熟，不会使用「随」字诀。\n");
	if( (int)me->query_skill("taiji-shengong", 1) < 200 )
		return notify_fail("你的太极神功太浅，别做梦了。\n");	
//	if ( !wizardp(me) && me->query_skill_mapped("force") != "taiji-shengong")
//		return (HIC"不使用本门内功，如何使用本门绝学!\n"NOR);	
//	if (me->query_skill_mapped("sword") != "taiji-jian")
//		return ("你没正确激发该技能 。\n");
	if ((int)me->query("max_neili")<1000)								
		return notify_fail("你的内力修为不够。\n");
	if ((int)me->query("max_jingli")<1000)								
		return notify_fail("你的精力修为不够。\n");
	if( (int)me->query("jingli") < 1000 )
		return notify_fail("你的精力不够。\n");		
    if( (int)me->query("neili") < 1000 )
        return notify_fail("你的真气不够。\n");
    if(me->is_busy())
        return notify_fail("你现在正忙着！\n");
	if (me->query_temp("autolian"))
		return notify_fail("你正在发动自动连招！\n"); 	
	if ( me->query_temp("cooldown") )	//CD写法	2017.9.7添加
		return notify_fail("你处于技能冷却状态中，过会在使用吧。\n");
		
    skill = me->query_skill("taiji-jian")/10;
    msg = HIB "$N使出太极剑法「随」字诀，剑圈逐渐缩小将周身护住，并随时进行防守反击。\n"NOR;
    message_vision(msg, me, target);
	me->set_temp("cooldown", 1);	//CD写法	2017.9.7添加
	call_out("del_cooldown", 3, me);	//CD写法1

    me->add_temp("apply/attack", skill);
    me->add_temp("apply/dodge", skill);
    msg = MAG  "「动静随心，敌静我动」！" NOR;
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);	
	msg = WHT  "「借力用力，力由心生」！" NOR;
	COMBAT_D->do_attack(target,target, target->query_temp("weapon"),TYPE_REGULAR,msg);	
    msg = MAG  "「阴阳逆转，两仪变幻」！" NOR;
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    me->add_temp("apply/attack", -skill);
    me->add_temp("apply/dodge", -skill);
    me->add("neili", -300);	
	me->add("jingli", -300);
	
	if (me->query("qi") < me->query("max_qi"))
	{
		damage = me->query_skill("taiji-jian")*2+me->query_skill("taiji-shengong")+(me->query("max_qi")-me->query("qi"))/20;
		damage = damage/2 + random(damage/2);
		damage = damage*(100-target->query_meridian())/100;
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		message_vision(HIR "$N剑随身动，动静由心。$n一个不慎，中了一剑。\n"NOR, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
	}
	if (me->query("jing") < me->query("max_jing"))
	{
		damage = me->query_skill("taiji-jian")*2+me->query_skill("taiji-shengong")+(me->query("max_jing")-me->query("jing"))/20;
		damage = damage/2 + random(damage/2);
		damage = damage*(100-target->query_meridian())/100;
		target->receive_damage("jing", damage,me);
		target->receive_wound("jing", damage/2,me);
		message_vision(HIR "$N意随心动，剑划方圆。$n一个不慎，中了一剑。\n"NOR, me, target, damage, HBWHT+HIM"精神伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人精神的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
	}
	
	message_vision(HIB "$N使出太极剑法「三环套月」连续三个剑圈向$n袭来。\n"NOR, me, target);
	me->add_temp("apply/attack", skill);
	me->add_temp("apply/damage", skill);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
	me->add_temp("apply/attack", -skill);
	me->add_temp("apply/damage", -skill);	
    me->add("neili", -300);	
	me->add("jingli", -300);	
	
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