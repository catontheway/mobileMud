// milin1.c 密林
// by llin

inherit ROOM;

void create()
{
        set("short", "密林");
        set("long", 
"林中阴森森的，除了几声鸟叫外再没有其他的声音，四周\n"
"都是参天大树，遮天蔽日。脚下是厚厚的落叶，看不出有什么\n"
"人迹，显得格外怕人。\n"
        );
        set("exits", ([
                "east" :"/d/guiyunzhuang/guiyunting",
        ]));
        set("objects",([
          CLASS_D("taohua") + "/qulingf":1 ]));
        setup();
        replace_program(ROOM);
}


