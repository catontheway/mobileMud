#include <ansi.h> 
#include <armor.h>

inherit WEAPONTYPE;

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
	      set_name("WEAPON_SWORD", ({ "WEAPON_ID", "IDTYPE" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "unittext");
		set("long", @LONG
LONG_TITLE
LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "ownertext");
		set("ownername", "ownernametext");
		set("value", valuetext);
		  set("forge/max", damagetext);
  set("forge/times_max", damagetext);
  set("level", damagetext);

     set("armor_prop/damage", damagetext);
     set("armor_prop/attack", attacktest);
     set("armor_prop/defense", defensetext);
     set("armor_prop/armor", armortext);
     set("armor_prop/magic", magictest);
     
     
 //先天类    
		set("armor_prop/intelligence",inttext);
		set("armor_prop/strength",strtext);
		set("armor_prop/personality",pertext);
    set("armor_prop/spirituality", kartext);
		set("armor_prop/dexerity",dextext);
		set("armor_prop/constitution",context);
    //技能类
      //技能类
  //  set("armor_prop/claw", clawtext);
    //set("armor_prop/cuff", cufftest);
    set("armor_prop/dodge", dodgetext);
	 set("armor_prop/parry", parrytest);
	 set("armor_prop/force", forcetest);
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
    set("armor_prop/kf_def_wound", atext);
    set("armor_prop/kf_wound", btext);
    set("armor_prop/cant_all_busy", ctext);
    set("armor_prop/armor_effect_armor_vs_force", dtext);
    set("armor_prop/armor_effect_healup", etext);
    set("armor_prop/armor_effect_poison", ftext);
    set("armor_prop/armor_effect_rebound", gtext);
 //   set("armor_prop/weapon_effect_jing", htext);
    set("armor_prop/max_all_busy", htext);
   // set("armor_prop/max_busy_dianxue", jtext);
    //set("armor_prop/max_busy_jiemai", ktext);
    //set("armor_prop/max_busy_fenjin", ltext);
    //set("armor_prop/max_busy_confuse", mtext);
    //set("armor_prop/max_busy_body", ntext);
  //  set("armor_prop/AllPoisonsImmune", otext);
    //set("armor_prop/PoisonAttack", ptext);
    set("armor_prop/kf_hit_rate", itext);
    set("armor_prop/kf_anti_hr", jtext);
//伤害防御类
    set("armor_prop/deep_injure", stext);
    set("armor_prop/week_injure", ttext);
    set("armor_prop/abs_week_injure", utext);
    set("armor_prop/defense_attack", vtext);
    set("armor_prop/armor_vs_force", wtext);
    set("armor_prop/armor_effect_armor_vs_force", xtext);
    set("armor_prop/attack_speed", ytext);
     set("armor_prop/attack_factor", ztext);
     set("armor_prop/parry_factor", btest);
     set("armor_prop/dodge_factor", atest);
//气血恢复治疗类
    set("armor_prop/max_qi", aatext);
    set("armor_prop/max_jing", bbbtext);
    set("armor_prop/neili_recover", aatext);
    set("armor_prop/qi_recover", aatext);
    set("armor_prop/jing_recover", cctext);
    set("armor_prop/jingli_recover", ddtext);
    set("armor_prop/qi_cure", eetext);
    set("armor_prop/jing_cure", fftext);
   

    set("wtypeA",wtypeAtext);
    set("wtypeB",wtypeBtext);
    set("wtypeC",wtypeCtext);
    set("wtypeD",wtypeDtext);
    set("wtypeE",wtypeEtext);
    set("wtypeF",wtypeFtext);
    set("wtypeG",wtypeGtext);
    set("wtypeH",wtypeHtext);
    set("wtypeI",wtypeItext);
    set("wtypeJ",wtypeJtext);
    set("wtypeK",wtypeKtext);
    set("wtypeL",wtypeLtext);
    
    
                set("skill", ([
                        "name": "skillnametext",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": skilllevtext,              
                ]) );		


		set("material", "default");
    set("sharpness", sharpnesstext);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";