// shadan-san.c 田七鲨胆散

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
       set_name("田七鲨胆散",({"shadan san","san"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
       set("unit","包");
       set("long","这是一包桃花岛的田七鲨胆散，此物可以提高功力。\n");
		set("value", 10000);
		set("no_drop", "这样东西不能离开你。\n");
	}

       set("taohuadao",1);
	setup();
}

int do_eat(string arg)
{
	object me = this_player();

    if (me->query("family/family_name") != "桃花岛")
        return notify_fail("你不是桃花岛弟子，吃了桃花岛的药不怕中毒吗？\n");

	if (!id(arg))
	return notify_fail("你要吃什么？\n");
	else
	{
		me->add("max_neili", 1);
      message_vision(HIG"$N吃下一包田七鲨胆散，顿觉体内真气源源滋生，感觉觉你的内力增加了。\n"NOR,me);
	}
     if((int)me->query_condition("taoism_drug") < 100)
        {

       me->apply_condition("taoism_drug", 100);
	
      }
        destruct(this_object());
        return 1;
}

