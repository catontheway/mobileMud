//chengyao  按平一指的药方配出来的成药
//Made By jason@mudnow.com
//2000-5.-6
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("成药",({"cheng yao","yao"}));
        set("long","这是按平一指交给你的药方配出来的成药。\n");
        set("unit","包");
        setup();
}

int give_chengyao(object target,object ppl)
{
	
	object me=this_object();
    if(!target||!ppl) return 0;
	if (!ppl->query_temp("peiyao/in_job"))
	{
			write("你的药是哪里来的？哼！\n");
			return 0;
		}
  
        if(target->query("id")!="ping yizhi")
		{
			write("你必须把药交给平大夫！\n");
			return 0;
		}
        else
        {
            int ereward,breward,hj;
            message_vision("$N笑呵呵接过你配好的药，说：谢谢这位"+RANK_D->query_respect(ppl)+"\n",
                        target);

 ereward=(1000+random(1000));
  hj=(1000+random(1000));
            breward=(300+random(100));
			//hj=(500);
            ppl->add("combat_exp",ereward);
			ppl->add("potential",hj);
            ppl->add("balance",hj);
            message("vision",HIY"你得到了"+chinese_number(ereward)+"点经验的奖励。\n"
			HIY"你得到了"+chinese_number(hj)+"点潜能的奖励。\n"
              "你得到了"+chinese_number(breward/100)+"两银子的奖励。\n"NOR,ppl);
            ppl->set_temp("peiyao/in_job",0);
            destruct(me);
            return 1;
                 
        }
        
}
