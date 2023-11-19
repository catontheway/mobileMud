//yboat.c
//by hehe
//2003.3.13

#include <ansi.h>
inherit ROOM;

void init();
int do_row(string);

void create()
{
	set("short", "小船");
	set("long", @LONG
这艘小船是庄内的交通工具。因为船小，仅能容纳二三人。
船仺内放着一把浆(jiang)，
LONG
 );

	set("cost", 1);
	set("outdoors", "murong");

         set("item_desc", ([
              "jiang" :
"一把小桨，是划船用的(row)。你可以去划船去以下地方：\n
	听香水榭(tingxiang)，琴韵小筑(qinyun)\n"
	ZJOBACTS2+ZJMENUF(2,2,12,40)+"听香水榭:row tingxiang"+ZJSEP+"琴韵小筑:row qinyun\n",
                           ]));
    set("no_dbr_stage",1);
	setup();
}

void init()
{
	add_action("do_row", "row");
}

int do_row(string arg)
{
	object me;
    me = this_player() ;

     if (!arg )
	{
		return notify_fail("你用力划了几下，小船团团打转，看来你要先要找准一个方向。\n");
	}

    if (arg == "tingxiang")
	{
        message_vision("$N拿起船桨用力划了起来。\n",me);
		me->move("/d/murong/dahu");
		call_out("waittx", 10, me);
		return 1;
	}
	else if (arg == "qinyun")
	{
        message_vision("$N拿起船桨用力划了起来。\n",me);
		me->move("/d/murong/dahu");
		call_out("waitqy", 10, me);
		return 1;
	}
	else if (arg == "mantuo")
	{
        message_vision("$N想从这里去曼陀山庄，不可能！\n",me);
		return 1;
	}
	else
	{
        message_vision("没有这个方向，$N想好了去哪里。\n",me);
		return 1;
	}
}
void waittx(object me)
{
	tell_object(me, "\n............................\n" ) ;
	tell_object(me, "\n.......................\n" ) ;
	tell_object(me, "\n...................\n" ) ;
	tell_object(me, "\n..............\n" ) ;
	tell_object(me, "\n.....\n" ) ;
    message_vision("不知过了多久，船终于靠岸了，$N累得满头大汗。\n",me);
	me->move ("/d/murong/tbank") ;
}
void waitqy(object me)
{
	tell_object(me, "\n............................\n" ) ;
	tell_object(me, "\n.......................\n" ) ;
	tell_object(me, "\n...................\n" ) ;
	tell_object(me, "\n..............\n" ) ;
	tell_object(me, "\n.....\n" ) ;
    message_vision("不知过了多久，船终于靠岸了，$N累得满头大汗。\n",me);
	me->move ("/d/murong/hubian2") ;
}