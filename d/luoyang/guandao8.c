//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "大官道");
        set("long", @LONG
这是一条宽阔笔直，尘土飞扬的大官道，足可容得下十马并驰。南边
不远是东都洛阳古城的北门，往北直上可以到达洛水。
LONG
        );

        set("exits", ([
               "south" : __DIR__"guandao7",  
               "north" : __DIR__"luoshui",         
        ]));
        set("objects", ([
              __DIR__"npc/randomnpc" : 1,
        ]));

        set("outdoors", "luoyang");
        setup();
        replace_program(ROOM);
}

