// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";

void create()
{
	set("short", "东南宫墙");
	set("long", @LONG
这里是皇城大内宫墙，西面是大内的城门。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		"west" : __DIR__"lizhengmen",
		//"south" : __DIR__"heningmen",
		//"west" : __DIR__"wall1",
		"north" : __DIR__"walla",
	]));

	setup();
}