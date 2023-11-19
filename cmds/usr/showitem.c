/**

物品展示
by fang q 184377367

*/

#include <zjmud.h>
#include <room.h>
#include <ansi.h>
#include <combat.h>
#include <color.h>
#include <mxp.h>
#include <mudlib.h>
inherit F_CLEAN_UP;
#include <identify.h>



void do_look_eye(string player_id,string target);
void do_show_eye(object player,string objname);

int main(object me, string arg)
{
	//设置使用者 其实就是玩家英文账号

	object player,ob;
	//act_type 动作类型 target 目标
	string r, objname, target,player_id;
	//这句必须放在变量定义之后 没查为什么
	seteuid( getuid() );

	player = me;
	//if 必须花括号，不要用非主流!!
	if (! arg ){
		return notify_fail("你要搞点什么小动作？\n");
	}





	if (sscanf(arg, "look %s %s", player_id,target)==2){
		do_look_eye(player_id,target);
		return 1;
	}

	if (sscanf(arg, "%s", objname)==1){
			do_show_eye(player,objname);
				return 1;
		}


}


void do_show_eye(object player,string objname){
	object ob;
	string mtr_id,player_id;
	ob = present( objname, player );


	if (!ob){
		write("你身上没有这个东西!\n");
	}

	if (!objectp(ob)){
		write("你确定这是个物品?\n");
	}
	//look book of xxx
		mtr_id	 = (string)ob->query("id");
	player_id	 = player->query("id");
	CHANNEL_D->do_channel(player, "chat", ZJURL("cmds:showitem look "+player_id+" "+mtr_id)+ZJSIZE(24)+ob->query("name")+NOR"\n");


}


void do_look_eye(string player_id, string target){
	//先查找玩家
	 
     int rig,idf,itype;
	object player,ob;
	string show_txt,val,valt;
	 player = find_player(player_id);
	
    
	
	 if (!objectp(player)){
	 		write("对方好像下线了..!\n");
	 		return;
	 	 }


	 	 ob = present( target, player );

	 	 if (!objectp(ob)){
	 		write("没有这个东西!\n");
	 		return;
	 	 }
 idf = ob->get_idflevel();
    itype = ob->is_identify();
	 	show_txt =ZJOBLONG+ZJSIZE(26)+ob->query("name")+NOR+replace_string(ZJBR+ob->query("long"),"\n","")+NOR+ZJBR;

		//show_txt += ob->long()+"\n";
		if( itype==IDF_EQUIP || 
        ( itype==IDF_SIMPLE &&
          idf==IL_FULL ) )
    {
      if( idf==IL_INIT )
    	  show_txt += HIR"（未鉴定）\n"NOR;
      else if ( idf==IL_SIMPLE )
    	  show_txt += HIY"（部分鉴定）\n"NOR;
      else if ( idf==IL_FULL )
    	  show_txt += HIG"（已鉴定）\n"NOR;
      
      show_txt+=ob->identify(idf);
  	}
  	else if ( itype==IDF_SIMPLE )
  	  show_txt=ob->identify(IL_FULL);
    
    rig = ob->query("rigidity");
    if (rig > 0)	//已经坏了的就不管了。
        if (rig > 100)
			show_txt += ob->name() + "完好无损，宛如新的一般。\n";
           // message("vision", obj->name() + "完好无损，宛如新的一般。\n";
        else if (rig > 80)
            show_txt += ob->name() + "已经轻微磨损，表面布满了细细的划痕。\n";
        else if (rig > 40)
           show_txt += ob->name() + "多次与其他兵器撞击，表面已是遍体鳞伤，但仍然可以凑合着用。\n";
        else if (rig > 10)
            show_txt += ob->name() + "已是严重受损，几道明显的裂纹已经危及了它的寿命。\n";
        else if (rig > 0)
           show_txt += ob->name() + "被几道深深的裂痕分割成几部份，几乎马上就要断了。\n";
	 	//show_txt+="\n";
	 	show_txt = replace_string(show_txt,"\n",ZJBR);
	if(show_txt[(strlen(show_txt)-4)..(strlen(show_txt)-1)]=="$br#")
		show_txt = show_txt[0..(strlen(show_txt)-5)];
	show_txt += "\n";
	//str += desinq(me,obj);
	//str += getact(me,obj);
	write(show_txt+"\n");
	

}



int help(object me)
{
	write(@HELP
指令格式 : 例 eye object

HELP );
	return 1;
}

