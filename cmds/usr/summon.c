// summon. 取回兵器

#include <ansi.h>
#include <command.h>

inherit F_CLEAN_UP;

int main(object me, string str)
{
        object ob, env;
        string file, msg;
        mapping summon;
        string *ks;
        int i;

        if (! str)
        {
                summon=me->query("can_summon");
                if (! mapp(summon) || ! sizeof(summon))
                        return notify_fail("你要召唤什么物品？\n");

                ks = keys(summon);
                /*
                msg = "你现在可以召唤的物品代码有";
                if (sizeof(ks) >= 2)
                        msg += implode(ks[0..sizeof(ks) - 2], "、") +
                                "和" + ks[sizeof(ks) - 1] + "。\n";
                else
                        msg += ks[0] + "。\n";
                msg = sort_string(msg, 64);
                */
              msg = ZJOBLONG+"你现在可以召唤的物品有:"+ZJBR+NOR;
              //  msg += "你现在可以召唤的物品有:\n"+ZJBR+NOR;
              
               // msg += "你现在可以召唤的物品有:"+ZJBR+NOR;
               // msg += "\n" NOR;
         //   msg += ZJOBACTS2+ZJMENUF(1,1,7,40);
                for( i=0; i<sizeof(ks); i++ )
                {
                         
                        if( !get_object(summon[ks[i]]) ) { me->delete("can_summon/"+ks[i]); continue; }
                        msg += sprintf(HIW "物品代码：%-15s    物品名字："+ZJURL("cmds:summon "+ks[i])+ZJSIZE(20)"%-20s"+ZJBR+NOR,ks[i],summon[ks[i]]->name());
                      //  msg +=  summon[ks[i]]->name()+"summon "+ks[i]+ZJSEP;
                       //  write("-------------------"+ks[i]+summon[ks[i]]->name()+" -------------------\n");
                }
                msg += "\n"; 
	message("vision",msg, me);
                return 1;
        }

        if (me->is_busy())
                return notify_fail("你现在正忙，等你有空了再说吧。\n");

        if( !stringp(file=me->query("can_summon/"+str)) )
                return notify_fail("你不知道如何召唤这个物品。\n");

        if (file_size(file + ".c") < 0 && file_size(file) < 0)
                return notify_fail("你不知道如何召唤这个物品。\n");

        if (me->is_ghost())
                return notify_fail("等你还了阳再召唤吧。\n");

        if( time()-me->query("combat/punish")<600 )
                return notify_fail("你暂时无法感应到你的物品。\n");

        env = environment(me);
        if( env->query("no_magic") && sscanf(base_name(env), "/f/%*s") != 1 )
                return notify_fail("你在这里无法感应到你的物品。\n");

        call_other(file, "???");
        ob = find_object(file);
        if (! ob || ! ob->receive_summon(me))
        {
                message_vision(HIM "$N" HIM "扬起手来，口中念念有"
                               "词。\n然而什么也没有发生 :)\n", me);
        }

        if (me->is_fighting())
                me->start_busy(2 + random(3));

        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : summon <物品的ID>

此指令可让你把某些物品呼唤过来并装备上，当然你得有一定的
精力施展仙术才行。
HELP );
        return 1;
}
