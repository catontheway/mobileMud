// File		: stonee1.c
// Created By	: iszt@pkuxkx, 2006-08-16

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
一条平整宽阔的石板路，路边就是积雪，稀稀疏疏的长着几根草茎。东南方
向是内城的角门，几个腰间悬剑的人匆匆向北走去。
LONG);
	
	set("outdoors", "凌霄城");
	set("exits", ([
		"west" : __DIR__"datinge",
		"southwest" : __DIR__"bingeast5",
		"southeast" : __DIR__"jiaomene",
		"north" : __DIR__"stonee2",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 1,
	]));

	setup();
	replace_program(ROOM);
}