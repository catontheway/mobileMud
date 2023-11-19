// huntian-qigong.c
// written by Xiang
#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) 
{ 
   return usage == "force"; 
}

/*
int valid_learn()
// need more limit here
{
	return 1;
}
*/

int practice_skill(object me)
{
	return notify_fail("混天气功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return SKILL_D("huntian-qigong/") + func;
}

int force_character(string char_type)
{
	int recv;
	recv=::force_character(char_type);
	switch(char_type)
	{
    case "TYPE_ENFORCE":
      return 12;
	  default:
	  	return recv;
	}
}
mapping exercise_msg(object me)
{
	return ([
		"status_msg" : "面带神光，衣袍飞舞" NOR,
		"start_my_msg" : "随意坐下，双手平放在双膝，默念口诀，开始运起独门心法。\n",
		"start_other_msg" : me->name()+"随意坐下，双手平放在双膝，嘴唇微微颤动，身上的衣袍开始鼓动起来。\n",
		"heal_my_msg" : "盘膝而坐，开始运功疗伤，衣袍似鼓风般向四周飘开。\n",
        "heal_other_msg" :  me->name() + "盘膝而坐，开始运功疗伤，衣袍似鼓风般向四周飘开。\n",
		"halt_msg" : "面色一沉，迅速收气，站了起来。\n",
		"end_my_msg" : "吸气入丹田，真气运转渐缓，慢慢收功，双手抬起，站了起来。\n",
		"end_other_msg" : "只见"+me->name()+"双手抬起，站了起来，衣袍慢慢垂了下来。\n",
		"hover_my_msg" : "吐气收功，衣袍缓缓落下，浑身汗如雨下。\n",
        "hover_other_msg" : me->name() + "吐气收功，衣袍缓缓落下，神完气足。\n",
		
	]);
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int ap,dp,damage1,damage2,damage,liannum;
	damage1 = (int)me->query_skill("huntian-qigong",1);
	damage2 = (int)me->query_skill("huntian-qigong",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	ap = me->query_skill("huntian-qigong",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	dp = victim->query_skill("force",1)*(victim->query("breakup")+victim->query("breakup")*victim->query("breakup")+100)/100;
	if( me->query_temp("lianzhao")>=1) liannum=me->query_temp("lianzhao");
	else liannum =1;
    if( me->query("neili") < 100 || me->query("jingli") < 100 || damage_bonus < 100 ) return 0;
	if ( me->query_skill("huntian-qigong",1) < 100 ) return 0;
	if ( me->query_skill_mapped("force") != "huntian-qigong") return 0;
	
	if ( random(ap) > dp/3 && random(7)==1 && me->query("jiali") > 0) 
	{
		damage = (damage1+damage_bonus)*(liannum+20)/(20*liannum+1);
		victim->receive_damage("qi", damage ,me);
		victim->receive_wound("qi", damage/3 ,me);
		me->add("neili", -100 );
		message_vision(HIB "$N发挥出"+HIR+"混天气功"NOR HIB"的精髓，混元内劲摧毁了$n的真元！！！！\n" NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
		return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiajing")>0 && random(7)==2 && (int)me->query("breakup")>1 )
	{
		damage = (damage2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("jingli",-100);
		victim->receive_damage("jing", damage,me);
		victim->receive_wound("jing", damage/3,me);
		message_vision(HIG "$N顿悟"+me->query("cognize")+HIG"，一股混元真气击破了$n的劳宫穴。\n" NOR, me,victim,damage,HBWHT+HIR"特效伤精"NOR);
		return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiali")>0 && random(7)==3 && (int)me->query("jm/gaibang") )
	{
		damage = ((damage1+damage2)/2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("neili",-100);
		victim->receive_damage("qi", damage,me);
		victim->receive_wound("qi", damage/3,me);
		message_vision(HIC "$N领悟丐帮武功精髓，掌力阴阳交融，勇猛无匹。\n" NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
		return ;
	}
}
