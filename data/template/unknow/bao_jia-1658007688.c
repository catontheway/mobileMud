// bao_jia.c
// Create by TEMPLATE_D. Tue Oct 05 13:26:20 2021.
#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name("金丝甲", ({ "bao jia" }));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是平西王收藏多年，爱之如命的一件宝甲，相传是当年魏武帝曹操所用之物
价值连城\n");
                set("material", "gold");
                set("unit", "件");
                set("value", 60000);
                set("wear_msg", BLU "$N披上了一件华美无比的宝甲。\n" NOR);

                set("remove_msg", YEL "$N将金丝甲脱了下来。\n" NOR);
                 set("armor_prop/armor", 500);
	set("no_sell", 1);
                 set("sell_in_playershop",1);
        }
	set("can_sign", 1);
	set("no_put", 1);
	set("no_store", 1);
	set("item_owner", "haitian");
	set("auto_load", 1);
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

