//tianyuebing  中秋月饼(加50内力)
//Made By jason@mudnow.com
//2000-5.-6
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("月饼",({"da yuebing","yuebing"}));
        set("long","据说是溢出食坊制作的中秋月饼,看上去就让人馋涎欲滴,还不赶紧尝尝(eat)?\n");
        set("unit","块");
	set("no_drop",1);
        set("no_get",1);
        set("value",0);
        set("no_store",1);
		set("product_time",time());
       setup();
}

void init()
{
    add_action("do_eat","eat");
}

int do_eat(string arg)
{
    object me = this_player();
	object ob = this_object();
	int i,j;
    if (!arg)  return notify_fail("你要吃什么？\n");
	 if (me->query("gift/20210815") >= 1)
                return notify_fail("你已经吃过了月饼了，也不怕撑得慌！\n");
    if((arg=="da yuebing") || (arg=="yuebing")) 
    {
		//if (time() - ob->query("product_time") > 259200)
		//{
			//return notify_fail("过期月饼你也吃，想找死啊？\n");
	//	}
      //  if ( (int)me->query("zhongqiu/gift_yuebing" ) > 0 ) return notify_fail("你已经吃过月饼了，难道你想吃成肥猪吗？\n");
      //  if(me->query("mud_age")<360000)
        //        return notify_fail("起码要在这个mud中呆足100个小时才可以食用中秋月饼!\n");
        //if(me->query("combat_exp")<200000)
          //      return notify_fail("经验200000以上才可以食用中秋月饼!\n");
        message_vision(HIG"\n$N尝了一口月饼，顿时为它的味道所折服,三口两口把月饼吞下肚,心里充满了对溢出食坊的感激之情！\n"NOR,me);
		i=random(10);
		j=random(10);
		switch(i)
		{
			case 0:
			case 1:
			case 2:
		        me->add("str",1);
				me->add("balance",100000);
				me->add("combat_exp",2000+random(500));
        me->add("potential",20000+random(100));
		 me->add("gift/20210815",1);
	            tell_object(me,"\n哇，蛋黄的!你的先天臂力增长了一点!\n");
			break;
			case 3:
			case 4:
		        me->add("con",1);
				me->add("balance",100000);
				me->add("combat_exp",2000+random(500));
        me->add("potential",20000+random(100));
		 me->add("gift/20210815",1);
	            tell_object(me,"\n哇，鲜肉的！你的根骨增长了一点!\n");
			break;
			case 5:
			case 6:
			case 7:
		        me->add("int",1);
				me->add("balance",100000);
				me->add("combat_exp",2000+random(500));
        me->add("potential",20000+random(100));
		 me->add("gift/20210815",1);
	            tell_object(me,"\n哇，莲蓉的！你的悟性增长了一点!\n");
			break;
			case 8:
				me->add("dex",1);
				me->add("balance",100000);
				me->add("combat_exp",2000+random(500));
        me->add("potential",20000+random(100));
		 me->add("gift/20210815",1);
	            tell_object(me,"\n哇，五仁的！你的身法增长了一点!\n");
			break;
			case 9:
	            tell_object(me,"\n你吃到了一个过期月饼，好苦，额，呕吐不已！\n");
				if (me->query("zhongqiu/gift_yuebing")!=1)
				{
					if (j == 5)
					{
						tell_object(me,"\n你福至心灵，居然没有吐出任何东西！\n");
						me->add("kar",1);
    CHANNEL_D->do_channel(load_object(CHANNEL_D), "jh", HIR + "听说" + me->query("name") + HIR + "吃月饼差点吃进医院！\n" + NOR, -1);

					}
					else
					{
						me->set("food",me->max_food_capacity()/10);

						if (j == 4)
						{
							tell_object(me,"\n呕吐过程中你的灵性大发，发现了辨别过期月饼的办法！\n");
							me->add("spi",1);
							me->add("balance",100000);
				me->add("combat_exp",2000+random(500));
        me->add("potential",20000+random(100));
		 me->add("gift/20210815",1);
    CHANNEL_D->do_channel(load_object(CHANNEL_D), "jh", HIR + "听说" + me->query("name") + HIR + "吃月饼差点吃坏肚子！\n" + NOR, -1);
						}
					}
				}
			break;
		}
	      me->set("zhongqiu/gift_yuebing",1);
        destruct(this_object());
     }
     return 1;
}
