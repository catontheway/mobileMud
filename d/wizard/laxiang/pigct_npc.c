#include <ansi.h>
inherit NPC;
void create()
{
	set_name("铭文",({"pigct npc"}));
	set("long",0);
	set("title","[32m天龙寺[2;37;0m[33m特使[2;37;0m");
	set("age",163);
	set("str",29);
	set("con",29);
	set("int",31);
	set("spi",7);
	set("per",36);
	set("job_title","[1;33m武学大宗师[2;37;0m");
	set("nickname","[1;36m水　[1;37m云　[1;32m间[2;37;0m——　[1;33m大　将　军[2;37;0m[2;37;0m");
	set("combat_exp",105681225);
	set("max_qi",12470);
	set("max_jing",8188);
	set("gender","男性");
	set("max_neili",15748);
	set("max_jingli",12587);
	set("jiali",0);
	set("race","人类");
	set("class",0);
	set("repute",1517677);
	set("score",2003);
	set("family/family_name","天龙寺");
	set_skill("dodge",1008);
	set_skill("finger",1008);
	set_skill("liumai-shenjian",1008);
	set_skill("juemen-gun",1008);
	set_skill("strategy",203);
	set_skill("strike",52);
	set_skill("literate",1008);
	set_skill("yuejia-qiangfa",482);
	set_skill("beiming-shengong",652);
	set_skill("xiake-shenfa",920);
	set_skill("staff",1008);
	set_skill("xiake-strike",1009);
	set_skill("buddhism",153);
	set_skill("iron-cloth",1008);
	set_skill("jinshe-jian",301);
	set_skill("bizhen-qingzhang",37);
	set_skill("claw",1008);
	set_skill("parry",1008);
	set_skill("xiake-jianfa",847);
	set_skill("bixue-xinfa",363);
	set_skill("kuihua-zhua",837);
	set_skill("blade",1008);
	set_skill("yijin-jing",651);
	set_skill("hujia-daofa",1008);
	set_skill("force",1008);
	set_skill("kuangfeng-dao",1008);
	set_skill("spear",924);
	set_skill("unarmed",2);
	set_skill("kuangfeng-jian",1008);
	set_skill("qishang-quan",402);
	set_skill("medical-skill",1008);
	set_skill("xiake-quanjiao",1009);
	set_skill("feihua-zhuyue",304);
	set_skill("xiake-daofa",850);
	set_skill("yiyang-zhi",252);
	set_skill("leadership",201);
	set_skill("xiake-shengong",1008);
	set_skill("lingbo-weibu",1008);
	set_skill("training",301);
	set_skill("sword",1008);
	map_skill("dodge","xiake-shenfa");
	map_skill("finger","feihua-zhuyue");
	map_skill("strike","xiake-strike");
	map_skill("staff","juemen-gun");
	map_skill("claw","kuihua-zhua");
	map_skill("parry","hujia-daofa");
	map_skill("blade","hujia-daofa");
	map_skill("force","xiake-shengong");
	map_skill("spear","yuejia-qiangfa");
	map_skill("unarmed","xiake-quanjiao");
	map_skill("sword","kuangfeng-jian");
	set("shen_type",1);set("score",500000);setup();
}
