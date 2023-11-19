// dashou-yin.c 密宗大手印
//  by iceland
#include <ansi.h>
inherit SKILL;

mapping *action = (
{
([      "action" : "$N使出一招「莲花合掌印」，双掌合十，直直撞向$n的前胸",
"skill_name" : "莲花合掌印",
	"attack":	200,
	"parry":	200,
	"dodge":	200,
	"damage":	200,
	"force":	200,
	"lvl" : 0,
"damage_type" : "瘀伤",
	 ]),
([      "action" : "$N使出一招「合掌观音印」，飞身跃起，双手如勾，抓向$n的$l",
"skill_name" : "合掌观音印",
	"attack":	300,
	"parry":	300,
	"dodge":	300,
	"damage":	300,
	"force":	300,
	"lvl" : 8,
"damage_type" : "瘀伤",
	 ]),
([      "action" : "$N使出一招「准提佛母印」，运力于指，直取$n的$l",
"skill_name" : "准提佛母印",
	"attack":	300,
	"parry":	300,
	"dodge":	300,
	"damage":	300,
	"force":	300,
	"lvl" : 16,
"damage_type" : "瘀伤",
	 ]),
([      "action" : "$N使出一招「红阎婆罗印」，怒吼一声，一掌当头拍向$n的$l",
"skill_name" : "红阎婆罗印",
	"attack":	400,
	"parry":	400,
	"dodge":	400,
	"damage":	400,
	"force":	400,
	"lvl" : 24,
"damage_type" : "瘀伤",
	 ]),
([      "action" : "$N使出一招「药师佛根本印」，猛冲向前，掌如游龙般攻向$n",
"skill_name" : "药师佛根本印",
	"attack":	400,
	"parry":	400,
	"dodge":	400,
	"damage":	400,
	"force":	400,
	"lvl" : 32,
"damage_type" : "瘀伤",
	 ]),
([      "action" : "$N使出一招「威德金刚印」，伏身疾进，双掌自下扫向$n的$l",
"skill_name" : "威德金刚印",
	"attack":	500,
	"parry":	500,
	"dodge":	500,
	"damage":	500,
	"force":	500,
	"lvl" : 40,
"damage_type" : "瘀伤",
	 ]),
([      "action" : "$N使出一招「上乐金刚印」，飞身横跃，双掌前后击出，抓向$n的咽喉",
"skill_name" : "上乐金刚印",
	"attack":	500,
	"parry":	500,
	"dodge":	500,
	"damage":	500,
	"force":	500,
	"lvl" : 48,
"damage_type" : "瘀伤",
	 ]),
([      "action" : "$N使出一招「六臂智慧印」，顿时劲气弥漫，天空中出现无数掌影打向$n的$l",
"skill_name" : "六臂智慧印",
	"attack":	600,
	"parry":	600,
	"dodge":	600,
	"damage":	600,
	"force":	600,
	"lvl" : 56,
"damage_type" : "瘀伤",
	 ]),
});

int valid_enable(string usage) { return usage == "hand" || usage == "parry"; }

//int valid_combine(string combo) { return combo=="tianwang-zhua"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练密宗大手印必须空手。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱了，练不了密宗大手印。\n");
        if ((int)me->query_skill("longxiang-boruo", 1) < 20)
                return notify_fail("你的龙象般若功火候太浅，不能学密宗大手印。\n");
        if ((int)me->query_skill("force", 1) < 20)
                return notify_fail("你的基本内功火候太浅，不能学密宗大手印。\n");
                return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("dashou-yin",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
//      object weapon;

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练密宗大手印必须空手。\n");
        if ((int)me->query("qi") < 40)
                return notify_fail("你的体力不够，练不了密宗大手印。\n");
        if ((int)me->query("neili") < 40)
                return notify_fail("你的内力不够，练不了密宗大手印。\n");
        me->receive_damage("qi", 20);
        me->add("neili", -5);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"dashou-yin/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int ap,dp,damage1,damage2,damage,liannum;
	damage1 = (int)me->query_skill("dashou-yin",1);
	damage2 = (int)me->query_skill("dashou-yin",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	ap = me->query_skill("dashou-yin",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	dp = victim->query_skill("force",1)*(victim->query("breakup")+victim->query("breakup")*victim->query("breakup")+100)/100;
	if( me->query_temp("lianzhao")>=1) liannum=me->query_temp("lianzhao");
	else liannum =1;
    if ( me->query("neili") < 100 || me->query("jingli") < 100 || damage_bonus < 100) return 0;
	if ( (me->query_skill("xiaowuxiang",1) < 100 && me->query_skill("longxiang",1) < 100) || me->query_skill("dashou-yin",1) < 100)	 return 0;
//	if ( me->query_skill_mapped("force") != "xiaowuxiang" && me->query_skill_mapped("force") != "longxiang") return 0;
	if (objectp(me->query_temp("weapon"))) return 0;
	if (me->query_skill_mapped("force") == "xiaowuxiang") damage1 += random(damage1);

	if( random(ap) > dp/3 && random(7)==1 && me->query("jiali")>0 )
	{
		damage = (damage1+damage_bonus)*(liannum+20)/(20*liannum+1);
		victim->receive_damage("qi", damage ,me);
		victim->receive_wound("qi", damage/3 ,me);
		me->add("neili",-100);
		message_vision(HIR "$N右手摆在胸前，中指微曲，拇指搭在中指侧，其余三指展开如莲花初放，念道：“叭”，只见淡淡的红光包围$n。！\n" NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
		return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiajing")>0 && random(7)==2 && (int)me->query("breakup")>1 )
	{
		damage = (damage2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("jingli",-100);
		victim->receive_damage("jing", damage,me);
		victim->receive_wound("jing", damage/3,me);
		message_vision(HIG "$N顿悟"+me->query("cognize")+HIG"，一掌落下，突然变大，声势浩荡。\n" NOR, me,victim,damage,HBWHT+HIR"特效伤精"NOR);
		return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiali")>0 && random(7)==3 && (int)me->query("jm/xueshan") )
	{
		damage = ((damage1+damage2)/2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("neili",-100);
		victim->receive_damage("qi", damage,me);
		victim->receive_wound("qi", damage/3,me);
		message_vision(HIC "$N破解雪山寺的绝技，双掌平推，至$n身前，突然掌印变大，$n被击飞数步。\n" NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
		return ;
	}
}

