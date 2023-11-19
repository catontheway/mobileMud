// Room: /d/suzhou/road1.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "青石官道");
	set("long", @LONG
你走在一条青石大道上，人来人往非常繁忙，不时地有人
骑着马匆匆而过。大道两旁有一些小货摊，似乎是一处集市。
西面就是江州城了。
LONG );
	set("outdoors", "jiangzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"northeast"     : __DIR__"guandaoe3",
		"west" : __DIR__"guandaoe1",
	]));
	setup();
	
}
