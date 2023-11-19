#include <ansi.h>
// damo.c 达摩老祖

inherit NPC;
inherit F_MASTER;
string ask_me();
void consider();
void heal();

void create()
{
    set_name("达摩老祖", ({"damo laozu","laozu"}));
    set("long",
            "他就是当年从天竺来中土的达摩祖师. \n"
            "他神态祥和，面带微笑，是你如沐春风. \n"
            "他端坐这那里，口中喃喃的诵读着佛经. \n");
    set("title",RED "少林" NOR + GRN "祖师" NOR);
    set("gender", "男性");
    set("age", 100);
    set("attitude", "friendly");
    set("shen_type", 1);
    set("str", 30);
    set("int", 30);
    set("con", 30);
    set("dex", 30);

    set("max_qi", 5000);
    set("max_jing", 3000);
    set("neili", 5000);
    set("max_neili", 5000);
    set("jiali", 100);
    set("combat_exp", 15000000);
    set("score", 500000);
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
                (: consider() :)
                }) );
    set("chat_chance", 100);
    set("chat_msg", ({
                (: heal :),
                }));

    set_skill("force", 500);
    set_skill("hunyuan-yiqi", 480);
    set_skill("tongzi-gong",200);
    set_skill("blade", 500);
    set_skill("xiuluo-dao", 500);
    set_skill("dodge", 450);
    set_skill("shaolin-shenfa", 450);
    set_skill("cuff", 500);
    set_skill("jingang-quan",500);
    set_skill("parry",500);
    set_skill("sword", 500);
    set_skill("damo-jian", 500);
    set_skill("buddhism", 450);
    set_skill("finger", 500);
    set_skill("nianhua-zhi", 500);
    set_skill("literate", 280);

    map_skill("force","hunyuan-yiqi");
    map_skill("dodge","shaolin-shenfa");
    map_skill("cuff","jingang-quan");
    map_skill("parry","jingang-quan");
    map_skill("blade","xiuluo-dao");
    map_skill("sword","damo-jian");
    map_skill("finger","nianhua-zhi");
    prepare_skill("finger", "nianhua-zhi");
    set("inquiry",
            ([
             "洗髓经" : (: ask_me :),
             ]));
    set("book_count", 1);

    create_family("少林派",1,"祖师");
    set("class", "bonze");

    setup();
    carry_object("/clone/weapon/changjian");
}

string ask_me()
{
    mapping fam;
    object ob;
    
    if(!(fam=this_player()->query("family"))
        ||fam["family_name"]!="少林派")
        return RANK_D->query_respect(this_player())+
            "与本派素无往来，不知此话从何说起?";
    if ( this_player()->query("score") < 200 )
        return "你对本派贡献太小，本派的上乘武学现在还不能给你。";
    if(this_player()->query_skill("force") <100)
        return RANK_D->query_respect(this_player())+
            "你的内力修为不够，要了也没用";
    if (query("book_count") <1)
        return "洗髓经已被别人取走，你请回吧.";
    add("book_count", -1);
    ob=new("d/shaolin/obj/xisui");
    ob->move(this_player());
    return "好吧，你就拿去吧,一定要好好保管.";
}

void attempt_apprentice(object ob)
{
    if ((string)ob->query("family/family_name")!="少林派" || (string)ob->query("class")!="bonze") {
        command("say 少林乃佛门圣地");
        command("say " + RANK_D->query_respect(ob) + "六根未净，老衲不能收你");
        return;
    }
    if((int)ob->query("betrayer")>=1)
    {
        command("say "+RANK_D->query_respect(ob)+"你多次叛师，背信弃义。我怎会收你。\n");
        return;
    }
    if ((int)ob->query_skill("buddhism", 1) < 150) {
        command("say 你的禅宗心法太弱，不易修行上乘武功.");
        command("say " + RANK_D->query_respect(ob) + 
                "还是回去吧");
        return;
    }
    if ((int)ob->query("shen") < 100000) {
        command("say 出家人慈悲为怀，德行是很重要的");
        command("say 德行乃修行之本" + RANK_D->query_respect(ob) + 
                " 德行还欠缺了些，希望你能加强这方面的修行.");
        return;
    }
    if (ob->query_int() < 40) {
        command("say 禅宗最重视顿悟");
        command("say " + RANK_D->query_respect(ob) + "悟性不够,不能传我衣钵.");
        return;
    }
    command("recruit " + ob->query("id"));
    ob->set("title" , RED "少林" NOR + GRN "长老" NOR);
    ob->set("name" , "渡" + ob->query("name")[2..3]);
}

void init()
{

    object ob;
    mapping fam;

    ::init();

    ob = this_player();
    if ((int)ob->query("shen") < 0 && (string)ob->query("family/master_id") == "damo laozu") 
    {
        command("say 你多次行凶越货，胡作非为，我岂能仍是你的师傅。\n");
        command("expell "+ ob->query("id"));
    }
}       
void consider()
{
    object *enemy,target;
    enemy = query_enemy() - ({ 0 });
    target = enemy[random(sizeof(enemy))];
    switch( random(2) )
    {
        case 0:
            command("wield jian");
            command("perform sword.sanjue " + target->query("id"));
            command("unwield jian");
            break;
        case 1: 
            command("perform finger.fuxue " +target->query("id"));           
            break;
    }
}
void heal()
{
    object ob=this_object();

    if (ob->query("eff_qi") < ob->query("max_qi"))
    {
        command("exert heal");
        command("enforce 100");
        return;
    }

    if (ob->query("qi") < ob->query("eff_qi"))
    {
        command("exert recover");
        return;
    }

    if (ob->query("jing") < ob->query("eff_jing"))
        command("exert regenerate");

    return;
}
