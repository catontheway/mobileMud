// Room: /hangzhou/beidajie1.c
// hubo 2008/4/19
// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
void create()
{
	set("short", "后宅");
	set("long", @LONG
这里是韩王府的后宅，一些内眷住在这里。
LONG);
        //set("outdoors", "hangzhou");
        set("exits", ([
                //"north" : __DIR__"hw_houzhai",
                "south" : __DIR__"hw_dating",
                //"west" : __DIR__"hw_zuoxiang",
                //"east" : __DIR__"hw_youxiang",        
]));
          
		  set("hsz_no_task",1);
   setup();
}