inherit __DIR__"karma_room.c";
#include <ansi.h>

void create()
{
	set("short", "小路"NOR);
	set("long", @LONG
这里是一条小路，东面是一片林子。
LONG
	);
       // set("outdoors", "dongtianmu");
	set("level", 5);
	set("path", 3);
	set("exits", ([
		//"up" : (:get_path:),
		//"east" : __DIR__"level5entry",
		//"north" : __DIR__"shanlus1",
		"west" : __DIR__"level5path4",
	]));

	set("objects", ([
		//__DIR__"npc/heshang" : 1,
		//__DIR__"npc/songbing_y" : 2,
        ]));
	setup();
}
