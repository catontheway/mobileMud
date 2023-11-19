//cikebi_book.c
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"古刺客匕法秘籍"NOR, ({ "liuxingmingwang book", "lxmw book","book","blade book" }));
        set_weight(600);
                set("unit", "本");
                set("long",
"这是上古留传下来的神奇短兵刃秘籍，是可遇而不可求的.\n相传上面所载的古刺客匕法，是上古极强的武功之一。\n");
                set("no_store", 1);
                set("no_sell", 1);
                set("no_pawn", 1);
                set("value", 100);
                set("material", "paper");
                set("skill", ([
                        "name":  "cike-bi", 
                                      
                        "jing_cost":      50,                           
                        "difficulty":   50,                            
               
                "max_skill": 60, 
                                                                               
                ]) );
}
void init()
{
				remove_call_out("des");
				call_out("des",30,this_player(),this_object());
}
int des(object me,object book)
{
	tell_object(me,HIW"忽然间，秘籍就化为一阵幻影化为乌有了!\n"NOR);
	destruct(book);
	return 1;
}
