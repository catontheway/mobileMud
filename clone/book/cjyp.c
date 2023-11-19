// jinshe1.c 
inherit ITEM;
#include <ansi.h>; 
void create()
{
	set_name( YEL"基础乐谱"NOR, ({ "yp", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
        "这是一本用薄纸写成的书。上书：「基础乐谱」。\n"
        "书皮泛黄，看来已经保存很久了。\n", );
        
		set("value", 500);
		set("material", "music");
		set("skill", ([
			"name":	"music",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost": 20+random(20),// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	100	// the maximum level you can learn
		]) );
	}
}

