
// by Zine
inherit __DIR__"drug.c";
#include <ansi.h>
void create()
{
	set_name("千年人参片", ({ "qiannian renshenpian","renshen pian","drug" }));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "片");
		set("long", "这是一片千年人参片，可以入药。\n");
		set("value", 800);
		set("material", "grass");
		set("drugcode",30);
		
	}
	setup();
	call_out("DownPrice",1);
}
