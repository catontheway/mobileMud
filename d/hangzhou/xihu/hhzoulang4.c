// Room: /hangzhou/hhzoulang4.c
// hubo 2008/4/19

// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
void create()
{
        set("short", "走廊");
        set("long", @LONG
红花会杭州分舵的走廊，后面是花园。
LONG);
       
        set("exits", ([     
                "north" : __DIR__"hhhuayuan",
                "east" : __DIR__"hhzoulang2",
]));
      
   setup();
}

