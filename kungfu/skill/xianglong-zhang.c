// xianglong-zhang.c 降龙十八掌		上乘武学400~1000
// modified by Venus Oct.1997
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
string *parry_msg = ({
	"$p不待回身，半招「神龙摆尾」，做势反劈。$P见这招势凶狠，不敢硬接，纵身避开。\n",
	"只见$p左掌圆劲，右掌直推，挡在身前。一招纯是防御，却是在双方之间布了一道坚壁。\n",
	"$p当下不敢怠慢，双掌当胸平推，将自己全身笼罩在掌力之下。守得稳若渊停岳峙，直无半点破绽。\n",
});
string query_parry_msg(object weapon, object victim) 
{ 
//   object me = victim->select_opponent();          	
	object me;          		

	if (me && victim && victim!=me)
	{
		if ( victim->query_temp("weapon") || victim->query_skill("xianglong-zhang", 1) < 100 || victim->query_skill_prepared("unarmed") != "xianglong-zhang" )	
			return SKILL_D("parry")->query_parry_msg(weapon);
		else 
		{     	
			string *slbw = ({
                "$n更不回身，右手一招「神龙摆尾」向后挥去，这是降龙十八掌中的救命绝招，$p在情急之下使将出来，更是威力倍增！！\n",
                "$n避让不及，不待回身，一招「神龙摆尾」，反手向$P还劈一掌！\n",
                "就在这一瞬之间，$p急忙转身，同时一招「神龙摆尾」向$P反手横劈！\n",
				});
			message_vision(YEL"\n"+slbw[random(sizeof(slbw))]+""NOR,me,victim);
			return COMBAT_D->do_attack(victim, me, me->query_temp("weapon")) + "";
		}
	}
}


