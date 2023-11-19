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
	set_name(HIG"潜能运气丹"NOR, ({"putao"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("jhxk", 1);
            set("no_sell",1);
		set("unit", "粒");
		set("base_unit", "粒");
		set("base_weight", 10);
		set("base_value", 100);
		set("long","这是一个由幕后黑手炼制的"HIG"潜能运气丹"NOR"，吃下它会发生奇怪的事情！还有千分之一的概率增加容貌(潜能随机+100-50000)\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
      if (me->is_busy())
                return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		    return notify_fail("正在战斗中，不能使用"+ name() +"。\n");

	me->add("potential",100+random(49900));
	write(YEL"你吃下一粒"HIG"潜能运气丹"YEL"发现自己的潜能大增!"NOR"\n");

        if (random(1000)==1) {
            me->add("per",1);
            message_vision(HIW"只见$N身上发出一道耀眼的白光，似乎发生了什么神奇的事情。"NOR"\n", me);
            write(HIM"恭喜：你的先天容貌提升了!"NOR"\n");
            }
	add_amount(-1);
	return 1;
}