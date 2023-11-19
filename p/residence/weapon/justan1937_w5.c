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
	set_name("[1;37m先天剑[2;37;0m", ({ "zhanlu sword", "sword" }));
	set_weight(9624);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "uni0");
		set("long", @LONG
[31m湛卢威力、锋利、坚硬都冠绝当世，乃千古神兵！
[2;37;0m这是一把由无比坚硬的[1;36m万年寒冰铁[2;37;0m制成，重十九斤二两四钱的[31m湛卢之剑[2;37;0m。
综合评价[35m毁天灭地[2;37;0m 看起来无比锋利，具有[1;31m毁天灭地[2;37;0m的威力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;36m完美[2;37;0m [36m木[2;37;0m:[1;31m毁天[2;37;0m [33m土[2;37;0m:[1;36m完美[2;37;0m 
上面还刻了一些符字：
锋利:[1;33m灭世[2;37;0m 天渊:[33m很高[2;37;0m 巧制:[35m标准[2;37;0m 
体灵:[1;34m举世[2;37;0m 白石:[1;34m举世[2;37;0m 紫石:[31m精致[2;37;0m 闪电:[1;36m完美[2;37;0m 
长生:[1;32m魔王[2;37;0m 威力:[31m精致[2;37;0m 
以及一排古篆字【 [1;32m曹青帝[2;37;0m 】。和一些【 [1;32m掌法[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "justan1937");
		set("ownername", "曹青帝");
		set("value", 36000);
 set("forge/max", 68);
  set("forge/times_max", 68);
  set("level", 68);
if(query("weapon_prop/damage"))
     set("weapon_prop/damage", 68);
     set("weapon_prop/attack", 70);
     set("weapon_prop/defense", 89);
     set("weapon_prop/armor", 59);
     set("weapon_prop/magic", 0);
     
     
 //先天类    
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/personality",0);
    set("weapon_prop/spirituality", 0);
		set("weapon_prop/dexerity",45);
		set("weapon_prop/constitution",0);
    //技能类
  //  set("weapon_prop/claw", cla0);
   // set("weapon_prop/cuff", cufftest);
    set("weapon_prop/dodge", 87);
    //set("weapon_prop/finger", fingertest);
    //set("weapon_prop/hand", handtest);
    set("weapon_prop/parry", 61);
    //set("weapon_prop/strike", striketest);
    //set("weapon_prop/unarmed", unarmedtest);
    //set("weapon_prop/blade", bladetest);
    //set("weapon_prop/whip", whiptest);
    //set("weapon_prop/staff", stafftest);
    set("weapon_prop/force", 0);
  //  set("weapon_prop/dagge", daggetest);
    //set("weapon_prop/hammer", hammertest);
    //set("weapon_prop/spear", speartest);
    //set("weapon_prop/throwing", throwingtest);
    
    
   
//特效数值
    set("weapon_prop/kf_def_wound", 12);
    set("weapon_prop/kf_wound", 0);
    set("weapon_prop/cant_all_busy", 0);
    set("weapon_prop/cant_busy_dianxue", 0);
    set("weapon_prop/cant_busy_jiemai", 12);
    set("weapon_prop/cant_busy_fenjin", 7);
    set("weapon_prop/cant_busy_confuse", 6);
    set("weapon_prop/cant_busy_body", 0);
    set("weapon_prop/max_all_busy", 0);
    set("weapon_prop/max_busy_dianxue", 0);
    set("weapon_prop/max_busy_jiemai", 0);
    set("weapon_prop/max_busy_fenjin", 0);
    set("weapon_prop/max_busy_confuse", 0);
    set("weapon_prop/max_busy_body", 0);
    set("weapon_prop/AllPoisonsImmune", 12);
    set("weapon_prop/PoisonAttack", 0);
    set("weapon_prop/kf_hit_rate", 0);
    set("weapon_prop/kf_anti_hr", 0);
//伤害防御类
    set("weapon_prop/deep_injure", 8);
    set("weapon_prop/week_injure", 0);
    set("weapon_prop/abs_week_injure", 16);
    set("weapon_prop/defense_attack", 6);
    set("weapon_prop/armor_vs_force", 0);
    set("weapon_prop/armor_effect_armor_vs_force", 0);
    set("weapon_prop/attack_speed", 0);
     set("weapon_prop/attack_factor", 8);
     set("weapon_prop/parry_factor", 0);
     set("weapon_prop/dodge_factor", 10);
//气血恢复治疗类
    set("weapon_prop/max_qi", 0);
    set("weapon_prop/max_jing", 0);
    set("weapon_prop/neili_recover", 0);
    set("weapon_prop/qi_recover", 45);
    set("weapon_prop/jing_recover", 0);
    set("weapon_prop/jingli_recover", 0);
    set("weapon_prop/qi_cure", 0);
    set("weapon_prop/jing_cure", 45);

    set("wtypeA",7);
    set("wtypeB",15);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",7);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",16);
    set("wtypeJ",0);
    set("wtypeK",14);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "strike",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		
		set("base_unit", "发");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 24);

		set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放下。\n");
	}
	
	init_sword(1549);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";