mapping *action = ({
([      "action": "$N突然身形加快，双掌平平推向$n的$l",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,	
    "damage_type": "瘀伤"
]),
([      "action": "$N突然身形飞起，双掌居高临下一招"+(order[random(13)])+"「飞龙在天」"NOR"拍向$n的$l",     
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,	
    "damage_type": "瘀伤"
]),
([      "action": "$N右掌一招"+(order[random(13)])+"「见龙在田」"NOR"，迅捷无比地劈向$n的$l",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,	
    "damage_type": "瘀伤"
]),
([      "action": "$N双掌施出一招"+(order[random(13)])+"「鸿渐于陆」"NOR"，隐隐带着风声拍向$n的$l",
		"attack":	500,
		"parry":	500,
		"dodge":	500,
		"damage":	500,
		"force":	500,
    "damage_type": "瘀伤"
]),
([      "action": "$N左掌聚成拳状，右掌一招"+(order[random(13)])+"「潜龙勿用」"NOR"缓缓推向$n的$l",
		"attack":	500,
		"parry":	500,
		"dodge":	500,
		"damage":	500,
		"force":	500,
    "damage_type": "瘀伤"
]),
([      "action": "$N施出一招"+(order[random(13)])+"「利涉大川」"NOR"，右掌插腰，左掌劈向$n的$l",
		"attack":	500,
		"parry":	500,
		"dodge":	500,
		"damage":	500,
		"force":	500,
    "damage_type": "瘀伤"
]),
([      "action": "$N使出"+(order[random(13)])+"「突如其来」"NOR"，右掌从不可能的角度向$n的$l推出",
		"attack":	500,
		"parry":	500,
		"dodge":	500,
		"damage":	500,
		"force":	500,
    "damage_type": "瘀伤"
]),
([      "action": "$N大吼一声，双掌使出"+(order[random(13)])+"「震惊百里」"NOR"，不顾一切般击向$n",
		"attack":	600,
		"parry":	600,
		"dodge":	600,
		"damage":	600,
		"force":	600,	
    "damage_type": "瘀伤"
]),
([      "action": "$N使出"+(order[random(13)])+"「或跃在渊」"NOR"，向$n的$l连拍数掌",
		"attack":	600,
		"parry":	600,
		"dodge":	600,
		"damage":	600,
		"force":	600,	
    "damage_type": "瘀伤"
]),
([      "action": "$N身形滑动，双掌使一招"+(order[random(13)])+"「双龙取水」"NOR"一前一后按向$n的$l",
		"attack":	600,
		"parry":	600,
		"dodge":	600,
		"damage":	600,
		"force":	600,	
    "damage_type": "瘀伤"
]),
([      "action": "$N使出"+(order[random(13)])+"「鱼跃于渊」"NOR"，身形飞起，双掌并在一起向$n的$l劈下",     
		"attack":	600,
		"parry":	600,
		"dodge":	600,
		"damage":	600,
		"force":	600,	
    "damage_type": "瘀伤"
]),
([      "action": "$N双掌立起，使出"+(order[random(13)])+"「时乘六龙」"NOR"向$n连砍六下",
		"attack":	600,
		"parry":	600,
		"dodge":	600,
		"damage":	600,
		"force":	600,	
    "damage_type": "瘀伤"
]),
([      "action": "$N使出"+(order[random(13)])+"「密云不雨」"NOR"，左掌封住$n的退路，右掌斜斜地劈向$l",     
		"attack":	700,
		"parry":	700,
		"dodge":	700,
		"damage":	700,
		"force":	700,
    "damage_type": "瘀伤"
]),
([      "action": "$N使出"+(order[random(13)])+"「损则有孚」"NOR"，双掌软绵绵地拍向$n的$l",
		"attack":	700,
		"parry":	700,
		"dodge":	700,
		"damage":	700,
		"force":	700,
    "damage_type": "瘀伤"
]),
([      "action": "$N脚下一转，突然欺到$n身前，一招"+(order[random(13)])+"「龙战于野」"NOR"拍向$n的$l",     
		"attack":	800,
		"parry":	800,
		"dodge":	800,
		"damage":	800,
		"force":	800,
    "damage_type": "瘀伤"
]),
([      "action": "$N门户大开，一招"+(order[random(13)])+"「履霜冰至」"NOR"向$n的$l劈去",
		"attack":	800,
		"parry":	800,
		"dodge":	800,
		"damage":	800,
		"force":	800,
    "damage_type": "瘀伤"
]),
([      "action": "$N使出"+(order[random(13)])+"「羝羊触蕃」"NOR"，双掌由下往上击向$n的$l",
		"attack":	900,
		"parry":	900,
		"dodge":	900,
		"damage":	900,
		"force":	900,
    "damage_type": "瘀伤"
]),
([      "action": "$N左掌护胸，右掌使一招"+(order[random(13)])+"「神龙摆尾」"NOR"上下晃动着击向$n的$l",     
		"attack":	1000,
		"parry":	1000,
		"dodge":	1000,
		"damage":	1000,
		"force":	1000,
    "damage_type": "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }  
//2019-1-1阿飞新规划，技能代码完善
//string valid_combine() { return "juehu-shou"; }		//互备技能
string skill_pinji() {return "上乘";}				//品级区分：上乘、中乘、下乘
string skill_xingbie() {return "男性";}				//性别区分：男性、女性、无性、通用
string skill_zhengxie() {return "中立";}			//正邪区分：正道、邪道、中立
string skill_menpai() {return "丐帮";}				//门派区分：门派，江湖
string skill_yinyang() {return "阳";}				//阴阳区分：阳、阴、中性
string skill_zhenying() {return "正派";}			//阵营区分：正派、邪派、中立、通用
int damage_damage() {return 87;}	//外伤系数
int force_damage() {return 59;}		//内伤系数
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
		return notify_fail("练降龙十八掌必须空手。\n");
	if (me->query("family/family_name")!="丐帮")
		return notify_fail("你不是乞丐，学不了丐帮镇帮绝技。\n");
	
	if ( me->query("gender") != "男性" )
		return notify_fail("降龙十八掌这种刚猛的武功不是女人能学得了的！\n");
	if ( me->query("str") < 30 )
		return notify_fail("降龙十八掌这种刚猛的武功不是细胳膊细腿能学得了的！\n");
	if ((int)me->query_skill("huntian-qigong", 1) < 30)	
		return notify_fail("你的混天气功火候不够，无法练降龙十八掌。\n");
	if ((int)me->query_skill("xianglong-zhang", 1) > (int)me->query_skill("strike", 1))
		return notify_fail("你的掌法基础太差劲了。\n");	
	if ((int)me->query_skill("xianglong-zhang", 1) > 3000)
		return notify_fail("上乘武学只能教到这里了，以后要靠自己勤加修习领悟。\n");	
	if ((int)me->query("max_neili") < 1000)
		return notify_fail("你的内力太弱，无法练降龙十八掌。\n");
	if ((int)me->query("score",1) < 200)
		return notify_fail("你对我派毫无贡献而言，怎么可能传授你武功呢。\n");
	
	if (random(10)==1) me->add("score",-10);
    return 1;
}

int practice_skill(object me)
{ 
//	if (!wizardp(me))
//		return ("巫师突然从黑暗中冲了出来，对你大吼一声：该门派没开放。\n");	
	if (me->query("family/family_name")!="丐帮")
		return notify_fail("你不是乞丐，偷学丐帮镇帮绝技，作死吗！！。\n");
	
	if ( me->query("gender") != "男性" )
		return notify_fail("降龙十八掌这种刚猛的武功不是女人能学得了的！\n");
	
	if ((int)me->query("qi") < 40)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("你的内力不够练降龙十八掌。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -5);
	return 1;
}
mapping query_action(object me, object weapon)
{
	int x = 1 + random(8);
	int y = 3 + random(10);
	string *sanhui_msg = 
	({
		HIW"$N大步迈出，左手一划，右掌呼的一声，便向$n击去，正是一招「亢龙有悔」，力自掌生，猛不可当"NOR,
		HIM"$N一掌既出，身子抢前，又是一招「亢龙有悔」，後掌推前掌，双掌力道并在一起，排山倒海的压将过来"NOR,
		HIG"$N跟着又是一招「亢龙有悔」，前招掌力相消，次招掌力又至。竟如怒涛狂涌，势不可挡，又如一堵无形的高墙，向$n身前疾冲"NOR,
	});

	if ( me->query_skill_mapped("force") == "huntian-qigong" && me->query("jiali")>100 )
	{
		if ( random(me->query_skill("xianglong-zhang")) > 600 && random(20)>15 && me->query_temp("powerup") && me->query("neili") > 1000  )
		{
			me->add("neili", -100);
			return ([
			"action": HIY"$N一招「亢龙有悔」，平推出去。初推出去看似轻描淡写，但一遇阻力，刹时之间连加"+ chinese_number(y) +"道後劲，一道强似一道，重重叠叠，直至无坚不摧，无强不破"NOR,
			"attack":	1000,
			"parry":	1000,
			"dodge":	1000,
			"damage":	1000,
			"force":	1000,
			"damage_type": random(2)?"内伤":"瘀伤" ]);
		}
		if ( random(me->query_skill("xianglong-zhang")) > 500 && random(15)==1 && me->query_temp("powerup") && me->query("neili") > 500)
		{
			me->add("neili", -100);
			return ([
			"action": YEL"$N踏上两步，呼的一声，一招「亢龙有悔」当胸击去。这一掌"+ chinese_number(x) +"分发，"+ chinese_number(10-x) +"分收，劲道去而复回，实是非同小可"NOR,
			"attack":	1000,
			"parry":	1000,
			"dodge":	1000,
			"damage":	1000,
			"force":	1000,
			"damage_type": random(2)?"内伤":"瘀伤" ]);
		}
		if (random(me->query_skill("xianglong-zhang",1)) > 400 && random(15)==2 && me->query_temp("powerup") && me->query("neili") > 500)
		{
			me->add("neili", -100);
			return ([
			"action": HIY"$N左腿微屈，右臂内弯，右掌划了个圆圈，呼的一声向外急推，凌厉无比，正是威力最强的"+(order[random(13)])+"「亢龙有悔」"NOR""NOR,
			"attack":	900,
			"parry":	900,
			"dodge":	900,
			"damage":	900,
			"force":	900,
			"damage_type": "瘀伤"]);
		}
		if (random(me->query_skill("xianglong-zhang",1)) > 300 && random(15)==3 && me->query_temp("powerup") && me->query("neili") > 500)
		{
			me->add("neili", -100);
			return ([
			"action": HIC"$N眼见$n招数凶猛。避让不及，急忙转身，同时反手猛劈，正是降龙掌的救命绝招"+(order[random(13)])+"「神龙摆尾」"NOR""NOR,
			"attack":	900,
			"parry":	900,
			"dodge":	900,
			"damage":	900,
			"force":	900,
			"damage_type": "瘀伤"]);
		}
		if ( random(me->query_skill("xianglong-zhang")) > 300 && random(15)==4 && me->query("neili") > 1000  )
		{
			return ([
			"action": sanhui_msg[random(3)],
			"attack":	800,
			"parry":	800,
			"dodge":	800,
			"damage":	800,
			"force":	800,
			"damage_type": random(2)?"内伤":"瘀伤" ]);
		}
	}

	return action[random(sizeof(action))];
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{
	int ap,dp, damage1,damage2,damage,liannum;

    ap = me->query_skill("xianglong-zhang",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	dp = victim->query_skill("parry",1)*(victim->query("breakup")+victim->query("breakup")*victim->query("breakup")+100)/100;
    damage1= (int) me->query_skill("xianglong-zhang",1);
	damage2 = (int)me->query_skill("xianglong-zhang",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	if( me->query_temp("lianzhao")>=1) liannum=me->query_temp("lianzhao");
	else liannum =1;
	if( me->query("neili") < 100 || me->query("jingli") < 100 || damage_bonus < 100 ) return 0;
	if ( me->query_skill("huntian-qigong",1) < 100 || me->query_skill("xianglong-zhang",1)<100) return 0;
//	if ( me->query_skill_mapped("force") != "huntian-qigong") return 0;
	if (objectp(me->query_temp("weapon")) ) return 0;

	if (random(7)==1 && random(ap) > dp/3 && me->query("jiali") > 0)
	{
		damage = (damage1+damage_bonus)*(liannum+20)/(20*liannum+1);
		victim->receive_damage("qi", damage ,me);
		victim->receive_wound("qi", damage/3 ,me);
		me->add("neili", -100);
		message_vision(HIR "只听$n" HIR "前胸「咔嚓」一声脆响，竟像是肋骨断折的声音。\n" NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
        return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiajing")>0 && random(7)==2 && (int)me->query("breakup")>1 )
	{
		damage = (damage2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("jingli",-100);
		victim->receive_damage("jing", damage,me);
		victim->receive_wound("jing", damage/3,me);
		message_vision(HIG "$N顿悟"+me->query("cognize")+HIG"，双掌划了个圆圈，缓缓的向外推出，正是最刚猛的"+(order[random(13)])+"「降龙无悔」。$n一声惨叫，胸前「咔嚓咔嚓」几声脆响。\n" NOR, me,victim,damage,HBWHT+HIR"特效伤精"NOR);
		return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiali")>0 && random(7)==3 && (int)me->query("jm/gaibang") )
	{
		damage = ((damage1+damage2)/2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("neili",-100);
		victim->receive_damage("qi", damage,me);
		victim->receive_wound("qi", damage/3,me);
		message_vision(HIM"$N融汇丐帮武学精髓，后退一步，随即跃起，双掌盘旋而上，正是威力最强的"+(order[random(13)])+"「飞龙在天」，$n一声惨叫，口中鲜血狂喷。\n" NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
		return ;
	}
}

//2017.3.25阿飞封掉ob_hit特效，怀疑与伤害为0的死亡有关
int ob_hit(object ob, object me, int damage)
{
	string msg;
	int ap,dp,j,damage1,damage2;

	ap = me->query_skill("xianglong-zhang", 1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	dp = ob->query_skill("sword",1)*(ob->query("breakup")+ob->query("breakup")*ob->query("breakup")+100)/100;
	damage1 = me->query_skill("xianglong-zhang", 1);
	damage2 = me->query_skill("xianglong-zhang", 1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	if( damage < 10 ) damage=10;
	if( me->query("neili") < 100 || me->query("jingli") < 100 ) return damage;
	if (objectp(me->query_temp("weapon")) ) return damage;
	if (me->query_skill("huntian-qigong",1) < 300 || me->query_skill("xianglong-zhang", 1) < 300) return damage;
//	if (me->query_skill_mapped("force")!="huntian-qigong" ) return damage;

	if ( random(8) == 1 && random(ap) > dp/4 )
	{
        msg = HIC"$N硬接了$n这一招，反手一式「亢龙有悔」，将对方打的后退三步！\n" NOR;
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
		message_vision(HIY"$N顿悟"+me->query("cognize")+HIY"，物极必反，亢必有悔。以极阳之势，待强弩之末，有悔得吉，彼吝得凶。\n"NOR, me, ob,damage2,HBWHT+HIY"精神反伤"NOR);
		return j;
	}
	if(random(ap) > dp/4 && random(8)==3 && (int)me->query("jm/gaibang") )
	{
		j = -(damage/3+random(damage/3));
		ob->receive_damage("qi",damage1,me);
		ob->receive_wound("qi",damage1/2,me);
		COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 1);
		me->add("neili", -100 );
		if (!ob->is_busy()) ob->start_busy(1);
		message_vision(HIB"$N融汇丐帮武学精髓，但见$N硬接了$n这一招，右掌紧接着向后一摆，一招「神龙摆尾」出其不意地按在了$n的$l上！\n"NOR, me, ob,damage1,HBWHT+HIY"气血反伤"NOR);
		return j;
	}
}


string perform_action_file(string action)
{
    return __DIR__"xianglong-zhang/" + action;
}

