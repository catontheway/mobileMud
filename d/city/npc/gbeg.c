#include <localtime.h>
#include <ansi.h>
inherit NPC;
string ask_skill();
string ask_times();
mixed ask_gift1();
void create()
{
        set_name("老乞丐", ({"gbeg"}));
        set("title", HIR"道听途说"NOR);
        set("long",
                "他是一位低调的老人，风霜满面。\n"
        );

        set("no_get",1);
        set("gender", "男性");
        set("inquiry", ([
		 "门派奖励" : (: ask_gift1: ),
                "洗点查询" : (: ask_skill, "gift_skill" : ),
                "次数查询" : (: ask_times, "chktimes" : ),
                  ]));
        set("chat_msg", ({
               // "老乞丐说道： 提供新手启动资金服务。\n",
               // "老乞丐说道： 提供新手启动技能服务。\n",
                "老乞丐说道： 提供任务次数查询服务。\n",
                      }));
        set("attitude", "friendly");
		set("shen_type",1);
		setup();
}
void init()
{
    object me = this_player();

    ::init();


    add_action("do_changegift","xd");
}

int do_changegift(string arg)
{
     int str, ints, con, dex, kar, per;
     object me;
     me = this_player();
     if (me->query("marks/changegift"))
          return notify_fail(RANK_D->query_respect(me)+"，每个人一生只有一次这样的机会！\n");
     
     if ( !arg || sscanf(arg, "%d %d %d %d %d %d", str, ints, con, dex, kar, per) != 6)
     return notify_fail("指令格式：xd <膂力> <悟性> <根骨> <身法> <福缘> <容貌>。\n");

     if(str+ints+con+dex !=80)
     return notify_fail("你的前四项属性值不等于80，请重新输入！\n");

     if(str>30 || ints>30 || con>30 || dex>30 || kar>30 || per>30)
     return notify_fail("各项属性均不能超过30！\n");
     
     if(str<10 || ints<10 || con<10 || dex<10 || kar<10 || per<10)
     return notify_fail("各项属性均不能低于10！\n");
     
     
     me->set("str",str);
     me->set("int",ints);
     me->set("con",con);
     me->set("dex",dex);
     me->set("kar", kar);
     me->set("per", per);
     me->set("marks/changegift",1);
     log_file("static/changegift", sprintf("%s(%s)于%s调整先天属性，调整后膂力%d，悟性%d，根骨%d，身法%d，福缘%d，容貌%d。\n",me->query("name"),me->query("id"),ctime(time()),me->query("str"),me->query("int"),me->query("con"),me->query("dex"),me->query("kar"),me->query("per")));
     me->save();
     write(HIM"恭喜你，老乞丐成功为你改善先天资质！\n"NOR);
     return 1;
}


 string ask_skill()

{
         object me= this_player();
      if  (me->query("combat_exp")>3000000)
     {
         return "你的经验够高了。还不自己出去闯荡江湖。臭不要脸的! ";
        
     }

  /* if (me->query("gift/skill"))
     {
         return "你已经得到启动技能！贪得无厌小心我送去小黑屋反省!";
        
     }
         me->set_temp_skill("sword",100,36000,0)
         me->set_temp_skill("hero-jianfa",100,36000,0)
         me->set_temp("gift/skill",1);*/
         tell_object(me,HIR"如果你需要的话，输入 xd 命令，我可以尝试改善下你的先天资质。
命令格式：xd <膂力> <悟性> <根骨> <身法> <福缘> <容貌>
例如      xd 20 20 20 20 20 20
记住，我只能帮你这一次，一定要考虑好了再告诉我。你可以请教下武林中的前辈，或者阅读他们的经验之著。\n"NOR);
         
       //  return 1;
     
    
}
mixed ask_gift1()
{
        //int td;
        object ob;
        object me = this_player();

      //  td = time() / 86400;

       if (me->query("gifter/which_day"))
          return notify_fail(RANK_D->query_respect(me)+"，每个人一生只有一次这样的机会！\n");

        tell_object(me, HIY "\n你领取了一个门派的礼物(" HIM "月饼" NOR + HIY ")，祝你在侠客行里玩的愉快！\n" NOR);

        ob = new("/clone/cs");
        ob->move(me, 1);
 
        me->set("gifter/which_day",1);
        return 1;
}


string ask_times()

{
	string lbl;
    object me= this_player();  
    if  (me->query("combat_exp")<3000000)
     {    
        tell_object(me, "老乞丐怒道：经验这么低，才做了几次任务就敢来问次数？丢不丢人！给我滚出去！\n");
		message_vision(HIC "只见$N飞起一脚，正中$n的屁股。$n咕噜噜地滚出门去了……\n" NOR, this_object(), me);
 		me->move("/d/city/beidajie1");
		return "真烦人！";
    }
    lbl =  HIY "    ★  %-10s★  " + HIW + "%s：" + HIC + " %s\n" NOR;
  tell_object(me, HIR"◎============================================================================◎\n");
  tell_object(me, sprintf(lbl,"萧    峰","次数", chinese_number( me->query("jobs/completed/xiaofeng") ) ));
  tell_object(me, sprintf(lbl,"韩 世 忠","次数", chinese_number( me->query("jobs/completed/hansz") ) ));
  tell_object(me, sprintf(lbl,"公 孙 止","次数", chinese_number( me->query("jobs/completed/gongsun") ) )); 
  tell_object(me, sprintf(lbl,"护    镖","次数", chinese_number( me->query("jobs/completed/hubiao") ) ));
  tell_object(me, sprintf(lbl,"慕容玉玺","次数", chinese_number( me->query("jobs/completed/murong") ) ));
  tell_object(me, sprintf(lbl,"胡 一 刀","次数", chinese_number( me->query("jobs/completed/huyidao") ) ));
  tell_object(me, sprintf(lbl,"韩 员 外","次数", chinese_number( me->query("newjobs/completed/hyw") ) ));
  tell_object(me, sprintf(lbl,"刺    杀","次数", chinese_number( me->query("jobs/completed/mzj") ) ));
  tell_object(me, sprintf(lbl,"万 安 塔","次数", chinese_number( me->query("newjobs/completed/wat") ) ));
  tell_object(me, sprintf(lbl,"T A S K ","次数", chinese_number( me->query("jobs/completed/task") ) ));  
  tell_object(me, sprintf(lbl,"鄱 阳 湖","次数", chinese_number( me->query("newjobs/completed/pyh") ) )); 
  tell_object(me, sprintf(lbl,"百 晓 生","次数", chinese_number( me->query("newjobs/completed/bxs") ) )); 
  tell_object(me, sprintf(lbl,"南海神尼","次数", chinese_number( me->query("newjobs/completed/shenni") ) )); 
  tell_object(me, HIR"◎============================================================================◎\n"NOR);

  return "多多努力！";
}

void unconcious()
{
    die();
}

void die()
{
    set("eff_qi",this_object()->query("max_qi"));
    set("qi",this_object()->query("max_qi"));
    set("eff_jing",this_object()->query("max_jing"));
    set("jing",this_object()->query("max_jing"));
    return;
}
