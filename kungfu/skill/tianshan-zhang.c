// tianshan-zhang.c 天山杖法	下乘武学100~300

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([  "action": "$N高举$w, 一招"+(order[random(13)])+"「雪海冰雹」"NOR"，从天而降砸向$n的$l",
		"attack":	100,
		"parry":	100,
		"dodge":	100,
		"damage":	100,
		"force":	100,
        "lvl" : 3,
        "damage_type": "砸伤"
]),

([  "action": "$N使出一招"+(order[random(13)])+"「天山雪野」"NOR"，手中$w封住下盘扫向$n的$l",
		"attack":	100,
		"parry":	100,
		"dodge":	100,
		"damage":	100,
		"force":	100,
        "lvl" : 5,
        "damage_type": "砸伤"
]),

([  "action": "$N使出一招"+(order[random(13)])+"「满天飞雪」"NOR"，挥动手中$w从各个方向点往$n的$l",
		"attack":	200,
		"parry":	200,
		"dodge":	200,
		"damage":	200,
		"force":	200,
        "lvl" : 55,
        "damage_type": "刺伤"
]),

([  "action": "忽听得呼一声猛响，$N一招"+(order[random(13)])+"「雪峰插云」"NOR"，手握$w飞身砸向$n的$l",
		"attack":	200,
		"parry":	200,
		"dodge":	200,
		"damage":	200,
		"force":	200,
        "lvl" : 79,
        "damage_type": "砸伤"
]),
([	"action": "$N使出一招"+(order[random(13)])+"「冰河开冻」"NOR"，手中$w大开大阖扫向$n的$l",
		"attack":	200,
		"parry":	200,
		"dodge":	200,
		"damage":	200,
		"force":	200,
	"lvl" : 1,
	"damage_type": "挫伤"
]),
([	"action": "$N手中$w阵阵风响，一招"+(order[random(13)])+"「山风凛冽」"NOR"向$n的$l攻去",
		"attack":	200,
		"parry":	200,
		"dodge":	200,
		"damage":	200,
		"force":	200,
	"lvl" : 13,
	"damage_type": "挫伤"
]),
([	"action": "$N举起$w，居高临下使一招"+(order[random(13)])+"「天山雪崩」"NOR"砸向$n的$l",
		"attack":	200,
		"parry":	200,
		"dodge":	200,
		"damage":	200,
		"force":	200,
	"lvl" : 30,
	"damage_type": "挫伤"
]),
([	"action": "$N一招"+(order[random(13)])+"「残阳照雪」"NOR"，纵身飘开数尺，手中$w砸向$n的$l",
		"attack":	200,
		"parry":	200,
		"dodge":	200,
		"damage":	200,
		"force":	200,
	"lvl" : 45,
	"damage_type": "挫伤"
]),
([	"action": "$N使一招"+(order[random(13)])+"「回光幻电」"NOR"，手中$w幻一条疾光点向$n的$l",
		"attack":	200,
		"parry":	200,
		"dodge":	200,
		"damage":	200,
		"force":	200,
	"lvl" : 60,
	"damage_type": "挫伤"
]),
([	"action": "$N使出的"+(order[random(13)])+"「风霜碎影」"NOR"，$w连挥杖影霍霍劈向$n的$l",
		"attack":	200,
		"parry":	200,
		"dodge":	200,
		"damage":	200,
		"force":	200,
	"lvl" : 75,
	"damage_type": "挫伤"
]),
([	"action": "$N的$w凭空一指，一招"+(order[random(13)])+"「断石狼烟」"NOR"点向$n的$l",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
	"lvl" : 90,
	"damage_type": "挫伤"
]),
([	"action": "$N纵身一跃，手中$w一招"+(order[random(13)])+"「长空雷隐」"NOR"对准$n的$l扫去",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
	"lvl" : 105,
	"damage_type": "挫伤"
]),
([	"action": "$N手中$w中宫直进，一式"+(order[random(13)])+"「冰谷初虹」"NOR"对准$n的$l点去",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
	"lvl" : 120,
	"damage_type": "挫伤"
]),
([	"action": "$N一招"+(order[random(13)])+"「峰回路转」"NOR"，$w左右迂回向$n的$l点去",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
	"lvl" :  145,
	"damage_type": "挫伤"
]),
});
int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }
//2019-1-1阿飞新规划，技能代码完善
//string valid_combine() { return "juehu-shou"; }		//互备技能
string skill_pinji() {return "下乘";}				//品级区分：上乘、中乘、下乘
string skill_xingbie() {return "通用";}				//性别区分：男性、女性、无性、通用
string skill_zhengxie() {return "中立";}			//正邪区分：正道、邪道、中立
string skill_menpai() {return "星宿派";}				//门派区分：门派，江湖
string skill_yinyang() {return "中性";}				//阴阳区分：阳、阴、中性
string skill_zhenying() {return "邪派";}			//阵营区分：正派、邪派、中立、通用
int damage_damage() {return 44;}	//外伤系数
int force_damage() {return 64;}		//内伤系数
//int qi_heal() {return 50;}		//内功疗气系数
//int jing_heal() {return 50;}		//内功疗精系数
int practice_level() {return 100;}	//自练级别
int practice_add() {return 100;}	//自练效率
int perform_level() {return 300;}	//PFM最低使用级别

