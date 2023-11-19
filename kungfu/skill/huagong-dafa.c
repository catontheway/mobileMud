// huagong-dafa.c 化功大法c
// by yucao
// modified by cleansword
// Modified by iszt@pkuxkx
// Modified by iszt@pkuxkx, 2007-03-20, no other force allowed
#include <ansi.h>
inherit FORCE;
int valid_enable(string usage) { return usage == "force"; }
int valid_learn(object me)
{
        int i = (int)me->query_skill("huagong-dafa", 1);
        int t=-1,j;
        mapping skills;

        t = -i/80*i*i - 1;
        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("你的基本内功火候不足，不能学化功大法。\n");
        if (i > 100 && (int)me->query("shen") > t && (int)me->query("shen") > -5000000) 
                return notify_fail("学化功大法，要心狠手辣，奸恶歹毒，你可做得不够呀！\n");

        if ((int)me->query_skill("poison", 1) < 350 && (int)me->query_skill("poison", 1) < i / 2)
                 return notify_fail("你用毒的功夫还不到家，学不了化功大法。\n");  

        if ( me->query_skill("buddhism",1) || me->query_skill("taoism",1) )
                return notify_fail("你练了秃驴牛鼻子们的心法，还学化功大法做什么！\n");


                
        skills = me->query_skills();
        for(i=0; i<sizeof(skills); i++)
        {
                //不能出师去星宿，严格限制，注意！ by Jpei
                //if(me->query("chushi/done") && me->query("chushi/last_family")!="星宿派")
                       //return 1;
                if(load_object(SKILL_D(keys(skills)[i]))->valid_enable("force")
                  && keys(skills)[i] != "huagong-dafa"
                  && keys(skills)[i] != "xiaowuxiang-gong")
                       return notify_fail("你不先散了别派内功，怎能学化功大法？！\n");
        }
        return 1;
}

void skill_improved(object me)
{
        int skill, poison;
        skill = me->query_skill("huagong-dafa", 1);
        poison = me->query_skill("poison", 1);

        if(skill >= 50 && !me->query("xingxiu/hgdf") && poison > 50){
                tell_object(me, HIY"冥冥中你感觉到体内的化功大法和毒技相互相济，使你的内力修为有所提高！\n"NOR);
                me->add("max_neili", (150-poison>10) ? 150-poison : 10);
                me->set("xingxiu/hgdf", 1);
                }
        if(skill >= 150 && me->query("xingxiu/hgdf")==1 && poison > 100){
                tell_object(me, HIY"冥冥中你感觉到体内的化功大法和毒技相互相济，使你的精力修为有所提高！\n"NOR);
                me->add("max_jingli", 100);
                me->set("xingxiu/hgdf", 2);
                }
        if(skill >= 250 && me->query("xingxiu/hgdf")==2 && poison > 150){
                tell_object(me, HIY"冥冥中你感觉到体内的化功大法和毒技相互相济，使你的武功修为有所提高！\n"NOR);
                me->add("combat_exp", 200000);
                me->add("exp/huagong", 200000);
                me->set("xingxiu/hgdf", 3);
                }
        if(skill >= 350 && me->query("xingxiu/hgdf")==3 && poison > 200){
                tell_object(me, HIY"冥冥中你感觉到体内的化功大法和毒技相互相济，使你的属性有所提高！\n"NOR);
                me->add("con", 2);
                me->add("xiantian/con/huagong", 2);
                me->set("xingxiu/hgdf", 4);
                }
}


int practice_skill(object me)
{
        return notify_fail("化功大法只能用学(learn)的来增加熟练度。\n");
}
string exert_function_file(string func)
{
        return __DIR__"huagong-dafa/" + func;
}

int force_character(string char_type)
{
	int recv;
	recv=::force_character(char_type);
	switch(char_type)
	{
		case "TYPE_RECOVER":          //TYPE_RECOVER
			return 80;
	  case "TYPE_REC_CD":          //TYPE_REC_CD
	  	return 8; 
    case "TYPE_SUCK_EFF":
      return 15;
	  case "TYPE_SPECIAL_NEILI_EFF": // corporeity 特技对内力最大值的影响
	    return 75;
	  default:
	  	return recv;
	}
}

