/*
兵器强化系统，思路来自于塞班年代的手机网游，代码本身简单，需要一定的逻辑性。
*/

#include <ansi.h>
inherit ITEM;

int query_autoload() { return 1; }
void create()
{
        set_name(HIM "装备强化石" NOR, ({ "bqh shi", "qhs" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIM "装备强化石可以将自造装备进行强化升级。\n" NOR);
                set("unit", "张");
            set("value",500000);
        }
        setup();
}

void init()
{
        add_action("do_integrate", "qianghua");
}

int do_integrate(string arg)
{
        object me;
        object ob;
        string ownerid,namejia;
        int jiapoint,cgl,cgll;

        if (! arg)
                return notify_fail("你要往什么道具上使用兵器强化石？\n");

        me = this_player();
        if (! objectp(ob = present(arg, me)) &&
            ! objectp(ob = present(arg, environment(me))))
                return notify_fail("你身上和附近没有这样道具啊。\n");

        if (!ob->is_weapon() && !ob->is_unarmed_weapon())
                return notify_fail("你只能在兵器上使用兵器强化石。\n");

        ownerid = ob->item_owner();
jiapoint = ob->query("point")/10;
cgl = ob->query("qianghuadengji");
cgll = cgl/4;
if (cgl>=20)
{
tell_object(me, HIC "你的" + ob->name() + HIC"已经满级了！\n" NOR);
return 1;
}
if (random(cgl) == 0||getuid(me)=="shulele")
{
        ob->add("qianghuadengji", 1);
        if (!ob->query("yuanmc"))//如果第一次强化，导入参数原名称。
        {
        ob->set("yuanmc",ob->query("name"));
        }
        else
        {
         switch (cgll){
    case 1:ob->set("name",HIG+ob->query("yuanmc") +NOR+ "+" + ob->query("qianghuadengji"));break;//绿色
    case 2:ob->set("name",HIC+ob->query("yuanmc") +NOR+ "+" + ob->query("qianghuadengji"));break;//蓝色
    case 3:ob->set("name",HIR+ob->query("yuanmc")+NOR + "+" + ob->query("qianghuadengji"));break;//红色
    case 4:ob->set("name",HIY+ob->query("yuanmc")+NOR + "+" + ob->query("qianghuadengji"));break;//黄色
    case 5:ob->set("name",HIM+ob->query("yuanmc")+NOR + "+" + ob->query("qianghuadengji"));break;//紫色
    default:ob->query("name",ob->query("name")+ "+" + ob->query("qianghuadengji"));//如果强化出错，无变化，这里预防bug。
    }
   //     namejia = ob->query("yuanmc") + "+" + ob->query("qianghuadengji");
        }
   ob->add("weapon_prop/max_qi",1000);
    me->set("can_summon/" + ob->query("id"), base_name(ob));
        ob->save();
        if (ob->query("qianghuadengji")==20)
        {
        message("channel:chat",HBRED"系统通告"HIR"："+me->query("name")+"成功把"+ob->name()+"强化到了满级，一把神兵利器出世了.\n"NOR,users());
        }
        tell_object(me, "你把" + name() + "盖在" + ob->name() + "上，然后口中念念有词，\n"
                        "只见兵器强化石融入了" + ob->name() + "体内！\n");
        tell_object(me, HIC "强化成功！你感受到" + ob->name() + HIC"变的更坚硬锋利了。\n" NOR);
        }
        else
        {tell_object(me, HIC "强化失败！你的" + ob->name() + HIC"啥变化都没有！\n" NOR);
        }
        

        destruct(this_object());
        return 1;
}