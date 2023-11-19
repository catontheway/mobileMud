inherit ITEM;

#include <ansi.h>
string *names = ({
        HIW"基本音律-碧海潮生"NOR,
        HIY"基本音律-碧海潮生"NOR,
        HIR"基本音律-碧海潮生"NOR,
        HIM"基本音律-碧海潮生"NOR,
        HIB"基本音律-碧海潮生"NOR,
        HIG"基本音律-碧海潮生"NOR,
});
void create()
{
        set_name(names[random(sizeof(names))] ,({"y l","gift"}));
        set("long","基本音律-碧海潮生！\n"
        );
        set("value",1000000);
        set_weight(10);
        set("no_store",1);
        set("no_sell",1);
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
        if(arg!="y l"&&arg!="gift") return 0;
       // if (me->query("gift/202008151") > 1)
         //       return notify_fail("你已经吃过了月饼了，也不怕撑得慌！\n");
        message_vision(HIC"只见一阵飘渺的声音响起" 
        + this_object()->name() + HIC"，消失了～～\n"NOR,me);

         me->set_skill("music::shaw::bihai-chaosheng",500);
              
        tell_object(me,HIW"你的音律增加了五百级！\n"NOR);
       // me->add("gift/20200815",1);
        me->save();
        destruct(this_object());
        return 1;
}
