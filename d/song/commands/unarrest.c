// unarrest.c 
// Zine 2012/10/14
inherit F_CLEAN_UP;
#include <ansi.h>
#include "cmd_assist.h"
int help(object me);
int main(object me,string arg)
{
	object pl;
	string benefit="unarrest",type="day";
	song_cycle(me,type,benefit);
	if (arg=="-h")
	return help(me);
    if (!DASONG_D->get_my_pin(me)||!me->query("song/pro"))
    return 0;
    if (DASONG_D->get_my_pin(me)>4)
	return 0;
    if (me->query("song/"+benefit+"/times")>=1)
    {
		tell_object(me,"你今天已经帮助"+me->query("song/unarrest/target_name")+"疏通过一次了，要适可而止。\n");
		return 1;
	}
    if (!arg||arg=="")
    {
		tell_object(me,"你要帮谁疏通解除通缉？\n");
		return 1;
	}
	if (present_song_user(me,arg)==0)
	return 1;
	else 
	pl=find_player(arg);
    if (DASONG_D->get_my_pin(pl)>0&&DASONG_D->get_my_pin(me)-DASONG_D->get_my_pin(pl)>1)
    {
		tell_object(me,"大人物的事情，小虾米就别掺和了！\n");
		return 1;
	}
    if (!pl->query_condition("killer"))
    {
		tell_object(me,pl->query("name")+"根本没被通缉。\n");
		return 1;
	}
    me->set("song/"+benefit+"/times",1);
    me->set("song/"+benefit+"/target_name",pl->query("name"));
    pl->apply_condition("killer", 1);
    message_vision(HIW"$N拍着胸脯对$n道：放心，包在我身上了！一会我就给刑部打个招呼去。\n"NOR,me,pl);
    return 1;
}
int help(object me)
{
    write("
指令格式 : unarrest <id> 
帮助某玩家解除通缉状态。
"    );
    return 1;
}
