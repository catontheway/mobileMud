// Zine dec 7 2010 ,铜雀台
#include <ansi.h>
inherit ITEM;

void init()
{
	add_action("do_yanjiu", "yue");
	add_action("do_yanjiu", "du");
	add_action("do_yanjiu", "fan");
	add_action("do_yanjiu", "yanjiu");
}

void create()
{
	set_name(HIG"大智无定指谱"NOR, ({ "dazhi zhipu","zhipu","book"}));
	set_weight(500);
    set("value",1);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一本大智无定指的指谱，少林失传武学，你可以研究(yanjiu)一下。\n");
			set("unit", "本");
		}
}

int do_yanjiu()
{
   
    object me=this_player();
    if (this_object()->query("owner")!=me->query("id"))
    {
        tell_object(me,"你翻了翻这本武功秘籍，却觉得过于晦涩难懂。\n");
        return 1;
    }
    if (me->query("tqt_sl_skill1"))
    {
        tell_object(me,"你不是已经掌握了『大智无定指』吗？\n");
        return 1;
    }
    if ((int)me->query_skill("yizhi-chan")<100)
    {
        tell_object(me,"你的一指禅功夫太浅，大智无定指对于你过于艰难了。\n");
        return 1;
    }
    
    message_vision("$N开始认真研读$n，掌握了『大智无定指』的运功方法！\n"NOR, me,this_object());
    me->set("tqt_sl_skill1",1);
    message_vision("$N很诡异地无风自燃起来了。\n",this_object());
    destruct(this_object());
    return 1;		
}