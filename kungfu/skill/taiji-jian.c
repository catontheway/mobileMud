// taiji-jian.c 太极剑	中乘武学200~600
// cleansword 2/15/96
// Marz 5/21/96
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h"
inherit SKILL;

string *dir = (
{
	"上盘",
	"下盘",
	"左侧",
	"右侧",
	"後心",
});
string *taijin = ( {"「乱环诀」", "阴阳诀」", "「动静诀」", "「两仪诀」", "「刚柔诀」", "「沾黏诀」", "「挤字诀」", "「引字诀」","钻翻", "螺旋","静恒","开合","软手","虚灵"});
string *order = ( {""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


mapping *action = (
{
([  "action" : "$N虚步提腰，一招「"+HIM+"蜻蜓点水"+NOR+"」，手中$w轻轻颤动，一剑剑点向$n的$l",
		"attack":	200,
		"parry":	200,
		"dodge":	200,
		"damage":	200,
		"force":	200,
	"lvl" : 0,
"damage_type" : "刺伤"
	 ]),
([  "action" : "$N向前跨上一步，左手剑诀，右手$w使出一式「"+YEL+"指南针"+NOR+"」直刺$n的$l",
		"attack":	200,
		"parry":	200,
		"dodge":	200,
		"damage":	200,
		"force":	200,
	"lvl" : 10,
"damage_type" : "刺伤"
	 ]),
([  "action" : "$N身形往右一挫，左手剑诀，右手$w使出一式「"+WHT+"大魁星"+NOR+"」刺向$n的$l",
		"attack":	200,
		"parry":	200,
		"dodge":	200,
		"damage":	200,
		"force":	200,
	"lvl" : 15,
"damage_type" : "刺伤"
	 ]),
([  "action" : "$N双膝下沉，右手$w使出一式「"+BLU+"探海式"+NOR+"」，由下而上疾刺$n的$l",
		"attack":	200,
		"parry":	200,
		"dodge":	200,
		"damage":	200,
		"force":	200,
	"lvl" : 26,
"damage_type" : "刺伤"
	 ]),
([  "action" : "$N一招「"+HIW+"燕子掠波"+NOR+"」，$w自上而下划出一个大弧，平平地向$n的$l挥去",
		"attack":	200,
		"parry":	200,
		"dodge":	200,
		"damage":	200,
		"force":	200,
	"lvl" : 37,
"damage_type" : "刺伤"
	 ]),
([  "action" : "$N上身往左侧一拧，一招「"+BLK+"乌龙摆尾"+NOR+"」，右手$w反手向$n的$l挥去",
		"attack":	200,
		"parry":	200,
		"dodge":	200,
		"damage":	200,
		"force":	200,
	"lvl" : 48,
"damage_type" : "刺伤"
	 ]),
([  "action" : "$N一招「"+RED+"右"+NOR+"拦扫」，一招「"+RED+"左"+NOR+"拦扫」，剑锋平指，一气呵成横扫$n的$l",
		"attack":	200,
		"parry":	200,
		"dodge":	200,
		"damage":	200,
		"force":	200,
	"lvl" : 50,
"damage_type" : "刺伤"
	 ]),
([  "action" : "$N左腿提膝，手中$w斜指，一招「"+HIC+"宿鸟投林"+NOR+"」刺向$n的$l",
		"attack":	200,
		"parry":	200,
		"dodge":	200,
		"damage":	200,
		"force":	200,
	"lvl" : 60,
"damage_type" : "刺伤"
	 ]),
([  "action" : "$N一招「"+CYN+"青龙出水"+NOR+"」，$w自下而上划出一个大弧，平平地挥向$n的$l",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
	"lvl" : 70,
"damage_type" : "刺伤"
	 ]),
([  "action" : "$N使出「"+RED+"三"+NOR+"环套"+HIW+"月"+NOR+"」，$w划出三个圆圈，剑锋直出，绵绵不断划向$n的$l",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
	"lvl" : 80,
"damage_type" : "刺伤"
	 ]),
([  "action" : "$N一招「"+MAG+"风卷荷叶"+NOR+"」，$w轻灵地划出几个圆弧，迅速地向$n的$l挥去",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
	"lvl" : 100,
"damage_type" : "刺伤"
	 ]),
([  "action" : "$N一招「"+YEL+"虎抱头"+NOR+"」，$w划出一个左低右高的大弧，斜斜地斩向$n的$l",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
	"lvl" : 120,
"damage_type" : "刺伤"
	 ]),
([  "action" : "$N使出「"+HIR+"狮子摇头"+NOR+"」，$w由右向左划出一个大８字，将$n圈在其中",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,
	"lvl" : 141,
"damage_type" : "刺伤"
	 ]),
([  "action" : "$N左脚踏实，右脚虚点，一招「"+HIW+"仙人指路"+NOR+"」，右手$w带着一团剑花，逼向$n的$l",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,
	"lvl" : 162,
"damage_type" : "刺伤"
	 ]),
([  "action" : "$N轻轻跃起，一招「"+CYN+"野马跳涧"+NOR+"」，$w在半空中化为一圈银芒，落向$n的$l",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,
	"lvl" : 184,
"damage_type" : "刺伤"
	 ]),
([  "action" : "$N两腿前箭后弓，一招「"+HIR+"射雁式"+NOR+"」，右手$w直刺$n的$l",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,
	"lvl" : 205,
"damage_type" : "刺伤"
	 ]),
([  "action" : "$N一招「"+WHT+"小魁星"+NOR+"」，身形往左一挫，左手剑诀，右手$w平平地向$n的$l挥去",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,
	"lvl" : 210,
"damage_type" : "刺伤"
	 ]),
([  "action" : "$N猱身扑上，一招「"+HIW+"白猿献果"+NOR+"」，手中$w斜斜地向$n的$l挥去",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,
	"lvl" : 220,
"damage_type" : "刺伤"
	 ]),
([  "action" : "$N一招「"+RED+"迎风掸尘"+NOR+"」，$w看似随意地一挥，$n却陡觉一股劲气迎面袭来。",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,
	"lvl" : 225,
"damage_type" : "刺伤"
	 ]),
([  "action" : "$N一招「"+YEL+"顺水推舟"+NOR+"」，$w自上而下划出一个大弧，平平地向$n的$l挥去。",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,
	"lvl" : 230,
"damage_type" : "刺伤"
	 ]),
([  "action" : "$N一招「"+WHT+"流星赶月"+NOR+"」，$w疾刺$n的$l",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,
	"lvl" : 235,
"damage_type" : "刺伤"
	 ]),
([  "action" : "$N突然盘蹲下身来，一招「"+BLU+"海底捞月"+NOR+"」，$w自下而上地向$n的$l挥去",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,
	"lvl" : 240,
"damage_type" : "刺伤"
	 ]),
([  "action" : "$N一招「"+HIG+"挑帘式"+NOR+"」，$w自下而上徐徐划出一个大弧，平平地向$n的$l挥去",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,
	"lvl" : 245,
"damage_type" : "刺伤"
	 ]),
([  "action" : "$N一招「"+YEL+"黄蜂入洞"+NOR+"」，$w自上而下划出一个大弧，平平地向$n的$l挥去",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,
	"lvl" : 250,
"damage_type" : "刺伤"
	 ]),
([  "action" : "$N一招「"+WHT+"大鹏展翅"+NOR+"」，身形跃起，右手$w刺向$n的$l",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,
	"lvl" : 255,
"damage_type" : "刺伤"
	 ]),
([  "action" : "$N一招「"+BLK+"车轮剑"+NOR+"」，$w化作一片银盘，平平地向$n的$l卷去",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,
	"lvl" : 260,
"damage_type" : "刺伤"
	 ]),
([  "action" : "$N左脚轻点地面，身形往前一扑，一招「"+BLU+"天马行空"+NOR+"」，$w向$n的$l挥去",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,
	"lvl" : 265,
"damage_type" : "刺伤"
	 ]),
([  "action" : "$N一招「"+WHT+"风扫梅花"+NOR+"」，身体跃在半空，手中$w扫向$n的$l",
		"attack":	500,
		"parry":	500,
		"dodge":	500,
		"damage":	500,
		"force":	500,
	"lvl" : 260,
"damage_type" : "刺伤"
	 ]),
([  "action" : "$N一招「"+HIC+"却步抽剑"+NOR+"」，左脚跃步落地，$w回抽，反手勾向$n的$l",
		"attack":	500,
		"parry":	500,
		"dodge":	500,
		"damage":	500,
		"force":	500,
	"lvl" : 270,
"damage_type" : "刺伤"
	 ]),
([  "action" : "$N右腿半屈般蹲，一招「"+WHT+"如封似闭"+NOR+"」，剑尖虚指，转身撩向$n的$l",
		"attack":	500,
		"parry":	500,
		"dodge":	500,
		"damage":	500,
		"force":	500,
	"lvl" : 280,
"damage_type" : "刺伤"
	 ]),
([  "action" : "$N回身拧腰，右手虚抱，一招「"+HIY+"拨云瞻日"+NOR+"」，$w中宫直进，刺向$n的$l",
		"attack":	600,
		"parry":	600,
		"dodge":	600,
		"damage":	600,
		"force":	600,
	"lvl" : 300,
"damage_type" : "刺伤"
	 ]),
});

int valid_enable(string usage)
{
	return (usage == "sword") || (usage == "parry");
}
//2019-1-1阿飞新规划，技能代码完善
//string valid_combine() { return "juehu-shou"; }		//互备技能
string skill_pinji() {return "中乘";}				//品级区分：上乘、中乘、下乘
string skill_xingbie() {return "通用";}				//性别区分：男性、女性、无性、通用
string skill_zhengxie() {return "中立";}			//正邪区分：正道、邪道、中立
string skill_menpai() {return "武当派";}				//门派区分：门派，江湖
string skill_yinyang() {return "中性";}				//阴阳区分：阳、阴、中性
string skill_zhenying() {return "正派";}			//阵营区分：正派、邪派、中立、通用
int damage_damage() {return 55;}	//外伤系数
int force_damage() {return 60;}		//内伤系数
//int qi_heal() {return 50;}		//内功疗气系数
//int jing_heal() {return 50;}		//内功疗精系数
int practice_level() {return 100;}	//自练级别
int practice_add() {return 100;}	//自练效率
int perform_level() {return 300;}	//PFM最低使用级别

int valid_learn(object me)
{
	object weapon;
//	if (!wizardp(me))
//		return notify_fail("巫师突然从黑暗中冲了出来，对你大吼一声：该门派没开放。\n");	

    if (me->query("family/family_name")!="武当派")
		return notify_fail("你不是武当弟子，无法学习武当绝技。\n");

	if ((int)me->query_skill("taiji-shengong", 1) < 50 )
		return notify_fail("你的太极神功火候太浅。\n");
	if ((int)me->query_skill("taiji-jian",1) >= 900 && me->query("family/master_id") !="zhang sanfeng")
		return notify_fail("本人只能教你到这，更高的或许你只能找张真人学习了。\n");
//	if ((int)me->query_skill("taiji-quan", 1) <= me->query_skill("taiji-jian", 1))
//		return notify_fail("你的太极拳火候太浅。\n");
	if (me->query_skill("sword", 1) <=me->query_skill("taiji-jian", 1))
		return notify_fail("你的基础不够，无法领会更高深的技巧。\n");

	if (random(100)==1) me->add("score",-5);	
	return 1;
}

/*string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
	if(level >= action[i]["lvl"])
		return action[i]["skill_name"];
}
*/
mapping query_action(object me, object weapon)
{
	int level;
	string str;
	level = (int)me->query_skill("taiji-jian",1);

// 随字诀
	if(me->query_temp("powerup") && random(20) > 15 && random(level)>300 &&  me->query("jiali")>100)
	{
		switch(random(3))
		{
		case 0:
			str = HIR"$N将内力灌注于剑上，向$n"+dir[random(sizeof(dir))]+"攻去！突然间$N的剑尖由"+dir[random(sizeof(dir))]+"圈转回来，攻向$n的$l！\n"NOR;
			break;
		case 1:
			str = HIR"$N手中剑尖连点$n" + dir[random(sizeof(dir))] + "的要穴！$n连忙守备，却见$N剑身一弯，转而攻向$n 的$l！\n"NOR;
			break;
		case 2:
			str = HIR"$N$w急舞，剑尖乱颤，陡然出一剑向$n的檀中大穴攻去！剑未及$n半尺，突然又转向$n的" + dir[random(sizeof(dir))]+"！\n"NOR;
			break;
		}

		if(objectp(weapon)) str = replace_string(str, "$w", weapon->name()+HIR);
		return ([
            "action":str,
			"attack":	600,
			"parry":	600,
			"dodge":	600,
			"damage":	600,
			"force":	600,
		    "damage_type": "割伤",
			]);
	}
// 三环套月
	if(me->query_temp("taiji") && random(20) > 15 && random(level)>300 &&  me->query("jiali")>100)
	{
		switch(random(7))
		{
		case 0:
			str = HIC"$N使出「三环套月」，招式一变，左手抚剑把，右手托剑，剑尖青光闪动，以一个圆弧将$w"HIC"向$n轻轻挑出"NOR;
			break;
		case 1:
			str = HIC"然后$N移进一步，右手左招，左手右招，同样一剑接着挥出，上下连续，不着一点停顿的痕迹"NOR;
			break;
		case 2:
			str = HIC"剑光紧接，$N手中的$w"HIC"又一次挥出急点$n$l，这三剑剑势相联，剑气相叠，剑意相同，正合道家三清之属"NOR;
			break;
		default:
			str = HIC"$N使出「三环套月」，招式一变，左手抚剑把，右手托剑，剑尖青光闪动，以一个圆弧将$w"HIC"向$n轻轻挑出"NOR;
			break;
		}
		
		return ([
            "action":str,
			"attack":	600,
			"parry":	600,
			"dodge":	600,
			"damage":	600,
			"force":	600,
            "damage_type": "刺伤",
		        ]);
	}
	return action[random(sizeof(action))];	//2017.9.4阿飞改，将招式简单点

}

int practice_skill(object me)
{
	object weapon;
//	if (!wizardp(me))
//		return notify_fail("巫师突然从黑暗中冲了出来，对你大吼一声：该门派没开放。\n");	
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
	if (!objectp(weapon = me->query_temp("secondary_weapon")) || (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if (me->query("family/family_name")!="武当派")
		return notify_fail("你先加入武当派在练吧。\n");	
	
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练太极剑法。\n");
	me->receive_damage("qi", 30);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"taiji-jian/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{
	string msg;
	int ap,dp, damage1,damage2,damage,liannum;
	object weapon1,weapon2;
	weapon1 = me->query_temp("weapon");
	weapon2 = victim->query_temp("weapon");
    ap = me->query_skill("taiji-jian",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	dp = victim->query_skill("parry",1)*(victim->query("breakup")+victim->query("breakup")*victim->query("breakup")+100)/100;
    damage1= (int) me->query_skill("taiji-jian",1);
	damage2 = (int)me->query_skill("taiji-jian",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	if( me->query_temp("lianzhao")>=1) liannum=me->query_temp("lianzhao");
	else liannum =1;	
	if( me->query("neili") < 100 || me->query("jingli") < 100 || damage_bonus < 100 ) return 0;
	if ( (me->query_skill("taiji-shengong",1) < 100 && me->query_skill("yinyun-ziqi",1) < 100) || me->query_skill("taiji-jian",1)<100) return 0;
//	if ( me->query_skill_mapped("force") != "taiji-shengong" && me->query_skill_mapped("force") != "yinyun-ziqi") return 0;
	if (!objectp(weapon1 = me->query_temp("weapon")) || (string)weapon1->query("skill_type") != "sword") return 0;

	if (random(7)==1 && random(ap) > dp/3 && me->query("jiali") > 0)
	{
		damage = (damage1+damage_bonus)*(liannum+20)/(20*liannum+1);
		victim->receive_damage("qi", damage ,me);
		victim->receive_wound("qi", damage/3 ,me);
		me->add("neili", -100);
		message_vision(HIY"$N划出一道剑圈，$n手忙脚乱，慌乱不堪！顿时陷入太极剑的剑圈内！\n"NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
        return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiajing")>0 && random(7)==2 && (int)me->query("breakup")>1 )
	{
		damage = (damage2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("jingli",-100);
		victim->receive_damage("jing", damage,me);
		victim->receive_wound("jing", damage/3,me);
		message_vision(HIG "$N顿悟"+me->query("cognize")+HIG"，$N使出太极剑法「三环套月」连续三个剑圈向$n袭来。\n" NOR, me,victim,damage,HBWHT+HIR"特效伤精"NOR);
		return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiali")>0 && random(7)==3 && (int)me->query("jm/wudang") )
	{
		damage = ((damage1+damage2)/2+damage_bonus)*(liannum+20)/(20*liannum+1);
		msg = HIM"$N融汇武当太极精髓，"NOR;
		if (objectp(weapon2 = victim->query_temp("weapon")))
		{
			msg += HIM"左手剑诀斜引，"+weapon1->name()+HIM"画个半圆，平搭在$n"+weapon2->name()+HIM"背脊上，劲力传出，"NOR;
			if(random(3)==0)
			{
				msg += HIM"$n招式渐见涩滞，只觉得手中"+weapon2->name()+HIM"倒似不断的在增加重量，一个把持不定，脱手飞出！\n"NOR;
				weapon2->unequip();
				weapon2->move(environment(victim));
				message_vision(msg, me,victim);
			}
			else
			{
				msg += HIY"$n一招使出，真力运得不足，被"+weapon1->name()+HIM"带着连转几个圈子，吐了一口鲜血，手中"+weapon2->name()+HIM"一震，险些脱手！\n"NOR;
				victim->receive_damage("qi", damage,me);
				victim->receive_wound("qi", damage/3,me);
				message_vision(msg, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
			}
		}
		else
		{
			msg += HIM"如抱太极，手中"+weapon1->name()+"斜指，只见$N使出四两拨千斤之巧劲，将$n的力道借力打力反击回来。"NOR;
			victim->receive_damage("qi", damage,me);
			victim->receive_wound("qi", damage/3,me);
			message_vision(msg, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
		}
		me->add("neili",-100);
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
	ap = me->query_skill("taiji-jian", 1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	dp = ob->query_skill("sword",1)*(ob->query("breakup")+ob->query("breakup")*ob->query("breakup")+100)/100;
	damage1 = me->query_skill("taiji-jian", 1);
	damage2 = me->query_skill("taiji-jian", 1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	if( damage < 10 ) damage=10;
	if( me->query("neili") < 100 || me->query("jingli") < 100 ) return damage;
	if ( (me->query_skill("taiji-shengong",1) < 100 && me->query_skill("yinyun-ziqi",1) < 100) || me->query_skill("taiji-jian",1)<100) return damage;
//	if ( me->query_skill_mapped("force") != "taiji-shengong" && me->query_skill_mapped("force") != "yinyun-ziqi") return damage;
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword") return damage;

	if ( random(8) == 1 && random(ap) > dp/4 )
	{
		msg = HIG"只见$N使出四两拨千斤之巧劲，剑锋斜引，结果$n的力道被卸在一旁！\n"NOR;
		if (!ob->is_busy()) ob->start_busy(1);
		me->add("neili", -100 );
		j = -(damage+random(damage));
		message_vision(msg, me, ob);
		return j;
	}
	if(random(ap) > dp/4 && random(8)==2 && (int)me->query("breakup")>1 )
	{
		msg = HIY"$N顿悟"+me->query("cognize")+HIY"，如抱太极，一股雄浑无比的力道组成了一个旋涡来！！$n的内力被太极神功借力打力反击在自己身上！\n"NOR;
		j = -(damage/2+random(damage/2));
		ob->receive_damage("jing",damage2,me);
		ob->receive_wound("jing",damage2/2,me);
		me->add("jingli", -100 );
		if (!ob->is_busy()) ob->start_busy(1);
		message_vision(msg, me, ob,damage2,HBWHT+HIY"精神反伤"NOR);
		return j;
	}
	if(random(ap) > dp/4 && random(8)==3 && (int)me->query("jm/wudang") )
	{
		msg =HIC"$N融汇武当派以柔克刚之精髓，於"+weapon->name()+HIC"上连催两重劲，剑弯成弧，又是一弯，便如长蛇之游，奇诡不可设想。"NOR;
		j = -(damage/3+random(damage/3));
		ob->receive_damage("qi",damage1,me);
		ob->receive_wound("qi",damage1/2,me);
		me->add("neili", -100 );
		if (!ob->is_busy()) ob->start_busy(1);
		message_vision(msg, me, ob,damage1,HBWHT+HIY"气血反伤"NOR);
		return j;
	}
}


/*//2018.9.5 阿飞改，重新启动自动连招
void do_interlink(object me, object victim)
{
	int extra,max_enemy, max_att, i, j;
    object *enemy, weapon;
	string all_enemy;
	if( !objectp(weapon = me->query_temp("weapon") ) || (string)weapon->query("skill_type") != "sword" ) return;
	if ( me->query_skill_mapped("sword") != "taiji-jian" ) return;
//	if (me->query_skill_mapped("force") != "taiji-shengong") return;
	if ( (int)me->query_skill("taiji-jian", 1) < 600 || (int)me->query_skill("taiji-shengong", 1) < 600)  return;
	if( me->query("neili") < (int)me->query_skill("taiji-jian", 1)*4 ) return;
	if ( me->query_temp("autolian") ) return;
	if ( me->query_temp("cooldown") ) return;
	if (me->is_busy()) return;
	if ( me->query("auto_lian") ) return;	//自动连招开关，使用auto命令来设置
	
	if ( (int)me->query_skill("taiji-jian", 1) > 600 && me->query("jm/wudang",1) )   
	{
		enemy = me->query_enemy();
		if ( !(max_enemy=sizeof(enemy)) ) return;
		if ( playerp(me) && !me->query("xy_huiyuan") ) return;
		all_enemy = "";
		max_att = 3;
		for ( i=0; i<max_enemy; i++ )
		{
			if ( !objectp(enemy[i]) ) continue;
			all_enemy += enemy[i]->name();
			if ( i < max_enemy-1) all_enemy += "、";
		}		
		message_vision(HIC+"$N使出太极剑法「三环套月」连续三个剑圈向"+all_enemy+"袭来。\n\n" NOR,me);
		me->set_temp("autolian", 1);	//2017.3.3阿飞改，添加自动连招标记
		call_out("del_autolian", 3, me);		
//		me->add_temp("lianzhao", max_att);	 //2016.6.1阿飞改，增加连招标记，用于削弱连招伤害	
		extra = me->query_skill("taiji-jian", 1)/3;	
		if ( me->query_skill_mapped("force") != "taiji-shengong") extra += me->query_skill("taiji-jian", 1)/2;	//2018.9.5阿飞改，不使用本门特内则减益
		if ((string)weapon->query("id") == "taiji baodao") extra = -me->query_skill("taiji-jian", 1)/3; //2018.3.25阿飞改，拿特殊武器有加成
		me->add_temp("apply/attack", -extra);	
		me->add_temp("apply/damage", -extra);
		me->add_temp("apply/strength", -extra);			
		for ( i=0; i<max_enemy; i++ )
		{
			if ( !objectp(enemy[i]) ) continue;
			
			for ( j=0; j<max_att; j++ )
			{
				if( !objectp(weapon = me->query_temp("weapon") ) || (string)weapon->query("skill_type") != "sword" || me->query_skill_mapped("sword") != "taiji-jian" ) break;	//防止使用辟邪自动连后更换其他技能，终止自动连
				if ( me->query_temp("cooldown") ) break;	//防止使用辟邪自动连后使用其他pfm，终止自动连						
				if ( (me->is_fighting(enemy[i]) || enemy[i]->is_fighting(me)) && enemy[i]->query("eff_qi") > 0 )
				{
					if ( environment(me) == environment(enemy[i]) )
					{
						COMBAT_D->do_attack(me, enemy[i], me->query_temp("weapon"), TYPE_REGULAR);
					}
				}
				else 
					break;
			}
		}
//		me->delete_temp("lianzhao");  //2016.6.1阿飞改，连招结束取消连招标记	
		me->add_temp("apply/attack", extra);	
		me->add_temp("apply/damage", extra);
		me->add_temp("apply/strength", extra);	
		me->add("neili", -120*max_att);
	}
}
int is_interlink()
{
	return 1;
}
void del_autolian(object me)
{ 
	if ( !objectp(me) ) return;
	if ( me->query_temp("autolian") ) me->delete_temp("autolian");
}
*/