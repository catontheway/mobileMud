
// by Zine
inherit __DIR__"drug.c";
#include <ansi.h>
void create()
{
	set_name("松节", ({ "song jie","drug" }));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "片");
		set("long", "这是一片松节，可以入药。\n");
		set("value", 3500);
		set("material", "grass");
		set("drugcode",21);
		
	}
	setup();
	call_out("DownPrice",1);
}
