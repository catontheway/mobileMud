// 马车店 Zine 2012.8.1
inherit WAGON_SHOP;
void create()
{
        set("short", "计氏马车分行");
		set("exits", ([
		
		"north" : __DIR__"tieqiang",
		]));
		set("price",100);//雇车价格
        ::create();
}

