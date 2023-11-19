// jianzhen.c 七星剑阵

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
 string query_name() { return " 七星"ZJBR"剑阵 "; }
int perform(object me, object target)
{
	string msg;
	int i, attack_time,extra,ap,dp;
	object weapon,weapon2;
	
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("七星剑阵只能对战斗中的对手使用。\n");
	if (me->is_busy()) 
		return notify_fail("你现在正忙着呢！\n");
	if ( me->query_skill("quanzhen-jian",1) < 300) 
		return notify_fail("你的全真剑法还不够纯熟！\n");
	if( me->query_skill("xiantian-gong",1) < 300 )
		return notify_fail("你的本门内功还不够纯熟！\n");		
    if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
        return notify_fail("使用七星剑阵必须拿着一把剑！\n");
//	if( me->query_skill_mapped("force") != "tiangang-zhengqi" && me->query_skill_mapped("force") != "xiantian-qigong")	
//         return ("你必须激发本门内功才能使用「七星剑阵」！\n");  
			 
//	if (me->query_skill_mapped("sword") != "quanzhen-jian")
//		return ("你没正确激发该技能 。\n");	
	if( (int)me->query("max_neili") < 2000 )
		return  notify_fail("你的内力修为还不够高。\n");
	if( (int)me->query("max_jingli") < 2000 )
		return notify_fail("你的精力修为还不够高。\n");
	if( (int)me->query("jingli") < 1000 )
		return notify_fail("你的精力不够了。\n");	
	if( (int)me->query("neili") < me->query_skill("quanzhen-jian",1)*4  ) 
		return notify_fail("你的内力不够。\n");
	if (me->query_temp("autolian"))
		return notify_fail("你正在发动自动连招！\n"); 	
	if ( me->query_temp("cooldown") )	//CD写法	2017.9.7添加
		return notify_fail("你处于技能冷却状态中，过会在使用吧。\n");
		
	extra = me->query_skill("quanzhen-jian",1)/15;
	if( me->query_skill_mapped("force") != "tiangang-zhengqi" && me->query_skill_mapped("force") != "xiantian-gong") extra -= me->query_skill("quanzhen-jian", 1)/18;	//2018.9.5阿飞改，不使用本门特内则减益	
	if ((string)weapon->query("id") == "qixing sword") extra += me->query_skill("quanzhen-jian", 1)/15; //2018.3.25阿飞改，拿特殊武器有加成
	ap = me->query("xyzx_sys/level") + me->query_skill("quanzhen-jian", 1) + me->query_skill("sword") + me->query_skill("force");
	dp = target->query("xyzx_sys/level") + target->query_skill("force") + target->query_skill("sword");
	ap = ap*((int)me->query("breakup")+(int)me->query("breakup")*(int)me->query("breakup")+100)/100;
	dp = dp*((int)target->query("breakup")+(int)target->query("breakup")*(int)target->query("breakup")+100)/100;
	attack_time = me->query_skill("quanzhen-jian",1)/600;
	msg = RED  "$N召唤出【七星剑阵】，以手中的"+ weapon->name() +"为剑阵主剑，顿时爆发无数细小剑气击向$n！" NOR;
    message_vision(msg, me, target);
	me->set_temp("cooldown", 1);	//CD写法	2017.9.7添加
	call_out("del_cooldown", 3, me);	//CD写法1	
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	me->add_temp("apply/strength", extra);
	if (attack_time < 1) attack_time= 1;
	if (me->query("jm/quanzhen"))
	{
		if (attack_time > 100+(int)me->query_temp("lianzhao_max_add")*4) attack_time = 100+(int)me->query_temp("lianzhao_max_add")*4;	
	} else 
	{
		if (attack_time > 50+(int)me->query_temp("lianzhao_max_add")*2) attack_time = 50+(int)me->query_temp("lianzhao_max_add")*2;	
	}
	
//	me->add_temp("lianzhao", attack_time);	 //2016.6.1阿飞改，增加连招标记，用于削弱连招伤害	
	for(i=0;i < attack_time;i++)
	{
	msg = RED "$N七星剑阵，剑气不绝．．．．！\n" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_REGULAR,msg);
	}
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->add_temp("apply/strength", -extra);
	me->add("neili", -(100*attack_time));
//	me->delete_temp("lianzhao");  //2016.6.1阿飞改，连招结束取消连招标记	
	
	message_vision(GRN"\n$N收起「七星剑阵」，潜运内力将"+weapon->name()+GRN"一抖。这一下使得剑气纵横，竟然声震山谷。不明其理之人，无不骇异！\n\n" NOR, me);	
	if (random(ap)>dp/3)
	{
		if (objectp(weapon2 = target->query_temp("weapon")) )
		{
			message_vision(HIW"\n只听“嚓”的一声，$n手中的"+weapon2->name()+"被$N的内力冲击，裂成了碎片！\n"NOR,me,target);
			weapon2->unequip();
			weapon2->move(environment(target));
			weapon2->set("name", "断掉的" + weapon2->query("name"));
			weapon2->set("item_old_value", weapon2->query("value"));
			weapon2->set("value", 0);
			weapon2->set("backold_weapon_prop", weapon2->query("weapon_prop"));
			weapon2->set("weapon_prop", 0);
//			target->reset_action();
		}
		else
		{
			message_vision(HIW"\n一剑光寒十九洲，$N手中的"+weapon->name()+"经内力灌注，爆发出七星光芒！\n"NOR,me,target);
			me->add_temp("apply/damage", extra*3);
			me->add_temp("apply/attack", extra*3);
			COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_REGULAR);
			me->add_temp("apply/damage", -extra*3);
			me->add_temp("apply/attack", -extra*3);			

		}
		me->add("jingli", -500);
	}
	else
	{
		message_vision("\n$N一套「全真剑法」使完，手中"+weapon->name()+"上的光芒渐渐也消失了。\n", me,target);
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