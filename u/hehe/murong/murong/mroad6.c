//mroad6.c
//by hehe
//2003.3.5

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "小路");
    set("long", @LONG
这是一条小路，两边都种满了茶花。
LONG
    );

    set("exits", ([
		"east" : __DIR__"mroad5",
		"west" : __DIR__"mroad7",
    ]));
    
    set("outdoors", "murong");
    setup();

}
