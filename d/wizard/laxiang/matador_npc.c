#include <ansi.h>
inherit NPC;
void create()
{
	set_name("斗牛士",({"matador npc"}));
	set("long",0);
	set("title","[32m明教[2;37;0m[33m圣使[2;37;0m");
	set("age",91);
	set("str",36);
	set("con",37);
	set("int",25);
	set("spi",5);
	set("per",37);
	set("job_title","[1;33m武学大宗师[2;37;0m");
	set("nickname",0);
	set("combat_exp",100016379);
	set("max_qi",17876);
	set("max_jing",18946);
	set("gender","男性");
	set("max_neili",11347);
	set("max_jingli",11536);
	set("jiali",737);
	set("race","人类");
	set("class",0);
	set("repute",3059419);
	set("score",1514);
	set("family/family_name","明教");
	set_skill("hujia-daofa",1002);
	set_skill("unarmed",407);
	set_skill("xiake-quanjiao",634);
	set_skill("dodge",923);
	set_skill("throwing",186);
	set_skill("longxiang-boruo",635);
	set_skill("literate",684);
	set_skill("force",900);
	set_skill("huoyan-dao",751);
	set_skill("identification",53);
	set_skill("yuxue-dunxing",923);
	set_skill("feihua-shou",441);
	set_skill("parry",974);
	set_skill("sword",961);
	set_skill("shenghuo-lingfa",961);
	set_skill("xiangfu-lun",977);
	set_skill("training",10);
	set_skill("jiuyang-shengong",909);
	set_skill("medical-skill",685);
	set_skill("strike",752);
	set_skill("qiankun-danuoyi",333);
	set_skill("huanxi-chan",507);
	set_skill("blade",992);
	set_skill("hammer",978);
	map_skill("unarmed","xiake-quanjiao");
	map_skill("dodge","yuxue-dunxing");
	map_skill("throwing","feihua-shou");
	map_skill("force","longxiang-boruo");
	map_skill("parry","qiankun-danuoyi");
	map_skill("sword","shenghuo-lingfa");
	map_skill("strike","huoyan-dao");
	map_skill("blade","hujia-daofa");
	map_skill("hammer","xiangfu-lun");
	set("shen_type",1);set("score",500000);setup();
}
