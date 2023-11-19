inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIW"八卦盘"NOR, ({"ba gua"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("dianquan",1);
		set("no_shop", 1);
	 	set("u_times",5);
		set("unit", "个");
		set("long","这是一个八卦盘，能够"ZJURL("cmds:use ba gua")ZJSIZE(20)"占卜"NOR"当前师门任务npc的精确位置！可以使用5次。\n");
	}
}

void init()
{
    if (environment()==this_player())
    	add_action("on_used","use");
}

int on_used(string arg)
{
	object ob;
	object me=this_player();
	mapping q;
	string area;

	if (arg!="ba gua")
      		return notify_fail("你要用什么?\n");  

	if(!mapp(q=me->query("quest")))
	{
      		return notify_fail("你现在没有任务，使用八卦盘占卜什么?\n");  
	}
	if(q["type"]!="kill")
	{
      		return notify_fail("你现在没有师门行凶任务，无需占卜。\n");  
	}
	if(ob=find_living(q["id"]))
	{
		sscanf(base_name(environment(ob)),"/d/%s/%*s",area);
                message_vision(HIW"$N从怀里掏出一个"+name()+""HIW"，往上撒了几个铜钱，嘴里念念有词，开始掐指细算。"NOR"\n" , me);
		tell_object(me,HIR+q["name"]+NOR"（"+q["id"]+"）目前正在"HIW+MAP_D->query_map_short(area)+NOR"的"HIW+environment(ob)->query("short")+NOR"活动。\n");

		add("u_times",-1);
		if(query("u_times")>0) tell_object(me,"这个八卦盘还可以使用"+query("u_times")+"次。\n");
	}
	else
		tell_object(me,"无法占卜到目标人物，可能是目标人物已被就地正法或者消失了。\n");

	if(query("u_times")<=0){
	tell_object(me,"你的奇门八卦盘因为使用次数过多而破损了。\n");
		destruct(this_object());
}

	return 1;
}
