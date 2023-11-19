// 谷底
// edit: by zine Oct 19 2010

inherit __DIR__"xxconfig";
#include <ansi.h>
#include "/d/xingxiu/climb_fall.h"

void create()
{
	set("short", HIW"瀑布"NOR);
	set("long", @LONG
这里是一条大瀑布，水流日夜不停的向下冲去。
LONG
	);
    set("climb_bonus",12);
    set("exits", ([
             "down" : __DIR__"fall2",
             "up": __DIR__"fall_top",
        ]));
    set("outdoors", "xingxiuhai");
        	set("item_desc", ([
"瀑布" : "这里是一条大瀑布，水流日夜不停的向下冲去。\n"
		 ZJOBACTS2+ZJMENUF(2,2,12,40)+"爬:climb up\n",
    ]));
    setup();
	::create();
}


void init()
{
    add_action("do_climb","climb");
    add_action("do_none", "");
}

int valid_leave(object me,string dir)
{
    if (dir=="up")
    {
        return notify_fail("快到瀑布顶端了，水流更加湍急，非人力可上。\n");
    }
    if (dir=="down")
    {
        return notify_fail("别做梦了，这样的大瀑布你想直接走上去？老老实实"+ZJURL("cmds:climb down")+"爬(climb)吧。\n");
    }
    return ::valid_leave(me,dir);
}

int do_climb(string arg)
{
    object ob,rm,me=this_player();
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (me->query_skill("dodge",1)<300||((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance())>30)
    {
        tell_object(me,"你爬了一半，脚下一滑，重重的摔了下去。\n");
        me->unconcious();
        return 1;
    }
    if (arg=="up")
    {
        rm=load_object(__DIR__"fall_top");
        if (!present("fei zhua",me))
        {
            tell_object(me,"没有任何助力或工具，你恐怕是爬不上去的。\n");
            return 1;
        }
        ob=present("fei zhua",me);
        if (!ob->query("is_feizhua_xx"))
        {
            tell_object(me,"没有任何助力或工具，你恐怕是爬不上去的。\n");
            return 1;
        }
        me->add_busy(2+random(3));
        climb_up(me);
        tell_room(rm,me->name()+"十分艰难地爬了过来。\n");
        me->move(rm);
        return 1;
    }
    else if (arg=="down")
    {
        rm=load_object(__DIR__"fall2");
        message_vision(HIW"$N手脚并用，抓着瀑布下的突起，向下爬去。\n"NOR,me);
        me->add_busy(2+random(3));
        climb_down(me);
        tell_room(rm,me->name()+"十分艰难地爬了过来。\n");
        me->move(rm);
        return 1;
    }
    else
    {
        tell_object(me,"你要往哪个方向爬？\n");
        return 1;
    }
}

