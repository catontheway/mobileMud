inherit F_CLEAN_UP; 

#define PATH_D  "/adm/daemons/pathd.c"

int main(object me, string arg)
{
        mixed a;
        mixed br;
        string str = "",*walks;
        
        if( uptime() < 1 )
                return notify_fail("系统气喘嘘地叹道：重启不到2100秒，请稍后再试 ....\n");

        if(time() - me->query_temp("last_walk") < 10 )
                return notify_fail("系统气喘嘘地叹道：慢慢来 ....\n");
			
		

        if( !arg ) return notify_fail("你想得到去哪儿的路径？\n");
		
	
        if( environment(me)->is_chat_room() ) return notify_fail("聊天室内不能使用寻路功能！\n");

        if( sscanf(base_name(environment(me)), "/f/%*s") )
                return notify_fail("副本里禁止使用walk寻路功能 ....\n");

        if( !is_chinese(arg) )
                return notify_fail("请输入中文地址。\n");

        me->set_temp("last_walk", time());
        a = PATH_D->search_for_path(me, arg);
        if( !a || a == 1) {
                me->set_temp("last_walk", time()+10);
                write("没有这个地方，或者这个地方离这里超过规定的距离限制。\n");
                return 1;
        }
        write(arg+"路径搜索完成，共"+sizeof(a[1])+"步，路线为：\n");
        for( int i = 0;i < sizeof(a[1]);i++ )
        {
                str    += a[1][i] + ";";
        }
        str = str[0..<2]; 
        write(str+"\n");//输出路线
        br = me->query("env/brief");
        me->set("env/brief", 1);
        walks = explode(str,";");
for(int i = 0;i < sizeof(walks);i++)
{
tell_object(me,ZJFORCECMD(walks[i]));//利用客户端来处理指令，可以达到防止玩家进行机器人或脚本操作等行为。
}
        me->set("env/brief", br);
        write("你已经到达"+arg+"。\n");
        return 1;
}


