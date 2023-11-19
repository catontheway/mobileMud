// shi_zi.c
// Create by TEMPLATE_D. Fri Nov 11 15:55:47 2022.
// shizi.c 玉石子

#include <weapon.h>
#include <ansi.h>
inherit THROWING;

void create()
{
	set_name("[1;37m玉石子[2;37;0m", ({ "shi zi" }));
    set_weight(150);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "把");
        set("base_unit", "枚");
        set("long", HIW"这是一枚白里透亮的石子，不过在暗器高手的手里可是行凶的利器。\n"NOR);
        set("value", 10);
        set("base_weight", 15);
        //set("material", "stone");
        set("wield_msg", "$N不知道从哪里拿出起一枚$n，捏在手中。\n");
        set("unwield_msg", "$N手中的$n又不知道跑哪里去了。\n");
    }
    set_amount(10);
    init_throwing(30);
	set("can_sign", 1);
	set("no_put", 1);
	set("no_store", 1);
	set("item_owner", "songyao");
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

