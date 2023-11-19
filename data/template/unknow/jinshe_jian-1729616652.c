// jinshe_jian.c
// Create by TEMPLATE_D. Thu Oct 14 10:21:08 2021.
// jinshe-jian.c 金蛇剑

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name("[33m金蛇剑[2;37;0m", ({ "jinshe jian" }));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", 
"这剑金光灿烂，握在手中甚是沉重，看来竟是黄金混和了其他五
金所铸，剑身上一道血痕，发出碧油油的暗光，极是诡异。剑的
形状甚是奇特，整柄剑就如是一条蛇盘曲而成，蛇尾勾成剑柄，
蛇头则是剑尖，蛇舌伸出分叉，是以剑尖竟有两叉。\n");
                set("value", 10000);
                set("material", "gold");
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中，顿时全身凉飕飕地只感寒气逼人。\n");
                set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
        }
        init_sword(150);
	set("can_sign", 1);
	set("no_put", 1);
	set("no_store", 1);
	set("item_owner", "a2675517109");
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

