// Rewrote by iszt@pkuxkx, 2007-02-11
#include "dong.h"
inherit ROOM;

void create()
{
	setshort();
	setlong();
    set("no_task",1);
	set("exits", ([
		"south" : __DIR__"dong61",
		"north" : __DIR__"dong68",
	]));

//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
