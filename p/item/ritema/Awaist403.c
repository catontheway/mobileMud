#include <ansi.h> 
#include <armor.h>

inherit WAIST;

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
	      set_name("[1;35m轩辕之腰带[2;37;0m", ({ "xuanyuan waist", "waist" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
		set("long", @LONG
[1;35m昔日黄帝持此物立于指南车上，驱迷雾，扫阴霾，率应龙旱魃，御百兽而战蚩尤！$br#[2;37;0m这是一条由无比坚硬的精钢加上[1;37m蚕丝[2;37;0m制成，重零斤七两七钱的[1;35m轩辕之腰带[2;37;0m。$br#

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 25000);
                  //  基础类
  set("forge/max", 0);
  set("forge/times_max", 0);
  set("level", 0);

     set("armor_prop/damage", 0);
     set("armor_prop/attack", 0);
     set("armor_prop/defense", 0);
     set("armor_prop/armor", 41);
     set("armor_prop/magic", 0);
     
     
 //先天类    
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/personality",0);
    set("armor_prop/spirituality", 0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    //技能类
    set("armor_prop/claw", 0);
    set("armor_prop/cuff", 0);
    set("armor_prop/dodge", 0);
    set("armor_prop/finger", 0);
    set("armor_prop/hand", 33);
    set("armor_prop/parry", 0);
    set("armor_prop/strike", 0);
    set("armor_prop/unarmed", 35);
    set("armor_prop/blade", 0);
    set("armor_prop/whip", 0);
    set("armor_prop/staff", 0);
    set("armor_prop/force", 0);
    set("armor_prop/dagge", 32);
    set("armor_prop/hammer", 0);
    set("armor_prop/spear", 33);
    set("armor_prop/throwing", 0);
    
    
   
//特效数值
    set("armor_prop/kf_def_wound", 0);
    set("armor_prop/kf_wound", 0);
    set("armor_prop/cant_all_busy", 0);
    set("armor_prop/cant_busy_dianxue", 0);
    set("armor_prop/cant_busy_jiemai", 0);
    set("armor_prop/cant_busy_fenjin", 0);
    set("armor_prop/cant_busy_confuse", 0);
    set("armor_prop/cant_busy_body", 0);
    set("armor_prop/max_all_busy", 0);
    set("armor_prop/max_busy_dianxue", 0);
    set("armor_prop/max_busy_jiemai", 0);
    set("armor_prop/max_busy_fenjin", 0);
    set("armor_prop/max_busy_confuse", 0);
    set("armor_prop/max_busy_body", 0);
    set("armor_prop/AllPoisonsImmune", 0);
    set("armor_prop/PoisonAttack", 20);
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
     set("armor_prop/attack_factor", 20);
     set("armor_prop/parry_factor", 0);
     set("armor_prop/dodge_factor", 0);
//气血恢复治疗类
    set("armor_prop/max_qi", 0);
    set("armor_prop/max_jing", 0);
    set("armor_prop/neili_recover", 0);
    set("armor_prop/qi_recover", 0);
    set("armor_prop/jing_recover", 0);
    set("armor_prop/jingli_recover", 0);
    set("armor_prop/qi_cure", 15);
    set("armor_prop/jing_cure", 0);
   
//攻击特效
    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
		
    
    
                set("skill", ([
                        "name": "hand",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 17);
        }
        setup();
}



#include "/obj/ritem/armorzy.h";