// dashouyin dashou-yin perform
// by dubei

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";
string query_name() { return "大"ZJBR"手印 "; }
inherit F_SSERVER;

int perform(object me, object target)
{
	int damage, jiali, ap, dp;
	object armor;

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) || !living(target) )
		return notify_fail("「大手印」只能在战斗中对对手使用。\n");
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手使用「大手印」！\n");	
    if(me->is_busy())
        return notify_fail("你现在正忙着！\n");
	if( (int)me->query_skill("dashou-yin",1) < 200 )
		return notify_fail("你的大手印不够娴熟，不会使用密宗神功「大手印」！\n");
//	if (target && target->query_temp("apply/shade_vision")) 
//		return ("对方隐身了，你看不到"+target->query("name")+"。\n"); 
	if( (int)me->query_skill("hand",1) < 200 )
		return notify_fail("你的基本手法不够娴熟，不会使用密宗神功「大手印」！\n");
	if( (int)me->query_skill("longxiang-boruo",1) < 200 )
		return notify_fail("你对密宗的内功了解不够，不能使用「大手印」！\n");
	if( (int)me->query("max_neili") < 2000 )
		return notify_fail("你的内力修为太弱，不能使用「大手印」！\n");
	if( (int)me->query("max_jingli") < 1000 )
		return notify_fail("你的精力修为太弱，不能使用「大手印」！\n");
	if( (int)me->query("neili") < 1000 )
		return notify_fail("你的内力太少了，无法使用出「大手印」！\n");
	if( (int)me->query("jingli") < 1000 )
		return notify_fail("你精力衰竭，无法使用出「大手印」！\n");	
//	if ( me->query_skill_mapped("force") != "longxiang" && me->query_skill_mapped("force") != "xiaowuxiang")
//		return ("你未使用本门内功！\n");
//	if ( me->query_skill_mapped("unarmed") != "dashou-yin" )
//		return ("你现在无法使用「大手印」！\n");
	if (me->query_temp("autolian"))
		return notify_fail("你正在发动自动连招！\n"); 	
	if ( me->query_temp("cooldown") )	//CD写法	2017.9.7添加
		return notify_fail("你处于技能冷却状态中，过会在使用吧。\n");
		
	jiali = me->query("jiali")+1;

	ap = me->query("level") + me->query_skill("dashou-yin", 1) + me->query_skill("hand") + me->query_skill("force") + me->query("max_neili")/10000;
	dp = target->query("level") + target->query_skill("dodge") + target->query_skill("parry") + target->query("max_neili")/10000;
	ap = ap*((int)me->query("breakup")+(int)me->query("breakup")*(int)me->query("breakup")+100)/100;
	dp = dp*((int)target->query("breakup")+(int)target->query("breakup")*(int)target->query("breakup")+100)/100;
	damage = me->query_skill("dashou-yin",1) + me->query_skill("force",1) + jiali;
	damage = damage/2 + random(damage/2);
	damage = damage*(100-target->query_meridian())/100;
	message_vision(BLU"\n$N突然面色怪异，低声默念密宗真言，双臂骨节一阵爆响，猛然腾空而起，伸手向$n胸前按去，好一式密宗「大手印」！\n"NOR,me,target);
	me->set_temp("cooldown", 1);	//CD写法	2017.9.7添加
	call_out("del_cooldown", 3, me);	//CD写法1
	if( random(ap) > dp/3 )
	{
		if( objectp(armor = target->query_temp("armor/cloth")) && armor->query("armor_prop/armor") < 10000 && damage > 500)
		{
			message_vision(HIY"只见这斗大的手印正好印在$N的$n"HIY"上，越变越大，竟将它震得粉碎，裂成一块块掉在地上！\n"NOR, target);
			armor->unequip();
			armor->move(environment(target));
			armor->set("name", "破碎的" + armor->query("name"));
			armor->set("item_old_value", armor->query("value"));
			armor->set("value", 0);
			armor->set("backold_armor_prop", armor->query("armor_prop"));
			armor->set("armor_prop", 0);
//			target->reset_action();
		}
		target->receive_damage("qi", damage,  me);
		target->receive_wound("qi", damage/2, me);
		me->add("neili", -jiali);		
		message_vision(RED"$n只觉得霍的胸口一阵剧痛，已经被拍中了前胸！\n"NOR, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
	}
	else
	{
		message_vision( CYN"可是$n看破了$N的企图，并没有上当。\n"NOR,me,target);
	}
	me->add("neili", -500);
	me->add("jingli", -500);
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