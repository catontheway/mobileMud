//五军大都督

#include <ansi.h>
inherit NPC;
#include <title.h>
#include "huilu2.h"
#include "/d/yingtianfu/neicheng/npc/daming_npc_officer.h"
void create()
{
    set_name("都督同知", ({"dudu tongzhi", "dudu"}));
    set("title", HIW"大明五军都督府"NOR);
    set("gender", "男性");
    set("age", 40);
    set("long", "他就是当今朝廷五军都督府的都督同知。\n");
    set("attitude","heroism");
    set("generation",0);

    set("max_qi",800);
    set("eff_qi",800);
    set("qi",800);
    set("max_jing",300);
    set("jing",300);
    set("shen_type",1);
    set("no_clean_up",1);
    set("mingpin",1);
    set("combat_exp",2000000);

    
	

    setup();
    setup_player_name();
}
