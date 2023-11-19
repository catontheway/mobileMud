// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit SWORD;

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
	set_name("[31m太阿之剑[2;37;0m", ({ "taie sword", "sword" }));
	set_weight(6288);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long","[31m太阿帝王之兵，持之能号令天下，莫有不从！$br#[2;37;0m这是一把由无比坚硬的[1;37m软银[2;37;0m制成，重十二斤五两七钱的[31m太阿之剑[2;37;0m。$br#$br#上面刻了几个古符号：$br#[32m水[2;37;0m:[1;33m灭世[2;37;0m [37m天[2;37;0m:[1;33m灭世[2;37;0m 
");
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 36000);

  //  基础类
  set("forge/max", 78);
  set("forge/times_max", 78);
  set("level", 78);
if(query("weapon_prop/damage"))
     set("weapon_prop/damage", 78);
     set("weapon_prop/attack", 0);
     set("weapon_prop/defense", 0);
     set("weapon_prop/armor", 0);
     set("weapon_prop/magic", 0);
     
     
 //先天类    
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",27);
		set("weapon_prop/personality",0);
    set("weapon_prop/spirituality", 0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",32);
    //技能类
  //  set("weapon_prop/claw", 28);
   // set("weapon_prop/cuff", 0);
    set("weapon_prop/dodge", 0);
    //set("weapon_prop/finger", 0);
    //set("weapon_prop/hand", 0);
    set("weapon_prop/parry", 0);
    //set("weapon_prop/strike", 51);
    //set("weapon_prop/unarmed", 0);
    //set("weapon_prop/blade", 0);
    //set("weapon_prop/whip", 55);
    //set("weapon_prop/staff", 0);
    set("weapon_prop/force", 0);
    set("weapon_prop/dagge", 0);
    //set("weapon_prop/hammer", 0);
    //set("weapon_prop/spear", 0);
    //set("weapon_prop/throwing", 0);
    
    
   
//特效数值
    set("weapon_prop/kf_def_wound", 0);
    set("weapon_prop/kf_wound", 15);
    set("weapon_prop/cant_all_busy", 0);
    set("weapon_prop/cant_busy_dianxue", 0);
    set("weapon_prop/cant_busy_jiemai", 0);
    set("weapon_prop/cant_busy_fenjin", 0);
    set("weapon_prop/cant_busy_confuse", 0);
    set("weapon_prop/cant_busy_body", 0);
    set("weapon_prop/max_all_busy", 0);
    set("weapon_prop/max_busy_dianxue", 0);
    set("weapon_prop/max_busy_jiemai", 16);
    set("weapon_prop/max_busy_fenjin", 19);
    set("weapon_prop/max_busy_confuse", 0);
    set("weapon_prop/max_busy_body", 0);
    set("weapon_prop/AllPoisonsImmune", 19);
    set("weapon_prop/PoisonAttack", 21);
    set("weapon_prop/kf_hit_rate", 0);
    set("weapon_prop/kf_anti_hr", 0);
//伤害防御类
    set("weapon_prop/deep_injure", 0);
    set("weapon_prop/week_injure", 23);
    set("weapon_prop/abs_week_injure", 0);
    set("weapon_prop/defense_attack", 0);
    set("weapon_prop/armor_vs_force", 0);
    set("weapon_prop/armor_effect_armor_vs_force", 0);
    set("weapon_prop/attack_speed", 21);
     set("weapon_prop/attack_factor", 0);
     set("weapon_prop/parry_factor", 0);
     set("weapon_prop/dodge_factor", 21);
//气血恢复治疗类
    set("weapon_prop/max_qi", 0);
    set("weapon_prop/max_jing", 0);
    set("weapon_prop/neili_recover", 0);
    set("weapon_prop/qi_recover", 28);
    set("weapon_prop/jing_recover", 0);
    set("weapon_prop/jingli_recover", 0);
    set("weapon_prop/qi_cure", 0);
    set("weapon_prop/jing_cure", 0);
   
//武器攻击特效
    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",20);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",22);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "axe",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 18);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_sword(199);
	setup();
}



#include "/obj/ritem/weaponzy.h";