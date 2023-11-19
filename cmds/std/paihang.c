// by Whuan@pkuxkx
// modified by Zine 20110801 去掉ansi符以及给名字那栏加了4个字符位置，对应最长的六个字名字，以及12字母的id
#include <ansi.h>
#include <mudlib.h>

inherit F_CLEAN_UP;
int top_list(object ob1,object ob2);

string replace_color(string arg)
{
        string str;
        str = arg;
        if (str)
        {
            str = replace_string(str,BLK,"");
            str = replace_string(str,RED,"");
            str = replace_string(str,GRN,"");
            str = replace_string(str,YEL,"");
            str = replace_string(str,BLU,"");
            str = replace_string(str,MAG,"");
            str = replace_string(str,CYN,"");
            str = replace_string(str,WHT,"");
            
            str = replace_string(str,HIR,"");
            str = replace_string(str,HIG,"");
            str = replace_string(str,HIY,"");
            str = replace_string(str,HIB,"");
            str = replace_string(str,HIM,"");
            str = replace_string(str,HIC,"");
            str = replace_string(str,HIW,"");
            str = replace_string(str,NOR,"");
            str = replace_string(str,BNK,"");   
        }
          
        
                
        return str;
}

int main(object me, string arg)
{
    
        object *list,*ob;
        int i,j,flag=0;
        string msg,str;
           
        
    if (time()-me->query_temp("scan_time") < 30 && !wizardp(me))
                return notify_fail("不要频繁的查询，谢谢！\n");

    me->set_temp("scan_time",time());
        ob = filter_array(objects(), (: userp($1) && !wizardp($1)&&!$1->query("no_top") :));
        list = sort_array(ob, (: top_list :));
       
       
        
        j=to_int(arg);
        if (j>= sizeof(list)) j=sizeof(list);
        j=j-10;
        if (j<=0) j=0;
        msg = ZJOBLONG+CHINESE_MUD_NAME+"在线百大高手排行榜\n" NOR+ZJOBACTS2+ZJMENUF(2,2,6,35);
        for (i = j ;i < j + 100 ; i++) {
			
        if( i >= sizeof(list)) 
        msg += sprintf("暂时空缺。"+NOR+":paihang"+ZJSEP);
            else {
                if( !list[i] ) continue;
                if( !list[i]->query("id") ) continue;
                if(list[i] == me) {msg += BBLU HIY;flag=1;}
                str=list[i]->query("name");
                str=replace_color(str);
				
                msg += sprintf(HIC"第       %-11s  名"+NOR+ZJBR+HIG"%s"+NOR+ZJBR+HIR"%-14s"+NOR+ZJBR+HIY"综合评价 %6d  "+NOR+":look "+list[i]->query("id")+ZJSEP,chinese_number(i+1),list[i]->query("name"),list[i]->query("family")?list[i]->query("family/family_name"):"普通百姓",TOPTEN_D->get_score(list[i]));    
            }
			//write(msg+"\n");
        }
       
            if (flag==0 || 1>0)
            {
                    for (i=0;i<sizeof(list);i++)
                    if (list[i]==me)
                    {
						//msg+="    你目前的排名是"+HIY"第"+chinese_number(i+1)+"名"+NOR+"，";
                           // msg+="你的评价是："HIY+sprintf("%5d\n",TOPTEN_D->get_score(list[i]))+NOR;
                           msg+=sprintf("你目前的排名是"+HIY"第"+chinese_number(i+1)+"名"+ZJBR+"你的评价是："HIY+"%5d"+NOR+":look "+list[i]->query("id")+ZJSEP,TOPTEN_D->get_score(list[i]));
                            //msg+="你的评价是："HIY+sprintf("%5d\n",TOPTEN_D->get_score(list[i]))+NOR;
                            break;
                    }
	   }
	   
        
        write(msg+"\n");
        return 1;

}
int top_list(object ob1, object ob2)
{
        int score1,score2;

        score1 = TOPTEN_D->get_score(ob1);
        score2 = TOPTEN_D->get_score(ob2);

        return score2 - score1;
}

int help(object me)
{
write(@HELP
指令格式 : paihang <数字> 
 
这个指令可以让你知道在线十大高手是哪些，别去惹他们。 
 
HELP
    );
    return 1;
}
