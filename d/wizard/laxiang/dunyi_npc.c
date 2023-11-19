#include <ansi.h>
inherit NPC;
void create()
{
	set_name("遁一",({"dunyi npc"}));
	set("long",0);
	set("title","[31m武当派[2;37;0m[32m真人[2;37;0m");
	set("age",108);
	set("str",35);
	set("con",39);
	set("int",23);
	set("spi",6);
	set("per",44);
	set("job_title","[1;33m武学大宗师[2;37;0m");
	set("nickname",0);
	set("combat_exp",100120462);
	set("max_qi",27675);
	set("max_jing",6500);
	set("gender","男性");
	set("max_neili",12410);
	set("max_jingli",7887);
	set("jiali",0);
	set("race","人类");
	set("class","taoist");
	set("repute",4690745);
	set("score",504);
	set("family/family_name","武当派");
	set_skill("iron-cloth",660);
	set_skill("literate",753);
	set_skill("taiji-zhao",634);
	set_skill("fanwen",401);
	set_skill("sword",911);
	set_skill("blade",835);
	set_skill("taiji-dao",910);
	set_skill("hujia-daofa",866);
	set_skill("force",753);
	set_skill("taoism",641);
	set_skill("claw",753);
	set_skill("cuff",626);
	set_skill("medical-skill",551);
	set_skill("parry",958);
	set_skill("tiyunzong",962);
	set_skill("taiji-shengong",810);
	set_skill("taiji-quan",957);
	set_skill("dodge",972);
	set_skill("taiji-jian",910);
	map_skill("sword","taiji-jian");
	map_skill("blade","taiji-dao");
	map_skill("force","taiji-shengong");
	map_skill("claw","taiji-zhao");
	map_skill("cuff","taiji-quan");
	map_skill("parry","taiji-jian");
	map_skill("dodge","tiyunzong");
	setup();
}
