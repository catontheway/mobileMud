//Zine 25 Nov 2010

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "黄河渡口");
        set("long", @LONG
这里是黄河北岸一处免费的渡口，东北面不远是著名的丝绸之路，可以通向
西域。
LONG
        );
        set("exits", ([
             "southwest" : __DIR__"hhb20",
             "northeast" : __DIR__"hhb19",
             
        ]));
       

        set("free",1);//免费渡口
        

        
        set("no_clean_up", 0);
        set("outdoors", "huanghe");
//渡船属性
        set("boat","/d/huanghenorth/duchuan4f"); //船
        set("waittime",12); //等船时间
        set("arrivetime",12); //船行时间
        set("destination","/d/huanghe/dkn4f"); //目的地
		set("npc_forbidden_dirs",({}));
        setup();
}

#include "hh-pass.h"






