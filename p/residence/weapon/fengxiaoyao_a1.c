#include <ansi.h> 
#include <armor.h>

inherit HANDS;

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
	      set_name("[1;31m飞瀑[2;37;0m", ({ "shengxie hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "uni16");
		set("long", @LONG
[31m胜邪威力巨大而无任何要求！
[2;37;0m这是一副由无比坚硬的[1;36m万年寒冰铁[2;37;0m加上[1;33m龙茧蚕丝[2;37;0m制成，重六斤四两六钱的[31m胜邪之手套[2;37;0m。
综合评价[35m毁天灭地[2;37;0m 看起来无比坚固，具有[1;34m倚天屠龙[2;37;0m的防护力！
上面刻了几个古符号：
[31m火[2;37;0m:[1;31m无双[2;37;0m 
上面还刻了一些符字：
坚硬:[1;33m灭世[2;37;0m 巧制:[35m标准[2;37;0m 
体灵:[1;36m完美[2;37;0m 紫石:[1;32m魔王[2;37;0m 闪电:[1;32m魔王[2;37;0m 
不老:[1;32m魔王[2;37;0m 威力:[33m很高[2;37;0m 
以及一排古篆字【 [1;32m风逍遥[2;37;0m 】。和一些【 [1;32m棍法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "fengxiaoyao");
		set("ownername", "风逍遥");
		set("value", 36000);
		  set("forge/max", 1116);
  set("forge/times_max", 1116);
  set("level", 1116);

     set("armor_prop/damage", 1116);
     set("armor_prop/attack", 95);
     set("armor_prop/defense", 79);
     set("armor_prop/armor", 740);
     set("armor_prop/magic", 82);
     
     
 //先天类    
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/personality",0);
    set("armor_prop/spirituality", 0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    //技能类
  //  set("armor_prop/claw", cla0);
    //set("armor_prop/cuff", cufftest);
    set("armor_prop/dodge", 0);
	 set("armor_prop/parry", 94);
	 set("armor_prop/force", 0);
   /* set("armor_prop/finger", fingertest);
    set("armor_prop/hand", handtest);
   
    set("armor_prop/strike", striketest);
    set("armor_prop/unarmed", unarmedtest);
    set("armor_prop/blade", bladetest);
    set("armor_prop/whip", whiptest);
    set("armor_prop/staff", stafftest);
    
    set("armor_prop/dagge", daggetest);
    set("armor_prop/hammer", hammertest);
    set("armor_prop/spear", speartest);
    set("armor_prop/throwing", throwingtest);*/
    
    
   
//特效数值
      set("armor_prop/kf_def_wound", 0);
    set("armor_prop/kf_wound", 0);
    set("armor_prop/cant_all_busy", 0);
    set("armor_prop/armor_effect_armor_vs_force", 0);
    set("armor_prop/armor_effect_healup", 0);
    set("armor_prop/armor_effect_poison", 0);
    set("armor_prop/armor_effect_rebound", 0);
 //   set("armor_prop/weapon_effect_jing", 13);
    set("armor_prop/max_all_busy", 13);
   // set("armor_prop/max_busy_dianxue", 13);
    //set("armor_prop/max_busy_jiemai", ktext);
    //set("armor_prop/max_busy_fenjin", ltext);
    //set("armor_prop/max_busy_confuse", mtext);
    //set("armor_prop/max_busy_body", ntext);
  //  set("armor_prop/AllPoisonsImmune", otext);
    //set("armor_prop/PoisonAttack", ptext);
    set("armor_prop/kf_hit_rate", 13);
    set("armor_prop/kf_anti_hr", 13);
//伤害防御类
    set("armor_prop/deep_injure", 0);
    set("armor_prop/week_injure", 16);
    set("armor_prop/abs_week_injure", 0);
    set("armor_prop/defense_attack", 0);
    set("armor_prop/armor_vs_force", 0);
    set("armor_prop/armor_effect_armor_vs_force", 0);
    set("armor_prop/attack_speed", 0);
     set("armor_prop/attack_factor", 0);
     set("armor_prop/parry_factor", 0);
     set("armor_prop/dodge_factor", 13);
//气血恢复治疗类
    set("armor_prop/max_qi", 0);
    set("armor_prop/max_jing", 94);
    set("armor_prop/neili_recover", 0);
    set("armor_prop/qi_recover", 0);
    set("armor_prop/jing_recover", 45);
    set("armor_prop/jingli_recover", 94);
    set("armor_prop/qi_cure", 0);
    set("armor_prop/jing_cure", 0);
   

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",12);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "club",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		


		set("material", "default");
    set("sharpness", 26);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";