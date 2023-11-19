// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
//#include <condition.h>
string query_name() { return HIC "沧海笑" NOR; }
string name() { return HIC "沧海笑" NOR; }

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	object weapon, weapon2;
	object *obs;
	int i,ap, dp,extra, damage,damage1;

	if (!target ) target = offensive_target(me);
	if (!target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail(name() + "只能对战斗中的对手使用。\n");		
//	if (me->is_busy()) 
//		return ("你现在正忙着呢！\n");
	
	if( !objectp(weapon = me->query_temp("weapon") ) || weapon->query("skill_type") != "sword" )
		return notify_fail("你使用的武器不对，无法施展" + name() + "。\n");
//	if (target && target->query_temp("apply/shade_vision")) 
//		return ("对方隐身了，你看不到"+target->query("name")+"。\n"); 		
	if( (int)me->query_skill("sword",1) < 300 )
		return notify_fail("你的剑法修为不够，难以施展" + name() + "。\n");
	if( target && !living(target) )
		return notify_fail("对方都已经这样了，用不着这么费力吧？\n");
	if( me->query("max_neili")<5000 ) 
		return notify_fail("你此时的内力修为不足，难以施展" + name() + "。\n"); 
	if( me->query("max_jingli")<3000 ) 
		return notify_fail("你此时的精力修为不足，难以施展" + name() + "。\n"); 			
	if( me->query("neili")<5000 ) 
		return notify_fail("你此时的内力不足，难以施展" + name() + "。\n"); 
	if( me->query("jingli")<3000 ) 
		return notify_fail("你此时的精力不足，难以施展" + name() + "。\n"); 


	if (me->query_temp("autolian"))
		return notify_fail("你正在发动自动连招！\n"); 	
	if ( me->query_temp("cooldown") )	//CD写法	2017.9.7添加
		return notify_fail("你处于技能冷却状态中，过会在使用吧。\n");
		
	ap = me->query_skill("zixia-shengong",1) + me->query_skill("dugu-jiujian", 1) + me->query_skill("sword") + me->query("level");
	dp = target->query_skill("dodge") + target->query_skill("parry");
	ap = ap*((int)me->query("breakup")+(int)me->query("breakup")*(int)me->query("breakup")+100)/100;
	dp = dp*((int)target->query("breakup")+(int)target->query("breakup")*(int)target->query("breakup")+100)/100;
	extra = me->query_skill("dugu-jiujian",1)/10 + me->query_skill("zixia-shengong",1)/10;
	obs = me->query_enemy();
	
	message_vision(HBWHT "$N贯通两种独孤九剑，使出了独孤九剑的绝学之精髓！\n" NOR, me, target);	
	message_vision(HIM "$N融汇两种独孤九剑的剑意，自此笑傲江湖，绝迹人间！\n" NOR, me, target);
	message_vision(HIY "$N虽然已不在江湖，但江湖仍然流传着$N的歌声！\n" NOR, me, target);
	me->set_temp("cooldown", 1);	//CD写法	2017.9.7添加
	call_out("del_cooldown", 5, me);	//CD写法1

	msg = HIW "$N剑气冲霄，使出「"HIG"万剑归一"HIW"」绝技，身法陡然加快，猛地连出9招！\n"NOR;
	message_vision(msg, me, target);
	me->add_temp("apply/attack", extra);
	me->add_temp("apply/damage", extra);	
	msg = HIC"第一剑！「"HIG"独孤九剑"HIY"==那一剑的惊艳=="HIC"」"NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg = HIW"第二剑！「"HIG"独孤九剑"HIC"==那一剑的浪漫=="HIW"」"NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg = HIY"第三剑！「"HIG"独孤九剑"HIW"==那一剑的凄然=="HIY"」"NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg = HIR"第四剑！「"HIG"独孤九剑"BBLU+HIW"==那一剑的风情=="NOR+HIR"」"NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg = BLU"第五剑！"HIB"「"HIG"独孤九剑"HIR"==那一剑的灿烂=="BLU"」"NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg = HIG"第六剑！「"HIG"独孤九剑"RED"==那一剑的潇洒=="HIG"」"NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg = CYN"第七剑！「"HIG"独孤九剑"HIY"==那一剑的哀愁=="NOR+CYN"」"NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg = HIW+BLK"\n第八剑！「"HIG"独孤九剑"HIB"==那一剑的寂寞=="HIW+BLK"」"NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg = MAG"第九剑！"HIR"「"HIG"独孤九剑"HIY"之"U+HIG"九"HIW"天"HIY"御"HIW+BLK"剑"HIR"术"NOR+HIR"」"NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);	
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->add("neili", -1000);
	me->add("jingli", -1000);

	if(me->query_skill("dugu-jiujian", 1) > 500 && me->query_skill("zixia-shengong", 1) > 500)
	{
		switch (random(3))
		{
		case 0:
			msg = HIY "$N" HIY "随手一剑指向$n" HIY "，落点正是$n" HIY "破绽所在，神剑之威，当真人所难测。\n" NOR;
			break;

		case 1:
			msg = HIY "$N" HIY "剑招大开大阖，看似杂乱无章，但招招皆击$n" HIY "攻势中破绽，有如神助。\n" NOR;
			break;

		default:
			msg = HIY "$N" HIY "反手横剑刺向$n" HIY "，这似有招似无招的一剑竟然威力奇大，令人匪夷所思。\n" NOR;
			break;
		}
		me->add_temp("apply/attack", extra*2);
		me->add_temp("apply/damage", extra*2);
		COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
		me->add_temp("apply/attack", -extra*2);
		me->add_temp("apply/damage", -extra*2);
		if (random(ap) > dp/3 )
		{
			damage = me->query_skill("zixia-shengong",1)*5 + me->query_skill("dugu-jiujian", 1)*me->query("int",1) + me->query_skill("sword", 1) + me->query("jiali");
			damage = damage/3 + random(damage/3) + target->query("max_qi")*2/100;
			damage = damage*(100-target->query_meridian())/100;
			target->receive_damage("qi",damage,me);
			target->receive_wound("qi",damage/2,me);
			me->add("neili", -1000);
			me->add("jingli", -1000);
			msg =HIR "$n" HIR "全然无法领会$N" HIR "剑招中的奥妙，一个疏神，登遭重创！\n" NOR;
			message_vision(msg, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//			if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
                if( me->query("jm/dugu"))
                {
    
					damage1 = weapon->query("weapon_prop/damage")+me->query_skill("zixia-shengong",1) + me->query_skill("dugu-jiujian", 1);
					damage1 = damage1/2 + random(damage1/2) + target->query("max_jing")*1/100;
					damage1 = damage1*(100-target->query_meridian())/100;
                    target->receive_damage("qi", damage1, me);
                    target->receive_wound("qi", damage1/2, me);
                    msg = HIR "紧接着，$N" HIR "追加了致命一击，给$n" HIR "造成更严重的创伤。\n" NOR;
					message_vision(msg, me, target, damage1, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//					if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage1 +"，内伤为"+ damage1/2 +"。\n"NOR);
					me->add("neili", -1000);
					me->add("jingli", -1000);					
                }
		}
		else
		{
			msg = CYN "可$n" CYN "淡然处之，并没将$N"CYN "此招放在心上，随手架开，不漏半点破绽。\n" NOR;
			message_vision(msg, me, target);
		}
		
		msg = HIW "$N" HIW "神态写意，温柔抚弄手中的" + weapon->name() + HIW "，只见" + weapon->name() +HIW "表面掠过一丝光影，微微颤动，整把剑竟灵动起来、有若生物。\n" HIM"$N"HIM"将手中"+weapon->query("name")+HIM"缓缓刺出，剑招随意无章！\n"HIM "这招看似缓慢，其实疾如闪电，看似随意无章，却是和" + weapon->name() + HIM "融为一体，无懈可击，蕴涵着返璞归真的意境。\n" NOR;
		message_vision(msg, me,target);
		me->add_temp("apply/attack", extra*2);
		me->add_temp("apply/damage", extra*2);
		for (i = 0; i < sizeof(obs); i++)
		{
			COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_REGULAR);
		}
		me->add_temp("apply/attack", -extra*2);
		me->add_temp("apply/damage", -extra*2);
		if (random(ap) > dp/3 )
		{
			damage = me->query_skill("zixia-shengong",1)*me->query("int",1) + me->query_skill("dugu-jiujian", 1)*5 + me->query_skill("sword", 1) + me->query("jiali");
			damage = damage/3 + random(damage/3) + target->query("max_qi")*2/100;
			damage = damage*(100-target->query_meridian())/100;
			target->receive_damage("qi",damage,me);
			target->receive_wound("qi",damage/2,me);
			me->add("neili", -1000);
			me->add("jingli", -1000);
			target->apply_condition("no_force", 20);
			msg = HIR "$n" HIR "想招架却感无从招架，想躲避也感到无处可躲，登时被$N" HIR "一剑划过，\n"HIR "遭受重创，一阵锥心的刺痛，全身真气源源而泻！\n" NOR;
			message_vision(msg, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//			if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
                if( me->query("jm/dugu"))
                {
    
					damage1 = weapon->query("weapon_prop/damage")+me->query_skill("zixia-shengong",1) + me->query_skill("dugu-jiujian", 1);
					damage1 = damage1/2 + random(damage1/2) + target->query("max_jing")*1/100;
					damage1 = damage1*(100-target->query_meridian())/100;
                    target->receive_damage("qi", damage1, me);
                    target->receive_wound("qi", damage1/2, me);
                    msg = HIR "紧接着，$N" HIR "追加了致命一击，给$n" HIR "造成更严重的创伤。\n" NOR;
					message_vision(msg, me, target, damage1, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//					if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage1 +"，内伤为"+ damage1/2 +"。\n"NOR);
					me->add("neili", -1000);
					me->add("jingli", -1000);
                }
		}
		else
		{
			msg = HIC "$n" HIC "情急之下，不及考虑，倒地一滚，侥幸避开$N" HIC "这一招的攻击，冷汗直淋！\n" NOR;
			message_vision(msg, me, target);
		}		
	}

	if(me->query_skill("dugu-jiujian", 1) > 800 && me->query_skill("zixia-shengong", 1) > 800)
	{	
        if( objectp(weapon2 = target->query_temp("weapon")) )
        {
            msg = HIC "$N" HIC "一袭青衫，踏歌而来，口中作歌曰：" HIB "沧海一声笑，滔滔两岸潮，浮沉随浪只记今朝\n" HIW "歌声中，只见$N" HIW "肩膀微动，一道白光瞬间击出，射向$n。  \n"  NOR;
			message_vision(msg, me, target);
			me->add_temp("apply/attack", extra*2);
			me->add_temp("apply/damage", extra*2);
			for (i = 0; i < sizeof(obs); i++)
			{
				COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_REGULAR);
			}
			me->add_temp("apply/attack", -extra*2);
			me->add_temp("apply/damage", -extra*2);
			damage = me->query_skill("zixia-shengong",1)*me->query("int",1) + me->query_skill("dugu-jiujian", 1)*me->query("int",1) + me->query_skill("sword", 1) + me->query("jiali");
			damage = damage/3 + random(damage/3) + target->query("max_qi")*2/100;
			damage = damage*(100-target->query_meridian())/100;
            if( random(ap) > dp/3 )
            {
                me->add("neili", -1000);
				me->add("jingli", -1000);
                msg = HIR "$n" HIR "大骇，连忙举起手中兵器胡乱抵挡，却不想虎口剧痛，手中" + weapon2->name() +HIR "捏不住，脱手而出。\n" NOR;
				message_vision(msg,me,target);
				if (random(3)==1) 
				{
					target->map_skill(weapon2->query("skill_type"));	//下特殊兵器
					message_vision(RED"$n被剑道入体，一时半会难以使用剑法。\n"NOR,me, target);
				}
                weapon2->unequip();
                weapon2->move(environment(me));
				target->receive_damage("qi", damage,me);
				target->receive_wound("qi", damage/2,me);
				target->apply_condition("no_equip", 20);
				msg = HIC "$N" HIC "大笑道：$n" HIC "不过如此，尝尝下面这招滋味如何？\n" NOR;
				message_vision(msg, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//				if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
                if( me->query("jm/dugu"))
                {
    
					damage1 = weapon->query("weapon_prop/damage")+me->query_skill("zixia-shengong",1) + me->query_skill("dugu-jiujian", 1);
					damage1 = damage1/2 + random(damage1/2) + target->query("max_jing")*1/100;
					damage1 = damage1*(100-target->query_meridian())/100;
                    target->receive_damage("qi", damage1, me);
                    target->receive_wound("qi", damage1/2, me);
                    msg = HIR "紧接着，$N" HIR "追加了致命一击，给$n" HIR "造成更严重的创伤。\n" NOR;
					message_vision(msg, me, target, damage1, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//					if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage1 +"，内伤为"+ damage1/2 +"。\n"NOR);
					me->add("neili", -1000);
					me->add("jingli", -1000);
                }				
            } 
			else
            {
                msg = CYN "$n" HIY "心随意动，手中" + weapon2->name() +  "轻轻一点。\n"HIY "只听[叮]的一声响，$N" HIY "轻笑道：$n" HIY "果然了得，\n" NOR;
				message_vision(msg, me, target);
            }
        }
        else
        {
			msg = HIC "$N" HIG "长歌道：" WHT" 苍天笑，纷纷世上潮，谁负谁胜出天知晓 \n" HIC "$N" HIB "随意挥洒手中的" + weapon->name() +"发出道道" HIW "剑气"HIC"，寒光闪闪，\n" HIC "从四面八方朝$n" HIC" 直射而去！\n" NOR;
			message_vision(msg, me, target);
			me->add_temp("apply/attack", extra*2);
			me->add_temp("apply/damage", extra*2);
			for (i = 0; i < sizeof(obs); i++)
			{
				COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_REGULAR);
			}
			me->add_temp("apply/attack", -extra*2);
			me->add_temp("apply/damage", -extra*2);
			damage = me->query_skill("zixia-shengong",1)*me->query("int",1) + me->query_skill("dugu-jiujian", 1)*me->query("int",1) + me->query_skill("sword", 1) + me->query("jiali");
			damage = damage/3 + random(damage/3) + target->query("max_qi")*2/100;
			damage = damage*(100-target->query_meridian())/100;
			if( random(ap) > dp/3 )
			{
				if (random(3)==1) 
				{
					target->map_skill("unarmed");	//下特殊拳脚
					message_vision(RED"$n被剑道入体，一时半会难以使用拳脚。\n"NOR,me, target);
				}
				target->receive_damage("qi", damage,me);
				target->receive_wound("qi", damage/2,me);
				me->add("neili", -1000);
				me->add("jingli", -1000);
				target->apply_condition("no_exert", 20);
                msg = HIR "$n" HIR "被漫天剑气惊得面如土色，只觉避无所避，挡无可挡，转眼间" HIW "剑气" HIR "临身全身各大穴道鲜血喷溅！\n\n" NOR;
				message_vision(msg, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//				if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
                if( me->query("jm/dugu"))
                {
    
					damage1 = weapon->query("weapon_prop/damage")+me->query_skill("zixia-shengong",1) + me->query_skill("dugu-jiujian", 1);
					damage1 = damage1/2 + random(damage1/2) + target->query("max_jing")*1/100;
					damage1 = damage1*(100-target->query_meridian())/100;
                    target->receive_damage("qi", damage1, me);
                    target->receive_wound("qi", damage1/2, me);
                    msg = HIR "紧接着，$N" HIR "追加了致命一击，给$n" HIR "造成更严重的创伤。\n" NOR;
					message_vision(msg, me, target, damage1, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//					if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage1 +"，内伤为"+ damage1/2 +"。\n"NOR);
					me->add("neili", -1000);
					me->add("jingli", -1000);
                }
			} else
			{
                msg = CYN "$n" CYN "眼见漫天" HIW "剑气" CYN "，势不可挡，身法连闪之下，堪堪避了开去，惊出一身冷汗！\n\n" NOR;
				message_vision(msg, me, target);
			}
        }
		
		msg = HIY "$N" HIY "握紧" + weapon->name() + HIY "向天一指, 叫道 : 剑魂一出 ～ 血光漫天 ～ \n"HIY "顿时" + weapon->name() + HIY "剑身化出一道红色的剑形，在天空中恣意飞旋穿梭 ...\n" NOR;
		message_vision(msg, me,target);
		me->add_temp("apply/attack", extra*2);
		me->add_temp("apply/damage", extra*2);
		for (i = 0; i < sizeof(obs); i++)
		{
			COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_REGULAR);
		}
		me->add_temp("apply/attack", -extra*2);
		me->add_temp("apply/damage", -extra*2);
		if (random(ap) > dp/3 )
		{
			damage = me->query_skill("zixia-shengong",1)*me->query("int",1) + me->query_skill("dugu-jiujian", 1)*me->query("int",1) + me->query_skill("sword", 1) + me->query("jiali");
			damage = damage/3 + random(damage/3) + target->query("max_qi")*2/100;
			damage = damage*(100-target->query_meridian())/100;
			target->receive_damage("qi",damage,me);
			target->receive_wound("qi",damage/2,me);
			me->add("neili", -1000);
			me->add("jingli", -1000);
			msg = HIC "$n" HIR "被剑魂入侵，魂不守舍，登时被$N" HIC "一剑划过，\n"HIC "遭受重创，鲜血四射，浑身伤口不断增加！\n" NOR;
			message_vision(msg, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//			if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
                if( me->query("jm/dugu"))
                {
    
					damage1 = weapon->query("weapon_prop/damage")+me->query_skill("zixia-shengong",1) + me->query_skill("dugu-jiujian", 1);
					damage1 = damage1/2 + random(damage1/2) + target->query("max_jing")*1/100;
					damage1 = damage1*(100-target->query_meridian())/100;
                    target->receive_damage("qi", damage1, me);
                    target->receive_wound("qi", damage1/2, me);
                    msg = HIR "紧接着，$N" HIR "追加了致命一击，给$n" HIR "造成更严重的创伤。\n" NOR;
					message_vision(msg, me, target, damage1, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//					if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage1 +"，内伤为"+ damage1/2 +"。\n"NOR);
					me->add("neili", -1000);
					me->add("jingli", -1000);
                }
		}
		else
		{
			msg = HIC "$n" HIC "情急之下，不及考虑，倒地一滚，侥幸避开$N" HIC "这一招的攻击，冷汗直淋！\n" NOR;
			message_vision(msg, me, target);
		}
	}
        
	if(me->query_skill("dugu-jiujian", 1) > 1200 && me->query_skill("zixia-shengong", 1) > 1200)
	{
		msg = HIB "$N" HIY "握紧" + weapon->name() + HIB "竖立胸前，祭出心血, 顿时剑光大作，血光冲天，剑魂之力大涨！ \n"
	      HIB "顿时" + weapon->name() + HIB "剑身化出无数道血红色的剑形，在天空中恣意飞旋穿梭 ...\n" NOR;
		message_vision(msg, me,target);	
		message_vision(HIR "\n漫天剑魂以闪电般的高速在空中穿梭, 以狂乱无比的热情尽情狂舞 ...\n" NOR, me);
		me->add_temp("apply/attack", extra*2);
		me->add_temp("apply/damage", extra*2);
		for (i = 0; i < sizeof(obs); i++)
		{
			COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_REGULAR);
		}
		me->add_temp("apply/attack", -extra*2);
		me->add_temp("apply/damage", -extra*2);
		if (random(ap) > dp/3 )
		{
			damage = me->query_skill("zixia-shengong",1)*me->query("int",1) + me->query_skill("dugu-jiujian", 1)*me->query("int",1) + me->query_skill("sword", 1) + me->query("jiali");
			damage = damage/3 + random(damage/3) + target->query("max_qi")*2/100;
			damage = damage*(100-target->query_meridian())/100;
			target->receive_damage("qi",damage,me);
			target->receive_wound("qi",damage/2,me);
			me->add("neili", -1000);
			me->add("jingli", -1000);
			target->apply_condition("no_enforce", 20);
			msg = HIG "$n" HIG "被血剑穿心，漫天剑魂，根本就无法闪避！" HIG "剑光所到之处，万剑臣服！\n"HIG "$n五官七窍无处不流血，浑身筋脉似乎没有完好的！\n" NOR;
			message_vision(msg, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//			if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
                if( me->query("jm/dugu"))
                {
    
					damage1 = weapon->query("weapon_prop/damage")+me->query_skill("zixia-shengong",1) + me->query_skill("dugu-jiujian", 1);
					damage1 = damage1/2 + random(damage1/2) + target->query("max_jing")*1/100;
					damage1 = damage1*(100-target->query_meridian())/100;
                    target->receive_damage("qi", damage1, me);
                    target->receive_wound("qi", damage1/2, me);
                    msg = HIR "紧接着，$N" HIR "追加了致命一击，给$n" HIR "造成更严重的创伤。\n" NOR;
					message_vision(msg, me, target, damage1, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//					if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage1 +"，内伤为"+ damage1/2 +"。\n"NOR);
					me->add("neili", -1000);
					me->add("jingli", -1000);
                }
		}
		else
		{
			msg = HIC "$n" HIG "见满天都是血色剑魂，心知无法闪避，只好运转全身真气来阻挡$N" HIG "这一招的攻击，总好过被剑魂穿心吧。\n" NOR;
			message_vision(msg, me, target);
		}
		
		message_vision("\n"HIY"$N的人与剑已开始有了动作，一种极缓慢，极优美的动作，就像是风那么自然\n"HIY"$N的瞳孔在收缩，"+weapon->name()+""HIY"已慢慢的刺了出来\n"HIY"从最不可思议的部位刺了出来，刺出时忽然又有了最不可思议的变化\n"HIY"世上根本没有人能破这一剑，绝对没有任何人能谁想去破这一剑，就是去送死\n\n"NOR,me,target);
		me->add_temp("apply/attack", extra*2);
		me->add_temp("apply/damage", extra*2);
		for (i = 0; i < sizeof(obs); i++)
		{
			COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_REGULAR);
		}
		me->add_temp("apply/attack", -extra*2);
		me->add_temp("apply/damage", -extra*2);
		if(random(10)>=3)
		{

			damage = me->query_skill("zixia-shengong",1)*me->query("int",1) + me->query_skill("dugu-jiujian", 1)*me->query("int",1) + me->query_skill("sword", 1) + me->query("jiali");
			damage = damage/3 + random(damage/3) + target->query("max_qi")*2/100 + target->query("max_jing")*2/100;
			damage = damage*(100-target->query_meridian())/100;
			target->add("neili", -damage);
			target->receive_damage("qi", damage,me);
			target->receive_wound("qi", damage/2,me);
			target->receive_damage("jing", damage,me);
			target->receive_wound("jing", damage/2,me);			
			me->add("neili",-1000);
			me->add("jingli", -1000);
			target->apply_condition("no_perform", 20);
			message_vision(HIR"血花耀眼又灿烂，灿烂的婉如流星，流星一现即逝，血花也很快的洒下\n"NOR, me,target, damage, HBWHT+HIM"精气伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//			if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"，精神的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
		}
		else
		{
			message_vision(HIB"$n 心守一处，看清了$N的攻势，不徐不疾的避了开来！\n"NOR,me,target);
		}

	}	
	if( target->query("qi") < target->query("max_qi")*20/100 || target->query("jing") < target->query("max_jing")*20/100 )
	{
		msg = HIR "$N" HIR "见$n" HIR"浑身浴血，已是摇摇欲坠，叹了一声道： \n" NOR
                HIM "人生苦短，还是早早投胎去吧！手中" + weapon->name() +" 一挥！\n" NOR
                HIY "$n" HIR "喉中咯咯作响，面上尽是不甘之色，终于倒了下去。 \n\n" NOR;
		msg += HIC"$N" HIC "青衫飘飘而去，歌声如风：清风笑，竟惹寂寥，豪情还剩了一襟晚照~~~ \n\n\n" NOR;
		message_vision(msg, me, target);
		target->die(me);
		me->start_busy(1);		
		return 1;	//这里其实应该加个return 1的，昏迷之后理应中断PFM
	}	
	msg = HIC"$N" HIC "青衫飘飘而去，歌声如风：苍生笑，不再寂寥，豪情仍在痴痴笑笑~~~~~~ \n\n\n" NOR;
	message_vision(msg, me, target);
		
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