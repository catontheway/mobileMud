// 马车店 Zine 2012.8.1
inherit WAGON_SHOP;
#include "/d/song/etc/special_wagon.h"
void create()
{
        set("short", "中原马车行");
		set("exits", ([
		
		"east" : __DIR__"chaguan",
		]));
		set("price",100);//雇车价格
        ::create();
}

