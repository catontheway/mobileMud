#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

#define KONG "「" HIG "「空」字诀" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	int ap, dp,skill,i,max;

	if( !target ) target = offensive_target(me);
	if( !target||!target->is_character()||!me->is_fighting(target) )
		return notify_fail(KONG "只能对战斗中的对手使用。\n");
	if( objectp(me->query_temp("weapon")) )
		return notify_fail(KONG "只能空手施展。\n");
	if (me->is_busy()) 
		return notify_fail("你现在正忙着呢！\n");
	if ((int)me->query_skill("kongming-quan", 1) < 200)
		return notify_fail("你的空明拳不够娴熟，难以施展" KONG "。\n");
	
//	if (me->query_skill_mapped("unarmed") != "kongming-quan") 
//		return ("你没有激发空明拳，难以施展" KONG "。\n");
	if (me->query_skill("force",1) < 200)
		return notify_fail("你的内功修为不够，难以施展" KONG "。\n");
	if ((int)me->query("neili") < me->query_skill("kongming-quan",1)*4)
		return notify_fail("你现在的真气不够，难以施展" KONG "。\n");
	if( (int)me->query("max_neili") < 1000 )
		return notify_fail("你的内力修为还不够高。\n");
	if( (int)me->query("max_jingli") < 1000 )
		return notify_fail("你的精力修为还不够高。\n");
	if( (int)me->query("jingli") < me->query_skill("kongming-quan",1)*4 )
		return notify_fail("你的精力不够了，难以施展" KONG "。\n");	
	if (target && !living(target))
		return notify_fail("对方都已经这样了，用不着这么费力吧？\n");
	if (me->query_temp("autolian"))
		return notify_fail("你正在发动自动连招！\n"); 	
	if ( me->query_temp("cooldown") )	//CD写法	2017.9.7添加
		return notify_fail("你处于技能冷却状态中，过会在使用吧。\n");

	skill = me->query_skill("kongming-quan",1)/12;
	if ( me->query_skill_mapped("force")!="xiantian-gong") skill -= me->query_skill("kongming-quan", 1)/15;	//2018.9.5阿飞改，不使用本门特内则减益	
//	if ((string)weapon->query("id") == "kong ming") skill += (int)me->query_skill("kongming-quan", 1)/12;	 //2018.3.25阿飞改，拿特殊武器有加成	
	max = me->query_skill("kongming-quan",1)/600;
		
	msg = HIC "\n$N" HIC "双掌陡然连续反转，一招「" HIG "「空」字诀"
              HIC "」，双掌带风，已将$n" HIC "笼罩在掌风之中。" NOR;
	message_vision(msg, me, target);
	me->set_temp("cooldown", 1);	//CD写法	2017.9.7添加
	call_out("del_cooldown", 3, me);	//CD写法1		 
	ap = me->query("xyzx_sys/level") + me->query_skill("kongming-quan", 1) + me->query_skill("unarmed") + me->query_skill("force");
	dp = target->query("xyzx_sys/level") + target->query_skill("dodge") + target->query_skill("parry");
	ap = ap*((int)me->query("breakup")+(int)me->query("breakup")*(int)me->query("breakup")+100)/100;
	dp = dp*((int)target->query("breakup")+(int)target->query("breakup")*(int)target->query("breakup")+100)/100;
	if (max < 1) max = 1;
	if (me->query("jm/quanzhen")) 
	{
		if(max > 100+(int)me->query_temp("lianzhao_max_add")*4) max = 100+(int)me->query_temp("lianzhao_max_add")*4;
	} else 
	{
		if(max > 50+(int)me->query_temp("lianzhao_max_add")*2) max = 50+(int)me->query_temp("lianzhao_max_add")*2;
	}
	if (random(ap) > dp/4)
	{
		me->add_temp("apply/strength", skill);
        me->add_temp("apply/attack", skill);
		me->add_temp("apply/damage", skill);
		msg = HIR "\n结果$n" HIR "目不暇接，顿时被$N" HIR "掌风所困，顿时阵脚大乱。\n" NOR;
		message_vision(msg, me, target);
//		me->add_temp("lianzhao", max);	 //2016.6.1阿飞改，增加连招标记，用于削弱连招伤害
		for (i = 0; i < max; i++)
		{
			switch ( random(6) )
			{
				case 0: msg = RED"空屋住人！\n" NOR;
					break;
				case 1: msg = GRN"空碗盛饭！\n" NOR;
					break;
				case 2: msg = YEL"空钵装水！\n" NOR;
					break;
				case 3: msg = BLU"虚怀若谷！\n" NOR;
					break;
				case 4: msg = MAG"空山鸟语！\n" NOR;
					break;
				case 5: msg = CYN"我心空明！\n" NOR;
					break;				
			}
			message_vision(msg, me,target);
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		}
		me->add_temp("apply/strength", -skill);
        me->add_temp("apply/attack", -skill);
		me->add_temp("apply/damage", -skill);
		me->add("neili", -max * 100);
		me->add("jingli", -max * 100);
//		me->delete_temp("lianzhao");  //2016.6.1阿飞改，连招结束取消连招标记		
    } else
    {
        msg = HIY "\n$n" HIY "看清$N" HIY "这几招的来路，但"
                "内劲所至，掌风犀利，也只得小心抵挡。\n" NOR; 
		message_vision(msg, me, target);
		me->add("neili", -100);
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