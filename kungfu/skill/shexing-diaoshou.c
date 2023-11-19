// shexing-diaoshou.c 蛇形刁手	中乘武学200~600
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
//#include <condition.h>
inherit SKILL;
string *order = ( {""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = (
{
([	"action" : "$N一式"+(order[random(13)])+"「灵蛇出洞」"NOR"，右手虚晃，左手扬起，突然拍向$n的背后二穴",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
	"lvl" : 0,
"skill_name" : "灵蛇出洞",
"damage_type" : "瘀伤"
	 ]),
([	"action" : "$N侧身一晃，一式"+(order[random(13)])+"「虎头蛇尾」"NOR"，左手拿向$n的肩头，右拳打向$n的胸口",
		"attack":	200,
		"parry":	200,
		"dodge":	200,
		"damage":	200,
		"force":	200,
	"lvl" : 10,
    "skill_name" : "虎头蛇尾",
    "damage_type" : "瘀伤"
	 ]),
([	"action" : "$N一式"+(order[random(13)])+"「画蛇添足」"NOR"，右手环拢成爪，一出手就向扣$n的咽喉要害",
		"attack":	200,
		"parry":	200,
		"dodge":	200,
		"damage":	200,
		"force":	200,
	"lvl" : 20,
    "skill_name" : "画蛇添足",
    "damage_type" : "瘀伤"
	 ]),
([	"action" : "$N左手虚招，右掌直立，一式"+(order[random(13)])+"「杯弓蛇影」"NOR"，错步飘出，疾拍$n的面门",
		"attack":	200,
		"parry":	200,
		"dodge":	200,
		"damage":	200,
		"force":	200,
	"lvl" : 30,
    "skill_name" : "杯弓蛇影",
    "damage_type" : "瘀伤"
	 ]),
([	"action" : "$N使一式"+(order[random(13)])+"「蛇行鼠窜」"NOR"，左拳上格，右手探底突出，抓向$n的裆部",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
	"lvl" : 38,
    "skill_name" : "蛇行鼠窜",
    "damage_type" : "瘀伤"
	 ]),
([	"action" : "$N一式"+(order[random(13)])+"「蛇磐青竹」"NOR"，十指伸缩，虚虚实实地袭向$n的全身要穴",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
	"lvl" : 51,
    "skill_name" : "蛇磐青竹",
    "damage_type" : "内伤"
	 ]),
([	"action" : "$N双手抱拳，一式"+(order[random(13)])+"「万蛇汹涌」"NOR"，掌影翻飞，同时向$n施出九九八十一招",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,	
	"lvl" : 56,
    "skill_name" : "万蛇汹涌",
    "damage_type" : "内伤"
	 ]),
([	"action" : "$N一式"+(order[random(13)])+"「白蛇吐信」"NOR"，拳招若隐若现，若有若无，急急地拍向$n的丹田",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,	
	"lvl" : 60,
    "skill_name" : "白蛇吐信",
    "damage_type" : "内伤"
	 ]),
([      "action" : "$N左指挥出，一式"+(order[random(13)])+"「青蛇挺身」"NOR"，削向$n的掌缘",
		"attack":	200,
		"parry":	200,
		"dodge":	200,
		"damage":	200,
		"force":	200,
	"lvl" : 0,
    "skill_name" : "青蛇挺身",
    "damage_type" : "瘀伤"
	 ]),
([      "action" : "$N全身之力聚于一指，一式"+(order[random(13)])+"「银蛇吐信」"NOR"，指向$n的胸前",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
	"lvl" : 15,
    "skill_name" : "银蛇吐信",
    "damage_type" : "瘀伤"
	 ]),
([      "action" : "$N左掌贴于神道穴，右手一式"+(order[random(13)])+"「金蛇摆尾」"NOR"，向$n的$l划过",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
	"lvl" : 25,
    "skill_name" : "金蛇摆尾",
    "damage_type" : "瘀伤"
	 ]),
([      "action" : "$N双目怒视，一式"+(order[random(13)])+"「蝮蛇捕食」"NOR"，双指拂向$n的额、颈、肩、臂、胸、背",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
	"lvl" : 45,
    "skill_name" : "蝮蛇捕食",
    "damage_type" : "瘀伤"
	 ]),
([      "action" : "$N一式"+(order[random(13)])+"「待机而行」"NOR"，左掌掌心向外，右指蓄势点向$n的$l",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,
	"lvl" : 60,
    "skill_name" : "待机而行",
    "damage_type" : "瘀伤"
	 ]),
([      "action" : "$N右手伸出，十指叉开，一式"+(order[random(13)])+"「猛蛇出洞」"NOR"，小指拂向$n的太渊穴",
		"attack":	500,
		"parry":	500,
		"dodge":	500,
		"damage":	500,
		"force":	500,
	"lvl" : 70,
    "skill_name" : "猛蛇出洞",
    "damage_type" : "瘀伤"
	 ]),
([      "action" : "$N双迸出无数道劲气，一式"+(order[random(13)])+"「千蛇缠身」"NOR"射向$n的全身",
		"attack":	600,
		"parry":	600,
		"dodge":	600,
		"damage":	600,
		"force":	600,
	"lvl" : 80,
    "skill_name" : "千蛇缠身",
    "damage_type" : "瘀伤"
	 ]),

});

int valid_enable(string usage)
{
	return usage=="hand" || usage=="parry"|| usage=="unarmed";
}
//2019-1-1阿飞新规划，技能代码完善
string valid_combine() { return "bosi-guaizhao"; }		//互备技能
string skill_pinji() {return "中乘";}				//品级区分：上乘、中乘、下乘
string skill_xingbie() {return "通用";}				//性别区分：男性、女性、无性、通用
string skill_zhengxie() {return "中立";}			//正邪区分：正道、邪道、中立
string skill_menpai() {return "白驼山派";}				//门派区分：门派，江湖
string skill_yinyang() {return "中性";}				//阴阳区分：阳、阴、中性
string skill_zhenying() {return "邪派";}			//阵营区分：正派、邪派、中立、通用
int damage_damage() {return 65;}	//外伤系数
int force_damage() {return 44;}		//内伤系数
//int qi_heal() {return 50;}		//内功疗气系数
//int jing_heal() {return 50;}		//内功疗精系数
int practice_level() {return 100;}	//自练级别
int practice_add() {return 100;}	//自练效率
int perform_level() {return 300;}	//PFM最低使用级别

int valid_learn(object me)
{
//	if (!wizardp(me))
//		return ("巫师突然从黑暗中冲了出来，对你大吼一声：该门派没开放。\n");	
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练蛇形刁手必须空手。\n");
	
	if ((int)me->query_skill("hamagong", 1) < 100)
		return notify_fail("你的蛤蟆功不够 \n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练蛇形刁手。\n");
	
	if (random(100)==1) me->add("score",-5);	
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
	int level = (int)me->query_skill("shexing-diaoshou",1);
		if( random(8)==1 && random(level) > 300 && me->query("jiali")>100)
		{
			return ([
			"action" : HIG"$N紧接着，$N口中发出“嘶嘶”的声音，双手半曲，三指上竖成蛇状，陪合着潇遥步法，有如急风暴雨般攻出了数招"NOR,
			"attack":	600,
			"parry":	600,
			"dodge":	600,
			"damage":	600,
			"force":	600,	
			"skill_name" : "蛇形百变",
			"damage_type" : "瘀伤"
			]);
		}
	
    return action[random(sizeof(action))];	//2017.9.4阿飞改，将招式简单点

}
int practice_skill(object me)
{
//	if (!wizardp(me))
//		return ("巫师突然从黑暗中冲了出来，对你大吼一声：该门派没开放。\n");	
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练蛇形刁手。\n");
   
	me->receive_damage("qi", 25);
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"shexing-diaoshou/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{
	int ap,dp, damage1,damage2,damage,liannum;

    ap = me->query_skill("shexing-diaoshou",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	dp = victim->query_skill("parry",1)*(victim->query("breakup")+victim->query("breakup")*victim->query("breakup")+100)/100;
    damage1= (int) me->query_skill("shexing-diaoshou",1);
	damage2 = (int)me->query_skill("shexing-diaoshou",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	if( me->query_temp("lianzhao")>=1) liannum=me->query_temp("lianzhao");
	else liannum =1;
	if( me->query("neili") < 100 || me->query("jingli") < 100 || damage_bonus < 100 ) return 0;
	if ( me->query_skill("hamagong",1) < 100 || me->query_skill("shexing-diaoshou",1)<100) return 0;
//	if ( me->query_skill_mapped("force") != "hamagong") return 0;
	if (objectp(me->query_temp("weapon")) ) return 0;

	if (random(7)==1 && random(ap) > dp/3 && me->query("jiali") > 0)
	{
		victim->apply_condition("snake_poison",20);
		victim->apply_condition("qx_snake_poison",20);
		me->add("neili", -100);
		if (!victim->is_busy()) victim->start_busy(2);
		message_vision(HIR "$N倒转经脉，身形一变，一口毒气对着$n吐出！$n头一昏，不知所措 ！\n"NOR, me,victim);
        return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiajing")>0 && random(7)==2 && (int)me->query("breakup")>1 )
	{
		damage = (damage2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("jingli",-100);
		victim->receive_damage("jing", damage,me);
		victim->receive_wound("jing", damage/3,me);
		message_vision(HIG "$N顿悟"+me->query("cognize")+HIG"，$N倒转经脉一招收回，一招又出，$n伤口一凉，再次鲜血喷出！\n" NOR, me,victim,damage,HBWHT+HIR"特效伤精"NOR);
		return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiali")>0 && random(7)==3 && (int)me->query("jm/baituo") )
	{
		damage = ((damage1+damage2)/2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("neili",-100);
		victim->receive_damage("qi", damage,me);
		victim->receive_wound("qi", damage/3,me);
		message_vision(HIM"$N贯通白驼山武学精髓，趁$n喘息未定，又攻一招，$n觉一股劲风扑面而来，吐出了一大口鲜血！\n" NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
		return ;
	}
}


