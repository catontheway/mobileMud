// story:laojun 西游

#include <ansi.h>

int give_gift();

protected mixed *story = ({
        "唐僧：怎么拿几本书这么慢？",
        "悟空：他... 他什么的，办事效率真差！",
        "八戒：呵呵，师傅，猴哥，你们怎么都是聪明一世，糊涂一时啊？人事，人事啊！",
        "沙僧：师傅，大师兄！我觉得二师兄说的有道理。",
        "唐僧：嗯... 悟空啊，我这里有一个紫金钵盂，还是唐王送的，你就...",
        "悟空：靠！我那金箍棒还是金的呢，更值钱，师傅你等着。",
        "啊～～～～～～～～～～～～～～",
        "唐僧：八戒，怎么回事？",
        "八戒：师傅你放心吧，那不是猴哥的叫声。",
        "悟空：师傅，阿摊阿叶那俩混蛋已经被我摆平了。",
        "“扑通”一声，唐僧晕倒了。",
        "悟空、八戒、沙僧：师傅！师傅！",
        "唐僧悠悠醒转：这事闹大了，咱们快去找佛祖解释解释吧。",
        "佛祖：呒，我都已经知道了，这不能怪两位使者，他们薪水低，捞点外快也是正常的。",
        "悟空：靠！还薪水低？我一搜就搜出了三两黄金！",
        "佛祖：三两黄金算什么，毛毛雨啦。当年尊者为人讲法，拿三斗三升碎金子，还嫌太少了呢。",
        "悟空：娘的，连尊者都是贪污犯，真不知道我们跑这么远取经干什么！",
        "悟空狠狠的把黄金扔了出去，道：他妈的，都见鬼去！",
        (: give_gift :),
        "唐僧：...",
        "观音：...",
        "众佛：...",
        "沙僧：...",
        "八戒：猴哥真是帅呆了。",
        "“嘭”的一声猪八戒被压到五指山下了。",
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

int give_gift()
{
        STORY_D->give_gift("/clone/money/gold", 50,
                           HIM "\n“啪”的一声一些黄金掉到你面前。\n\n" NOR);
        return 1;
}
