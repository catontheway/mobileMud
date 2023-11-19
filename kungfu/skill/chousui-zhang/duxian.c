// 毒仙炎
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
//#include <condition.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,damage,ap,dp;
	
	if( !target ) target = offensive_target(me);
	if (!target || !target->is_character() || !me->is_fighting(target))
		return notify_fail("只能在战斗中使用。\n");
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用这个绝技！\n");
	
	if( me->is_busy())
		return notify_fail("你现在没空！！\n");
	if( (int)me->query("max_neili") < 3000  )
		return notify_fail("你的内力修为不够。\n");
	if( (int)me->query("max_jingli") < 1000  )
		return notify_fail("你的精力修为不够。\n");
	if( (int)me->query("neili") < 2000 )
		return notify_fail("你的内力不够。\n");
	if( (int)me->query("jingli") < 5000 )
		return notify_fail("你的精力不够。\n");
	if( !wizardp(me) &&(int)me->query_skill("tianshan-zhang", 1) < 300 )
		return notify_fail("你的天山杖法等级太低!不能贯通使用毒仙炎！\n");
	if(!wizardp(me) && (int)me->query_skill("chousui-zhang", 1) < 300 )
		return notify_fail("你的抽髓掌等级太低!不能贯通使用毒仙炎！\n");
	if(!wizardp(me) && (int)me->query_skill("huagong-dafa", 1) < 300 )
		return notify_fail("你的化工大法等级太低!不能贯通使用毒仙炎！\n");
	if ( me->query_skill_mapped("strike") != "chousui-zhang")
		return notify_fail("你必须激发该技能才能使用!\n");
	if ( !wizardp(me) && me->query_skill_mapped("force") != "huagong-dafa")
		return notify_fail("不使用本门内功，如何使用本门绝学!\n");

	if (me->query_temp("autolian"))
		return notify_fail("你正在发动自动连招！\n"); 
	if ( me->query_temp("cooldown") )	//CD写法	2017.9.7添加
		return notify_fail("你处于技能冷却状态中，过会在使用吧。\n");
		
	message_vision(HBWHT "$N贯通星宿派武学，使出了星宿派的绝学之精髓！\n" NOR, me, target);
	ap = me->query("level") + me->query_skill("chousui-zhang", 1) + me->query_skill("tianshan-zhang", 1) + me->query_skill("strike") + me->query_skill("force");
	dp = target->query("level") + target->query_skill("dodge") + target->query_skill("parry");
	ap = ap*((int)me->query("breakup")+(int)me->query("breakup")*(int)me->query("breakup")+100)/100;
	dp = dp*((int)target->query("breakup")+(int)target->query("breakup")*(int)target->query("breakup")+100)/100;
	extra = me->query_skill("tianshan-zhang",1)/10+me->query_skill("huagong-dafa",1)/10;	
	msg = HIM "\n$N突然间手舞足蹈，口中念念有词，诵道：“星宿神功，威震寰宇，古今无比”，\n";
	msg += HIM "跟着将手中杖向空中连连抛送，毫无章法，好似跳大罗金仙舞，让人瞠目结舌。\n\n"NOR;
	message_vision(msg, me, target );
	me->set_temp("cooldown", 1);	//CD写法	2017.9.7添加
	call_out("del_cooldown", 3, me);	//CD写法1	

	msg = HIY "$N使出天山派绝技「天山奇峰」，身法陡然加快。万岳朝宗！" NOR;
	message_vision(msg, me, target );
	me->add_temp("apply/attack", extra);
	me->add_temp("apply/damage", extra);
	msg =  HIB  "        ^^玉进天池！^^       " NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  RED  "      ^^^^山风凛冽！^^^^  " NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIM  "    ^^^^^^开门见山！^^^^^ " NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIC  "^^^^^^^^^^^天山雪崩！^^^^^^^^^^^ " NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->add("neili", -500);	
	me->add("jingli", -500);	
	
