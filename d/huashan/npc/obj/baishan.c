// baishan.c 白色长衫
// By Marz

#include <armor.h>

inherit CLOTH;

void create()
{
    set_name("白色长衫", ({"shan", "cloth", "chang shan"}) );
    set_weight(1500);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "件");
        set("long", "这是件质地轻软的白色长衫。\n");
        set("material", "cloth");
        set("armor_prop/armor", 1);
    }
    setup();
}
