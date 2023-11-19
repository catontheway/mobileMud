// huoyan-dao.c 火焰刀
// by snowman@SJ

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N内息转动，运劲于双臂，全身骨节一阵暴响，起手一式「示诞生」向$n劈出，将$n全身笼罩在赤热的掌风下",
        "skill_name" : "示诞生",
        "force" : 250,
        "lvl" : 0,
        "dodge" : 15,
        "parry": 10,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N面带轻笑，一招「始心镜」，火焰刀内劲由内及外慢慢涌出，$P双掌如宝像合十于胸前，向着$n深深一鞠",
        "skill_name" : "始心镜",
        "force" : 280,
        "lvl" : 20,
        "dodge" : 10, 
        "parry": 5,
        "damage_type" : "震伤",
]),
([      "action" : "$N双掌合十而又打开，这招「现宝莲」以火焰刀无上功力聚出一朵红莲，盛开的花瓣飞舞旋转，漫布在$n四周",
        "skill_name" : "现宝莲",
        "force" : 340,
        "lvl" : 50,
        "dodge" : 5,
        "weapon" : "红莲刀气",
        "damage_type" : "割伤",
]),
([      "action" : "$N面带金刚相，双掌搓圆，使无数炙热的刀气相聚，这招「破法执」犹如一只巨大的手掌，凌空向$n飞抓而下",
        "skill_name" : "破法执",
        "force" : 320,
        "lvl" : 70,
        "dodge" : 10,
        "damage_type" : "内伤",
]),
([      "action" : "$N暴喝一声，竟然使出伏魔无上的「开显圆」，气浪如飓风般围着$P飞旋，炎流将$n一步步向着$P拉扯过来",
        "skill_name" : "开显圆",
        "force" : 400,
        "lvl" : 120,
        "dodge" : -10,
        "damage_type" : "震伤",
]),
([      "action" : "$N口念伏魔真经，双掌连连劈出，将$n笼罩在炙焰之下，这如刀切斧凿般的「显真常」气浪似乎要将$p从中劈开",
        "skill_name" : "显真常",
        "force" : 350,
        "lvl" : 140,
        "dodge" : -5, 
        "weapon" : "无形刀气",
        "damage_type" : "割伤",
]),
([      "action" : "$N现宝相，结迦兰，右手「归真法」单掌拍出，半空中刀气凝结不散，但发出炙灼的气浪却排山倒海般地涌向$n",
        "skill_name" : "归真法",
        "force" : 430,
        "lvl" : 160,
        "dodge" : -15, 
        "parry": 5,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N虚托右掌，一式「吉祥逝」，内力运转，跟着全身衣物无风自动，$P身体微倾，手掌闪电一刀，斩向$n$l",
        "skill_name" : "吉祥逝",
        "force" : 500,
        "lvl" : 180,
        "dodge" : 5, 
        "parry": 10,
        "weapon" : "无形气浪",
        "damage_type" : "割伤",
]),
});

 
int valid_enable(string usage) { return usage == "strike" || usage == "parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练火焰刀必须空手。\n");
        if ((int)me->query("max_neili") < 1500) 
                return notify_fail("以你的内力修为，还不足以练习火焰刀。\n");
        if ((int)me->query_con() < 30) 
                return notify_fail("你的根骨太低，不能驾御火焰刀。\n");
        if ((int)me->query_skill("longxiang-boruo", 1) < 100)
                return notify_fail("火焰刀需要有龙象般若功第一层以上的火候才能学习。\n");
        if ((int)me->query_skill("force") < 100)
                return notify_fail("你的基本内功火候太浅，不能学火焰刀。\n");
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
        level = (int) me->query_skill("huoyan-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练火焰刀必须空手。\n");
        if ((int)me->query("qi") < 50 || (int)me->query("neili") < 20)
                return notify_fail("你的体力不够，练不了火焰刀。\n");
        me->receive_damage("qi", 40);
        me->add("neili",-10);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"huoyan-dao/" + action;
}


