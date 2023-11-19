#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIM "干将圣符" NOR, ({ "ganjiang charm", "charm" }));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIM "干将圣符可以将自制装备升级为可SUMMON道具，以后可以随时\n"
                            "召唤(SUMMON)升级后的道具。\n"
                            "指令格式： upd <欲升级道具ID> \n" NOR);
                        
                set("unit", "块");
                set("value", 500000);
        }
        setup();
}

int query_autoload()
{
        return 1;
}

void init()
{
        add_action("do_integrate", "updd");
}

int do_integrate(string arg)
{
        object me;
        object ob;
        string content,sxjq,mysxjq,file;
        string item, str;
        mapping data;

        if (! arg)
                return notify_fail("你要往什么道具上使用该圣符？\n");
        
    
                
        me = this_player();
       if (! objectp(ob = present(arg, me)) &&
            ! objectp(ob = present(arg, environment(me))))
                return notify_fail("你身上和附近没有这样道具啊。\n");

        if (member_array(F_EQUIP, deep_inherit_list(ob)) == -1 &&
            !ob->query("can_summon") )
                return notify_fail("这类物品无法升级。\n");        
        
        //  if (!ob->is_weapon() && !ob->is_unarmed_weapon())
          //      return notify_fail("你只能在自制装备上使用圣符。\n");
        
        if( ob->query("money_id") )
                return notify_fail("你没用过钱啊？\n"); 
                
     
                
        tell_object(me,HIR "\n$N" HIR "用利刃将双手手心划破，双掌贴在" + ob->name() + HIR "上，"
                     "渐渐地，" + ob->name() + HIR "将$N" HIR "的鲜血吸收……\n\n" NOR);

        tell_object(me, "你把" + name() + "盖在" + ob->name() + "上，然后口中念念有词，\n"
                        "只见圣符化作一道红光飞入" + ob->name() + "体内！\n");

        tell_object(me, HIC "你感受" + ob->name() + HIC"发生了不可言喻的变化。\n" NOR);
        ob->set("weapon_prop/max_qi",1000);
        
 
         ob->save();
        
                                

        destruct(this_object());
        return 1;
}
