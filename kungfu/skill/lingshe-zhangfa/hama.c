#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
//#include <condition.h>
#include "/kungfu/skill/eff_msg.h"
inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra,damage,ap,dp;
	int equip,ak,dk;	
	object weapon;
	object *inv;
	
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail(HIC"只能在战斗中使用。\n"NOR);
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "staff")
		return notify_fail(HIC"你使用的武器不对。\n"NOR);
	if(me->is_busy())
		return notify_fail(HIC"你现在没空！！\n"NOR);
//	if (target && target->query_temp("apply/shade_vision")) 
//		return ("对方隐身了，你看不到"+target->query("name")+"。\n"); 
//    if (me->query("family/family_name")!="白驼山派")
//		return (HIC"你不加入老毒物门下，使用老毒物的看家绝技怕是离死不远了！。\n"NOR);		
	if( (int)me->query("neili") < 2000  )
		return notify_fail(HIC"你的内力不够。\n"NOR);
	if( (int)me->query("jingli") < 2000  )
		return notify_fail(HIC"你的精力不够。\n"NOR);
	if( (int)me->query("max_neili") < 5000 )
		return notify_fail(HIC"你的内力修为不够。\n"NOR);
	if( (int)me->query("max_jingli") < 5000 )
		return notify_fail(HIC"你的精力修为不够。\n"NOR);
	if( (int)me->query_skill("lingshe-zhangfa", 1) < 300 )
		return notify_fail(HIC"你的灵蛇杖法不够熟练!不能贯通使用！\n"NOR);
	if( (int)me->query_skill("chanchu-bufa", 1) < 300 )
		return notify_fail(HIC"你的蟾蜍步法不够熟练!不能贯通使用！\n"NOR);
	if( (int)me->query_skill("hamagong", 1) < 300 )
		return notify_fail(HIC"你的蛤蟆功不够熟练!不能贯通使用！\n"NOR);
	if (me->query_skill_mapped("staff") != "lingshe-zhangfa")
		return notify_fail(HIC"你没有激发灵蛇杖法，难以施展。\n"NOR);
	 if ( me->query_skill_mapped("dodge") != "chanchu-bufa")
         return notify_fail("蛤蟆功必须要有对应的步法配合！\n");  
	if ( !wizardp(me) && me->query_skill_mapped("force") != "hamagong")
		return notify_fail(HIC"不使用本门内功，如何使用本门绝学!\n"NOR);
	
	
	if ( me->query_temp("cooldown") )	//CD写法	
		return notify_fail("你处于技能冷却状态中，过会在使用吧。\n");
		
	ap = me->query("xyzx_sys/level") + me->query_skill("lingshe-zhangfa", 1) + me->query_skill("hamagong",1)+ me->query_skill("chanchu-bufa",1) + me->query_skill("staff") + me->query_skill("force");
	dp = target->query("xyzx_sys/level") + target->query_skill("dodge") + target->query_skill("parry");	
	ap = ap*((int)me->query("breakup")+(int)me->query("breakup")*(int)me->query("breakup")+100)/100;
	dp = dp*((int)target->query("breakup")+(int)target->query("breakup")*(int)target->query("breakup")+100)/100;
	msg = HBWHT "$N贯通白驼武学，使出了白驼的绝学之精髓！\n" NOR;	
	message_vision(msg, me, target);
	me->set_temp("cooldown", 1);	//CD写法	
	call_out("del_cooldown", 5, me);	//CD写法1	
	extra = me->query_skill("hamagong",1)/10;
	me->add_temp("apply/attack",extra);
	me->add_temp("apply/damage",extra);
	weapon = me->query_temp("weapon");

	msg = HIY "$N跳出数丈外，突然一声暴喝：“------ 狂 ----- 风 ----- 扫 ----- 落 ----- 叶 ----- ！！！”" NOR;
	message_vision(msg, me, target);
	msg =  YEL  "$N身形加快，所到之处，狂风四起！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  YEL  "$N突如起来的从狂风中闪出，对着$n胸前就是一杖！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = YEL  "$N御杖回身，立于$n身侧，反手一劈！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = YEL  "$N借力打力，一个纵身，居高临下，当头又是一杖！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = YEL  "人在半空，$N化虚为掌，化实为杖，朝$n点刺过去！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = YEL "$N持杖乱舞，密不透风，使$n渐渐感到透不过气来！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = YEL "$N见有机可乘，一杖接着一杖，招招致命！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = YEL "$N聚起天地之灵气，手中的"+ weapon->name() +"卷起千层大浪朝$n挥去！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	me->add_temp("apply/attack",-extra);
	me->add_temp("apply/damage",-extra);		
	if (random(ap) > dp/3 )
	{
		msg = RED "蛇毒" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		target->apply_condition("snake_poison",20);
		msg = RED "蟾蜍毒" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		target->apply_condition("chanchu_poison",20);
		msg = RED "七修蛇毒" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		target->apply_condition("qx_snake_poison",20);
	}
	me->add("neili", 2000);
		
