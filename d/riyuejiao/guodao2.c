//by zine
#include <ansi.h>
inherit "/d/riyuejiao/entry_prison.c";
void create()
{
	set("short","过道");
	set("long",@LONG 
一条长长的过道，过道里灯火忽明忽暗，闪烁不定。
LONG
	);
	set("exits", ([
		"east"	: __DIR__"guodaoc",
		"west"	: __DIR__"guodaob",
		"north"	: __DIR__"guodao1",
        "south" : __DIR__"guodao3",
	]));
	 set("action_list", ([
		"开北门 " : "open north",	
		"开东门 " : "open west",	
		"开西门 " : "open east",	
		"开南门 " : "open south",	
      
        	
       ]));
    set("no_task",1);
	setup();
}
