// Room: /d/xingxiu/xxh5.c
// Jay 3/18/96

inherit ROOM;
#include "/d/xingxiu/flower.h"
void create()
{
        set("short", "星宿海");
        set("long", @LONG
这里是星宿海的尽头。因为附近有野羊出没，所以星宿派弟子常常在此烤羊肉串
吃。当打不到野羊时，他们就抢山下牧人的羊。
LONG
        );
        set("exits", ([
             "southeast" : __DIR__"xxh3",
             "southwest" : __DIR__"xxh4",
        ]));
        set("objects", ([
                __DIR__"npc/boshou"  : 1,
                __DIR__"npc/obj/yangrou.c" : 2,
                flower:random(2) ,]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        setup();
        replace_program(ROOM);

}

