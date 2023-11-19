// shenliwan.c 福缘丹

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIG "大仙豆" NOR, ({ "xian dou", "dou"}) );
        set_weight(200);
         set("jhxk", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一颗仙界的仙豆，据说吃了可以增长光阴。\n");
                set("value", 10000);
                set("unit", "颗");
                	set("only_do_effect", 1);
        }
}



int do_effect(string arg)
{
        object me;

   //     if (! id(arg))
     //           return notify_fail("你要吃什么？\n");

        me = this_player();
        if(me->query("gift/200705011") > 100)
        {
                message_vision("$N一仰脖，吞下了一颗$n。\n", me, this_object());
                tell_object(me, HIG "不过你没什么感觉，大概吃的太多了。\n" NOR);
        }
        else
        {
                message_vision("$N一仰脖，吞下了一颗$n。\n", me, this_object());
                tell_object(me, HIG "你感到自己长大了一岁！\n" NOR);
                me->add("mud_age", 86400);
                me->add("gift/200705011", 1);
        }
        if(me->query("mud_age") < 0)
                me->set("mud_age", 0);
        destruct(this_object());
        return 1;
}
