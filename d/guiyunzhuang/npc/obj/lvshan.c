// lvshan.c 绿衫

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("绿衫",({"lvshan", "shan", "cloth"}));
    set_weight(1500);
    if( clonep() )
       set_default_object(__FILE__);
    else {
	    set("female_only", 1);
        set("unit", "件");
        set("long","这是一件绿色的绸缎衫，上面还绣有几朵桃花。 \n");
        set("material", "cloth");
        set("armor_prop/armor", 1);
    }
    setup();
}
