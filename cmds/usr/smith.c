#include <ansi.h>
mapping *products(object me)
{
	return SMITH->smith(me);
}
int main(object me, string arg)
{
	mapping *products=products(me);
	string lu_msg,msg="\n";
	if (!arg)
	{
		msg = ZJOBLONG+HIW+"你可打造的装备有：\n"NOR+ZJOBACTS2+ZJMENUF(1,1,4,35);
		for (int i=0;i<sizeof(products);i++)
		{
			msg+=sprintf(HIW"%s"+ZJBR+"温度需要："+products[i]["temperature"]+ZJBR+"基础失败概率："+products[i]["fail_possibility"]+ZJBR+"开始等级："+products[i]["maker_level"]+ZJBR+"锤炼次数："+products[i]["hammer_require"]+" 次。"+ZJBR+"随着锻造术级别的提升，锻造"+products[i]["name"]+"的失败概率下降；随着材料的提升，锻造"+products[i]["name"]+"的失败概率升高。"+NOR+":smith "+products[i]["name"]+ZJSEP,products[i]["name"]);
			if (i==sizeof(products)-1)
			msg+="";
			else
			msg+="";
		}
		write(msg+"\n");
		return 1;
	}
	else
	{
		for (int i=0;i<sizeof(products);i++)
		if (products[i]["name"]==arg)
		{
			write("『"+HIC+arg+NOR+"』温度需要："+products[i]["temperature"]+"|基础失败概率："+products[i]["fail_possibility"]+"%|开始等级："+U+(products[i]["maker_level"])+NOR+" 级|锤炼次数："+U+(products[i]["hammer_require"])+NOR+" 次。\n");
			write("随着锻造术级别的提升，锻造"+arg+"的失败概率下降；随着材料的提升，锻造"+arg+"的失败概率升高。\n");
			return 1;
		}
	}
	write("『"+arg+"』并不存在，或你并未掌握打造这种装备的方法。\n");
	return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : smith
用这个指令可以查询你可以打造的所有装备。
smith <装备>
用这着指令可以查询你需要打造装备的具体细节。
HELP
);
        return 1;
}

