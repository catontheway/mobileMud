//yiyang-zhi 	一阳指 	中乘武学200~600
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
//#include <condition.h>
inherit SKILL;
string *order = ( {""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

string *xue_name = (
{
	"劳宫穴","膻中穴","曲池穴","关元穴","曲骨穴","中极穴","承浆穴","天突穴","百会穴",
	"幽门穴","章门穴","大横穴","紫宫穴","冷渊穴","天井穴","极泉穴","清灵穴","至阳穴",
});

mapping *action = (
{
([      "action" : "$N右手食指微点，出招"+(order[random(13)])+"「晓天初阳」"NOR"，一股雄浑的一阳指力射向$n，出手沉稳，招数正大",
		"attack":	200,
		"parry":	200,
		"dodge":	200,
		"damage":	200,
		"force":	200,
"weapon" : "一阳指力",
	"lvl" : 0,
"skill_name" : "晓天初阳",
"damage_type" : "刺伤"
	 ]),
([      "action" : "$N一指"+(order[random(13)])+"「日出霞光」"NOR"，激出的一股罡气涌向$n，看似是温淳平和，但沛然浑厚，无可与抗",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
	"lvl" : 20,
"skill_name" : "日出霞光",
"damage_type" : "内伤"
	 ]),
([      "action" : "忽听嗤嗤轻响，一股柔和的气流自$N手指涌出，正是一招"+(order[random(13)])+"「阳春暖融」"NOR"，缓缓点向$n$l",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
"weapon" : "一阳指力",
	"lvl" : 40,
"skill_name" : "阳春暖融",
"damage_type" : "刺伤"
	 ]),
([      "action": "$N一步跨到$n身后，又如闪电般跃回，一式「鲁阳返日」，右手食指疾出，指向$n的$l",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
	"lvl" : 60,
"weapon" : HIR "一阳指力" NOR,
"skill_name" : "鲁阳返日",
"damage_type" : "刺伤"
	 ]),
([      "action": "$N左手轻扬，右手食指挟着雄浑内力疾点$n的$l，招式光明坦荡，正是一式「阳春白雪」",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
	"lvl" : 80,
"weapon" : HIR "一阳指力" NOR,
"skill_name" : "阳春白雪",
"damage_type" : "刺伤"
	 ]),
([      "action": "$N身影飘起，一式「阳钩挥天」，身形自上而下闪出，右手猛然劲点向$n的$l",
		"attack":	500,
		"parry":	500,
		"dodge":	500,
		"damage":	500,
		"force":	500,
	"lvl" : 100,
"weapon" : HIR "一阳指力" NOR,
"skill_name" : "阳钩挥天",
"damage_type" : "刺伤"
	 ]),
([      "action" : "$N踏前一步，伸指凌空轻轻一点，$n只觉气息一紧，已被"+(order[random(13)])+"「赤日焦阳」"NOR"的刚阳气劲触到$l",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
	"lvl" : 60,
"weapon" : "纯阳真气",
"skill_name" : "赤日焦阳",
"damage_type" : "刺伤"
	 ]),
([      "action" : "$N衣袖轻摆，罡阳柔气从袖底挥出，涌向$n的$l，正是玄功若神的一招"+(order[random(13)])+"「晓阳云暖」"NOR"",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,
	"lvl" : 80,
"skill_name" : "晓阳云暖",
"damage_type" : "内伤"
	 ]),
([      "action": "$N左掌斜削，突然间变掌为指，嗤的一式「丹凤朝阳」，使出一阳指力，疾点$n的$l",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,
	"lvl" : 180,
"weapon" : HIR "一阳指力" NOR,
"skill_name" : "丹凤朝阳",
"damage_type" : "刺伤"
	 ]),
([      "action" : "$N面带微笑，伸出右食指，缓缓点向$n胸口，这招"+(order[random(13)])+"「暮云映日」"NOR"劲气弥漫，却无丝毫破空之声",
		"attack":	500,
		"parry":	500,
		"dodge":	500,
		"damage":	500,
		"force":	500,
"weapon" : "一阳指力",
	"lvl" : 100,
"skill_name" : "暮云映日",
"damage_type" : "刺伤"
	 ]),
([      "action" : "只见$N食指微屈，一指"+(order[random(13)])+"「九天乾阳」"NOR"点出，气象森严，雍容肃穆，于威猛之中不脱王者风度！",
		"attack":	600,
		"parry":	600,
		"dodge":	600,
		"damage":	600,
		"force":	600,
"weapon" : "纯阳真气",
	"lvl" : 110,
"skill_name" : "九天乾阳",
"damage_type" : "内伤"
	 ]),
([ "action" : HIW"$N头顶白气氤氲，渐聚渐浓，便似蒸笼一般，食指伸出，一式"+(order[random(13)])+"「三阳开泰」"NOR"按向$n！"NOR,
		"attack":	600,
		"parry":	600,
		"dodge":	600,
		"damage":	600,
		"force":	600,
	"lvl" : 130,
"skill_name" : "三阳开泰",
"damage_type" : "震伤"
	 ])
});

int valid_enable(string usage)
{
	return usage=="unarmed" || usage=="parry" || usage=="finger";
}
//2019-1-1阿飞新规划，技能代码完善
//string valid_combine() { return "juehu-shou"; }		//互备技能
string skill_pinji() {return "中乘";}				//品级区分：上乘、中乘、下乘
string skill_xingbie() {return "男性";}				//性别区分：男性、女性、无性、通用
string skill_zhengxie() {return "正道";}			//正邪区分：正道、邪道、中立
string skill_menpai() {return "大理段家";}				//门派区分：门派，江湖
string skill_yinyang() {return "中性";}				//阴阳区分：阳、阴、中性
string skill_zhenying() {return "中立";}			//阵营区分：正派、邪派、中立、通用
int damage_damage() {return 60;}	//外伤系数
int force_damage() {return 60;}		//内伤系数
//int qi_heal() {return 50;}		//内功疗气系数
//int jing_heal() {return 50;}		//内功疗精系数
int practice_level() {return 100;}	//自练级别
int practice_add() {return 100;}	//自练效率
int perform_level() {return 300;}	//PFM最低使用级别

int valid_learn(object me)
{
//	if (!wizardp(me))
//		return ("巫师突然从黑暗中冲了出来，对你大吼一声：该门派没开放。\n");	
	if ( me->query("gender") != "男性" )
		return notify_fail("你又不是男人练不了一阳指。\n");
    if ((int)me->query("int", 1) < 15)
        return notify_fail("你呆头呆脑的学不了一阳指。\n");
    if ((int)me->query("con", 1) < 25)
        return notify_fail("你体质虚弱，恐怕练不了一阳指。\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练一阳指必须空手。\n");

	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练一阳指。\n");
	if (me->query_skill("finger", 1) <=me->query_skill("yiyang-zhi", 1))
		return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
	
	if (random(100)==1) me->add("score",-5);
	return 1;
}

int valid_combine(string combo)
{
	return combo=="haotian-zhang";
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
	return action[random(sizeof(action))];	//2017.9.4阿飞改，将招式简单点
}
int practice_skill(object me)
{
//	if (!wizardp(me))
//		return ("巫师突然从黑暗中冲了出来，对你大吼一声：该门派没开放。\n");	
	if ( me->query("gender") != "男性" )
		return notify_fail("你又不是男人练不了一阳指。\n");
	if (me->query_skill("unarmed", 1) <=me->query_skill("yiyang-zhi", 1))
		return notify_fail("你的基础不够，无法练习更高深的技巧。\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练一阳指必须空手。\n");
  
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练一阳指。\n");
	
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"yiyang-zhi/" + action;
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{
	string name;
	int ap,dp, damage1,damage2,damage,liannum;

    ap = me->query_skill("yiyang-zhi",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	dp = victim->query_skill("parry",1)*(victim->query("breakup")+victim->query("breakup")*victim->query("breakup")+100)/100;
    damage1= (int) me->query_skill("yiyang-zhi",1);
	damage2 = (int)me->query_skill("yiyang-zhi",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	name = xue_name[random(sizeof(xue_name))];
	if( me->query_temp("lianzhao")>=1) liannum=me->query_temp("lianzhao");
	else liannum =1;
	if( me->query("neili") < 100 || me->query("jingli") < 100 || damage_bonus < 100 ) return 0;
	if ( me->query_skill("kumu-shengong",1) < 100 || me->query_skill("yiyang-zhi",1)<100) return 0;
//	if ( me->query_skill_mapped("force") != "kumu-shengong") return 0;
	if (objectp(me->query_temp("weapon"))) return 0;

	if (random(7)==1 && random(ap) > dp/3 && me->query("jiali") > 0)
	{
		damage = (damage1+damage_bonus)*(liannum+20)/(20*liannum+1);
		victim->receive_damage("qi", damage ,me);
		victim->receive_wound("qi", damage/3 ,me);
		me->add("neili", -100);
		if (!victim->is_busy()) victim->start_busy(1);
		message_vision(CYN "$n被$N发出的指劲击中"RED+name+CYN"，真气不由得一滞！\n" NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
        return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiajing")>0 && random(7)==2 && (int)me->query("breakup")>1 )
	{
		damage = (damage2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("jingli",-100);
		victim->receive_damage("jing", damage,me);
		victim->receive_wound("jing", damage/3,me);
		if (!victim->is_busy()) victim->start_busy(1);
		message_vision(HIG "$N顿悟"+me->query("cognize")+HIG"，$n被$N凌空一指点中"RED+name+CYN"，真气不由得一滞！。\n" NOR, me,victim,damage,HBWHT+HIR"特效伤精"NOR);
		return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiali")>0 && random(7)==3 && (int)me->query("jm/dali") )
	{
		damage = ((damage1+damage2)/2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("neili",-100);
		victim->receive_damage("qi", damage,me);
		victim->receive_wound("qi", damage/3,me);
		if (!victim->is_busy()) victim->start_busy(1);
		message_vision(HIM"$N贯通大理段氏武学精髓，$n被$N发出的剑气刺中"RED+name+CYN"，飚出一道鲜血！\n" NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
		return ;
	}
}

//2017.3.25阿飞封掉ob_hit特效，怀疑与伤害为0的死亡有关
int ob_hit(object ob, object me, int damage)
{
	string name,msg;
	int ap,dp,j,damage1,damage2;
	name = xue_name[random(sizeof(xue_name))];
	ap = me->query_skill("yiyang-zhi", 1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	dp = ob->query_skill("unarmed",1)*(ob->query("breakup")+ob->query("breakup")*ob->query("breakup")+100)/100;
	damage1 = me->query_skill("yiyang-zhi", 1);
	damage2 = me->query_skill("yiyang-zhi", 1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	if( damage < 10 ) damage=10;
	if( me->query("neili") < 100 || me->query("jingli") < 100 ) return damage;
	if (objectp(me->query_temp("weapon"))) return damage;
	if (me->query_skill("kumu-shengong",1) < 300 || me->query_skill("yiyang-zhi", 1) < 300) return damage;
//	if (me->query_skill_mapped("force")!="kumu-shengong" ) return damage;

	if ( random(8) == 1 && random(ap) > dp/4 )
	{
        msg = HIY"$n"+HIY+"被$N的纯阳指力反点！结果点中了 "+ name +HIY"。\n"NOR;
		if (!ob->is_busy()) ob->start_busy(1);
		ob->apply_condition("yyz_damage",30);
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
		message_vision(HIY"$N顿悟"+me->query("cognize")+HIY"，$n出招之际，$N右手食指挟着纯阳指力点中$n手腕，内劲顺着手太阴肺经攻入$n檀中。\n"NOR, me, ob,damage2,HBWHT+HIY"精神反伤"NOR);
		return j;
	}
	if(random(ap) > dp/4 && random(8)==3 && (int)me->query("jm/dali") )
	{
		j = -(damage/3+random(damage/3));
		me->add("eff_qi",damage1+damage2);
		if (me->query("eff_qi")>me->query("max_qi")) me->set("eff_qi",me->query("max_qi"));
		me->add("qi",damage1+damage2);
		if (me->query("qi")>me->query("eff_qi")) me->set("qi",me->query("eff_qi"));
		me->add("neili", -100 );
		message_vision(HIB"$N融汇天龙寺武学精髓，深吸一口气！施展开一阳指诀，以纯阳指力遍布全身！脸色红润多了。\n"NOR, me, ob);
		return j;
	}
}

