// quanzhen-jianfa.c 全真剑法	下乘武学100~300
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([      "action":"$N使一式"+(order[random(13)])+"「探海屠龙」"NOR"，手中$w由左至右横扫向向$n的$l",
		"attack":	100,
		"parry":	100,
		"dodge":	100,
		"damage":	100,
		"force":	100,
        "lvl" : 0,
        "skill_name" : "探海屠龙",
        "damage_type":  "割伤"
]),
([      "action":"$N踏上一步，"+(order[random(13)])+"「罡风扫叶」"NOR"，手中$w盘旋飞舞出一道剑光劈向$n的$l",
		"attack":	100,
		"parry":	100,
		"dodge":	100,
		"damage":	100,
		"force":	100,
        "lvl" : 9,
        "skill_name" : "罡风扫叶",
        "damage_type":  "割伤"
]),
([      "action":"$N手中$w一抖，一招"+(order[random(13)])+"「顺水推舟」"NOR"，斜斜一剑反腕撩出，攻向$n的$l",
		"attack":	100,
		"parry":	100,
		"dodge":	100,
		"damage":	100,
		"force":	100,
        "lvl" : 18,
        "skill_name" : "顺水推舟",
        "damage_type":  "割伤"
]),
([      "action":"$N手中$w连绕数个大圈，一式"+(order[random(13)])+"「星弛电闪」"NOR"，一道剑光飞向$n的$l",
		"attack":	100,
		"parry":	100,
		"dodge":	100,
		"damage":	100,
		"force":	100,
        "lvl" : 27,
        "skill_name" : "星弛电闪",
        "damage_type":  "刺伤"
]),
([      "action":"$N一式"+(order[random(13)])+"「白鹤亮翅」"NOR"，左手伸展，右手$w挥向$n的$l",
		"attack":	200,
		"parry":	200,
		"dodge":	200,
		"damage":	200,
		"force":	200,
        "lvl" : 36,
        "skill_name" : "白鹤亮翅",
        "damage_type":  "割伤"
]),
([      "action":"$N手中$w斜指苍天，一式"+(order[random(13)])+"「横行漠北」"NOR"，对准$n的$l斜斜击出",
		"attack":	200,
		"parry":	200,
		"dodge":	200,
		"damage":	200,
		"force":	200,
        "lvl" : 44,
        "skill_name" : "横行漠北",
        "damage_type":  "刺伤"
]),
([      "action":"$N一式"+(order[random(13)])+"「马蹴落花」"NOR"，手腕急抖，挥洒出万点金光，刺向$n的$l",
        "force" : 320,
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
        "lvl" : 52,
        "skill_name" : "马蹴落花",
        "damage_type":  "刺伤"
]),
([      "action":"$N一式"+(order[random(13)])+"「九品莲台」"NOR"，$w飞斩盘旋，如疾电般射向$n的胸口",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
        "lvl" : 60,
        "skill_name" : "九品莲台",
        "damage_type":  "刺伤"
]),
([      "action":"$N使一式"+(order[random(13)])+"「荆轲刺秦」"NOR"，手中$w合身疾刺$n的胸口，威不可当",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
        "lvl" : 70,
        "skill_name" : "荆轲刺秦",
        "damage_type":  "刺伤"
]),
([      "action":"$N手中$w划出一道长长的弧线，刺向$n的$l，却是一招"+(order[random(13)])+"「箫史乘龙」"NOR"",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
        "lvl" : 80,
        "skill_name" : "箫史乘龙",
        "damage_type":  "刺伤"
]),
([      "action":"$N回剑自守，使一式"+(order[random(13)])+"「深藏若虚」"NOR"，蓦地手中$w向$n击出",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
        "lvl" : 90,
        "skill_name" : "深藏若虚",
        "damage_type":  "刺伤"
]),
([      "action":"$N左足踢起，一式"+(order[random(13)])+"「魁星踢斗」"NOR"，$w从不可思议的角度刺向$n",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
        "lvl" : 114,
        "skill_name" : "魁星踢斗",
        "damage_type":  "刺伤"
]),
([      "action":"$N一式"+(order[random(13)])+"「紫电穿云」"NOR"，$w突然从天而降，一片金光围掠$n全身",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
        "lvl" : 129,
        "skill_name" : "紫电穿云",
        "damage_type":  "刺伤"
]),
([	"action":"$N晃动$w，踏奇门，走偏锋，剑尖颤了几颤，一招巧妙无比的"+(order[random(13)])+"「分花拂柳」"NOR"，似左实右，已点在$n$l",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
	"lvl" : 105,
	"skill_name" : "分花拂柳",
	"damage_type":	"刺伤"
]),
([	"action":"$N使一招"+(order[random(13)])+"「琴心三叠」"NOR"，身形向上飘起，手中$w虚虚实实幻出三点寒光射向$n$l",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
	"lvl" : 109,
	"skill_name" : "琴心三叠",
	"damage_type":	"刺伤"
]),
([	"action":"$N身形绕$n一转，猛然一式"+(order[random(13)])+"「罡风扫叶」"NOR"，将$w舞出满天剑影，挟着劲风向$n扫去",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
	"lvl" : 125,
	"skill_name" : "罡风扫叶",
	"damage_type":	"割伤"
]),
([	"action":"$N忽然身形高高跃起，使出"+(order[random(13)])+"「浪迹天涯」"NOR"，$w幻出漫天花瓣，迅如雷霆射向$n的$l",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
	"lvl" : 135,
	"skill_name" : "浪迹天涯",
	"damage_type":	"刺伤"
]),
([	"action":"$N左手捏着剑诀，右足踏开一招"+(order[random(13)])+"“定阳针”"NOR"向上斜刺，$w锵然跃出倏的化作几点星光射向$n的$l",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
	"lvl" : 145,
	"skill_name" : "定阳针",
	"damage_type":	"刺伤"
]),
});
string *parry_msg = ({
        "$n身体一个平移，使出一招「平沙落雁」，手中的$v化作一天剑雨，将$N的攻势湮灭在其中。\n",
        "$n剑锋一侧，使出一招「平湖秋月」，手中的$v舞得密不透雨，只听见一阵迅疾的兵器接触之声，磕开了$N的$w。\n",
        "$n将手中的$v一抖，一招「六桥烟柳」，化作点点青光，$N顿觉无从下手，无奈只得收招自保。\n",
        "$n反手一招「烟寺晚钟」，剑锋斜指，划出一道长虹，手中$v一下就荡开了$N的$w。\n",
        });
