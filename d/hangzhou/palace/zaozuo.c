// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
#include <ansi.h>
#include "/d/song/xunshi.h"
void create()
{
	set("short", YEL"造作所"NOR);
	set("long", @LONG
这里是大内的造作所。
LONG
	);
        //set("outdoors", "hangzhou");

	set("exits", ([
		//"east" : __DIR__"walla",
		"northeast" : __DIR__"yudao1",
		//"west" : __DIR__"wall1",
		//"north" : __DIR__"funing",
		//"enter" : __DIR__"kunning2",
	]));
	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		//"/d/hangzhou/npc/huangmen_g" : 1,
		"/d/song/npc/zaozuo" : 1,
		//"/d/hangzhou/npc/songbing_z" : 2,
        ])); 
	setup();
}