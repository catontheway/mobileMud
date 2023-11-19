// linzhennan.c 林震南
// modified by Jay 4/7/96

#include <ansi.h>


inherit NPC;
string* dart_area=({"/d/pker/dangpu","/d/xiangyang/dangpu","/d/city/qianzhuang",
"/d/guiyunzhuang/taihujie2","/d/quanzhou/qianzhuang"});
string* dart_short=({"杀手帮当铺","襄阳当铺","扬州钱庄","太湖街","嘉兴钱庄"});
string* dart_id=({"dugu meng","shi chunqiu","qian yankai","shang ren","bao fangyuan",
"wang heji"});
string* dart_name=({"独孤梦","史春秋","钱眼开","商人","包方圆"});
int* dart_value=({8,11,1,8,9});

string do_job();
string do_give();
string do_fail();

int ask_fuwei();
int ask_yuantu();
int ask_pixie();
int ask_tong();

void create()
{
        set_name("林震南", ({ "lin zhennan", "lin", "zhennan" }));
        set("gender", "男性");
        set("age", 45);
        set("long", "他就是「福威镖局」的总镖头－－林震南。\n");

        set("combat_exp", 30000);
        set("shen_type", 1);

        set("max_neili", 500);
        set("neili", 500);
        set("jiali", 10);

        set_skill("force", 40);
        set_skill("sword", 50);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);

        set("inquiry", ([
                "向阳老宅" : "林震南说道：那是我从前在福建时住的家院，已经破败了。\n",
                "福威镖局" : (: ask_fuwei :),
                "远图公" : (: ask_yuantu :),
                "林远图" : "林震南大怒：小孩子这么没礼貌，直呼先人名讳！\n",
                "辟邪剑法" : (: ask_pixie:),
                "铜钱" : (: ask_tong:),
                "铜板" : (: ask_tong:),
                 "护镖": (:do_job:),
                "奖励": (:do_give:),
                "放弃":(:do_fail:),
        ]) );


        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 15);

        setup();
        carry_object("/clone/weapon/changjian")->wield();
}

int ask_fuwei()
{
 say("林震南炫耀地说：我们林家三代走镖，一来仗着先祖远图公当年闯下的威名，二\n"
     "来靠著我们林家家传的玩艺儿不算含糊，这才有今日的局面，成为大江以南首屈\n"
     "一指的大镖局。江湖上提到『福威镖局』四字，谁都要翘起大拇指，说一声：『\n"
     "好福气！好威风！』哈哈，哈哈！\n");
 this_player()->set_temp("marks/林1", 1);
 return 1;
}

int ask_yuantu()
{
  if ((int)this_player()->query_temp("marks/林1")) {
 say("林震南磕一磕烟斗，说道：远图公是我的祖父，福威镖局是他一手创办的。当年\n"
     "祖父以七十二路辟邪剑法开创镖局，当真是打遍黑道无敌手。其时白道上英雄见\n"
     "他太过威风，也有去找他比试武艺的，青城派掌门余观主的师父长青子少年之时\n"
     "便在他辟邪剑法下输了几招。\n");
 this_player()->set_temp("marks/林2", 1);
 return 1;
  }
  else {
 say("林震南说道：远图公是我的祖父。\n");
 return 1;
  }
}

int ask_pixie()
{
  int p1, p2, p3, p4;

  if ((int)this_player()->query("passwd")) {
 say("林震南不悦地说道：我不是都告诉你了吗？我的剑法不及先祖。\n");
  }
  else if ((int)this_player()->query_temp("marks/林2")) {
 say("林震南一惊，说道：你怎么知道的？噢，我刚才说露嘴了。嗨，在下的功夫外人\n"
     "不知底细，其实及不上先祖。。\n");
 write("林震南顿一顿，接着对你低声说：先祖去世前，曾给家父留下");
 p1=random(4)+1;
 p2=random(4)+1;
 p3=random(4)+1;
 p4=random(4)+1;
 this_player()->set("passwd",p1*1000+p2*100+p3*10+p4);
 write(CHINESE_D->chinese_number(p1)+"千"+CHINESE_D->chinese_number(p2)+
       "百"+CHINESE_D->chinese_number(p3)+"十"+CHINESE_D->chinese_number(p4));
 write("个\n铜钱，我一直未解其中奥秘。\n");
  }
  else {
   message("vision",
   HIY "林震南勃然大怒，喝道：你也窥视我们林家的辟邪剑谱？！我跟你拼了！\n"
   NOR, environment(), this_object() );
   kill_ob(this_player());
  }
  this_player()->delete_temp("marks/林1");
  this_player()->delete_temp("marks/林2");
  return 1;
}

int ask_tong()
{
  int p, p1, p2, p3, p4;

  if (!(p=(int)this_player()->query("passwd"))) {
 say("林震南一脸讥笑的样子，说：怎么混到这一步了到处要钱？\n");
  }
  else {
 write("林震南低声说：先祖去世前，曾给家父留下");
 p1=(int)p/1000;
 p2=(int)(p-p1*1000)/100;
 p3=(int)(p-p1*1000-p2*100)/10;
 p4=(int)(p-p1*1000-p2*100-p3*10);
 write(CHINESE_D->chinese_number(p1)+"千"+CHINESE_D->chinese_number(p2)+
       "百"+CHINESE_D->chinese_number(p3)+"十"+CHINESE_D->chinese_number(p4));
 write("个\n铜钱，我一直未解其中奥秘。\n");
  }

  return 1;
}

