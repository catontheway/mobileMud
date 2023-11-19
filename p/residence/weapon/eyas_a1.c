#include <ansi.h> 
#include <armor.h>

inherit CLOTH;

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
	      set_name("[1;33m测试[2;37;0m", ({ "gongbu cloth", "cloth" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "uni0");
		set("long", @LONG
[31m工布天生怪异，功能参商！
[2;37;0m这是一件由无比坚硬的[1;36m万年寒冰铁[2;37;0m加上[1;33m龙茧蚕丝[2;37;0m制成，重十三斤七两二钱的[31m工布之服装[2;37;0m。
综合评价[35m毁天灭地[2;37;0m 看起来无比坚固，具有[1;33m举世无匹[2;37;0m的防护力！
上面刻了几个古符号：
[1;33m金[2;37;0m:[1;33m天圣[2;37;0m [1;35m风[2;37;0m:[1;31m创世[2;37;0m 
[1;34m电[2;37;0m:[1;31m毁天[2;37;0m 
上面还刻了一些符字：
坚硬:[1;33m灭世[2;37;0m 天灵:[35m标准[2;37;0m 天宇:[33m很高[2;37;0m 巧制:[1;36m完美[2;37;0m 
闪电:[31m精致[2;37;0m 
不老:[31m精致[2;37;0m 
以及一排古篆字【 [1;32m眼[2;37;0m 】。和一些【 [1;32m剑法[2;37;0m 】的技巧。

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "eyas");
		set("ownername", "眼");
		set("value", 36000);
		  set("forge/max", 0);
  set("forge/times_max", 0);
  set("level", 0);

     set("armor_prop/damage", 0);
     set("armor_prop/attack", 66);
     set("armor_prop/defense", 0);
     set("armor_prop/armor", 840);
     set("armor_prop/magic", 0);
     
     
 //先天类    
		set("armor_prop/intelligence",55);
		set("armor_prop/strength",46);
		set("armor_prop/personality",0);
    set("armor_prop/spirituality", 0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    //技能类
  //  set("armor_prop/claw", cla0);
    //set("armor_prop/cuff", cufftest);
    set("armor_prop/dodge", 0);
	 set("armor_prop/parry", 0);
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
    set("armor_prop/armor_effect_armor_vs_force", 15);
    set("armor_prop/armor_effect_healup", 0);
    set("armor_prop/armor_effect_poison", 0);
    set("armor_prop/armor_effect_rebound", 0);
 //   set("armor_prop/weapon_effect_jing", 0);
    set("armor_prop/max_all_busy", 0);
   // set("armor_prop/max_busy_dianxue", 0);
    //set("armor_prop/max_busy_jiemai", ktext);
    //set("armor_prop/max_busy_fenjin", ltext);
    //set("armor_prop/max_busy_confuse", mtext);
    //set("armor_prop/max_busy_body", ntext);
  //  set("armor_prop/AllPoisonsImmune", otext);
    //set("armor_prop/PoisonAttack", ptext);
    set("armor_prop/kf_hit_rate", 0);
    set("armor_prop/kf_anti_hr", 0);
//伤害防御类
    set("armor_prop/deep_injure", 0);
    set("armor_prop/week_injure", 0);
    set("armor_prop/abs_week_injure", 0);
    set("armor_prop/defense_attack", 0);
    set("armor_prop/armor_vs_force", 0);
    set("armor_prop/armor_effect_armor_vs_force", 0);
    set("armor_prop/attack_speed", 0);
     set("armor_prop/attack_factor", 0);
     set("armor_prop/parry_factor", 0);
     set("armor_prop/dodge_factor", 0);
//气血恢复治疗类
    set("armor_prop/max_qi", 0);
    set("armor_prop/max_jing", 69);
    set("armor_prop/neili_recover", 0);
    set("armor_prop/qi_recover", 0);
    set("armor_prop/jing_recover", 62);
    set("armor_prop/jingli_recover", 69);
    set("armor_prop/qi_cure", 0);
    set("armor_prop/jing_cure", 0);
   

    set("wtypeA",10);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",14);
    set("wtypeG",0);
    set("wtypeH",15);
    set("wtypeI",13);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",13);
    
    
                set("skill", ([
                        "name": "sword",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		


		set("material", "default");
    set("sharpness", 19);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";