// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "水部司衙门");
	set("long", @LONG
这里是水部司的衙门。
LONG
	);
    //set("outdoors", "hangzhou");
	set("yamen","gongbu");
	set("exits", ([
		"northwest" : __DIR__+query("yamen")+"court",
	
	]));
	setup();
}