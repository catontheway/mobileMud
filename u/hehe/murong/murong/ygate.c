//ygate.c
//by hehe
//2003.3.5
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
    set("short", "燕子坞大门");
    set("long", HIB @LONG

        ■■■■■■■■■■■■■■■■■■■■■■■■■■
        ■■■■■■■■■■■■■■■■■■■■■■■■■■
            ■■■■■■■■■■■■■■■■■■■■■■
        ■■■■■■■□□□□□□□□□□□■■■■■■■■  
        ■■■■■■■□□  燕  子  坞  □□■■■■■■■■  
          ■■■■■■□□□□□□□□□□□■■■■■■■
          ■■■■■■■■■■■■■■■■■■■■■■■■  
          ■■■■■■□□□□□‖□□□□□■■■■■■■
          ■■■■■■□□□□□‖□□□□□■■■■■■■
          ■■■■■■□□□◎□‖□◎□□□■■■■■■■
          ■■■■■■□□□□□‖□□□□□■■■■■■■
          ■■■■■■□□□□□‖□□□□□■■■■■■■
          ■■■■■■□□□□□‖□□□□□■■■■■■■
LONG NOR
    );

    set("exits", ([
		"south" : __DIR__"yroad4",
		"north" : __DIR__"yyuan1",
    ]));
    
    set("outdoors", "murong");
    setup();

}