// Room: /hangzhou/beidajie1.c
// hubo 2008/4/19
// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
void create()
{
	set("short", "下瓦子");
	set("long", @LONG
下瓦子是临安城最热闹的所在，有集市，商铺，茶馆和红楼。
LONG);
        set("outdoors", "hangzhou");
        set("exits", ([
                "west" : __DIR__"jiyuan",
				"east" : __DIR__"dianxinpu",
                "out" : __DIR__"xiawa",
                "south" : __DIR__"qianzhuang",
                "southeast" : __DIR__"zahuopu",
			    "southwest" : __DIR__"jiulou",
]));
          
   setup();
}