// help.c
#include <ansi.h>
#include "/doc/help.h"
#define DEFAULT_LINE 50000
#define DEFAULT_HELP_PATHS ({"/help/", })

#define DEFAULT_TIT_PATHS ({"/help/tit/",})
inherit F_CLEAN_UP;

string *default_search = DEFAULT_SEARCH_PATHS;
string *tit_search = DEFAULT_TIT_PATHS;
string *help_search = DEFAULT_HELP_PATHS;
string desinq(object me,string str)
{
	
	 str = ZJOBACTS+ZJMENUF(1,7,7,38);

	

	
	 str += "帮助列表:help sy1"+ZJSEP
	 +"地图列表:help faq"+ZJSEP
	 +"门派简介:help faq"+ZJSEP
	 +"玩家相关:help faq"+ZJSEP
	 +"任务系统:help faq"+ZJSEP
	 +"功夫相关:help faq"+ZJSEP
	 +"秘密介绍:help faq"+ZJSEP;
	 



	if(str==(ZJOBACTS+ZJMENUF(1,4,9,32))) str = "";
	return str+"\n";
}
void query_wiki(string arg,object me)
{
	if (!me) return;
	if (me->query_temp("wiking") && ((time() - me->query_temp("wiki_start_time")< 65)))
	  		tell_object(me,"你上次的wiki查询还未结束，暂时无法进行wiki查询。\n");
	else if (!me->query("env/nowiki"))
	  		tell_object(me,load_object("/adm/daemons/webd")->query_web(me,arg,"WIKI"));
	me->set_temp("wiking",arg);
	me->set_temp("wiki_start_time",time());
}
int main(object me, string arg)
{
	object ob;
	int i,page;
	string file, *search,str;

//tell_object(this_player(),HIY"因游戏内不能贴图，且巫师更新帮助速度较慢，请查看北侠百科寻求帮助。\n访问地址："+HIR"http://wiki.pkuxkx.com/"+HIY"中获得。\n"NOR);
	// If no topic specified, give the topics.。
	if( !arg )
	{
		if (file_size(HELP_DIR + "/tit/topics") > 0)
		{
			str = replace_string(color_filter(read_file(HELP_DIR+"/tit/topics")),"\n","");
			str = replace_string(str,"$sp#","\n");
			write(ZJOBLONG+str+"\n");
		} else
		{
			write("没能找到帮助主题。\n");
		}
		
		return 1;
	}
	
		
	
			
		
			
		
	

	seteuid(getuid());

	if(sscanf(arg,"%s %d",arg,page)!=2)
		page = 1;
	if( pointerp(tit_search) ) {
		i = sizeof(tit_search);
		while(i--) if( file_size(tit_search[i] + arg)>0 ) {
			str = replace_string(color_filter(read_file(tit_search[i] + arg)),"\n","");
			str = replace_string(str,"$sp#","\n");
			write(ZJOBLONG+str+"\n");
			return 1;
		}
	}
	if( pointerp(help_search) ) {
		i = sizeof(help_search);
		while(i--) if( file_size(help_search[i] + arg)>0 ) {
			write(ZJOBLONG+replace_string(color_filter(read_file(help_search[i] + arg)),"\n",ZJBR)+"\n");
			//me->zj_more(ZJMAPTXT,arg,explode(color_filter(read_file(help_search[i] + arg)),"\n"),DEFAULT_LINE,page);
			return 1;
		}
	}
	if( pointerp(default_search) ) {
		i = sizeof(default_search);
		while(i--) if( file_size(default_search[i] + arg)>0 ) {
			write(ZJOBLONG+replace_string(color_filter(read_file(default_search[i] + arg)),"\n",ZJBR)+"\n");
	//		me->zj_more(ZJOBLONG,arg,explode(color_filter(read_file(default_search[i] + arg)+NOR),"\n"),10,page);
		
			
			return 1;
		}
	}
	
	
	if( stringp(file = me->find_command(arg)) ) {
		notify_fail("有这个指令存在，但是并没有详细的说明文件。\n");
		return file->help(me);
	}
	// Search the individual search path first.
	if( pointerp(search = me->query("help_search_path")) ) {
		i = sizeof(search);
		while(i--) if( file_size(search[i] + arg)>0 ) {
			me->start_more( read_file(search[i] + arg) );
			return 1;
		}
	}

	// Support efun/lfun help with same name as other topics such as
	// ed() and ed command.
	sscanf(arg, "%s()", arg);
	//arg最后如果有\，则会死循环出错，所以去掉arg中的\和空格
	arg = replace_string(arg," ","");
	arg = replace_string(arg,"\\","");
	// Finally, search the default search paths.
	if( pointerp(default_search) ) {
		i = sizeof(default_search);
		while(i--) if( file_size(default_search[i] + arg)>0 ) {
			me->start_more( F_NAME->replace_color(read_file(default_search[i] + arg) ));
			return 1;
		}
	}

	return notify_fail("没有针对这项主题的说明文件。\n");
}

int help(object me)
{
	write(@HELP
指令格式：help <主题>              例如：> help cmds
          help <函数名称>()        例如：> help call_out()

这个指令提供你针对某一主题的详细说明文件，若是不指定主题，则提供你有关
主题的文件。
HELP
	);
	return 1;
}

