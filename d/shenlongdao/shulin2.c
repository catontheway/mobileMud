// Room: /shenlongjiao/shulin1.c
// kiden 06/08/25

inherit ROOM;

void create()
{
        set("short", "树林");
        set("long", @LONG
到处开满了奇花异草，奇香扑鼻，但闻久了头有些晕。
走不得几步，忽听草中簌簌有声，跟着眼前黄影闪动，七八条中间黑的毒蛇窜了出来。
LONG
        );
        set("outdoors", "city");

        set("exits", ([
                "west" : __DIR__"shulin1",        
                "east" : __DIR__"shulin3",
                "south" : __DIR__"shulin1",
                "north" : __DIR__"shulin"+random(4),                
        ]));

   set("objects", ([
         __DIR__"npc/snake"+random(7):1,
//        __DIR__"npc/rascal":1,
       ]));
        setup();
        replace_program(ROOM);
}

