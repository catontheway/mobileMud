#include <ansi.h>
int main(object me, string arg)
{
	string info,name,id,file,infoa,infob;
  object weapon,newob;

    if(me->is_busy())
        return notify_fail("你现在正忙。\n");

if (!arg)
{
	printf(HIY+me->query("name")+""HIM" 打造武器列表"HIY"\n"HIW"----------------------------------------------\n"NOR);
  file = "/p/residence/weapon/"+me->query("id")+"_w1.c";
  newob=load_object(file);
	if( newob)
	{
	printf(HIG"代码w1 打造武器:"+HIB" %s\n"NOR,newob->query("name")+"("+newob->query("id")+")");
	}
	else printf(HIG"代码w1 打造武器:"+HIB" 无\n"NOR);

  file = "/p/residence/weapon/"+me->query("id")+"_w2.c";
  newob=load_object(file);
	if( newob)
	{
	printf(HIG"代码w2 打造武器:"+HIB" %s\n"NOR,newob->query("name")+"("+newob->query("id")+")");
	}
	else printf(HIG"代码w2 打造武器:"+HIB" 无\n"NOR);
		
		
  file = "/p/residence/weapon/"+me->query("id")+"_w3.c";
  newob=load_object(file);
	if( newob)
	{
	printf(HIG"代码w3 打造武器:"+HIB" %s\n"NOR,newob->query("name")+"("+newob->query("id")+")");
	}
	else printf(HIG"代码w3 打造武器:"+HIB" 无\n"NOR);
		
	printf(HIY+me->query("name")+""HIM" 打造防具列表"HIY"\n"NOR);

  file = "/p/residence/weapon/"+me->query("id")+"_a1.c";
  newob=load_object(file);
	if( newob)
	{
	printf(HIG"代码a1 打造防具:"+HIB" %s\n"NOR,newob->query("name")+"("+newob->query("id")+")");
	}
	else printf(HIG"代码a1 打造防具:"+HIB" 无\n"NOR);


  file = "/p/residence/weapon/"+me->query("id")+"_a2.c";
  newob=load_object(file);
	if( newob)
	{
	printf(HIG"代码a2 打造防具:"+HIB" %s\n"NOR,newob->query("name")+"("+newob->query("id")+")");
	}
	else printf(HIG"代码a2 打造防具:"+HIB" 无\n"NOR);
		
		
  file = "/p/residence/weapon/"+me->query("id")+"_a3.c";
  newob=load_object(file);
	if( newob)
	{
	printf(HIG"代码a3 打造防具:"+HIB" %s\n"NOR,newob->query("name")+"("+newob->query("id")+")");
	}
	else printf(HIG"代码a3 打造防具:"+HIB" 无\n"NOR);		


		
  file = "/p/residence/weapon/"+me->query("id")+"_a4.c";
  newob=load_object(file);
	if( newob)
	{
	printf(HIG"代码a4 打造防具:"+HIB" %s\n"NOR,newob->query("name")+"("+newob->query("id")+")");
	}
	else printf(HIG"代码a4 打造防具:"+HIB" 无\n"NOR);		
		
  file = "/p/residence/weapon/"+me->query("id")+"_a5.c";
  newob=load_object(file);
	if( newob)
	{
	printf(HIG"代码a5 打造防具:"+HIB" %s\n"NOR,newob->query("name")+"("+newob->query("id")+")");
	}
	else printf(HIG"代码a5 打造防具:"+HIB" 无\n"NOR);		
		
  file = "/p/residence/weapon/"+me->query("id")+"_a6.c";
  newob=load_object(file);
	if( newob)
	{
	printf(HIG"代码a6 打造防具:"+HIB" %s\n"NOR,newob->query("name")+"("+newob->query("id")+")");
	}
	else printf(HIG"代码a6 打造防具:"+HIB" 无\n"NOR);		

  file = "/p/residence/weapon/"+me->query("id")+"_a7.c";
  newob=load_object(file);
	if( newob)
	{
	printf(HIG"代码a7 打造防具:"+HIB" %s\n"NOR,newob->query("name")+"("+newob->query("id")+")");
	}
	else printf(HIG"代码a7 打造防具:"+HIB" 无\n"NOR);		

  file = "/p/residence/weapon/"+me->query("id")+"_a8.c";
  newob=load_object(file);
	if( newob)
	{
	printf(HIG"代码a8 打造防具:"+HIB" %s\n"NOR,newob->query("name")+"("+newob->query("id")+")");
	}
	else printf(HIG"代码a8 打造防具:"+HIB" 无\n"NOR);												

  file = "/p/residence/weapon/"+me->query("id")+"_a9.c";
  newob=load_object(file);
	if( newob)
	{
	printf(HIG"代码a9 打造防具:"+HIB" %s\n"NOR,newob->query("name")+"("+newob->query("id")+")");
	}
	else printf(HIG"代码a9 打造防具:"+HIB" 无\n"NOR);		


	printf(HIW"---------"HIM" ☆ 星月传奇打造武器系统 ☆ "HIW"------------\n"NOR);
me->start_busy(1);
}
else
{
  file = "/p/residence/weapon/"+me->query("id")+"_"+arg+".c";
	newob=load_object(file);
	if (!newob)
	return notify_fail("没有这个代码的自造武器。\n");

	if (newob)
{
message_vision(HIR "$N双手一展 一"+newob->query("unit")+newob->query("name")+"("+newob->query("id")+")"+HIR" 从虚空中出现在$N身上。\n" NOR, me);
if (present(newob->query("id"),me)) destruct(present(newob->query("id"),me));
newob=load_object(file);
newob->move(me);
}
me->start_busy(3);
}		
return 1;
}
int help(object me)
{  
write(@HELP
指令格式: 
	uweapon 查看你所拥有的打造武器。
	uweapon 代码 召唤你所拥有的打造武器。
HELP
   );   
return 1;
}