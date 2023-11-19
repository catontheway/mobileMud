// chang_jian.c
// Create by TEMPLATE_D. Mon Sep 20 21:29:54 2021.
//sword.c
//made by hacky

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

inherit F_AUTOLOAD;
inherit F_SAVE;

void create ()
{
	set_name("[31m长剑[2;37;0m", ({ "chang jian" }));
 set_weight(5000);
	set("no_drop", 1);
	set("no_give", "[1;37m师傅给的剑，怎么能随便给别人!
[2;37;0m");
	set("no_get", 1);
 if(clonep())
   set_default_object(__FILE__);
 else {
   set("unit","柄");
   set("value",0);
   set("long",@LONG
这是一把看似寻常的长剑，但拿在手里却很合手。
剑的表面与别的长剑没有什么差别，但在剑柄上却刻有一排小字: 
               重阳赠与爱徒
LONG
    );
   set("material","steel");
   set("wield_msg","$N[唰]的一声抽出一柄$n握在手中. \n");
   set("unwield_msg","$N将手中的$n插回剑鞘. \n");
  }
   init_sword(40);
	set("can_sign", 1);
	set("no_put", 1);
	set("no_store", 1);
	set("item_owner", "dashi");
	set("auto_load", 1);
	set("no_sell", 1);
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

