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
	set_name("[37m测试四号[2;37;0m", ({ "zhanlu sword", "sword" }));
	set_weight(23865);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "uni9");
		set("long", @LONG
[31m湛卢威力、锋利、坚硬都冠绝当世，乃千古神兵！
[2;37;0m这是一把由无比坚硬的[1;36m万年寒冰铁[2;37;0m制成，重四十七斤七两三钱的[31m湛卢之剑[2;37;0m。
综合评价[35m毁天灭地[2;37;0m 看起来无比锋利，具有[1;31m毁天灭地[2;37;0m的威力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;34m举世[2;37;0m [36m木[2;37;0m:[1;31m开元[2;37;0m [33m土[2;37;0m:[1;34m举世[2;37;0m 
上面还刻了一些符字：
锋利:[1;33m灭世[2;37;0m 福源:[33m很高[2;37;0m 
巧制:[31m精致[2;37;0m 
体灵:[1;34m举世[2;37;0m 白石:[35m标准[2;37;0m 周天:[35m标准[2;37;0m 威力:[35m标准[2;37;0m 
以及一排古篆字【 [1;32m幕后黑手[2;37;0m 】。和一些【 [1;32m指法[2;37;0m 】的技巧。

LONG
);
	set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "o");
		set("ownername", "幕后黑手");
		set("value", 36000);
 set("forge/max", 55);
  set("forge/times_max", 55);
  set("level", 55);
if(query("weapon_prop/damage"))
     set("weapon_prop/damage", 55);
     set("weapon_prop/attack", 0);
     set("weapon_prop/defense", 87);
     set("weapon_prop/armor", 67);
     set("weapon_prop/magic", 48);
     
     
 //先天类    
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/personality",0);
    set("weapon_prop/spirituality", 48);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    //技能类
  //  set("weapon_prop/claw", 0);
   // set("weapon_prop/cuff", 48);
    set("weapon_prop/dodge", 58);
    //set("weapon_prop/finger", 0);
    //set("weapon_prop/hand", 48);
    set("weapon_prop/parry", 0);
    //set("weapon_prop/strike", 0);
    //set("weapon_prop/unarmed", 48);
    //set("weapon_prop/blade", 48);
    //set("weapon_prop/whip", 48);
    //set("weapon_prop/staff", 0);
    set("weapon_prop/force", 48);
    set("weapon_prop/dagge", 0);
    //set("weapon_prop/hammer", 48);
    //set("weapon_prop/spear", 0);
    //set("weapon_prop/throwing", 0);
    
    
   
//特效数值
    set("weapon_prop/kf_def_wound", 0);
    set("weapon_prop/kf_wound", 0);
    set("weapon_prop/cant_all_busy", 7);
    set("weapon_prop/cant_busy_dianxue", 16);
    set("weapon_prop/cant_busy_jiemai", 0);
    set("weapon_prop/cant_busy_fenjin", 0);
    set("weapon_prop/cant_busy_confuse", 0);
    set("weapon_prop/cant_busy_body", 16);
    set("weapon_prop/max_all_busy", 10);
    set("weapon_prop/max_busy_dianxue", 0);
    set("weapon_prop/max_busy_jiemai", 15);
    set("weapon_prop/max_busy_fenjin", 12);
    set("weapon_prop/max_busy_confuse", 16);
    set("weapon_prop/max_busy_body", 0);
    set("weapon_prop/AllPoisonsImmune", 0);
    set("weapon_prop/PoisonAttack", 0);
    set("weapon_prop/kf_hit_rate", 8);
    set("weapon_prop/kf_anti_hr", 0);
//伤害防御类
    set("weapon_prop/deep_injure", 0);
    set("weapon_prop/week_injure", 9);
    set("weapon_prop/abs_week_injure", 0);
    set("weapon_prop/defense_attack", 0);
    set("weapon_prop/armor_vs_force", 0);
    set("weapon_prop/armor_effect_armor_vs_force", 7);
    set("weapon_prop/attack_speed", 10);
     set("weapon_prop/attack_factor", 0);
     set("weapon_prop/parry_factor", 0);
     set("weapon_prop/dodge_factor", 15);
//气血恢复治疗类
    set("weapon_prop/max_qi", 48);
    set("weapon_prop/max_jing", 48);
    set("weapon_prop/neili_recover", 0);
    set("weapon_prop/qi_recover", 48);
    set("weapon_prop/jing_recover", 48);
    set("weapon_prop/jingli_recover", 48);
    set("weapon_prop/qi_cure", 48);
    set("weapon_prop/jing_cure", 0);

    set("wtypeA",8);
    set("wtypeB",13);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",8);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",7);
    set("wtypeJ",8);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "finger",
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
	
	init_sword(1528);
	setup();
}

int query_autoload() { return 1; }

#include "/obj/weaponzy.h";