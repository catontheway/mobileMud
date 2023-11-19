// /kungfu/skill/xiangfu-lun.c
// xiangfu-lun.c 降伏轮
// dubei
// snowman(98,12,22)
// iceland(99.8.3)
#include <ansi.h>
#include <combat.h>
inherit SKILL;

string *order = ( {""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


mapping *action = (
{
([      "action" : "$N使一招"+(order[random(13)])+"「破竹势」"NOR"，抡起手中的$w向$n的$l砸去  ",
"skill_name" : "破竹势",
		"attack":	200,
		"parry":	200,
		"dodge":	200,
		"damage":	200,
		"force":	200,
	"lvl" : 0,
"damage_type" : "挫伤",
	 ]),
([      "action" : "$N使一招"+(order[random(13)])+"「隐山谷势」"NOR"，双肩一沉，舞动手中$w向$n的$l横扫  ",
"skill_name" : "隐山谷势",
		"attack":	200,
		"parry":	200,
		"dodge":	200,
		"damage":	200,
		"force":	200,
	"lvl" : 8,
"damage_type" : "挫伤",
	 ]),
([      "action" : "$N使一招"+(order[random(13)])+"「隐微势」"NOR"，就地一滚，手中自下而上撩向$n的$l  ",
"skill_name" : "隐微势",
		"attack":	200,
		"parry":	200,
		"dodge":	200,
		"damage":	200,
		"force":	200,
	"lvl" : 16,
"damage_type" : "挫伤",
	 ]),
([      "action" : "$N使一招"+(order[random(13)])+"「擒纵势」"NOR"，身形起伏之际$w扫向$n的$l  ",
"skill_name" : "擒纵势",
		"attack":	200,
		"parry":	200,
		"dodge":	200,
		"damage":	200,
		"force":	200,
	"lvl" : 24,
"damage_type" : "挫伤",
	 ]),
([      "action" : "$N使一招"+(order[random(13)])+"「圆满势」"NOR"，$w如离弦之箭般直捣$n的$l  ",
"skill_name" : "圆满势",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
	"lvl" : 32,
"damage_type" : "挫伤",
	 ]),
([      "action" : "$N跃入半空，使一招"+(order[random(13)])+"「月重辉势」"NOR"，高举$w敲向$n的$l  ",
"skill_name" : "月重辉势",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
	"lvl" : 40,
"damage_type" : "挫伤",
	 ]),
([      "action" : "$N使一招"+(order[random(13)])+"「捉月势」"NOR"，斜举手中$w击向$n的$l  ",
"skill_name" : "捉月势",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
	"lvl" : 48,
"damage_type" : "挫伤",
	 ]),
([      "action" : "$N提一口真气，使出"+(order[random(13)])+"「显吉祥」"NOR"，$w扫向$n的头部  ",
"skill_name" : "显吉祥",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,
	"lvl" : 56,
"damage_type" : "挫伤",
	 ]),
([      "action" : "$N一招"+(order[random(13)])+"「大赞叹光明势」"NOR"，右手立掌念经，左手单臂抡起$w，夹杂着阵阵风声向$n的$l砸去",
"skill_name" : "大赞叹光明势",
		"attack":	200,
		"parry":	200,
		"dodge":	200,
		"damage":	200,
		"force":	200,
	"lvl" : 5,
"damage_type" : "砸伤",
	 ]),
([      "action" : "$N将手中$w抛上半空，跃起一掌砸在$w上，这式"+(order[random(13)])+"「大皈依光明势」"NOR"有如流星坠地，直轰$n",
"skill_name" : "大皈依光明势",
		"attack":	200,
		"parry":	200,
		"dodge":	200,
		"damage":	200,
		"force":	200,
	"lvl" : 25,
"damage_type" : "瘀伤",
	 ]),
([      "action" : "凭空闪出一道雪白的光幕，光电闪烁中$w挟"+(order[random(13)])+"「大功德光明势」"NOR"的无上劲力，从$N手中飞出砍向$n的$l",
"skill_name" : "大功德光明势",
		"attack":	200,
		"parry":	200,
		"dodge":	200,
		"damage":	200,
		"force":	200,
	"lvl" : 45,
"damage_type" : "割伤",
	 ]),
([      "action" : "$N双眼磕闭，全身衣物却在内劲冲击下涨如气球，那$w在这"+(order[random(13)])+"「大福德光明势」"NOR"的推动下，向$n缓缓压来",
"skill_name" : "大福德光明势",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
	"lvl" : 65,
"damage_type" : "内伤",
	 ]),
([      "action" : "$N双手画圈，越转越急，光幕宛如一轮明月，将$P笼罩，这"+(order[random(13)])+"「大吉祥光明势」"NOR"的劲力带着$w以排山倒海之势飞旋而出",
"skill_name" : "大吉祥光明势",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
	"lvl" : 85,
"damage_type" : "砸伤",
	 ]),
([      "action" : "$N口中高唱「降魔咒」，一招"+(order[random(13)])+"「大三昧光明势」"NOR"挥出，$w幻化的漫天的轮影犹如行云流水般涌向$n",
"skill_name" : "大三昧光明势",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,	
	"lvl" : 105,
"damage_type" : "瘀伤",
	 ]),
([      "action" : "$N一招"+(order[random(13)])+"「大般若光明势」"NOR"，面带宝光，以无上降魔大法催动手$w，那舞动的光云慢慢移向$n，彷佛要笼罩一切妖魔",
"skill_name" : "大般若光明势",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,	
	"lvl" : 125,
"damage_type" : "瘀伤",
	 ]),
([      "action" : "$N提一口真气，使出"+(order[random(13)])+"「大智慧光明势」"NOR"，手中$w上下翻飞，轮番砸向$n，叫$p再也分不清哪个是真，哪个是假",
"skill_name" : "大智慧光明势",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,	
	"lvl" : 145,
"damage_type" : "砸伤",
	 ]),
([      "action" : "$N面带微笑，眼露慈光，全身所散发出的"+(order[random(13)])+"「大慈悲光明势」"NOR"气劲宛如惊涛骇浪，$w一层接一层地涌向$n",
"skill_name" : "大慈悲光明势",
		"attack":	500,
		"parry":	500,
		"dodge":	500,
		"damage":	500,
		"force":	500,
	"lvl" : 165,
"damage_type" : "瘀伤",
	 ]),
([      "action" : "$N双手高举$w，大喝一声使出"+(order[random(13)])+"「大圆满光明势」"NOR"自上而下斩向$n，其快绝无比，气势汹涌，已达圆满之境",
"skill_name" : "大圆满光明势",
		"attack":	600,
		"parry":	600,
		"dodge":	600,
		"damage":	600,
		"force":	600,
	"lvl" : 185,
"damage_type" : "刺伤",
	 ]),
});

string *parry_msg = (
{
	"$n不躲不避，手中$w摆开，在$P跟前形成了一道光幕，$N此招根本无法再进。\n",
	"却见$n踏前一步，手中$w翻飞，其势甚巨，$N前进不能，只好闪身而退。\n",
	"$n轮法突变，$w带着风声飞舞出去，后发先至，在$N还没攻出时就破了$p的招数。\n",
	"但见$n举$w硬挡，乒的一声架开了来势汹汹的$N。\n",
});

string *msg = (
{
	""+(order[random(13)])+"空中那五只$w对击，声若龙吟，悠悠不绝，就在$n一呆之际，$w飞砸了出去！"NOR"",
	""+(order[random(13)])+"呜呜声响中，$w旋转飞舞着撞向$n，在$p便要挡隔时，却绕过他飞到了身後"NOR"",
	""+(order[random(13)])+"$w连续掷出，连续飞回，绕著$n兜个圈子，忽高忽低，或正或斜，所发声音也是有轻有响，旁观众人均给扰得眼花撩乱，心神不定"NOR"",
	""+(order[random(13)])+"一声「小心了！」，蓦然间$w五体归一，并排向$n撞去，势若五牛冲阵，威不可挡"NOR"",
	""+(order[random(13)])+"只见$w绕著$n，上下翻飞，$w跳跃灵动，呜呜响声不绝，掀的阵阵狂风有如刀割，似要把$n从中劈开"NOR"",
	""+(order[random(13)])+"突然，狂风乱起，激荡中那$w相碰相撞，五轮归一，合并了向$n砸去"NOR"",
	""+(order[random(13)])+"法轮在$n身前环饶，猛地向$p迎头击下，接着又飞来一轮，一抄一送，呜呜声响，兜向$n$l"NOR"",
	""+(order[random(13)])+"呼呼飞啸声中，那五只$w或直飞、或斜飞、或回旋、或下坠、或上升，霎时间$n的全部退路已被封死"NOR"",
	""+(order[random(13)])+"猛地里$w向$n$l飞砸下，在$p沉肩卸避之时，$w又突然上飞击出，砸向$p的$l"NOR"",
	""+(order[random(13)])+"那$w飞旋砸到，$n却并不回头，听风辨器，一一挡开，但$w便如长上了眼睛一般，竟然又旋飞到了$n$l"NOR"",
});


int valid_enable(string usage) { return usage == "hammer" || usage == "parry"; }

void skill_improved(object me)
{
	int skill = me->query_skill("xiangfu-lun", 1);
	if(skill >= 200 && !me->query("ryl_add")){
		me->set("ryl_add", 1);   
		tell_object(me, HIW"\n忽然，你感道内息越转越快，瞬时功力已经上升到了一个新的境界！\n你的精力增加了！\n你的内力增加了！\n"NOR);
		me->add("max_jingli", skill/2+random(skill));
		me->add("max_neili",skill/2+random(skill));
	}
	if(skill > 300 && random(4) == 1)
	{
		me->set_skill("xiangfu-lun", skill-1);
	}
}
int valid_learn(object me)
{
        if((int)me->query_str() <35)
		return notify_fail("你的臂力不够学降伏轮。\n");
	if((int)me->query("max_neili") < 2000)
		return notify_fail("你的内力不够。\n");
	if((int)me->query_skill("longxiang-boruo", 1) <= 200)
		return notify_fail("需要有第二层以上龙象般若功火候,才能学降伏轮。\n");
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

	level = (int) me->query_skill("xiangfu-lun",1);
	
	if( !userp(me) && me->query("env/invisibility")
	&& me->query("master_user/user") ){
		return ([
			"action": msg[random(sizeof(msg))],
			"damage":(random(4)+1)*60,
			"damage_type":random(2)?"砸伤":"瘀伤",
			"dodge": 5,
			"force":250+random(250)
		]);
	}

	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

mixed query_parry_msg(object weapon, object me, int attack_type)
{
	if (objectp(weapon) && objectp(me)
	&& (string)weapon->query("skill_type") == "hammer"
	&& me->query_skill_mapped("hammer") == "xiangfu-lun"
	&& me->query_skill_mapped("parry") == "xiangfu-lun")
		return parry_msg[random(sizeof(parry_msg))];
	return "结果被堪堪架开。\n";
return "结果被架开！！！！！！！！！！！！\n";

}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	    || (string)weapon->query("skill_type") != "hammer")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的气不够，无法练习降伏轮。\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("你的现在的内力不足，无法继续练降伏轮。\n");
	me->add("qi", -45);
	me->add("neili", -25);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"xiangfu-lun/" + action;
}

void after_hit(object me, object victim, string attack_skill, int damage)
{
	object wp1, target, *eny; 
	string msg;
	int i, pflv;

	pflv = (int)me->query("purefamily/level");
	if (pflv>0 && me->query("purefamily/family_name") != "大轮寺") 
		pflv=0;

	wp1 = me->query_temp("weapon");
	eny=me->query_enemy();
	eny-=({victim});
	if (pflv>=5) i=3;
	else if (pflv==4) i=2;
	else i=1;
	while (i>0 && sizeof(eny)>0 )
	{
		target = eny[random(sizeof(eny))];
		if (F_KUNGFU->hit_rate( me->query_str()+15, target->query_dex(), 9, me, target) )
		{
			msg=HIG"$N"HIG"挥舞" +wp1->name()+ HIG "顺势向$n" HIG "砸了过来，砰的一声砸了个正着。\n"NOR;
			message_vision(msg, me, target);
			F_KUNGFU->hit_wound("qi", damage*4/5, damage/5, me, target);
			COMBAT_D->report_status(target);
			damage = damage * (70+random(20)) / 100;
		}
		else
		{
			message_vision(HIY"$N"HIY"挥舞" +wp1->name()+ HIG "顺势向$n" HIY "砸了过来，但一下挥了个空。\n"NOR, me, target);
			break;
		}
		eny -= ({ target });
		i--;
	}
}

void after_victim_parry(object me, object victim, string attack_skill)
{
	object wp1, wp2; 
	int pflv, dmg, duo = 0;
	string msg;

	if( !objectp(wp2= victim->query_temp("weapon")) )
	{
		if( !objectp(wp2= victim->query_temp("secondary_weapon")) )
			return;
	}
	
	pflv = (int)me->query("purefamily/level");
	if (pflv>0 && me->query("purefamily/family_name") != "大轮寺") 
		pflv=0;
	
	if (pflv>=5 && F_KUNGFU->hit_rate( me->query_str(), victim->query_str(), 12, me, victim) )
	{
		if ((wp2->query("id") == "xuantie sword" || wp2->query("never_broken"))
			&& !wp2->query("owner")) //玄铁剑居然没有特殊标记，只好用ID，囧
		{
			msg = HIY+"$N"+HIY"力贯双臂，势挟风雷，砸在$n"+HIY"的"+wp2->name()+HIY"上，噗的一声，响声又沉又闷，便如木棍击打败革！\n"NOR;
			message_vision(msg, me, victim);
		} else {
			msg = HIM+"$N"+HIM"力贯双臂，势挟风雷，砸在$n"+HIM"的"+wp2->name()+HIM"上，发出一声巨响！\n"NOR;
			dmg = me->query_str() / 2;
			wp2->add("rigidity", -dmg);
			if (wp2->query("rigidity") < 1)
			{
				msg += HIR "只听见「啪」地一声，"+ wp2->name() + HIR + "登时断为两截，$n也被这一击震得倒退三步，呕出一口鲜血！\n" NOR;
				message_vision(msg, me, victim);
				dmg = me->query_skill("longxiang-boruo", 1) + me->query_skill("xiangfu-lun",1);
				dmg *= 2;
				dmg = dmg*4/5 + random(dmg/5);
				F_KUNGFU->hit_wound("qi", dmg, dmg/3, me, victim);
				COMBAT_D->report_status(victim);
				return;
			}
			message_vision(msg, me, victim);
		}
	}
		
	if( !me->query("env/锁")
	|| me->query_skill("xiangfu-lun", 1) < 150 
	|| !me->query("jiali")
	|| me->query("neili") < 1000 
	|| me->query_skill_mapped("parry") != "xiangfu-lun" )
		return;

	wp1 = me->query_temp("weapon");

	if( random(10) >= 6 
	&& F_KUNGFU->hit_rate( me->query("combat_exp"), victim->query("combat_exp"), 12, me, victim) ){
		message_vision(HIW"$N"HIW"手臂暴长，施展「锁」字诀，"+wp1->name()+HIW"探出，嚓的一声锁住了$n"+wp2->name()+HIW"。\n"NOR, me,victim);
		if( F_KUNGFU->hit_rate( me->query_str(), victim->query_str(), 18, me, victim) ){           
			me->add("neili", -150);
			message_vision(HIG+"$N"+HIG"运劲回拉，$n"+HIG"臂骨喀的一声，险些就被拉断，剧痛之下手一松，"+wp2->name()+HIG"被夺了过去！\n"NOR, me, victim);
			wp2->unequip();
			wp2->move(me);
			duo = 1;
		}

		else if( F_KUNGFU->hit_rate( me->query_str(), victim->query_str(), 12, me, victim) ){           
			me->add("neili", -50);
			message_vision(HIG+"$N"+HIG"运劲回拉，$n"+HIG"被带得踉跄几步，但觉虎口剧痛，"+wp2->name()+HIG"脱手飞出！\n"NOR, me, victim);
			wp2->unequip();
			wp2->move(environment(victim));
			duo = 1;
		}

		else if( me->query_temp("shield") ){           
			me->add("neili", -50);
			message_vision(HIY"$n"+HIY"借势前冲，"+wp2->name()+HIY"直刺过去，但被$N"+HIY"护体真气荡得滑了开去。\n"NOR, me, victim);
		}

		else message_vision(HIY"$n"+HIY"借势前冲，"+wp2->name()+HIY"直刺$N"+HIY"，$N"+HIY"变招奇快，"+wp1->name()+HIY"一抖松脱，纵身退了开去。\n"NOR, me, victim);
        
        if(duo == 1 && wp2->query("gem_ob_autoloaded") == 1)
        {
            message_vision(wp2->name()+"片片寸断，散落一地,$N不禁叹息不已。\n",victim);
            wp2->unequip();
            destruct(wp2);
        }
	}
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{
	string msg;
	int ap,dp, damage1,damage2,damage,liannum;
	object weapon1,weapon2;
	weapon1 = me->query_temp("weapon");
	weapon2 = victim->query_temp("weapon");
    ap = me->query_skill("riyue-lun",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	dp = victim->query_skill("parry",1)*(victim->query("breakup")+victim->query("breakup")*victim->query("breakup")+100)/100;
    damage1= (int) me->query_skill("riyue-lun",1);
	damage2 = (int)me->query_skill("riyue-lun",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	if( me->query_temp("lianzhao")>=1) liannum=me->query_temp("lianzhao");
	else liannum =1;
	if( me->query("neili") < 100 || me->query("jingli") < 100 || damage_bonus < 100 ) return 0;
	if ( ( me->query_skill("xiaowuxiang",1) < 100 && me->query_skill("longxiang",1) < 100) || me->query_skill("riyue-lun",1)<100) return 0;
//	if ( me->query_skill_mapped("force") != "xiaowuxiang" && me->query_skill_mapped("force") != "longxiang") return 0;
	if (!objectp(weapon1 = me->query_temp("weapon")) || (string)weapon1->query("skill_type") != "hammer") return 0;

	if (random(7)==1 && random(ap) > dp/3 && me->query("jiali") > 0)
	{
		damage = (damage1+damage_bonus)*(liannum+20)/(20*liannum+1);
		victim->receive_damage("qi", damage ,me);
		victim->receive_wound("qi", damage/3 ,me);
		me->add("neili", -100);
		if (!victim->is_busy()) victim->start_busy(1);
		message_vision(HIR"$N大呼酣战，口念密宗不动明王真言，运龙象之力朝$n击去！\n"NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
        return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiajing")>0 && random(7)==2 && (int)me->query("breakup")>1 )
	{
		damage = (damage2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("jingli",-100);
		victim->receive_damage("jing", damage,me);
		victim->receive_wound("jing", damage/3,me);
		if (!victim->is_busy()) victim->start_busy(1);
		message_vision(HIG "$N顿悟"+me->query("cognize")+HIG"，剑随意走，手中" + weapon1->name() + HIG "脱手而出，旋即又回旋返回，$n刚躲过前一轮，未能防备后招，后心受到重重一击。\n" NOR, me,victim,damage,HBWHT+HIR"特效伤精"NOR);
		return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiali")>0 && random(7)==3 && (int)me->query("jm/xueshan") )
	{
		damage = ((damage1+damage2)/2+damage_bonus)*(liannum+20)/(20*liannum+1);
		msg = HIM"$N贯通雪山寺武学精髓，手中" + weapon1->name() + HIM "正面炙热如日，背面月光冷清，如日月凌空，" NOR;
		if ( objectp(weapon2=victim->query_temp("weapon")))
		{
			msg += HIM"$n提起全身功力注入手中" + weapon2->name() + HIM "，“哄”的一声巨响，" NOR;
			if(random(10)>3)
			{
				msg += HIM"$n狂喷鲜血。\n" NOR;
				victim->receive_damage("qi", damage,me);
				victim->receive_wound("qi", damage/3,me);
				message_vision(msg, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
			}
			else
			{
				weapon2->unequip();
//				weapon2->reset_action();
				weapon2->move(environment(victim));
				weapon2->set("name", "断掉的" + weapon2->query("name"));
				weapon2->set("item_old_value", weapon2->query("value"));
				weapon2->set("value", 0);
				weapon2->set("backold_weapon_prop", weapon2->query("weapon_prop"));
				weapon2->set("weapon_prop", 0);			
				msg += HIM "紧接着"+(order[random(13)])+"「叮当」"NOR"一声兵刃破碎的声音，兵器碎片溅了一地！\n" NOR;
				message_vision(msg, me,victim);
				if( !me->is_killing(victim) ) me->kill_ob(victim);
				if( !victim->is_killing(me) ) victim->kill_ob(me);
				message_vision( HIR"$N摧毁了$n的武器！这可是不死不休的大仇啊！\n"+NOR,me,victim);
			}
		}
		else
		{
			msg += HIM"$n一会炙热，一会阴冷，忍受不住吐出一口鲜血。\n" NOR;
			victim->receive_damage("qi", damage,me);
			victim->receive_wound("qi", damage/3,me);
			message_vision(msg, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
		}
		me->add("neili",-100);
		return ;
	}
}



int help(object me)
//added by iszt@pkuxkx, 2006-11-28
{
	write(HIW"\n降伏轮\n\n"NOR);
	write(@HELP
	可激发为锤法和招架。
	达到200级时可增加100～300点最大内力和最大精力。
	要求：  后天膂力35；
		最大内力2000；
		龙象般若功160级；
	练习：  耗气45；
		耗内力25；
	「锁」字诀：
	设置 set 锁 1 后满足要求随机自动出招，效果为夺来或打掉对方兵器。
	要求：  降伏轮150级；
		加力不为0；
		内力1000；
		激发降伏轮为招架。
HELP
	);
	return 1;
}
