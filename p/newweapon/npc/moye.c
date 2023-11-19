// moye.c  莫邪
// Written by Doing Lu  1998/11/2
//输入参数 类别, 材料1,材料2,材料3,名称,ID
inherit NPC;
//inherit F_NOCLONE;

#include <ansi.h>
inherit __DIR__"user_weapond.c";
int	ask_me();
//int	ask_me2();
int	no_money();


mapping item_type = ([
"剑":"SWORD", 
"刀":"BLADE", 
"锤":"HAMMER", 
"鞭":"WHIP", 
"棍":"CLUB", 
"杖":"STAFF",  
"暗器":"THROWING",  
"匕首":"DAGGER", 
"斧":"AXE",
"手套":"HANDS", 
"服装":"CLOTH", 
"披风":"ARMOR", 
"靴子":"BOOTS", 
"头盔":"HEAD",
"项链":"NECK",
"肚带":"SURCOAT",
"盾牌":"SHIELD", 
"腰带":"WAIST", 
"护腕":"WRISTS",
]);


string *typeshi2=({
RED"鸡血石"NOR,
HIC"青田石"NOR,
MAG"芙蓉石"NOR,
WHT"寿山石"NOR,
GRN"蛇纹石"NOR,
HIG"尖晶石"NOR,
HIM"孔雀石"NOR,
HIB"碧玺石"NOR,
HIY"金刚石"NOR,
});

string *typeshi1=({
HIY"金"NOR,
CYN"木"NOR,
GRN"水"NOR,
RED"火"NOR,
YEL"土"NOR,
HIM"风"NOR,
HIW"雷"NOR,
HIB"电"NOR,
WHT"天"NOR,
BBLK"地"NOR,
HIC"人"NOR,
HIR"魔"NOR,
HIC"天灵"NOR,
CYN"天宇"NOR,
YEL"福源"NOR,
RED"绝代"NOR,
GRN"天渊"NOR,
HIG"天玄"NOR,
WHT"白石"NOR,
MAG"紫石"NOR,
HIC"闪电"NOR,
HIW"巧制"NOR,
HIR"体灵"NOR,
YEL"周天"NOR,
HIY"长生"NOR,
HIG"不老"NOR,
GRN"不灭"NOR,
BLU"威力"NOR,
});

void create()
{
	set_name("莫邪", ({ "mo ye", "moye", "mo" }));
	set("long", "她长得清美秀丽，一副不食人间烟火的模样。她就是铸剑大师干将的妻子。\n" );

	set("nickname", HIY "剑仙" NOR);
	set("gender", "女性");
	set("attitude", "friendly");
  set("qi",100000);
  set("jing",100000);
  set("max_qi",100000);
  set("max_jing",100000);
  
  set("neili",100000);
  set("max_neili",100000);

	set("combat_exp",9000000);
	set("age", 25);
	set("per", 30);
	set("shen_type", 0);
	set_skill("sword",1000);
//set_skill("ai-sword",1000);
//map_skill("sword", "ai-sword");
	set("str", 2000);			// 保证不会因为负荷过大而接受不了东西

	set("inquiry", ([
		"dazao" : (: ask_me :),
		"打造准备" : (: ask_me :),
		"没钱" : (: no_money :),
		"原料" : "炼制道具可不能没有原料啊，要想炼制好武器就得有"
                         "玄铁石一类的东西。\n          要想炼制好防具就"
                         "得有天蚕丝那些东西。这些原料很难找，可遇不可求啊！\n",
		"价格" : "打造需要一千两黄金定金。",
		"名字" : "你可以用(setname)来指定打造品的名称。",	
		"颜色" : "你可以用(setcolor)来指定打造品的名称。",	
	]));

        setup();

        set("startroom", "/d/item/jianchang");
  //      check_clone();
        if (! this_object()) return;

carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object me;

	// 清除询问标志
        if (! objectp(me = this_player()) || ! interactive(me))
                return;

	add_action("do_show", "show");
  add_action("do_answer", "answer");
  add_action("do_answer2", "setnumber");
  add_action("do_answer3", "setname");
  add_action("do_answer4", "setcolor");
	if (me->query_temp("item/status") == "item_gived")
	{
		remove_call_out("greeting2");
		call_out("greeting2", 1, me);
	} else
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me);
	}
}

