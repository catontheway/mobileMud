// story:tbh

#include <ansi.h>

string give_gift();

protected mixed *story = ({
        "冰冰哈哈大笑说道，哈哈~~~~我告诉你，",
        "你刚才喝的那杯参茶，已经被我下了天下第一奇毒－－一！日！丧！命！散！",
        "无欢冲冰冰哈哈大笑道，哈哈~~~~天下第一奇毒，哪轮得到你那一日丧命散？！",
        "应该是我们家的含！笑！半！步！颠才对！",
        "冰冰笑道，哈哈~~~~废话！我们一日丧命散是用七种不同的毒虫，再加上鹤顶红，",
        "提炼七七四十九日而成的，无色无味，行凶于无影无踪。",
        "无欢笑道：我们“含笑半步颠”是用蜂蜜，川贝，桔梗，加上天山雪莲配制而成，",
        "不须冷藏，也没有防腐剂，除了毒性猛烈之外，味道还很好吃。", 
        "冰冰说道，吃了我们“一日丧命散”的人，一日之内会武功全失，筋脉逆流，",
        "胡思乱想，而致走火入魔，最后会血管爆裂而死。",
        "无欢对冰冰点点头说道，没有错！而吃了“含笑半步颠”的朋友，顾名思义，"
        ,"绝不能走半步路，或者面露笑容，否则也会全身爆炸而死。",
        "实在是居家旅行－－行凶灭口～～必备良药～",
        "李逍遥说道，那么，哪里才能买的到呢？",
        "无欢对李逍遥点头道，啊！这位大虾运气真好，我这里正好有一粒。",
        "冰冰一把抢过药丸，哼道：这颗烂药真有这么厉害吗？！ ",
        "无欢说道：失礼啦，普天之下这颗最厉害！",
        "冰冰哼道：当老娘我不敢嗑？！",
        "（将药丸放在嘴边，停住）",
        "嘿嘿，你当我白痴，老糊涂了？！嗑你个头？！",
        "冰冰将药丸随手扔出了窗外。",
        (: give_gift :)
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

string give_gift()
{
        STORY_D->give_gift("/clone/story/obj/intdan", 1,
                           HIM "\n“啪”的一声一枚药丸掉到你面前。\n\n" NOR);
        return HIM "听说冰冰扔掉了一枚仙丹。\n" NOR;
}

