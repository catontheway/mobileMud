// animal: snake.c
// Jay 3/18/96

inherit NPC;
#include "/d/baituo/npc/snake.h"
void create()
{
        set_name("毒蛇", ({ "snake", "she" }) );
         set("race", "蛇类");
        set("age", 4);
        set("long", "一只有着三角形脑袋的蛇，尾巴沙沙做响。\n");
        set("attitude", "peaceful");

        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 1000);
        set("max_qi",300);
        set("qi",300);

        set_temp("apply/attack", 15);
        set_temp("apply/damage", 6);
        set_temp("apply/armor", 2);

        setup();
}
/*
void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) )
        {
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob); 
        }
}
*/
void die()
{
        object ob;
        message_vision("$N啪的一声断成两截！$N死了。\n", this_object());
        destruct(this_object());
}

