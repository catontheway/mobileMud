// 山林
// edit: by zine Oct 19 2010

inherit __DIR__"shanlinconfig";

void create()
{
	set("short", "山林");
	set("long", @LONG
这里是一座毒虫出没的山林，千年的古树却是制作兵器的上佳材料。
LONG
	);
    set("normaldesc", @LONG
这里是一座毒虫出没的山林，千年的古树却是制作兵器的上佳材料。
LONG
	);
	set("exits", ([ 
		"south" : __DIR__"shanlin5",
        "west" : __DIR__"shanlin7",
		
    ]));
		 set("action_list", ([
		
        "找毒虫" : "xian",
        "挖毒草 " : "wa",
        	
       ]));
	//set("objects", ([(__DIR__"npc/qinjun") : 1,
    //]));
	setup();
	::create();
}

