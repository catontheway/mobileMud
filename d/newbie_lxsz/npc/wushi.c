//D:\xkx\d\liuxiu-shanzhuang\npc\wushi.c武师
// labaz 2012/10/23

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include "../newbie_village.h"

string *reject_msg = ({
	"说道：您太客气了，这怎么敢当？\n",
	"像是受宠若惊一样，说道：请教？这怎么敢当？\n",
	"笑着说道：您见笑了，我这点雕虫小技怎够资格「指点」您什么？\n",
});

string skill_level(string, int,string);

int do_bai(string);
int do_halt();
int do_give(string);
int do_cha(string);
int do_learn(string);

void create()
{
	set_name(HIC"武师"NOR, ({ "wu shi", "wushi" }));
	set("title", "柳秀山庄");
	set("nickname", "太乙教头");
	set("shen_type", 1);

	set("gender", "男性");
	set("age", 35);
	set("long",
		"他是柳秀山庄的武师。\n");

	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 2000);
	set("max_jingli", 2000);
	set("max_jing", 2000);
	set("max_neili", 500);
	set("combat_exp", 4000);
	
	set_skill("dodge", 30);
	set_skill("force", 30);
	set_skill("taiyi-shengong", 30);
	set_skill("taiyi-you", 30);
	set_skill("taiyi-zhang", 30);
	set_skill("parry", 30);
	set_skill("sword", 20);
	set_skill("strike", 30);
	set_skill("taiyi-jian", 20);

	map_skill("force", "taiyi-shengong");
	map_skill("dodge", "taiyi-you");
	map_skill("strike", "taiyi-zhang");
	map_skill("parry", "taiyi-jian");
	map_skill("sword", "taiyi-jian");

	prepare_skill("strike", "taiyi-zhang");

    // set("attitude", "friendly");
    
	setup();
	
	carry_object(__DIR__"obj/jian")->wield();
}

void init()
{
	add_action("do_halt","halt");
	add_action("do_bai","bai");
	add_action("do_bai","apprentice");
	add_action("do_give","give");
	add_action("do_learn","xue");
	add_action("do_learn","learn");
	add_action("do_cha","cha");
	//add_action("do_cha","skills");
}

int do_halt()
{
	object who;
	who=this_player();
    if (who->is_fighting())
    {
        who->set_temp("newbie/halt",1);
    }
	return 0;
}

int accept_fight(object who)
{
	object ob;
	ob=this_object();
	
	if (ob->is_fighting()) return 0;
	call_out("checking",1,ob,who);
	return 1;
}

int checking(object ob,object who)
{
    int eff_qi;
	if (!who) return 1;
	if ((!ob->is_fighting()) && (present(who, environment())))
	{
		if (0==who->query_temp("newbie/halt"))
		{
			who->set_temp("newbie/fight",1);
            if (1==check_questindex(who,"尚武堂找武师比武，fight wushi"))
            {
                eff_qi=0.8*who->query("max_qi");
                who->set("eff_qi",eff_qi);
            }
			if (living(who))
			{
				set_nextquest(who,"尚武堂找武师比武，fight wushi","这场比试消耗了你不少的体力，回厢房去休息(sleep)一下吧。", 20, 100);
                if (1==check_questindex(who,"尚武堂找武师再次比武"))
                {
                    tell_object(who, GRN"经过这场比试，你对基本剑法有了更深的领悟！\n" NOR);
                    tell_object(who, HIC "你的「" + to_chinese("sword") + "」进步了！\n" NOR);
                    // SKILL_D("sword")->skill_improved(who);
                    who->set_skill("sword",6);
                    set_nextquest(who,"尚武堂找武师再次比武","你颇有慧根，竟悟出了剑法的剑意。\n趁热打铁去练习一级太乙剑法，一定能有收获的。\n可通过lian sword <次数>，来提高你当前enable的剑法\n", 50, 250);
                    message_vision(GRN"武师对$N说道：”能教的我都传授给你了，其他的就靠你自己领悟和努力了！“\n"NOR, who);
                }
			}
		}
        who->set_temp("newbie/halt",0);
        return 1;
	}
	remove_call_out("checking");
	call_out("checking",1,ob,who);
}

