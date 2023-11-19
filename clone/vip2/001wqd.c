//bianxingdan.c 变性丹

#include <ansi.h>

inherit ITEM;

int do_eat_2(string arg);

void create()
{
	set_name(HIR"顶级自选武器丹" NOR, ({ "wq dan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","自选种类武器丹。\n");
		set("value", 10000);
		set("no_sell",1);
		set("jhxk", 20);
		set("only_do_effect", 1);
		set("unit", "颗");
	}
}

void init()
{
	add_action("do_eat_2","bianxing");
}

int do_eat_2(string arg)
{
	object ob,me=this_player();		
	string wq, id, family;
	
	object item;
	 int ayai;
	
	if (!arg||sscanf(arg,"%s %s", wq, id) != 2)
	{
		tell_object(me, ZJOBLONG + "你想要什么种类的防具："NOR+"\n"ZJOBACTS2+ZJMENUF(3,3,10,30)+
					CYN"剑"NOR":bianxing 剑 wq dan"ZJSEP+
					CYN"刀"NOR":bianxing 刀 wq dan"ZJSEP+
					CYN"锤"NOR":bianxing 锤 wq dan"ZJSEP+
					CYN"鞭"NOR":bianxing 鞭 wq dan"ZJSEP+
					CYN"棍"NOR":bianxing 棍 wq dan"ZJSEP+
					CYN"杖"NOR":bianxing 杖 wq dan"ZJSEP+
					CYN"暗器"NOR":bianxing 暗器 wq dan"ZJSEP+
					CYN"匕首"NOR":bianxing 匕首 wq dan"ZJSEP+
					CYN"斧"NOR":bianxing 斧 wq dan\n");
		return 1;
	}

	if( !objectp(ob = present(id, me)) )
		return 0;	
	

	if (wq !="剑" && wq !="刀" && wq !="锤" && wq !="鞭" && wq !="棍" && wq !="杖"
	 && wq !="暗器" && wq !="匕首"  && wq !="斧") {
		tell_object(me, "没有这种类别！\n");
		return 1;
	}
		
	
	
	tell_object(me, "你一仰脖，吞下了一颗" + name() +"。\n");

	//tell_object(me,"你获得一件"+wq+"！\n");
	ayai=300+random(179);
	if (wq == "剑") {
		item = new("/p/item/ritemw/Wsword"+ayai);
                        item->move(me, 1);
						 tell_object(me, HIM "你获得了一" +  item->query("unit") +  item->name() +
                        HIM "。\n" NOR);
	}
	else if (wq == "刀") {
		item = new("/p/item/ritemw/Wblade"+ayai);
                        item->move(me, 1);
						 tell_object(me, HIM "你获得了一" +  item->query("unit") +  item->name() +
                        HIM "。\n" NOR);
	}
	else if (wq == "锤") {
	item = new("/p/item/ritemw/Whammer"+ayai);
                        item->move(me, 1);
						 tell_object(me, HIM "你获得了一" +  item->query("unit") +  item->name() +
                        HIM "。\n" NOR);
	}
	else if (wq == "鞭") {
		item = new("/p/item/ritemw/Wwhip"+ayai);
                        item->move(me, 1);
						 tell_object(me, HIM "你获得了一" +  item->query("unit") +  item->name() +
                        HIM "。\n" NOR);
	}
	else if (wq == "棍") {
		item = new("/p/item/ritemw/Wclub"+ayai);
                        item->move(me, 1);
						 tell_object(me, HIM "你获得了一" +  item->query("unit") +  item->name() +
                        HIM "。\n" NOR);
	}
	else if (wq == "杖") {
		item = new("/p/item/ritemw/Wstaff"+ayai);
                        item->move(me, 1);
						 tell_object(me, HIM "你获得了一" +  item->query("unit") +  item->name() +
                        HIM "。\n" NOR);
	}
	else if (wq == "暗器") {
		item = new("/p/item/ritemw/Wthrowing"+ayai);
                        item->move(me, 1);
						 tell_object(me, HIM "你获得了一" +  item->query("unit") +  item->name() +
                        HIM "。\n" NOR);
	}
	else if (wq == "匕首") {
		item = new("/p/item/ritemw/Wdagger"+ayai);
                        item->move(me, 1);
						 tell_object(me, HIM "你获得了一" +  item->query("unit") +  item->name() +
                        HIM "。\n" NOR);
	}
	else if (wq == "斧") {
		item = new("/p/item/ritemw/Waxe"+ayai);
                        item->move(me, 1);
						 tell_object(me, HIM "你获得了一" +  item->query("unit") +  item->name() +
                        HIM "。\n" NOR);
	}
	




	log_file("static/using", sprintf("%s(%s) eat 武器丹 at %s 时间：%s.\n",
				me->name(1), me->query("id"), wq, ctime(time())));
	destruct(this_object());

	return 1;
}

int do_effect(object me)
{
	do_eat_2("");
	return 1;
}

int query_autoload() { return 1; }