int ob_hit(object ob, object me, int damage)
{
	int j, ap,dp,damage1,damage2;
	ap = (int) me->query_skill("huoyan-dao",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	dp = (int) ob->query_skill("unarmed",1)*(ob->query("breakup")+ob->query("breakup")*ob->query("breakup")+100)/100;
	damage1 = me->query_skill("huoyan-dao", 1);
	damage2 = me->query_skill("huoyan-dao", 1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	if (damage <10)  damage=10;
	if( me->query("neili") < 100 || me->query("jingli") < 100 ) return damage;
	if (objectp(me->query_temp("weapon"))) return damage;
	if ( (me->query_skill("longxiang",1) < 100 && me->query_skill("xiaowuxiang",1) < 100) || me->query_skill("huoyan-dao",1) < 300) return damage;
//	if ( me->query_skill_mapped("force") != "longxiang" && me->query_skill_mapped("force") != "xiaowuxiang") return damage;

	if(random(8)==1 && random(ap) > dp/4 )
	{
		j = -(damage+random(damage));
		me->add("neili",-100);
		if (!ob->is_busy()) ob->start_busy(1);
		message_vision(HIR"只听得$N身前嗤嗤声响，“火焰刀”威势大盛，将$n招式上的内力都逼将回来！"NOR, me, ob);
		return j;
	}
	if(random(ap) > dp/4 && random(8)==2 && (int)me->query("breakup")>1 )
	{
		j = -(damage+random(damage));
		ob->receive_damage("jing",damage2,me);
		ob->receive_wound("jing",damage2/2,me);
		me->add("jingli", -100 );
		message_vision(HIY"$N顿悟"+me->query("cognize")+HIY"，手掌扬处，挡住了一些$n攻来的内力，趁势反击。\n"NOR, me, ob,damage2,HBWHT+HIY"精神反伤"NOR);
		return j;
	}
	if(random(ap) > dp/4 && random(8)==3 && (int)me->query("jm/xueshan") )
	{
		j = -(damage/3+random(damage/3));
		ob->receive_damage("qi",damage1,me);
		ob->receive_wound("qi",damage1/2,me);
		me->add("neili", -100 );
		message_vision(HIB"$N融汇雪山寺绝技，展开火焰刀法，封住了一些$n的攻击！\n"NOR, me, ob,damage1,HBWHT+HIY"气血反伤"NOR);
		return j;
	}	
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int ap,dp,damage1,damage2,damage,liannum;
	int flag = 1;
	damage1 = (int)me->query_skill("huoyan-dao",1);
	damage2 = (int)me->query_skill("huoyan-dao",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	ap = me->query_skill("huoyan-dao",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	dp = victim->query_skill("force",1)*(victim->query("breakup")+victim->query("breakup")*victim->query("breakup")+100)/100;
	if( me->query_temp("lianzhao")>=1) liannum=me->query_temp("lianzhao");
	else liannum =1;
    if( me->query("neili") < 100 || me->query("jingli") < 100 || damage_bonus < 100 ) return 0;
	if (objectp(me->query_temp("weapon"))) return 0;
	if ( (me->query_skill("longxiang",1) < 100 && me->query_skill("xiaowuxiang",1) < 100) || me->query_skill("huoyan-dao",1) < 100) return 0;
//	if ( me->query_skill_mapped("force") != "longxiang" && me->query_skill_mapped("force") != "xiaowuxiang") return 0;
	if (me->query_skill_mapped("force") == "longxiang") flag=1;
	if (me->query_skill_mapped("force") == "xiaowuxiang") flag=2;
	if( random(ap) > dp/3 && random(7)==1 && me->query("jiali")>0 )
	{
		damage = (damage1+damage_bonus)*(liannum+20)/(20*liannum+1);
		victim->receive_damage("qi", damage ,me);
		victim->receive_wound("qi", damage/3 ,me);
		me->add("neili",-100);
		message_vision(HIM "$n被掌风扫中，感觉伤口烧了起来，红红的一片！\n" NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
		return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiajing")>0 && random(7)==2 && (int)me->query("breakup")>1 )
	{
		damage = (damage2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("jingli",-100);
		victim->receive_damage("jing", damage,me);
		victim->receive_wound("jing", damage/3,me);
		message_vision(HIG "$N发挥出"+me->query("cognize")+HIG"的力量，双掌通红，拍向$n，$n只觉得如被火烧。\n" NOR, me,victim,damage,HBWHT+HIR"特效伤精"NOR);
		return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiali")>0 && random(7)==3 && (int)me->query("jm/xueshan") )
	{
		damage = ((damage1+damage2)/2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("neili",-100);
		victim->receive_damage("qi", damage,me);
		victim->receive_wound("qi", damage/3,me);
		message_vision(HIC "$N融汇雪山寺武学，掌心凝聚一团火焰，掌未到，火焰的热力已至。\n" NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
		return ;
	}
}

int help(object me)
{
        write(HIR"\n大轮寺绝技「火焰刀」："NOR"\n");
        write(@HELP
        
        要求：  最大内力 1500 以上；
                后天根骨 30 以上；
                龙象般若功等级 100 以上；
                内功等级 100 以上。     
HELP
        );
        return 1;
}

