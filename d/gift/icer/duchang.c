//duchang.c     预测场
// By icer

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "国庆彩票发售现场");
        set("long", @LONG
这里是庆祝国庆卖彩券的地方，人很多，人人都期望能买到幸运号码好
中奖，几位卖彩券的小姐也是忙得不亦乐乎。旁边墙上贴着一篇说明(sign)，
上面写着彩券的兑奖办法。
LONG
        );
    set("item_desc", ([
        "sign" : "彩券分三种：精力彩券、内力彩券、容貌彩券。
其中精力彩券价格为30点最大精力，内力彩券价格为30点最大内力，容貌彩券价格为5点容貌。
彩券是自动保存(autoload)的，就是说quit重进也不会丢。10月7号左右会开奖，每类彩券
开出特等奖一名、一等奖五名，二等奖十名，三等奖二十名。
特等奖奖励为1000点最大精力或内力或100点容貌（依彩票类型而定）。
一等奖奖励为500点最大精力或内力或50点容貌（依彩票类型而定）。
二等奖奖励为300点最大精力或内力或30点容貌（依彩票类型而定）。
三等奖奖励为100点最大精力或内力或10点容貌（依彩票类型而定）。
找这里的彩票小姐打buy jingli，buy neili，buy rongmao可以购买相应的彩票。
请保管好自己的彩票，遗失不补。\n\n",
        ]));

        set("exits", ([
                "northwest" : "/d/city/guangchang",
        ]));

        set("objects",([
                            "/u/icer/girl2" : 1,
//                            __DIR__"npc/huangniu" :1,

        ]));

        setup();
}