mapping buffer_applied(object ob)
{
    mapping buf, tbuf;
    int lv1, lv2, gint, pflv;
    
    lv1=ob->query_skill("huagong-dafa",1);
    lv2=ob->query_skill("chousui-zhang",1);
    gint=ob->query("con");
    buf=([]);
    
   // if ( !ob->query("huashan_newskills/qizong") )
     // return buf;

    if ( lv1<=60 || lv2<=60 )
      return buf;
      
    if ( mapp(ob->query_temp("passive/huagong-dafa")) )
      return buf;
    
	pflv = (int)ob->query("purefamily/level");
    if (pflv>0 && ob->query("purefamily/family_name") != "大轮寺")	pflv = 0;

    buf["max_qi"]=(lv2/10 + lv1/5)*(100+gint)*2;
	 buf["max_neili"]=lv1*20;
    buf["max_jing"]=(lv2/10 + lv1/15)*(100+gint)*1;
    ob->set_temp("passive/huagong-dafa", buf);
//     ob->set_temp("active_force_buffer/huagong-dafa/name", "大龙象护体");                              //buff名称
    ob->set_temp("active_force_buffer/huagong-dafa/effect1", "最大气血+"+(buf["max_qi"])+"点");     //效果描述1
    ob->set_temp("active_force_buffer/huagong-dafa/effect2", "最大精神+"+(buf["max_jing"])+"点");
    ob->set_temp("active_force_buffer/huagong-dafa/effect5", "最大内力+"+(buf["max_neili"])+"点");	//效果描述2
	if (pflv>=5)
	{
		buf["kf_hit_rate"] = 10;
		buf["deep_injure"] = 5;
		ob->set_temp("active_force_buffer/huagong-dafa/effect3", "技能命中提升+10%");   //效果描述2
		ob->set_temp("active_force_buffer/huagong-dafa/effect4", "普通伤害增益+5%");   //效果描述2
	}
    return buf;
}
mapping buffer_removed(object ob)
{
    mapping buf;
    
    buf=ob->query_temp("passive/huagong-dafa");;
    if ( mapp(buf) )
    {
      buf["max_qi"]=buf["max_qi"]*(-1);
      buf["max_jing"]=buf["max_jing"]*(-1);
	  buf["kf_hit_rate"]=buf["kf_hit_rate"]*(-1);
	  buf["deep_injure"] = buf["deep_injure"]*(-1);
	  buf["strength"] = buf["strength"]*(-1);
    }
    else
      buf=([]);

    ob->delete_temp("passive/huagong-dafa");
    ob->delete_temp("active_force_buffer/huagong-dafa");
    return buf;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int ap,dp,damage1,damage2,damage,liannum;
	damage1 = (int)me->query_skill("huagong-dafa",1);
	damage2 = (int)me->query_skill("huagong-dafa",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	ap = me->query_skill("huagong-dafa",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	dp = victim->query_skill("force",1)*(victim->query("breakup")+victim->query("breakup")*victim->query("breakup")+100)/100;
	if( me->query_temp("lianzhao")>=1) liannum=me->query_temp("lianzhao");
	else liannum =1;
    if( me->query("neili") < 100 || me->query("jingli") < 100 || damage_bonus < 100 ) return 0;
	if ( me->query_skill("huagong-dafa",1) < 100) return 0;
	if ( me->query_skill_mapped("force") != "huagong-dafa") return 0;

	if ( random(ap) > dp/3 && random(7)==1 && me->query("jiali") > 0) 
	{
		damage = (damage1+damage_bonus)*(liannum+20)/(20*liannum+1);
		victim->receive_damage("qi", damage ,me);
		victim->receive_wound("qi", damage/3 ,me);
		victim->add("neili",-damage );
		me->add("neili", -100 );
		message_vision(HIB "$N发挥出"+HIR+"化功大法"NOR HIB"的真髓，化掉了$n的真元！！！！\n" NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
		return ;	
	}
	if( random(ap) > dp/3 && (int)me->query("jiajing")>0 && random(7)==2 && (int)me->query("breakup")>1 )
	{
		damage = (damage2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("jingli",-100);
		victim->add("jingli",-damage );
		victim->receive_damage("jing", damage,me);
		victim->receive_wound("jing", damage/3,me);
		message_vision(HIG "$N气聚丹田，强行提升到"+me->query("cognize")+HIG"，将$n精气化掉了不少。\n" NOR, me,victim,damage,HBWHT+HIR"特效伤精"NOR);
		return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiali")>0 && random(7)==3 && (int)me->query("jm/xingxiu") )
	{
		damage = ((damage1+damage2)/2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("neili",-100);
		victim->add("jingli",-damage );
		victim->receive_damage("qi", damage,me);
		victim->receive_wound("qi", damage/3,me);
		victim->apply_condition("sanpoison", victim->query_condition("sanpoison") + 5);
		message_vision(HIC "$N贯通星宿派毒功，真气攻入$n经脉，$n顿时吐出一口黑血。\n" NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
		return ;
	}
}
//化工大法的最大内力为特别设置
//由于化工大法的最大内力相对来说没有优势，所以suck类内力的杂质含量设置为15%，相比来说也更低一点
int query_max_neili(object ob)
{
  return (400+ob->query("con") )*ob->query_skill("force")/30;
}