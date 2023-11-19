//bianxingdan.c 变性丹

#include <ansi.h>

inherit ITEM;

int do_eat_2(string arg);

void create()
{
	set_name(HIR"顶级自选种类防具丹" NOR, ({ "fj dan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","自选种类防具丹。\n");
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
	string fj, id, family;
	
	object item;
	 int ayai;
	
	if (!arg||sscanf(arg,"%s %s", fj, id) != 2)
	{
		tell_object(me, ZJOBLONG + "你想要什么种类的防具："NOR+"\n"ZJOBACTS2+ZJMENUF(3,3,10,30)+
					CYN"手套"NOR":bianxing 手套 fj dan"ZJSEP+
					CYN"披风"NOR":bianxing 披风 fj dan"ZJSEP+
					CYN"头盔"NOR":bianxing 头盔 fj dan"ZJSEP+
					CYN"腰带"NOR":bianxing 腰带 fj dan"ZJSEP+
					CYN"肚带"NOR":bianxing 肚带 fj dan"ZJSEP+
					CYN"盾"NOR":bianxing 盾 fj dan"ZJSEP+
					CYN"护腕"NOR":bianxing 护腕 fj dan"ZJSEP+
					CYN"项链"NOR":bianxing 项链 fj dan"ZJSEP+
					CYN"靴"NOR":bianxing 靴 fj dan"ZJSEP+
					CYN"服装"NOR":bianxing 服装 fj dan\n");
		return 1;
	}

	if( !objectp(ob = present(id, me)) )
		return 0;	
	

	if (fj !="手套" && fj !="披风" && fj !="头盔" && fj !="腰带" && fj !="肚带" && fj !="盾"
	 && fj !="护腕" && fj !="项链"  && fj !="靴" && fj !="服装") {
		tell_object(me, "没有这种类别！\n");
		return 1;
	}
		
	
	
	tell_object(me, "你一仰脖，吞下了一颗" + name() +"。\n");

	//tell_object(me,"你获得一件"+fj+"！\n");
	ayai=300+random(179);
	if (fj == "手套") {
		item = new("/p/item/ritema/Ahands"+ayai);
                        item->move(me, 1);
						 tell_object(me, HIM "你获得了一" +  item->query("unit") +  item->name() +
                        HIM "。\n" NOR);
	}
	else if (fj == "披风") {
		item = new("/p/item/ritema/Aarmor"+ayai);
                        item->move(me, 1);
						 tell_object(me, HIM "你获得了一" +  item->query("unit") +  item->name() +
                        HIM "。\n" NOR);
	}
	else if (fj == "头盔") {
	item = new("/p/item/ritema/Ahead"+ayai);
                        item->move(me, 1);
						 tell_object(me, HIM "你获得了一" +  item->query("unit") +  item->name() +
                        HIM "。\n" NOR);
	}
	else if (fj == "腰带") {
		item = new("/p/item/ritema/Awaist"+ayai);
                        item->move(me, 1);
						 tell_object(me, HIM "你获得了一" +  item->query("unit") +  item->name() +
                        HIM "。\n" NOR);
	}
	else if (fj == "肚带") {
		item = new("/p/item/ritema/Asurcoat"+ayai);
                        item->move(me, 1);
						 tell_object(me, HIM "你获得了一" +  item->query("unit") +  item->name() +
                        HIM "。\n" NOR);
	}
	else if (fj == "盾") {
		item = new("/p/item/ritema/Ashield"+ayai);
                        item->move(me, 1);
						 tell_object(me, HIM "你获得了一" +  item->query("unit") +  item->name() +
                        HIM "。\n" NOR);
	}
	else if (fj == "护腕") {
		item = new("/p/item/ritema/Awrists"+ayai);
                        item->move(me, 1);
						 tell_object(me, HIM "你获得了一" +  item->query("unit") +  item->name() +
                        HIM "。\n" NOR);
	}
	else if (fj == "项链") {
		item = new("/p/item/ritema/Aneck"+ayai);
                        item->move(me, 1);
						 tell_object(me, HIM "你获得了一" +  item->query("unit") +  item->name() +
                        HIM "。\n" NOR);
	}
	else if (fj == "靴") {
		item = new("/p/item/ritema/Aboots"+ayai);
                        item->move(me, 1);
						 tell_object(me, HIM "你获得了一" +  item->query("unit") +  item->name() +
                        HIM "。\n" NOR);
	}
	else if (fj == "服装") {
	 item = new("/p/item/ritema/Acloth"+ayai);
                        item->move(me, 1);
						 tell_object(me, HIM "你获得了一" +  item->query("unit") +  item->name() +
                        HIM "。\n" NOR);
	}




	log_file("static/using", sprintf("%s(%s) eat 防具丹 at %s 时间：%s.\n",
				me->name(1), me->query("id"), fj, ctime(time())));
	destruct(this_object());

	return 1;
}

int do_effect(object me)
{
	do_eat_2("");
	return 1;
}

int query_autoload() { return 1; }