if (me->query_skill("lingshe-zhangfa",1) > 500 && me->query_skill("chanchu-bufa",1) > 500)
{	
	msg = BLU "\n$N身子蹲下，左掌平推而出，使的正是$N生平最得意的「蛤蟆功」绝招，掌风直逼$n而去！\n"NOR;
	message_vision(msg, me, target);

	if( random(ap) > dp/3 )
	{
		me->add("neili", -1000);
		me->add("jingli", -1000);
		damage = me->query_skill("hamagong",1) + me->query_skill("lingshe-zhangfa",1) + me->query_skill("chanchu-bufa",1);
		damage = damage/2 + random(damage/2);
		damage = damage*(100-target->query_meridian())/100;
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		msg = HIG "\n$n正要出手反击，哪知$N排山倒海的掌力直接将$n击的到飞而去！\n"NOR;
		message_vision(msg, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//优化化学伤害显示的写法
//		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
	}
	else
	{
		me->add("neili", -1000);
		message_vision( HIY"$n但觉一股微风扑面而来，风势虽然不劲，然已逼得自己呼吸不畅，知道不妙，连忙跃开数尺。\n" NOR,me, target);			
	}
}
	
if (me->query_skill("lingshe-zhangfa",1) > 800 && me->query_skill("chanchu-bufa",1) > 800)
{
	msg = BLU "\n$N左掌劲力未消，右掌也跟着推出，功力相叠，「蛤蟆功」掌风排山倒海般涌向$n！\n"NOR;
	message_vision(msg, me, target);
	if( random(ap) > dp/3 )
	{
		if (me->query("jm/baituo"))
			damage = me->query_skill("hamagong")*me->query("con",1)/3 + me->query_skill("lingshe-zhangfa")*5 + me->query_skill("chanchu-bufa");
		else damage = me->query_skill("hamagong")*me->query("con",1)/4 + me->query_skill("lingshe-zhangfa")*2 + me->query_skill("chanchu-bufa");
		me->add("neili", -1000);
		me->add("jingli", -2000);		
		damage = damage/4 + random(damage/4);
		damage = damage*(100-target->query_meridian())/100;
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		msg = HIR "\n$n一步跃出，躲开$N左掌，然未堤防到$N右掌已至，被击个正着！\n"NOR;
		message_vision(msg, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//优化化学伤害显示的写法
//		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
	}
	else
	{
		message_vision(HIY"你喘息未定，又觉一股劲风扑面而来，连忙跃开数尺，狼狈地避开。\n" NOR, me, target);
		if (me->query("jm/baituo"))
		{
			message_vision( HIC"然而$N突然经脉逆转，$n虽然闪避了这一招，但是仍然受到莫名影响，浑身真气逆行而上，内力大损。\n" NOR,me, target);
			damage = me->query_skill("hamagong")*me->query("con",1)/5 + me->query_skill("lingshe-zhangfa",1) + me->query_skill("force",1);
			damage = damage/5 + random(damage/5);
			damage = damage*(100-target->query_meridian())/100;
			target->add("jingli", -damage);
			target->add("neili", -damage);	
		}
	}

}	
	
if (me->query_skill("lingshe-zhangfa",1) > 1200 && me->query_skill("chanchu-bufa",1) > 1200 )
{
	msg = BLU "\n$N双腿一登，双掌相并向前猛力推出，$n连同身前方圆三丈全在「蛤蟆功」劲力笼罩之下！\n"NOR;
	message_vision(msg, me, target);
	if( random(ap) > dp/3 )
	{
		me->add("jingli", -300);
		me->add("neili", -1000);
		if (me->query("jm/baituo")) 
			damage = me->query_skill("hamagong", 1)* me->query("con",1)*3/2 + me->query_skill("lingshe-zhangfa",1)* me->query("con",1)*3/2 + me->query_skill("chanchu-bufa",1)* me->query("con",1)*3/2 + me->query_skill("hamagong") + me->query_skill("lingshe-zhangfa") + me->query_skill("chanchu-bufa")+me->query_skill("staff",1)+me->query_skill("dodge",1)+me->query_skill("force",1);
		else damage = me->query_skill("hamagong", 1)* me->query("con",1) + me->query_skill("lingshe-zhangfa",1)* me->query("con",1) + me->query_skill("chanchu-bufa",1)* me->query("con",1) + me->query_skill("hamagong") + me->query_skill("lingshe-zhangfa") + me->query_skill("chanchu-bufa")+me->query_skill("staff",1)+me->query_skill("dodge",1)+me->query_skill("force",1);
		damage = damage/3 + random(damage/3) + me->query("qi")*4/100;
		damage = damage*(100-target->query_meridian())/100;
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/3,me);
		message_vision(HIM"$N紧接着双掌平推，一道如山般的巨掌向$n扑面而来！\n"NOR,me,target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/3 +"。\n" NOR);
		if (me->query("jm/baituo"))
		{
			target->receive_damage("jing", damage/3,me);
			target->receive_wound("jing", damage/6,me);
			message_vision( HIC"$N眼中精光一闪，突然 “呱” 的一声，$n如中雷击，全身真气逆行，顿时肝肠寸断，精神萎靡。\n" NOR,me, target, damage/3, HBWHT+HIM"精神伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法			
//			if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人追加精神的外伤为"+ damage/3 +"，内伤为"+ damage/10 +"。\n" NOR);

			message_vision(HIB"$n被掌风刮过，浑身上下凉飕飕的，似乎被细雨淋过，一股腥气！\n"NOR,me,target);
			inv = all_inventory(target);
			ak = sizeof(inv);
			if (ak>3) ak=3;
			dk=random(ak);
			for(equip=0; equip<dk; equip++)
			{	//一定几率碎腰带、裤子、鞋子
				if( inv[equip]->query("equipped") 
				&& (inv[equip]->query("armor_type")=="waist" || inv[equip]->query("armor_type")=="pants" || inv[equip]->query("armor_type")=="boots") )	
			{
				message_vision( HIR"$n身穿的"+inv[equip]->query("name")+HIR+"沾满了蛤蟆毒液，$n手忙脚乱地把它脱了下来，丢弃在地上！\n"+NOR,me,target);
				inv[equip]->unequip();
//				inv[equip]->reset_action();
				inv[equip]->move(environment(target));
				inv[equip]->set("name",  "破碎的" + inv[equip]->query("name"));
				inv[equip]->set("item_old_value", inv[equip]->query("value"));
				inv[equip]->set("value", 0);
				inv[equip]->set("backold_armor_prop", inv[equip]->query("armor_prop"));
				inv[equip]->set("armor_prop", 0);
//				inv[equip]->set("long", "这是一件碎得无法再穿的"+inv[equip]->query("name")+"。\n");
				if( !target->is_killing(me) ) target->kill_ob(me);
				message_vision( HIW"$N摧毁了$n的装备！$n非得跟你玩命不可！\n"+NOR,me,target);			
			}
			}			
			
		}		
	}
	else
	{
		me->add("neili", -1000);
		message_vision(HIY"你用尽全身力量向右一纵一滚，摇摇欲倒地站了起来，但总算躲开了这致命的一击！\n" NOR, me, target);
		if (me->query("jm/baituo"))
		{
			damage = me->query_skill("dodge", 1) + me->query_skill("force",1) + me->query_skill("hamagong")*me->query("con",1) + me->query_skill("chanchu-bufa");
			damage = damage/5 + random(damage/5);
			damage = damage*(100-target->query_meridian())/100;
			target->receive_damage("jing", damage,me);
			target->receive_wound("jing", damage/2,me);
			message_vision( HIC"然而$N突然经脉逆转，$n虽然躲开了这致命一击，但是$N蛤蟆功诡异至极，你经脉真气渐渐的紊乱，痛苦无比。\n" NOR,me, target, damage, HBWHT+HIM"精神伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//			if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人精神的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
		}
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
