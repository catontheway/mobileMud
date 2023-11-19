// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit THROWING;

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
	set_name("[1;31m天子针[2;37;0m", ({ "shengxie throwing", "throwing" }));
	set_weight(697);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "uni0");
		set("long", @LONG
[31m胜邪威力巨大而无任何要求！
[2;37;0m这是一支由极为坚硬的[1;36m万年寒冰铁[2;37;0m制成，重一斤三两九钱的[31m胜邪之暗器[2;37;0m。
综合评价[35m毁天灭地[2;37;0m 看起来极为锋利，具有[1;33m举世无匹[2;37;0m的威力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;32m魔王[2;37;0m [36m木[2;37;0m:[1;33m天圣[2;37;0m [32m水[2;37;0m:[1;36m完美[2;37;0m [31m火[2;37;0m:[1;31m创世[2;37;0m [33m土[2;37;0m:[1;33m天圣[2;37;0m [1;37m雷[2;37;0m:[1;31m无双[2;37;0m 
上面还刻了一些符字：
锋利:[1;33m灭世[2;37;0m 体灵:[33m很高[2;37;0m 闪电:[1;34m举世[2;37;0m 
周天:[1;32m魔王[2;37;0m 长生:[32m粗糙[2;37;0m 不老:[35m标准[2;37;0m 
以及一排古篆字【 [1;32m宋珧[2;37;0m 】。和一些【 [1;32m招架[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "songyao");
		set("ownername", "宋珧");
		set("value", 36000);
 set("forge/max", 0);
  set("forge/times_max", 0);
  set("level", 0);
if(query("weapon_prop/damage"))
     set("weapon_prop/damage", 0);
     set("weapon_prop/attack", 86);
     set("weapon_prop/defense", 42);
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
  //  set("weapon_prop/claw", cla0);
   // set("weapon_prop/cuff", cufftest);
    set("weapon_prop/dodge", 0);
    //set("weapon_prop/finger", fingertest);
    //set("weapon_prop/hand", handtest);
    set("weapon_prop/parry", 0);
    //set("weapon_prop/strike", striketest);
    //set("weapon_prop/unarmed", unarmedtest);
    //set("weapon_prop/blade", bladetest);
    //set("weapon_prop/whip", whiptest);
    //set("weapon_prop/staff", stafftest);
   // set("weapon_prop/force", forcetest);
  //  set("weapon_prop/dagge", daggetest);
    //set("weapon_prop/hammer", hammertest);
    //set("weapon_prop/spear", speartest);
    //set("weapon_prop/throwing", throwingtest);
    
    
   
//特效数值
     set("weapon_prop/kf_def_wound", 12);
    set("weapon_prop/kf_wound", 0);
    set("weapon_prop/cant_all_busy", 0);
    set("weapon_prop/weapon_effect_jing", 12);
    set("weapon_prop/weapon_effect_poison", 13);
    set("weapon_prop/weapon_effect_suck", 0);
  //  set("weapon_prop/cant_busy_confuse", 0);
  //  set("weapon_prop/cant_busy_body", 7);
    set("weapon_prop/max_all_busy", 0);
  //  set("weapon_prop/max_busy_dianxue", jtext);
    //set("weapon_prop/max_busy_jiemai", ktext);
   // set("weapon_prop/max_busy_fenjin", ltext);
   // set("weapon_prop/max_busy_confuse", mtext);
   // set("weapon_prop/max_busy_body", ntext);
   // set("weapon_prop/AllPoisonsImmune", otext);
  //  set("weapon_prop/PoisonAttack", ptext);
    set("weapon_prop/kf_hit_rate", 7);
    set("weapon_prop/kf_anti_hr", 11);
//伤害防御类
    set("weapon_prop/deep_injure", 0);
    set("weapon_prop/week_injure", 0);
    set("weapon_prop/abs_week_injure", 13);
    set("weapon_prop/defense_attack", 16);
    set("weapon_prop/armor_vs_force", 0);
    set("weapon_prop/armor_effect_armor_vs_force", 0);
    set("weapon_prop/attack_speed", 0);
     set("weapon_prop/attack_factor", 0);
     set("weapon_prop/parry_factor", 13);
     set("weapon_prop/dodge_factor", 0);
//气血恢复治疗类
    set("weapon_prop/max_qi", 37);
    set("weapon_prop/max_jing", 59);
    set("weapon_prop/neili_recover", 93);
    set("weapon_prop/qi_recover", 37);
    set("weapon_prop/jing_recover", 59);
    set("weapon_prop/jingli_recover", 59);
    set("weapon_prop/qi_cure", 37);
    set("weapon_prop/jing_cure", 59);

    set("wtypeA",9);
    set("wtypeB",10);
    set("wtypeC",7);
    set("wtypeD",14);
    set("wtypeE",10);
    set("wtypeF",0);
    set("wtypeG",12);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "parry",
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
	set_amount(99);
	init_throwing(858);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";