int valid_enable(string usage) { return usage == "sword" || usage == "parry"|| usage=="array"; }
//2019-1-1阿飞新规划，技能代码完善
string valid_combine() { return "yunv-jianfa"; }		//互备技能
string skill_pinji() {return "下乘";}				//品级区分：上乘、中乘、下乘
string skill_xingbie() {return "通用";}				//性别区分：男性、女性、无性、通用
string skill_zhengxie() {return "中立";}			//正邪区分：正道、邪道、中立
string skill_menpai() {return "全真教";}				//门派区分：门派，江湖
string skill_yinyang() {return "阳";}				//阴阳区分：阳、阴、中性
string skill_zhenying() {return "正派";}			//阵营区分：正派、邪派、中立、通用
int damage_damage() {return 60;}	//外伤系数
int force_damage() {return 55;}		//内伤系数
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
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你必须先找把剑才能学全真剑法。\n");
	if ((int)me->query_skill("sword", 1) < (int)me->query_skill("quanzhen-jianfa", 1))
        return notify_fail("你的基本剑法火候太浅。\n");
	if (me->query("family/family_name")!="全真派")
		return notify_fail("你不是全真教弟子，无法传授本教技能。\n");	
   
    if ((int)me->query("max_neili") < 200)
        return notify_fail("你的内力不够。\n");
	
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
	if(level >= action[i-1]["lvl"])
		return action[i-1]["skill_name"];
}
mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];	//2017.9.4阿飞改，将招式简单点
}

