// ganjiang_blade.c
// Create by TEMPLATE_D. Mon Sep 20 13:49:48 2021.
// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit BLADE;

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
	set_name("[31m干将之刀[2;37;0m", ({ "ganjiang blade" }));
	set_weight(12158);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "uni0");
		set("long","[31m干将威力无比，能开天辟地，荡妖除魔！$br#[2;37;0m这是一柄由绝对坚硬的[1;37m软银[2;37;0m制成，重二十四斤三两一钱的[31m干将之刀[2;37;0m。$br#$br#上面刻了几个古符号：$br#[32m水[2;37;0m:[1;31m开元[2;37;0m [1;35m风[2;37;0m:[1;35m绝世[2;37;0m $br#[1;37m雷[2;37;0m:[1;34m举世[2;37;0m [40m地[2;37;0m:[1;31m开元[2;37;0m 
");
    set("no_get",1);
	set("no_put", 1);
	  set("no_pawn",1);
	set("no_drop", 1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 36000);

  //  基础类
  set("forge/max", 100);
  set("forge/times_max", 100);
  set("level", 100);
if(query("weapon_prop/damage"))
     set("weapon_prop/damage", 1000);
     set("weapon_prop/attack", 1000);
     set("weapon_prop/defense", 1000);
     set("weapon_prop/armor", 1000);
     set("weapon_prop/magic", 1000);
     
     
 //先天类    
		set("weapon_prop/intelligence",1000);
		set("weapon_prop/strength",1000);
		set("weapon_prop/personality",1000);
    set("weapon_prop/spirituality", 1000);
		set("weapon_prop/dexerity",1000);
		set("weapon_prop/constitution",1000);
    //技能类
  //  set("weapon_prop/claw", 68);
   // set("weapon_prop/cuff", 61);
    set("weapon_prop/dodge", 1000);
    //set("weapon_prop/finger", 0);
    //set("weapon_prop/hand", 0);
    set("weapon_prop/parry", 1000);
    //set("weapon_prop/strike", 0);
    //set("weapon_prop/unarmed", 0);
    //set("weapon_prop/blade", 0);
    //set("weapon_prop/whip", 0);
    //set("weapon_prop/staff", 0);
    set("weapon_prop/force", 1000);
    set("weapon_prop/dagge", 1000);
    //set("weapon_prop/hammer", 46);
    //set("weapon_prop/spear", 0);
    //set("weapon_prop/throwing", 0);
    
    
   
//特效数值
    set("weapon_prop/kf_def_wound", 1000);
    set("weapon_prop/kf_wound", 1000);
    set("weapon_prop/cant_all_busy", 1000);
    set("weapon_prop/cant_busy_dianxue", 1000);
    set("weapon_prop/cant_busy_jiemai", 1000);
    set("weapon_prop/cant_busy_fenjin", 1000);
    set("weapon_prop/cant_busy_confuse", 1000);
    set("weapon_prop/cant_busy_body", 1000);
    set("weapon_prop/max_all_busy", 1000);
    set("weapon_prop/max_busy_dianxue", 1000);
    set("weapon_prop/max_busy_jiemai", 1000);
    set("weapon_prop/max_busy_fenjin", 1000);
    set("weapon_prop/max_busy_confuse", 1000);
    set("weapon_prop/max_busy_body", 1000);
    set("weapon_prop/AllPoisonsImmune", 1000);
    set("weapon_prop/PoisonAttack", 1000);
    set("weapon_prop/kf_hit_rate", 1000);
    set("weapon_prop/kf_anti_hr", 1000);
//伤害防御类
    set("weapon_prop/deep_injure", 1000);
    set("weapon_prop/week_injure", 1000);
    set("weapon_prop/abs_week_injure", 1000);
    set("weapon_prop/defense_attack", 1000);
    set("weapon_prop/armor_vs_force", 1000);
    set("weapon_prop/armor_effect_armor_vs_force", 1000);
    set("weapon_prop/attack_speed", 1000);
     set("weapon_prop/attack_factor", 1000);
     set("weapon_prop/parry_factor", 1000);
     set("weapon_prop/dodge_factor", 1000);
//气血恢复治疗类
    set("weapon_prop/max_qi", 1000);
    set("weapon_prop/max_jing", 1000);
    set("weapon_prop/neili_recover", 1000);
    set("weapon_prop/qi_recover", 1000);
    set("weapon_prop/jing_recover", 1000);
    set("weapon_prop/jingli_recover", 1000);
    set("weapon_prop/qi_cure", 1000);
    set("weapon_prop/jing_cure", 1000);
   
//武器攻击特效
    set("wtypeA",1000);
    set("wtypeB",1000);
    set("wtypeC",1300);
    set("wtypeD",1000);
    set("wtypeE",1000);
    set("wtypeF",1100);
    set("wtypeG",800);
    set("wtypeH",1000);
    set("wtypeI",1000);
    set("wtypeJ",1000);
    set("wtypeK",1000);
    set("wtypeL",1000);
    

                set("skill", ([
                        "name": "whip",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 25);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_blade(979);
	set("can_sign", 1);
	set("no_store", 1);
	set("item_owner", "o");
	set("bowner", "o");
	set("auto_load", 1);
	set("no_sell", 1);
	set("rigidity", 145);
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

