#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(GRN"兑奖凭证"NOR, ({"duijiang pingzheng", "note"}));
        set("unit", "张");
        set("long", "这是兑换福利用的凭证，可以到杂物库房提取你想要的物品。\n");
        set("type", "item");
        setup();
}
