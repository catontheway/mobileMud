// long_lin.c
// Create by TEMPLATE_D. Mon Sep 27 20:39:36 2021.
// /d/gift/becool/longlin.c by becool 2008-11
#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
        int bonus;
        if (random(100)<90) bonus = random(50)+1;
        else if (random(100)<99) bonus = random(30)+51;
        else bonus = random(20)+81;	
	set_name("[1;33m龙 鳞[2;37;0m", ({ "long lin" }));
        set_weight(100);
	set("unit", "件");
	set("no_sell", 1);
	set("no_pawn", 1);
	set("long", "一件很轻极具质感的的贴身防具，由无数泛着微光的鳞片织成，显然来历不凡。
右下角不起眼的地方刻有一行小字：虫皮第4号，不知道是什么意思。
");
	set("value", 100000);
	set("armor_type", "cloth");
	set("material", "cloth");
	set("wear_msg", "$N脱了个精光，把[1;33m龙 鳞[2;37;0m贴身穿上，四周隐隐现出一圈光环。
");
	set("remove_msg", "$N找了个没人的角落把[1;33m龙 鳞[2;37;0m脱了下来，不胜怜惜的看了又看。
");
	set("armor_prop", ([ /* sizeof() == 2 */
  "magic" : 4,
  "armor" : 504,
]));

	set("attribute", 4);
	set("taozhuang", "long");
	set("can_sign", 1);
	set("auto_load", 1);
	set("no_drop", 1);
	set("no_put", 1);
	set("no_store", 1);
	set("item_owner", "qqa12345");
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