void greeting(object me)
{
	if (objectp(me) && environment(me) == environment())
	{
		message_vision("$N笑着对$n说：你好，你是想打造道具"
                               "吗？\n", this_object(), me);
	}
}

void greeting2(object me)
{
	if (objectp(me) && environment(me) == environment())
	{
		message_vision("$N对$n说：交钱就可以打造了哦。\n",
                               this_object(), me);
	}
}

int do_show(string arg)
{
	object	me;
	object	ob,ob1;
	string	msg;
        string  mat;
	int	i,power_point;
	int	value;
	int	n;
mapping type;


	string type2,str;
	string type1;
	string name;
	object *inv;
	me = this_player();
	if (! arg)
        {
 inv = filter_array(all_inventory(me),(:$1->query("material_attrib"):));
		if (!sizeof(inv))
		{
			write(ZJOBLONG"你身上没有材料\n");
			return 1;
		}
		write(ZJOBLONG"请选择你材料：\n");
		str = ZJOBACTS2+ZJMENUF(2,2,8,30);
		for (i = 0; i < sizeof(inv); i++)
		{
	
			if(inv[i]->query_amount())
					str += inv[i]->query_amount()+inv[i]->query("base_unit")+inv[i]->query("name")+ZJBR+inv[i]->query("id")+":show "+inv[i]->query("id") + ZJSEP;
				else
					str += inv[i]->query("name")+ZJBR+inv[i]->query("id")+":show "+inv[i]->query("id") + ZJSEP;
			
		}
		write(str+"\n");
		return 1;       
}	

        mat = arg;
	power_point = 0;

	if (! objectp(ob = present(mat, me)))
		return notify_fail("算了吧，你身上没有 " + mat + " 这种东西。\n");



if ( ob->query("upyushi"))
{

	if ( me->query_temp("item/upyushi"))
		return notify_fail("你已经给了改造材料"+me->query_temp("item/upyushin")+"。\n");

	if (! me->query_temp("paid/moye2"))
		return notify_fail("算了吧，你先给订金吧。\n");


if (ob->query("upyushilb")) me->set_temp("item/upyushilb",ob->query("upyushilb"));
if (ob->query("upyushilv")) me->set_temp("item/upyushilv",ob->query("upyushilv"));
if (ob->query("upyushi")) me->set_temp("item/upyushi",ob->query("id"));
if (ob->query("upyushi")) me->set_temp("item/upyushin",ob->query("name"));

type2=typeshi2[ob->query("upyushilb")];
type1=typeshi1[ob->query("upyushilv")];
name=type1+"之"+type2;

	message_vision("$N对$n说道：" 
		"你是要改造的材料是" + name + "吧！\n",
 this_object(), this_player());
me->set_temp("paid/moye2",0);
me->delete_temp("paid/moye2");
destruct(ob);
return 1;	
	
}		


	if (! ob->query("material_attrib"))
	{
		message_vision("$N一愣，对$n说道：这种东西也能用来炼"
                               "制，我没听说过。\n", this_object(), me);
		return notify_fail("你想好再来吧。\n");

	}
 if (!me->query_temp("nwtemp") && !me->query_temp("natemp"))
                {
                        message_vision("$N摇摇头，对$n说：快说你要做什么东西！\n",
                                       this_object(), me);
		return notify_fail("你想好再来吧。\n");

                }


 if (me->query_temp("nwtemp") )
                {
if ( !ob->query("kuangshi") && !ob->query("wyushi"))
{
                        message_vision("$N摇摇头，对$n说：做武器需要矿石两块，如果有条件再加玉一块！\n",
                                       this_object(), me);
		return notify_fail("你想好再来吧。\n");
}
if ( ob->query("kuangshi"))
{
if ( !objectp(ob1 = present(mat+" 2", me)))
{
                        message_vision("$N摇摇头，对$n说：做武器需要相同矿石两块，一块不够！\n",
                                       this_object(), me);
		return notify_fail("你想好再来吧。\n");
}
}

}

if (me->query_temp("natemp") )
                {
if ( !ob->query("kuangshi") && !ob->query("ayushi")  && !ob->query("buliao"))
{
                        message_vision("$N摇摇头，对$n说：做武器需要矿石一块，布料一块，如果有条件再加玉一块！\n",
                                       this_object(), me);
		return notify_fail("你想好再来吧。\n");
}
                }

if (ob->query("kuangshi")) me->set_temp("item/kuangshi",ob->query("material"));
if (ob->query("buliao")) me->set_temp("item/buliao",ob->query("material"));
if (ob->query("ayushi")) me->set_temp("item/ayushi",ob->query("id"));
if (ob->query("wyushi")) me->set_temp("item/wyushi",ob->query("id"));	

if (me->query_temp("nwtemp")) type=TYPE1[me->query_temp("nwtemp")-1];
if (me->query_temp("natemp")) type=TYPE2[me->query_temp("natemp")-1];

        msg = sprintf("$N仔细看了看$n拿出的原料，说道：这种原料打造道具，\n" +
	              "是可以打造道具的，要是没问题"
                      "，请找我丈夫打造吧。\n", chinese_number(value));
	message_vision(msg, this_object(), me);
	message_vision("$N对$n说道：" 
		"你是要打造" + type["TYPE3"] + "吧！\n"
		"你现在的准备情况如下:\n"
		"打造用矿石："+MDESC_WEAPON[me->query_temp("item/kuangshi")]+"\n"
		"防具用布料: "+MDESC_ARMOR[me->query_temp("item/buliao")]+"\n"
		"武器用玉石:"+MDESC_WYU[me->query_temp("item/wyushi")]+"\n"
    "防具用玉石:"+MDESC_AYU[me->query_temp("item/ayushi")]+"\n",
 this_object(), this_player());
  message_vision(ZJURL("cmds:show")+"选择玉石，布料，或者矿石"NOR"\n",
              this_object(), this_player());
if (ob)
destruct(ob);
if (ob1)
destruct(ob1);
	return 1;
}

