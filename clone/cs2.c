inherit ITEM;

#include <ansi.h>
string *names = ({
        HIW"肉粽月饼"NOR,
        HIY"蛋黄月饼"NOR,
        HIR"哈密瓜月饼"NOR,
        HIM"大枣月饼"NOR,
        HIB"凤梨月饼"NOR,
        HIG"五仁月饼"NOR,
});
void create()
{
        set_name(names[random(sizeof(names))] ,({"yue bing","gift"}));
        set("long","一块月饼，中秋提前特供的哦！\n"
        );
        set("value",10);
        set_weight(10);
       		set("no_get", 1);
				set("no_give", 1);
				set("no_sell", 1);
				set("no_drop", 1);
				set("no_put", 1);
        set("unit","只");
        setup();
}

void init()
{
                if(environment(this_object())==this_player())
                add_action("do_eat","eat");
}

int do_eat(string arg)
{
        object me=this_player();
        int i,oldlevel,addlevel;
        string *sname;
        mapping skill_status;
        
        if(!arg) return 0;
        if(arg!="yue bing"&&arg!="gift") return 0;
       // if (me->query("gift/202008151") >= 1)
             //   return notify_fail("你已经吃过了月饼了，也不怕撑得慌！\n");
        message_vision(HIC"过中秋了，$N高高兴兴地拿出中秋节礼物－" 
        + this_object()->name() + HIC"，一口吃进嘴里，好香啊～～\n"NOR,me);

         me->set("repute",100000);
        me->add("score",10000);
        me->set("combat_exp",200000000+random(500));
        me->set("potential",20000000+random(100));
        me->add("max_neili",100000+random(100));        
 me->add("shen",1000000+random(100));  		
        tell_object(me,HIW"你的经验增加了！\n"HIM"你的潜能增加了！\n"NOR);
        me->add("gift/202008151",1);
        me->save();
        destruct(this_object());
        return 1;
}
