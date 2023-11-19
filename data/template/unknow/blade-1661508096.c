// blade.c
// Create by TEMPLATE_D. Sat Oct 09 01:08:05 2021.
// gangdao.c
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
	set_name("[37m鬼头刀[2;37;0m", ({ "blade" }));
        set_weight(9000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄亮晃晃的鬼头刀,刀头上有鬼头,嘴里镶着一个铁环.");
                 set("value", 100000);
                set("material", "steel");
                set("wield_msg", WHT"$N「唰」的一声抽出一柄鬼头刀握在手中,刀头的铁环花拉作响.\n"NOR);
                set("unwield_msg",WHT"将手中的$n插回刀鞘。\n"NOR);
        }
        init_blade(100);
	set("can_sign", 1);
	set("no_put", 1);
	set("no_store", 1);
	set("item_owner", "wukong");
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

