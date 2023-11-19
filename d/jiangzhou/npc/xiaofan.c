//Zine

inherit NPC;
inherit F_DEALER;
#include <ansi.h>

void create()
{
        string name,*tmp,*pinying;
        string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
        name=NAME_D->create_name();
        tmp=explode(name,"@");
        pinying=explode(tmp[1]," ");
        set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
        set("title", color[random(sizeof(color))]+"杂货铺老板"+NOR);
        set("shen_type", 1);
        set("random_npc",1);
        set("str", 20);
        set("gender", "男性");
        set("age", random(20)+45);
        set("long",
                "他是这里的杂货铺老板，虽然生意不好，却一直在坚持。\n");
        set("combat_exp", 8000);
        set("attitude", "friendly");
        set("inquiry", ([
                
                "here" : "这里是江州，过了江就是信阳。\n",
                
        ]));
        set("sinan","yes");
        set("vendor_goods", ({
                "/d/murong/obj/yuer",
                "/d/murong/obj/yugou",
                "/d/jiangzhou/obj/sword",
                "/d/xingxiu/npc/obj/case",
                "/clone/obj/gemlocker",
				"/clone/obj/anqidai",
                    }));

        setup();
        
}



void init()
{
        
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

