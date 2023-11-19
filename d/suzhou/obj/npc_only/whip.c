#include <ansi.h>
#include <weapon.h>
inherit WHIP;
#include <math.h>
void create()
{
	set_name(RED"蝎尾鞭"NOR, ({ "xiewei bian", "bian","whip" }));
	set_weight(3500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄蝎尾鞭，攻击十分出色。\n");
		set("value", 5000);
		set("material", "jade");
		set("wield_msg", "$N「唰」的一声抖出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n卷回腰间。\n");
	}
	init_whip(200);
	setup();
}
int npc_only()
{
	return 1;
}
int price(object me)
{
	int value=query("value"),time,*times=({});
	string *anti=({});
	if (arrayp(query("anti_job")))
	anti=query("anti_job");
	if (anti==({}))
	return value;
	for (int i=0;i<sizeof(anti);i++)
	times+=({me->query(anti[i])});
	time=max(times);
	if (time<=1000)
	value=value;
	else if (time<=1800)
	value*=2;
	else if (time<=2600)
	value*=3;
	else if (time<=6000)
	value*=(time/800);
	else
	value*=(time/500);
	return value;
}
