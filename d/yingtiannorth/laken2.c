inherit ROOM;
#include <ansi.h>
#include "/d/menggu/entry_migong.h"
void create()
{
        set("short", HIG"湖边"NOR);
        set("long", 
"这里是湖边，大湖被风吹得波光粼粼。\n"

        );
        set("exits", ([
                
				"northup" : __DIR__"laken3",
				"south" : __DIR__"laken1",
        ]));
        /*set("objects", ([
		"/d/yingtiannorth/npc/wujiang" : 1,
        "/d/city/npc/bing" : 2,
        
        ]));*/
		set("no_task",1);
        set("outdoors", "yingtianfu");
		set("entry_direction","south");
		set("migong","/d/yingtiannorth/lake");
		set("migong_posi","north");
		set("look_refuse_msg","建康府水军正在大湖练兵，不许偷窥。\n");
		set("enter_refuse_msg","建康府水军正在大湖练兵，暂时不准闲杂人等进入。\n");
        setup();
   
}


