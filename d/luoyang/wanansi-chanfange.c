//万安寺 
//by picewolf
//2009-5-7

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"禅房"NOR);
        set("long", @LONG
这里原先是寺内僧人的禅房，现在被番僧霸占了。
LONG
			);

        set("exits", ([     
			"west" : __DIR__"wanansi-wofodian", 
			"east" : __DIR__"wanansi-kefange", 
        ]));

		set("outdoors", "luoyang");
		setup();
		replace_program(ROOM);
}