// taiyuan_axe.c
// Create by TEMPLATE_D. Mon Sep 20 14:13:13 2021.
// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit AXE;

string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

void create()
{
	set_name("[37m太渊之斧[2;37;0m★", ({ "taiyuan axe" }));
	set_weight(6588);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long","[37m太渊之斧[2;37;0m这是一柄由极其坚硬的[1;32m绿石[2;37;0m制成，重十三斤一两七钱的[37m太渊之斧[2;37;0m。上面刻了几个古符号：[1;36m人[2;37;0m:[1;34m举世[2;37;0m 
");
    set("no_get",1);
	set("no_put", 1);
	  set("no_pawn",1);
	set("no_drop", 1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 16000);

  //  基础类
  set("forge/max", 0);
  set("forge/times_max", 0);
  set("level", 0);
if(query("weapon_prop/damage"))
	set("weapon_prop", ([ /* sizeof() == 1 */
  "max_qi" : 1000,
]));










































































    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",8);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "unarmed",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 18);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_axe(512);
	set("can_sign", 1);
	set("no_store", 1);
	set("item_owner", "o");
	set("bowner", "o");
	set("auto_load", 1);
	set("no_sell", 1);
	setup();
}



#include "/obj/ritem/weaponzy.h";
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