int do_bai(string arg)
{
	object ob, old_app, me, wuqi;
	mapping family, skills;
	int i;
	string *skname;

	me=this_player();
	ob=this_object();

	if( !arg ) 
    {
		tell_object(me,"指令格式：apprentice | bai [cancel]|<对象>\n");
        return 1;
    }

	if( ("wushi"!=arg)&&("wu shi"!=arg) )
		return 0;

	if (me->is_busy())
		{
            tell_object(me,"你现在正忙着呢。\n");
            return 1;
        }

	if( !living(ob) ) 
        {
            tell_object(me,"你必须先把" + ob->name() + "弄醒。\n");
            return 1;
        }
        
	if( arg=="cancel" ) {
		old_app = me->query_temp("pending/apprentice");
		if( !objectp(old_app) )
		{
            tell_object(me,"你现在并没有拜任何人为师的意思。\n");
            return 1;
        }
		write("你改变主意不想拜" + old_app->name() + "为师了。\n");
		tell_object(old_app, me->name() + "改变主意不想拜你为师了。\n");
		me->delete_temp("pending/apprentice");
		return 1;
	}

		
	if (0==check_questindex(me,"找武师拜师学艺，bai wushi"))
	{
		tell_object(me, "武师现在并没有收任何人为徒的意思。\n",1);
		return 1;
	}
    if (1==check_questindex(me,"找武师拜师学艺，bai wushi"))
	{
		tell_object(me, "武师说道：”好吧，看你是个习武的料，便教你两手，不过先得帮我做点事。“
武师趴在你耳边轻轻说道：“我需要一壶烧刀子和一把钢剑，你去酒铺、铁匠铺给我买回来。”\n\n");
		me->set_temp("newbie/needmoney",1);
		return 1;
	}
	if (2==check_questindex(me,"找武师拜师学艺，bai wushi") )
	{
		if (0==check_questindex(me,"bai wushi,查看武师技能，cha wushi"))
		{
			message_vision(GRN"$N恭恭敬敬地向$n磕头请安，叫道：「师父！」\n武师忙道：“先别急着叫师傅，东西给我买来了没。”\n\n"NOR, me, ob);
		}
		else
		{
			message_vision(GRN"$N恭恭敬敬地向$n磕头请安，叫道：「师父！」\n"NOR, me, ob);
            if ( 1==check_questindex(me,"bai wushi,查看武师技能，cha wushi") && 0==me->query("newbie_village/master") )
            {
                message_vision(GRN"武师笑道：“为师退隐江湖已久，早已不收徒弟。只传你武功，今后莫要对外人提起及我。\n跟我学艺这段时间，你就用这把太乙剑吧。”\n"NOR,me);
		me->set_slill("dodge",5);
		me->set_slill("force",5);
		me->set_slill("parry",5);
		me->set_slill("strike",5);
		me->set_slill("taiyi-shengong",5);
		me->set_slill("sword",5);
		me->set_slill("taiyi-you",5);
		me->set_slill("taiyi-zhang",5);
		me->set_slill("taiyi-jian",5);
    me->set("newbie_village/master",1);

                wuqi=new(__DOMAIN_DIR__"weapon/taiyijian");
                if (wuqi->move(me)) message_vision(GRN"武师从兵器架上拿给了$N一把太乙剑。(wield jian 可以装备这把剑)\n"NOR,me);
                me->save();
            }
		}
		return 1;
	}
	return 0;
}

void dest_ob()
{
	object ob;
	if(objectp(ob=present("jian"))) destruct(ob);
	if(objectp(ob=present("shaodaozi"))) destruct(ob);
	if(objectp(ob=present("shi he"))) destruct(ob);
}

int accept_object(object who, object ob)
{
	object *inv;
	int i;
	
	call_out("dest_ob",2);

	// if (ob->query("id")=="hulu" && ob->qurery("name")=="[33m"+"葫芦")
	if (1==check_questindex(who,"帮武师去铁匠铺买一把钢剑，去酒铺买一壶烧刀子酒，回来交给武师"))
	{
		if (ob->query("id")=="jian") who->set_temp("newbie/jian",1);
		if (ob->query("id")=="shaodaozi") who->set_temp("newbie/shaodaozi",1);
		if (2 == who->query_temp("newbie/jian")+who->query_temp("newbie/shaodaozi"))
		{
			message_vision(GRN"$N向武师做了个揖，道：“还望您能指点在下几招！”\n武师嘿嘿笑道：“痴老汉这酒还是那么够劲，直勾老子肚子里的馋虫，你去买根鸡腿给我下下酒。\n记住我要吃热得，去杂货铺买个食盒，把鸡腿放进去带回来。(pu jitui in shi he)”\n\n"NOR, who);
			set_nextquest(who,"帮武师去铁匠铺买一把钢剑，去酒铺买一壶烧刀子酒，回来交给武师","没办法，继续跑腿去买东西吧，要有诚意。(put jitui in shi he)", 20, 100);
			return 1;
		}
		else if (1==who->query_temp("newbie/jian")+who->query_temp("newbie/shaodaozi"))
		{
			return 1;
		}
	}
	if (1==check_questindex(who,"再去酒铺买个鸡腿，去杂货铺买个食盒，把鸡腿放到食盒里交给武师"))
	{
		if (ob->query("id")=="shi he")
		{
			inv = all_inventory(ob);
			for(i=0; i<sizeof(inv); i++) 
			{
				if (inv[i]->query("id")=="jitui")
				{
					message_vision(GRN"武师对$N说道：“看你这么有诚意，我就来教你几招。”\n\n"NOR, who);
					set_nextquest(who,"再去酒铺买个鸡腿，去杂货铺买个食盒，把鸡腿放到食盒里交给武师","还等什么，赶紧拜师(bai wushi)吧，再看看师傅都会些什么功夫(cha wushi)。", 20, 100);
					return 1;
				}
			}
			message_vision(GRN"武师对$N皱起了眉头，问道：“你怎么没把鸡腿装到食盒里呢？空盒子你自己留着吧。”\n"NOR,who);
			return 0;
		}
		if (ob->query("id")=="jitui")
		{
			message_vision(GRN"武师对$N皱起了眉头，说道：“把它装到食盒里再给我。”\n"NOR,who);
			return 0;
		}
	}
	return 0;
}

/*int do_cha(object me, string arg)
{
       object ob;
	mapping skl, lrn, map, pmap;
	string *sname, *mapped, *pmapped, str, mski,skill1, *huanshou_str;
	string skillname, skcolor;
	string *basic;
	string *spec;
	string *text,sss;
	mixed  *lists;
	string *others;
	string fname,space;
	string pops;
	int valid_check;
	int cha_type;
	int lvl;
	int i, k,j,all,page;
	seteuid(getuid());
	skill1 = 0;

	if (! arg)
	{
		ob = me;
		page = 1;
	}
	else if (strlen(arg)<2&&sscanf(arg,"%d",page)==1)
	{
		ob = me;
	}
	else
	{
		string *temp;
		if (sscanf(arg, "%s of %s", skill1, arg) == 2)
			;
		else if (temp = explode(arg, " "))
		{
			if(strlen(temp[sizeof(temp) - 1])<2&&sscanf(temp[sizeof(temp) - 1],"%d",page)==1)
			{
				temp = temp[0..sizeof(sizeof(temp) - 2)];
			}
			if (sizeof(temp) < 2)
				arg = "me";
			else
				arg = implode(temp[0..sizeof(temp) - 2], " ");
			skill1 = temp[sizeof(temp) - 1];

			if (file_size(SKILL_D(skill1) + ".c") <= 0)
			{
				if (sizeof(temp) < 2)
					arg = skill1;
				else
					arg += " " + skill1;
				ob = present(arg, environment(me));
				skill1 = 0;
			}
		}
		else
		{
			if (! wizardp(me) && (! (ob = present(arg, environment(me))) || ! ob->is_character() || ! me->is_apprentice_of(ob)))
			{
				skill1 = arg;
				arg = "me";
			}
		}

		if (ob && ! ob->is_character())
			ob = 0;

		if (skill1 && file_size(SKILL_D(skill1) + ".c") <= 0)
		{
			if (objectp(ob))
			{
				arg = 0;
				skill1 = 0;
			} else
				return notify_fail("没有(" + skill1 +  ")这种技能。\n");
		}

		if (! ob || ! ob->is_character())
		{
			if (arg == "me")
				ob = me;
			else
				ob = present(arg, environment(me));
	
			if (! ob || ! ob->is_character()) ob = find_player(arg);
			if (! ob || ! ob->is_character()) ob = find_living(arg);
		}

		if (! ob || ! ob->is_character())
			return notify_fail("你要察看谁的技能？\n");
	}

	if (ob != me)
	{
		if ((int)ob->skills(me, skill1))
			return 1;
	}
       
	if (ob == me || wizardp(me) || ob->is_apprentice_of(me) || me->is_apprentice_of(ob) || me->query("couple/id") == ob->query("id") || me->is_brother(ob) )
		valid_check = 1;
	else
	{
		fname = me->query("league/league_name");
		if (stringp(fname) && fname == ob->query("league/league_name"))
			valid_check = 1;
		else
			valid_check = 0;
		if (me->query("can_whistle"))
		{
		   huanshou_str=keys(me->query("can_whistle"));
		   if(ob->query("owner")!=me->query("id"))
		   {
		      valid_check = 0;
		   }
		   else
		   {
		      valid_check = 1;
		   }
		}
	}
	if (ob != me && !wizardp(me) && ob->query("env/nocha_skills"))
		return notify_fail("对方设置了技能不公开。\n");
//	if (! valid_check)
//		return notify_fail("只有巫师或有师徒/夫妻/结拜/主宠/同盟关系的人才能察看他人的技能。\n");

	skl = ob->query_skills();
	if (! sizeof(skl))
	{
		write((ob==me ? "你" : ob->name()) + "目前并没有学会任何技能。\n");
		return 1;
	}

	sname = keys(skl);

	str = ZJOBLONG + (ob == me ? "你" : ob->name()) + "目前所学到的";
	if (skill1)
	{
		// filter the skill array by skill1
		if (member_array(skill1, valid_types) != -1)
		{
			sname = filter_array(sname, (: filter_for_enable :), skill1);
			str += to_chinese(skill1) + "及相关技能\n";
		}
		else if (SKILL_D(skill1)->main_skill() && member_array(SKILL_D(skill1)->main_skill(), sname) == -1)
		{
			mski = SKILL_D(skill1)->main_skill();
			cha_type = 3;
			sname = filter_array(sname, (: filter_for_main :), mski);
			str += to_chinese(skill1) + "中的招式和可以激发的基础武功\n";
		}
		else
		{
			cha_type = 3;
			sname = filter_array(sname, (: filter_for_combine :), skill1);
			str += to_chinese(skill1) + "和可以激发的基础武技与能够组合的技能\n";
		}
	} else
	{
		if(!page) page = 1;
		str += "所有技能：\n";
	}

	if (! sizeof(sname))
	{
		write("你目前还没有掌握该技能。\n");
		return 1;
	}

	basic = filter_array(valid_types, (: member_array($1, $(sname)) != -1 :));

	lists = allocate(sizeof(basic));

	others = ({ });
	spec = ({ });

	sname -= basic;
	for (i = 0; i < sizeof(sname); i++)
	{
		if (! sname[i]) continue;

		// enable for basic skill
		for (k = 0; k < sizeof(basic); k++)
		{
			string main_skill;

			if (SKILL_D(sname[i])->valid_enable(basic[k]))
			{
				// yes, I record this special skill
				if (! lists[k])
					lists[k] = ({ sname[i] });
				else
					lists[k] += ({ sname[i] });

				spec += ({ sname[i] });
				// Is this a sub skill ?
				if (main_skill = SKILL_D(sname[i])->main_skill())
				{
					// yes, I select out all the other sub skills
					int st;
					for (st = i + 1; st < sizeof(sname); st++)
						if (sname[st] && SKILL_D(sname[st])->main_skill() == main_skill)
						{
							spec += ({ sname[st] });
							// record it
							lists[k] += ({ sname[st] });
							sname[st] = 0;
						}
				}

				break;
			}
		}

		if (k == sizeof(basic))
			others += ({ sname[i] });
	}
	sname = ({ });

	for (i = 0; i < sizeof(basic); i++)
	{
		sname += ({ basic[i] });
		if (lists[i]) sname += lists[i];
	}

/*
        spec = sort_array(spec, (: strcmp :));
        basic = sort_array(basic, (: strcmp :));
        others = sort_array(others, (: strcmp :));
	sname += spec;
	sname += basic;
	sname += others;


	sname += others;
	j = (int)sizeof(skl);
	// get the skill map
	map = ob->query_skill_map();
	if (mapp(map)) mapped = values(map);
	if (! mapped) mapped = ({});
	pmap = me->query_skill_prepare();
	if (mapp(pmap)) pmapped = values(pmap);
	if (! pmapped) pmapped = ({});
	lrn = ob->query_learned();
	if (! mapp(lrn)) lrn = ([]);

	str = replace_string(str,"\n",ZJBR);
	if(str[(strlen(str)-4)..(strlen(str)-1)]=="$br#")
		str = str[0..(strlen(str)-5)];
	str += "\n";
	str += ZJOBACTS2+ZJMENUF(3,3,9,30);
	if(!arg)
		str += "　查看激发"ZJBR"　enable:jifa"ZJSEP"　查看准备"ZJBR"　prepare:bei"ZJSEP"　取消准备"ZJBR"　bei none:bei none"ZJSEP;
	text = ({});
	for (i = 0; i < sizeof(sname); i++)
	{
		int percent;
		skillname = to_chinese(sname[i]);
		if (member_array(sname[i], valid_types) != -1)
			skcolor = CYN;
		else
			skcolor = WHT;

		if (! objectp(find_object(SKILL_D(sname[i]))) && ! objectp(load_object(SKILL_D(sname[i]))))
		{
			write(HIR "Error(No such skill):" + sname[i] + NOR"\n");
			continue;
		}
		lvl = skl[sname[i]];
		percent = lrn[sname[i]] * 100 / ((lvl + 1) * (lvl + 1) + 1);
		if (percent > 100) percent = 100;
		pops = ZJPOPMENU;
		if(ob==me)
		{
			if(!strlen(arg)<2&&page)
			{
				if(member_array(sname[i], valid_types) == -1)
				{
					pops += "激发"+to_chinese(sname[i])+"|skills "+sname[i];
					pops += ZJSP2"准备"+to_chinese(sname[i])+"|prepare "+sname[i];
					pops += ZJSP2"研究"+to_chinese(sname[i])+"|yanjiu "+sname[i];
				}
				else
				{
					pops += "练习"+to_chinese(sname[i])+"|lian "+sname[i];
					pops += ZJSP2"研究"+to_chinese(sname[i])+"|yanjiu "+sname[i];
					pops += ZJSP2"只用"+to_chinese(sname[i])+"|jifa "+sname[i]+" none";
				}
				pops += ZJSP2"查看"+to_chinese(sname[i])+"|chaski "+sname[i];
				pops += ZJSP2"放弃"+to_chinese(sname[i])+"|abandon "+sname[i];
			}
			else if(cha_type==3)
			{
				if(member_array(sname[i], valid_types) == -1)
				{
					if(!mapp(pmap)||member_array(sname[i], pmapped) == -1)
						pops += "组合"+to_chinese(sname[i])+"|bei "+sname[i]+" "+skill1;
					else
						pops += "撤销组合"+to_chinese(sname[i])+"|bei none";
				}
				else
				{
					pops = "jifa "+sname[i]+" "+skill1;
				}
			}
		}
		else
		{
			pops += "向"+ob->query("name")+"请教"+to_chinese(sname[i])+"|learn "+ob->query("id")+" for "+sname[i]+" 50";
			pops += ZJSP2"查看"+to_chinese(sname[i])+"|chaski "+sname[i];
		}
		text +=({ sprintf("%s%s%s%s"NOR ZJBR WHT"　%d/%d%%"NOR":%s",
			skcolor,
			(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
			(member_array(sname[i], mapped)==-1? "　": RED"㊣"NOR),
			skillname, lvl, percent,pops) });
	}
	if(!page) page = 1;
	all = sizeof(text)/30;
	if(sizeof(text)%30) all += 1;
	if(page<1) page = 1;
	if(page>all) page = all;
	j = (page-1)*30;
	i = page*30;
	if (i >= sizeof(text)) i = sizeof(text);
	i--;
	str += implode(text[j..i], ZJSEP);
	if(all>1)
	{
		sss = "";
		if(ob!=me) sss += " "+file_name(ob);
		if(skill1) sss += " "+skill1;
//		str += ZJSEP"上一页:skills "+(1)+ZJSEP"下一页:skills "+(2);
		str += ZJSEP"上一页:skills"+sss+" "+(page-1)+ZJSEP"下一页:skills"+sss+" "+(page+1);
	}
	tell_object(me,str+"\n");
	return 1;
}


int filter_for_enable(string skill, string skill1)
{
	return (skill == skill1) || (SKILL_D(skill)->valid_enable(skill1));
}

int filter_for_main(string skill, string skill1)
{
	return  (SKILL_D(skill1)->valid_enable(skill))||(SKILL_D(skill)->main_skill() == skill1);
}

int filter_for_combine(string skill, string skill1)
{
	return (SKILL_D(skill1)->valid_enable(skill)) || (SKILL_D(skill)->valid_combine(skill1));
}
string skill_level(string type, int level)
{
    int grade;
    if (level>=100) if (level<300) grade=(level-100)/20+10 ;else return  NOR "返璞归真" NOR;
    else    grade = level / 10;
    switch(type) {
	case "knowledge":
	    if( grade >= sizeof(knowledge_level_desc) )
		grade = sizeof(knowledge_level_desc)-1;
	    return knowledge_level_desc[grade];
	    break;
	default:
	    if( grade >= sizeof(skill_level_desc) )
		grade = sizeof(skill_level_desc)-1;
	    return skill_level_desc[grade];
    }
}*/

int do_learn(string arg)
{
	string skill, teacher, master, skill_name, slow_msg;
	object ob,me;
	int master_skill, my_skill, gin_cost, slow_factor;
  	int i, tmp, learn_times;

	me=this_player();

	if (me->is_busy())
    {
		tell_object(me,"你现在正忙着呢。\n");
        return 1;
    }
    
	if(!arg)
	{
        tell_object(me,"指令格式：learn|xue <某人> for <技能> [次数]\n");
        return 1;
    }
  	if (sscanf(arg, "%s for %s %d", teacher, skill, learn_times)!=3 )
    {
        tell_object(me,"指令格式：learn|xue <某人> for <技能> [次数]\n");
	}
	if (learn_times < 1) 
		{
            tell_object(me,"指令格式：learn|xue <某人> for <技能> [次数]\n");
            return 1;
        }

	if( me->is_fighting() )
		{
            tell_object(me,"临阵磨枪？来不及啦。\n");
            return 1;
        }

	if( !(ob = present(teacher, environment(me))) || !ob->is_character())
		{
            tell_object(me,"你要向谁求教？\n");
            return 1;
        }

	if( !living(ob) )
		{
            tell_object(me,"嗯....你得先把" + ob->name() + "弄醒再说。\n");
            return 1;
        }

	if( me->query("potential")-me->query("learned_points") < learn_times )
		{
            tell_object(me,"你的潜能不够，没有办法再成长了。\n");
            return 1;
        }

	// HACK: recognize_apprentice takes care of the payment 
	// for literate.  We have to do this learn_times.
	for (i=0; i<learn_times; i++) 
    {
	    if( !me->query("newbie_village/master") || "wu shi" != ob->query("id") ) 
        {
            tell_object(me, ob ->name() + reject_msg[random(sizeof(reject_msg))] );
            return 1;
	    }
	}

	slow_factor = 1;
	slow_msg = "";

	if( !master_skill = ob->query_skill(skill, 1) )
	    {
            tell_object(me,"这项技能你恐怕必须找别人学了。\n");
            return 1;
        }

	
	if( ob->prevent_learn(me, skill) ) 
    {
        tell_object(me,ob->name() + "不愿意教你这项技能。\n");
        return 1;
    }

	my_skill = me->query_skill(skill, 1);

    if (5==me->query_skill("dodge",1) && 5==me->query_skill("force",1) && 5==me->query_skill("parry",1) && 5==me->query_skill("strike",1) && 5==me->query_skill("sword",1)
&& 5==me->query_skill("taiyi-shengong",1) && 5==me->query_skill("taiyi-you",1) && 5==me->query_skill("taiyi-zhang",1) && 5==me->query_skill("taiyi-jian",1))
    {
        set_nextquest(me,"学习武师身上所有基本功夫到5级，所有高级功夫到5级","把学到的功夫都激发起来吧！\njifa force taiyi-shengong 将太乙神功作为你使用的内功
jifa dodge taiyi-you 将太乙神游作为你使用的轻功\njifa sword taiyi-jian 将太乙剑法作为你使用的剑法\njifa parry taiyi-jian 将太乙剑法作为你使用的招架\njifa strike taiyi-zhang 将太乙掌法作为你使用的掌法", 50, 250);
		return 1;
	}	

	if ( my_skill>=5 && (skill == "dodge" || skill == "force" || skill == "parry" || skill == "strike" || skill == "sword"))
	{
		tell_object(me,"你只能学到五级的基本功夫。\n");
        return 1;
	}

	if ( my_skill>=5 && (skill == "taiyi-shengong" || skill == "taiyi-you" || skill == "taiyi-zhang" || skill == "taiyi-jian")) 
	{
		tell_object(me,"你只能学到五级的高级功夫。\n");
        return 1;
	}

	// if (me->is_spouse_of(ob) )
	    // if (my_skill >= master_skill - 20*(me->query("married_times")-1))
		// return notify_fail(ob->name() + "想到你和以前" 
			// + me->query("spouse/title") 
			// + "在一起的情形，有点不大愿意教你这项技能。\n");
	    // else if ( (ob->query("combat_exp") < 10000 
	    	       // || me->query("combat_exp") < 10000 )
			// && (string)SKILL_D(skill)->type() == "martial" ) 
		// return notify_fail("你们夫妇实战经验还不足，不能互相传授武艺！\n");
		
	// notify_fail("依你目前的能力，没有办法学习这种技能。\n");
	// if (me->is_spouse_of(ob)) me->add_temp("mark/朱", learn_times);
	// if( !SKILL_D(skill)->valid_learn(me) ) return 0;
	// if (me->is_spouse_of(ob)) me->add_temp("mark/朱", -learn_times);

	gin_cost = 60 / (int)me->query("int");

	if( !my_skill ) {
	    gin_cost *= 2;
	    me->set_skill(skill,0);
	}

	printf("你向%s请教有关「%s」的疑问。\n", ob->name(), to_chinese(skill));

	if( ob->query("env/no_teach") )
		{
            tell_object(me,"但是" + ob->name() + "现在并不准备回答你的问题。\n");
            return 1;
        }

	tell_object(ob, sprintf("%s向你请教有关「%s」的问题。\n", me->name(), to_chinese(skill)));

	if( (int)ob->query("jing") > learn_times*gin_cost/5 + 1 ) {
		if( userp(ob) ) ob->receive_damage("jing", learn_times*gin_cost/5 + 1);
	} else {
		write("但是" + ob->name() + "显然太累了，没有办法教你什么。\n");
		tell_object(ob, "但是你太累了，没有办法教" + me->name() + "。\n");
		return 1;
	}
		
	gin_cost = learn_times * gin_cost*3/2;
	
	if( (int)me->query("jing") > gin_cost ) {
		if( (string)SKILL_D(skill)->type()=="martial"
		&&	my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) {
			printf("也许是缺乏实战经验，你对%s的回答总是无法领会。\n", ob->name() );
		} else {
		    if(skill_name = SKILL_D(skill)->query_skill_name(my_skill)) {
			if ( skill=="linji-zhuang" )
			    printf("你听了%s的指导，%s对「%s」的修养似乎有所提高。\n", 
				    ob->name(), slow_msg, skill_name);
			else
			    printf("你听了%s的指导，%s对「%s」这一招似乎有些心得。\n", 
				    ob->name(), slow_msg, skill_name);
		    }
		    else
			printf("你听了%s的指导，%s似乎有些心得。\n", ob->name(), slow_msg);
			
            me->add("learned_points", learn_times );

		    tmp = 0;
		    for (i=0; i<learn_times; i++)  tmp += random(me->query_int());
	
		    me->improve_skill(skill, tmp/slow_factor);

		}
	} else {
		gin_cost = me->query("jing") > 0 ? (int)me->query("jing") : 0;
		write("你今天太累了，结果什么也没有学到。去睡一觉再来学吧。\n");
	}

	me->receive_damage("jing", gin_cost);
    
    if (5==me->query_skill("dodge",1) && 5==me->query_skill("force",1) && 5==me->query_skill("parry",1) && 5==me->query_skill("strike",1) && 5==me->query_skill("sword",1)
&& 5==me->query_skill("taiyi-shengong",1) && 5==me->query_skill("taiyi-you",1) && 5==me->query_skill("taiyi-zhang",1) && 5==me->query_skill("taiyi-jian",1))
    {
	
        set_nextquest(me,"学习武师身上所有基本功夫到5级，所有高级功夫到5级","把学到的功夫都激发起来吧！\njifa force taiyi-shengong 将太乙神功作为你使用的内功
jifa dodge taiyi-you 将太乙神游作为你使用的轻功\njifa sword taiyi-jian 将太乙剑法作为你使用的剑法\njifa parry taiyi-jian 将太乙剑法作为你使用的招架\njifa strike taiyi-zhang 将太乙掌法作为你使用的掌法", 50, 250);
    }

	return 1;
}