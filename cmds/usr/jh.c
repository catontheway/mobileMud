
#include <combat.h>
#include <ansi.h>
int help(object me);

int main(object me, string arg)
{
	string str,scc,tee;
     if (! arg || arg == "")
        {		str = ZJOBLONG+"离线计划设置系统\n"+ZJOBACTS2+ZJMENUF(2,2,8,30);;
	//str +=" 「计划开始」"+ZJBR+HIY+"状态"+NOR+HIR+query("jhks", me )+NOR+":set jhKs REPEAT"+ZJSEP;
	str += " 「计划指令【1】」"+ZJBR+HIY+"状态："+NOR+HIR+me->query("env/jhzl1" )+NOR+":jh jhzl1"+ZJSEP;
	str += " 「计划指令【2】」"+ZJBR+HIY+"状态："+NOR+HIR+me->query("env/jhzl2")+NOR+":jh jhzl2"+ZJSEP;
	str += " 「计划指令【3】」"+ZJBR+HIY+"状态："+NOR+HIR+me->query("env/jhzl3")+NOR+":jh jhzl3"+ZJSEP;
	str += " 「计划指令【4】」"+ZJBR+HIY+"状态："+NOR+HIR+me->query("env/jhzl4" )+NOR+":jh jhzl4"+ZJSEP;
	str += " 「计划指令【5】」"+ZJBR+HIY+"状态："+NOR+HIR+me->query("env/jhzl5")+NOR+":jh jhzl5"+ZJSEP;
	str += " 「计划指令【6】」"+ZJBR+HIY+"状态："+NOR+HIR+me->query("env/jhzl6")+NOR+":jh jhzl6"+ZJSEP;
	str += " 「计划指令【7】」"+ZJBR+HIY+"状态："+NOR+HIR+me->query("env/jhzl7" )+NOR+":jh jhzl7"+ZJSEP;
	str += " 「计划指令【8】」"+ZJBR+HIY+"状态："+NOR+HIR+me->query("env/jhzl8")+NOR+":jh jhzl8"+ZJSEP;
	str += " 「计划指令【9】」"+ZJBR+HIY+"状态："+NOR+HIR+me->query("env/jhzl9" )+NOR+":jh jhzl9"+ZJSEP;
	str += " 「计划指令【10】」"+ZJBR+HIY+"状态："+NOR+HIR+me->query("env/jhzl10")+NOR+":jh jhzl10"+ZJSEP;
	str += " 「计划指令【11】」"+ZJBR+HIY+"状态："+NOR+HIR+me->query("env/jhzl11" )+NOR+":jh jhzl11"+ZJSEP;
	str += " 「计划指令【12】」"+ZJBR+HIY+"状态："+NOR+HIR+me->query("env/jhzl12")+NOR+":jh jhzl12"+ZJSEP;
	//str +=" 「计划结束循环」"+HIY+"状态"+NOR+HIR+query("jhjs", me )+NOR+":set jhjs LOOP"+ZJSEP;
	str +=" 「设定计划」:jh sdjh"+ZJSEP;
	str +=" 「开始计划」:jihua start"+ZJSEP;
	//str += "\n";
	 

	
	write(str+"\n");
		}
	if(arg == "sdjh")
	{
		
	//tee = implode(scc, "\n") + "\n";
	me->set("schedule", "REPEAT"+"\n"+
	me->query("env/jhzl1" )+"\n"+
	me->query("env/jhzl2")+"\n"+
	me->query("env/jhzl3")+"\n"+
	me->query("env/jhzl4" )+"\n"+
	me->query("env/jhzl5")+"\n"+
	me->query("env/jhzl6")+"\n"+
	me->query("env/jhzl7" )+"\n"+
	me->query("env/jhzl8")+"\n"+
	me->query("env/jhzl9")+"\n"+
	me->query("env/jhzl10" )+"\n"+
	me->query("env/jhzl11" )+"\n"+
	me->query("env/jhzl12")+"\n"+
	"LOOP");
	write(me->query("schedule" )+"\nok\n");
	}
	if(arg == "jhzl1")
	{
	write(INPUTTXT("请输入你想设置「计划指令【1】」的指令","set jhzl1 $txt#")+"\n");
	//return 0;
	}
	if(arg == "jhzl2")
	{write(INPUTTXT("请输入你想设置「计划指令【2】」的指令","set jhzl2 $txt#")+"\n");
	//return 1;
	}
	if(arg == "jhzl3")
	{
	write(INPUTTXT("请输入你想设置「计划指令【3】」的指令","set jhzl3 $txt#")+"\n");
	//return 1;
	}
	if(arg == "jhzl4")
	{
	write(INPUTTXT("请输入你想设置「计划指令【4】」的指令","set jhzl4 $txt#")+"\n");
//	return 1;
	}
	if(arg == "jhzl5")
	{
	write(INPUTTXT("请输入你想设置「计划指令【5】」的指令","set jhzl5 $txt#")+"\n");
	//return 1;
	}
	if(arg == "jhzl6")
	{
	write(INPUTTXT("请输入你想设置「计划指令【6】」的指令","set jhzl6 $txt#")+"\n");
	//return 1;
	}
	if(arg == "jhzl7")
	{
	write(INPUTTXT("请输入你想设置「计划指令【7】」的指令","set jhzl7 $txt#")+"\n");
	//return 1;
	}
	if(arg == "jhzl8")
	{
	write(INPUTTXT("请输入你想设置「计划指令【8】」的指令","set jhzl8 $txt#")+"\n");
	//return 1;
	}
	if(arg == "jhzl9")
	{
	write(INPUTTXT("请输入你想设置「计划指令【9】」的指令","set jhzl9 $txt#")+"\n");
	//return 1;
	}
	if(arg == "jhzl10")
	{
	write(INPUTTXT("请输入你想设置「计划指令【10】」的指令","set jhzl10 $txt#")+"\n");
	//return 1;
	}
	if(arg == "jhzl11")
	{
	write(INPUTTXT("请输入你想设置「计划指令【11】」的指令","set jhzl11 $txt#")+"\n");
	//return 1;
	}
	if(arg == "jhzl12")
	{
	write(INPUTTXT("请输入你想设置「计划指令【12】」的指令","set jhzl12 $txt#")+"\n");
	//write(ZJFORCECMD("jh"));
	//return 1;
	}
	
	
	
       
	
   //str += "\n";
       

   return 1;
}

int help(object me)
{
	write(@HELP
指令格式 :walk <地图名字>

      快捷走路。
see also : hp

HELP
    );
    return 1;
}
