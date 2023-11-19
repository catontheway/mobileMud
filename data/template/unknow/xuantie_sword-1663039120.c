// xuantie_sword.c
// Create by TEMPLATE_D. Sun Oct 03 21:31:37 2021.
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
	set_name("[1;32m玄铁剑[2;37;0m", ({ "xuantie sword" }));
    set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",

"这是一把黑幽幽的长剑，入手十分沉重。\n"
);
                set("value", 21500);
	set("no_sell", 1);
                set("material", "steel");
                set("rigidity", 1000);
                set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
        }

     init_sword(125);
	set("can_sign", 1);
	set("no_put", 1);
	set("no_store", 1);
	set("item_owner", "a2675517109");
	set("auto_load", 1);
	set("weapon_prop/damage", 150);
	set("no_drop", 1);
        setup();

}

int receive_summon(object me)
{
        return ITEM_D->receive_summon(me, this_object());
}

// 隐藏物品
int hide_anywhere(object me)
{
        return ITEM_D->hide_anywhere(me, this_object());
}


int is_no_clone() { return 1; }

