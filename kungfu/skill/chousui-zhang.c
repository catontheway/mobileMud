// chousui-zhang.c  抽髓掌	中乘武学200~600
// modified by Venus Oct.1997
// by yucao

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
//#include <condition.h>
inherit SKILL;
string *order = ( {""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = (
{
([      "action": ""+(order[random(13)])+"$N脸上露出诡异的笑容，隐隐泛出绿色的双掌扫向$n的$l"NOR"",
		"attack":	200,
		"parry":	200,
		"dodge":	200,
		"damage":	200,
		"force":	200,
"damage_type": "瘀伤"
	 ]),
([      "action": ""+(order[random(13)])+"$N突然身形旋转起来扑向$n，双掌飞舞着拍向$n的$l"NOR"",
			"attack":	200,
			"parry":	200,
			"dodge":	200,
			"damage":	200,
			"force":	200,
"damage_type": "瘀伤"
	 ]),
([      "action": ""+(order[random(13)])+"$N将毒质运至右手，一招「腐尸毒」阴毒无比地抓向$n的$l"NOR"",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
"damage_type": "瘀伤"
	 ]),
([      "action": ""+(order[random(13)])+"$N双掌挟着一股腥臭之气拍向$n的$l"NOR"",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
"damage_type": "瘀伤"
	 ]),
([      "action": ""+(order[random(13)])+"$N催动内力，衣袖挥动，双掌挟着一股腥臭之气一前一后拍向$n的$l"NOR"",
		"attack":	300,
		"parry":	300,
		"dodge":	300,
		"damage":	300,
		"force":	300,
	"lvl" : 0,
"damage_type": "瘀伤"
	 ]),

([      "action": ""+(order[random(13)])+"$N双脚一曲一弯，身体旋转起来, 突然间双掌飞舞着拍向$n的$l"NOR"",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,	
	"lvl" : 0,
"damage_type": "瘀伤"
	 ]),

([      "action": ""+(order[random(13)])+"$N身形飘动，围着$n一圈圈游走，同时双掌连拍，激起阵阵劲风吹向$n"NOR"",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,	
	"lvl" : 30,
"damage_type": "内伤"
	 ]),

([      "action": ""+(order[random(13)])+"$N突然厉声大喝，跃于半空，立掌如斧，上上下下向$n连连劈出数掌"NOR"",
"weapon" : "掌风",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,	
	"lvl" : 50,
"damage_type": "割伤"
	 ]),

([      "action": ""+(order[random(13)])+"$N身形微晁抢前一步，运起十成功力，大喝一声，须发戟张，呼的一掌又向$n推去"NOR"",
		"attack":	500,
		"parry":	500,
		"dodge":	500,
		"damage":	500,
		"force":	500,
	"lvl" : 70,
"damage_type": "内伤"
	 ]),

([      "action": ""+(order[random(13)])+"$N面露诡异的笑容，猛地向前冲出，对准$n的$l就是一招阴毒无比的「抽髓掌」"NOR"",
		"attack":	500,
		"parry":	500,
		"dodge":	500,
		"damage":	500,
		"force":	500,
	"lvl" : 95,
"damage_type": "瘀伤"
	 ]),

([      "action": ""+(order[random(13)])+"$N心念一转，计上心来，一招「三阴蜈蚣爪」，招招连环，连珠般抓向$n的$l"NOR"",
"weapon" : "手爪",
		"attack":	600,
		"parry":	600,
		"dodge":	600,
		"damage":	600,
		"force":	600,	
	"lvl" : 120,
"damage_type": "抓伤"
	 ]),
});

int valid_enable(string usage)
{
	return  usage=="strike" || usage=="parry";
}
//2019-1-1阿飞新规划，技能代码完善
string valid_combine() { return "huoyan-dao"; }		//互备技能
string skill_pinji() {return "中乘";}				//品级区分：上乘、中乘、下乘
string skill_xingbie() {return "通用";}				//性别区分：男性、女性、无性、通用
string skill_zhengxie() {return "邪道";}			//正邪区分：正道、邪道、中立
string skill_menpai() {return "星宿派";}				//门派区分：门派，江湖
string skill_yinyang() {return "阴";}				//阴阳区分：阳、阴、中性
string skill_zhenying() {return "邪派";}			//阵营区分：正派、邪派、中立、通用
int damage_damage() {return 65;}	//外伤系数
int force_damage() {return 54;}		//内伤系数
//int qi_heal() {return 50;}		//内功疗气系数
//int jing_heal() {return 50;}		//内功疗精系数
int practice_level() {return 100;}	//自练级别
int practice_add() {return 100;}	//自练效率
int perform_level() {return 300;}	//PFM最低使用级别

mapping query_action(object me)
{
	if (present("huo yan", environment(me)))
	{
		if (random(me->query_skill("chousui-zhang")) > 600 && me->query_temp("powerup") && 
		me->query("neili") > 1000 && random(20)==1 && me->query("jiali")>=100)
		{
			me->add("neili", -200);
			return ([
            "action":BLU"$N神色惨淡，伸手打开发髻，长发下垂，覆在脸上，跟着力咬舌尖，"+HIR+"一口鲜"
			            "血向火焰中喷去。\n那火焰忽地一暗，"+HIW+"随即大为明亮，$N猛地身子急旋，如陀"
			            "螺般连转了十多个圈子，"+HIR+"大袖拂动，整个火焰堆陡地拨起，便如一座火墙般向$n压过去"NOR,
		"attack":	600,
		"parry":	600,
		"dodge":	600,
		"damage":	600,
		"force":	600,	
            "weapon": "火焰",
            "damage_type": "烧伤"]);
		}
		if (random(me->query_skill("chousui-zhang")) > 500 && me->query_temp("powerup") && 
		me->query("neili") > 800 && random(20)==2 && me->query("jiali")>=100)
		{
			me->add("neili", -200);
			return ([
            "action":HIG"$N厉声大喝，掌力加盛，绿火突然化作一个"+HIR+"斗大的火球，向$n疾冲过来。使力极猛，去势奇快，"+HIG+"只见一碧绿的火球在空中骨碌碌的迅速转动"NOR,
		"attack":	600,
		"parry":	600,
		"dodge":	600,
		"damage":	600,
		"force":	600,	
            "weapon": "火球",
            "damage_type": "烧伤"]);
		}
		if (random(me->query_skill("chousui-zhang")) > 400 && me->query_temp("powerup") && 
		me->query("neili") > 600 && random(20)==3 && me->query("jiali")>=100)
		{
			me->add("neili", -150);
			return ([
            "action":HIR"$N衣袖一拂，一股劲气直射入火焰之中，"+HIG+"火焰中又分出一道细细的绿火，便如一根水线般，"
			            +HIW+"$N衣袖挥动，两股劲风分袭$n左右"NOR,
		"attack":	500,
		"parry":	500,
		"dodge":	500,
		"damage":	500,
		"force":	500,
            "weapon": HIG"绿火"NOR,
            "damage_type": "烧伤"]);
		}
		if (random(me->query_skill("chousui-zhang")) > 300 && me->query_temp("powerup") && 
		me->query("neili") > 500 && random(20)==4 && me->query("jiali")>=100)
		{
			me->add("neili", -150);
			return ([
            "action":HIR"$N随即左掌斜拍出一道"+HIG+"绿火"+HIR+"向$n射去，声势汹汹，"+HIG+"便似一条绿色长蛇横卧空际，轻轻摆动，"
			            +HIR+"颜色又是鲜艳，"+BLU+"又是诡异，光芒闪烁不定"+HIG+"照映得$n头脸皆碧"NOR,
		"attack":	500,
		"parry":	500,
		"dodge":	500,
		"damage":	500,
		"force":	500,
            "weapon": HIG"绿火"NOR,
            "damage_type": "烧伤"]);
		}
		if (random(me->query_skill("chousui-zhang")) > 200 && me->query_temp("powerup") && 
		me->query("neili") > 400 && random(20)==5 && me->query("jiali")>=100)
		{
			me->add("neili", -100);
			return ([
            "action":HIR"$N突然间双眉往上一竖，右手食指点两点，火焰堆中嗤嗤两声轻响，"+HIG+"爆出几朵火花，犹如流星一般，"
			            "在$N内力摧迫下，分从左右袭向$n，来势迅速之极"NOR,
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,		
            "weapon": "火花",
            "damage_type": "烧伤"]);
		}
	}
	if (random(me->query_skill("chousui-zhang",1)) > 200 && 
	me->query("neili") > 200 && random(20)>14 && me->query("jiali")>=10)
	{
		me->add("neili", -100);
		return ([
            "action": ""+(order[random(13)])+"$N咬破舌尖，口中喷血，聚集全身的力量击向$n"NOR"",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,		
            "damage_type": "瘀伤"]);
	}
	return action[random(sizeof(action))];
}

int valid_learn(object me)
{
//	if (!wizardp(me))
//		return ("巫师突然从黑暗中冲了出来，对你大吼一声：该门派没开放。\n");		
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练抽髓掌必须空手。\n");
	if ((int)me->query_skill("huagong-dafa", 1) < 100)
		return notify_fail("你的化功大法火候不够，无法练抽髓掌。\n");
    if (me->query("family/family_name")!="星宿派")
		return notify_fail("你不加入星宿派，是无法学习这种阴毒的技能。\n");	
    if ((int)me->query("con", 1) < 20)
        return notify_fail("你的根骨太差，没法学习抽髓掌。\n");

	if (random(100)==1) me->add("score",-5);
	return 1;
}


int practice_skill(object me)
{
//	if (!wizardp(me))
//		return ("巫师突然从黑暗中冲了出来，对你大吼一声：该门派没开放。\n");	
	if (me->query("family/family_name")!="星宿派")
		return notify_fail("你不拍丁春秋的马屁，还敢私自练习这种阴毒的技能！\n");	
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 10)
		return notify_fail("你的内力不够练抽髓掌。\n");
	
	me->receive_damage("qi", 20);
	me->add("neili", -10);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int ap,dp,damage1,damage2,damage,liannum;
	ap = (me->query_skill("chousui-zhang", 1)+me->query_skill("huagong-dafa"))*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	dp = victim->query_skill("force",1)*(victim->query("breakup")+victim->query("breakup")*victim->query("breakup")+100)/100;
	damage1 = (int)me->query_skill("chousui-zhang",1);
	damage2 = (int)me->query_skill("chousui-zhang",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	if( me->query_temp("lianzhao")>=1) liannum=me->query_temp("lianzhao");
	else liannum =1;
    if ( me->query("neili") < 100 || me->query("jingli") < 100 || damage_bonus < 100) return 0;
	if ( me->query_skill("huagong-dafa",1) < 100 || me->query_skill("chousui-zhang",1) < 100) return 0;
//	if ( me->query_skill_mapped("force") != "huagong-dafa") return 0;	
	if (objectp(me->query_temp("weapon"))) return 0;

	if (random(7)==0 && me->query("jiali")>0 && random(ap)>dp/3)
	{
		damage = (damage1+damage_bonus)*(liannum+20)/(20*liannum+1);
		victim->add("neili",-damage);
		me->add("neili", -100 );
		return HIY "$n" HIY "感到内力如雪花融化一样，消失了。。\n" NOR;
	}
	if (random(7)==1 && me->query("jiali")>0 && random(ap)>dp/3) 
	{
		me->add("neili", -100 );
		victim->apply_condition("xx_poison",20);
		victim->apply_condition("sanpoison",20);
		victim->apply_condition("sanxiao_poison",20);
		return HIY "$n" HIY "感到肌肤便似腐烂一般，散发出一股极难闻的恶臭。。\n" NOR;
	}
	if( random(ap) > dp/3 && (int)me->query("jiajing")>0 && random(7)==2 && (int)me->query("breakup") )
	{
		damage = (damage2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("jingli",-100);
		victim->receive_damage("jing", damage,me);
		victim->receive_wound("jing", damage/3,me);
		message_vision(HIG "$N咬破舌尖，口吐一口鲜血，聚起"+me->query("cognize")+HIG"的力量击向$n。\n" NOR, me,victim,damage,HBWHT+HIR"特效伤精"NOR);
		return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiali")>0 && random(7)==3 && (int)me->query("jm/xingxiu") )
	{
		damage = ((damage1+damage2)/2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("neili",-100);
		victim->receive_damage("qi", damage,me);
		victim->receive_wound("qi", damage/3,me);
		message_vision(HIC "$N面露诡异的笑容，领悟星宿派武功的精妙所在，掌心一点绿火闪烁不定。\n" NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
		return ;
	}	
}
string perform_action_file(string action)
{
    return __DIR__"chousui-zhang/" + action;
}

	//2017.3.25阿飞封掉ob_hit特效，怀疑与伤害为0的死亡bug有关
int ob_hit(object ob, object me, int damage)
{
	string msg;
	int j, ap,dp,damage1,damage2;
	ap = ((int)me->query_skill("huagong-dafa")+(int)me->query_skill("chousui-zhang",1))*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	dp = (int)ob->query_skill("force",1)*(ob->query("breakup")+ob->query("breakup")*ob->query("breakup")+100)/100;
	damage1 = (int)me->query_skill("huagong-dafa",1)+(int)me->query_skill("chousui-zhang",1);
	damage2 = ((int)me->query_skill("huagong-dafa",1)+(int)me->query_skill("chousui-zhang",1))*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	if (damage <10)  damage=10;
    if ( me->query("neili") < 100 || me->query("jingli") < 100 ) return damage;
	if ( me->query_skill("huagong-dafa",1) < 100 || me->query_skill("chousui-zhang",1) < 100) return damage;
//	if ( me->query_skill_mapped("force") != "huagong-dafa") return damage;
	if (objectp(me->query_temp("weapon"))) return damage;

	if (random(8)==1 && random(ap)>dp/4 )
	{
		ob->add("neili",-damage1);
		if (ob->query("neili") < 0) ob->set("neili",0);
		me->add("neili", -100 );
		msg = HIY"$N掌心附有化功大法，$n的内力和攻击如雪花融化一样，消失了不少。\n"NOR;
		j = -(damage/2+random(damage));
		message_vision(msg, me, ob);
		return j;
	}
	if(random(ap) > dp/4 && random(8)==2 && (int)me->query("breakup")>1 )
	{
		j = -(damage+random(damage));
		ob->receive_damage("jing",damage2,me);
		ob->receive_wound("jing",damage2/2,me);
		me->add("jingli", -100 );
		message_vision(HIY"$N领悟"+me->query("cognize")+HIY"，掌力诡异，$n只觉得精气源源流失！\n"NOR, me, ob,damage2,HBWHT+HIY"精神反伤"NOR);	
		return j;
	}
	if(random(ap) > dp/4 && random(8)==3 && (int)me->query("jm/xingxiu") )
	{
		j = -(damage+random(damage));
		me->add("jing",damage2);
		if(me->query("jing")>me->query("eff_jing")) me->set("jing",me->query("eff_jing"));
		me->add("neili", -100 );
		message_vision(HIB"$N忽然使出星宿派不传之技，自己的精气大振！\n"NOR, me, ob);		
		return j;
	}	
}