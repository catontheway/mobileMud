// taiji-quan.c 太极拳	上乘武学400~1000
// 增加不同技能级别相应的学习和能使出的招数名, by ReyGod, in 12/17/1996
//      query_skill_name() and query_action()
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h"
inherit SKILL;


string *taijin = ( {"「乱环诀」", "阴阳诀」", "「动静诀」", "「两仪诀」", "「刚柔诀」", "「沾黏诀」", "「挤字诀」", "「引字诀」","钻翻", "螺旋","静恒","开合","软手","虚灵"});
string *order = ( {""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = (
{
([	"action" : "$N使一招"+(order[random(13)])+"「揽雀尾」"NOR"，双手划了个半圈，按向$n的$l",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,
"skill_name" : "揽雀尾",
	"lvl" : 0,
"damage_type" : "瘀伤"
	 ]),
([	"action" : "$N使一招"+(order[random(13)])+"「单鞭」"NOR"，右手收置肋下，左手向外挥出，劈向$n的$l",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,
"skill_name" : "单鞭",
	"lvl" : 5,
"damage_type" : "瘀伤"
	 ]),
([	"action" : "$N左手回收，右手由钩变掌，由右向左，使一招"+(order[random(13)])+"「提手上式」"NOR"，向$n的$l打去",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,
"skill_name" : "提手上式",
	"lvl" : 10,
"damage_type" : "瘀伤"
	 ]),
([	"action" : "$N双手划弧，右手向上，左手向下，使一招"+(order[random(13)])+"「白鹤亮翅」"NOR"，分击$n的面门和$l",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,
"skill_name" : "白鹤亮翅",
	"lvl" : 15,
"damage_type" : "瘀伤"
	 ]),
([	"action" : "$N左手由胸前向下，身体微转，划了一个大圈，使一招"+(order[random(13)])+"「搂膝拗步」"NOR"，击向$n的$l",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,
"skill_name" : "搂膝拗步",
	"lvl" : 20,
"damage_type" : "瘀伤"
	 ]),
([	"action" : "$N左手由下上挑，右手内合，使一招"+(order[random(13)])+"「手挥琵琶」"NOR"，向$n的$l打去",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,
"skill_name" : "手挥琵琶",
	"lvl" : 25,
"damage_type" : "瘀伤"
	 ]),
([	"action" : "$N左手变掌横于胸前，右拳由肘下穿出，一招"+(order[random(13)])+"「肘底看锤」"NOR"，锤向$n的$l",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,
"skill_name" : "肘底看锤",
	"lvl" : 30,
"damage_type" : "瘀伤"
	 ]),
([	"action" : "$N左脚前踏半步，右手使一招"+(order[random(13)])+"「海底针」"NOR"，指由下向$n的$l戳去",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,
"skill_name" : "海底针",
	"lvl" : 35,
"damage_type" : "瘀伤"
	 ]),
([	"action" : "$N招"+(order[random(13)])+"「闪通臂」"NOR"，左脚一个弓箭步，右手上举向外撇出，向$n的$l挥去",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,
"skill_name" : "闪通臂",
	"lvl" : 40,
"damage_type" : "瘀伤"
	 ]),
([	"action" : "$N两手由相对，转而向左上右下分别挥出，右手使一招"+(order[random(13)])+"「斜飞式」"NOR"，挥向$n的$l",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,
"skill_name" : "斜飞式",
	"lvl" : 45,
"damage_type" : "瘀伤"
	 ]),
([	"action" : "$N左手虚按，右手使一招"+(order[random(13)])+"「白蛇吐信」"NOR"，向$n的$l插去",
		"attack":	500,
		"parry":	500,
		"dodge":	500,
		"damage":	500,
		"force":	500,
"skill_name" : "白蛇吐信",
	"lvl" : 50,
"damage_type" : "瘀伤"
	 ]),
([	"action" : "$N双手握拳，向前向后划弧，一招"+(order[random(13)])+"「双峰贯耳」"NOR"打向$n的$l",
		"attack":	500,
		"parry":	500,
		"dodge":	500,
		"damage":	500,
		"force":	500,
"skill_name" : "双风贯耳",
	"lvl" : 55,
"damage_type" : "瘀伤"
	 ]),
([	"action" : "$N左手虚划，右手一记"+(order[random(13)])+"「指裆锤」"NOR"击向$n的裆部",
		"attack":	500,
		"parry":	500,
		"dodge":	500,
		"damage":	500,
		"force":	500,
"skill_name" : "指裆锤",
	"lvl" : 60,
"damage_type" : "瘀伤"
	 ]),
([	"action" : "$N施出"+(order[random(13)])+"「伏虎式」"NOR"，右手击向$n的$l，左手攻向$n的裆部",
		"attack":	500,
		"parry":	500,
		"dodge":	500,
		"damage":	500,
		"force":	500,
"skill_name" : "伏虎式",
	"lvl" : 65,
"damage_type" : "瘀伤"
	 ]),
([	"action" : "$N由臂带手，在面前缓缓划过，使一招"+(order[random(13)])+"「云手」"NOR"，挥向$n的$l",
		"attack":	600,
		"parry":	600,
		"dodge":	600,
		"damage":	600,
		"force":	600,	
"skill_name" : "云手",
	"lvl" : 70,
"damage_type" : "瘀伤"
	 ]),
([	"action" : "$N左腿收起，右手使一招"+(order[random(13)])+"「金鸡独立」"NOR"，向$n的$l击去",
		"attack":	600,
		"parry":	600,
		"dodge":	600,
		"damage":	600,
		"force":	600,	
"skill_name" : "金鸡独立",
	"lvl" : 75,
"damage_type" : "瘀伤"
	 ]),
([	"action" : "$N右手由钩变掌，双手掌心向上，右掌向前推出一招"+(order[random(13)])+"「高探马」"NOR"",
		"attack":	600,
		"parry":	600,
		"dodge":	600,
		"damage":	600,
		"force":	600,	
"skill_name" : "高探马",
	"lvl" : 80,
"damage_type" : "瘀伤"
	 ]),
([	"action" : "$N右手使一式招"+(order[random(13)])+"「玉女穿梭」"NOR"，扑身向$n的$l插去",
		"attack":	600,
		"parry":	600,
		"dodge":	600,
		"damage":	600,
		"force":	600,	
"skill_name" : "玉女穿梭",
	"lvl" : 85,
"damage_type" : "瘀伤"
	 ]),
([	"action" : "$N右手经腹前经左肋向前撇出，使一招"+(order[random(13)])+"「反身撇锤」"NOR"，向$n的$l锤去",
		"attack":	600,
		"parry":	600,
		"dodge":	600,
		"damage":	600,
		"force":	600,	
"skill_name" : "反身撇锤",
	"lvl" : 90,
"damage_type" : "瘀伤"
	 ]),
([	"action" : "$N左手虚按，右腿使一招"+(order[random(13)])+"「转身蹬腿」"NOR"，向$n的$l踢去",
		"attack":	600,
		"parry":	600,
		"dodge":	600,
		"damage":	600,
		"force":	600,	
"skill_name" : "反身蹬腿",
	"lvl" : 95,
"damage_type" : "瘀伤"
	 ]),
([	"action" : "$N左手向上划弧拦出，右手使一招"+(order[random(13)])+"「搬拦锤」"NOR"，向$n的$l锤去",
		"attack":	600,
		"parry":	600,
		"dodge":	600,
		"damage":	600,
		"force":	600,	
"skill_name" : "白蛇吐信",
	"lvl" : 100,
"damage_type" : "瘀伤"
	 ]),
([	"action" : "$N使一招"+(order[random(13)])+"「栽锤」"NOR"，左手搂左膝，右手向下锤向$n的$l",
		"attack":	600,
		"parry":	600,
		"dodge":	600,
		"damage":	600,
		"force":	600,	
"skill_name" : "栽锤",
	"lvl" : 110,
"damage_type" : "瘀伤"
	 ]),
([	"action" : "$N双手先抱成球状，忽地分开右手上左手下，一招"+(order[random(13)])+"「野马分鬃」"NOR"，向$n的$l和面门打去",
		"attack":	600,
		"parry":	600,
		"dodge":	600,
		"damage":	600,
		"force":	600,	
"skill_name" : "野马分鬃",
	"lvl" : 120,
"damage_type" : "瘀伤"
	 ]),
([	"action" : "$N左手由胸前向下，右臂微曲，使一招"+(order[random(13)])+"「抱虎归山」"NOR"，向$n的$l推去",
		"attack":	600,
		"parry":	600,
		"dodge":	600,
		"damage":	600,
		"force":	600,	
"skill_name" : "抱虎归山",
	"lvl" : 130,
"damage_type" : "瘀伤"
	 ]),
([	"action" : "$N双手经下腹划弧交于胸前，成十字状，一式"+(order[random(13)])+"「十字手」"NOR"，向$n的$l打去",
		"attack":	600,
		"parry":	600,
		"dodge":	600,
		"damage":	600,
		"force":	600,	
"skill_name" : "十字手",
	"lvl" : 140,
"damage_type" : "瘀伤"
	 ]),
([	"action" : "$N左脚踏一个虚步，双手交叉成十字拳，一招"+(order[random(13)])+"「进步七星」"NOR"，向$n的$l锤去",
		"attack":	700,
		"parry":	700,
		"dodge":	700,
		"damage":	700,
		"force":	700,
"skill_name" : "进步七星",
	"lvl" : 150,
"damage_type" : "瘀伤"
	 ]),
([	"action" : "$N身体向后腾出，左手略直，右臂微曲，使一招"+(order[random(13)])+"「倒撵猴」"NOR"，向$n的$l和面门打去",
		"attack":	700,
		"parry":	700,
		"dodge":	700,
		"damage":	700,
		"force":	700,
"skill_name" : "倒撵猴",
	"lvl" : 160,
"damage_type" : "瘀伤"
	 ]),
([	"action" : "$N双手伸开，以腰为轴，整个上身划出一个大圆弧，\n一招"+(order[random(13)])+"「转身摆莲」"NOR"，将$n浑身上下都笼罩在重重掌影之中",
		"attack":	800,
		"parry":	800,
		"dodge":	800,
		"damage":	800,
		"force":	800,
"skill_name" : "转身摆莲",
	"lvl" : 170,
"damage_type" : "瘀伤"
	 ]),
([	"action" : "$N双手握拳，右手缓缓收至耳际，左手缓缓向前推出，\n拳意如箭，一招"+(order[random(13)])+"「弯弓射虎」"NOR"，直奔$n心窝而去",
		"attack":	900,
		"parry":	900,
		"dodge":	900,
		"damage":	900,
		"force":	900,
"skill_name" : "弯弓射虎",
	"lvl" : 180,
"damage_type" : "瘀伤"
	 ]),
([	"action" : "$N双手在胸前翻掌，由腹部向前向上推出，一招"+(order[random(13)])+"「如封似闭」"NOR"，一股劲风直逼$n",
		"attack":	900,
		"parry":	900,
		"dodge":	900,
		"damage":	900,
		"force":	900,
"skill_name" : "如封似闭",
	"lvl" : 200,
"damage_type" : "瘀伤"
	 ]),
});

int valid_enable(string usage)
{
	return usage=="cuff" || usage=="parry";
}
//2019-1-1阿飞新规划，技能代码完善
//string valid_combine() { return "juehu-shou"; }		//互备技能
string skill_pinji() {return "上乘";}				//品级区分：上乘、中乘、下乘
string skill_xingbie() {return "通用";}				//性别区分：男性、女性、无性、通用
string skill_zhengxie() {return "正道";}			//正邪区分：正道、邪道、中立
string skill_menpai() {return "武当派";}				//门派区分：门派，江湖
string skill_yinyang() {return "中性";}				//阴阳区分：阳、阴、中性
string skill_zhenying() {return "正派";}			//阵营区分：正派、邪派、中立、通用
int damage_damage() {return 55;}	//外伤系数
int force_damage() {return 88;}		//内伤系数
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
		return notify_fail("练太极拳必须空手。\n");
	if ((int)me->query_skill("taiji-shengong", 1) < 30)
		return notify_fail("你的太极神功火候不够，无法学太极拳。\n");
	if ((int)me->query_skill("taiji-quan", 1) > 3000)
		return notify_fail("上乘武学只能教到这里了，以后要靠自己勤加修习领悟。\n");		
	if (me->query("family/family_name")!="武当派")
		return notify_fail("你不是武当弟子，学不了。\n");	
	if ((int)me->query("con", 1) < 30)
		return notify_fail("你的根骨不够，难以领会太极行云流水的意境。\n");		
	if ((int)me->query("max_neili") < 1000)
		return notify_fail("你的内力太弱，无法练太极拳。\n");
	if (me->query_skill("cuff", 1) <=me->query_skill("taiji-quan", 1))
		return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
	if ((int)me->query("score",1) < 1000)
		return notify_fail("你对我派毫无贡献而言，怎么可能传授你武功呢。\n");
	if (random(10)==1) me->add("score",-10);		
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
	int level;
	string msg;
	level = (int) me->query_skill("taiji-quan",1);
	msg = random(2)==1?HIW"只见$N虚灵顶劲、涵胸拔背、松腰垂臀、沉肩坠肘，双手抱了个太极式的圆圈，纯以意行太极，已达形神合一，心动气动的境界，\n结果使出了太级拳中的"NOR:
	      HIW"刹时间$N悟到了太极拳旨中“似松非松，将展未展，劲断意不断”的精微奥妙之处，使出一招犹如行云流水，潇洒无比。\n结果使出了太级拳中的"NOR;
	msg = msg + order[random(13)] + taijin[random(14)] + NOR;
	if ( me->query_temp("taiji") && random(level) > 300 && random(20)>15 && me->query("jiali")>100)
	{
		return ([
            "action" : msg,
			"attack":	1000,
			"parry":	1000,
			"dodge":	1000,
			"damage":	1000,
			"force":	1000,
            "damage_type" : random(2)==1?"瘀伤":"内伤",
		        ]);
	}
	
	if ( me->query_temp("powerup") && random(level) > 300 && random(20)>15 && me->query("jiali")>100)
	{
		return ([
            "action": HIW"$N双手一圈，如抱太极，一股雄浑无比的力道组成了一个旋涡，结果$n的力道被太极拳借力打力反击回来！"NOR,
			"attack":	900,
			"parry":	900,
			"dodge":	900,
			"damage":	900,
			"force":	900,
            "damage_type" : "内伤",
            "skill_name" : "阴阳决",
		        ]);
	}

	if ( random(level) > 300 && random(20)>15 && me->query("jiali")>100)
	{
		return ([
            "action": HIW"$N左掌阳，右掌阴，目光凝视$n，两掌向$p慢慢合拢，竟是凝重如山，却又轻灵似羽！"NOR,
			"attack":	800,
			"parry":	800,
			"dodge":	800,
			"damage":	800,
			"force":	800,
            "damage_type" : "内伤",
            "skill_name" : "阴阳决",
		        ]);
	}
	return action[random(sizeof(action))];	//2017.9.4阿飞改，将招式简单点

}

int practice_skill(object me)
{
//	if (!wizardp(me))
//		return ("巫师突然从黑暗中冲了出来，对你大吼一声：该门派没开放。\n");	
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练太极拳必须空手。\n");
	if (me->query("family/family_name")!="武当派")
		return notify_fail("你先加入武当派在练吧。\n");	
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练太极拳。\n");

	me->receive_damage("qi", 25);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"taiji-quan/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{
	int ap,dp, damage1,damage2,damage,liannum;

    ap = me->query_skill("taiji-quan",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	dp = victim->query_skill("parry",1)*(victim->query("breakup")+victim->query("breakup")*victim->query("breakup")+100)/100;
    damage1= (int) me->query_skill("taiji-quan",1);
	damage2 = (int)me->query_skill("taiji-quan",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	if( me->query_temp("lianzhao")>=1) liannum=me->query_temp("lianzhao");
	else liannum =1;
	if( me->query("neili") < 100 || me->query("jingli") < 100 || damage_bonus < 100 ) return 0;
	if ( (me->query_skill("taiji-shengong",1) < 100 && me->query_skill("yinyun-ziqi",1) < 100) || me->query_skill("taiji-quan",1)<100) return 0;
//	if ( me->query_skill_mapped("force") != "taiji-shengong" && me->query_skill_mapped("force") != "yinyun-ziqi") return 0;
	if (objectp(me->query_temp("weapon")) ) return 0;

	if (random(7)==1 && random(ap) > dp/3 && me->query("jiali") > 0)
	{
		damage = (damage1+damage_bonus)*(liannum+20)/(20*liannum+1);
		victim->receive_damage("qi", damage ,me);
		victim->receive_wound("qi", damage/3 ,me);
		me->add("neili", -100);
		message_vision(HIY"$N运起“引”字诀，如影随形，右掌已搭住$n左腕，巧劲随即发出！结果$n身不由主的向前一冲，跨出几步，方始站定。\n"NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
        return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiajing")>0 && random(7)==2 && (int)me->query("breakup")>1 )
	{
		damage = (damage2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("jingli",-100);
		victim->receive_damage("jing", damage,me);
		victim->receive_wound("jing", damage/3,me);
		message_vision(HIG "$N顿悟"+me->query("cognize")+HIG"，运起“挤”字诀，双手一圈，如抱太极，一股雄浑无比的力道组成了一个旋涡！结果$n身不由主的在原地急转了七八下，如转陀螺，如旋纺锤！\n"NOR, me,victim,damage,HBWHT+HIR"特效伤精"NOR);
		return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiali")>0 && random(7)==3 && (int)me->query("jm/wudang") )
	{
		damage = ((damage1+damage2)/2+damage_bonus)*(liannum+20)/(20*liannum+1);
		victim->receive_damage("qi", damage,me);
		victim->receive_wound("qi", damage/3,me);
		message_vision(HIM"$N融汇武当太极精髓，运起太极拳中粘、引、挤、按等招式，想将$n身子带歪！$n想使出千斤坠之力定住身形，却已满脸胀得通红，身不由己，狼狈万状。"NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
		me->add("neili",-100);
		return ;
	}	
	if( random(ap) > dp/3 && (int)me->query("jiali")>0 && random(7)==4 )
	{
		damage = (damage1+damage_bonus)*(liannum+20)/(20*liannum+1);
		victim->receive_damage("qi", damage,me);
		victim->receive_wound("qi", damage/3,me);
		message_vision(HIM"$N运起“粘”字诀，双手弧划，左圈右围，一个跟着一个，太极圆圈连连发出！登时便套得$n跌跌撞撞，身不由主的立足不稳，犹如中酒昏迷。"NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
		me->add("neili",-100);
		return ;
	}

}

//2017.3.25阿飞封掉ob_hit特效，怀疑与伤害为0的死亡有关
int ob_hit(object ob, object me, int damage)
{
	string msg;
	int ap,dp,j,damage1,damage2;

	ap = me->query_skill("taiji-quan", 1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	dp = ob->query_skill("sword",1)*(ob->query("breakup")+ob->query("breakup")*ob->query("breakup")+100)/100;
	damage1 = me->query_skill("taiji-quan", 1);
	damage2 = me->query_skill("taiji-quan", 1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	if( damage < 10 ) damage=10;
	if( me->query("neili") < 100 || me->query("jingli") < 100 ) return damage;
	if ( (me->query_skill("taiji-shengong",1) < 100 && me->query_skill("yinyun-ziqi",1) < 100) || me->query_skill("taiji-quan",1)<100) return damage;
//	if ( me->query_skill_mapped("force") != "taiji-shengong" && me->query_skill_mapped("force") != "yinyun-ziqi") return damage;
	if (objectp(me->query_temp("weapon"))) return damage;

	if ( random(8) == 1 && random(ap) > dp/4 )
	{
		msg = HIG"$n只觉上盘各路已全处在$N双掌的笼罩之下，避无可避，只得运劲于背，硬接他这一掌，同时右臂紧挥，只盼两人各受一招，成个两败俱伤之局。\n"NOR;
		if (!ob->is_busy()) ob->start_busy(1);
		me->add("neili", -100 );
		j = -(damage+random(damage));
		ob->receive_damage("qi",damage1,me);
		ob->receive_wound("qi",damage1/2,me);
		message_vision(msg, me, ob,damage1,HBWHT+HIY"气血反伤"NOR);
		return j;
	}
	if(random(ap) > dp/4 && random(8)==2 && (int)me->query("breakup")>1 )
	{
		msg = HIY"$N顿悟"+me->query("cognize")+HIY"，如抱太极，一股雄浑无比的力道组成了一个旋涡，只带得$n在原地急转七八下，如转陀螺，好容易使出“千斤坠”之力定住身形，却已满脸胀得通红，狼狈万状！！\n"NOR;
		j = -(damage+random(damage));
		ob->receive_damage("jing",damage2,me);
		ob->receive_wound("jing",damage2/2,me);
		me->add("jingli", -100 );
		if (!ob->is_busy()) ob->start_busy(1);
		message_vision(msg, me, ob,damage2,HBWHT+HIY"精神反伤"NOR);
		return j;
	}
	if(random(ap) > dp/4 && random(8)==3 && (int)me->query("jm/wudang") )
	{
		msg =HIC"$N融汇武当派以柔克刚之精髓，用借力打力之法使身体微侧，左手一划，套住$n，右掌顺势一推，以四两拨千斤之巧劲将$n的劲力全数倒翻回去！"NOR;
		j = -(damage+random(damage));
		ob->receive_damage("qi",damage1,me);
		ob->receive_wound("qi",damage1/2,me);
		me->add("neili", -100 );
		if (!ob->is_busy()) ob->start_busy(1);
		message_vision(msg, me, ob,damage1,HBWHT+HIY"气血反伤"NOR);
		return j;
	}
}
mapping buffer_applied(object ob)
{
    mapping buf, tbuf;
    int level;
    
    if ( ob->query("family/family_name") != "武当派" )
    {
      buf=([]);
      ob->delete_temp("zhanyi-18die");
      return buf;
    }
	
	if (ob->query_skill_mapped("parry")!="taiji-quan" || mapp(ob->query_temp("zhanyi-18die")) )
      return buf;
    
    level=ob->query_skill("zhanyi-18die",1);
	if (level <=0)  return buf;
	
    buf=([]);
	if(ob->query("chushi/done") || ob->query("betrayer"))
	{
		buf["parry_factor"]=1+level/300;
		if ( buf["parry_factor"]>8 )
			buf["parry_factor"]=8;
		buf["week_injure"]=1+level/600;
		if ( buf["week_injure"]>4 )
			buf["week_injure"]=4;
	}
	else
	{
		buf["parry_factor"]=1+level/150;
		if ( buf["parry_factor"]>16 )
			buf["parry_factor"]=16;
		buf["week_injure"]=1+level/300;
		if ( buf["week_injure"]>8 )
			buf["week_injure"]=8;
	}
/*    buf["dodge_factor"]=-1-level/200;
    if ( buf["dodge_factor"]<-11 )
      buf["dodge_factor"]=-11; */
//去除门派限制。enable 武功不应该纳入 perform buff 限制
/*    if ( mapp(tbuf=ob->query_temp("active_buffer")) &&
         sizeof(tbuf)>1 &&
         stringp(tbuf["family"]) &&
         tbuf["family"]!="武当派" &&
         tbuf["family"]!="公共武学" )
    {
      buf=([]);
      ob->delete_temp("zhanyi-18die");
      return buf;
    }
*/
    ob->set_temp("zhanyi-18die", buf);
    ob->set_temp("active_buffer/family","武当派");
    ob->set_temp("active_buffer/zhanyi-18die/name", "沾衣十八跌");                       //buff名称
    ob->set_temp("active_buffer/zhanyi-18die/effect1", "招架+"+(buf["parry_factor"])+"%");     //效果描述1
//    ob->set_temp("active_buffer/zhanyi-18die/effect2", "躲闪命中"+(buf["dodge_factor"])+"%");     //效果描述2
    ob->set_temp("active_buffer/zhanyi-18die/effect2", "普通伤害抗性+"+(buf["week_injure"])+"%");     //效果描述3
    return buf;
}

mapping buffer_removed(object ob)
{
    mapping buf;
    
    buf=ob->query_temp("zhanyi-18die");
    if ( mapp(buf) && ( ob->query("family/family_name") != "武当派" || ob->query_skill_mapped("parry")!="taiji-quan"
			|| ob->query_skill("zhanyi-18die",1)<=0 ) )
	{
		buf["parry_factor"]=buf["parry_factor"]*(-1);
		buf["dodge_factor"]=buf["dodge_factor"]*(-1);
		buf["week_injure"]=buf["week_injure"]*(-1);
		ob->delete_temp("zhanyi-18die");
		ob->delete_temp("active_buffer/zhanyi-18die");
	}
    else
      buf=([]);
    return buf;
}
