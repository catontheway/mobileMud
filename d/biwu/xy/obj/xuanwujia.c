// xuanwujia.c 玄武甲
//created by zine 25 aug 2010
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{	
	set_name(HIM"玄武甲"NOR, ({ "xuanwu jia", "armor", "jia" }) );
    set_weight(18000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
		{
			set("unit", "件");
			set("material", "steel");
			set("value", 1);
			set("long", "传说中四灵的战甲。\n");
			set("armor_prop/armor", 1000);
        }
        setup();
}