// 发出提示信息
int ask_me()
{
	int val,val2;
	string status;
	object me = this_player();
	// 计算价值
		val = 1000;
		val2 = 1500;
		
		// 价值单位为黄金
		val *= 10000;
        val2 *= 10000;
		
	status = query_temp("item/status");

		
	if (status == "accept")
	{
		if (query_temp("item/player_id") != me->query("id"))
		{
			command("say 我正在和别的客人商量呢，你先别添乱！");
			return 0;
		}

	}
	
	
	message_vision("$N对$n说道：" 
		"你是要打造自己的道具吗？\n"
		"我们这里可以为你打造各种武器和防具，都是第一流的。\n"
		"你先决定打造的类型(answer)。然后决定存放位置(setnumber)。\n"
		"然后把原料给我(show) 原料武器需要 二块原铁 如果有的话最好还有一块玉石。\n"
    "防具需要 一块原铁 一块布料 如果有的话最好还有一块玉石。\n"
		"如果你满意就先付一千两黄金的定金。"
    "咱们就一手交钱，一手交货！\n", this_object(), me);

		message_vision("$N对$n说道：很好，如果打造武器需要" 
                                + "1000两黄金。\n",
			       this_object(), me);

		message_vision("$N对$n说道：但如果改造武器就需要" 
                                + "1500两黄金。\n",
			       this_object(), me);

		if (wizardp(me))
		{
			message_vision("$N仔细看了看$n，笑着说道：原"
                                       "来是巫师，那么你随便给点好了。\n",
                                       this_object(), me);
			
		}
		if ( me->query("nbjob")==33 || me->query("nbjob")==34   )
		{
			if( me->query("nmoneydz",1) <=5)
			{
			message_vision("$N仔细看了看$n，笑着说道：原"
                                       "来是新手来学习，那么你随便给点就好了。\n",
                                       this_object(), me);
		}
		}
	
	
	me->set_temp("item/status", "item_gived");
	set_temp("item/status", "accept");
	set_temp("item/player_id", me->query("id"));
	return 1;
}

