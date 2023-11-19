#include <ansi.h>
inherit NPC;
void create()
{
	set_name("泰坦",({"titan npc"}));
	set("long",0);
	set("title","[31m武当派[2;37;0m[32m道长[2;37;0m");
	set("age",111);
	set("str",35);
	set("con",43);
	set("int",47);
	set("spi",10);
	set("per",42);
	set("job_title","[1;33m武学大宗师[2;37;0m");
	set("nickname","[35m★云中城堡★[1;5m[1;33m高级生物[2;37;0m[2;37;0m");
	set("combat_exp",118899898);
	set("max_qi",41941);
	set("max_jing",9695);
	set("gender","男性");
	set("max_neili",15254);
	set("max_jingli",13594);
	set("jiali",0);
	set("race","人类");
	set("class","taoist");
	set("repute",10009819);
	set("score",520);
	set("family/family_name","武当派");
	set_skill("literate",1038);
	set_skill("medical-skill",527);
	set_skill("sword",1039);
	set_skill("yunu-xinfa",380);
	set_skill("kongming-quan",633);
	set_skill("taiji-zhao",414);
	set_skill("qixing-array",845);
	set_skill("blade",1038);
	set_skill("taiji-shengong",1054);
	set_skill("tonggui-jian",954);
	set_skill("finger",818);
	set_skill("iron-cloth",549);
	set_skill("taiji-quan",1040);
	set_skill("taoism",1205);
	set_skill("xiantian-gong",864);
	set_skill("unarmed",168);
	set_skill("yangxin-quan",623);
	set_skill("cuff",1043);
	set_skill("taiji-jian",1036);
	set_skill("taiji-dao",1039);
	set_skill("yiyang-zhi",813);
	set_skill("hujia-daofa",1038);
	set_skill("xiake-quanjiao",280);
	set_skill("parry",1047);
	set_skill("dodge",1041);
	set_skill("array",858);
	set_skill("force",1003);
	set_skill("fx-step",875);
	set_skill("tiangang-beidou",134);
	set_skill("quanzhen-jian",324);
	set_skill("tiyunzong",1038);
	set_skill("daoxue-xinfa",441);
	map_skill("sword","taiji-jian");
	map_skill("blade","taiji-dao");
	map_skill("finger","yiyang-zhi");
	map_skill("unarmed","xiake-quanjiao");
	map_skill("cuff","taiji-quan");
	map_skill("parry","hujia-daofa");
	map_skill("dodge","tiyunzong");
	map_skill("array","qixing-array");
	map_skill("force","xiantian-gong");
	setup();
}
