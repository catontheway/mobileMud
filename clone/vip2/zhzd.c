#pragma save_binary

// bible.c

inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(YEL"中华字典"NOR, ({ "zonghuazidian"}));
	set_weight(600);
	set("jhxk",5);
	//set("owner","教父");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
			"这是一本中华字典，上面写满了密密麻麻的字，能学到500级读书写字。\n"
			);
		set("value", 1000);
		set("material", "paper");
		set("skill", ([
			"name":	"literate",		// name of the skill
			"exp_required":	0,		// minimum combat experience required
			"jing_cost":30,			// gin cost every time study this
			"difficulty":10,		// the base int to learn this skill
							// modify is gin_cost's (difficulty - int)*5%
			"max_skill":500			// the maximum level you can learn
							// from this object.
		]) );
	}
	setup();
}
