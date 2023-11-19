// maze.c 矩阵迷宫
// seagate@pkuxkx by 2011.02.16

// maze.c 随机迷宫（伤精神陷阱）
// seagate@pkuxkx by 2011.02.17

#include <ansi.h>
inherit ROOM;
#include "nature.h"
inherit F_VIRTUAL;

void create()
{
  set("outdoors", "shaolin/cjg");
  set("cjgmaze", "level2");
  set("no_die",1);
	setup();
}

int do_lian()
{
	tell_object(this_player(), "这里太危险了，还是不要修炼武功了。\n");
	return 1;
}

void init()
{
	object *inv, me, ob;
	int complex, lp;
	mapping fam;
	
	me=this_player();
	
  if ( !userp(me) )
  	return;

	add_action("do_lian","lian");
	add_action("do_lian","practice");
	add_action("do_lian","xiulian");
	if ( time()-me->query_temp("cjg/time")>=1800 )
	{
		tell_object(me, "你在竹林中滞留了太长时间了，被路过的巡逻僧兵发现了踪迹。\n");
    me->set("startroom", "/d/shaolin/jlyuan");
    me->move("/d/shaolin/jlyuan"); 
    return;
	}
  
  if ( !random(4+c_is_day()*2) )
  {
    message_vision(CYN"$N掉进了护寺僧人设下的陷阱。\n"NOR, me);
    me->start_busy(3);
    me->receive_damage("jing", 1000, "掉进陷阱");
    me->receive_wound("jing", 300, "掉进陷阱");
  }
  
  inv=all_inventory();
	for(lp=0;lp<sizeof(inv);lp++)
	{
	  if (inv[lp]->is_character() &&
	  	  living(inv[lp]) &&
	  	  ( inv[lp]->query("id")=="husi sengren" ||
	  	    inv[lp]->query("id")=="husi zhanglao" ) &&
	  	  inv[lp]->query("uni_target")==me &&
	  	  inv[lp]->is_fighting() )
	    return;
  }
  
  if ( ( c_is_day() &&
  	     !random(4) ) || 
    	 !me->query_temp("cjg/fights") )
  {
  	tell_object(this_object(), "突然远处一队巡逻僧兵走了过来，已经来不及躲避了，只能尽快杀掉他们。\n");
  	ob=new(__DIR__"npc/huseng");
  	ob->move(this_object());
  	ob->alert_seng(me);
  	destruct(ob);
  	me->add_temp("cjg/fights",1);
  }
}

//没有组队的直接送出副本
//必须领队走出迷宫其他人才可以走
//每走一步都需要检查房间内是否还有你们队伍相关的护寺僧人没有杀干净
int valid_leave(object me, string dir)
{
  object *inv, ob;
  int lp;
  
  inv=all_inventory(this_object());
  for(lp=0; lp<sizeof(inv); lp++)
  {
  	if ( (inv[lp]->query("id")=="husi sengren"||
  		    inv[lp]->query("id")=="husi zhanglao") &&
  		   inv[lp]->query("uni_target")==me )
  	{
  		write("你必须解决了房间内的敌人以后才能离开。\n");
  		return 0;
  	}
  }
  
  if ( dir=="out" && 
  	   query("exits/out") &&
  	   query("maze/room")=="0_0" )
  	return notify_fail("进入藏经阁副本以后就不能回头了。\n");
  
  return ::valid_leave(me, dir);
}

void clean_corpse()
{
	object *inv=all_inventory(this_object());
	int fighting=0,lp;
	
	for ( lp=0;lp<sizeof(inv);lp++ )
	{
	  if ( objectp(inv[lp]) &&
		     !userp(inv[lp]) && 
		     inv[lp]->is_corpse() )
    {
	    destruct(inv[lp]);	
	  }
	  
	  if ( userp(inv[lp]) &&
	  	   inv[lp]->is_fighting() )
	    fighting=1;
	}
	
	if ( fighting )
		call_out("clean_corpse",10);
}