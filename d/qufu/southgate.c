// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>
string look_gaoshi();
void create()
{
        set("short", "南城门");
        set("long", "这里是曲阜的南门。城墙上贴着告示(gaoshi)。\n");
        set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
        set("exits", ([
               //"north" : "/d/changjiang/cjn20",
               "north" : __DIR__"southstreet1",
               "south" : __DIR__"guandaos1",
               
                
        ]));
        set("objects", ([
		"/d/city/npc/wujiang1"+random(2) : 1,
        "/d/city/npc/bing" : 2,
        ]));
        set("outdoors", "qufu");
        setup();
   
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n曲阜知县谕\n";
}

