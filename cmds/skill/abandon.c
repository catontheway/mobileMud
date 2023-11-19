// abandon.c
// modified by vast for 自创武功
// modified by jpei for yes/no 05162008

inherit F_CLEAN_UP;
#include <ansi.h>
protected int delete_skill(string arg, object me, string skill);
int main(object me, string arg)
{
        int i, flag;
        string *skillname;
        mapping skills;
         int skill_lvl, lvl;
    	int jingcost;
	string skill;
    	string name,ok;
	int lost,queren;
        if( !arg || arg=="" )
                return notify_fail("你要放弃哪一项技能？\n");
        if(sscanf(arg,"%s %d %d",skill,lvl,queren)==3)
	{
		if(lvl<1)
			return notify_fail("放弃单位至少需要1 。。。\n");
	}
	else if(sscanf(arg,"%s %d",skill,lvl)==2)
	{
		if(skill=="exp")
		{
			write(ZJOBLONG"你确定要放弃"+lvl+HIY"经验"NOR"吗？\n"ZJOBACTS2+ZJMENUF(3,3,10,30)+"确认:abandon "+arg+" 1\n");
			return 1;
		}
		else
		{
			write(ZJOBLONG"你确定要放弃"+lvl+"级"HIY+to_chinese(skill)+NOR"吗？\n"ZJOBACTS2+ZJMENUF(3,3,10,30)+"确认:abandon "+arg+" 1\n");
			return 1;
		}
	}
	else skill=arg;

    	if (me->is_fighting())
		return notify_fail("你正忙着打架呢，哪有时间做这种事？\n");

    	if (me->is_busy())
		return notify_fail("你正忙，没法静下心来。\n");

    	jingcost = me->query("int") + random(me->query("int"));
    	if (jingcost > me->query("jing"))
		return notify_fail("你无法集中精力。\n");

	if (skill == "exp")
	{
		if (me->query("combat_exp")>1 && me->query("zjvip/times")<1)
			return notify_fail("暂不开放。\n");

		if (!queren)
			return notify_fail(INPUTTXT("请谨慎操作！"ZJBR"你想放弃多少的"HIY"经验"NOR"：","abandon exp"+" $txt#")+"\n");
		lost = me->query("combat_exp");
		if (lost < lvl)
			return notify_fail("你发现自己现在对武学简直就是一无所知。\n");

		if (199999 < lvl)
			return notify_fail("一次最多只能忘掉199999实战经验。\n");

		message("vision", me->name() + "坐下在凝神思索什么。\n",environment(me), me);
		tell_object(me, "你不再想拳脚兵器轻功内功，只是一门心思忘记武功。\n");
		me->start_busy(1);

		me->add("combat_exp", -lvl);
                switch (random(6))
		{
		case 0:
			tell_object(me, HIR "你又想起了很多温馨的往事，不由得沉浸其中。"NOR"\n");
			break;
		case 1:
			tell_object(me, HIR "你似乎又看到了遥远的童年，一时忘却了尘世间的烦恼。"NOR"\n");
			break;
		case 2:
			tell_object(me, HIR "你黯然一声长叹，只觉得自己为了武学荒废一生，实在无谓。"NOR"\n");
			break;
		case 3:
			tell_object(me, HIR "你心如止水，所有的武功都仿佛离自己远去了。"NOR"\n");
			break;
		case 4:
			tell_object(me, HIR "你抬头仰望天空，发现它明亮透析，说不出的娇媚，令你身心俱化。"NOR"\n");
			break;
		default:
			tell_object(me, HIR "你脑海中晃过当年无数刻苦修炼的日子，不由得暗自苦笑。"NOR"\n");
			break;
		}

		//UPDATE_D->check_user(me);
		return 1;
	}
        if( !find_object(PLAYER_SKILL_D(arg)) && file_size(PLAYER_SKILL_D(arg)+".c") < 0)//判断是否是非自创武功
        if( !find_object(SKILL_D(arg)) && file_size(SKILL_D(arg) + ".c") < 0)//判断是否是自创武功
                return notify_fail("没有这项技能，请检查是否输入有误。\n");

        skills = me->query_skills();
        for (i = sizeof(skillname = keys(skills)) - 1; i >= 0; i--)
                if (skillname[i] == arg) flag = 1;
        if (flag != 1)
                return notify_fail("你并没有学过这项技能。\n");
 
        if (me->is_busy())   
                return notify_fail("你正忙着呢。\n"); 
        me->start_busy(1); 
        
        //暂时不判断skills level，存在自创功夫
        write("\n注意！你将要放弃"HIW+to_chinese(arg)+"("+arg+")"NOR" ，确定吗？[Y|N] >");
        input_to("delete_skill", me, arg); 
 
        return 1;
}

