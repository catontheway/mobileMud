// ai zhanglao by binlang 97/07/20
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("矮长老",({"ai zhanglao","ai"}));
//        set("nickname", RED "君子" NOR + "剑");
        set("title", YEL "华山派" NOR + YEL "隐侠" NOR);
        set("long",
                "他就是华山的隐侠，高矮二老中的矮长老\n"
              );
        set("gender", "男性");
        set("age", 85);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 30);
        set("con", 26);
        set("dex", 28);
        set("max_qi", 4000);
        set("max_jing", 3000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 100);
        set("combat_exp", 1500000);
        set("score", 50000);
        set_skill("force",180);
        set_skill("zixia-shengong", 180);
        set_skill("huashan-xinfa", 150);
        set_skill("cuff", 150);
        set_skill("poyu-quan", 150);
        set_skill("strike", 150);
        set_skill("hunyuan-zhang", 150);
        set_skill("dodge", 150);
        set_skill("huashan-shenfa", 180);
        set_skill("parry", 180);
        set_skill("sword", 150);
        set_skill("blade",150);
        set_skill("fanliangyi-dao",180);
        set_skill("huashan-jianfa",180);
        set_skill("huashan-neigong",170);
        set_skill("literate", 150);
        map_skill("cuff", "poyu-quan");
        map_skill("strike", "hunyuan-zhang");
        map_skill("force", "zixia-shengong");
        map_skill("dodge", "huashan-shenfa");
        map_skill("parry", "huashan-jianfa");
        map_skill("sword", "huashan-jianfa");
        map_skill("blade","fanliangyi-dao");
        prepare_skill("cuff", "poyu-quan");
        prepare_skill("strike", "hunyuan-zhang");
        create_family("华山派",17,"弟子");
        setup();
        carry_object("/d/huashan/npc/obj/gangdao")->wield();
        carry_object("/d/huashan/obj/baishan")->wear();
}
void attempt_apprentice(object ob)
{
      string title1;
        if ((string)ob->query("family/family_name")!="华山派")
        {
                command("say 你非我派弟子，我不能收你。");
                return ;
        }
        if((int)ob->query("betrayer"))
        {
  command("say "+RANK_D->query_respect(ob)+"你多次判师，背信弃义.我怎会收你。\n");
                return;
        }
        if ((int)ob->query("score") < 800)
          {
           command("shake " + ob->query("id"));
           command("say 你自问对本派尽心了吗?");
           return;
          }
      if((ob->query_skill("parry",1)<50)||
        (ob->query_skill("dodge",1)<50)||
        (ob->query_skill("cuff",1)<50)||
        (ob->query_skill("sword",1)<50)||   
        (ob->query_skill("parry",1)<50)||
        (ob->query_skill("strike",1)<50)
       ||(ob->query_skill("huashan-jianfa",1)<50)
       ||(ob->query_skill("force",1)<50)
       ||(ob->query_skill("poyu-quan",1)<50)
       ||(ob->query_skill("hunyuan-zhang",1)<50)
       ||(ob->query_skill("huashan-shenfa",1)<50)
       ||((ob->query_skill("zixia-shengong",1)<50)&&
       (ob->query_skill("huashan-neigong",1)<50)))  
         {
      command("say 先好好打好基础，在来拜我也不迟\n");
      return;
         }
    
            if ((int)ob->query("shen") < 50000) {
 command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
command("say 在德行方面，" + RANK_D->query_respect(ob) +
                               "是否还做得不够？");
                       return;
                                               }
     command("say 好吧，我就收下你了！\n");
    command("say 你今后可要惩恶扬善，旷扶正义！绝不可为非作歹，否则为师绝不会放过你的！\n");
           command("recruit "+ob->query("id"));
           }

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                        ob->set("title",GRN "华山派" NOR + YEL +"剑侠" NOR);
                        return;
}
void re_rank(object student)
{
        if(student->query("gender")=="男性")
        {
                
            student->set("title",GRN "华山派" NOR + YEL +"剑侠" NOR);
                        return;
               
        }
        else
        {
          student->set("title",GRN "华山派" NOR + YEL +"女剑侠" NOR);
                        return;
                
        }
}
void init()
{
        object ob;
        mapping fam;
        ::init();
        ob = this_player();
   if ( (int)ob->query("shen")<-100 && (string)ob->query("family/master_id") == "ai zhanglao")
        {
                command("say 你多次行凶越货，胡作非为，我岂能仍是你的师傅。\n");
                command("expell "+ ob->query("id"));
        }
}
