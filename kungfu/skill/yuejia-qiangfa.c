// Modified by iszt@pkuxkx, 2007-04-07

inherit SKILL;

#include <ansi.h>
mapping *action = ({
([
	"action":
HIW"$N"+HIW"使出一招「气吞山河」，手中的$w"+HIW"画了数圈，又一个急转，向$n"+HIW"的$l刺来"NOR,
	"dodge" : 20,
	"force" : 100,
	"damage" : 150,
	"lvl" : 20,
	"skill_name" : "气吞山河",
	"damage_type" : "刺伤"
	]),
([
	"action":
HIW"$N"+HIW"手中的$w"+HIW"突然从手中跃起，一招「还我河山」，扫向$n"+HIW"的$l"NOR,
	"dodge" : 2,
	"force" : 150,
	"damage" : 200,
	"lvl" : 40,
	"skill_name" : "还我河山",
	"damage_type" : "刺伤"
]),
([
	"action":
HIW"$N"+HIW"把枪一竖，一招「运筹帷幄」，身形借枪之力腾空跃起，手中$w"+HIW"从天而降，指向$n"+HIW"的$l"NOR,
	"dodge":	200,
	"force" : 110,
	"damage" : 160,
	"lvl" : 80,
	"skill_name" : "运筹帷幄",
	"damage_type" : "刺伤"
]),
([
	"action":
HIW"$N"+HIW"将手中$w"+HIW"一横，身体一转,$w"HIW"又从跨下刺出,一招「万川归一」对准$n"+HIW"的面部袭来"NOR,
	"dodge" : 0,
	"force" : 250,
	"damage" : 300,
	"lvl" : 120,
	"skill_name" : "万川归一",
	"damage_type" : "刺伤"
]),
([
	"action":
HIW"$N"+HIW"枪势一收，仰天一声长啸，手中$w"+HIW"突然暴起，一招「仰天长啸」向$n"+HIW"刺去"NOR,
	"dodge" : 40,
	"force" : 300,
	"damage" : 350,
	"lvl" : 160,
	"skill_name" : "仰天长啸",
	"damage_type" : "刺伤"
	]),
([
	"action":
HIW"$N"+HIW"左手一反，右手单臂握$w"+HIW"，使出一招「怒发冲冠」直指向$n"+HIW"的$l"NOR,
	"dodge" : 300,
	"force" : 350,
	"damage" : 400,
	"lvl" : 200,
	"skill_name" : "怒发冲冠",
	"damage_type" : "刺伤"
]),
([
	"action":
HIW"$N"+HIW"手中$w"+HIW"轻轻一晃，$w"+HIW"化为一道电光，却不禁神色黯然的使出「潇潇雨歇」刺向$n"+HIW"的$l"NOR,
	"dodge" : 30,
	"force" : 450,
	"damage" : 500,
	"lvl" : 230,
	"skill_name" : "潇潇雨歇",
	"damage_type" : "刺伤"
]),
([
	"action":
HIW"$N"+HIW"突然想起岳王爷不由得悲从心头起，使出「岳家枪法」最厉害的一招「夺魄连环」，手中$w"+HIW"闪电般的直奔$n"+HIW"胸口而去"NOR,
	"dodge" : 60,
	"force" : 600,
	"damage" : 800,
	"lvl" : 250,
	"skill_name" : "夺魄连环",
	"damage_type" : "刺伤"
]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_neili") < 150 )
		return notify_fail("你的内力不够，没有办法练岳家枪法。\n");

	if( !(ob = me->query_temp("weapon"))
	||      (string)ob->query("skill_type") != "spear" )
		return notify_fail("你必须先找一杆枪才能练此枪法。\n");

	return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level, actionnuma, actionnumb, maxnum;
		for( i=0 ; i < sizeof(action) ; i++ )
			if ( action[i]["lvl"] <= me->query_skill("yuejia-qiangfa",1) )
			{
			maxnum = i;
			}
		if ( me->query_temp("yuejia_lianhuan") > 2 )
		{
			actionnuma = me->query_temp("yuejia_lianhuan")-3;
			actionnumb = me->query_temp("yuejia_lianhuan")-2;
		}
		else
		{
			actionnuma = 0;
			actionnumb = 1;
		}
		if ( actionnuma > maxnum )
		{
			actionnuma = maxnum;
		}
		if ( actionnumb > maxnum )
		{
			actionnumb = maxnum;
		}
		if ( me->query_temp("yuejia_lianhuan_num") == 1 )
		{
			return action[actionnuma];
		}
		if ( me->query_temp("yuejia_lianhuan_num") == 2 )
		{
			return action[actionnumb];
		}
		else
	    {
			level = (int) me->query_skill("yuejia-qiangfa",1);
			for(i = sizeof(action); i > 0; i--)
				if (level > action[i-1]["lvl"])
				    return action[NewRandom(i, 20, level/5)];
		}
		
}

int valid_enable(string usage)
{
	return usage=="spear"|| usage == "parry" ;
}

int valid_combine(string combo) { return combo=="yuejia-qiangfa"; }

int practice_skill(object me)
{
	if( (int)me->query("qi") < 30
	||	(int)me->query("neili") < 50 )
		return  notify_fail("你的内力或气不够，没有办法练习岳家枪法。\n");
	if(me->query_skill("yuejia-qiangfa",1)>50)
		return notify_fail("你现在只能在岳王墓中观看墙壁才能继续提高岳家枪法。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -40);
	return 1;
}

string *parry_msg = ({
	HIR"$n"+HIR"以攻代守，$v"+HIR"直向$N"+HIR"刺去。$N"+HIR"吓的连退数步，撤回了攻势。"NOR,
	HIR"$n"+HIR"连滚带爬勉强躲了开去。"NOR,
});

string *unarmed_parry_msg = ({
	HIR"$n"+HIR"将手中的$v"+HIR"连续刺出，挡住$N"+HIR"的全部攻势。"NOR,
});

string query_parry_msg(object weapon)
{
	if( weapon )
		return parry_msg[random(sizeof(parry_msg))];
	else
		return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

string perform_action_file(string action)
{
	return __DIR__"yuejia-qiangfa/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{
	int ap,dp, damage1,damage2,damage,liannum;
	object weapon;
	weapon = me->query_temp("weapon");
    ap = me->query_skill("yuejia-qiang",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	dp = victim->query_skill("dodge",1)*(victim->query("breakup")+victim->query("breakup")*victim->query("breakup")+100)/100;
    damage1= (int) me->query_skill("yuejia-qiang",1);
	damage2 = (int)me->query_skill("yuejia-qiang",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	if( me->query_temp("lianzhao")>=1) liannum=me->query_temp("lianzhao");
	else liannum =1;
	if( me->query("neili") < 100 || me->query("jingli") < 100 || damage_bonus < 100 ) return 0;
	if ( me->query_skill("yuejia-qiang",1)<100) return 0;
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "spear") return 0;
//	if ( me->query_skill_mapped("force") != "yijing-force") return 0;

	if (random(7)==1 && random(ap) > dp/3 && me->query("jiali") > 0)
	{
		damage = (damage1+damage_bonus)*(liannum+20)/(20*liannum+1);
		victim->receive_damage("qi", damage ,me);
		victim->receive_wound("qi", damage/3 ,me);
		me->add("neili", -100);
		message_vision(HIG"$N使出一招「八千里路云和月」，整个人消失在一团枪影之中！\n"NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
        return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiajing")>0 && random(7)==2 && (int)me->query("breakup")>1 )
	{
		damage = (damage2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("jingli",-100);
		victim->receive_damage("jing", damage,me);
		victim->receive_wound("jing", damage/3,me);
		if (!victim->is_busy()) victim->start_busy(1);
		message_vision(HIG "$N顿悟"+me->query("cognize")+HIG"，使出一招「怒发冲冠」，将手中的" + weapon->name() + HIG "舞得密不透风，挺枪直刺，将$n捅上天了。\n" NOR, me,victim,damage,HBWHT+HIR"特效伤精"NOR);
		return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiajing")>0 && random(7)==3 && (int)me->query("jm/tiezhang") )
	{
		damage = ((damage1+damage2)/2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("jingli",-100);
		victim->receive_damage("qi", damage,me);
		victim->receive_wound("qi", damage/3,me);
		message_vision(HIG "$N顿悟"+me->query("cognize")+HIG"，使出一招「三十功名尘与土」，手中的" + weapon->name() + HIG "冲天而起，万军从中直取敌将。\n" NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
		return ;
	}
}

//2017.3.25阿飞封掉ob_hit特效，怀疑与伤害为0的死亡有关
int ob_hit(object ob, object me, int damage)
{
	string msg;
	int ap,dp,j,damage1,damage2;
	object weapon;
	weapon = me->query_temp("weapon");
	ap = me->query_skill("yuejia-qiang", 1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	dp = ob->query_skill("spear",1)*(ob->query("breakup")+ob->query("breakup")*ob->query("breakup")+100)/100;
	damage1 = me->query_skill("yuejia-qiang", 1);
	damage2 = me->query_skill("yuejia-qiang", 1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	if( damage < 10 ) damage=10;
	if( me->query("neili") < 100 || me->query("jingli") < 100 ) return damage;
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "spear") return damage;
	if (me->query_skill("yuejia-qiang", 1) < 300) return damage;
//	if ( me->query_skill_mapped("force") != "yijing-force") return damage;

	if ( random(8) == 1 && random(ap) > dp/4 )
	{
        msg = HIY"$N豪气干云，吟道：「笑谈渴饮匈奴血」，手中的" + weapon->name() + HIY "由下而上，荡出了几道枪气，让$n不知所措！\n"NOR;
		if (!ob->is_busy()) ob->start_busy(1);
		me->add("neili", -100 );
		j = -(damage+random(damage));
		message_vision(msg, me, ob);
		return j;
	}
	if(random(ap) > dp/4 && random(8)==2 && (int)me->query("breakup")>1 )
	{
		j = -(damage/2+random(damage/2));
		ob->receive_damage("jing",damage2,me);
		ob->receive_wound("jing",damage2/2,me);
		me->add("jingli", -100 );
		if (!ob->is_busy()) ob->start_busy(1);
		message_vision(HIY"$N顿悟"+me->query("cognize")+HIY"，吟道：「凭栏处，潇潇雨歇」，手中的" + weapon->name() + HIY "舞得密不透风，将$n封于丈外。\n"NOR, me, ob,damage2,HBWHT+HIY"精神反伤"NOR);
		return j;
	}
	if(random(ap) > dp/4 && random(8)==3 && (int)me->query("jm/tiezhang") )
	{
		j = -(damage/2+random(damage/2));
		ob->receive_damage("qi",damage1,me);
		ob->receive_wound("qi",damage1/2,me);
		me->add("neili", -100 );
		message_vision(HIY"$N慷慨的诵道：「莫等闲白了少年头，空悲切」，手中的"+weapon->name()+HIY"化做漫天残照，荡开了$n。\n"NOR, me, ob,damage1,HBWHT+HIY"气血反伤"NOR);
		return j;
	}
}
