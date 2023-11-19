// Room: /d/diaoyudao/shulin6.c 树林
// hongdou 98.09.20

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
这里有一大片临近海滩的树林，海风轻轻吹过，树梢萧萧作响，和着林
中鸟儿的鸣叫，一种说不出的幽静、和平的感觉，使你流连忘返。
LONG
	);

	set("exits", ([
                 "east" : __DIR__"shulinout",
		"south" : __DIR__"shulin7",
                 "west" : __DIR__"shulin4",
                "north" : __DIR__"shulin5",
	]));

	set("outdoors", "diaoyudao");
	setup();
	replace_program(ROOM);
}

