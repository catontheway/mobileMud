//Created by ququ
inherit ITEM;
#include <ansi.h>

void create()
{
/*ITEM_NAME*/set_name("八仙桌"
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
/*LONG*/+"这是一张竹子做的八仙桌。\n"
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