// beiming-shengong.c 北冥神功.c
// by paladin
// Modified by iszt@pkuxkx, 2007-03-19, no other force allowed
#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage == "force" ||(usage == "parry");}
int valid_learn(object me)
{
	mapping fam;
	mapping skills;
	int i;

/*
        if (!(fam = this_player()->query("family"))
        || (fam["family_name"] != "天龙寺" 
        && fam["family_name"] != "灵鹫宫"
        && this_player()->query("chushi/last_family") != "天龙寺"
        && this_player()->query("chushi/last_family") != "灵鹫宫"
        ))
		return notify_fail("你的师傅会这个吗？\n");
*/
        if (this_player()->query("family/family_name") != "天龙寺" 
         && this_player()->query("family/family_name") != "灵鹫宫"
         && this_player()->query("chushi/last_family") != "天龙寺"
         && this_player()->query("chushi/last_family") != "灵鹫宫" )
                return notify_fail("你的师傅会这个吗？\n");

	if ((int)me->query_skill("force", 1) < 100)
		return notify_fail("你的基本内功火候不足，不能学北冥神功。\n");

	skills = me->query_skills();
	for(i=0; i<sizeof(skills); i++)
		if(load_object(SKILL_D(keys(skills)[i]))->valid_enable("force")
			&& keys(skills)[i] != "beiming-shengong"
      && keys(skills)[i] != "bahuang-gong"
      && keys(skills)[i] != "xiaowuxiang-gong"
      && keys(skills)[i] != "kurong-shengong"
      && keys(skills)[i] != "yijin-jing"
      && this_player()->query("reborn/all")!=1)
			return notify_fail("北冥神功举世无双，你必须先放弃普通的内功。\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("北冥神功只能用学(learn)的来增加熟练度。\n");
}
string *parry_msg = ({
	"只见$n将手中$v左一带，右一带，轻轻的将$N的$w各了开去。\n",
	"$n用手中$v在$N的$w上轻轻一搭，\n$N的$w就如着了魔法一般，荡了开去。\n",
});

string *unarmed_parry_msg = ({
	"但是$n用左手轻轻一推$N的$w，\n$N的$w就如着了魔法一般，荡了开去。\n",
	"$n左手轻轻推出，拍向$N的$w，$N的攻击被移的无影无踪。\n",
});

string query_parry_msg(object weapon)
{
	if( weapon )
		return parry_msg[random(sizeof(parry_msg))];
	else
		return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

string exert_function_file(string func)
{
	return __DIR__"beiming-shengong/" + func;
}

int force_character(string char_type)
{
	int recv;
	recv=::force_character(char_type);

	switch(char_type)
	{
		case "TYPE_RECOVER":     //TYPE_RECOVER
			return 80;
	  case "TYPE_REC_CD":     //TYPE_REC_CD
	  	return 8;
    case "TYPE_SUCK_EFF":
      return 25;
	  case "TYPE_SPECIAL_NEILI_EFF": // corporeity 特技对内力最大值的影响
	    return 25;
	  default:
	  	return recv;
	}
}

//北冥神功的最大内力为特别设置
int query_max_neili(object ob)
{
  int maxn;
  maxn=ob->query_skill("force")*(ob->query("con")+10)/2;
  if ( 20*ob->query_skill("force") + 200*ob->query("con") < maxn )
    maxn=20*ob->query_skill("force") + 200*ob->query("con");
  return maxn;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int ap,dp,damage1,damage2,damage,maxnei,liannum;
	damage1 = (int)me->query_skill("beiming-shengong",1);
	damage2 = (int)me->query_skill("beiming-shengong",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	ap = me->query_skill("beiming-shengong",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	dp = victim->query_skill("force",1)*(victim->query("breakup")+victim->query("breakup")*victim->query("breakup")+100)/100;
	maxnei = (int)me->query("max_neili");
	if( me->query_temp("lianzhao")>=1) liannum=me->query_temp("lianzhao");
	else liannum =1;
    if ( me->query("neili") < 100 || me->query("jingli") < 100 || damage_bonus < 100) return 0;
	if ( me->query_skill("beiming-shengong",1) < 100) return 0;
	if ( me->query_skill_mapped("force") != "beiming-shengong") return 0;
	if (me->query("jm/xiaoyao")) maxnei = (int)me->query("max_neili")*2;
	if ( random(ap) > dp/3 && random(7)==1 && me->query("jiali") > 0) 
	{
		damage = (damage1+damage_bonus)*(liannum+20)/(20*liannum+1);
		victim->receive_damage("qi", damage ,me);
		victim->receive_wound("qi", damage/3 ,me);
		me->add("neili",-100);
		if (me->query("neili") < maxnei)  me->add("neili", damage );
		if (victim->query("neili") > damage) victim->add("neili",-damage );
		message_vision(HIB "$N发挥出"+HIR+"北冥神功的“吸”字诀，吸走了$n的真元！！！！\n" NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
		return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiajing")>0 && random(7)==2 && (int)me->query("breakup")>1 )
	{
		damage = (damage2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("jingli",-100);
		victim->receive_damage("jing", damage,me);
		victim->receive_wound("jing", damage/3,me);
		if (me->query("qi") < me->query("eff_qi"))  me->add("neili", damage2 );
		message_vision(HIR "北冥之海，海纳百川，$N发挥出"+me->query("cognize")+HIR"的力量，将$n气血吸走了不少。\n" NOR, me,victim,damage,HBWHT+HIR"特效伤精"NOR);
		return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiali")>0 && random(7)==3 && (int)me->query("jm/xiaoyao") )
	{
		damage = ((damage1+damage2)/2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("neili",-100);
		victim->receive_damage("qi", damage,me);
		victim->receive_wound("qi", damage/3,me);
		if (me->query("neili") < maxnei)  me->add("neili", damage );
		if (victim->query("neili") > damage) victim->add("neili",-damage );
		message_vision(HIR "$N领悟逍遥派的武学之精义，以有余而补不足。\n" NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
		return ;
	}
}
