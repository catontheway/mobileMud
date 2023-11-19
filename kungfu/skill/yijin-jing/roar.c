// roar.c 佛门狮子吼
// Modified by Venus Oct.1997

#include <ansi.h>

inherit F_CLEAN_UP;
string query_name() { return "佛门狮子吼"; }
int exert(object me, object target)
{
    object *ob;
    int i, skill, damage;
      if( (int)me->query_skill("buddhism", 1) < 100 )
       return notify_fail("你的禅宗心法不够，无法使用佛门狮子吼。\n");

    if( (int)me->query("neili") < 600 )
       return notify_fail("你的内力不够。\n");

    if( environment(me)->query("no_fight") )
       return notify_fail("在这里不能攻击他人。\n");

//    skill = me->query_skill("force");
    skill = me->query_skill("force")*3/4;
    skill += me->query_skill("buddhism")/2;

    me->add("neili", -200);
    me->receive_damage("qi", 10);

    me->start_busy(5);
    message_combatd(
        HIY "$N深深地吸一囗气，真力迸发，运起佛门狮子吼，发出一声惊天动地的长啸。\n" NOR, me);

    ob = all_inventory(environment(me));
    for(i=0; i<sizeof(ob); i++)
    {
       if( !living(ob[i]) || ob[i]==me ) continue;
       if(!me->visible(ob[i])) continue;
       if( skill/2 + random(skill/2) < (int)ob[i]->query("con") * 2 ) continue;

       damage = skill - ((int)ob[i]->query("max_neili") / 10);
       if( damage > 0 )
       {
          ob[i]->receive_damage("jing", damage * 2, me );
          if( (int)ob[i]->query("neili") < skill * 2 ) ob[i]->receive_wound("jing", damage, me);
          tell_object(ob[i], "你觉得眼前一阵金星乱冒，耳朵痛得像是要裂开一样！\n");
          COMBAT_D->report_status(ob[i]); 
       }
	if (userp(me) && userp(ob[i]))
	{
//先出手的做个标记，被杀的话行凶者不增加杀气，by all@2015/1/21
		if ( !environment(ob[i])->query("no_die") && !(ob[i]->query("attack_player/id")==me->query("id") && time()-ob[i]->query("attack_player/time")<300)
		&& !(me->query("attack_by_player/id")==ob[i]->query("id") && time()-me->query("attack_by_player/time")<300))
		{
//		me->set("attack_player/id",ob[i]->query("id"));
//		me->set("attack_player/time",time());
		ob[i]->set("attack_by_player/id",me->query("id"));
		ob[i]->set("attack_by_player/time",time());		
		}			
	}			
       if( userp(ob[i]) ) ob[i]->fight_ob(me);
       else if( !ob[i]->is_killing(me->query("id")) ) ob[i]->kill_ob(me);
    }
    return 1;
}

