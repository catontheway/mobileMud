//added by labaz
// 狂欢发放NPC 加入端午狂欢 
#include <localtime.h>
#include <ansi.h>
inherit NPC;

string ask_me(string);
mixed ask_gift();
string ask_baibao();
string ask_baibao1();
string ask_baibao2();
string ask_baibao3();
void create()
{
	set_name("天神随从", ({ "tianshen suicong", "suicong" }));
	set("long", "他是天神的一名随从，被专门安排到此处负责玩家节日庆祝事宜。\n");
	set("gender", "男性");
	set("age", 200);
	//set_color("$HIR$");
	set("title", HIY"节日使者"NOR);

	set("inquiry", ([
	    "欢乐国庆" : (:ask_baibao1:),
		"装备补偿" : (:ask_baibao3:),
		"欢乐国庆2" : (:ask_baibao2:),
		"新人福利" : (:ask_gift:),
		"储物袋" : (:ask_baibao:),
		"狂欢":(: ask_me, "kuanghuan" : ),
		//"kuanghuan" : (: ask_me, "kuanghuan" : ),
		"开始" : (: ask_me, "start" : ),
		//"start" : (: ask_me, "start" : ),
	]));

	set("combat_exp", 400000000);
	set("shen_type", 0);
	set("attitude", "friendly");

	setup();
}

void init()
{
	::init();
}

nosave mapping holidays = ([
      "元旦":(["ask_startdate":"2020|12|30", "ask_enddate" : "2021|01|05", "duration" : 30]),
	"春节" : (["ask_startdate":"2021|01|26", "ask_enddate" : "2021|02|07", "duration" : 30]),
	"北侠生日" : (["ask_startdate":"2021|03|01", "ask_enddate" : "2021|03|07", "duration" : 30]),
	"端午" : (["ask_startdate":"2021|05|29", "ask_enddate" : "2021|05|31", "duration" : 30]),
	"女排夺冠" : (["ask_startdate":"2020|08|23", "ask_enddate" : "2020|08|24", "duration" : 30]),
	"国庆" : (["ask_startdate":"2021|09|27", "ask_enddate" : "2021|10|09", "duration" : 7]),
	"中秋":(["ask_startdate":"2021|09|15","ask_enddate":"2021|09|21","duration":30]),
	"双倍月":(["ask_startdate":"2020|12|25","ask_enddate":"2021|01|25","duration":30]),
]);

