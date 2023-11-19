// middle_blade.c 中古之杖
// by seagate@pkuxkx 2011.02.17

#include <ansi.h>
#include <weapon.h>
inherit F_GEMS;
inherit EQUIP;

void create()
{
	int flag;
	
  set_name(HIB"中古之杖"NOR, ({ "middle staff", "staff" }) );
  set_weight(6000);
  set("unit", "根");
  set("value", 20000);
  set("material", "steel");
  set("rigidity", 300);
  set("max_rigidity", 300);
  set("forge/times_max",1);
  set("forge/max", 3);
  set("generation", 2);
  set("suit", "cjg_level1");
  set("weapon_prop/strength", 25);
  set("weapon_prop/dexerity", -10);
  set("weapon/strength", 25);
  set("weapon/dexerity", -10);
  set("long", "一根汉代匠工精心打造的禅杖。\n");
  if(query("two_hand")) 
  	flag = 1;
	set("weapon_prop/damage", 190);
	set("flag", (int)flag | LONG );
	set("skill_type", "staff");
	if( !query("actions") ) 
	{
    set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "bash", "crush", "slam" }) );
	}
  setup();
}
  	  