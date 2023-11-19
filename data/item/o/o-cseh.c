// ITEM Made by player(幕后黑手:o) /data/item/o/o-cseh.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Sep 28 05:24:57 2021
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("测试二号[2;37;0m", ({ "cseh" }));
	set_weight(15000);
	set("item_make", 1);
	set("unit", "把");
	set("long", "这是由0炼制而成的一把刀。
");
	set("makeinfo", "[1;31m
幕后黑手(o)[1;31m 出品
[2;37;0m");
	set("value", 1);
	set("point", 3808);
	set("max_consistence", 100);
	set("material", "0");
	set("material_file", "0");
	set("quality_level", 0);
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一把[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if( !check_clone() ) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return short() + query_makeinfo() + query("long") + item_long(); }
