// xiantian-qigong.c 先天气功	上乘武学400~1000
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit FORCE;

mapping *action = (
{
([      "action" : "$N单掌一抖，运聚先天功功力，呼啸着向$n的$l处拍去",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,	
"damage_type": "内伤"
	 ]),
([      "action" : "$N右掌平伸，左掌运起先天功的劲力，猛地拍向$n的$l",
		"attack":	500,
		"parry":	500,
		"dodge":	500,
		"damage":	500,
		"force":	500,
"damage_type": "内伤"
	 ]),
([      "action" : "$N身形一展，右掌护住心脉，左掌中攻直进，贯向$n$l",
		"attack":	600,
		"parry":	600,
		"dodge":	600,
		"damage":	600,
		"force":	600,	
"damage_type": "内伤"
	 ]),
([      "action" : "$N运转先天真气，双掌回圈，顿时一波澎湃的气劲直袭$n",
		"attack":	700,
		"parry":	700,
		"dodge":	700,
		"damage":	700,
		"force":	700,
"damage_type": "内伤"
	 ]),
([      "action" : "$N爆喝一声，张嘴吐出一口先天真气，如箭矢般刺向$n",
		"attack":	800,
		"parry":	800,
		"dodge":	800,
		"damage":	800,
		"force":	800,
"damage_type": "内伤"
	 ]),
([      "action" : "$N双掌快速击出，先天无极内劲不断的侵入$n五脏六腑",
		"attack":	900,
		"parry":	900,
		"dodge":	900,
		"damage":	900,
		"force":	900,
"damage_type": "内伤"
	 ]),
([      "action" : "$N双臂左旋右摆，双掌缓缓聚拢，掌心凝聚一团先天纯阳气劲直袭$n",
		"attack":	1000,
		"parry":	1000,
		"dodge":	1000,
		"damage":	1000,
		"force":	1000,
"damage_type": "内伤"
	 ]),
});

