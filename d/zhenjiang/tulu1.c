// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "土路");
        set("long", @LONG
这里是镇江府城廓边的一段土路。
LONG);
        set("outdoors", "zhenjiang");
        set("exits", ([     
                "east" : __DIR__"tulu2",   
                "west" : __DIR__"northgate",
]));
     
        
   setup();
}