protected int delete_skill(string arg, object me, string skill)
{
        int i, flag;
        string basename, *skillname,*baseskillname;
        mapping skillmaxim, skills;

        if( arg[0]=='y' || arg[0]=='Y' ){ 
                //检查此功夫是否已经wbei
                flag = 0;
                skills = me->query_wprepare();
                if (sizeof(skills)>0){
                        baseskillname = keys(skills);
                        for (i = sizeof (skillname = values(skills))-1;i>=0;i--)
                                if ( (skillname[i] == skill)||(baseskillname[i] == skill) )  flag = 1;
                        if (flag){
                                for (i = sizeof (skillname = keys(skills))-1;i>=0;i--)
                                        me->prepare_wskill(baseskillname[i]);
                                write("你解除了当前的兵器功夫组合。\n");
                        }
                }
                //检查此功夫是否已经bei
                flag = 0;
                skills = me->query_skill_prepare();
                if (sizeof(skills)>0){
                        baseskillname = keys(skills);
                        for (i = sizeof (skillname = values(skills))-1;i>=0;i--)
                                if ( (skillname[i] == skill)||(baseskillname[i] == skill) )  flag = 1;
                        if (flag){
                                for (i = sizeof (skillname = keys(skills))-1;i>=0;i--)
                                        me->prepare_skill(baseskillname[i]);
                                write("你解除了当前的拳脚功夫组合。\n");
                        }
                }
                //检查此功夫是否已经enable
                skills = me->query_skill_map();
                if (sizeof(skills)>0){
                        baseskillname = keys(skills);
                        for (i = sizeof (skillname = values(skills))-1;i>=0;i--)
                                if ( (skillname[i] == skill)||(baseskillname[i] == skill) )  me->map_skill(baseskillname[i]);
                }
                me->reset_action();
        
                //判断是否是非自创武功
                if( !find_object(PLAYER_SKILL_D(skill)) && file_size(PLAYER_SKILL_D(skill)+".c") < 0){
                        if( !me->delete_skill(skill) )
                                return notify_fail("你并没有学过这项技能。\n"); 
                        write("\n你决定放弃继续学习"+ to_chinese(skill) +"("+skill+")。\n\n");
                }else{
                        if( !me->delete_skill(skill) )
                                return notify_fail("你并没有学过这项技能。\n");
                        skillmaxim = me->query("skillmaxim");
                        basename = "/cmds/skill/createskill.c"->get_header_skillbasename(skill + ".c");
                        map_delete(skillmaxim, basename);
                        log_file( "CREATESKILL", sprintf("%s(%s) 放弃学习 %s(%s) (%s)\n",
                            me->query("name"),
                            me->query("id"),
                            "/cmds/skill/createskill.c"->get_header_skillchname(arg + ".c"),
                            arg,
                            ctime(time()) ) );  
                        write("\n你决定放弃继续学习"+ to_chinese(skill) +"("+skill+")。\n\n");
                        CHINESE_D->remove_translate(arg);
                        seteuid(ROOT_UID);
                        rm(PLAYER_SKILL_D(skill)+".c");
                        seteuid(getuid());
                }
        }else{
                write("\n你决定保留"+ to_chinese(skill) +"("+skill+")。\n\n");
        }
        return 1;
}


int help()
{
        write(@TEXT
指令格式：abandon|fangqi <技能名称>

放弃一项你所学过的技能，注意这里所说的「放弃」是指将这项技能从你人物
的资料中删除，如果你以后还要练，必须从０开始重练，请务必考虑清楚。

这个指令使用的场合通常是用来删除一些「不小心」练出来的技能，由于每个
人有着不同的天赋，所修习的武功也不会相同。如果样样都学，到头来只会样
样不精。
TEXT
        );
        return 1;
}

