#include <ansi.h>
inherit NPC;
void create()
{
	set_name("卓尔不群",({"fordfocus npc"}));
	set("long",0);
	set("title","[1;31m朝廷一品官员 [2;37;0m[1;33m鹿鼎公[2;37;0m");
	set("age",26);
	set("str",45);
	set("con",44);
	set("int",43);
	set("spi",4);
	set("per",42);
	set("job_title",0);
	set("nickname",0);
	set("combat_exp",95334582);
	set("max_qi",10242);
	set("max_jing",7609);
	set("gender","男性");
	set("max_neili",10080);
	set("max_jingli",8753);
	set("jiali",0);
	set("race","人类");
	set("class","officer");
	set("repute",1878116);
	set("score",1410);
	set("family/family_name","朝廷");
	set_skill("juemen-gun",660);
	set_skill("kuihua-zhua",589);
	set_skill("iron-cloth",450);
	set_skill("qishang-quan",399);
	set_skill("dodge",660);
	set_skill("literate",500);
	set_skill("medical-skill",539);
	set_skill("staff",590);
	set_skill("blade",602);
	set_skill("strategy",200);
	set_skill("sword",594);
	set_skill("identification",49);
	set_skill("kuangfeng-jian",592);
	set_skill("parry",593);
	set_skill("force",590);
	set_skill("training",12);
	set_skill("hujia-daofa",704);
	set_skill("bixue-xinfa",350);
	set_skill("claw",590);
	set_skill("buddhism",100);
	set_skill("yijin-jing",664);
	set_skill("leadership",200);
	set_skill("kuangfeng-dao",602);
	map_skill("dodge","juemen-gun");
	map_skill("staff","juemen-gun");
	map_skill("blade","hujia-daofa");
	map_skill("sword","kuangfeng-jian");
	map_skill("parry","hujia-daofa");
	map_skill("force","yijin-jing");
	map_skill("claw","kuihua-zhua");
	setup();
}
