//Created by ququ
inherit ITEM;
#include <ansi.h>

void create()
{
/*ITEM_NAME*/set_name("书桌"
, ({
"table", 
 }));
		set("no_sell",1);
		set("value",1);
/*CANEXPAND*/ set("canexpand",1);
         
		if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", ""
/*LONG*/+"这是一张长方的书桌。\n"
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//LONG
//OVERLONG
);
                set("unit", 
/*SET_UNIT*/"张"
);
        }
        setup();
}