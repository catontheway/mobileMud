#include <ansi.h>
inherit NPC;
void create()
{
	set_name("家有童话",({"hopecity npc"}));
	set("long",0);
	set("title","[32m朝廷一品官员 [2;37;0m[1;33m女元帅[2;37;0m");
	set("age",107);
	set("str",38);
	set("con",40);
	set("int",22);
	set("spi",11);
	set("per",164);
	set("job_title","[1;33m武学大宗师[2;37;0m");
	set("nickname",0);
	set("combat_exp",199627851);
	set("max_qi",39143);
	set("max_jing",39696);
	set("gender","女性");
	set("max_neili",37750);
	set("max_jingli",8226);
	set("jiali",0);
	set("race","人类");
	set("class","officer");
	set("repute",15021051);
	set("score",2462);
	set("family/family_name","朝廷");
	set_skill("zui-gun",1244);
	set_skill("liumai-shenjian",1247);
	set_skill("blade",204);
	set_skill("beiming-shengong",824);
	set_skill("lingbo-weibu",1189);
	set_skill("taoism",107);
	set_skill("feihua-shou",854);
	set_skill("yiyangzhi",1202);
	set_skill("feihua-zhuyue",341);
	set_skill("meinu-quan",1213);
	set_skill("buddhism",113);
	set_skill("tiangang-beidou",312);
	set_skill("jiuyang-shengong",1220);
	set_skill("bixue-xinfa",230);
	set_skill("medical-skill",306);
	set_skill("quanzhen-jian",1244);
	set_skill("staff",201);
	set_skill("hunyuan-yiqi",323);
	set_skill("leadership",321);
	set_skill("cuff",211);
	set_skill("strategy",315);
	set_skill("yunu-xinfa",160);
	set_skill("taiji-shengong",150);
	set_skill("xiantian-gong",208);
	set_skill("taiji-quan",1241);
	set_skill("tiyunzong",1243);
	set_skill("tonggui-jian",1199);
	set_skill("jiuyin-baiguzhao",333);
	set_skill("kuangfeng-dao",1178);
	set_skill("yunu-jianfa",315);
	set_skill("sword",566);
	set_skill("kuangfeng-jian",1112);
	set_skill("dodge",1240);
	set_skill("hujia-daofa",1196);
	set_skill("force",1227);
	set_skill("literate",931);
	set_skill("parry",1244);
	set_skill("taiji-jian",1244);
	set_skill("finger",1246);
	map_skill("blade","hujia-daofa");
	map_skill("staff","zui-gun");
	map_skill("cuff","meinu-quan");
	map_skill("sword","taiji-jian");
	map_skill("dodge","tiyunzong");
	map_skill("force","beiming-shengong");
	map_skill("parry","hujia-daofa");
	map_skill("finger","feihua-zhuyue");
	setup();
}
