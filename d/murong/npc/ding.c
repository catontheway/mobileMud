//ding.c
//by hehe
//2003.3.13

inherit NPC;
void create()
{
	set_name("庄丁", ({ "zhuang ding", "ding" }));
    set("gender", "男性");
    set("age", 24);
	set("str", 24);
    set("int", 23);
    set("con", 23);
    set("dex", 22);
    set("combat_exp", 30000);
    set("shen_type", 0);
    set("attitude", "peaceful");
	set("max_qi",750);
    set("max_jing",500);
    set("neili",550);
    set("max_neili",550);
	set("jiali",0);
	set("score", 6000);

    set_skill("cuff", 55);
	set_skill("parry",55);
	set_skill("yanling-shenfa",55);
    set_skill("dodge",55);
	set_skill("force",55);
	set_skill("shenyuan-gong",55);
    set_skill("sword",55);

	map_skill("force","shenyuan-gong");
	map_skill("dodge","yanling-shenfa");

    set_temp("apply/attack", 20);
    set_temp("apply/defense", 20);

    set("shen_type",1);set("score",200);setup();
	carry_object(__DIR__"obj/shoes1")->wear();
    carry_object(__DIR__"obj/cloth")->wear(); 
}
