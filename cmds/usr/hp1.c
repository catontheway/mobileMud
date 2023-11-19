
#include <ansi.h>
 
inherit F_CLEAN_UP;
string time_change(int timep);
string status_color(int current, int max);
int main(object me, string arg)
{
	object ob,*tar;
	mapping yours,my,vip,vip1,vip2;
	string sp,status;
	int osize;
  
int nsize = file_size("/log/channel/qqlt");
	seteuid(getuid(me));
	ob = me;
	//int osize;
  
	my = ob->query_entire_dbase();
    tar = me->query_enemy();
	if (sizeof(tar)==1&&objectp(tar[0]))
    yours = tar[0]->query_entire_dbase();
	if (my["max_jing"] < 1 || my["max_qi"] < 1)
		return notify_fail("无法察看" + ob->name(1) + "的状态。\n");
/*if (osize != nsize)
message("channel",
	sprintf(read_file("log/channel/qqlt", file_length("log/channel/qqlt"), 1)),users());*/
	// if ( me->query("xkxvip/times") > 86400*7 )
//	 vip = 
	//line += sprintf("会员时效："HIY "%.2f\n" NOR, (me->query("xkxvip/times")*1.0)/86400 );
 if (!me->is_busy() ){
		 if (me->query("quest/time") <= time() || me->query("wjob/task_time")<= time())
			sp = ZJHPTXT+ZJMENUF(4,4,25,40) + sprintf("姓名：%s:100/100:%s",my["name"],"#000000");
			else if (me->query("quest/time") || me->query("wjob/task_time") )
			sp =ZJHPTXT+ZJMENUF(4,4,25,40) + sprintf("任务时限.%d秒:%d/1:%s", ob->query("quest/time") - time(),1,"#BB3F51B5");
			
		 }
			else if (me->is_busy() )
			{
			
		   if(me->query_temp("pending/suicide"))
			sp =ZJHPTXT+ZJMENUF(4,4,25,40) + sprintf("自杀删档中:100/100:%s","#BB3F51B5");
		    else if(me->query_temp("pending/draw"))
			sp =ZJHPTXT+ZJMENUF(4,4,25,40) + sprintf("画方圆:100/100:%s","#BB3F51B5");
			else if(me->query_temp("pending/cooking"))
			sp =ZJHPTXT+ZJMENUF(4,4,25,40) + sprintf("炒菜中:100/100:%s","#BB3F51B5");
			else if(me->query_temp("pending/exercise"))
			sp = ZJHPTXT+ZJMENUF(4,4,25,40) + sprintf("打坐中:100/100:%s","#BB3F51B5");
			else if(me->query_temp("pending/respirating"))
			sp =ZJHPTXT+ZJMENUF(4,4,25,40)  + sprintf("吐纳中:100/100:%s","#BB3F51B5");
			else if(me->query_temp("pending/respirate"))
			sp =ZJHPTXT+ZJMENUF(4,4,25,40) + sprintf("吐纳中:100/100:%s","#BB3F51B5");
			else if (me->query_temp("pending/xiulian"))
			sp = ZJHPTXT+ZJMENUF(4,4,25,40)  + sprintf("修练中:100/100:%s","#BB3F51B5");
			else if (me->query_temp("pending/practice"))
			sp = ZJHPTXT+ZJMENUF(4,4,25,40)  + sprintf("练习中:100/100:%s","#BB3F51B5");
			
			else if (me->query_temp("huoqiang/period"))
			sp =ZJHPTXT+ZJMENUF(4,4,25,40) + sprintf("火墙:100/100:%s","#BB3F51B5");
			else if(me->query_busy())
			sp =ZJHPTXT+ZJMENUF(4,4,25,40) + sprintf("忙乱.%d秒:%d/1:%s",me->query_busy(),1,"#BB3F51B5");
			
			}
		sp += "║"+sprintf("气血.%d:%d/%d/%d:%s:%s",my["qi"],my["qi"],my["eff_qi"],my["max_qi"]+ob->query_gain_qi(),"#99FF0000","exert recover");
		
		 if ( me->query("wrong_status") - time() >0 )
			sp += "║" + sprintf("走火入魔.%d秒:%d/1:%s", ob->query("wrong_status") - time(),1,"#BB3F51B5");
		 else sp += "║" + sprintf("内力.%d:%d/%d/%d:%s",my["neili"],my["neili"],my["max_neili"],ob->query_current_neili_limit(),"#990066FF");
		sp += "║" + sprintf("精神.%d:%d/%d/%d:%s:%s",my["jing"],my["jing"],my["eff_jing"],my["max_jing"],"#996600CC","exert regenerate");
		sp += "║" + sprintf("精力.%d:%d/%d:%s",my["jingli"],my["jingli"],my["max_jingli"],"#99006600",);
		
		
				
		sp += "║" + sprintf("食物.%d:%d/%d:%s",my["food"],my["food"],ob->max_food_capacity(),"#99FF6600");
		sp += "║" + sprintf("饮水.%d:%d/%d:%s",my["water"],my["water"],ob->max_water_capacity(),"#990000FF");
		
		sp += "║" + sprintf("潜能.%d:%d/%d/%d:%s",my["potential"]-my["learned_points"],my["potential"]-my["learned_points"],ob->query_potential_limit()-my["potential"],ob->query_potential_limit(),"#99FF00FF");
		//if ( me->query("xkxvip/times") > 1 )
		//sp += "║" + sprintf("会员时效.%d秒:%d/1:%s",ob->query("xkxvip/times"),1,"#99FF00FF");
	//else sp += "║" + sprintf("会员时效.%d秒:%d/1:%s",me->query("xkxvip/times"),"#99FF00FF");
	
	sp += "\n";
	tell_object(me, sp);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : hp
	  hp <对象名称>		  (巫师专用)
 
这个指令可以显示你(你)或指定对象(含怪物)的精, 气, 神数值。
 
see also : score
HELP );
    return 1;
}


