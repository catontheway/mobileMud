// exercise.c
// Modified by iszt@pkuxkx, 2007-04-18, use msg defined in force skill

#include <skill.h>
#include <ansi.h>

int exercising(object me);
int halt_exercise(object me, object who, string how);
void auto_dazuo(object me, int exercise_cost)
{
	if(!me||!me->query_temp("pending/auto_dazuo"))
		return;
	if(me->is_busy())
		call_out("auto_dazuo",1,me,exercise_cost);

	else if( (int)me->query("qi") < exercise_cost )
	{
		if (SKILL_D("force/recover")->exert(me, me)&&me->query_skill("force")>45)
		{
			if( (int)me->query("qi") < exercise_cost)
			{
				tell_object(me,"体力不足，休息中。。。\n");
				tell_object(me,ZJFORCECMD("exert recover"));
				call_out("auto_dazuo",10,me,exercise_cost);
			}
			else
			{
				call_out("auto_dazuo",1,me,exercise_cost);
			}
		}
		else
		{
			tell_object(me,"体力不足，休息中。。。\n");
			tell_object(me,ZJFORCECMD("exert recover"));
			call_out("auto_dazuo",10,me,exercise_cost);
		}
	}
	else
	{
		tell_object(me,"托管中，继续打坐。。。。。。\n");
		tell_object(me,ZJFORCECMD("exercise "+exercise_cost));
	}
}
int main(object me, string arg)
{
	int exercise_cost;
	object where;
	string force;
	mapping msg;

	seteuid(getuid());
	where = environment(me);
	
	if (where->query("pigging"))
		return notify_fail("你还是专心拱猪吧！\n");

	if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("你现在正忙着呢。\n");

	if( me->is_fighting() )
		return notify_fail("战斗中不能练内功，会走火入魔。\n");

	if( !stringp(force = me->query_skill_mapped("force")) )
		return notify_fail("你必须先用 enable 选择你要用的内功心法。\n");

	if( !arg || !sscanf(arg, "%d", exercise_cost))
	{
		exercise_cost = me->query("max_qi") *2/5;
			if (exercise_cost < 10 ) exercise_cost = 10;
			me->set_temp("pending/auto_dazuo",exercise_cost);
	}
	//	return notify_fail("你要花多少气练功？\n");

	if (exercise_cost < 10)
		return notify_fail("你的内功还没有达到那个境界！你至少需要十点的气来打坐！\n");

	if (exercise_cost > 100000 )
		return notify_fail("你的内功还没有达到那个境界！你最多打坐十万的气！\n");

	if( me->query("qi") < exercise_cost+10  ||  
	    me->query("qi") < exercise_cost*11/10 )
		{
			tell_object(me,ZJFORCECMD("exert recover"));
			tell_object(me,ZJFORCECMD("exercise"));
		return notify_fail("你现在的气太少了，无法产生内息运行全身经脉。\n");
		
		}

	if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
		return notify_fail("你现在精不够，无法控制内息的流动！\n");
	
  if (me->query_temp("neili_speedup") )
  	return notify_fail("你正在运行内功加速全身气血恢复，无法静下心来搬运真气。\n");
  	
  if ( time()-me->query("wrong_status")<0 )
    return notify_fail("你体力真气混乱，短时间内无法静下心来搬运真气。\n");

	msg = SKILL_D(force)->exercise_msg(me);
	if (!msg || undefinedp(msg["start_my_msg"]))
		write("你坐下来运气用功，一股内息开始在体内流动。\n");
	else
		write(msg["start_my_msg"]);

	me->set_temp("pending/exercise", 1);
	me->set_temp("exercise_cost", exercise_cost);

	if (!environment(me)->query("least_msg"))
	if (!msg || undefinedp(msg["start_other_msg"]))
		tell_room(environment(me),
			me->name() + "盘膝坐下，开始修炼内力。\n", ({ me }));
	else
		tell_room(environment(me),
			msg["start_other_msg"], ({ me }));

	me->start_busy( "exercising", "halt_exercise" );

	return 1;
}

