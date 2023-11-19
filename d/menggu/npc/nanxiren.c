// nanxiren.c
#include <ansi.h>;
inherit NPC;

void create()
{
        set_name("南希仁", ({ "nan xiren", "nan" }));
        set("title", "江南七侠");
        set("nickname", HIG"南山樵子"NOR);
        set("long", "
他是个挑柴模样的汉子，三十岁上下年纪，一身青布衣裤，腰里
束了根粗草绳，足穿草鞋，粗手大脚，神请木讷。\n");
        set("gender", "男性");
        set("age", 30);
       set("unique", 1);
        set("attitude", "peaceful");
        set("class", "fighter");
        set("shen_type", 1);
        set("per", 15);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);
        
        set("max_qi", 1200);
        set("max_jing", 500);
        set("neili", 1200);
        set("max_neili", 1200);
        set("jiali", 20);
        set("combat_exp", 300000);
        set("score", 6000);

        set("max_qi", 3500);
        set("max_jing", 500);
        set("neili", 3500);
        set("max_neili", 3500);
        set("jiali", 20);
        set("combat_exp", 1400000);
        set("score", 6000);

        set_skill("force", 160);
        set_skill("taiji-shengong", 160);
        set_skill("dodge", 160);
        set_skill("qingmang-jian", 160);
        set_skill("strike", 160);
        set_skill("parry", 160);
        set_skill("kunlun-zhang", 160);
        set_skill("axe", 160);
        set_skill("leiting-axe", 160);

        map_skill("force", "taiji-shengong");
        map_skill("strike", "kunlun-zhang");
        map_skill("dodge", "qingmang-jian");
        map_skill("axe", "leiting-axe");
        map_skill("parry", "wuchang-zhang");
        prepare_skill("strike", "kunlun-zhang");

        set("inquiry", ([
                "郭靖" : "靖儿是我们的乖徒儿！\n",
                "江南七侠" : "七侠可不敢当，我们七兄妹江湖上有个匪号叫江南七怪！\n",
                "江南七怪" : "住嘴！！七怪也是你叫的？！\n",
                "丘处机" : "丘道长豪侠仗义，是条汉子！\n",
                "柯镇恶" : "他是我大哥，你别看他眼睛看不见，你是什么样的人他心里很清楚。\n",
                "朱聪"   : "呵呵，小心你的口袋。\n",
                  "韩宝驹"   : "我三哥可有马王神之称。\n",
                "张阿生"   : "可惜五弟已经被黑风双煞害死了。\n",
                "全金发"   : "那是我六弟。\n",
                "韩小莹"   : "那是我七妹,你想不想试试她的越女剑？\n",
                "梅超风"   : "这婆娘，早晚我要杀了她。\n",
                "陈玄风"   : "你能告诉我他在哪吗？\n",
        ]));

        setup();
        carry_object("/d/quanzhou/npc/obj/biandan");
        carry_object("/d/quanzhou/npc/obj/axe")->wield();
        carry_object("/clone/misc/cloth")->wear();
}


int hello(object me)
{
	command("9494");
}

int bye(object me)
{
	command("wave "+me->query("id"));
}
