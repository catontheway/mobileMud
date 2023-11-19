// Room: /city/wumiao.c
// YZC 1995/12/04 
// Modified by iszt@pkuxkx, 2007-04-03

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "武庙");
	set("long", @LONG
这里是岳王庙的正殿，内有岳飞像，像上方悬挂岳飞手书「还我河山」的横
匾。殿两侧壁上嵌着「尽忠报国」四个大字。武人到此，都放下武器，毕恭毕敬
地上香礼拜。柱子上贴着张告示，上书『杀气过高者忏悔(chanhui)，欲结善缘者
捐献(juanxian)』。
LONG);
	set("no_fight", 1);
	set("no_perform", 1);
	set("no_steal", 1);
	set("no_sleep_room", 1);

	set("objects", ([
		__DIR__"obj/box" : 1,
	]));

	set("exits", ([
		"east" : __DIR__"beidajie2",
		"up" : __DIR__"mingren",
		"northwest": "/d/wizard/guest_room",
	]));
	setup();
	"/clone/board/wm_b"->foo();
}

void init()
{
	string *sname;
	int *svalue;
	mapping skill_status;	//灵鹫宫返老还童用
	int i, level; 
	float exper;
	object user = this_player();	

	add_action("do_chanhui","chanhui");
	add_action("do_juanxian","juanxian");
	add_action("do_none","exert");

	exper = to_float(user->query("combat_exp"));

	if (wizardp(user)) return;

	if ( skill_status = user->query_skills() )
	{
		sname  = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) 
		{
			level = skill_status[sname[i]];
			if( pow(to_float(level-2), 3.0) / 10.0 > exper 
				&& exper > 100.0
				&& SKILL_D(sname[i])->type() != "knowledge") 
			{
				level = ceil( pow( exper*10.0, 0.333333) );
				user->set_skill(sname[i], level+1);
				write(HIR+BNK+"你的" + sname[i] + "等级超出经验支持的能力范围，已经恢复到" + (level+1) + "级。\n"+NOR);
			}
		}
	}
	if(user->query("max_qi") < 0 || user->query("max_jing") < 0)
	{
		user->set("tooold", 1);
		user->set("max_qi", 10);
		user->set("eff_qi", 10);
		user->set("qi", 10);
		user->move(__DIR__"mingren");
		user->set("startroom", __DIR__"mingren");
	}
}

int do_none()
{
	write("对不起，武庙你只能老实呆着。\n");
	return 1;
}

int do_juanxian(string arg)
{
	object me = this_player();
	int amount,denote_amount;
	object money,board;

	if (!arg)
		return notify_fail("你要捐献多少张壹千两的银票？？\n");

	sscanf(arg,"%d",amount);
	if (amount < 1)
		return notify_fail("你要捐献还是要抢钱啊？\n");
	if (me->query("kar") > 39)
		return notify_fail("方丈说道：阿弥陀佛，这位施主福星高照，再捐就福贯满盈了。\n");
	money = present("thousand-cash",me);
	if (!money)
		return notify_fail("你没带壹千两银票来。\n");
	if ((int)money->query_amount() < amount)
		return notify_fail("你没带那么些银票。\n");
		if (amount < 50)
				return notify_fail("方丈说道：施主好意心领了，但本寺最低捐献金额为五十张壹千两的银票。\n");
	if (amount > 120)
		return notify_fail("方丈大惊失色：施主出手豪阔，本寺福薄，一次最多接受捐献价值一千二百两黄金的银票。\n");
	board = present("board", environment(me));
	message_vision("$N从身上掏出" + chinese_number(amount) + "张壹千两的银票，双手奉上方丈。\n
			方丈命人收了银票，并在善缘簿上记下了$N的名字。\n",me);
	board->do_record(me->query("name") + "(" + me->query("id") + ")捐献千两银票" + chinese_number(amount) + "张。");
	if (me->query("denote_amount") && !me->query("denote"))
		me->set(("denote_amount"),(int)me->query("denote_amount")%1000);
	denote_amount = (int)(me->query("denote_amount") + amount*10)/((me->query("denote")+1)*1000);
	if (denote_amount >= 1)
	{
		denote_amount = (int)(me->query("denote_amount") + amount*10)%((me->query("denote")+1)*1000);
		me->add("kar",1);
		me->add("denote",1);
		me->add("xiantian/kar/juanxian",1);
		tell_object(me,HIG"冥冥中你觉得自己的福缘有所增加！\n"NOR);
	}
	else denote_amount = (int)(me->query("denote_amount") + amount*10)%((me->query("denote")+1)*1000);
	me->set("denote_amount",denote_amount);
	if (me->query("denote") > 4)
		me->set("job_title",HIW"善人"NOR);
	if (me->query("denote") > 9)
		me->set("job_title",HIG"乐善好施"NOR);
	money->add_amount(0-amount);
	return 1;
}
int do_chanhui()
{
	object me = this_player();
	if ( me->is_busy() )
		return notify_fail("你现在正忙着！\n");

	if ( me->query("shaqi") <= 0 )
		return notify_fail("你心中已没有丝毫杀气，如果真的一心向善，不如皈依我佛。\n");

	if ( me->query("jing") > 50 )   
	{
		message_vision("$N双膝跪地，两眼紧闭，口中念念有词，脸上充满悔恨之意。\n", me);
		me->start_busy(100);
		me->add("shaqi", -30);
		me->add("jing", -50);
		call_out("end_chanhui",50, me);
	}
	else return notify_fail("你的精不够！\n");

	return 1;
}	   

void end_chanhui( object me )
{
	if(!me) return;
	if ( me->query("shaqi") < 0 )
	{
		me->set("attitude","peaceful");
		tell_object( me, "你心中一片平和，已经没有丝毫杀气。\n");
		me->delete("attitude");
		me->set("shaqi" ,0 );
	}
	else {
		tell_object( me, "你感觉心中的杀气渐渐消失......\n");
	}
	me->start_busy(1);
	return;
}
