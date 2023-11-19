// benguan.c 本相大师
// by paladin
#include <ansi.h>

inherit NPC;
inherit F_AQUESTMASTER;

void create()
{
       
set_name("本相大师", ({ "benxiang dashi", "benxiang" }));
        set("long",
                 "他就是本相大师。\n"
                "他今年三十岁。\n");
        set("title",RED "天龙寺" NOR + GRN +"本相大师" NOR);
        set("gender", "男性");
        set("age", 30);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("chat_chance_combat", 100);

        set("max_qi", 800);
        set("max_jing", 800);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 60);
        set("combat_exp", 90000);
        set("score", 8000);

        set_skill("force", 80);
        set_skill("dodge", 60);
        set_skill("finger", 60);
        set_skill("parry", 60);
        set_skill("sword", 60);
        set_skill("liumai-shenjian", 40);
        set_skill("yiyangzhi",40);
        set_skill("kurong-shengong",60);
        set_skill("duanshi-shenfa",60);

        map_skill("force", "kurong-shengong");
        map_skill("dodge", "duanshi-shenfa");
        map_skill("finger", "yiyangzhi");
        map_skill("sword", "liumai-shenjian");
        map_skill("parry", "yiyangzhi");
        prepare_skill("finger","yiyangzhi");
        create_family("天龙寺", 2, "弟子");
        set("class", "bonze");

        setup();
//        carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
add_action("give_wsquest","quest");
}


