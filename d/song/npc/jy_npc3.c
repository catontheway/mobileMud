#include <ansi.h>
inherit __DIR__"song_officer";
void create()
{
	call_out("npc_to_player",1,"右司谏",40,-1);
	::create();
}

