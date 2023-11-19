#include <ansi.h>

inherit ITEM;
string *typew=({
"sword",
"blade",
"hammer",
"whip",
"club",
"staff",
"throwing",
"dagger",
"axe",
});
string *typea=({
"hands",
"cloth",
"armor",
"boots",
"head",
"neck",
"surcoat",
"waist",
"wrists",
});
void create()
{
        set_name(HIG "随机高级防具" NOR, ({ "wis dan" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","为萌新而准备。\n"ZJURL("cmds:use wis dan")ZJSIZE(15)"使用"NOR"看看!\n");
                set("jhxk", 10);
                set("value", 1000);
                set("unit", "粒");
                set("only_do_effect", 1);
        }
}

int do_effect(object me)
{
        object item;
        int ayai;
ayai=200+random(100);

        message_vision("$N一仰脖，吞下了一粒" + this_object()->name() +
                       "。\n", me);

                        item = new("/p/item/ritema/A"+typea[random(9)]+ayai);
                        item->move(me, 1);
                      

        destruct(this_object());
        return 1;
}