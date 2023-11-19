
// Room: /d/beijing/west/shibanlu5.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"石板路"NOR);
	set("long",
HIC"这是一条青石板路，两边种了不少柏树，显得庄严肃穆。
往南走是南天门，北面是座圆台，一阵阵浓郁的花香扑鼻
而来。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"south" : __DIR__"nantianmen",
  	"northup" : __DIR__"huanqiu",
]));
        set("outdoors", "beijing");
	setup();

}
void init()
{
     object me = this_player();
     if(me->query_temp("chaoting/xuncheng"))
     {
       me->set_temp("xc/shibanlu5",1);
      }

}