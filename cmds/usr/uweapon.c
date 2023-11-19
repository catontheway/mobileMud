#include <ansi.h>
int main(object me, string arg)
{
	string info,name,id,file,infoa,infob;
  object weapon,newob,oldob;
	object obj, who, *inv, obj2;
	int i, amount;
	string str;
	
	
    if(me->is_busy())
        return notify_fail("你现在正忙。\n");
	str = ZJOBLONG"\n";
	str += ZJOBACTS2+ZJMENUF(1,1,10,30);

if (!arg)
{
	
	str += sprintf(HIW"                              "HIY+me->query("name")+""HIM"武器列表     :uweapon"ZJSEP);
  file = "/p/residence/weapon/"+me->query("id")+"_w1.c";
  newob=load_object(file);
	if( newob)
	{
	
	str += sprintf(HIG"武器_w1"+HIB" %s"NOR":uweapon w1"ZJSEP,newob->query("name")+"("+newob->query("id")+")");
	}
	else 
	str += sprintf(HIG"武器_w1"+HIB" 无"NOR":uweapon"ZJSEP);

  file = "/p/residence/weapon/"+me->query("id")+"_w2.c";
  newob=load_object(file);
	if( newob)
	{
	
	str += sprintf(HIG"武器_w2"+HIB" %s"NOR":uweapon w2"ZJSEP,newob->query("name")+"("+newob->query("id")+")");
	}
	else 
	str += sprintf(HIG"武器_w2"+HIB" 无"NOR":uweapon"ZJSEP);
		
		
  file = "/p/residence/weapon/"+me->query("id")+"_w3.c";
  newob=load_object(file);

	if( newob)
	{
	
	str += sprintf(HIG" 武器_w3"+HIB" %s"NOR":uweapon w3"ZJSEP,newob->query("name")+"("+newob->query("id")+")");
	}
	else 
	str += sprintf(HIG" 武器_w3"+HIB" 无"NOR":uweapon"ZJSEP);

file = "/p/residence/weapon/"+me->query("id")+"_w4.c";
  newob=load_object(file);
	if( newob)
	{
	
	str += sprintf(HIG" 武器_w4"+HIB" %s"NOR":uweapon w4"ZJSEP,newob->query("name")+"("+newob->query("id")+")");
	
	}
	else 
	str += sprintf(HIG" 武器_w4"+HIB" 无"NOR":uweapon"ZJSEP);

file = "/p/residence/weapon/"+me->query("id")+"_w5.c";
  newob=load_object(file);
	
	
if( newob)
	{
	
	str += sprintf(HIG" 武器_w5"+HIB" %s"NOR":uweapon w5"ZJSEP,newob->query("name")+"("+newob->query("id")+")");
	}
	else 
	str += sprintf(HIG" 武器_w5"+HIB" 无"NOR":uweapon"ZJSEP);


	

		
	
	str += sprintf(HIW"                              "HIY+me->query("name")+""HIM" 防具列表     :uweapon"ZJSEP);

  file = "/p/residence/weapon/"+me->query("id")+"_a1.c";
  newob=load_object(file);
	if( newob)
	{
	
	str += sprintf(HIG" 防具_a1"+HIB" %s"NOR":uweapon a1"ZJSEP,newob->query("name")+"("+newob->query("id")+")");
	}
	else 
	str += sprintf(HIG" 防具_a1"+HIB" 无"NOR":uweapon"ZJSEP);


  file = "/p/residence/weapon/"+me->query("id")+"_a2.c";
  newob=load_object(file);
	if( newob)
	{
	
	str += sprintf(HIG" 防具_a2"+HIB" %s"NOR":uweapon a2"ZJSEP,newob->query("name")+"("+newob->query("id")+")");
	}
	else 
	str += sprintf(HIG" 防具_a2"+HIB" 无"NOR":uweapon"ZJSEP);
		
		
  file = "/p/residence/weapon/"+me->query("id")+"_a3.c";
  newob=load_object(file);
	if( newob)
	{
	
	str += sprintf(HIG" 防具_a3"+HIB" %s"NOR":uweapon a3"ZJSEP,newob->query("name")+"("+newob->query("id")+")");
	}
	else
	str += sprintf(HIG" 防具_a3"+HIB" 无"NOR":uweapon"ZJSEP);


		
  file = "/p/residence/weapon/"+me->query("id")+"_a4.c";
  newob=load_object(file);
	if( newob)
	{
	
	str += sprintf(HIG" 防具_a4"+HIB" %s"NOR":uweapon a4"ZJSEP,newob->query("name")+"("+newob->query("id")+")");
	}
	else 
   str += sprintf(HIG" 防具_a4"+HIB" 无"NOR":uweapon"ZJSEP);
	
		
  file = "/p/residence/weapon/"+me->query("id")+"_a5.c";
  newob=load_object(file);
	if( newob)
	{
	
	str += sprintf(HIG" 防具_a5"+HIB" %s"NOR":uweapon a5"ZJSEP,newob->query("name")+"("+newob->query("id")+")");
	}
	else 	
	str += sprintf(HIG" 防具_a5"+HIB" 无"NOR":uweapon"ZJSEP);
		
  file = "/p/residence/weapon/"+me->query("id")+"_a6.c";
  newob=load_object(file);
	if( newob)
	{
	
	str += sprintf(HIG" 防具_a6"+HIB" %s"NOR":uweapon a6"ZJSEP,newob->query("name")+"("+newob->query("id")+")");
	}
	else 
	 str += sprintf(HIG" 防具_a6"+HIB" 无"NOR":uweapon"ZJSEP);

  file = "/p/residence/weapon/"+me->query("id")+"_a7.c";
  newob=load_object(file);
	if( newob)
	{
	
	str += sprintf(HIG" 防具_a7"+HIB" %s"NOR":uweapon a7"ZJSEP,newob->query("name")+"("+newob->query("id")+")");
	}
	else 
	str += sprintf(HIG" 防具_a7"+HIB" 无"NOR":uweapon"ZJSEP);

  file = "/p/residence/weapon/"+me->query("id")+"_a8.c";
  newob=load_object(file);
	if( newob)
	{
	
	str += sprintf(HIG" 防具_a8"+HIB" %s"NOR":uweapon a8"ZJSEP,newob->query("name")+"("+newob->query("id")+")");
	}
	else
	str += sprintf(HIG" 防具_a8"+HIB" 无"NOR":uweapon"ZJSEP);

  file = "/p/residence/weapon/"+me->query("id")+"_a9.c";
  newob=load_object(file);
	if( newob)
	{
	
	str += sprintf(HIG" 防具_a9"+HIB" %s"NOR":uweapon a9"ZJSEP,newob->query("name")+"("+newob->query("id")+")");
	}
	else
	str += sprintf(HIG" 防具_a9"+HIB" 无"NOR":uweapon"ZJSEP);

  file = "/p/residence/weapon/"+me->query("id")+"_a10.c";
  newob=load_object(file);
	if( newob)
	{
	
	str += sprintf(HIG" 防具_a10"+HIB" %s"NOR":uweapon a10"ZJSEP,newob->query("name")+"("+newob->query("id")+")");
	}
	else 
	str += sprintf(HIG" 防具_a10"+HIB" 无"NOR":uweapon"ZJSEP);

	
	str += sprintf(HIW"                      "HIM" ☆ 武器系统 ☆      :uweapon"ZJSEP);
	tell_object(me,str+"\n");
//me->start_busy(1);
}
else
{
  file = "/p/residence/weapon/"+me->query("id")+"_"+arg+".c";
	newob=load_object(file);
	if (!newob)
	return notify_fail("没有这个代码的自造武器。\n");

	if (newob)
{
oldob=present(newob->query("id"),me);
if (oldob && oldob->query("makeritem")==1  && oldob->query("ownmake")==1)
{
message_vision(HIG "$N双手一收 一"+newob->query("unit")+newob->query("name")+"("+newob->query("id")+")"+HIG" 消失在了虚空中。\n" NOR, me);
	 destruct(oldob);


	inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
if (base_name(inv[i])+".c"==file)
	 destruct(inv[i]);

}

}
else
{
message_vision(HIR "$N双手一展 一"+newob->query("unit")+newob->query("name")+"("+newob->query("id")+")"+HIR" 从虚空中出现在$N身上。\n" NOR, me);
newob=load_object(file);
newob->move(me);
newob->set("bowner",me->query("id"));
}
}
//me->start_busy(3);
}		
return 1;
}
int help(object me)
{  
write(@HELP
指令格式: 
	uweapon 查看你所拥有的武器。
	uweapon 代码 召唤你所拥有的武器。
HELP
   );   
return 1;
}                                                                             