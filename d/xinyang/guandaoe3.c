// Room: /wudang/guandao1.c
// llin 11.25.1997 

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long",
"一条行人走马的大道，路上不时有些赶路的旅人，还有一队\n"
"镖车，几个镖头押着车，不紧不慢的走着。这里是官家管着的地\n"
"方，不会有强人出没。东南面不远处就是扬州了，西面通往信阳\n"
"城。\n"

	);
        set("outdoors", "xiangyangnan");

	set("exits", ([
		"west" : __DIR__"guandaoe2",
        "southeast" : "/d/city/ximen",
		
	]));

	setup();
}

