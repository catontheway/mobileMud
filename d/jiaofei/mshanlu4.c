//Create by whuan@pkuxkx
//铁掌帮
inherit __DIR__"jiaofeiroom.c";


void jiaofei_init()
{
	short_name = "石阶";
  long_describe = "你顺着山路走了许久，终于到了拇指峰的第一节，远远望去，其余四峰直插云霄，若隐若现";
 	doorstr = 20; 
 	nextdirect = "northup";
 	npc_type="shenlongdao";
 	level=1;
}

void create()
{
	::create();
	set("exits", ([ 
         "northup" : __DIR__"mshanlu5",
         "southdown" : __DIR__"mshanlu3",	
      ]));
}