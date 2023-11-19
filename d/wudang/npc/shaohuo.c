// shaohuo.c 烧火道士

inherit NPC;

void create()
{
	set_name("道士", ({ "shaohuo daoshi", "daoshi" }));
	set("long", 
		"一个中年道士，他从灶台边抬起头来，脸上被烟火熏的一块黑，一块红。\n");
	set("gender", "男性");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", 1);

	set("str", 20);
	set("int", 20);
	set("con", 25);
	set("dex", 20);
	
	set("max_qi", 300);
	set("max_jing", 200);
	set("neili", 300);
	set("max_neili", 300);

	set("combat_exp", 5000);
	set("score", 1000);
	set("times",3);

//	set_skill("force", 60);
	set_skill("dodge", 40);
	set_skill("club",40);
	set_skill("unarmed", 40);
	set_skill("parry", 40);
//	set_skill("sword", 40);
//	set_skill("taiji-quan", 20);
	set_skill("taoism", 20);

//	map_skill("parry", "taiji-quan");
//	map_skill("sword", "taiji-jian");

	create_family("武当派", 4, "烧火弟子");

	setup();
        carry_object("/d/wudang/obj/yellowrobe")->wear();
        carry_object("/d/wudang/obj/huogun")->wield();
}
#include "/kungfu/class/wudang/wudang.h"
