// buliao.c

#include <ansi.h>
inherit ITEM;

void initlvl();
#include "jadeh.c"

void create()
{
        set_name("玉石", ({ "yushi" }));
        set_weight(3000+random(5000));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "这是一块女娲补天用的玉石。\n");
                set("value", 3000);
                set("upyushi",1);
                //set("wyushi",1);
                set("no_sell",1);// add by LinuX@SJ
        }
        setup();
        initlvl();
//set_level(4,0);
}

int set_level(int level,int hehe)
{
	string type2;
	string type1;
	string name;
  set("upyushi",1);
type2=typeshi2[level];
type1=typeshi1[hehe];
name=type1+"之"+type2;
set_name(name, ({"nvwo shi","nvwoshi","shi"}));
set("upyushilb",level);	
set("upyushilv",hehe);
set("value", level*3000);
	return 1;
}

void initlvl() { set_level(4,27); }

