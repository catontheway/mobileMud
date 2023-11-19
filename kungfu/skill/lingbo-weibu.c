// lingbo-weibu.c
#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
        GRN"$n借力旋转，扶摇而上，衣裾漫天飞舞，潇洒已极！\n"NOR,
        GRN"$n轻轻一跃，如鸟掠长空，凌虚而行，瞬间已在丈外！\n"NOR,
        GRN"$n仿佛站着未动，不过衣角被风轻轻吹了一下，正是“竦轻躯以鹤立，若将飞而未翔”！\n"NOR,
        GRN"$n从容而立，忽焉趋左，忽焉在右，瞻之在前，顾之已后，体迅飞阖,飘忽若瘢\n"NOR,
        GRN"$n长袖飘飘，足不点地，宛如凌风，$N连衣角都没碰着！\n"NOR,
        GRN"$n如风行水上，愈显得雍容高雅，$N不由得自惭形秽，招数一滞！\n"NOR});

int valid_enable(string usage)
{
    return (usage=="dodge");
}

int valid_learn(object me)
{
    mapping fam;
    if ((!(fam = this_player()->query("family"))|| fam["family_name"] != "天龙寺")&&this_player()->query("chushi/last_family")!="天龙寺")
		if (this_player()->query("tqt/old_family1")!="天龙寺")
		{
			if (this_player()->query("tqt/old_family2")!="天龙寺")
			{
				if (this_player()->query("tqt/old_family3")!="天龙寺")
					return notify_fail("你不是天龙寺的弟子，无法学习凌波微步。\n");
			}
		}

    if( me->query_skill("literate",1) < 100 )
        return notify_fail("你的读书识字还不到 100 级，没法领会凌波微步的玄妙之初。\n");
    return 1;
}

string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
    mapping fam;
    if( (int)me->query("qi") < 30 || (int)me->query("jing") < 20 )
        return notify_fail("你的气或神不够，不能练凌波微步。\n");
    me->receive_damage("qi", 30);
    me->receive_damage("jing", 10);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"lingbo-weibu/" + action;
}

int effective_level() { return 10;}

int learn_bonus()
{
    return 10;
}
int practice_bonus()
{
    write("凌波微步靠的是悟性，是实践，光苦练是无济于事的。");
    return 2;
}
int black_white_ness()
{
    return 20;
}
int ob_hit(object ob, object me, int damage)
{

    string msg;
    int j,ap,dp,damage1,damage2;

	ap = (me->query_skill("lingboweibu", 1) + me->query("xyzx_sys/level")) * me->query("int",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	dp = (ob->query_skill("dodge", 1) + ob->query("xyzx_sys/level")) * ob->query("dex",1)*(ob->query("breakup")+ob->query("breakup")*ob->query("breakup")+100)/100;
	damage1 = me->query_skill("lingboweibu", 1);
	damage2 = me->query_skill("lingboweibu", 1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	if( damage < 10 ) damage=10;
	if( me->query("neili") < 100 || me->query("jingli") < 100 ) return damage;
	if (me->query_skill("beiming-shengong",1) < 300 || me->query_skill("lingboweibu", 1) < 300) return damage;
//	if (me->query_skill_mapped("force")!="beiming-shengong" ) return damage;

	if ( random(8) == 1 && random(ap) > dp/4 )
	{
        msg = HIG"$N只是身子一晃一转，蹴的一下转到$n的背后，$n只觉眼前一花，不见了对手的身影！\n"NOR;
		if (!ob->is_busy()) ob->start_busy(1);
		me->add("neili", -100 );
		j = -(damage+random(damage));
		message_vision(msg, me, ob);
		return j;
	}
	if(random(ap) > dp/4 && random(8)==2 && (int)me->query("breakup")>1 )
	{
		j = -(damage+random(damage));
		ob->receive_damage("jing",damage2,me);
		ob->receive_wound("jing",damage2/2,me);
		me->add("jingli", -100 );
		if (!ob->is_busy()) ob->start_busy(1);
		message_vision(HIY"$N顿悟"+me->query("cognize")+HIY"，脚下左一步右一步，$n一招打空，急忙收力，力道反打了回来。\n"NOR, me, ob,damage2,HBWHT+HIY"精神反伤"NOR);
		return j;
	}
	if(random(ap) > dp/4 && random(8)==3 && (int)me->query("jm/xiaoyao") )
	{
		j = -(damage+random(damage));
		ob->receive_damage("qi",damage1,me);
		ob->receive_wound("qi",damage1/2,me);
		me->add("neili", -100 );
		if (!ob->is_busy()) ob->start_busy(1);
		message_vision(HIB"$N领悟逍遥派武功精髓，身随意转，$n招招落在空处，顿时真气紊乱！\n"NOR, me, ob,damage1,HBWHT+HIY"气血反伤"NOR);
		return j;
	}
       
}