string ask_me(string arg)
{
	object who;
	mixed date_local, pre_start, pre_end, cur_start, cur_end;
	string *holidays_name, mounth, *date_start, *date_end, day, name, reason;
	int i, time, duration, start, end, local;

	who = this_player();
	time = time();
	date_local = localtime(time);
	local = date_local[LT_YEAR] * 10000 + (date_local[LT_MON] + 1) * 100 + date_local[LT_MDAY];

	holidays_name = keys(holidays);

	for (i = 0; i < sizeof(holidays_name); i++)
	{
		date_start = explode(holidays[holidays_name[i]]["ask_startdate"], "|");
		start = atoi(implode(date_start, ""));
		date_end = explode(holidays[holidays_name[i]]["ask_enddate"], "|");
		end = atoi(implode(date_end, ""));
		
		if (local >= start && local <= end)
		{
			name = holidays_name[i];
			//printf("%s\n",name);
			duration = holidays[holidays_name[i]]["duration"];
			reason = holidays[name]["reason"];
			if (!reason)
				reason = "狂欢";
			break;
		}
	}

	if (undefinedp(name))
	{
		if (who->query("kuanghuan/name"))
		{
			pre_start = localtime(who->query("kuanghuan/starttime"));
			pre_end = localtime(who->query("kuanghuan/endtime"));
			return "目前没有安排新的狂欢，你上次申请的" + who->query("kuanghuan/name") + "狂欢是从" + pre_start[LT_YEAR] + "年" + (pre_start[LT_MON] + 1) + "月" + pre_start[LT_MDAY] + "日" + pre_start[LT_HOUR] + "点" + pre_start[LT_MIN] + "分" + pre_start[LT_SEC] + "秒" +
				"开始，到" + pre_end[LT_YEAR] + "年" + (pre_end[LT_MON] + 1) + "月" + pre_end[LT_MDAY] + "日" + pre_end[LT_HOUR] + "点" + pre_end[LT_MIN] + "分" + pre_end[LT_SEC] + "秒" + "结束！\n";
		}
		else
		{
			return "目前没有安排新的狂欢，请关注news的通知。";
		}
	}
	switch (arg)
	{
	case "kuanghuan":
		return name + "已至，天神命我开放" + reason + "活动，在" + atoi(date_start[0]) + "年" + atoi(date_start[1]) + "月" + atoi(date_start[2]) + "日" + "到" + atoi(date_end[0]) + "年" + atoi(date_end[1]) + "月" + atoi(date_end[2]) + "日" + "期间可向我申请开始，持续时间为" + duration + "天!\n逾期申请概不受理，切记！\n";
		case "start":
		if (who->query("kuanghuan/year") < start)
		{
			who->set("kuanghuan/year", local);
			who->set("kuanghuan/name", name);
			who->set("kuanghuan/starttime", time);
			who->set("kuanghuan/endtime", time + duration * 24 * 3600);
			who->set("doublereward", who->query("kuanghuan/starttime")); //赋值到系统狂欢变量1
			who->set("double_reward", who->query("kuanghuan/endtime"));  //赋值到系统狂欢变量2
			cur_start = localtime(who->query("kuanghuan/starttime"));
			cur_end = localtime(who->query("kuanghuan/endtime"));
			return "你的" + name + reason + "活动申请成功，从" + cur_start[LT_YEAR] + "年" + (cur_start[LT_MON] + 1) + "月" + cur_start[LT_MDAY] + "日" + cur_start[LT_HOUR] + "点" + cur_start[LT_MIN] + "分" + cur_start[LT_SEC] + "秒" +
				"开始，到" + cur_end[LT_YEAR] + "年" + (cur_end[LT_MON] + 1) + "月" + cur_end[LT_MDAY] + "日" + cur_end[LT_HOUR] + "点" + cur_end[LT_MIN] + "分" + cur_end[LT_SEC] + "秒" + "结束！\n";
		}
		else
		{
			pre_start = localtime(who->query("kuanghuan/starttime"));
			pre_end = localtime(who->query("kuanghuan/endtime"));
			return name + reason + "活动你已经申请过了！从" + pre_start[LT_YEAR] + "年" + (pre_start[LT_MON] + 1) + "月" + pre_start[LT_MDAY] + "日" + pre_start[LT_HOUR] + "点" + pre_start[LT_MIN] + "分" + pre_start[LT_SEC] + "秒" +
				"开始，到" + pre_end[LT_YEAR] + "年" + (pre_end[LT_MON] + 1) + "月" + pre_end[LT_MDAY] + "日" + pre_end[LT_HOUR] + "点" + pre_end[LT_MIN] + "分" + pre_end[LT_SEC] + "秒" + "结束！\n";
		}
	}
}
string ask_baibao()
{
	object ob;
	mapping myfam;
	object nang;

	ob = this_player();
	myfam = (mapping)ob->query("family");
	
	if (ob->query("combat_exp") < 10000)
		return "虽然我这里有只储物袋，可是你战斗经验这么差，被人抢走了怎么办？\n";
/*
	if (ob->query("chuwudai"))
		return "你之前不是已经领过了吗？你还是赶紧联系管理员去处理一下吧。\n";
	*/
	if ( present("chuwu dai", ob))
		return "你已经有了一个储物袋，别贪得无厌！\n";

	nang=new("/clone/misc/baibao");
	nang->set("owner_id", ob->query("id"));
	nang->move(ob);
	ob->set("chuwudai", 1);
	write("你得到一个储物袋!\n");
	return "这可是个宝贝，好好利用它吧。";
}
string ask_baibao1()
{
	object ob;
	mapping myfam;
	object nang;

	ob = this_player();
	myfam = (mapping)ob->query("family");
	
	if (ob->query("gift/2021gq") )
		return "你领过了啊\n";
/*
	if (ob->query("chuwudai"))
		return "你之前不是已经领过了吗？你还是赶紧联系管理员去处理一下吧。\n";
	*/
	//if ( present("chuwu dai", ob))
		//return "你已经有了一个储物袋，别贪得无厌！\n";

	ob->add("int",1);
		ob->add("str",1);
			ob->add("dex",1);
				ob->add("con",1);
					//me-add("jhxk",1);
	ob->set("gift/2021gq", 1);
	write("你得到一个月饼!\n");
	return "你的四维各增加一点。";
}
string ask_baibao3()
{
	object ob;
	mapping myfam;
	object nang;

	ob = this_player();
	myfam = (mapping)ob->query("family");
	if (ob->query("combat_exp") < 500000)
	return "小号领什么补偿，一边玩去。";
	if (ob->query("gift/2021gqq") )
		return "你领过了啊\n";
/*
	if (ob->query("chuwudai"))
		return "你之前不是已经领过了吗？你还是赶紧联系管理员去处理一下吧。\n";
	*/
	//if ( present("chuwu dai", ob))
		//return "你已经有了一个储物袋，别贪得无厌！\n";

nang=new("/clone/vip2/1djfj");
	nang->move(ob);
	nang=new("/clone/vip2/1djfj");
	nang->move(ob);
	nang=new("/clone/vip2/1djfj");
	nang->move(ob);
	nang=new("/clone/vip2/1djfj");
	nang->move(ob);
	nang=new("/clone/vip2/3djwq");
	nang->move(ob);
	ob->set("gift/2021gqq", 1);
	//write("你得到一个月饼!\n");
	return "你领取了补偿。";
}
string ask_baibao2()
{
	object ob;
	int td;
	mapping myfam;
	object nang;
td = time() / 86400;
	ob = this_player();
	myfam = (mapping)ob->query("family");
	if (ob->query("combat_exp") < 200000)
	return "小号领什么积分，一边玩去。";
	if( ob->query("gifter/which_day") == td )
                return "你今天已经领过礼物了。";
		ob->add("jhxk",5);
ob->set("gifter/which_day", td);
	ob->set("gift/2021zq1", 1);
	write("你得到五点江湖侠客!\n");
	return "这可是个好东西。";
}
mixed ask_gift()
{
        object me = this_player();


        if( me->query("gifter/20081224") )
                return "你已经领过新手礼物了，不要太贪心。:)";

    //me->set("combat_exp", 3000);
    me->set("potential", 50000);
    me->set("pot/lxsz", 3500);
    me->set("max_neili", 200);
    me->set("max_jingli", 200);
    me->add("balance",50000);
	me->set_skill("dodge",30);
	me->add("per",5);
		me->set_skill("force",30);
		me->set_skill("parry",30);
		me->set_skill("strike",30);
		me->set_skill("cuff",30);
		me->set_skill("sword",30);
		me->set_skill("blade",30);
         message_vision("$N获得了一两黄金，5w点潜能作为闯入江湖的依靠。江湖险恶，再送一些基础技能，忘好自为之！！！\n",me);

        me->set("gifter/20081224", 1, me);

        tell_object(me, HIY "\n天空突现一道金光照耀着你，你冥冥中感觉到在侠客行的世界将万事有如神助！\n" NOR);

        return 1;
}
