#include <ansi.h>
inherit NPC;
void create()  
{	set_name(YEL"歌妓"NOR, ({ "ge ji","ji"}));
	set("gender", "女性");
	set("age", 18);
	set("str", 17);
	set("dex", 26);
	set("long", "她是吕文德买来的歌妓。\n");
	set("combat_exp", 100);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 10);
	
	set("neili", 100); 
	set("max_neili", 100);
        set("chat_chance", 10);
        set("chat_msg", ({
       "吕大人,我再给您吹一个小曲,好不好啊?\n"
        }) );
         

        setup();
	carry_object(__DIR__"obj/dizi");

}

