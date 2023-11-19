#include <ansi.h> 
#include <armor.h>

inherit SURCOAT;

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

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[1;36m解决[2;37;0m", ({ "chungou surcoat", "surcoat" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "uni13");
		set("long", @LONG
[31m纯钩将帅之兵，持之能挥军百万，克敌制胜！
[2;37;0m这是一条由无比坚硬的[1;36m万年寒冰铁[2;37;0m加上[1;33m龙茧蚕丝[2;37;0m制成，重二斤七两四钱的[31m纯钩之肚带[2;37;0m。
综合评价[35m毁天灭地[2;37;0m 看起来无比坚固，具有[32m水准以上[2;37;0m的防护力！
上面刻了几个古符号：
[40m地[2;37;0m:[1;31m开元[2;37;0m [36m木[2;37;0m:[1;34m举世[2;37;0m [31m火[2;37;0m:[1;31m创世[2;37;0m [1;34m电[2;37;0m:[1;31m无双[2;37;0m 
上面还刻了一些符字：
坚硬:[1;33m灭世[2;37;0m 天灵:[35m标准[2;37;0m 天宇:[32m粗糙[2;37;0m 巧制:[31m精致[2;37;0m 
白石:[32m粗糙[2;37;0m 紫石:[35m标准[2;37;0m 长生:[35m标准[2;37;0m 威力:[1;34m举世[2;37;0m 
以及一排古篆字【 [1;32m幕后黑手[2;37;0m 】。和一些【 [1;32m掌法[2;37;0m 】的技巧。

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
		  set("forge/max", 86);
  set("forge/times_max", 86);
  set("level", 86);

     set("armor_prop/damage", 86);
     set("armor_prop/attack", 0);
     set("armor_prop/defense", 0);
     set("armor_prop/armor", 247);
     set("armor_prop/magic", 0);
     
     
 //先天类    
		set("armor_prop/intelligence",56);
		set("armor_prop/strength",36);
		set("armor_prop/personality",0);
    set("armor_prop/spirituality", 0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    //技能类
    set("armor_prop/claw", 36);
    set("armor_prop/cuff", 0);
    set("armor_prop/dodge", 38);
    set("armor_prop/finger", 36);
    set("armor_prop/hand", 0);
    set("armor_prop/parry", 57);
    set("armor_prop/strike", 0);
    set("armor_prop/unarmed", 0);
    set("armor_prop/blade", 0);
    set("armor_prop/whip", 0);
    set("armor_prop/staff", 0);
    set("armor_prop/force", 36);
    set("armor_prop/dagge", 0);
    set("armor_prop/hammer", 36);
    set("armor_prop/spear", 0);
    set("armor_prop/throwing", 36);
    
    
   
//特效数值
    set("armor_prop/kf_def_wound", 6);
    set("armor_prop/kf_wound", 0);
    set("armor_prop/cant_all_busy", 10);
    set("armor_prop/cant_busy_dianxue", 0);
    set("armor_prop/cant_busy_jiemai", 0);
    set("armor_prop/cant_busy_fenjin", 0);
    set("armor_prop/cant_busy_confuse", 0);
    set("armor_prop/cant_busy_body", 0);
    set("armor_prop/max_all_busy", 14);
    set("armor_prop/max_busy_dianxue", 0);
    set("armor_prop/max_busy_jiemai", 0);
    set("armor_prop/max_busy_fenjin", 11);
    set("armor_prop/max_busy_confuse", 0);
    set("armor_prop/max_busy_body", 0);
    set("armor_prop/AllPoisonsImmune", 0);
    set("armor_prop/PoisonAttack", 0);
    set("armor_prop/kf_hit_rate", 0);
    set("armor_prop/kf_anti_hr", 0);
//伤害防御类
    set("armor_prop/deep_injure", 0);
    set("armor_prop/week_injure", 13);
    set("armor_prop/abs_week_injure", 0);
    set("armor_prop/defense_attack", 0);
    set("armor_prop/armor_vs_force", 0);
    set("armor_prop/armor_effect_armor_vs_force", 6);
    set("armor_prop/attack_speed", 13);
     set("armor_prop/attack_factor", 0);
     set("armor_prop/parry_factor", 0);
     set("armor_prop/dodge_factor", 12);
//气血恢复治疗类
    set("armor_prop/max_qi", 0);
    set("armor_prop/max_jing", 0);
    set("armor_prop/neili_recover", 0);
    set("armor_prop/qi_recover", 0);
    set("armor_prop/jing_recover", 0);
    set("armor_prop/jingli_recover", 36);
    set("armor_prop/qi_cure", 0);
    set("armor_prop/jing_cure", 0);
   

    set("wtypeA",0);
    set("wtypeB",8);
    set("wtypeC",0);
    set("wtypeD",14);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",12);
    set("wtypeI",0);
    set("wtypeJ",13);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "strike",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		


		set("material", "default");
    set("sharpness", 24);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";