//inventory.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int i,j,all,page;
	object *inv, bao,ob;
	mapping count;
	mapping equiped;
	mapping unit;
	mapping ids;
	mapping itype;
	string *text,pops,short_name,stk;
	int    total_item;
	
	string str,sss;
	string *dk=({});

	if( !arg )
	{
		page = 1;
	}
	else if(sscanf(arg,"%d %s",page,arg)!=2)
	{
		page = 1;
	}

	if (wizardp(me) && arg)
	{
		ob = find_player(arg);
		if (! ob) ob = find_living(arg);
		if (! ob) ob = present(arg, environment(me));
		if (! ob) return notify_fail("没有这个玩家。\n");
	}

	if (! ob) ob = me;

	inv = all_inventory(ob);
	if (! sizeof(inv))
	{
		write(ZJOBLONG+((ob == me) ? "你共有"HIY+ob->query("jhxk")+"点侠客积分"NOR"。目前你身上没有任何东西。\n" : ob->query("jhxk")+"身上没有携带任何东西。\n"));
		return 1;
	}
	
	for (i = 0; i < sizeof(inv); i++)
	{
		short_name = inv[i]->query("name");
//		short_name = inv[i]->query("name")+ZJBR+inv[i]->query("id");
		if(inv[i]->query_amount())
			short_name = inv[i]->query_amount() + inv[i]->query("base_unit") + short_name;
         
		sss = short_name;
		if (inv[i]->query("equipped"))
			sss = HIG"■"NOR+sss;
		else sss = " "+sss;
			
		
		
			pops = ZJPOPMENU+ZJMENUF(1,1,9,30);
			pops += "查看"+sss+"|look "+inv[i]->query("id")+ZJSP2;
			if (inv[i]->query("equipped")&&inv[i]->query("weapon_prop"))	
			pops += "放下"+sss+"|unwield "+inv[i]->query("id")+ZJSP2;
			else if (inv[i]->query("equipped")&&inv[i]->query("armor_prop"))
            pops += "脱掉"+sss+"|remove "+inv[i]->query("id")+ZJSP2;
			else if (inv[i]->query("weapon_prop"))	
			pops += "装备"+sss+"|wield "+inv[i]->query("id")+ZJSP2;
			else if (inv[i]->query("armor_prop"))	
			pops += "穿戴"+sss+"|wear "+inv[i]->query("id")+ZJSP2;
		    else if (inv[i]->query("skill"))
			pops += "研读"+sss+"|study "+inv[i]->query("id")+ZJSP2;
			else if(inv[i]->is_book())	
			pops += "研读"+sss+"|study "+inv[i]->query("id")+ZJSP2;
			else if (inv[i]->is_szj())
			pops += "研读"+sss+"|yandu "+inv[i]->query("id")+ZJSP2;
			//else if (inv[i]->is_bao())
			
			else if (!inv[i]->query("skill") || !inv[i]->query("weapon_prop") || !inv[i]->query("armor_prop") || !inv[i]->is_szj() || !inv[i]->is_bao())
			{
				pops += "使用"+sss+"|use "+inv[i]->query("id")+ZJSP2;
			pops += "吃"+sss+"|eat "+inv[i]->query("id")+ZJSP2;
			pops += "喝"+sss+"|drink "+inv[i]->query("id")+ZJSP2;
			}
		
		    pops += "展示"+sss+"|showitem "+inv[i]->query("id")+ZJSP2;
			 pops += "合并升级"+sss+"|combine "+inv[i]->query("id")+ZJSP2;
			pops += "存入"+sss+"|mystore put "+inv[i]->query("id")+ZJSP2;
		    pops += "当"+sss+"|mpawn "+inv[i]->query("id")+ZJSP2;
			pops += "丢弃"+sss+"|drop "+inv[i]->query("id")+ZJSP2;
		
		 dk += ({  sprintf("%s"NOR":%s", sss,pops)});
		 
	write(str+"\n");
		
	}
	text = sort_array(dk, 1);

	str = ZJOBLONG+sprintf("%s共有"HIY"%d点侠客积分。"NOR+ZJBR"身上带著下列这些东西(%d件，负重 %d%%)：\n",
		      (ob == me)? "你" : ob->name(),ob->query("jhxk"),sizeof(text),
		      (int)ob->query_encumbrance() * 100 / (int)ob->query_max_encumbrance());

	

	
	str += ZJOBACTS2+ZJMENUF(3,3,8,35);
	str += "穿戴全部:wear all"+ZJSEP"装备全部:wield all"+ZJSEP"脱下全部:remove all"+ZJSEP;
	all = sizeof(text)/20;
	if(sizeof(text)%20) all += 1;
	if(page<1) page = 1;
	if(page>all) page = all;
	j = (page-1)*20;
	i = page*20;
	if (i >= sizeof(text)) i = sizeof(text);
	i--;
	if(all>1)
		str += "上一页:inventory "+(page-1)+" "+ob->query("id")+ZJSEP"下一页:inventory "+(page+1)+" "+ob->query("id")+ZJSEP;
	str += implode(text[j..i], ZJSEP);
	
	



	

	
	
	write(str+"\n");
	return 1;
}

int help (object me)
{
	write(@HELP
指令格式: inventory
 
可列出你(你)目前身上所携带的所有物品。
 
注 : 此指令可以 " i " 代替。

HELP );
	return 1;
}