if(me->query_skill("chousui-zhang",1)>500 && me->query_skill("tianshan-zhang",1)>500 )
{	
	damage = me->query_skill("chousui-zhang",1) + me->query_skill("huagong-dafa",1) + me->query_skill("tianshan-zhang",1)+me->query_skill("force",1);
	damage = damage/2 + random(damage/2);
	damage = damage*(100-target->query_meridian())/100;
	message_vision(HIY"$N的招式突变，手上冒出了绿光! $n被绿光扫中，全身不由一震!\n"NOR,me,target);
	extra = me->query_skill("chousui-zhang",1)/10+me->query_skill("huagong-dafa",1)/10;	
	me->add_temp("apply/attack", extra);
	me->add_temp("apply/damage", extra);	
	target->apply_condition("xx_poison",20);
	msg =  HIR  "「腐尸毒」" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	target->apply_condition("poison_sandu",20);
	msg =  HIR  "「毒砂掌」" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	target->apply_condition("sanpoison",20);
	msg =  HIR  "「无形毒」" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add("neili", -300);
	if (random(ap) >dp/3)
	{
		msg =  HIR  "「三笑逍遥散」" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		target->receive_damage("jing", damage,me);
		target->receive_wound("jing", damage/2,me);
		if (random(3)==1) target->apply_condition("sanxiao_poison",20);
		me->add("neili", -2000);
		me->add("jingli", -2000);	
		message_vision(HIR"$N突然怪异的一笑，$n尽然跟着笑了笑!\n"NOR,me,target, damage, HBWHT+HIM"精神伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人精神的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);		
	}
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);	
}

if(me->query_skill("chousui-zhang",1)>1000 && me->query_skill("tianshan-zhang",1)>1000 )
{
	if (me->query("jm/xingxiu")) damage = me->query_skill("chousui-zhang",1)*me->query("con",1)*3/20 + me->query_skill("huagong-dafa",1)*me->query("con",1)*3/20 + me->query_skill("tianshan-zhang",1)*me->query("con",1)*3/20+me->query_skill("force",1)+me->query_skill("unarmed",1);
	else damage = me->query_skill("chousui-zhang",1)*me->query("con",1)/10 + me->query_skill("huagong-dafa",1)*me->query("con",1)/10 + me->query_skill("tianshan-zhang",1)*me->query("con",1)/10+me->query_skill("force",1)+me->query_skill("unarmed",1);
	damage = damage/3 + random(damage/3) + me->query("jing")*1/100;
	damage = damage*(100-target->query_meridian())/100;
	message_vision(RED "\n$N用全身的内力注入地上！对着地上一指..地上出现了团"HIR"火焰\n" NOR, me,target);
	message_vision(BLU"\n$N神色惨淡，伸手打开发髻，长发下垂，覆在脸上，跟着点燃红磷粉，咬破舌尖，一口"RED"鲜血"BLU"向火焰中喷去。"HIR"火焰忽地一暗，随即大为"RED"明亮"HIR"，耀得众人眼睛也不易睁开。\n\n"NOR,me,target);
	msg = HIB"\n$N猛地身子急旋，如陀螺般连转了十多个圈子，接着$P大袖拂动，"HIR"整个火焰堆陡地拨起，凌空燃烧，便如一座"RED"火墙"HIR"般，夹着排山倒海之势向$n压来！\n"NOR;
	message_vision(msg, me, target );
	if( random(ap) > dp/3  )
	{

		msg = HIY"\n$n只吓目瞪口呆，一怔之间，急忙跃起，但一朵"HIW"火花"HIY"已射到身前，嗤的一声响，火花已烧上肚腹。$n“啊”的一声大叫，落了下来。那团"HIR"大火墙"HIY"也即回入火焰堆中。\n" NOR;
		message_vision(msg, me, target);
		if (random(4)==1) 
		{
			target->map_skill("unarmed");	//下特殊拳脚
			message_vision(RED"$n手上粘上毒火，疼痛不已，没办法使用拳脚。\n"NOR,me, target);
		}
		target->receive_damage("jing", damage,me);
		target->receive_wound("jing", damage/2,me);
		target->add("neili",-damage);
		msg = HIG"\n结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n";
		msg +=  RED"\n $n真气损失过重，已经有如风中残烛，随时都可能断气。\n"NOR;
		message_vision(msg, me, target, damage, HBWHT+HIM"精神伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法		
//		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人精神的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
		me->add("neili", -3000);
		me->add("jingli", -3000);	
		target->apply_condition("fire_poison",10);
		target->apply_condition("qx_snake_poison",10);
		target->apply_condition("xhlq_poison",10);
		target->apply_condition("xys_poison",20);
	}
	else
	{
		msg = "$p急提内力奋力一震，将$N打出的大火墙卸在了身旁!\n" NOR;
		message_vision(msg, me, target);
		me->add("neili", -1000);
		me->add("jingli", -1000);	
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