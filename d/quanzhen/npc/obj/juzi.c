//made by hacky;
//97,12,1
//pingguo.c
#include <ansi.h>
inherit ITEM;

inherit F_FOOD;

void create()
{
   set_name("橘子",({"juzi","ju"}));

   set_weight(30);
   if(clonep() )
     set_default_object(__FILE__);
   else
    {
   set("long",@LONG
一个蜜橘,你不禁想上去咬一口
LONG
    );
   set("unit","个");
   set("value",500);
   set("food_remaining",3);
   set("food_suply",20);
    }
 }    