int valid_enable(string usage)
{
	return usage == "force";
}
//2019-1-1阿飞新规划，技能代码完善
//string valid_combine() { return "juehu-shou"; }		//互备技能
string skill_pinji() {return "上乘";}				//品级区分：上乘、中乘、下乘
string skill_xingbie() {return "通用";}				//性别区分：男性、女性、无性、通用
string skill_zhengxie() {return "正道";}			//正邪区分：正道、邪道、中立
string skill_menpai() {return "全真教";}				//门派区分：门派，江湖
string skill_yinyang() {return "阳";}				//阴阳区分：阳、阴、中性
string skill_zhenying() {return "正派";}			//阵营区分：正派、邪派、中立、通用
//int damage_damage() {return 60;}	//外伤系数
//int force_damage() {return 60;}		//内伤系数
int qi_heal() {return 80;}		//内功疗气系数
int jing_heal() {return 70;}		//内功疗精系数
int practice_level() {return 100;}	//自练级别
int practice_add() {return 100;}	//自练效率
int perform_level() {return 300;}	//PFM最低使用级别

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int ap,dp, damage1,damage2,damage,liannum;

    ap = me->query_skill("xiantian-qigong",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	dp = victim->query_skill("force",1)*(victim->query("breakup")+victim->query("breakup")*victim->query("breakup")+100)/100;
    damage1= (int) me->query_skill("xiantian-qigong",1);
	damage2 = (int)me->query_skill("xiantian-qigong",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	if( me->query_temp("lianzhao")>=1) liannum=me->query_temp("lianzhao");
	else liannum =1;
	if( me->query("neili") < 100 || me->query("jingli") < 100 || damage_bonus < 100 ) return 0;
	if ( me->query_skill("xiantian-qigong",1)<100) return 0;
	if ( me->query_skill_mapped("force") != "zixia-shengong") return 0;

	if (random(7)==1 && random(ap) > dp/3 && me->query("jiali") > 0)
	{
		damage = (damage1+damage_bonus)*(liannum+20)/(20*liannum+1);
		victim->receive_damage("qi", damage ,me);
		victim->receive_wound("qi", damage/3 ,me);
		me->add("neili", -100);
		if (!victim->is_busy()) victim->start_busy(1);
		message_vision(HIR"随着$N的攻击,一股先天纯阳真力瞬间爆发了出来，$n"HIR "只感五内俱焚，喉咙沙哑无比，不禁咳一口鲜血！\n" NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
        return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiajing")>0 && random(7)==2 && (int)me->query("breakup")>1 )
	{
		damage = (damage2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("jingli",-100);
		victim->receive_damage("jing", damage,me);
		victim->receive_wound("jing", damage/3,me);
		message_vision(HIG "$N顿悟"+me->query("cognize")+HIG"，纯阳真气遍布全身，$n甫一接触，$N的内劲趁势侵入$n经脉，$n哇的一声吐出一口精血。\n" NOR, me,victim,damage,HBWHT+HIR"特效伤精"NOR);
		return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiali")>0 && random(7)==3 && (int)me->query("jm/quanzhen") )
	{
		damage = ((damage1+damage2)/2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("neili",-100);
		victim->receive_damage("qi", damage,me);
		victim->receive_wound("qi", damage/3,me);
		message_vision(HIM"$N贯通全真教内功精髓，纯阳内劲势如破竹，进入$n经脉，$n顿时一口鲜血吐出。\n" NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
		return ;
	}
}
//2017.3.25阿飞封掉ob_hit特效，怀疑与伤害为0的死亡有关
int ob_hit(object ob, object me, int damage)
{
	string msg;
	int ap,dp,j,damage1,damage2;

	ap = me->query_skill("xiantian-qigong", 1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	dp = ob->query_skill("unarmed",1)*(ob->query("breakup")+ob->query("breakup")*ob->query("breakup")+100)/100;
	damage1 = me->query_skill("xiantian-qigong", 1);
	damage2 = me->query_skill("xiantian-qigong", 1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	if( damage < 10 ) damage=10;
	if( me->query("neili") < 100 || me->query("jingli") < 100 ) return damage;
	if (me->query_skill("xiantian-qigong", 1) < 300) return damage;
	if (me->query_skill_mapped("force")!="xiantian-qigong" ) return damage;
	if ( random(8) == 1 && random(ap) > dp/4 )
	{
        msg = HIR "只见$N" HIR "先天护体神功自然而然发动，将$n" HIR "的攻击化为无形。\n" NOR;
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
		message_vision(HIY"$N顿悟"+me->query("cognize")+HIY"，只见$N" HIY "先天护体神功自然而然发动，抵抗$n" HIY "的攻击。\n"NOR, me, ob,damage2,HBWHT+HIY"精神反伤"NOR);
		return j;
	}
	if(random(ap) > dp/4 && random(8)==3 && (int)me->query("jm/quanzhen") )
	{
		j = -(damage/3+random(damage/3));
		ob->receive_damage("qi",damage1,me);
		ob->receive_wound("qi",damage1/2,me);
		me->add("neili", -100 );
		message_vision(HIB"$N贯通全真教先气功精髓。只见$N" HIB "先天护体神功灌注全身，将$n" HIB "的力道尽数反震回去。\n"NOR, me, ob,damage1,HBWHT+HIY"气血反伤"NOR);
		return j;
	}
}


int valid_learn(object me)
{
	mapping skl;
	string *sname;
	int i;
	int lvl = (int)me->query_skill("xiantian-qigong", 1);
	int t = 1, j;
	if (lvl<=100)
		for (j = 1; j < lvl / 10; j++)
			t*=2;
//	if (!wizardp(me))
//		return ("巫师突然从黑暗中冲了出来，对你大吼一声：该门派没开放。\n");	
	if ( me->query("gender") == "无性")
		return notify_fail("你无根无性，阴阳不调，难以修行玄门正宗的先天气功。\n");
	if ( me->query("class") == "bonze" )
		return notify_fail(RANK_D->query_respect(me)+"欲修我道家玄门气功，怎又去入了佛门？\n");
	
	
	if ((int)me->query_skill("force", 1) < 30)
		return notify_fail("你的基本内功火候还不够。\n");
	if ((int)me->query("con", 1) < 30)
		return notify_fail("先天功需要极高的根骨才能修炼。\n");	
	if ((int)me->query_skill("xiantian-gong", 1) > 3000)
		return notify_fail("上乘武学只能教到这里了，以后要靠自己勤加修习领悟。\n");		
	
	
	if(lvl<=100)
	{
		if (lvl > 10 && (int)me->query("shen") < t * 100)
			return notify_fail("你的侠义正气太低了。\n");
	}
	else
	{
		if ((int)me->query("shen") < (51200 + (lvl - 100) * 1000))
			return notify_fail("你的侠义正气太低了。\n");
	}
	skl = this_player()->query_skills();
	sname  = keys(skl);
	for (i=0; i<sizeof(skl); i++)
	{
		if (sname[i]=="xixing-dafa") continue;
		if (sname[i]=="yijing-force") continue;
		if (sname[i]=="xiantian-gong") continue;
		if (sname[i]=="tiangang-zhengqi") continue;
		if( SKILL_D(sname[i])->valid_enable("force") )
			return notify_fail("你不先散了别派内功，怎能学先天功？！\n");
	}
	if (random(10)==1) me->add("score",-5);		
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("先天气功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"xiantian-gong/" + func;
}

int force_character(string char_type)
{
	int recv;
	recv=::force_character(char_type);
	switch(char_type)
	{
	  case "TYPE_DEC_SPD":        //TYPE_DEC_SPD
	  	return 80;
	  case "TYPE_FORCE":        //TYPE_FORCE
	  	return 250;
    case "TYPE_SHIELD_NEILI":
      return 10;
	  default:
	  	return recv;
	}
}
mapping buffer_applied(object ob)
{
    mapping buf, tbuf;
    int lv1, lv2, gint, pflv;
    
    lv1=ob->query_skill("xiantian-gong",1);
    lv2=ob->query_skill("daoxue-xinfa",1);
    gint=ob->query("con");
    buf=([]);
    
  if ( ob->query_attr_version()<140913 )
      return buf;

    if ( lv1<=60 || lv2<=60 )
      return buf;
      
    if ( mapp(ob->query_temp("passive/xiantian-gong")) )
      return buf;
    
	

    buf["max_qi"]=(lv2/5 + lv1/5)*(100+gint)*2/5;
	 buf["armor"]=(lv2/20 + lv1/10)*(100+gint)*1/5;
    buf["max_jing"]=(lv2/5 + lv1/5)*(100+gint)*3/5;
    ob->set_temp("passive/xiantian-gong", buf);
    ob->set_temp("active_force_buffer/xiantian-gong/name", "先天功");                              //buff名称
    ob->set_temp("active_force_buffer/xiantian-gong/effect1", "最大气血+"+(buf["max_qi"])+"点");     //效果描述1
    ob->set_temp("active_force_buffer/xiantian-gong/effect2", "最大精神+"+(buf["max_jing"])+"点");
    ob->set_temp("active_force_buffer/xiantian-gong/effect3", "防御+"+(buf["armor"])+"点");	//效果描述2
	
    return buf;
}
mapping buffer_removed(object ob)
{
    mapping buf;
    
    buf=ob->query_temp("passive/xiantian-gong");;
    if ( mapp(buf) )
    {
      buf["max_qi"]=buf["max_qi"]*(-1);
      buf["max_jing"]=buf["max_jing"]*(-1);
	  buf["AllPoisonsImmune"]=buf["AllPoisonsImmune"]*(-1);
	  buf["anti_all_busy"] = buf["anti_all_busy"]*(-1);
	  buf["armor"] = buf["armor"]*(-1);
    }
    else
      buf=([]);

    ob->delete_temp("passive/xiantian-gong");
    ob->delete_temp("active_force_buffer/xiantian-gong");
    return buf;
}

mapping exercise_msg(object me)
{
	return ([
        "status_msg" : "脸上如一泓湖水般淡然自如。\n" ,
        "start_my_msg" : "盘膝而坐，开始吐纳练气，忽有白云氤氲于身周，从微白而至浩白，从光小而至光大，从波动而至光定，从不圆而至光圆。\n",
        "start_other_msg" :  me->name() + "盘膝而坐，忽有白云氤氲于身周，从微白而至浩白，从光小而至光大，从波动而至光定，从不圆而至光圆。\n",
        "heal_my_msg" : "心守太虚，意照气穴，开始运功疗伤。\n",
        "heal_other_msg" :  me->name() + "盘膝坐下吐气疗伤，心守太虚，意照气穴，云若微光，不即不离。\n",
        "halt_msg" :  "长出一口气，将内息急速退了回去，站了起来。\n",
        "end_my_msg" : "将内息走了个小周天，一切动静之间，心如泰山，不动不摇。\n",
        "end_other_msg" : "只见"+me->name() + "运功完毕，身周白云渐渐消失。\n",		
        "hover_my_msg" : "将内息走了个小周天，流回丹田，顿觉伤势恢复了许多。\n",
        "hover_other_msg" : "只见笼罩"+me->name() + "疗伤完毕，白雾见薄，轻烟袅袅似云般绕"+me->name() + "身周久久不散。\n",	
    ]);
}
