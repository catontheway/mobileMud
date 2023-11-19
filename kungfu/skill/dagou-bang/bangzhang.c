// bangzhang棒掌双绝

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>


inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	string msg;
	int damage,extra;
	int ap,dp;

//	if (!wizardp(me)) return ("巫师突然从黑暗中冲了出来，对你大吼一声：第3版本该绝招被查封。\n");	
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("这门绝学只能对战斗中的对手使用。\n");		
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");

	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	if( (int)me->query("max_neili") < 5000  )
		return notify_fail("你的内力不够。\n");
	if( (int)me->query("neili") < 5000 )
		return notify_fail("你的内力不够。\n");
	if( (int)me->query("jingli") < 5000 )
		return notify_fail("你的精力不够。\n");	
	if( (int)me->query_skill("xianglong-zhang", 1) < 300 )
		return notify_fail("你的降龙掌等级不够!不能贯通使用！\n");
	if( (int)me->query_skill("dagou-bang", 1) < 300 )
		return notify_fail("你的打狗棒等级不够!不能贯通使用！\n");
	if( (int)me->query_skill("huntian-qigong", 1) < 300 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");
	if (me->query_skill_mapped("staff") != "dagou-bang")
		return notify_fail("你用了打狗棒法了吗？？ 。\n");	
	if (me->query_skill_mapped("strike") != "xianglong-zhang")
		return notify_fail("你拳脚用的似乎不对吧 。\n");	
	if ( !wizardp(me) && me->query_skill_mapped("force") != "huntian-qigong")
		return notify_fail("不使用本门内功，如何使用本门绝学!\n");
	
	if (me->query_temp("autolian"))
		return notify_fail("你正在发动自动连招！\n"); 	
	if ( me->query_temp("cooldown") )	//CD写法	2017.9.7添加
		return notify_fail("你处于技能冷却状态中，过会在使用吧。\n");
		
	msg = HBWHT "$N贯通丐帮武学，使出了丐帮的绝学之精髓！\n" NOR;
	message_vision(msg, me, target);
	me->set_temp("cooldown", 1);	//CD写法	2017.9.7添加
	call_out("del_cooldown", 5, me);	//CD写法1	
	extra = me->query_skill("dagou-bang",1)/10 ;
	damage = me->query_skill("dagou-bang",1) + me->query_skill("xianglong-zhang",1) + me->query_skill("club",1)  + me->query_skill("unarmed",1) + me->query("jiali");
	ap = me->query("xyzx_sys/level") + me->query_skill("xianglong-zhang", 1) + me->query_skill("dagou-bang", 1) + me->query_skill("unarmed") + me->query_skill("club");
	dp = target->query("xyzx_sys/level") + target->query_skill("dodge") + target->query_skill("parry");
	ap = ap*((int)me->query("breakup")+(int)me->query("breakup")*(int)me->query("breakup")+100)/100;
	dp = dp*((int)target->query("breakup")+(int)target->query("breakup")*(int)target->query("breakup")+100)/100;
	damage = damage/3 + random(damage/3);	
	damage = damage*(100-target->query_meridian())/100;
	msg = HIR"$N怒喝一声，横过"+ weapon->name()+HIG"一搭，借势跃起，人未至，棒先到，凌虚下击，连施三下杀手！\n" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = WHT  "$N转过"+ weapon->name()+HIG"，刷刷刷连进三棒，棒法快捷无伦，都是打狗棒法中的杀招！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIC  "$N突然飞出"+ weapon->name()+HIG"，迎面劈向$n，这棒连戳三下，竟在霎时之间分点$p胸口三处大穴！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
//	if (!target->is_busy() && random(2)==0)  target->start_busy(3);	
	me->add("neili", -1000);
	target->receive_damage("qi",damage,me);		
	target->receive_wound("qi",damage/3,me);
	msg = YEL "$N心中一急,没头没脑的向前面打了出去,但正是打狗棒法的精要之所在！\n" NOR;
	message_vision(msg, me,target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法	
//	if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的内伤为"+ damage/3 +"。\n" NOR);
	
if( (int)me->query_skill("dagou-bang", 1) > 500 )	
{	
	extra = me->query_skill("dagou-bang",1)/10 ;
		me->add_temp("apply/attack",extra);
		me->add_temp("apply/damage",extra);	
	msg = RED "$N横棒挥出，变守为攻，发挥出打狗棒法中的攻手，连进了三记杀招！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = RED "第一招 $N横棒挥出，使出了封字决！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = RED "第二招 $N横棒挥出，使出了转字决！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = RED "第三招 $N横棒挥出，使出了拌字决！！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		me->add_temp("apply/attack",-extra);
		me->add_temp("apply/damage",-extra);
	me->add("neili", -1000);	
}

if( (int)me->query_skill("xianglong-zhang", 1) > 500 )	
{	
	extra = me->query_skill("xianglong-zhang",1)/10;
	msg = YEL "$N双掌平平提到胸前，神色沉重的缓缓施出降龙十八掌的最后一招「"+HIY"亢"NOR+HIC"龙"NOR+HIW"无"NOR+HIR"悔"NOR+YEL"」一招八式推向$n！" NOR;
	message_vision(msg, me, target);
	weapon->unequip();
		me->add_temp("apply/attack",extra);
		me->add_temp("apply/damage",extra);
	msg =  HIC  "第一式！$N右掌一式「龙现于野」，勇猛无比地劈向$n！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIR  "第二式！$N双掌施出一式「鸿龙在陆」，隐隐约约带着掌风拍向$n！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIB  "第三式！$N左掌御胸，右掌一式「潜龙出海」缓缓推向$n！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIY  "第四式！$N使出「龙跃在天」，向$n的连拍数掌！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIG "第五式！$N双掌一式「双龙戏水」一前一后按向$n的胸前！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIM  "第六式！$N身形转动，使出「晴天六龙」向$n连打六下！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = YEL  "第七式！$N脚下一转，突然欺到$n身前，一式「龙战于野」直拍向$n面门" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIW "第八式！$N突然飞起，双掌居高临下最后一式「龙啸九天」全力拍向$n！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		me->add_temp("apply/attack",-extra);
		me->add_temp("apply/damage",-extra);
	me->add("neili", -1000);
	weapon->wield();
}	

if( me->query_skill("xianglong-zhang", 1) > 1000 && me->query_skill("dagou-bang", 1) > 1000)
{
	if (me->query("jm/gaibang"))
		damage = me->query_skill("dagou-bang",1)*me->query("int",1)*3/2 + me->query_skill("xianglong-zhang",1)*me->query("str",1)*3/2 + me->query_skill("huntian-qigong",1)*me->query("int",1)*3/2 + me->query_skill("force",1) + me->query_skill("unarmed",1) + me->query_skill("club",1);
	else damage = me->query_skill("dagou-bang",1)*me->query("int",1) + me->query_skill("xianglong-zhang",1)*me->query("str",1) + me->query_skill("huntian-qigong",1)*me->query("str",1) + me->query_skill("force",1) + me->query_skill("unarmed",1) + me->query_skill("club",1);	
	
	if (random(ap) > dp/3)
	{	
		damage = damage/3 + random(damage/3) + target->query("jing")*5/100;
		damage = damage*(100-target->query_meridian())/100;
		if (random(4)==1) 
		{
			target->map_skill("parry");	//下特殊招架
			message_vision(RED"$n被连敲带打，脚下错乱难以招架。\n"NOR,me, target);
		}
		me->add("neili", -3000);
		target->receive_damage("qi",damage,me);
		target->receive_wound("qi",damage/2,me);		
		msg = HIR"$N咬紧牙关，双掌护身，心中默念降龙十八掌的口诀!"+HIY"亢"NOR+HIC"龙"NOR+HIW"无"NOR+HIR"悔!!"NOR+" ";
		msg += HIR"$N寒光一闪，杀意大增，心中默念打狗棒法的口诀!"+HIY"天"NOR+HIC"下"NOR+HIW"无"NOR+HIR"狗!!"NOR+" ";
		msg += HIB"\n$n被降龙掌和打狗棒同时击中，浑身麻痹，似乎忘了招架！\n"NOR;		
		msg += RED"\n结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n"NOR;
		message_vision(msg, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
//		if (!target->is_busy()) target->start_busy(3);
	} else
	{
		damage = damage/15 + random(damage/15) + target->query("jing")*1/100;
		damage = damage*(100-target->query_meridian())/100;
		target->receive_damage("qi",damage,me);
		target->receive_wound("qi",damage/2,me);
		me->add("neili", -1000);
		msg = RED"\n$N浑然一笑，潇潇洒洒扬长而去，$n呆若木鸡，一招击在空处！\n"NOR;		
		msg += HIC"\n然而，$n嘿嘿一笑，棒头掉转，反手一招"+HIB"神"NOR+HIR"龙"NOR+HIC"摆"NOR+HIM"尾!!"NOR+"！正中$N胸口。\n"NOR;
		message_vision(msg, target, me, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage/5 +"，内伤为"+ damage/10 +"。\n" NOR);	
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