int exercising(object me)
{
	int exercise_cost;
	int neili_gain;
	mapping msg;
	string force;
  int wrpct;

	if(!me)
		return 0;
	if(!living(me))
	{
		halt_exercise(me, me, "halt");
		return 0; // Added by iszt@pkuxkx, 2007-04-18, 防止晕了继续打坐死亡
	}
	exercise_cost = (int)me->query_temp("exercise_cost");
	neili_gain = 1 + (int)me->query_skill("force") / 10;
	neili_gain=to_int(to_float(neili_gain)*("feature/vein/BasicVein/shoutaiyin.c"->benefit_times(me)));
	if (exercise_cost < 1)
		return 0;
//      me->add("neili", neili_gain);
//      me->set_temp("exercise_cost", exercise_cost -= neili_gain);
//      me->add("qi", -neili_gain);
//      防止打坐假死bug iszt@pkuxkx, 2007-03-11
	exercise_cost -= neili_gain;
	if(exercise_cost < 0)
		neili_gain = neili_gain + exercise_cost; //e_c小于0时置为原来的值
        me->add("qi", -neili_gain);
        if(me->query("special_skill/constitution") && me->query("age")>=18)
        neili_gain += neili_gain / 2; //constitution特技能让打坐效率增加50%
		neili_gain=to_int(to_float(neili_gain)*("feature/vein/BasicVein/shoutaiyin.c"->benefit_effect(me)+1.0));
    neili_gain = neili_gain * SPEWEEK_D->query_dz_bonus()/100;
	
    if(me->query("max_neili") <1000)
	{
        neili_gain += neili_gain ; //最大内力1000以下时打坐效率增加一倍
	}	
    neili_gain =  to_int(neili_gain * REWARD_D->get_global_factor("dazuo"));
	neili_gain = to_int(neili_gain * REWARD_D->get_special_user_factor(me));
	me->set_temp("exercise_cost", exercise_cost);
	me->add("neili", 5+neili_gain);

	if (exercise_cost > 0)
		return 1;

	me->set_temp("pending/exercise", 0);

	force = me->query_skill_mapped("force");
	if (force) msg = SKILL_D(force)->exercise_msg(me);

	if (!msg || undefinedp(msg["end_my_msg"]))
	{
		tell_object(me, "你运功完毕，深深吸了口气，站了起来。\n");
		if(me->query_temp("pending/auto_dazuo"))
		call_out("auto_dazuo",1,me,me->query_temp("pending/auto_dazuo"));
	}
	else
		tell_object(me, msg["end_my_msg"]);
	if (!environment(me)->query("least_msg"))
	if (!msg || undefinedp(msg["end_other_msg"]))
	{
		tell_room(environment(me),
			me->name()+"运功完毕，深深吸了口气，站了起来。\n", ({me}));
			if(me->query_temp("pending/auto_dazuo"))
		call_out("auto_dazuo",1,me,me->query_temp("pending/auto_dazuo"));
			}
	else
		tell_room(environment(me),
			msg["end_other_msg"], ({me}));

  wrpct=to_int(ceil(F_KUNGFU->kungfu_wrongpct(me)*10000));
  if ( wrpct>0 && random(10000)<wrpct ) 
  {
    me->set("neili", 0 );
    me->set("wrong_status",time()+60);
    message_vision( HIG"突然之间$N失去了对真气的控制，看来短时间内再也无法运转真气了。\n"NOR, me );
    return 0;
  }
      
	if ((int)me->query("neili") < (int)me->query("max_neili") * 2)
		return 0;
	else {
		if ((int)me->query("max_neili") > (int)me->query_max_neili() ) {
			write("你的内力修为似乎已经达到了瓶颈。\n");
			me->set("neili", (int)me->query("max_neili"));
			return 0;
		}
		else {
			me->add("max_neili", 5);
			me->set("neili", (int)me->query("max_neili"));
			me->add("exercised_neili",5);
			write("你的内力增加了！！\n");
			if(me->query_temp("pending/auto_dazuo"))
		call_out("auto_dazuo",1,me,me->query_temp("pending/auto_dazuo"));
			return 0;
		}
	}
}

int halt_exercise(object me, object who, string how)
{
	if (!me) return 1;
	if ((int)me->query("neili") > (int)me->query("max_neili") * 2)
		me->set("neili", (int)me->query("max_neili") * 2);
	me->set_temp("pending/exercise", 0);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : exercise|dazuo [<耗费「气」的量> 必须多于 10]

运气练功，控制体内的气在各经脉间流动，藉以训练人体肌肉骨骼的耐
力、爆发力，并且用内力的形式将能量储备下来。
dz与dazuo不同的地方在于：dz在涨内力的同时还会增加内功的修习程度，
而且长期dz有可能会打通任督二脉，从而所有先天属性会随机增加1－2点。但
dz也有危险，在dz时halt或者战斗等可能导致走火，最大内力会减少一部分。
所以最好在安全的地方dz以避免走火。而dazuo就没有这方面的顾虑。

HELP
	);
	return 1;
}
