// /d/quanzhou/dahai_2.c
// Jay 3/17/96
#include <room.h>

inherit ROOM;

void create()
{ 
       set("short","大海");
       set("long", @LONG
这是一片茫茫的大海，你的船一驶进来就迷失了方向，不知道现在
自己身在何处，看来要去到目的地要费一番气力。
LONG
     );

    
        set("exits", ([
                 "east" : __DIR__"dahai_"+(random(10)+2),
                "south" : __DIR__"dahai_3",
                "west" : __DIR__"dahai_1",
                "north" : __DIR__"dahai_"+(random(10)+2),        ]));             
        setup();
        set("outdoors", "quanzhou");
        replace_program(ROOM);
}



       
