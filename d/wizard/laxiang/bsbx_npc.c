#include <ansi.h>
inherit NPC;
void create()
{
	set_name("不上不下",({"bsbx npc"}));
	set("long",0);
	set("title","[32m明教[2;37;0m[33m圣使[2;37;0m");
	set("age",82);
	set("str",36);
	set("con",31);
	set("int",28);
	set("spi",6);
	set("per",35);
	set("job_title","[1;33m武学大宗师[2;37;0m");
	set("nickname","[1;36m小昭美眉～～～～～～[1;37m我[1;32m来了[2;37;0m[2;37;0m");
	set("combat_exp",100245259);
	set("max_qi",19349);
	set("max_jing",18829);
	set("gender","男性");
	set("max_neili",13233);
	set("max_jingli",10661);
	set("jiali",0);
	set("race","人类");
	set("class",0);
	set("repute",4938081);
	set("score",1505);
	set("family/family_name","明教");
	set_skill("dodge",846);
	set_skill("literate",1002);
	set_skill("hand",846);
	set_skill("dagou-bang",1002);
	set_skill("force",1002);
	set_skill("strike",847);
	set_skill("qiankun-danuoyi",405);
	set_skill("jiuyang-shengong",854);
	set_skill("sword",1002);
	set_skill("claw",847);
	set_skill("xiaoyaoyou",846);
	set_skill("datengnuo-bufa",234);
	set_skill("xianglong-zhang",846);
	set_skill("iron-cloth",847);
	set_skill("begging",368);
	set_skill("parry",846);
	set_skill("feihua-shou",700);
	set_skill("qishang-quan",51);
	set_skill("shenghuo-shengong",992);
	set_skill("unarmed",606);
	set_skill("blade",975);
	set_skill("staff",1002);
	set_skill("hujia-daofa",1002);
	set_skill("throwing",847);
	set_skill("finger",847);
	set_skill("medical-skill",846);
	set_skill("huntian-qigong",770);
	map_skill("dodge","xiaoyaoyou");
	map_skill("force","jiuyang-shengong");
	map_skill("strike","xianglong-zhang");
	map_skill("sword","shenghuo-shengong");
	map_skill("parry","dagou-bang");
	map_skill("blade","hujia-daofa");
	map_skill("staff","dagou-bang");
	map_skill("throwing","feihua-shou");
	setup();
}
