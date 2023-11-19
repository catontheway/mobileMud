// halt.c
// By Xiang@XKX (12/17/95)
#define SCHEME_CMD      "/cmds/usr/jihua"
#define TRIGGER_CMD     "/cmds/usr/trigger"
int main(object me, string arg)
{
	
	if (me->query("doing") == "scheme")
	{
		// 执行计划中，终止
		write("你决定中止计划。\n");
		SCHEME_CMD->cancel_schedule(me);
		if (! me->is_busy())
			return 1;
	}

	if( me->query("doing") == "trigger" )
	{
		write("你决定中止触发练功。\n");
		TRIGGER_CMD->cancel_trigger(me);
		if (! me->is_busy())
			return 1;
	}
        if (me->is_fighting()) {
                if( wizardp(me) )
                {
                        me->remove_all_killer();
                        message_vision("$N使用巫师神力停止了这场战斗。\n",me);
                }
                else
                {
                        me->remove_all_enemy();
                        message_vision("$N身行向后一跃，跳出战圈不打了。\n", me);                        
                }
        }
        else if (!me->is_busy()) 
                return notify_fail("你现在不忙。\n");
        else if ((int)me->query_temp("pending/exercise") != 0) {
                message_vision("$N把正在运行的真气强行压回丹田，站了起来。\n", me);
                me->interrupt_me();
        }
        else if ((int)me->query_temp("pending/respirate") != 0) {
                message_vision("$N强行收回精气，站了起来。\n", me);
                me->interrupt_me();
        }
        else if ((int)me->query_temp("pending/cooking") != 0) {
                message_vision("$N停止了做菜。\n", me);
                me->interrupt_me();
        }
        else if ((int)me->delete_temp("pending/practice") != 0) {
                message_vision("$N强行收回内力，停了下来。\n", me);
                me->interrupt_me();
        }
        else if ( me->query_temp("play_music/status") &&
                  me->query_temp("weapon") )
                me->query_temp("weapon")->unequip();

//      else if ((int)me->query_temp("pending/respirate") != 0)
//      me->interrupt_me();
//      me->interrupt_me();

        return 1;
}
 
int help(object me)
{
        write(@HELP
指令格式: halt
 
这个指令可以让从当前的busy状态中解脱出来。
 
包括正在战斗，打坐，吐纳，烹饪等状态。
 
HELP
        );
        return 1;
}
