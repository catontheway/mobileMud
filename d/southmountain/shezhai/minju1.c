// 东天目山，一座随机生成的区域。玩家副本 Zine 2014/7/14
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "钱庄"+NOR);
	set("long", @LONG
这里是一座典型的畲族民房，一色的粉墙黛瓦，清秀隽永。因为来畲寨的人
越来越多，现在被改建为钱庄了。在墙上挂了块牌子(paizi)。
LONG);
 
 	set("item_desc", ([
		"【牌子】" : "本钱庄提供以下服务：钱币兑换    convert或者duihuan\n"
		ZJOBACTS2+ZJMENUF(3,3,8,30)"存钱:cun"ZJSEP"取钱:qu"ZJSEP"查账:check\n",
	]) );
        set("outdoors", "xitianmu");

	set("exits", ([
		//"southwest" : __DIR__"westgc",
		//"east" : __DIR__"xiaolu1",
		"west" : __DIR__"xiaolu1",
		//"north" : __DIR__"minju4",
	]));

	set("objects", ([
		"/d/yueyang/npc/zhanggui":1,
		//__DIR__"npc/songbing_y" : 2,
        ]));
	setup();
}
