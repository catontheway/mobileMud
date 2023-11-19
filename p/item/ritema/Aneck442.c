#include <ansi.h> 
#include <armor.h>

inherit NECK;

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
	      set_name("[1;36m昆仑之项链[2;37;0m", ({ "kunlun neck", "neck" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "串");
		set("long", @LONG
[1;36m	笑江湖浪迹十年游，空负少年头。$br#对铜陀巷泊，吟情渺渺，心事悠悠！ $br#酒令诗残梦断，南国正清愁。 $br#把剑凄然望，无处招归舟。 $br#明月天涯路远，问谁留楚佩，弄影中洲？$br#数英雄儿女，俯仰古今愁。$br#难消受灯昏罗帐，伥昙花一现恨难休！$br#飘零惯，金戈铁马，拼葬荒丘！ $br#[2;37;0m这是一串由绝对坚硬的精钢加上[1;37m蚕丝[2;37;0m制成，重一斤三两四钱的[1;36m昆仑之项链[2;37;0m。$br#$br#上面刻了几个古符号：$br#[1;33m金[2;37;0m:[1;33m天圣[2;37;0m [1;36m人[2;37;0m:[1;31m开元[2;37;0m 

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
  set("forge/max", 52);
  set("forge/times_max", 52);
  set("level", 52);

     set("armor_prop/damage", 52);
     set("armor_prop/attack", 0);
     set("armor_prop/defense", 0);
     set("armor_prop/armor", 41);
     set("armor_prop/magic", 0);
     
     
 //先天类    
		set("armor_prop/intelligence",38);
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
    set("armor_prop/parry", 50);
    set("armor_prop/strike", 0);
    set("armor_prop/unarmed", 0);
    set("armor_prop/blade", 0);
    set("armor_prop/whip", 0);
    set("armor_prop/staff", 0);
    set("armor_prop/force", 0);
    set("armor_prop/dagge", 0);
    set("armor_prop/hammer", 0);
    set("armor_prop/spear", 0);
    set("armor_prop/throwing", 25);
    
    
   
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
    set("armor_prop/PoisonAttack", 0);
    set("armor_prop/kf_hit_rate", 0);
    set("armor_prop/kf_anti_hr", 0);
//伤害防御类
    set("armor_prop/deep_injure", 9);
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
    set("armor_prop/max_jing", 0);
    set("armor_prop/neili_recover", 0);
    set("armor_prop/qi_recover", 0);
    set("armor_prop/jing_recover", 0);
    set("armor_prop/jingli_recover", 0);
    set("armor_prop/qi_cure", 0);
    set("armor_prop/jing_cure", 0);
   
//攻击特效
    set("wtypeA",10);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",13);
    set("wtypeL",0);
    
		
    
    
                set("skill", ([
                        "name": "axe",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 19);
        }
        setup();
}



#include "/obj/ritem/armorzy.h";