inherit __DIR__"karma_room.c";
#include <ansi.h>
void create()
{
	set("short", HIW+"地宫甬道"+NOR);
	set("long", @LONG
这里是一条长长的甬道，不知通向何方。
LONG
	);
       // set("outdoors", "dongtianmu");
	set("level", 1);
	set("maze", 7);
	setup();
	init_maze(1);
}
