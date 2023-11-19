
#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("[如影如幻]只能在战斗中使用。\n");

        if((int)me->query_skill("qingfu-shenfa",1) < 50)
                return notify_fail("你的青蝠身法不够熟练。\n" NOR);

        if((int)me->query("neili") < 400)
                return notify_fail(HIY "你现在真气不足。\n" HIY);

        if( target->is_busy() )
                return notify_fail(target->name() + "已经很忙了！\n");

	msg = YEL"$N长空而起，化作一只青蝠，施展诡异的身法朝$n飞去！\n" NOR;
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
                msg += NOR "结果$p被$P绕得不知所措！\n" NOR;
                target->start_busy(5);
                me->add("neili", -100);
                       } else {
                msg +=  "结果$P自己绕了个头晕眼花。\n";
                me->add("neili", -100);
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}
