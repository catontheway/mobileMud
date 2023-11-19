// Room: /city/datiepu.c
// YZC 1995/12/04
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "打铁铺内室");
	set("long", @LONG
这里是打铁铺的内室，专门出售一些价钱不菲的兵器。如果你要订一件属于
自己的兵器，当然还得去找老板。
LONG);
	set("exits", ([
		"north" : __DIR__"datiepu",
	]));
	set("objects", ([
	//	"/adm/npc/wang":1,
		"/d/city/npc/huoji1":1,

		"/p/newweapon/npc/moye":1,
		"/p/newweapon/npc/ganjiang":1,
		
	]));
		/*	set("action_list", ([
		HIC"武器命名"NOR:"name",
		HIG"设定描述"NOR:"desc",
		HIY"装上描述"NOR:"wieldmsg",
		HIY"放下描述"NOR:"removemsg",
		HIM"结束设定"NOR:"finish",
	]));*/
	setup();
	replace_program(ROOM);
}
