#include <ansi.h>
inherit NPC;
void create()
{
	set_name("渡四",({"highway npc"}));
	set("long",0);
	set("title","[31m少林[2;37;0m[32m长老[2;37;0m");
	set("age",144);
	set("str",28);
	set("con",33);
	set("int",33);
	set("spi",9);
	set("per",36);
	set("job_title","[1;33m武学大宗师[2;37;0m");
	set("nickname","[1;31m爱咋咋地[2;37;0m[2;37;0m");
	set("combat_exp",100694888);
	set("max_qi",11708);
	set("max_jing",26175);
	set("gender","男性");
	set("max_neili",14110);
	set("max_jingli",8863);
	set("jiali",0);
	set("race","人类");
	set("class","bonze");
	set("repute",2867327);
	set("score",2660);
	set("family/family_name","少林派");
	set_skill("parry",990);
	set_skill("iron-cloth",906);
	set_skill("strike",562);
	set_skill("yijin-jing",895);
	set_skill("damo-jian",884);
	set_skill("xiuluo-dao",993);
	set_skill("shaolin-shenfa",1002);
	set_skill("cuff",347);
	set_skill("blade",995);
	set_skill("sword",884);
	set_skill("force",907);
	set_skill("finger",1002);
	set_skill("medical-skill",905);
	set_skill("ranmu-daofa",994);
	set_skill("literate",884);
	set_skill("nianhua-zhi",179);
	set_skill("dodge",1002);
	set_skill("hujia-daofa",1003);
	set_skill("jingang-buhuai",500);
	set_skill("qishang-quan",237);
	set_skill("yizhi-chan",1002);
	set_skill("hunyuan-yiqi",500);
	set_skill("buddhism",1209);
	map_skill("parry","hujia-daofa");
	map_skill("iron-cloth","jingang-buhuai");
	map_skill("blade","xiuluo-dao");
	map_skill("sword","damo-jian");
	map_skill("force","yijin-jing");
	map_skill("finger","yizhi-chan");
	map_skill("dodge","shaolin-shenfa");
	set("shen_type",1);set("score",500000);setup();
}