int no_money()
{
        object me;
        object ob;

        me = this_player();
	message_vision("$N眼睛一瞪，对$n说道：没钱？你没钱关我啥事，"
                       "我又不是财神爷。\n", this_object(), me);
	return 1;
}

// 接受定金
int accept_object(object me, object ob)
{
        string status,str;
		string *types,lei;
	int  i,val,val2;

        status = query_temp("item/status");
		types = keys(item_type);
		foreach (lei in types)

		
	if (status == "accept")
	{
		if (query_temp("item/player_id") != me->query("id"))
		{
			command("say 我正在和别的客人商量呢，你先别添乱！");
			return 0;
		}

		if (! ob->query("money_id"))
		{
			command("say 你还是快点交钱吧，要是没钱就明说！");
			return 0;
		}
	}

				
		if (ob->query("money_id"))
	{
		
		// 计算价值
		val = 1000;
		val2 = 1200;
		
		// 价值单位为黄金
		val *= 10000;
        val2 *= 12000;
		
		if (wizardp(me))
		{
			val = 1;
			val2 = 200;
		}
		
		if ( me->query("nbjob")==33 || me->query("nbjob")==34   )
		{
			if( me->query("nmoneydz",1) <=5)
		{
			val = 1;
		}
		me->add("nmoneydz",1);
		}
		

		if (me->query_temp("item/status") == "answer_type")
		{
			message_vision("$N摇摇头，对$n说：快说你要做什么东西！\n",
				       this_object(), me);
			return 0;
		}

		if (me->query_temp("item/status") != "item_gived")
		{
			message_vision("$N把$n递过去的" + ob->name() +
				       "推了回来，道：无功不受禄！\n",
				       this_object(), me);
			return 0;
		}

		if (ob->value() < val)
		{
 			message_vision("$N对$n说：对不起，本店开张一"
				       "千多年来，还没有打过折扣。\n",
				       this_object(), me);
			return 0;
		}

		if  (ob->value() < val2)
{   
		str = ZJOBLONG"莫邪对你说：好，这就给你炼！你打算打造什么东西，请告诉我类型：\n"ZJOBACTS2+ZJMENUF(4,4,9,30);
		foreach (lei in types)
        str += lei+":answer "+item_type[lei]+ZJSEP;
		
		write(str+"\n");					   

        me->set_temp("paid/moye", 1);
}
else if  (ob->value() >= 12000000)
{
		message_vision("$N对$n说道：好这就给你改造装备,你先(show) 一下你用来改造的材料,\n"
		"然后找干将改造你的装备吧(duanlian) \n",
                               this_object(), me);
                me->set_temp("paid/moye2", 1);

}		


		me->set_temp("item/status", "answer_type");
		return -1;
	}
		

	message_vision("莫邪眼睛一瞪，对$N说道：你给我这些东西干什么？我不要！\n", me);
	return 0;
}

