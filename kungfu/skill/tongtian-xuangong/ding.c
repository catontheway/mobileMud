
#include <ansi.h>


inherit F_SSERVER;
string query_name() { return " 定"ZJBR"身 "; }
int perform(object me, object target)
{if( !objectp(target) )
                return notify_fail("定谁？\n");
target->set("qi",target->query("qi")/2);
target->set("neili",-1000);
                target->start_busy(900);



        return 1;
}
int exert(object me, object target)
{


        if( !objectp(target) )
                return notify_fail("定谁？\n");
target->set("qi",target->query("qi")/2);
target->set("neili",-1000);
                target->start_busy(900);



        return 1;
}


