#include <ansi.h>

inherit ITEM;
string *typew=({
"sword",
"blade",
"hammer",
"whip",
"club",
"staff",
"throwing",
"dagger",
"axe",
});
string *typea=({
"hands",
"cloth",
"armor",
"boots",
"head",
"neck",
"surcoat",
"shield",
"waist",
"wrists",
});
void create()
{
        set_name(HIG "随机打造升级玉石" NOR, ({ "wis dan" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","随机打造升级玉石包含1-9等。\n"ZJURL("cmds:use wis dan")ZJSIZE(15)"使用"NOR"看看!\n");
                set("jhxk", 10);
                set("value", 1000);
                set("unit", "粒");
                set("only_do_effect", 1);
        }
}

int do_effect(object me)
{
        object item;
        int ayai,lv,lb;
lv=0;
lb=random(28)+1;
if (random(2)==0 && lb <=12 ) lb= 12+random(17);
if (random(3)==0 && lb <=12 ) lb= 12+random(17);



if (random(4)==0) lv=100;
if (random(16)==0) lv=200;
if (random(32)==0) lv=300;
if (random(64)==0) lv=400;
if (random(128)==0) lv=500;	
if (random(256)==0) lv=600;
if (random(512)==0) lv=700;
if (random(1024)==0) lv=800;


if (random(2)==0 && lv >=300 ) lv= 300;
if (random(3)==0 && lv >=400 ) lv= 400;

if (random(2)==0)
{
	if (lv> 500) lv=500;
}

if (random(3)==0)
{
	if (lv> 600) lv=600;
}

if (random(4)==0)
{
	if (lv> 700) lv=700;
}

lb=lb+lv;

        message_vision("$N一仰脖，吞下了一粒" + this_object()->name() +
                       "。\n", me);
item = new("/p/newweapon/weaponobj/jade"+lb);
item->move(me, 1);

        destruct(this_object());
        return 1;
}