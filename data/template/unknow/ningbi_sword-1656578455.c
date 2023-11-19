// ningbi_sword.c
// Create by TEMPLATE_D. Sun Sep 26 13:47:59 2021.
//ningbisword.c  凝碧剑  by hubo

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name("[1;36m凝碧剑[2;37;0m", ({ "ningbi sword" }));
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一柄闪耀着逼人光芒的宝剑\n");
                set("value",100000);
                set("material", "steel");
                set("no_steal", 1);
                set("no_beg", 1);
                set("wield_msg", HIY "$N抽出凝碧剑哈哈大笑说：这宝家伙终于落在我手了！！ \n" NOR );
                set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
        }
        init_sword(150);
	set("can_sign", 1);
	set("no_put", 1);
	set("no_store", 1);
	set("item_owner", "wn060903");
	set("auto_load", 1);
	set("no_sell", 1);
	set("no_drop", 1);
	set("rigidity", 128);
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

