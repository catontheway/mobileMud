// Room: /city/qianzhuang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short","月记银号");
	set("long", @LONG
这是一家老字号的钱庄，已有几百年的历史，在全国各地都有分店。它发行
的银票信誉非常好，通行全国。在对面的墙上挂了块牌子(paizi)。
LONG);
 
	set("item_desc", ([
		"【牌子】" : "本钱庄提供以下服务：钱币兑换    convert或者duihuan\n"
		ZJOBACTS2+ZJMENUF(3,3,8,30)"存钱:cun"ZJSEP"取钱:qu"ZJSEP"查账:check\n",
	]) );

        set("no_fight", 1);
	set("exits", ([
		"south" : __DIR__"eaststreet1",
	]));

	set("objects", ([
		"/d/yueyang/npc/zhanggui":1,
	]));
	setup();
	replace_program(ROOM);
}