int do_answer(string arg)
{
        object money;
        object ob;
        object me;
        object ganjiang;
       mapping type;
       string *types,lei,str;

		types = keys(item_type);
		foreach (lei in types)
        me = this_player();
//        if (me->query_temp("item/status") != "answer_type")
//                return 0;
	
        if (! arg)
                return notify_fail("你要回答什么？\n");

        if (! me->query_temp("paid/moye", 1))
        {

                command("say 这...我和夫君也要生活啊。你"
                        "说一千两黄金怎么样？");
                return 1;
        }


me->delete_temp("nwtemp");
me->delete_temp("natemp");
//write(arg);
	switch(arg){
case "SWORD":	me->set_temp("nwtemp",1); break;
case "BLADE":	me->set_temp("nwtemp",2); break;
case "HAMMER":	me->set_temp("nwtemp",3); break;
case "WHIP":	me->set_temp("nwtemp",4); break;
case "CLUB":	me->set_temp("nwtemp",5); break;
case "STAFF":	me->set_temp("nwtemp",6); break;
case "THROWING":	me->set_temp("nwtemp",7); break;
case "DAGGER":	me->set_temp("nwtemp",8); break;
case "AXE":	me->set_temp("nwtemp",9); break;
	}
if (me->query_temp("nwtemp")) type=TYPE1[me->query_temp("nwtemp")-1];
	switch(arg){
case "HANDS":	me->set_temp("natemp",1); break;
case "CLOTH":	me->set_temp("natemp",2); break;
case "ARMOR":	me->set_temp("natemp",3); break;
case "BOOTS":	me->set_temp("natemp",4); break;
case "HEAD":	me->set_temp("natemp",5); break;
case "NECK":	me->set_temp("natemp",6); break;
case "SURCOAT":	me->set_temp("natemp",7); break;
case "SHIELD":	me->set_temp("natemp",8); break;
case "WAIST":	me->set_temp("natemp",9); break;
case "WRISTS":	me->set_temp("natemp",10); break;
	}

if (me->query_temp("natemp")) type=TYPE2[me->query_temp("natemp")-1];

         if (!me->query_temp("nwtemp") && !me->query_temp("natemp"))
{
	str = ZJOBLONG"莫邪对你说：我这没办法打造这类东西，请重新选择类型：\n"ZJOBACTS2+ZJMENUF(4,4,9,30);
		foreach (lei in types)
        str += lei+":answer "+item_type[lei]+ZJSEP;
		
		write(str+"\n");	

                return 0;
}
me->delete_temp("paid/moye");
        message_vision("$N对$n道：知道了,你是要打造" + type["TYPE3"] + "吧！\n",
                       this_object(), me);
tell_object(me,ZJFORCECMD("setnumber"));


	return 1;
}


int do_answer2(string arg)
{
        object money;
        object ob;
        object me;
        object ganjiang;
mapping type;
int i;
    string cmd, temp,str;
    int args, ratio, round;
        me = this_player();
//        if (me->query_temp("item/status") != "answer_type")
//                return 0;
	
        if (! arg)
			 {
               
			   if (me->query_temp("nwtemp"))
			    {  str = ZJOBLONG"你要设定这个道具为第几件：\n"ZJOBACTS2+ZJMENUF(4,4,9,30);
					 for (i = 0; i < 5; i++)
	                     { 
                  str += "打造武器"+chinese_number(i+1)+":setnumber "+(i+1)+ZJSEP;
	                     }	
				write(str+"\n");		 
			   return 1;
			   
			    }
				else if (me->query_temp("natemp")){
					str = ZJOBLONG"你要设定这个道具为第几件：\n"ZJOBACTS2+ZJMENUF(4,4,9,30);
					 for (i = 0; i < 10; i++)
	                     { 
                  str += "打造防具"+chinese_number(i+1)+":setnumber "+(i+1)+ZJSEP;
	                     }	
				write(str+"\n");		 
			   return 1;
			   
	                    }
				else return notify_fail("你想好再来吧。\n");  	
			return 1;	
              }
 if (!me->query_temp("nwtemp") && !me->query_temp("natemp"))
                {
                        message_vision("$N摇摇头，对$n说：快说你要做什么东西！\n",
                                       this_object(), me);
		return notify_fail("你想好再来吧。\n");
        
                }
				
				
				
				

 	if(!arg || (sscanf(arg, "%d", i)!=1 ))
		return notify_fail("你要设定这个道具为第几件，武器可以有5件(1-5)，防具可以有10件(1-10)。\n");
		
// write(i+"");
 
 if (me->query_temp("nwtemp") && ( i >5 || i <1) )
                {
   message_vision("$N摇摇头，对$n说：快说你要做什么！武器可以有5件(1-5) \n",
                                       this_object(), me);
		return notify_fail("你想好再来吧。\n");

                }

 if (me->query_temp("natemp") && ( i > 10 || i <1) )
                {
   message_vision("$N摇摇头，对$n说：快说你要做什么！防具可以有10件(1-10) \n",
                                       this_object(), me);
		return notify_fail("你想好再来吧。\n");

                }
me->set_temp("item/dzwz",i);
        message_vision("$N对$n道：知道了,你是要打造第" + i + "个位置吧！\n",
                       this_object(), me);
tell_object(me,ZJFORCECMD("setname"));


	return 1;
}


