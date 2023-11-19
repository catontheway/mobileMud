// xiaoyaoyou.c
// written by Xiang
#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
	"$n一个「蜻蜓点水」，躲过了$N这一招。\n",
	"$n身形向后一纵，使出一招「细胸巧翻云」，避过了$N的攻击。\n",
	"$n使出「虚怀若谷」，恰好躲过了$N的攻势。\n"
//        "但是$n身形飘忽，轻轻一纵，早已避开。\n",
//        "$n身随意转，倏地往一旁挪开了三尺，避过了这一招。\n",
//        "可是$n侧身一让，$N这一招扑了个空。\n",
//        "却见$n足不点地，往旁窜开数尺，躲了开去。\n",
//        "$n身形微晃，有惊无险地避开了$N这一招。\n"
});

int valid_enable(string usage) 
{ 
	return (usage == "dodge") || (usage == "move"); 
}

int valid_learn(object me) { return 1; }
string query_dodge_msg(string limb)
{

        return dodge_msg[random(sizeof(dodge_msg))];
}
string perform_action_file(string action)
{
        return __DIR__"xiaoyaoyou/" + action;
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("你的体力太差了，不能练逍遥游。\n");
        me->receive_damage("qi", 30);
        return 1;
}

int ob_hit(object ob, object me, int damage)
{
	string msg;
	int ap,dp,j,damage1,damage2;

	ap = me->query_skill("xiaoyaoyou", 1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	dp = ob->query_skill("sword",1)*(ob->query("breakup")+ob->query("breakup")*ob->query("breakup")+100)/100;
	damage1 = me->query_skill("xiaoyaoyou", 1);
	damage2 = me->query_skill("xiaoyaoyou", 1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	if( damage < 10 ) damage=10;
	if( me->query("neili") < 100 || me->query("jingli") < 100 ) return damage;
	if (me->query_skill("huntian-qigong",1) < 300 || me->query_skill("xiaoyaoyou", 1) < 300) return damage;
//	if (me->query_skill_mapped("force")!="huntian-qigong" ) return damage;

	if ( random(8) == 1 && random(ap) > dp/4 )
	{
        msg = HIG"$N顿悟逍遥意境，将逍遥二字发挥的淋漓尽致，身形变的不可捉摸。\n"NOR;
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
		message_vision(HIY"$N顿悟"+me->query("cognize")+HIY"，$n被$N的随心所欲的身法惊呆了！一时不慎，被反击一招。\n"NOR, me, ob,damage2,HBWHT+HIY"精神反伤"NOR);
		return j;
	}
	if(random(ap) > dp/4 && random(8)==3 && (int)me->query("jm/gaibang") )
	{
		j = -(damage/3+random(damage/3));
		ob->receive_damage("qi",damage1,me);
		ob->receive_wound("qi",damage1/2,me);
		me->add("neili", -100 );
		message_vision(HIB"$N融汇丐帮武学精髓，身如乞丐，心却逍遥！满场游走，带动$n露出破绽，趁势而入。\n"NOR, me, ob,damage1,HBWHT+HIY"气血反伤"NOR);
		return j;
	}
}
