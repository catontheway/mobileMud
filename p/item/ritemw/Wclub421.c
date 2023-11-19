// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit CLUB;

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
	set_name("[1;34m乔依乌斯之棍[2;37;0m", ({ "joeywus club", "club" }));
	set_weight(4256);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long","[1;34m在西方查理曼统治的时代，最简朴的剑也能值三头母牛的价钱。而查理大帝自己的那把传奇式的神兵“乔依乌斯”据说是半人半神的“韦兰铁匠”所造，乃当世界神兵！$br#[2;37;0m这是一根由无比坚硬的[31m流花石[2;37;0m制成，重八斤五两一钱的[1;34m乔依乌斯之棍[2;37;0m。$br#$br#上面刻了几个古符号：$br#[1;33m金[2;37;0m:[1;35m绝世[2;37;0m [1;34m电[2;37;0m:[1;33m天圣[2;37;0m [37m天[2;37;0m:[1;33m天圣[2;37;0m 
");
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 25000);

  //  基础类
  set("forge/max", 16);
  set("forge/times_max", 16);
  set("level", 16);
if(query("weapon_prop/damage"))
     set("weapon_prop/damage", 16);
     set("weapon_prop/attack", 0);
     set("weapon_prop/defense", 0);
     set("weapon_prop/armor", 0);
     set("weapon_prop/magic", 0);
     
     
 //先天类    
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/personality",0);
    set("weapon_prop/spirituality", 0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    //技能类
  //  set("weapon_prop/claw", 0);
   // set("weapon_prop/cuff", 0);
    set("weapon_prop/dodge", 0);
    //set("weapon_prop/finger", 0);
    //set("weapon_prop/hand", 0);
    set("weapon_prop/parry", 0);
    //set("weapon_prop/strike", 33);
    //set("weapon_prop/unarmed", 37);
    //set("weapon_prop/blade", 0);
    //set("weapon_prop/whip", 0);
    //set("weapon_prop/staff", 17);
    set("weapon_prop/force", 0);
    set("weapon_prop/dagge", 0);
    //set("weapon_prop/hammer", 0);
    //set("weapon_prop/spear", 0);
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
    set("weapon_prop/max_busy_dianxue", 0);
    set("weapon_prop/max_busy_jiemai", 0);
    set("weapon_prop/max_busy_fenjin", 0);
    set("weapon_prop/max_busy_confuse", 0);
    set("weapon_prop/max_busy_body", 14);
    set("weapon_prop/AllPoisonsImmune", 0);
    set("weapon_prop/PoisonAttack", 16);
    set("weapon_prop/kf_hit_rate", 0);
    set("weapon_prop/kf_anti_hr", 10);
//伤害防御类
    set("weapon_prop/deep_injure", 13);
    set("weapon_prop/week_injure", 13);
    set("weapon_prop/abs_week_injure", 0);
    set("weapon_prop/defense_attack", 0);
    set("weapon_prop/armor_vs_force", 0);
    set("weapon_prop/armor_effect_armor_vs_force", 0);
    set("weapon_prop/attack_speed", 0);
     set("weapon_prop/attack_factor", 0);
     set("weapon_prop/parry_factor", 0);
     set("weapon_prop/dodge_factor", 16);
//气血恢复治疗类
    set("weapon_prop/max_qi", 0);
    set("weapon_prop/max_jing", 0);
    set("weapon_prop/neili_recover", 0);
    set("weapon_prop/qi_recover", 0);
    set("weapon_prop/jing_recover", 0);
    set("weapon_prop/jingli_recover", 0);
    set("weapon_prop/qi_cure", 0);
    set("weapon_prop/jing_cure", 44);
   
//武器攻击特效
    set("wtypeA",11);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",10);
    set("wtypeI",10);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "parry",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 22);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_club(193);
	setup();
}



#include "/obj/ritem/weaponzy.h";