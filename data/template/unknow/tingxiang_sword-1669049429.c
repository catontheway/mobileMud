// tingxiang_sword.c
// Create by TEMPLATE_D. Thu Nov 10 12:10:38 2022.
//听香剑
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("[1;35m听香剑[2;37;0m", ({ "tingxiang sword" }));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是姑苏慕容的收藏的宝剑，锋利无比。\n");
                 set("value", 150000);
		set("material", "steel");
           set("wield_msg", GRN"$N从剑鞘中拔出一柄红光四射的" + HIM "听香剑" NOR + GRN"，握在手中，轻轻一弹，发出「嗡嗡」的声音。\n"NOR);
		set("unwield_msg", GRN"$N舞了个剑花，将" + HIM "听香剑" NOR + "插回鞘中。\n"NOR);
	}
           init_sword(135);
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

