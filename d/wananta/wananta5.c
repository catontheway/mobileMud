//万安寺 
//by picewolf
//2009-5-7

#include "wananta.h"
void create()
{
        set("short", HIC"万安塔五层"NOR);
        set("long", @LONG
这里是万安塔的第五层，四周火把通明，塔内亮如白昼。在
暗处站着几个番兵，守着一面响锣(luo),对你虎视眈眈。
LONG
			);
		set("room_lvl",5);
		set("item_desc", ([
		"luo" : "这是一面响锣，敲(qiao)一下，便可出塔。\n"
		ZJOBACTS2+ZJMENUF(2,2,12,40)+"敲响锣:qiao luo\n",
	]));
		set("exits", ([     
		"up" : __DIR__"wananta6", 
		]));
		set("outdoors", "luoyang");
		setup();
}

