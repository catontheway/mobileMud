
#include <ansi.h>

inherit COMBINED_ITEM;

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void setup()
{
	set_amount(1);
	::setup();
}

void create()
{
	set_name(HIR "无影丹" NOR, ({ "huohong xiandan", "dan", "xiandan" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一颗圆圆的极影丹，据说吃了能增加身法。\n");
		set("unit", "颗");
		set("base_unit", "颗");
		set("base_weight", 10);
		set("base_value", 10000);
		set("jhxk", 10);
            set("no_sell", 1);
		set("suit_point", 300);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	message_vision("$N一仰脖，吞下了一" + query("unit") + name() + "。\n", me);

	if (me->query("gift/unknowdan") >= 5)
	{
		message_vision("$N摇摇晃晃的，突然“啪嗒”一下子摔了个跟头。\n", me);
		tell_object(me, "你觉得吃完以后头重脚轻的。\n");
	}else
	{
		tell_object(me, HIM "霎时间你觉得腿骨欲裂，一时疼痛难忍。"NOR"\n");
		me->add("dex", 1);
	      me->add("gift/unknowdan", 1);
		write("\n "+HIR+"恭喜你："+NOR+HIG+"服用极影丹成功，《先天身法》增加了！！！"NOR"\n");
		// me->unconcious();
	}

	add_amount(-1);
      return 1;
}


