// cpud.c

#pragma optimize
#pragma save_binary

inherit F_DBASE;

#include <ansi.h>

int clean_up() { return 1; }

#define CHECK_PERIOD    1     // 100s检查一次
#define EXPECTATION     50      // 希望心跳50次

#define check_period    my["check_period"]
#define expectation     my["expectation"]
#define counter	 my["counter"]
#define last_check      my["last_check"]
#define last_rusage     my["last_rusage"]
#define last_0	  my["last_0"]
#define last_1	  my["last_1"]
#define last_2	  my["last_2"]
#define last_3	  my["last_3"]
#define last_4	  my["last_4"]

void create()
{
	mapping my;
	seteuid(getuid());
	set("channel_id", "");
	CHANNEL_D->do_channel(this_object(), "sys", "天外来音已启动。");
	set_heart_beat(1);

	// 初始化扫描时间
	my = query_entire_dbase();

	last_check = time();
	last_rusage = rusage();
	counter = 0;
}

void heart_beat()
{
	mapping my;
	mapping info;
	
	int tlen;
	int supp, cost;
	int osize;
    //int nsize = file_size("/log/channel/qqlt",1);
	
	string str,std;
	
	my = query_entire_dbase();

	counter++;
   str = read_file("/log/channel/qqlt",1);
   std = read_file("log/channel/ltbf",1);
   
	//rooms=explode(read_file("log/annel/lt",  1)，"\n")
	//file = get_dir(str, -1);
	//std = stat("log/annel/qqlt");
	//rooms = sprintf("%s",file);
	//rooms =explode(read_file("log/annel/qqlt",  1),"\n")[<1];
	if ((tlen = (time() - last_check)) < check_period)
		return;
	
	/*	if (read_file("/log/channel/qqlt",1)!= read_file("log/channel/ltbf",1))
		{
			 
		CHANNEL_D->do_channel(this_object(),"qq",
	sprintf(read_file("log/channel/qqlt", file_length("log/channel/qqlt"), 1)));
	//if (str=std)
	write_file("/log/channel/ltbf",read_file("log/channel/qqlt", file_length("log/channel/qqlt"), 1));
	
		}*/
	

	// rotate the stat.
	

	last_rusage = info;
	last_check  = time();
	counter = 0;

}
