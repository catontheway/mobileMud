// chanchu_bufa.c 蟾蜍步法
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit SKILL;
string *dodge_msg = ({
    "只见$n一招「"+RED+"蟾飞九天"+NOR+"」，身体向上笔直地纵起丈余，躲过了$N这一招。\n",
    "但是$n一个使出「"+WHT+"蛙鸣震天"+NOR+"」，身形飘忽，轻轻一纵，早已避开。\n",
     "$n一招「"+CYN+"蛙入稻田"+NOR+"」，身行随意转，倏地往一旁挪开了三尺，避过了这一招。\n",
    "可是$n一个「"+YEL+"蟾蜍扑虫"+NOR+"」，侧身一让，$N这一招扑了个空。\n",
    "却见$n「"+RED+"蟾翻白肚"+NOR+"」，足不点地，往旁窜开数尺，躲了开去。\n",
    "$n身形一招「"+GRN+"金蟾归月"+NOR+"」，身形微晃，有惊无险地避开了$N这一招。\n"
});
int valid_enable(string usage) { return (usage == "dodge");  }
//2019-1-1阿飞新规划，技能代码完善
//string valid_combine() { return "juehu-shou"; }		//互备技能
string skill_pinji() {return "下乘";}				//品级区分：上乘、中乘、下乘
string skill_xingbie() {return "男性";}				//性别区分：男性、女性、无性、通用
string skill_zhengxie() {return "中立";}			//正邪区分：正道、邪道、中立
string skill_menpai() {return "白驼山派";}				//门派区分：门派，江湖
string skill_yinyang() {return "中性";}				//阴阳区分：阳、阴、中性
string skill_zhenying() {return "邪派";}			//阵营区分：正派、邪派、中立、通用
//int damage_damage() {return 60;}	//外伤系数
//int force_damage() {return 60;}		//内伤系数
//int qi_heal() {return 50;}		//内功疗气系数
//int jing_heal() {return 50;}		//内功疗精系数
int practice_level() {return 100;}	//自练级别
int practice_add() {return 100;}	//自练效率
int perform_level() {return 300;}	//PFM最低使用级别

int valid_learn(object me)
{
//	if (!wizardp(me))
//		return ("巫师突然从黑暗中冲了出来，对你大吼一声：该门派没开放。\n");	

	if ((int)me->query_skill("hamagong", 1) < 30)
		return notify_fail("你的蛤蟆功太差了，没法学习蟾蜍步法。\n");
    if (me->query_skill("dodge",1) <= me->query_skill("chanchu-bufa",1) )
        return notify_fail("你的基本轻功基础不够，无法领会更高深的蟾蜍步法。\n");
	if ( me->query("gender") != "男性" )
		return notify_fail("没听说有女人会练习这么难看的身法啊？\n");	

	return 1;
}

string query_dodge_msg(string limb,object me)
{
   // me->set_temp("apply/dodge",me->query_skill("chanchu-bufa")/3);
    return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{ 
//	if (!wizardp(me))
//		return ("巫师突然从黑暗中冲了出来，对你大吼一声：该门派没开放。\n");	 

    if( (int)me->query("qi") < 45 )
		return notify_fail("你的体力太差了，不能练蟾蜍步法。\n");
	if ( me->query("gender") != "男性" )
		return notify_fail("没听说有女人会练习这么难看的身法啊？\n");

    me->receive_damage("qi", 35);
    return 1;
}

	//2017.3.25阿飞封掉ob_hit特效，怀疑与伤害为0的死亡bug有关
int ob_hit(object ob, object me, int damage)
{	
	int j,ap,dp,damage1,damage2;
	ap = (me->query_skill("hamagong",1) + me->query_skill("chanchu-bufa"))*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;;
	dp = ob->query_skill("dodge")*(ob->query("breakup")+ob->query("breakup")*ob->query("breakup")+100)/100;
	damage1 = (int)me->query_skill("hamagong",1) + me->query_skill("chanchu-bufa",1);
	damage2 = (int)me->query_skill("hamagong",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	if (damage <10)  damage=10;
	if( me->query("neili") < 100 || me->query("jingli") < 100 ) return damage;
	if (me->query_skill("hamagong",1) < 300 || me->query_skill("chanchu-bufa", 1) < 300) return damage;
//	if (me->query_skill_mapped("force")!="hamagong" ) return damage;

	if (me->is_busy() && random(6)==0 && me->query_skill_mapped("force")=="hamagong" )
	{
		j = -(damage/3+random(damage/3));
		me->start_busy(1);
		me->add("neili", -100 );		
		message_vision(HIC"$N逆转经脉，真气逆运三重天，堵塞的穴位一气贯通!\n"NOR, me, ob);
		return j;
	}
	if (random(ap) > dp/4 && random(8)==1 )
	{  
		me->add("neili", -100 );	
		j = -(damage/3+random(damage/3));
		if (!ob->is_busy()) ob->start_busy(2);
		message_vision(HIR "$n只觉眼前一花，一个黑糊糊的癞蛤蟆向你扑了过来，吓的不敢动弹！\n" NOR,me,ob);
		return j;
	} 
	if(random(ap) > dp/4 && random(8)==2 && (int)me->query("breakup") )
	{
		j = -(damage+random(damage));
		ob->receive_damage("jing",damage2,me);
		ob->receive_wound("jing",damage2/2,me);
		me->add("jingli", -100 );
		message_vision(HIG"$N癞蛤蟆吃天鹅肉，脚下"+me->query("cognize")+HIG"的力量爆发，一跃而起，将$n扑倒在地！\n"NOR, me, ob,damage2,HBWHT+HIY"精神反伤"NOR);		
		return j;
	}
	if(random(ap) > dp/4 && random(8)==3 && (int)me->query("jm/baituo") )
	{
		j = -(damage+random(damage));
		ob->receive_damage("qi",damage1,me);
		ob->receive_wound("qi",damage1/2,me);
		me->add("neili", -100 );
		message_vision(HIG"$N贯通白驼山武功精髓，逆转经脉，双掌撑地，一下跳到$n的背后！\n"NOR, me, ob,damage1,HBWHT+HIY"气血反伤"NOR);
		return j;
	}			      
}