#include <ansi.h>
inherit NPC;
void create()
{
	set_name("小鱼儿",({"atoy npc"}));
	set("long",0);
	set("title","无门无派，世外高人");
	set("age",49);
	set("str",38);
	set("con",49);
	set("int",20);
	set("spi",11);
	set("per",44);
	set("job_title","[1;31m北侠[1;36m第一高手[2;37;0m");
	set("nickname",0);
	set("combat_exp",400000077);
	set("max_qi",21008);
	set("max_jing",15826);
	set("gender","男性");
	set("max_neili",13985);
	set("max_jingli",11624);
	set("jiali",0);
	set("race","人类");
	set("class",0);
	set("repute",2333596);
	set("score",0);
	set("family/family_name",0);
	set_skill("xiake-shengong",289);
	set_skill("hujia-daofa",26);
	set_skill("lingbo-weibu",1014);
	set_skill("xiake-jianfa",243);
	set_skill("literate",1014);
	set_skill("throwing",1014);
	set_skill("dodge",1014);
	set_skill("jinshe-zhui",1014);
	set_skill("qishang-quan",400);
	set_skill("feihua-zhuyue",301);
	set_skill("force",1015);
	set_skill("parry",1014);
	set_skill("finger",402);
	set_skill("xiake-daofa",241);
	set_skill("unarmed",13);
	set_skill("xiake-quanjiao",298);
	set_skill("mintian-jiushi",184);
	set_skill("yijin-jing",501);
	set_skill("sword",121);
	set_skill("fanwen",192);
	set_skill("yuejia-qiangfa",482);
	set_skill("spear",1009);
	set_skill("identification",51);
	set_skill("yiyang-zhi",115);
	set_skill("jinshe-jian",51);
	set_skill("xiake-strike",298);
	set_skill("liumai-shenjian",998);
	set_skill("medical-skill",451);
	set_skill("xiake-shenfa",57);
	set_skill("beiming-shengong",814);
	map_skill("throwing","jinshe-zhui");
	map_skill("dodge","lingbo-weibu");
	map_skill("force","beiming-shengong");
	map_skill("parry","liumai-shenjian");
	map_skill("finger","feihua-zhuyue");
	map_skill("unarmed","xiake-quanjiao");
	map_skill("sword","liumai-shenjian");
	map_skill("spear","yuejia-qiangfa");
	set("shen_type",1);set("score",500000);setup();
}