#include <ansi.h>
inherit NPC;
void create()
{
	set_name("大师",({"yoda npc"}));
	set("long",0);
	set("title","[1;37m天下[1;35m第一[1;33m帅[2;37;0m");
	set("age",125);
	set("str",39);
	set("con",38);
	set("int",22);
	set("spi",12);
	set("per",45);
	set("job_title","[1;33m武学大宗师[2;37;0m");
	set("nickname",0);
	set("combat_exp",101698294);
	set("max_qi",11876);
	set("max_jing",6551);
	set("gender","男性");
	set("max_neili",25997);
	set("max_jingli",12372);
	set("jiali",0);
	set("race","人类");
	set("class","taoist");
	set("repute",8863995);
	set("score",2133);
	set("family/family_name","武当派");
	set_skill("liumai-shenjian",971);
	set_skill("cuff",973);
	set_skill("unarmed",49);
	set_skill("blade",972);
	set_skill("taiji-zhao",487);
	set_skill("beiming-shengong",660);
	set_skill("taiji-shengong",824);
	set_skill("lingbo-weibu",809);
	set_skill("taiji-quan",972);
	set_skill("taoism",216);
	set_skill("tiyunzong",984);
	set_skill("yiyangzhi",971);
	set_skill("feihua-zhuyue",913);
	set_skill("claw",488);
	set_skill("xiake-quanjiao",166);
	set_skill("sword",972);
	set_skill("dodge",984);
	set_skill("hujia-daofa",20);
	set_skill("identification",50);
	set_skill("force",825);
	set_skill("literate",552);
	set_skill("jinshe-jian",129);
	set_skill("medical-skill",296);
	set_skill("taiji-dao",971);
	set_skill("parry",972);
	set_skill("taiji-jian",971);
	set_skill("finger",972);
	map_skill("cuff","taiji-quan");
	map_skill("unarmed","xiake-quanjiao");
	map_skill("blade","taiji-dao");
	map_skill("claw","taiji-zhao");
	map_skill("sword","taiji-jian");
	map_skill("dodge","tiyunzong");
	map_skill("force","taiji-shengong");
	map_skill("parry","taiji-jian");
	map_skill("finger","yiyangzhi");
	setup();
}
