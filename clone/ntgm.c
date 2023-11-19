#include <ansi.h>
#include <title.h>
inherit ITEM;

void create()
{
        set_name(HIG "逆天改命★无损师门" NOR, ({ "ntgm dan" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","逆天改命★无损师门，使用无损脱离师门，相当于再出师一次，只能使用一次，并且铜雀台逆天改命增加到完成136次才能使用。注意：此物对朝廷无用\n"ZJURL("cmds:use ntgm dan")ZJSIZE(15)"使用"NOR"看看!\n");
                set("jhxk", 136);
                set("value", 1000);
				set("no_get", 1);
				set("no_give", 1);
				set("no_sell", 1);
				set("no_drop", 1);
				set("no_put", 1);
				//set("no_drop", 1);
                set("unit", "粒");
                set("only_do_effect", 1);
        }
}

int do_effect(object me)
{
        object item;
        int ayai;
		string *old_family=({});
/*if(me->query("ntgm"))
{
	 tell_object(me,"很遗憾，这次尝试似乎失败了。\n");
        return 1;
}*/
        message_vision("$N一仰脖，吞下了一粒" + this_object()->name() +
                       "。\n", me);

                        old_family+=({me->query("family/family_name")});
	me->set("tqt/old_family",old_family);
    me->set("reborn/chushi",1);
    me->set("chushi/done",1);//加上出师标记，防止纯门派漏洞
	me->delete("family");
	me->set("score",0);
	me->delete("class");
	me->set("ntgm",1);
	me->restore_face(FACE_ORIGIN);
	me->set("title",HIY+"铜雀台中人"+NOR);
	me->set_title(({TITLE_QUEST1, TITLE_QUEST2, TITLE_QUEST3, TITLE_QUEST4, TITLE_QUEST5, TITLE_QUEST6, TITLE_QUEST7, TITLE_QUEST8, TITLE_QUEST9}), me->query("title"),"铜雀台");
                      

        destruct(this_object());
        return 1;
}