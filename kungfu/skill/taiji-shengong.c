// taiji-shengong.c 太极神功
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit FORCE;
int valid_enable(string usage)
{
	return usage == "force";
}
//2019-1-1阿飞新规划，技能代码完善
//string valid_combine() { return "juehu-shou"; }		//互备技能
string skill_pinji() {return "上乘";}				//品级区分：上乘、中乘、下乘
string skill_xingbie() {return "通用";}				//性别区分：男性、女性、无性、通用
string skill_zhengxie() {return "正道";}			//正邪区分：正道、邪道、中立
string skill_menpai() {return "武当派";}				//门派区分：门派，江湖
string skill_yinyang() {return "中性";}				//阴阳区分：阳、阴、中性
string skill_zhenying() {return "正派";}			//阵营区分：正派、邪派、中立、通用
//int damage_damage() {return 50;}	//外伤系数
//int force_damage() {return 50;}		//内伤系数
int qi_heal() {return 80;}		//内功疗气系数
int jing_heal() {return 50;}		//内功疗精系数
int practice_level() {return 100;}	//自练级别
int practice_add() {return 100;}	//自练效率
int perform_level() {return 300;}	//PFM最低使用级别

int valid_learn(object me)
{
	mapping skl;
	string *sname;
	int lvl = (int)me->query_skill("taiji-shengong", 1);
	int t = 1, i;
	if (lvl<=100)     t=lvl*lvl;
	
//	if (!wizardp(me))
//		return ("巫师突然从黑暗中冲了出来，对你大吼一声：该门派没开放。\n");	
	if ( me->query("gender") == "无性" && lvl > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的太极神功。\n");
	if ( me->query("class") == "bonze" )
		return notify_fail("太极神功讲究阴阳调合，有违佛家六根清净之意，" +RANK_D->query_respect(me)+"欲修此功，已是罪过。\n");
    if (me->query("family/family_name")!="武当派")
		return notify_fail("你不是武当弟子，无法学习太极神功。\n");						   
	if ((int)me->query_skill("force", 1) < 50)
		return notify_fail("你的基本内功火候还不够。\n");
	if ((int)me->query_skill("taiji-shengong", 1) > 3000)
		return notify_fail("上乘武学只能教到这里了，以后要靠自己勤加修习领悟。\n");		
	
    if ((int)me->query_skill("force",1)<=(int)me->query_skill("taiji-shengong", 1))
        return notify_fail("你的基本内功基础不够，再学下去会走火入魔的。\n");	

	
	/*if(lvl<=100)
	{
		if (lvl > 10 && (int)me->query("shen") < t * 20)
			return ("你的侠义正气太低了。\n");
	}
	else
	{
		if ((int)me->query("shen") < (51200 + (lvl - 100) * 2000))
			return ("你的侠义正气太低了。\n");
	}*/
	if (me->query_skill("force",1)<=lvl)
		return notify_fail("你的基本内功基础不够，再学下去会走火入魔的。\n");
	skl = me->query_skills();
	sname  = keys(skl);
	for (i=0; i<sizeof(skl); i++)
	{
		if (sname[i]=="xixing-dafa") continue;
		if (sname[i]=="taiji-shengong") continue;
		if (sname[i]=="yijing-force") continue;
		if (sname[i]=="yinyun-ziqi") continue;		
		if( SKILL_D(sname[i])->valid_enable("force") )
			return notify_fail("你不先散了别派内功，怎能学太极神功？！\n");
	}
	if (random(100)==1) me->add("score",-5);			
	return 1;
}
int practice_skill(object me)
{
	return notify_fail("太极神功只能用学(learn)的来增加熟练度。\n");
}
string exert_function_file(string func)
{
	return __DIR__"taiji-shengong/" + func;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int ap,dp, damage1,damage2,damage,liannum;

    ap = me->query_skill("taiji-shengong",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	dp = victim->query_skill("force",1)*(victim->query("breakup")+victim->query("breakup")*victim->query("breakup")+100)/100;
    damage1= (int) me->query_skill("taiji-shengong",1);
	damage2 = (int)me->query_skill("taiji-shengong",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	if( me->query_temp("lianzhao")>=1) liannum=me->query_temp("lianzhao");
	else liannum =1;	
	if( me->query("neili") < 100 || me->query("jingli") < 100 || damage_bonus < 100 ) return 0;
	if ( me->query_skill("taiji-shengong",1) < 100 ) return 0;
	if ( me->query_skill_mapped("force") != "taiji-shengong") return 0;

	if (random(7)==1 && random(ap) > dp/3 && me->query("jiali") > 0)
	{
		damage = (damage1+damage_bonus)*(liannum+20)/(20*liannum+1);
		victim->receive_damage("qi", damage ,me);
		victim->receive_wound("qi", damage/3 ,me);
		me->add("neili", -100);
		message_vision(HIR"太极动而生阳，动极而静，静而生阴，静极复动，阴阳交泰！$n被阴阳鱼震的十分难受，“哇”的一声吐出一口血！\n" NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
        return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiajing")>0 && random(7)==2 && (int)me->query("breakup")>1 )
	{
		damage = (damage2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("jingli",-100);
		victim->receive_damage("jing", damage,me);
		victim->receive_wound("jing", damage/3,me);
		message_vision(HIG "$N顿悟"+me->query("cognize")+HIG"，动静由心，似慢实快，以太极之柔克敌之刚。\n" NOR, me,victim,damage,HBWHT+HIR"特效伤精"NOR);
		return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiali")>0 && random(7)==3 && (int)me->query("jm/wudang") )
	{
		damage = ((damage1+damage2)/2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("neili",-100);
		victim->receive_damage("qi", damage,me);
		victim->receive_wound("qi", damage/3,me);
		message_vision(HIM"$N领悟武当太极之道，劲气连绵不息，携$n之力道反击$n，将$n震的闷哼一声。\n" NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
		return ;
	}
}
int force_character(string char_type)
{
	int recv;
	recv=::force_character(char_type);
	switch(char_type)
	{
	  case "TYPE_DEC_SPD":     //TYPE_DEC_SPD
	  	return 80;
	  case "TYPE_FORCE":     //TYPE_FORCE
	  	return 250;
    case "TYPE_SHIELD_DEF":
      return 3;
    case "TYPE_SHIELD_NEILI":
      return 3;
	  default:
	  	return recv;
	}
}

mapping buffer_applied(object ob)
{
    mapping buf, tbuf;
    int level, lv2;
    
    level=ob->query_skill("taiji-shengong",1);
    lv2=ob->query_skill("taoism",1);
    buf=([]);

//attribute的版本低于140913则效果无法生效    
    if ( ob->query_attr_version()<140913 )
      return buf;
    
    if ( level<=60 || lv2<=40 )
      return buf;
      
    if ( mapp(ob->query_temp("passive/taiji-shengong")) )
      return buf;
    
    buf["max_qi"]=(lv2/2)*level/60;
    ob->set_temp("passive/taiji-shengong", buf);
    ob->set_temp("active_force_buffer/taiji-shengong/name", "太极神功");                              //buff名称
    ob->set_temp("active_force_buffer/taiji-shengong/effect1", "最大气血+"+(buf["max_qi"])+"点");     //效果描述1
    return buf;
}

mapping buffer_removed(object ob)
{
    mapping buf;
    
    buf=ob->query_temp("passive/taiji-shengong");;
    if ( mapp(buf) )
    {
      buf["max_qi"]=buf["max_qi"]*(-1);
    }
    else
      buf=([]);

    ob->delete_temp("passive/taiji-shengong");
    ob->delete_temp("active_force_buffer/taiji-shengong");
    return buf;
}

/*
mapping exercise_msg(object me)
{
  return ([
        "status_msg" : "脸上红光隐现，气象庄严。\n" ,
        "start_my_msg" : "盘膝坐下，右手食指指天，左手食指指地，口中“嘿”的一声，鼻孔中喷出了两条淡淡白气。\n",
        "start_other_msg" :  me->name() + "盘膝坐下，右手食指指天，左手食指指地，口中“嘿”的一声，鼻孔中喷出了两条淡淡白气。\n",
        "heal_my_msg" : "吐出来的白气缠住脑袋周围，缭绕不散，渐渐愈来愈浓，逐渐成为一团白雾，将你面目全都遮没了。\n",
        "heal_other_msg" :  me->name() + "吐出来的白气缠住"+ me->name() + "脑袋周围，缭绕不散，渐渐愈来愈浓，逐渐成为一团白雾，将"+ me->name() + "面目全都遮没了。\n",
        "halt_msg" :  "长出一口气，将内息急速退了回去，站了起来。\n",
        "end_my_msg" : "鼻孔中不断吸入白雾，待得白雾吸尽，你睁开双眼，缓缓站起。\n",
        "end_other_msg" : me->name()+"鼻孔中不断吸入白雾，待得白雾吸尽，"+me->name()+"睁开双眼，缓缓站起。\n",		
        "hover_my_msg" : "全身骨节格格作响，犹如爆豆。过了良久，爆豆声渐轻渐稀，跟着那团白雾也渐渐淡了。\n",
        "hover_other_msg" : "只听得"+me->name()+"全身骨节格格作响，犹如爆豆。过了良久，爆豆声渐轻渐稀，跟着那团白雾也渐渐淡了。\n",	
    ]);
}
*/