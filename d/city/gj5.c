// Room: /d/shaolin/cjlou1.c
// Date: YZC 96/01/19
// modify by chui

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "经验潜能房");
        set("long", @LONG
挂机房一号每次一分钟，你可以用gj来设置指令
LONG
        );

        set("exits", ([
                  "south" : __DIR__"bookstore",
        //"west" : __DIR__"bookstore",
        "north" : __DIR__"gj4",
        ]));

       // set("bo",1);
       /* set("objects",([
                "d/shaolin/obj/wuji1" : 1,
                "d/shaolin/obj/wuji2" : 1,
                "d/shaolin/obj/wuji3" : 1,
        ]));*/
        /*set("item_desc",([
                "shelf" : "架子上堆满了少林的经书武籍。\n",
        ]));*/
       // create_door("north", "壁门", "south", DOOR_CLOSED);
        set("no_perform",1);
        set("no_exert",1);
        set("no_fight",1);
set("action_list", ([
		//"移动书架 " : "push shelf",	
                "挂机 " : "gj",
      
        	
       ]));
        setup();
}

void init()
{
	
        add_action("do_linwu", "gj");
        
}


int do_linwu(string arg)
{
        object me;
        me=this_player();   
        
        if(arg) return 1;
        if(me->query("combat_exp")<10000) 
        {
          write(HIY"你现在经验太低无法冥想挂机!\n"NOR);
          return 1;
        }
        
        if(me->is_busy()||me->is_fighting())
        {
          write(HIY"你现在无法静下心挂机!\n"NOR);
          return 1;
        }
        
        if((int)me->query("max_neili")>(int)me->query("neili"))
        {
          write(HIY"你现在内息紊乱，无法静下心挂机!\n"NOR);
          return 1;
        }
        
        if(me->query("jingli")<100)
        {
          write(HIY"很明显,你现在太累了,无法冥想增加经验!\n"NOR);
          return 1;
        }
        
        me->start_busy(60);
        call_out("lingwu_loop",3, me,100);
        return 1;
}

void lingwu_loop(object me, int times)
{
        int mykar;
        if ( !objectp(me) )
        	return;
        //mykar = me->query("kar")+me->query_temp("wuming")/60;      //重新调整了算法，zine修正bug以后领悟命中率降低太多了。 by seagate
        
        if( me->query("xkxvip/times") > 0 )
        {
         // write(HIY"你领悟了挂机的意境，觉得颇有所获!\n"NOR);
          if((random(100))>99)
          {
            me->add("potential",100);
			me->add("combat_exp",100);
            write(HIY"人品爆发，百分之一的概率获得100点经验和潜能.\n"NOR);
           // write(HIY"你感觉这种事情已经发生"+me->query("wuming")+"次了。\n"NOR);
          }
          
        //  me->add("jingli",-100);
          me->add("potential",random(3)+1);
          me->add("combat_exp",random(3)+1);  
        }
        else if( me->query("xkxvip/times") == 0 )
        {
         // write(HIG"请注意！！！这是侠客行月卡用户的挂机场所!你在这里只能每小时获得月卡用户一半或者更少的经验潜能\n"NOR);
         
            me->add("potential",1);
            me->add("combat_exp",1);
          
        }
        
     //   me->add_temp("wuming",1);
        
        if ( !times )
	 {
	 if( me->query("xkxvip/times") == 0 )
	 return notify_fail(HIG"请注意！！！这是侠客行月卡用户的挂机场所!你在这里只能每小时获得月卡用户一半或者更少的潜能\n"NOR);
        	write(HIY"你停止感悟，觉得颇有所获!\n"NOR);
        	me->start_busy(0);
        }
        else
          call_out("lingwu_loop",3, me,times-1);
}

