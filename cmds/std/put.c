inherit F_CLEAN_UP;
int do_put(object me, object obj, object dest,int amount);  	
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
	string target, item,str;
object obj, dest, *inv, obj2;      	
	int i, amount;
	if(!arg) return notify_fail("你要将什麽东西放进哪里？\n");
/*
env = present(in, me);        	
if(!env) env = present(in, environment(me));  	
if (env->query("no_put_in") && !wizardp(me))	
return notify_fail("你不能在"+env->query("name")+"里放入任何东西。\n");	
*/
	if (sscanf(arg, "%s in %s", item, target) != 2 )

	{
		inv = all_inventory(me);
		if (!sizeof(inv))
		{
			write(ZJOBLONG"你身上什么都没有，哪来东西放？\n");
			return 1;
		}
		write(ZJOBLONG"请选择你要向容器放入的物品：\n");
		str = ZJOBACTS2+ZJMENUF(2,2,8,30);
		//for (i=sizeof(inv)-1;i>=0;i--)
                for (i = 0; i < sizeof(inv); i++)
                {
                
                str += inv[i]->query("name")+ZJBR+inv[i]->query("id")+":put "+ inv[i]->query("id")+" in "+arg + ZJSEP;
		
                } 
                         
			 write(str+"\n");	
                                
			return 1;
        }        
	dest = present(target, me);
	if( !dest || living(dest) ) dest = present(target, environment(me));
	if( !dest || living(dest) )
		return notify_fail("这里没有这样东西。\n");
	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("你身上没有这样东西。\n");
		if( amount < 1 )
			return notify_fail("东西的数量至少是一个。\n");
		if( obj->query_amount() ){
			if( amount > obj->query_amount() )
			return notify_fail("你没有那麽多的" + obj->name() + "。\n");
			else if( amount == (int)obj->query_amount() )
			return do_put(me, obj, dest,1);
			else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			return do_put(me, obj2, dest,1);
			return 1;
			}
		}else   { do_put(me, obj, dest,amount);return 1;}
	}
	if(item=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			if( inv[i] != dest ) do_put(me, inv[i], dest,1);
		write("Ok.\n");
		return 1;
	}
	if(!objectp(obj = present(item, me)))
		return notify_fail("你身上没有这样东西。\n");
	return do_put(me, obj, dest,1);
}
int do_put(object me, object obj, object dest,int amount)
{
	string str,arg;
	int i;
        if(obj->query("id")!="thousand-gold"&&(obj->query("no_drop") || obj->query("no_put")))
  return notify_fail(obj->name()+"不能放进"+dest->name()+"里。\n");
if (obj->query("no_put"))
return notify_fail("这样东西不能放入任何容器。\n"); 	
if (userp(obj))
	return notify_fail("这样东西不能放入任何容器。\n"); 	
	if (obj==dest)	return notify_fail("嘻嘻，这样也行？\n");
if(dest->query("no_put"))
return notify_fail("你不能在"+dest->name()+"里放入任何东西。\n"); 
if ( userp(me) && me->query_condition("killer") )
		return notify_fail("你目前正被通缉着，把东西都装一个容器里容易引人注意。\n");
	str=obj->query("id");
	arg=obj->query("unit")+obj->name();
	for (i=0;i<amount;i++){
		if( obj->move(dest) ) {
                if (dest->query("no_put") && obj ) 
                  destruct(obj);
			if(!objectp(obj = present(str, me))) {i++;break;}
		}else{	tell_object(me,obj->name()+"对"+dest->name()+"而言太重了。\n");
			if (!obj->move(me))	obj->move(environment(me));
			return 1;}
	}
	if( !dest->is_character() || dest->is_corpse() ){
		dest->add("no_clean_up",1);
		message_vision( sprintf("$N将%s%s放进%s。\n",
		CHINESE_D->chinese_number(i),arg,dest->name()),me );
	}else{
		message_vision( sprintf("$N偷偷地将%s%s放进%s的身上。\n",
		CHINESE_D->chinese_number(i),arg,dest->name()),me );
	}
	return 1;
}
int help(object me)
{
write(@HELP
指令格式 : put <物品名称> in <某容器>
 
这个指令可以让你将某样物品放进一个容器，当然，首先你要拥有这样物品。
 
HELP
    );
    return 1;
}