int valid_learn(object me)
{
    object weapon;
//	if (!wizardp(me))
//		return ("巫师突然从黑暗中冲了出来，对你大吼一声：该门派没开放。\n");		
    if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "staff")
        return notify_fail("你使用的武器不对。\n");
    if (me->query("family/family_name")!="星宿派")
		return notify_fail("你不是星宿派弟子，没法学习。\n");	
    if ((int)me->query_skill("huagong-dafa", 1) < 50)
		return notify_fail("你的化功大法火候不够，无法学习。\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力不够。\n");
    if (me->query_skill("staff", 1) <=me->query_skill("tianzhan-zhang", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
	
    return 1;
}
int practice_skill(object me)
{
    object weapon;
//	if (!wizardp(me))
//		return ("巫师突然从黑暗中冲了出来，对你大吼一声：该门派没开放。\n");		
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "staff")
        return notify_fail("你使用的武器不对。\n");
	if (me->query("family/family_name")!="星宿派")
		return notify_fail("你不是星宿派弟子，偷学天山杖法，告诉丁老怪去。\n");			
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够练天山杖法。\n");
	
    me->receive_damage("qi", 25);
    return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];	//2017.9.4阿飞改，将招式简单点
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{
	int ap,dp, damage1,damage2,damage,liannum;
	object weapon;
	weapon = me->query_temp("weapon");
    ap = me->query_skill("tianshan-zhang",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	dp = victim->query_skill("parry",1)*(victim->query("breakup")+victim->query("breakup")*victim->query("breakup")+100)/100;
    damage1= (int) me->query_skill("tianshan-zhang",1);
	damage2 = (int)me->query_skill("tianshan-zhang",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	if( me->query_temp("lianzhao")>=1) liannum=me->query_temp("lianzhao");
	else liannum =1;
	if( me->query("neili") < 100 || me->query("jingli") < 100 || damage_bonus < 100 ) return 0;
	if ( me->query_skill("huagong-dafa",1) < 100 || me->query_skill("tianshan-zhang",1)<100) return 0;
//	if ( me->query_skill_mapped("force") != "huagong-dafa") return 0;
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "staff") return 0;

	if (random(7)==0 && random(ap) > dp/3 && me->query("jiali") > 0)
	{
		damage = (damage1+damage_bonus)*(liannum+20)/(20*liannum+1);
		victim->add("neili", -damage);
		me->add("neili", -100);
		message_vision(HIY "$n" HIY "感到内力如雪花融化一样，消失了。。\n" NOR, me,victim);
        return ;
	}
	if (random(7)==1 && random(ap) > dp/3 && me->query("jiali") > 0)
	{
		damage = (damage1+damage_bonus)*(liannum+20)/(20*liannum+1);
		victim->receive_damage("qi", damage ,me);
		victim->receive_wound("qi", damage/3 ,me);
		me->add("neili", -100);
		victim->apply_condition("xx_poison",20);
		victim->apply_condition("sanpoison",20);
		message_vision(HIY "$n" HIY "感到肌肤便似腐烂一般，散发出一股极难闻的恶臭。。\n" NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
        return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiajing")>0 && random(7)==2 && (int)me->query("breakup")>1 )
	{
		damage = (damage2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("jingli",-100);
		victim->receive_damage("jing", damage,me);
		victim->receive_wound("jing", damage/3,me);
		victim->apply_condition("xx_poison", random(me->query_skill("huagong-dafa")/100) + 1 + victim->query_condition("xx_poison"));
		message_vision(HIG "$N顿悟"+me->query("cognize")+HIG"，手中" + weapon->name() + HIG "正在散发着毒气，$n觉得眼前一阵发晕，似乎中了毒！\n" NOR, me,victim,damage,HBWHT+HIR"特效伤精"NOR);
		return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiali")>0 && random(7)==3 && (int)me->query("jm/xingxiu") )
	{
		damage = ((damage1+damage2)/2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("neili",-100);
		victim->receive_damage("qi", damage,me);
		victim->receive_wound("qi", damage/3,me);
		victim->apply_condition("sanpoison", random(me->query_skill("huagong-dafa")/100) + 1 + victim->query_condition("sanpoison"));
		message_vision(HIM"$N融汇星宿派武学精髓，运起毒功将毒素凝聚于" + weapon->name() + HIG "上，你觉得被击中的地方一阵麻木，似乎中了毒！\n" NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
		return ;
	}
}


string perform_action_file(string action)
{
	return __DIR__"tianshan-zhang/" + action;
}
