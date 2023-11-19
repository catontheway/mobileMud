// lingwu.c
// 把达摩院的领悟命令抽出来变成本地，为以后扩展方便考虑。zine@pkuxkx 2013/2/28
#include <skill.h>
#include <ansi.h>
inherit F_CLEAN_UP;
#include "/cmds/skill/study_class_benefit.h"
int *query_scale(string skill);
//string *legal_lingwu_place=({"/d/shaolin/dmyuan2",});
string *adv_weapon=({"sword","blade","whip","staff","dagger","axe","halberd","spear","hammer","throwing"});
int main(object me,string arg)
{
  object where = environment(me);
  string skillname,arg2, lfam;
  int skill, skill_basic;
  int imp_skill;
  int i;
  int cost,exp;
  int *ls, *scale;
  int lingwu_times;
  seteuid(getuid());

  if (where->query("pigging"))
    return notify_fail("你还是专心拱猪吧！\n");
  
  if (me->is_busy())
    return notify_fail("你现在正忙着呢。\n");
  
  if( me->is_fighting() )
    return notify_fail("你已经在战斗中了，学一点实战经验吧。\n");
  
  if( !arg ) return notify_fail("提升什么？\n");
  
  arg2=arg;
  if(sscanf(arg2,"%s %d",arg,lingwu_times)!=2) 
  {
    arg=arg2;
    lingwu_times=1;
  }
  
  if (lingwu_times < 1) return notify_fail("你至少要花费一点潜能！\n");
  
  if (lingwu_times>9999999) return notify_fail("你至多花费9999999潜能！\n");
  if ((me->query("potential") - me->query("learned_points")) < lingwu_times)
	return notify_fail("你的潜能不够了。\n");
  skill_basic = me->query_skill(arg, 1);
   cost = me->query_skill(arg,1);
   
		if (cost < 100)
		return notify_fail("你对" + to_chinese(arg) + "的掌握程度还未到升级的程度。\n");
  if((string)SKILL_D(arg)->type()=="martial" && cost * cost * cost / 10 > (int)me->query("combat_exp") )
        return notify_fail("由于缺乏实战经验，你总是无法领会更高深的武功。\n" );
  if( skill_basic < 1 )
    return notify_fail("你还没学过这项技能吧？最好先去请教别人。\n");
  
 
  
  skill = me->query_skill(skillname, 1);
 // ls = sort_array(ls, -1);
	//scale = query_skill(skill);
//	imp_skill = 0;
//	for (i = 0; i < lingwu_times; i++)
	//	imp_skill += ls[i] * scale[i];

/*	imp_skill = imp_skill / 10 / (100 + SKILL_D(skill)->difficult_level()) +  (int)me->query("int") / 2;
	imp_skill += skill / 30;
	imp_skill += imp_skill * SPEWEEK_D->query_learn_bonus()/100;
   
    	
	if (skill > 500)
		imp_skill /= skill / 100 - 5 + 2;
	if ( me->query("int") >23)
		imp_skill += imp_skill*( me->query("int")-23)*4/300;
	if (imp_skill < 2)
		imp_skill = 2;
	//jing_cost = 1000 / intlv;
	//jing_cost = 0;*/
  
  imp_skill = (int)me->query_int()/5;
  imp_skill = imp_skill * SPEWEEK_D->query_learn_bonus()/100; //special week effect
  if (member_array(arg,adv_weapon)!=-1)
  {
    if (me->query("adv_weapon/class/"+arg+"/lv")>=8)
      imp_skill=imp_skill/1*5;
    if (me->query("adv_weapon/class/"+arg+"/lv")>=11)
      imp_skill=imp_skill/1*5;
  }
  exp=benefit(me,imp_skill*lingwu_times);
  me->improve_skill(arg,(exp-1)/2);
  tell_object(me,"你花费了" + chinese_number(lingwu_times) + "点潜能升级" + to_chinese(arg) + "。\n"); 
me->add("potential",-lingwu_times);  
 //}
  return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : lingwu <技能> <次数>

这个指令可以让你在特定地点领悟提高基本武功，比如过阵以后在达摩院二层领悟。

HELP
         );
    return 1;
}

