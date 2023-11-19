// lianhuan_jia.c
// Create by TEMPLATE_D. Sat Oct 23 13:08:43 2021.
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("[31m连环甲[2;37;0m", ({ "lianhuan jia" }));
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "steel");
                set("value", 200000);
                set("armor_prop/armor", 124);
        }
	set("can_sign", 1);
	set("no_put", 1);
	set("no_store", 1);
	set("item_owner", "mm1841494562");
	set("auto_load", 1);
	set("no_sell", 1);
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

