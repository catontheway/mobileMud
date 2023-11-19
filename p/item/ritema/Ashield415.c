#include <ansi.h> 
#include <armor.h>

inherit SHIELD;

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
	      set_name("[1;37m太白之盾[2;37;0m", ({ "taibai shield", "shield" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "面");
		set("long", @LONG
[1;37m赵客缦胡缨  吴钩霜雪明$br#银鞍照白马  飒沓如流星$br#十步杀一人  千里不留行	$br#事了拂衣去  深藏身与名$br#闲过信陵饮  脱剑膝前横	$br#将炙□朱亥  持觞劝侯嬴$br#三杯吐然诺  五狱倒为轻$br#眼花耳热後  意气素霓生$br#救赵挥金槌  邯郸先震惊$br#千秋二壮士  喧赫大梁城$br#纵死侠骨香  不惭世上英$br#谁能书阁下  白首太玄经$br#[2;37;0m这是一面由无比坚硬的精钢加上[1;37m蚕丝[2;37;0m制成，重三斤一两二钱的[1;37m太白之盾[2;37;0m。$br#$br#上面刻了几个古符号：$br#[37m天[2;37;0m:[1;31m毁天[2;37;0m [1;36m人[2;37;0m:[1;33m灭世[2;37;0m 

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
     set("armor_prop/armor", 141);
     set("armor_prop/magic", 0);
     
     
 //先天类    
		set("armor_prop/intelligence",28);
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
    set("armor_prop/hand", 0);
    set("armor_prop/parry", 0);
    set("armor_prop/strike", 0);
    set("armor_prop/unarmed", 28);
    set("armor_prop/blade", 0);
    set("armor_prop/whip", 0);
    set("armor_prop/staff", 0);
    set("armor_prop/force", 0);
    set("armor_prop/dagge", 0);
    set("armor_prop/hammer", 0);
    set("armor_prop/spear", 0);
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
    set("armor_prop/max_busy_fenjin", 13);
    set("armor_prop/max_busy_confuse", 16);
    set("armor_prop/max_busy_body", 17);
    set("armor_prop/AllPoisonsImmune", 11);
    set("armor_prop/PoisonAttack", 0);
    set("armor_prop/kf_hit_rate", 0);
    set("armor_prop/kf_anti_hr", 0);
//伤害防御类
    set("armor_prop/deep_injure", 0);
    set("armor_prop/week_injure", 0);
    set("armor_prop/abs_week_injure", 0);
    set("armor_prop/defense_attack", 16);
    set("armor_prop/armor_vs_force", 0);
    set("armor_prop/armor_effect_armor_vs_force", 0);
    set("armor_prop/attack_speed", 0);
     set("armor_prop/attack_factor", 0);
     set("armor_prop/parry_factor", 0);
     set("armor_prop/dodge_factor", 0);
//气血恢复治疗类
    set("armor_prop/max_qi", 0);
    set("armor_prop/max_jing", 0);
    set("armor_prop/neili_recover", 0);
    set("armor_prop/qi_recover", 0);
    set("armor_prop/jing_recover", 0);
    set("armor_prop/jingli_recover", 0);
    set("armor_prop/qi_cure", 0);
    set("armor_prop/jing_cure", 42);
   
//攻击特效
    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",15);
    set("wtypeJ",0);
    set("wtypeK",18);
    set("wtypeL",0);
    
		
    
    
                set("skill", ([
                        "name": "axe",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 15);
        }
        setup();
}



#include "/obj/ritem/armorzy.h";