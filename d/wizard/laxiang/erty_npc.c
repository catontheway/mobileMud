#include <ansi.h>
inherit NPC;
void create()
{
	set_name("无量",({"erty npc"}));
	set("long","我轻轻的来了
[2;37;0m");
	set("title","[1;34m全真派[2;37;0m[31m天仙[2;37;0m");
	set("age",102);
	set("str",32);
	set("con",17);
	set("int",37);
	set("spi",6);
	set("per",37);
	set("job_title","[1;37m善人[2;37;0m");
	set("nickname","[31mMUD[1;32m玩的是一种[1;37m心态[1;32m与[1;33m心境[2;37;0m[2;37;0m");
	set("combat_exp",106041889);
	set("max_qi",10014);
	set("max_jing",9607);
	set("gender","男性");
	set("max_neili",13865);
	set("max_jingli",12545);
	set("jiali",0);
	set("race","人类");
	set("class","taoism");
	set("repute",7604559);
	set("score",5066);
	set("family/family_name","全真派");
	set_skill("parry",1016);
	set_skill("sword",1015);
	set_skill("xiantian-gong",932);
	set_skill("literate",315);
	set_skill("daoxue-xinfa",402);
	set_skill("panguan-bifa",1016);
	set_skill("jinshe-zhui",278);
	set_skill("tiangang-beidou",129);
	set_skill("finger",606);
	set_skill("array",874);
	set_skill("cuff",331);
	set_skill("jiuyin-shengong",263);
	set_skill("tonggui-jian",1016);
	set_skill("yiyang-zhi",856);
	set_skill("identification",56);
	set_skill("quanzhen-jian",1016);
	set_skill("kongming-quan",324);
	set_skill("spear",316);
	set_skill("qishang-quan",408);
	set_skill("jinshe-jian",302);
	set_skill("force",920);
	set_skill("dodge",850);
	set_skill("qixing-array",920);
	set_skill("yuejia-qiangfa",482);
	set_skill("fx-step",851);
	map_skill("parry","yiyang-zhi");
	map_skill("sword","tonggui-jian");
	map_skill("finger","yiyang-zhi");
	map_skill("array","qixing-array");
	map_skill("cuff","qishang-quan");
	map_skill("spear","yuejia-qiangfa");
	map_skill("force","xiantian-gong");
	map_skill("dodge","fx-step");
	setup();
}