int practice_skill(object me)
{
	object weapon;
//	if (!wizardp(me))
//		return ("巫师突然从黑暗中冲了出来，对你大吼一声：该门派没开放。\n");	
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if (me->query("family/family_name")!="全真派")
		return notify_fail("你不是全真教弟子，无法练习本教技能。\n");				
	if ((int)me->query("neili") < 10)
		return notify_fail("你的内力不够练全真剑法。\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("你的体力不够练全真剑法。\n");
	
	me->receive_damage("qi", 25);
	me->add("neili", -5);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{
	int ap,dp, damage1,damage2,damage,liannum;
	object weapon;
	weapon = me->query_temp("weapon");
    ap = me->query_skill("quanzhen-jianfa",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	dp = victim->query_skill("parry",1)*(victim->query("breakup")+victim->query("breakup")*victim->query("breakup")+100)/100;
    damage1= (int) me->query_skill("quanzhen-jianfa",1);
	damage2 = (int)me->query_skill("quanzhen-jianfa",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	if( me->query_temp("lianzhao")>=1) liannum=me->query_temp("lianzhao");
	else liannum =1;
	if( me->query("neili") < 100 || me->query("jingli") < 100 || damage_bonus < 100 ) return 0;
	if ( ( me->query_skill("tiangang-zhengqi",1) < 100 && me->query_skill("xiantian-qigong",1) < 100) || me->query_skill("quanzhen-jianfa",1)<100) return 0;
//	if (me->query_skill_mapped("force") != "tiangang-zhengqi" && me->query_skill_mapped("force") != "xiantian-qigong") return 0;
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword") return 0;

	if (random(7)==1 && random(ap) > dp/3 && me->query("jiali") > 0)
	{
		damage = (damage1+damage_bonus)*(liannum+20)/(20*liannum+1);
		victim->receive_damage("qi", damage ,me);
		victim->receive_wound("qi", damage/3 ,me);
		me->add("neili", -100);
		message_vision(HIR"$N踏奇门，剑走偏锋，$n双眼一花，不知如何应对！一不小心就被剑气所伤！\n"NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
        return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiajing")>0 && random(7)==2 && (int)me->query("breakup")>1 )
	{
		damage = (damage2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("jingli",-100);
		victim->receive_damage("jing", damage,me);
		victim->receive_wound("jing", damage/3,me);
		if (!victim->is_busy()) victim->start_busy(1);
		message_vision(HIG "$N顿悟"+me->query("cognize")+HIG"，手中" + weapon->name() + HIG "疾颤，抖出七个剑花，只见$n身上接连炸起血花。\n" NOR, me,victim,damage,HBWHT+HIR"特效伤精"NOR);
		return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiali")>0 && random(7)==3 && (int)me->query("jm/quanzhen") )
	{
		damage = ((damage1+damage2)/2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("neili",-100);
		victim->receive_damage("qi", damage,me);
		victim->receive_wound("qi", damage/3,me);
		if (!victim->is_busy()) victim->start_busy(1);
		message_vision(HIM"$N贯通全真教武学精髓，一剑化七剑，以北斗七星之势将$n困于剑阵中，待剑光消散，$n已是全身血痕。\n" NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
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
	ap = me->query_skill("quanzhen-jianfa", 1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	dp = ob->query_skill("sword",1)*(ob->query("breakup")+ob->query("breakup")*ob->query("breakup")+100)/100;
	damage1 = me->query_skill("quanzhen-jianfa", 1);
	damage2 = me->query_skill("quanzhen-jianfa", 1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	if( damage < 10 ) damage=10;
	if( me->query("neili") < 100 || me->query("jingli") < 100 ) return damage;
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword") return damage;
	if (( me->query_skill("tiangang-zhengqi",1) < 100 && me->query_skill("xiantian-qigong",1) < 100) || me->query_skill("quanzhen-jianfa", 1) < 300) return damage;
//	if (me->query_skill_mapped("force") != "tiangang-zhengqi" && me->query_skill_mapped("force") != "xiantian-qigong") return damage;

	if ( random(8) == 1 && random(ap) > dp/4 )
	{
        msg = HIG"$N七星移位，走偏锋,$n双眼一花,不知如何应对!\n"NOR;
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
		message_vision(HIY"$N顿悟"+me->query("cognize")+HIY"，眼中闪现七星，突然身形从天璇位出现，剑光扫中$n的前胸。\n"NOR, me, ob,damage2,HBWHT+HIY"精神反伤"NOR);
		return j;
	}
	if(random(ap) > dp/4 && random(8)==3 && (int)me->query("jm/quanzhen") )
	{
		j = -(damage/3+random(damage/3));
		ob->receive_damage("qi",damage1,me);
		ob->receive_wound("qi",damage1/2,me);
		me->add("neili", -100 );
		message_vision(HIB"$N融汇全真教武学精髓，剑招加快，在$n下一招未出将出时，由摇光突入天枢，反击一剑！\n"NOR, me, ob,damage1,HBWHT+HIY"气血反伤"NOR);
		return j;
	}
}

string perform_action_file(string action)
{
	return __DIR__"quanzhen-jian/" + action;
}