int do_answer3(string arg)
{
        object money;
        object ob;
        object me;
        object ganjiang;
mapping type;
int i;
    string cmd, temp;
    int args, ratio, round;
        me = this_player();
//        if (me->query_temp("item/status") != "answer_type")
//                return 0;
	

 if (!me->query_temp("nwtemp") && !me->query_temp("natemp"))
                {
                        message_vision("$N摇摇头，对$n说：快说你要做什么东西！\n",
                                       this_object(), me);
		return notify_fail("你想好再来吧。\n");

                }
        if (! arg)
			 {tell_object(me,INPUTTXT("你要设定这个道具叫什么名字：","setname $txt#\n"));	
		 return 1;
               // return notify_fail("你要设定这个道具叫什么名字?\n");
		}
// write(i+"");
 
me->set_temp("item/itname",arg);
        message_vision("$N对$n道：知道了,你是要打造的东西叫:" + arg + " 吧！\n",
                       this_object(), me);
tell_object(me,ZJFORCECMD("setcolor"));


	return 1;
}





int do_answer4(string arg)
{
        object money;
        object ob;
        object me;
        object ganjiang;
mapping type;
int i;
    string cmd, temp;
    int args, ratio, round;
        me = this_player();
//        if (me->query_temp("item/status") != "answer_type")
//                return 0;
	
       // if (! arg)
             //   return notify_fail("你要设定这个道具为什么色? 有1-13种选择。\n ""HIY"",""HIG"",""RED"",""MAG"",""YEL"",""HIC"",""HIW"",""HIR"",""HIB"",""CYN"",""WHT"",""HIM"",""BLU"" \n");

		 if (! arg)
		{tell_object(me,INPUTTXT("你要设定这个道具为什么色? 有1-13种选择。"HIY"1，"HIG"2，"""RED"3，"""MAG"4，"""YEL"5，"""HIC"6，"""HIW"7，"""HIR"8，"""HIB"9，"""CYN"10，"""WHT"11，"""HIM"12，"""BLU"13"NOR"填入数字：","setcolor $txt#\n"));	
		 return 1;
               // return notify_fail("你要设定这个道具叫什么名字?\n");
		}	
			
			
 if (!me->query_temp("nwtemp") && !me->query_temp("natemp"))
                {
                        message_vision("$N摇摇头，对$n说：快说你要做什么东西！\n",
                                       this_object(), me);
		return notify_fail("你想好再来吧。\n");

                }

 	if(!arg || (sscanf(arg, "%d", i)!=1 ))
		return notify_fail("你要设定这个道具为哪种颜色?\n");
		
// write(i+"");
 
 if ( i >13 || i <1 )
                {
   message_vision("$N摇摇头，对$n说：你要设定这个道具为什么色? 有1-13种选择。\n ""HIY"",""HIG"",""RED"",""MAG"",""YEL"",""HIC"",""HIW"",""HIR"",""HIB"",""CYN"",""WHT"",""HIM"",""BLU"" \n\n",
                                       this_object(), me);
		return notify_fail("你想好再来吧。\n");

                }

me->set_temp("item/color",i);
        message_vision("$N对$n道：知道了,你是要打造第" + me->query_temp("item/color") + "种颜色吧！\n",
                       this_object(), me);

tell_object(me,ZJFORCECMD("show"));

	return 1;
}
