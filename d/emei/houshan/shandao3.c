// Room: /u/cuer/emei/shandao3.c

inherit ROOM;

void create()
{
	set("short", "山道");
set("outdoors","emei");
	set("long", @LONG
这是一条山中小道，道上人迹罕至，小道在这里分
出三岔，往西南通向千佛庵后门，往东南通向药王洞，
往北就是静修庵了。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"shandao4",
  "north" : __DIR__"jxan",
  "southwest" : __DIR__"shandao1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
