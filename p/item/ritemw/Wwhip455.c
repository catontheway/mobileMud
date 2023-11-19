// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit WHIP;

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
	set_name("[31m莫邪之鞭[2;37;0m", ({ "moye whip", "whip" }));
	set_weight(10788);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long","[31m莫邪锋利无比，能开天辟地，荡妖除魔！$br#[2;37;0m这是一根由无比坚硬的[1;37m软银[2;37;0m制成，重二十一斤五两七钱的[31m莫邪之鞭[2;37;0m。$br#$br#上面刻了几个古符号：$br#[36m木[2;37;0m:[1;35m绝世[2;37;0m [32m水[2;37;0m:[1;31m无双[2;37;0m [31m火[2;37;0m:[32m粗糙[2;37;0m [33m土[2;37;0m:[1;36m完美[2;37;0m [37m天[2;37;0m:[1;32m魔王[2;37;0m 
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
  set("forge/max", 0);
  set("forge/times_max", 0);
  set("level", 0);
if(query("weapon_prop/damage"))
     set("weapon_prop/damage", 0);
     set("weapon_prop/attack", 0);
     set("weapon_prop/defense", 0);
     set("weapon_prop/armor", 0);
     set("weapon_prop/magic", 0);
     
     
 //先天类    
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/personality",0);
    set("weapon_prop/spirituality", 39);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",34);
    //技能类
  //  set("weapon_prop/claw", 0);
   // set("weapon_prop/cuff", 0);
    set("weapon_prop/dodge", 0);
    //set("weapon_prop/finger", 35);
    //set("weapon_prop/hand", 0);
    set("weapon_prop/parry", 82);
    //set("weapon_prop/strike", 0);
    //set("weapon_prop/unarmed", 44);
    //set("weapon_prop/blade", 0);
    //set("weapon_prop/whip", 0);
    //set("weapon_prop/staff", 0);
    set("weapon_prop/force", 0);
    set("weapon_prop/dagge", 0);
    //set("weapon_prop/hammer", 0);
    //set("weapon_prop/spear", 58);
    //set("weapon_prop/throwing", 0);
    
    
   
//特效数值
    set("weapon_prop/kf_def_wound", 0);
    set("weapon_prop/kf_wound", 0);
    set("weapon_prop/cant_all_busy", 0);
    set("weapon_prop/cant_busy_dianxue", 0);
    set("weapon_prop/cant_busy_jiemai", 0);
    set("weapon_prop/cant_busy_fenjin", 0);
    set("weapon_prop/cant_busy_confuse", 0);
    set("weapon_prop/cant_busy_body", 0);
    set("weapon_prop/max_all_busy", 0);
    set("weapon_prop/max_busy_dianxue", 3);
    set("weapon_prop/max_busy_jiemai", 0);
    set("weapon_prop/max_busy_fenjin", 0);
    set("weapon_prop/max_busy_confuse", 0);
    set("weapon_prop/max_busy_body", 0);
    set("weapon_prop/AllPoisonsImmune", 0);
    set("weapon_prop/PoisonAttack", 0);
    set("weapon_prop/kf_hit_rate", 0);
    set("weapon_prop/kf_anti_hr", 0);
//伤害防御类
    set("weapon_prop/deep_injure", 0);
    set("weapon_prop/week_injure", 0);
    set("weapon_prop/abs_week_injure", 3);
    set("weapon_prop/defense_attack", 0);
    set("weapon_prop/armor_vs_force", 8);
    set("weapon_prop/armor_effect_armor_vs_force", 0);
    set("weapon_prop/attack_speed", 0);
     set("weapon_prop/attack_factor", 0);
     set("weapon_prop/parry_factor", 0);
     set("weapon_prop/dodge_factor", 0);
//气血恢复治疗类
    set("weapon_prop/max_qi", 43);
    set("weapon_prop/max_jing", 64);
    set("weapon_prop/neili_recover", 0);
    set("weapon_prop/qi_recover", 0);
    set("weapon_prop/jing_recover", 41);
    set("weapon_prop/jingli_recover", 59);
    set("weapon_prop/qi_cure", 52);
    set("weapon_prop/jing_cure", 38);
   
//武器攻击特效
    set("wtypeA",0);
    set("wtypeB",11);
    set("wtypeC",12);
    set("wtypeD",3);
    set("wtypeE",7);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",9);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "claw",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 26);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_whip(378);
	setup();
}



#include "/obj/ritem/weaponzy.h";