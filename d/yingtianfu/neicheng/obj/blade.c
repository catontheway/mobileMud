#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("精钢刀", ({ "jinggang dao", "dao","blade" }));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄大明制式的佩刀，高级武将方可使用。\n");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
		set("no_drop",1);
		set("no_give",1);
		set("no_get","大明的制式佩刀，捡了要杀头的。\n");
	}
	init_blade(100+random(25));
	setup();
}
