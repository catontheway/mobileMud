// long_ya.c
// Create by TEMPLATE_D. Tue Oct 05 09:31:46 2021.
#include <ansi.h>
#include <weapon.h>
inherit EQUIP;
void create()
{
        int bonus;
        int flag;
        if (random(100)<90) bonus = random(50)+1;
        else if (random(100)<99) bonus = random(30)+51;
        else bonus = random(20)+81;	
	set_name("[1;33m龙 牙[2;37;0m", ({ "long ya" }));
        set_weight(5000);
	set("weapon_prop", ([ /* sizeof() == 3 */
  "magic" : 44,
  "dodge" : -1,
  "damage" : 144,
]));
	set("unit", "把");
	set("no_sell", 1);
	set("no_pawn", 1);
	set("long", "一把泛着微弱光芒的巨剑，看似厚重，握在手中竟是轻巧之极。
剑柄上用隶书刻着几个字：虫牙第44号，甚是怪异。
[2;37;0m");
	set("value", 200000);
	set("material", "steel");
	set("rigidity", 700);
	set("wield_msg", "$N从背后抽出一把[1;33m龙 牙[2;37;0m，“嗡嗡”之声犹如龙吟。
[2;37;0m");
	set("unwield_msg", "$N把手中的[1;33m龙 牙[2;37;0m藏回身后，身形也跟着矮了一截似的。
[2;37;0m");

	set("attribute", 44);
	set("flag", 6);
	set("skill_type", "sword");
	set("taozhuang", "long");
        if( !query("actions") ) {
	set("actions", (: call_other, "/adm/daemons/weapond", "query_action" :));
	set("verbs", ({ /* sizeof() == 3 */
  "slash",
  "slice",
  "thrust"
}));
                                }
	set("can_sign", 1);
	set("no_drop", 1);
	set("no_put", 1);
	set("auto_load", 1);
	set("no_store", 1);
	set("item_owner", "haitian");
	set("max_rigidity", 700);
        setup();
}
int receive_summon(object me)
{
        return ITEM_D->receive_summon(me, this_object());
}

// 隐藏物品
int hide_anywhere(object me)
{
        return ITEM_D->hide_anywhere(me, this_object());
}


int is_no_clone() { return 1; }

