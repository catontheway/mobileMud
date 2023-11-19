// 大石谷，一座随机生成的区域。玩家副本 Zine 2014/7/14
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "鹰嘴石"+NOR);
	set("long", @LONG
这里有一块巨石，因为形似鹰嘴而得名。
LONG
	);
        set("outdoors", "dashigu");

	set("exits", ([
		"southeast" : __DIR__"jingke",
		//"northdown" : __DIR__"jingshui",
		//"northwest" : __DIR__"taohua",
		//"eastdown" : __DIR__"xiaoxic",
	]));
	set("stay_time",1);
	set("valid_startroom", 1);
	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		//__DIR__"npc/songbing_y" : 2,
        ]));
	setup();
}
void init()
{
	object me=this_player();
	me->set_temp("xitianmu/xiaoxi_stay",time());
	if (me->query("tianmuQuests/dashigu/gather"))
	{
		me->set("startroom", base_name(this_object()));
		me->set_temp("revive_room",base_name(this_object()));
	}
}
int valid_leave(object me,string dir)
{
	if (member_array(dir,keys(query("exits")))!=-1&&
	time()-me->query_temp("xitianmu/xiaoxi_stay")<query("stay_time"))
	return notify_fail("你观赏着"+query("short")+NOR+"风光，一步一步慢慢前行。\n");
	return ::valid_leave(me,dir);
}