// dagou-bang.c 打狗棒法	中乘武学200~600

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h"
inherit SKILL;

string *order = ( {""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
string *xue_name = (
{
	"强间穴","风府穴","大雅穴","灵台穴","悬枢穴",
});

mapping *action = ({
([  "action": "$N使出一招「"+BLK+"挑字诀：棒挑癞犬"+NOR+"」，手中$w化作两道青光砸向$n的$l",
	"attack":	200,
	"parry":	200,
	"dodge":	200,
	"damage":	200,
	"force":	200,
    "lvl" : 1,
    "damage_type": "挫伤"
]),
([  "action": "$N手中$w左右晃动，一招「"+RED+"封字决：饿狗拦路"+NOR+"」向$n的$l攻去",
	"attack":	300,
	"parry":	300,
	"dodge":	300,
	"damage":	300,
	"force":	300,
    "lvl" : 33,
    "damage_type": "挫伤"
]),
([  "action": "$N举起$w，居高临下使一招「"+GRN+"转字决：丧家之犬"+NOR+"」敲向$n的$l",
	"attack":	400,
	"parry":	400,
	"dodge":	400,
	"damage":	400,
	"force":	400,
    "lvl" : 66,
    "damage_type": "挫伤"
]),
([  "action": "$N施出「"+YEL+"绊字诀：拨狗朝天"+NOR+"」，$w由下往上向$n撩去",
	"attack":	300,
	"parry":	300,
	"dodge":	300,
	"damage":	300,
	"force":	300,
    "lvl" : 100,
    "damage_type": "挫伤"
]),
([  "action": "$N施出「"+HIW+"引字诀：引狗入寨"+NOR+"」，$w由下往上向$n撩去",
	"attack":	200,
	"parry":	200,
	"dodge":	200,
	"damage":	200,
	"force":	200,
    "lvl" : 100,
    "damage_type": "挫伤"
]),
([  "action": "$N施出「"+HIB+"戳字诀：狗急跳墙"+NOR+"」，$w由下往上向$n撩去",
	"attack":	400,
	"parry":	400,
	"dodge":	400,
	"damage":	400,
	"force":	400,
    "lvl" : 100,
    "damage_type": "挫伤"
]),
([  "action": "$N施出「"+HIG+"缠字诀：棒打双犬"+NOR+"」，$w由下往上向$n撩去",
	"attack":	300,
	"parry":	300,
	"dodge":	300,
	"damage":	300,
	"force":	300,
    "lvl" : 100,
    "damage_type": "挫伤"
]),
([  "action": "$N施出「"+HIC+"劈字诀：棒打狗头"+NOR+"」，$w由下往上向$n撩去",
	"attack":	500,
	"parry":	500,
	"dodge":	500,
	"damage":	500,
	"force":	500,
    "lvl" : 100,
    "damage_type": "挫伤"
]),
});


int valid_enable(string usage)
{
	return (usage == "staff") ||(usage == "club") || (usage == "parry");
}
//2019-1-1阿飞新规划，技能代码完善
//string valid_combine() { return "juehu-shou"; }		//互备技能
string skill_pinji() {return "中乘";}				//品级区分：上乘、中乘、下乘
string skill_xingbie() {return "通用";}				//性别区分：男性、女性、无性、通用
string skill_zhengxie() {return "正道";}			//正邪区分：正道、邪道、中立
string skill_menpai() {return "丐帮";}				//门派区分：门派，江湖
string skill_yinyang() {return "中性";}				//阴阳区分：阳、阴、中性
string skill_zhenying() {return "正派";}			//阵营区分：正派、邪派、中立、通用
int damage_damage() {return 62;}	//外伤系数
int force_damage() {return 54;}		//内伤系数
//int qi_heal() {return 50;}		//内功疗气系数
//int jing_heal() {return 50;}		//内功疗精系数
int practice_level() {return 100;}	//自练级别
int practice_add() {return 100;}	//自练效率
int perform_level() {return 300;}	//PFM最低使用级别

int valid_learn(object me)
{
//	if (!wizardp(me))
//		return ("巫师突然从黑暗中冲了出来，对你大吼一声：该门派没开放。\n");		
	if ((int)me->query("max_neili") < 200)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query("int",1) < 25)
		return notify_fail("打狗棒法需要聪慧之人才能学习。\n");
	if ((int)me->query_skill("huntian-qigong",1) < 30 )
		return notify_fail("你的内功修为不够,无法领悟打狗棒法的精要。\n");
    if (me->query("family/family_name")!="丐帮")
		return notify_fail("这是丐帮镇帮绝技，不加入丐帮是没法学习的。\n");
	
	if (me->query_skill("staff", 1) <=me->query_skill("dagou-bang", 1))
		return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
	if ((int)me->query("score",1) < 200)
		return notify_fail("你对我派毫无贡献而言，怎么可能传授你武功呢。\n");
	
	if (random(100)==1) me->add("score",-5);
	return 1;
}

mapping query_action(object me, object weapon)
{

	if ( random(20) > 15
	&& (int)me->query_skill("club", 1) >= 500 
	&& (int)me->query_skill("dagou-bang", 1) >= 500 
	&& (int)me->query_skill("force",1) >= 500 
	&& (int)me->query("neili") >= 500  )
	{
		me->add("neili", -50);
		return ([
            "action": HIG"$N眼中射出一道青芒，手中$w使出"RED""+(order[random(13)])+"「天下无狗」"NOR""HIG"，劈天盖地般攻向$n"NOR,
			"attack":	600,
			"parry":	600,
			"dodge":	600,
			"damage":	600,
			"force":	600,
            "damage_type": "内伤"]);
	}
	
	return action[random(sizeof(action))];	//2017.9.4阿飞改，将招式简单点
}

int practice_skill(object me)
{
	object weapon;
//	if (!wizardp(me))
//		return ("巫师突然从黑暗中冲了出来，对你大吼一声：该门派没开放。\n");	
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "club")
		return notify_fail("你使用的武器不对。\n");
    if (me->query("family/family_name")!="丐帮")
		return notify_fail("不加入丐帮偷练丐帮的镇帮绝技，要是被洪老帮主发现就死定了。\n");
	
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练打狗棒法。\n");
	if (me->query_skill("club", 1) <= me->query_skill("dagou-bang", 1))
		return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
	
	me->receive_damage("qi", 40);

	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"dagou-bang/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	string xname;
	int ap,dp,damage1,damage2,damage,liannum;
	object weapon1, weapon2;
	xname = xue_name[random(sizeof(xue_name))];
	weapon1 = me->query_temp("weapon");
	weapon2 = victim->query_temp("weapon");
	ap = me->query_skill("dagou-bang", 1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	dp = victim->query_skill("parry", 1)*(victim->query("breakup")+victim->query("breakup")*victim->query("breakup")+100)/100;
	damage1 = (int)me->query_skill("dagou-bang",1) + (int)me->query_skill("begging", 1)/3;
	damage2 = ((int)me->query_skill("dagou-bang",1) + (int)me->query_skill("begging", 1)/3)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	if( me->query_temp("lianzhao")>=1) liannum=me->query_temp("lianzhao");
	else liannum =1;
    if ( me->query("neili") < 100 || me->query("jingli") < 100 || damage_bonus < 100) return 0;
	if ( me->query_skill("huntian-qigong",1) < 300 || me->query_skill("dagou-bang",1) < 300)	 return 0;
//	if ( me->query_skill_mapped("force") != "huntian-qigong") return 0;	
	if (!objectp(weapon1 = me->query_temp("weapon")) || (string)weapon1->query("skill_type") != "club") return 0;

	if (random(7)==0 && me->query("jiali") > 0 && random(ap)>dp/3 )
	{
		damage = (damage1+damage_bonus)*(liannum+20)/(20*liannum+1);
		if (objectp(weapon2=victim->query_temp("weapon")))
		{
			weapon2->unequip();
			weapon2->move(environment(victim));
			me->add("neili", -100 );
			return HIG"$N"+weapon1->name()+HIG"疾翻，搭在"+weapon2->name()+HIG"尺许之处，运起“引”字诀，顺势向外牵引！\n"HIR"$n只感"+weapon2->name()+HIG"似欲脱手飞出，一个把握不住，手中兵器掉在地上。\n"NOR;
		} else
		{
			victim->receive_damage("qi", damage ,me);
			victim->receive_wound("qi", damage/3 ,me);
			me->add("neili", -100 );
			message_vision(HIR"$n纵身稍慢，被"+weapon1->name()+HIR"在左胫上一拨，右踝上一钩，扑地倒了。\n"NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
			return ;
		}
	}
	if (random(7)==1 && me->query("jiali") > 0 && random(ap)>dp/3 )
	{
		damage = (damage1+damage_bonus)*(liannum+20)/(20*liannum+1);
		victim->receive_damage("qi", damage ,me);
		victim->receive_wound("qi", damage/3 ,me);
		me->add("neili", -100 );
		message_vision(HIR"$n尚未落地，被"+weapon1->name()+HIR"又是一挑一打，$n立足不住，仰天一交摔倒。\n"NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
		return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiajing")>0 && random(7)==2 && (int)me->query("breakup")>1 )
	{
		damage = (damage2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("jingli",-100);
		victim->receive_damage("jing", damage,me);
		victim->receive_wound("jing", damage/3,me);
		COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
		message_vision(HIC"$N"+weapon1->name()+HIC"挥出，领悟"+me->query("cognize")+HIC"的力量，以“绊”字诀着地扫去，一绊不中，二绊续至，连环钩盘，绵绵而不绝。\n"NOR, me,victim,damage,HBWHT+HIR"特效伤精"NOR);
		return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiali")>0 && random(7)==3 && (int)me->query("jm/gaibang") )
	{
		damage = ((damage1+damage2)/2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("neili",-100);
		victim->receive_damage("qi", damage,me);
		victim->receive_wound("qi", damage/3,me);
		message_vision(HIG"$N顿悟丐帮武功精髓，使出“劈”字诀，挥舞起手中"+weapon1->name()+HIG"如狂风暴雨般的打去！$n被点中"RED+xname+HIG"，受伤不轻。\n"NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
		return ;
	}
	if (random(7)==4 && me->query("jiali") > 0 && random(ap)>dp/3 )
	{
		if (!victim->is_busy()) victim->start_busy(2);
		me->add("neili", -100 );
		return HIG"$N使个“缠”字诀，"+weapon1->name()+HIG"挥到东，$n跟向东，"+weapon1->name()+HIG"打到西，$n随到西，如影随形，借力制敌。\n"NOR;
	}
	if (random(7)==5 && me->query("jiali") > 0 && random(ap)>dp/3 )
	{
		damage = (damage1+damage_bonus)*(liannum+20)/(20*liannum+1);
		victim->receive_damage("qi", damage ,me);
		victim->receive_wound("qi", damage/3 ,me);
		me->add("neili", -100 );
		message_vision(HIG"$N"+weapon1->name()+HIG"缩回，使起“挑”字诀，将$n疾奔的力道反击回去\n"NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
		return ;
	}
	if (random(7)==6 && me->query("jiali") > 0 && random(ap)>dp/3 )
	{
		damage = (damage1+damage_bonus)*(liannum+20)/(20*liannum+1);
		victim->receive_damage("qi", damage ,me);
		victim->receive_wound("qi", damage/3 ,me);
		me->add("neili", -100 );
		message_vision(HIG"$N棒法再变，使出了“转”字诀。但见"+weapon1->name()+HIG"化成了一团碧影，猛点$n的"RED+xname+HIG"。\n"NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
		return ;
	}
}
	//2017.3.25阿飞封掉ob_hit特效，怀疑与伤害为0的死亡bug有关
int ob_hit(object ob, object me, int damage)
{
	int j,ap,dp,damage1,damage2;
	object weapon;
	weapon = me->query_temp("weapon");
	ap = me->query_skill("dagou-bang", 1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	dp = ob->query_skill("unarmed", 1)*(ob->query("breakup")+ob->query("breakup")*ob->query("breakup")+100)/100;
	damage1 = me->query_skill("dagou-bang", 1);
	damage2 = me->query_skill("dagou-bang", 1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	if (damage <10) damage=10;
    if ( me->query("neili") < 100 || me->query("jingli") < 100 ) return damage;
	if ( me->query_skill("huntian-qigong",1) < 300 || me->query_skill("dagou-bang",1) < 300) return damage;
//	if ( me->query_skill_mapped("force") != "huntian-qigong") return damage;
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "club") return damage;

	if ( random(ap)>dp/4 && random(8)==1 )
	{
		j = -damage/2;
		if (!ob->is_busy()) ob->start_busy(2);
		me->add("neili", -100 );
		message_vision(HIY"$N连续使出“绕”字诀，“绊”字决，让$n不知所措！\n"NOR, me, ob);
		return j;
	}
	if ( random(ap)>dp/4 && random(8)==2 && (int)me->query("breakup")>1 )
	{
		j = -damage;
		ob->receive_damage("jing",damage2,me);
		ob->receive_wound("jing",damage2/2,me);
		me->add("jingli", -100 );
		message_vision(HIG "$n一招甫出，但见$N使个“封”字诀，棒影飘飘，登时将自己身前数尺之地尽数封住了。$n无奈之下，只有后退一步，静观变化。\n" NOR, me, ob,damage2,HBWHT+HIY"精神反伤"NOR);
		return j;
	}
	if ( random(ap)>dp/4 && random(8)==3 && (int)me->query("jm/gaibang") )
	{
		j = -(damage+random(damage));
		me->add("neili", -100 );
		ob->receive_damage("qi",damage1,me);
		ob->receive_wound("qi",damage1/2,me);
		message_vision(HIG "$n的手指刚要碰到$N手腕，突然青影闪动，" + weapon->name() + HIG "一势“戳”字诀，来势神妙无方，\n" + "$n手腕已被重重地敲了一下，慌忙后退两步，变色斜睨，背上惊出了一阵冷汗。\n" NOR, me, ob,damage1,HBWHT+HIY"气血反伤"NOR);
		return j;
	}
}

//2018.9.5 阿飞改，重新启动自动连招
void do_interlink(object me, object victim)
{
	int extra,max_enemy, max_att, i, j;
    object *enemy, weapon;
	string all_enemy;
	if( !objectp(weapon = me->query_temp("weapon") ) || (string)weapon->query("skill_type") != "club" ) return;
	if ( me->query_skill_mapped("club") != "dagou-bang") return;
//	if ( me->query_skill_mapped("force") != "huntian-qigong") return 0;
	if ( (int)me->query_skill("dagou-bang", 1) < 600 || (int)me->query_skill("huntian-qigong", 1) < 600)  return;
	if( me->query("neili") < (int)me->query_skill("dagou-bang", 1)*4 ) return;
	if ( me->query_temp("autolian") ) return;
	if ( me->query_temp("cooldown") ) return;
	if (me->is_busy()) return;
	if ( me->query("auto_lian") ) return;	//自动连招开关，使用auto命令来设置
	
	if ( (int)me->query_skill("dagou-bang", 1) > 600 && me->query("int",1) > 30)   
	{
		enemy = me->query_enemy();
		if ( !(max_enemy=sizeof(enemy)) ) return;
		if ( userp(me) && !me->query("xkxvip/times") ) return;
		all_enemy = "";
		max_att = ((int)me->query_skill("dagou-bang", 1)-300)/(60*max_enemy);
		if (me->query("jm/gaibang")) 
		{
			if(max_att*max_enemy > 150+(int)me->query_temp("lianzhao_max_add")*4) max_att = (150+(int)me->query_temp("lianzhao_max_add")*4)/max_enemy;
		} else 
		{
			if(max_att*max_enemy > 50+(int)me->query_temp("lianzhao_max_add")*2) max_att = (50+(int)me->query_temp("lianzhao_max_add")*2)/max_enemy;
		}
		if(max_att < 1) max_att = 1;
		for ( i=0; i<max_enemy; i++ )
		{
			if ( !objectp(enemy[i]) ) continue;
			all_enemy += enemy[i]->name();
			if ( i < max_enemy-1) all_enemy += "、";
		}		
		message_vision(HIG+"$N眼中射出一道青芒，陡然使出「"+HIC+"天下无狗"+HIG+"」，如山棒影劈天盖地般攻向"+all_enemy+"。\n\n" NOR,me);
		me->set_temp("autolian", 1);	//2017.3.3阿飞改，添加自动连招标记
		call_out("del_autolian", 3, me);		
		me->add_temp("lianzhao", max_att);	 //2016.6.1阿飞改，增加连招标记，用于削弱连招伤害
		extra = me->query_skill("dagou-bang", 1)/3;	
		if ( me->query_skill_mapped("force") != "huntian-qigong") extra += me->query_skill("dagou-bang", 1)/2;	//2018.9.5阿飞改，不使用本门特内则减益
		if ((string)weapon->query("id") == "yuzhu zhang") extra = -me->query_skill("dagou-bang", 1)/3; //2018.3.25阿飞改，拿特殊武器有加成
		me->add_temp("apply/attack", -extra);	
		me->add_temp("apply/damage", -extra);
		me->add_temp("apply/strength", -extra);		
		for ( i=0; i<max_enemy; i++ )
		{
			if ( !objectp(enemy[i]) ) continue;
			
			for ( j=0; j<max_att; j++ )
			{
				if( !objectp(weapon = me->query_temp("weapon") ) || (string)weapon->query("skill_type") != "club" || me->query_skill_mapped("club") != "dagou-bang" ) break;	//防止使用辟邪自动连后更换其他技能，终止自动连
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
		me->delete_temp("lianzhao");  //2016.6.1阿飞改，连招结束取消连招标记	
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