string do_job()
{   int n;
    object ob,cart;
    ob=this_player(); 
    n=random(sizeof(dart_area));   

    if ( ob->query("in_dart"))
    {
        if(!ob->query_temp("over_dart")&&(int)ob->query_condition("dart_limit" ) <= 0)
    	{
    		command("heng "+ob->query("id"));
    		command("say 你办事不力，还有什么面目在江湖上混？！");
    		message("vision",HIW"你的江湖声望下降了！\n"NOR,ob);
    		message("vision",HIR"你的经验下降了！\n"NOR,ob);
    		ob->add("combat_exp",(100+random(100))*ob->query_temp("cart_value"));
    		ob->add("repute",(-2-random(5))*ob->query_temp("cart_value"));
    		ob->delete("in_dart");
    		ob->delete_temp("yunbiao");
    		return "一个比一个不中用！";
    	}
    	else
    	        return "你不是才要了任务吗？\n";
    }

    if ( (int)ob->query_condition("dart_limit" ) > 0 )
       return "你好象没完成任务吧。\n";

    if ( ob->is_busy() || ob->query_temp("pending/exercising"))
                return "你现在正忙着呢。\n";
    if ( (int)ob->query("combat_exp") < 2500000 )
       return "护镖是件危险工作，我看"+RANK_D->query_respect(ob)+"似乎没有这能力！\n";

    if ( (int)ob->query_skill("force") < 20 )
       return "护镖是件危险工作，我看"+RANK_D->query_respect(ob)+"的基本内力不足！\n";
      
    if(time()-ob->query("last_yunbiao_time")<120)
    	return "你上次运镖太辛苦了,下去休息休息吧.\n";

    ob->set("in_dart",1);
    ob->set_temp("dart_area",dart_area[n]);
    ob->set_temp("dart_id",dart_id[n]);
    ob->set_temp("dart_name",dart_name[n]);
    ob->set_temp("dart_value",dart_value[n]);
    ob->apply_condition("dart_limit", 60);

    cart=new("/d/city/npc/obj/cart");
    cart->set("master",ob->query("name"));
    cart->set("masterid",ob->query("id"));
    cart->move("/d/city/zhengting");
    command("nod");
    message_vision(CYN "几个伙计将镖推了出来。\n" NOR,ob); 
    ob->set_temp("yunbiao/can_go",1);
    ob->set("last_yunbiao_time",time());
    return ob->query("name")+"把这批红货送到"+dart_short[n]+"的"+dart_name[n]+"手中。\n";
    
}

string do_give()
{
  int bonus;
  object ob;
// int max_pot;

  ob=this_player();
//   max_pot=(int)this_player()->query("max_pot");

  if ( !ob->query("in_dart"))
    return "我没让你走镖啊？\n";

  if ( !ob->query_temp("over_dart") )
    return "镖车没有送到地头，莫非是你吞了！？\n";

if (ob->query("combat_exp") < 1000000)
{
    int creward,preward,rreward;
    ob->add_temp("yunbiao/lianxu",1);
    creward=(random(40)+30)*ob->query_temp("dart_value");
    preward=(random(10)+5)*ob->query_temp("dart_value");
    rreward=(5+random(3))*ob->query_temp("dart_value");
    creward=creward*ob->query_temp("yunbiao/lianxu");
    preward=preward*ob->query_temp("yunbiao/lianxu");
    rreward=rreward*ob->query_temp("yunbiao/lianxu");
    if(ob->query_temp("yunbiao/lianxu")>6) 
    	ob->set_temp("yunbiao/lianxu",3);
    ob->add("combat_exp",creward);
    ob->add("potential",preward);
    ob->add("repute",rreward);
    message("vision",HIW"你被奖励了"+chinese_number(creward)+"点经验，"+
    chinese_number(preward)+"点潜能和\n"+chinese_number(rreward)+"点江湖声望！\n"NOR,ob);
}
else {
    int creward,preward,rreward;
    ob->add_temp("yunbiao/lianxu",1);
    creward=(random(50)+40)*ob->query_temp("dart_value");
    preward=(random(8)+8)*ob->query_temp("dart_value");
    rreward=(10+random(10))*ob->query_temp("dart_value");
    creward=creward*ob->query_temp("yunbiao/lianxu");
    preward=preward*ob->query_temp("yunbiao/lianxu");
    rreward=rreward*ob->query_temp("yunbiao/lianxu");
    ob->add("combat_exp",creward);
    ob->add("potential",preward);
    ob->add("repute",rreward);
    if(ob->query_temp("yunbiao/lianxu")>8) 
        ob->set_temp("yunbiao/lianxu",4);
    message("vision",HIW"你被奖励了"+chinese_number(creward)+"点经验，"+
    chinese_number(preward)+"点潜能和\n"+chinese_number(rreward)+"点江湖声望！\n"NOR,ob);
}
  command("pat "+ob->query("id"));
  ob->delete("in_dart");
  ob->delete_temp("over_dart");
  ob->delete_temp("dart_name");
  ob->delete_temp("dart_id");
  ob->delete_temp("dart_area");
  ob->delete_temp("dart_value");
  
  return RANK_D->query_respect(ob)+"果然是栋梁之才！\n";
}


string do_fail()
{
	object ppl=this_player();
	if(!ppl->query("in_dart"))
		return "你没有领过什么任务吧？\n";
    else
  {
    ppl->delete("in_dart");
    ppl->apply_condition("dart_limit",-1);
    command("heng "+ppl->query("id",1));
    ppl->add("combat_exp",-5000);
    ppl->add("potential",-500);
    ppl->add("repute",-500);
    message_vision("$N的经验下降了。\n$N的潜能下降了。\n$N的武林声望下降了。\n",ppl);
    }
    return "这点小事你都办不好，还能指望你作些什么呢？\n";
}
