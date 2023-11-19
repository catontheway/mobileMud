// File		: xuepo2.c
// Created By	: iszt@pkuxkx, 2006-08-15

#include <ansi.h>
#include "snow.h"

inherit ROOM;

void create()
{
        set("short", HIW"雪坡"NOR);
	set("long", @LONG
陡峭的山坡之上，竟也被雪覆盖，行到此处，如果不是身具武功，几乎要手
脚并用了。真不敢想当初凌霄城的先辈们是如何建设起偌大的一座城的。远处山
上就是凌霄城了。
LONG);

	set("outdoors", "凌霄城");

	set("item_desc", ([
		"snow": (: snow :),
	]));

	set("objects", ([
	]));

	set("exits", ([
                "south" : "/d/dalunsi/jushuimen.c",
                "northup" : __DIR__"xuepo1",
		"eastup" : __DIR__"xuedi2.c",
	]));

	setup();
}