// kongming-quan.c	空明拳	中乘武学200~600
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit SKILL;
mapping *action = (
{
([      "action" : "$N使出「空」字诀，单拳击出，拳式若有若无，似乎毫无着力处，却又径直袭向$n",
		"attack":	200,
		"parry":	200,
		"dodge":	200,
		"damage":	200,
		"force":	200,
	"lvl" : 0,
"skill_name" : "空字诀",
"damage_type" : "瘀伤"
	 ]),
([      "action" : "$N使出「朦」字诀，拳招胡里胡涂，看似不成章法，但拳势却直指$n的$l",
		"attack":	200,
		"parry":	200,
		"dodge":	200,
		"damage":	200,
		"force":	200,
	"lvl" : 0,
"skill_name" : "朦字诀",
"damage_type" : "瘀伤"
	 ]),
([      "action" : "$N使出「洞」字诀，单拳似乎由洞中穿出，劲道内敛，招式却咄咄逼人，狠狠地击向$n",
		"attack":	200,
		"parry":	200,
		"dodge":	200,
		"damage":	200,
		"force":	200,
	"lvl" : 6,
"skill_name" : "洞字诀",
"damage_type" : "瘀伤"
	 ]),
([      "action" : "$N使出「松」字诀，出拳浑似无力，软绵绵地划出，轻飘飘地挥向$n的$l",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
	"lvl" : 12,
"skill_name" : "松字诀",
"damage_type" : "瘀伤"
	 ]),
([      "action" : "$N使出「风」字诀，单拳击出，带起一股柔风，$n刚觉轻风拂体，拳招竟已袭到了面前",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
	"lvl" : 20,
"skill_name" : "风字诀",
"damage_type" : "瘀伤"
	 ]),
([      "action" : "$N使出「通」字诀，拳力聚而不散，似有穿通之形，直击$n的$l",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
	"lvl" : 28,
"skill_name" : "通字诀",
"damage_type" : "瘀伤"
	 ]),
([      "action" : "$N使出「容」字诀，拳走空明，外包内容，似轻实重，正对着$n当胸而去",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
	"lvl" : 35,
"skill_name" : "容字诀",
"damage_type" : "瘀伤"
	 ]),
([      "action" : "$N使出「梦」字诀，拳势如梦，又在半梦半醒，$n一时神弛，拳风已然及体",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
	"lvl" : 40,
"skill_name" : "梦字诀",
"damage_type" : "瘀伤"
	 ]),
([      "action" : "$N使出「冲」字诀，单拳直击，拳式举重若轻，向$n的$l打去",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
	"lvl" : 46,
"skill_name" : "冲字诀",
"damage_type" : "瘀伤"
	 ]),
([      "action" : "$N使出「穷」字诀，正显潦倒之形，拳势虽然显出穷途末路，却暗含杀机，窥$n不备而猛施重拳",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,
	"lvl" : 53,
"skill_name" : "穷字诀",
"damage_type" : "瘀伤"
	 ]),
([      "action" : "$N使出「中」字诀，单拳缓缓击出，不偏不倚，虽是指向正中，拳力却将$n的周身笼住",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,
	"lvl" : 59,
"skill_name" : "中字诀",
"damage_type" : "瘀伤"
	 ]),
([      "action" : "$N使出「弄」字诀，拳招陡然花俏，似在作弄$n，却又暗伏后招",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,
	"lvl" : 65,
"skill_name" : "弄字诀",
"damage_type" : "瘀伤"
	 ]),
([      "action" : "$N使出「童」字诀，出拳如稚童般毫无章法，胡乱击向$n的$l",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,
	"lvl" : 72,
"skill_name" : "童字诀",
"damage_type" : "瘀伤"
	 ]),
([      "action" : "$N使出「庸」字诀，单拳击出时是最简单的招式，平平无奇，可是却阻住了$n的退路",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,
	"lvl" : 78,
"skill_name" : "庸字诀",
"damage_type" : "瘀伤"
	 ]),
([      "action" : "$N使出「弓」字诀，身体弯曲如弓，拳出似箭，迅捷地袭向$n",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,
	"lvl" : 85,
"skill_name" : "弓字诀",
"damage_type" : "瘀伤"
	 ]),
([      "action" : "$N使出「虫」字诀，身子柔软如虫，拳招也随着蠕动，$n竟无法判断这一拳的来势",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,
	"lvl" : 95,
"skill_name" : "虫字诀",
"damage_type" : "瘀伤"
	 ]),
([  "action":       "$N使一招「"+HIB+"空屋住人"+NOR+"」，双手轻飘飘地箍向$n$l",
		"attack":	500,
		"parry":	500,
		"dodge":	500,
		"damage":	500,
		"force":	500,
"damage_type": "瘀伤"
	 ]),
([  "action":       "$N左掌一平,右掌一伸,一招「"+HIB+"空碗盛饭"+NOR+"」直拍$n的$l",
		"attack":	500,
		"parry":	500,
		"dodge":	500,
		"damage":	500,
		"force":	500,
"damage_type": "瘀伤"
	 ]),
([  "action":       "$N身形绕$n一转，双手上撩,一招「"+HIB+"空钵装水"+NOR+"」击向$n$l",
		"attack":	500,
		"parry":	500,
		"dodge":	500,
		"damage":	500,
		"force":	500,
"damage_type": "瘀伤"
	 ]),
([  "action":       "$N左掌一按,右掌一挥,一招「"+HIB+"虚怀若谷"+NOR+"」拍向$n的$l",
		"attack":	500,
		"parry":	500,
		"dodge":	500,
		"damage":	500,
		"force":	500,
"damage_type": "瘀伤"
	 ]),
([  "action":       "$N使一招「"+HIB+"空山鸟语"+NOR+"」，$n的$l已围在$N的重重掌影之下",
		"attack":	500,
		"parry":	500,
		"dodge":	500,
		"damage":	500,
		"force":	500,
"damage_type": "瘀伤"
	 ]),
([  "action":       "$N神色一敛，使出「"+HIB+"我心空明"+NOR+"」，围绕$n的$l接连出掌",
		"attack":	600,
		"parry":	600,
		"dodge":	600,
		"damage":	600,
		"force":	600,	
"damage_type": "瘀伤"
	 ]),
});
int valid_enable(string usage)
{
	return usage=="cuff" ||  usage=="parry";
}
//2019-1-1阿飞新规划，技能代码完善
//string valid_combine() { return "juehu-shou"; }		//互备技能
string skill_pinji() {return "中乘";}				//品级区分：上乘、中乘、下乘
string skill_xingbie() {return "通用";}				//性别区分：男性、女性、无性、通用
string skill_zhengxie() {return "中立";}			//正邪区分：正道、邪道、中立
string skill_menpai() {return "江湖";}				//门派区分：门派，江湖
string skill_yinyang() {return "中性";}				//阴阳区分：阳、阴、中性
string skill_zhenying() {return "通用";}			//阵营区分：正派、邪派、中立、通用
int damage_damage() {return 50;}	//外伤系数
int force_damage() {return 50;}		//内伤系数
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
		return notify_fail("练空明拳必须空手。\n");
	if ((int)me->query("max_neili") < 150)
		return notify_fail("你的内力太弱，无法练空明拳。\n");
	if (me->query_skill("cuff", 1) <=me->query_skill("kongming-quan", 1))
		return notify_fail("你的基础不够，无法领会更高深的技巧。\n");

	if (random(100)==1) me->add("score",-5);
	return 1;
}
mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];	//2017.9.4阿飞改，将招式简单点
}
int practice_skill(object me)
{
//	if (!wizardp(me))
//		return ("巫师突然从黑暗中冲了出来，对你大吼一声：该门派没开放。\n");	
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练空明拳必须空手。\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("你的内力不够了！休息一下再练吧。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -5);
	return 1;
}
	//2017.3.25阿飞封掉ob_hit特效，怀疑与伤害为0的死亡有关
int ob_hit(object ob, object me, int damage)
{
	int j,ap,dp,damage2;
	ap = me->query_skill("kongming-quan", 1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	dp = ob->query_skill("parry", 1)*(ob->query("breakup")+ob->query("breakup")*ob->query("breakup")+100)/100;
	damage2 = me->query_skill("kongming-quan", 1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	if (damage <10)  damage=10;
	if( me->query("neili") < 100 || me->query("jingli") < 100 ) return damage;
	if (objectp(me->query_temp("weapon")) ) return damage;
	if (me->query_skill("kongming-quan",1) < 300 ) return damage;
//	if ( me->query_skill_mapped("force") != "yijing-force") return damage;
	
	if(random(ap) > dp/4 && random(8)==1	)
	{ 	
		message_vision(HIG"$N双拳空空如也，虚虚实实，变化莫测，让$n一时难以捕捉。\n"NOR, me, ob); 		
		j = -(damage+random(damage));
		me->add("neili", -100 );
		return j;        
	}  
	if(random(ap) > dp/4 && random(8)==2 && (int)me->query("breakup") )
	{
		j = -(damage/2+random(damage/2));
		ob->receive_damage("jing",damage2,me);
		ob->receive_wound("jing",damage2/2,me);
		me->add("jingli", -100 );
		message_vision(HIY"$N顿悟"+me->query("cognize")+HIY"，于$n招式用老之际，双拳飘飘忽忽的击出。\n"NOR, me, ob,damage2,HBWHT+HIY"精神反伤"NOR);
		return j;
	}
	if(random(ap) > dp/4 && random(8)==3 && (int)me->query("jm/quanzhen") )
	{
		j = -(damage/3+random(damage/3));
		if (!ob->is_busy()) ob->start_busy(2);
		me->add("neili", -100 );
		message_vision(HIB"$N融汇全真教武功精髓，左手实招，右手虚招，待$n刚出招，虚实转换，$n招式落入空处！\n"NOR, me, ob);		
		return j;
	}
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int ap,dp,damage1,damage2,damage,liannum;
	ap = me->query_skill("kongming-quan",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	dp = victim->query_skill("parry",1)*(victim->query("breakup")+victim->query("breakup")*victim->query("breakup")+100)/100;
	damage1 = (int)me->query_skill("kongming-quan",1);
	damage2 = (int)me->query_skill("kongming-quan",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	if( me->query_temp("lianzhao")>=1) liannum=me->query_temp("lianzhao");
	else liannum =1;
    if( me->query("neili") < 100 || me->query("jingli") < 100 || damage_bonus < 100 ) return 0;
	if ( me->query_skill("zixia-shengong",1) < 100 || me->query_skill("kongming-quan",1)<100) return 0;
//	if ( me->query_skill_mapped("force") != "yijing-force") return 0;
	if (objectp(me->query_temp("weapon"))) return 0;

	if( random(ap) > dp/3 && me->query("jiali")>0 && random(7)==1) 
	{
		damage = (damage1+damage_bonus)*(liannum+20)/(20*liannum+1);
		victim->receive_damage("qi", damage ,me);
		victim->receive_wound("qi", damage/3 ,me);
		message_vision(HIY"$N双拳空空荡荡，忽明忽暗，$n被一拳击中要害，登时呕出一大口鲜血！\n"NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
		return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiajing")>0 && random(7)==2 && (int)me->query("breakup")>1 )
	{
		damage = (damage2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("jingli",-100);
		victim->receive_damage("jing", damage,me);
		victim->receive_wound("jing", damage/3,me);
		message_vision(HIG "$N顿悟"+me->query("cognize")+HIG"，双手使出不同招式，一虚一实，$n不及换招，被击中$1。\n" NOR, me,victim,damage,HBWHT+HIR"特效伤精"NOR);
		return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiali")>0 && random(7)==3 && (int)me->query("jm/quanzhen") )
	{
		damage = ((damage1+damage2)/2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("neili",-100);
		victim->receive_damage("qi", damage,me);
		victim->receive_wound("qi", damage/3,me);
		if (!victim->is_busy()) victim->start_busy(1);
		message_vision(HIM"$N参悟全真教武功奥秘，内劲柔和绵长，拳力带着气劲，将$n牵引得左摇右晃。\n" NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
		return ;
	}
}



string perform_action_file(string action)
{
	return __DIR__"kongming-quan/" + action;
}
string *parry_msg = ({
        "$n一抖$v，手中的$v化作一条长虹，磕开了$N的$w。\n",
        "$n挥舞$v，手中的$v化做漫天雪影，荡开了$N的$w。\n",
        "$n手中的$v一抖，向$N的手腕削去。\n",
        "$n将手中的$v舞得密不透风，封住了$N的攻势。\n",
        "$n反手挥出$v，整个人消失在一团光芒之中。\n",
});

string *unarmed_parry_msg = ({
        "$n猛击$N的面门，逼得$N中途撤回$w。\n",
        "$n以守为攻，猛击$N的手腕。\n",
        "$n左手轻轻一托$N$w，引偏了$N$w。\n",
        "$n脚走阴阳，攻$N之必救。\n",
        "$n左拳击下，右拳自保，将$N封于尺外。\n",
        "$n双拳齐出，$N的功势入泥牛入海，消失得无影无踪。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}