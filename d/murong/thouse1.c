//thouse1.c
//by hehe
//2003.3.5

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "农舍");
    set("long", @LONG
这是一间典型江南水乡风格的农舍，屋里放满了渔具。
LONG
    );

    set("exits", ([
		"east" : __DIR__"troad4",
    ]));
    
    set("outdoors", "murong");
    setup();

}
