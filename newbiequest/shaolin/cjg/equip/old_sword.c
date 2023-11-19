// old_sword.c 近古之剑
// by seagate@pkuxkx 2011.02.17

#include <ansi.h>
#include <weapon.h>
inherit F_GEMS;
inherit EQUIP;

void create()
{
	int flag;
	
  set_name(HIG"近古之剑"NOR, ({ "old sword","jian","sword" }) );
  set_weight(1000);
  set("unit", "柄");
  set("value", 20000);
  set("material", "steel");
  set("rigidity", 300);
  set("max_rigidity", 300);
  set("forge/times_max",1);
  set("forge/max", 2);
  set("generation", 2);
  set("suit", "cjg_level1");
  set("weapon_prop/strength", 10);
  set("weapon_prop/attack", 50);
  set("weapon/strength", 10);
  set("weapon/attack", 50);
  set("long", "一柄宋代匠工精心打造的宝剑。\n");
  if(query("two_hand")) 
  	flag = 1;
	set("weapon_prop/damage", 230);
	set("flag", 2 | (int)flag | EDGED);
	set("skill_type", "sword");
	if( !query("actions") ) 
	{
    set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "slash", "slice", "thrust" }) );
	}
  setup();
}