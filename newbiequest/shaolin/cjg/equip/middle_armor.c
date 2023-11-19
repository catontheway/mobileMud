// middle_armor.c 中古之甲
// by seagate@pkuxkx 2011.02.17

#include <ansi.h>
#include <armor.h>
inherit F_GEMS;
inherit EQUIP;

void create()
{
  set_name(HIB"中古之甲"NOR, ({ "middle armor","armor" }) );
  set_weight(4000);
  set("unit", "件");
  set("value", 20000);
  set("material", "steel");
  set("rigidity", 300);
  set("max_rigidity", 300);
  set("forge/times_max",1);
  set("forge/max", 3);
  set("generation", 2);
  set("suit", "cjg_level1");
  set("armor_prop/armor", 550);
  set("armor_prop/magic", 10);
  set("armor/armor", 550);
  set("armor/magic", 10);
  set("long", "一件汉代匠工精心打造的盔甲。\n");
  setup();
	set("armor_type", TYPE_ARMOR);
}