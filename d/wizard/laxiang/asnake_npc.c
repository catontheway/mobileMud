#include <ansi.h>
inherit NPC;
void create()
{
	set_name("欧阳无言",({"asnake npc"}));
	set("long",0);
	set("title","[1;37m天下[1;35m第一[1;33m帅[2;37;0m");
	set("age",122);
	set("str",36);
	set("con",42);
	set("int",20);
	set("spi",8);
	set("per",48);
	set("job_title","[1;33m武学大宗师[2;37;0m");
	set("nickname","[1;35m依楼听风雨[1;37m，[1;36m淡看江湖路[2;37;0m[2;37;0m");
	set("combat_exp",101287885);
	set("max_qi",11377);
	set("max_jing",7242);
	set("gender","男性");
	set("max_neili",13654);
	set("max_jingli",9310);
	set("jiali",0);
	set("race","人类");
	set("class",0);
	set("repute",3947533);
	set("score",3196);
	set("family/family_name","白驼山");
	set_skill("stealing",10);
	set_skill("lingshe-zhangfa",1000);
	set_skill("training",236);
	set_skill("dodge",1000);
	set_skill("shentuo-zhang",1000);
	set_skill("jinshe-zhui",167);
	set_skill("hamagong",868);
	set_skill("chanchu-bufa",1000);
	set_skill("parry",1000);
	set_skill("staff",1000);
	set_skill("poison",315);
	set_skill("hand",1000);
	set_skill("hujia-daofa",1009);
	set_skill("literate",984);
	set_skill("qishang-quan",401);
	set_skill("throwing",874);
	set_skill("strike",1000);
	set_skill("blade",1004);
	set_skill("medical-skill",984);
	set_skill("unarmed",1000);
	set_skill("shexing-diaoshou",1000);
	set_skill("force",984);
	map_skill("dodge","chanchu-bufa");
	map_skill("parry","hujia-daofa");
	map_skill("staff","lingshe-zhangfa");
	map_skill("hand","shexing-diaoshou");
	map_skill("throwing","jinshe-zhui");
	map_skill("strike","shentuo-zhang");
	map_skill("blade","hujia-daofa");
	map_skill("unarmed","shentuo-zhang");
	map_skill("force","hamagong");
	setup();
}
