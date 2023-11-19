//liumai-shenjian.c 六脉神剑	上乘武学400~1000
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit SKILL;
int lvl_temp;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
string  *msg = ({
"$N手臂陡然一提，对$n发起攻击，手掌离$n不到一尺，立即变掌为指，使出"RED"「少泽剑」"NOR"，忽来忽去，变化精微，只见一股剑气从左小指激射而出，击向$n的$l",

"$N双掌自外向里划了一个圈，双掌托在胸前，伸出右小指，一招"RED"「少冲剑」"NOR"，缓缓地点向$n的周身大穴，弹指无声，到得近前，劲气弥漫，破空之声甚厉",

"$N长笑一声，右手硬生生缩回，左手横斩而至，俯身斜倚，无名指弹出，一式"RED"「关冲剑」"NOR"，拙滞古朴，奇正有别，指尖已对准$n的$l发出了一缕强烈的劲风",

"$N食指连动，快速无比，格开对方来势，变招奇速，如毒蛇出洞，疾从袖底穿出，大喝一声，使出"RED"「商阳剑」"NOR"，双手幻出无数指影，巧妙灵活，难以琢磨，拂向$n的$l",

"两指之间，相距只是电光般一闪，$N一翻掌，身向右移，奋起神威，右手斗然探出，中指一竖，一招"RED"「中冲剑」"NOR"，迅疾的向$n的$l划去，大开大合，气势雄伟",

"$N身子倒飞，嗤嗤两指，从容不迫地架开来势，大拇指使出"RED"「少商剑」"NOR"，按向$n的$l，劲道使得甚巧，初缓后急，剑气如怒潮般汹涌而至，剑路雄劲，石破天惊",

});

mapping *action = ({
([	"action" : "$N身子倒飞，嗤嗤两指，从容不迫地架开来势，大拇指使出"RED"「少商剑」"NOR"，按向$n的$l，劲道使得甚巧，初缓后急，剑气如怒潮般汹涌而至，剑路雄劲，石破天惊",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,	
	"skill_name" : "初杏问酒",
           "weapon" : "破体无形剑气",
           "damage_type":  "刺伤"
]),
([	"action" : "两指之间，相距只是电光般一闪，$N一翻掌，身向右移，奋起神威，右手斗然探出，中指一竖，一招"RED"「中冲剑」"NOR"，迅疾的向$n的$l划去，大开大合，气势雄伟",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,	
	"skill_name" : "叶底留莲",
           "weapon" : "破体无形剑气",
           "damage_type":  "刺伤"
]),
([	"action" : "$N食指连动，快速无比，格开对方来势，变招奇速，如毒蛇出洞，疾从袖底穿出，大喝一声，使出"RED"「商阳剑」"NOR"，双手幻出无数指影，巧妙灵活，难以琢磨，拂向$n的$l",
		"attack":	400,
		"parry":	400,
		"dodge":	400,
		"damage":	400,
		"force":	400,	
	"skill_name" : "清风拂桂",
           "weapon" : "破体无形剑气",
           "damage_type":  "刺伤"
]),
([	"action" : "$N长笑一声，右手硬生生缩回，左手横斩而至，俯身斜倚，无名指弹出，一式"RED"「关冲剑」"NOR"，拙滞古朴，奇正有别，指尖已对准$n的$l发出了一缕强烈的劲风",
		"attack":	500,
		"parry":	500,
		"dodge":	500,
		"damage":	500,
		"force":	500,
	"skill_name" : "菊圃秋霜",
           "weapon" : "破体无形剑气",
           "damage_type":  "刺伤"
]),
([	"action" : "$N双掌自外向里划了一个圈，双掌托在胸前，伸出右小指，一招"RED"「少冲剑」"NOR"，缓缓地点向$n的周身大穴，弹指无声，到得近前，劲气弥漫，破空之声甚厉",
		"attack":	500,
		"parry":	500,
		"dodge":	500,
		"damage":	500,
		"force":	500,
	"skill_name" : "伽叶微笑",
           "weapon" : "破体无形剑气",
           "damage_type":  "刺伤"
]),
([	"action" : "$N手臂陡然一提，对$n发起攻击，手掌离$n不到一尺，立即变掌为指，使出"RED"「少泽剑」"NOR"，忽来忽去，变化精微，只见一股剑气从左小指激射而出，击向$n的$l",
		"attack":	500,
		"parry":	500,
		"dodge":	500,
		"damage":	500,
		"force":	500,
	"skill_name" : "佛祖拈花",
           "weapon" : "破体无形剑气",
           "damage_type":  "刺伤"
]),
([ "name":   "少商剑",
           "action": "$N反过手来，双手拇指同时捺出，嗤嗤两声急响，“少商剑”有如石破天惊、风雨大至之势，分指$n膻中和$l",
		"attack":	600,
		"parry":	600,
		"dodge":	600,
		"damage":	600,
		"force":	600,
        "weapon" : "破体无形剑气",
           "damage_type":  "刺伤"
        ]),
([      "name":   "少商剑",
        "action": "$N大拇指一按，嗤嗤两指，劲道使得甚巧，「" HIW "少商剑" NOR "」剑气"
                  "如怒潮般涌至",
		"attack":	600,
		"parry":	600,
		"dodge":	600,
		"damage":	600,
		"force":	600,
        "weapon" : HIW "少商剑气" NOR,
        "damage_type":  "刺伤"
]),
([      "name":   "少商剑",
        "action": "$N大拇指连挥，「" HIW "少商剑" NOR "」便如是一幅泼墨山水，纵横倚斜"
                  "，剑路雄劲",
		"attack":	600,
		"parry":	600,
		"dodge":	600,
		"damage":	600,
		"force":	600,
        "weapon" : HIW "少商剑气" NOR,
        "damage_type":  "刺伤"
]),
([      "name":   "少商剑",
        "action": "$N双手拇指同时捺出，「" HIW "少商剑" NOR "」大开大阖，气派宏伟，每"
                  "一剑都有风雨大至之势",
		"attack":	600,
		"parry":	600,
		"dodge":	600,
		"damage":	600,
		"force":	600,
        "weapon" : HIW "少商剑气" NOR,
        "damage_type":  "刺伤"
]),
        ([ "name":   "商阳剑",
           "action": "$N食指连动，手腕园转，“商阳剑”一剑又一剑的刺出，轻灵迅速，奇巧活泼，剑气纵横，$n根本无法看清来路",
		"attack":	600,
		"parry":	600,
		"dodge":	600,
		"damage":	600,
		"force":	600,
        "weapon" : "破体无形剑气",
        "damage_type":  "刺伤"
        ]),
([      "name":   "商阳剑",
        "action": "$N变招奇速，右手食指疾从袖底穿出，「" HIW "商阳剑" NOR "」登时幻出"
                  "无数指影",
		"attack":	600,
		"parry":	600,
		"dodge":	600,
		"damage":	600,
		"force":	600,
        "weapon" : HIW "商阳剑气" NOR,
        "damage_type":  "刺伤"
]),
([      "name":   "商阳剑",
        "action": "$N拇指一屈，食指随即点出，嗤嗤两声急响，变成商阳剑法，「" HIW "商"
                  "阳剑" NOR "」激射刺出",
		"attack":	600,
		"parry":	600,
		"dodge":	600,
		"damage":	600,
		"force":	600,
        "weapon" : HIW "商阳剑气" NOR,
        "damage_type":  "刺伤"
]),
([      "name":   "商阳剑",
        "action": "$N以食指急运「" HIW "商阳剑" NOR "」之无形剑气，却不过是手指在数寸"
                  "范围内一点一戳",
		"attack":	600,
		"parry":	600,
		"dodge":	600,
		"damage":	600,
		"force":	600,
        "weapon" : HIW "商阳剑气" NOR,
        "damage_type":  "刺伤"
]),
        ([ "name":   "中冲剑",
           "action": "$N右手中指一竖，“中冲剑”向前刺出。真气鼓荡，嗤然声响，无形剑气直指$n的$l",
		"attack":	600,
		"parry":	600,
		"dodge":	600,
		"damage":	600,
		"force":	600,
        "weapon" : "破体无形剑气",
        "damage_type":  "刺伤"
        ]),
([      "name":   "中冲剑",
        "action": "$N将中指向上一刺，「" HIW "中冲剑" NOR "」拔地而起，接着手指向下一"
                  "划，剑气如利刀般砍出",
		"attack":	700,
		"parry":	700,
		"dodge":	700,
		"damage":	700,
		"force":	700,
        "weapon" : HIW "中冲剑气" NOR,
        "damage_type":  "刺伤"
]),
([      "name":   "中冲剑",
        "action": "电光火石之间，$N猛然翻掌，右手陡然探出，中指「" HIW "中冲剑" NOR
                  "」向$n一竖",
		"attack":	700,
		"parry":	700,
		"dodge":	700,
		"damage":	700,
		"force":	700,
        "weapon" : HIW "中冲剑气" NOR,
        "damage_type":  "刺伤"
]),
([      "name":   "关冲剑",
        "action": "$N右手无名指伸出，「" HIW "关冲剑" NOR "」剑路拙滞古朴，一股雄浑无"
                  "比的内力鼓荡而出",
		"attack":	700,
		"parry":	700,
		"dodge":	700,
		"damage":	700,
		"force":	700,
        "weapon" : HIW "关冲剑气" NOR,
        "damage_type":  "刺伤"
]),
([      "name":   "关冲剑",
        "action": "$N俯身斜倚，无名指「" HIW "关冲剑" NOR "」弹射而出，指尖已对准$n发"
                  "出了一缕强烈的劲风",
		"attack":	700,
		"parry":	700,
		"dodge":	700,
		"damage":	700,
		"force":	700,
        "weapon" : HIW "关冲剑气" NOR,
        "damage_type":  "刺伤"
]),
([      "name":   "关冲剑",
        "action": "$N无名指轻轻一挥，「嗤啦」一声，拙滞古朴的「" HIW "关冲剑" NOR "」"
                  "剑气向$n直射而出",
		"attack":	800,
		"parry":	800,
		"dodge":	800,
		"damage":	800,
		"force":	800,
        "weapon" : HIW "关冲剑气" NOR,
        "damage_type":  "刺伤"
]),
        ([ "name":   "关冲剑",
           "action": "$N右手无名指伸出，“关冲剑”剑路拙滞古朴，一股雄浑的内力鼓荡而出，如排山倒海般向$n涌去",
		"attack":	800,
		"parry":	800,
		"dodge":	800,
		"damage":	800,
		"force":	800,
           "damage_type":  "刺伤"
        ]),
        ([ "name":   "少泽剑",
           "action": "$N左手小指一伸，一条气流从少冲穴中激射而出，“少泽剑”出手入风，指向$n的$l",
		"attack":	800,
		"parry":	800,
		"dodge":	800,
		"damage":	800,
		"force":	800,
           "weapon" : "破体无形剑气",
           "damage_type":  "刺伤"
        ]),
([      "name":   "少泽剑",
        "action": "忽见$N左手小指一伸，一条气流从$P少冲穴中激射而出，一股「" HIW "少"
                  "泽剑" NOR "」登时射向$n",
		"attack":	800,
		"parry":	800,
		"dodge":	800,
		"damage":	800,
		"force":	800,
        "weapon" : HIW "少泽剑气" NOR,
        "damage_type":  "刺伤"
]),
        ([ "name":   "少冲剑",
           "action": "$N右手反指，小指伸出，真气自少冲穴激荡而出，“少泽剑”横生奇变，从$n意想不到的方向刺向$n的$l",
		"attack":	800,
		"parry":	800,
		"dodge":	800,
		"damage":	800,
		"force":	800,
        "weapon" : "破体无形剑气",
        "damage_type":  "刺伤"
        ]),
([      "name":   "少冲剑",
        "action": "$N掌托于胸前，伸出右小指，一招「" HIW "少冲剑" NOR "」缓缓地点向$n"
                  "的周身大穴",
		"attack":	800,
		"parry":	800,
		"dodge":	800,
		"damage":	800,
		"force":	800,
        "weapon" : HIW "少冲剑气" NOR,
        "damage_type":  "刺伤"
]),
([      "name":   "少冲剑",
        "action": "$N小指一弹，「" HIW "少冲剑" NOR "」化式「分花拂柳」，剑势如同柳絮"
                  "一般，飘而不乱",
		"attack":	800,
		"parry":	800,
		"dodge":	800,
		"damage":	800,
		"force":	800,
        "weapon" : HIW "少冲剑气" NOR,
        "damage_type":  "刺伤"
]),
([      "name":   "少冲剑",
        "action": "$N一招「" HIW "少冲剑" NOR "」，剑气回转无定形，竟从左侧绕了过来，"
                  "点向$n",
		"attack":	900,
		"parry":	900,
		"dodge":	900,
		"damage":	900,
		"force":	900,
        "weapon" : HIW "少冲剑气" NOR,
        "damage_type":  "刺伤"
]),
([      "name":   "少冲剑",
        "action": "$N右手小指一挥，一招「" HIW "少冲剑" NOR "」点点刺刺破空刺出，宛如"
                  "雕花刺画一般",
		"attack":	900,
		"parry":	900,
		"dodge":	900,
		"damage":	900,
		"force":	900,
        "weapon" : HIW "少冲剑气" NOR,
        "damage_type":  "刺伤"
]),
([      "name":   "六脉剑",
        "action": "$N双手手指齐动，连发六道剑气，一招「" HIW "六脉剑" NOR "」刺出，六道如龙剑气"
                  "将$n退路封住，无从闪避",
		"attack":	1000,
		"parry":	1000,
		"dodge":	1000,
		"damage":	1000,
		"force":	1000,
        "weapon" : HIW "六脉剑气" NOR,
        "damage_type":  "刺伤"
]),
});


int valid_enable(string usage) { return usage=="finger" ||  usage=="unarmed"||  usage=="parry"; }
//2019-1-1阿飞新规划，技能代码完善
string valid_combine() { return "liuyin-guimai"; }		//互备技能
string skill_pinji() {return "上乘";}				//品级区分：上乘、中乘、下乘
string skill_xingbie() {return "通用";}				//性别区分：男性、女性、无性、通用
string skill_zhengxie() {return "中立";}			//正邪区分：正道、邪道、中立
string skill_menpai() {return "大理段家";}				//门派区分：门派，江湖
string skill_yinyang() {return "阳";}				//阴阳区分：阳、阴、中性
string skill_zhenying() {return "中立";}			//阵营区分：正派、邪派、中立、通用
int damage_damage() {return 84;}	//外伤系数
int force_damage() {return 62;}		//内伤系数
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
		return notify_fail("练六脉神剑必须空手。\n");
			
	if ((int)me->query_skill("force", 1) < 100)
		return notify_fail("你的基本内功火候不够，无法学六脉神剑。\n");
    if ( (int)me->query_skill("beiming-shengong", 1) < 30)		
        return notify_fail("没有独门内功支持，学不了六脉神剑。\n");	
	if ((int)me->query_skill("yiyang-zhi", 1) < 30)
		return notify_fail("你的连一阳指都不会，如何能学六脉。\n");	
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力修为太弱，无法修炼六脉神剑。\n");
	if ((int)me->query_skill("liumai-shenjian", 1) > (int)me->query_skill("yiyang-zhi", 1))	
		return notify_fail("六脉神剑要以一阳指为基础才行吧。\n");			
	if ((int)me->query_skill("liumai-shenjian", 1) > 3000)	
		return notify_fail("上乘武学只能教到这里了，以后要靠自己勤加修习领悟。\n");
    if (me->query_skill("finger", 1) <=me->query_skill("liumai-shenjian", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
	
	if (random(10)==1) me->add("score",-10);
        return 1;
}
/*
int valid_learn(object me)
{
     return ("六脉神剑只能研习剑谱来提高。\n");
}*/

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
	if(level >= action[i-1]["lvl"])
		return action[i-1]["skill_name"];
}

int practice_skill(object me)
{
//	if (!wizardp(me))
//		return ("巫师突然从黑暗中冲了出来，对你大吼一声：该门派没开放。\n");	
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练六脉神剑必须空手。\n");
	if ((int)me->query("qi") < 50)
        return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 80)
        return notify_fail("你的内力不够练六脉神剑!\n");
	if ((int)me->query_skill("liumai-shenjian",1) < 200)
        return notify_fail("你的六脉神剑学的太浅显了，无法练习!\n");	
	if ((int)me->query_skill("liumai-shenjian",1) > (int)me->query_skill("finger",1))
        return notify_fail("你的基本指法太差了!\n");	
	if ((int)me->query_skill("liumai-shenjian",1) > (int)me->query_skill("force",1))
        return notify_fail("你的基本内功太差了!\n");				
	if ((int)me->query_skill("liumai-shenjian",1) > (int)me->query_skill("yiyang-zhi",1))
        return notify_fail("六脉神剑要以一阳指为基础，先将一阳指练好了再说吧!\n");			
	
	me->receive_damage("qi", 40);
	me->add("neili", -70);
	return 1;
}
                                          
mixed hit_ob(object me, object victim,int damage_bonus)       
{	
	int ap,dp,damage1,damage2,damage,liannum;
	damage1 = (int)me->query_skill("liumai-shenjian",1);
	damage2 = (int)me->query_skill("liumai-shenjian",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	ap = me->query_skill("liumai-shenjian",1)*(me->query("breakup")+me->query("breakup")*me->query("breakup")+100)/100;
	dp = victim->query_skill("force",1)*(victim->query("breakup")+victim->query("breakup")*victim->query("breakup")+100)/100;
	if( me->query_temp("lianzhao")>=1) liannum=me->query_temp("lianzhao");
	else liannum =1;
	if( me->query("neili") < 100 || me->query("jingli") < 100 || damage_bonus < 100 ) return 0;
	if ( ( me->query_skill("kumu-shengong",1) < 100 && me->query_skill("beiming-shengong",1) < 100) || me->query_skill("liumai-shenjian",1)<100) return 0;
//	if (me->query_skill_mapped("force") != "kumu-shengong" && me->query_skill_mapped("force") != "beiming-shengong" ) return 0;
	if (objectp(me->query_temp("weapon")) ) return 0;
	
	if (random(7)==1 && random(ap) > dp/3 && me->query("jiali") > 0)
	{
		damage = (damage1+damage_bonus)*(liannum+20)/(20*liannum+1);
		victim->receive_damage("qi", damage ,me);
		victim->receive_wound("qi", damage/3 ,me);
		me->add("neili", -100);
		victim->add("neili", -damage1);
		message_vision(HIR "只听噗的一声，$n气海穴一痛，紧接着一股鲜血从$n的身子喷出！\n" NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
        return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiajing")>0 && random(7)==2 && (int)me->query("breakup")>1 )
	{
		damage = (damage2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("jingli",-100);
		victim->add("jingli", -damage2);
		victim->receive_damage("jing", damage,me);
		victim->receive_wound("jing", damage/3,me);
		message_vision(HIG "$N顿悟"+me->query("cognize")+HIG"，左右手齐出，两道剑气一前一后，一股鲜血从$n身上溅出。\n" NOR, me,victim,damage,HBWHT+HIR"特效伤精"NOR);
		return ;
	}
	if( random(ap) > dp/3 && (int)me->query("jiali")>0 && random(7)==3 && (int)me->query("breakup")>1 )
	{
		damage = ((damage1+damage2)/2+damage_bonus)*(liannum+20)/(20*liannum+1);
		me->add("neili",-100);
		victim->add("neili", -damage1);
		victim->receive_damage("qi", damage,me);
		victim->receive_wound("qi", damage/3,me);
		message_vision(HIM"$N洞悉天龙寺武功精髓，六指连环射出剑气，「嗤啦」一声轻响，$n竟飞出数道血花！\n" NOR, me,victim,damage,HBWHT+HIR"特效伤气"NOR);
		return ;
	}

}
string query_parry_msg(object victim_weapon)
{
	switch (random(4))
	{
        case 0:
                return "$n随意挥洒，道道剑气纵横交错，宛若天网，$N唯有望洋兴叹，徒呼奈何。\n";
        case 1:
                return "$n不闪不避，一招中冲剑直袭$N的胸前大穴，迫得$N只有回身自救。\n";
        case 2:
                return "$n六剑连出，剑气回荡，直割得$N眉毛削落，脸面生通，再也不能前进半分！\n";
        default:
                return "$n一声长笑，无形剑气四处散开，将$N层层裹住，惟有勉强支撑。才约略摆脱了$n的反击。\n";
	}
}
mapping query_action(object me, object weapon)
{
    int level = (int)me->query_skill("liumai-shenjian", 1);
	
	if (random(level) > 500 && random(10)==1 && me->query("neili") > 1000 && me->query("jiali")>100 && me->query_skill("beiming-shengong",1) > 500 && me->query_skill_mapped("force") == "beiming-shengong" )
	{
		me->add("neili", -50);
		return ([
			"action": HIG"$N忽然觉得剑谱中的六路剑法一一涌向心头，十指纷弹，此去彼来，连绵无尽。剑气纵横，尘烟四起，六路剑法回转运使，$n顿时心神大乱，但觉全身几处刺痛，几股鲜血从身上标出。忍痛抬头一看，一柱剑气迎面又到",
			"attack":	1000,
			"parry":	1000,
			"dodge":	1000,
			"damage":	1000,
			"force":	1000,
			"weapon" : "无形剑气",
			"damage_type": "刺伤",
		]);
	}

	if ( random(level) > 500 && random(10)==2 && me->query("neili") > 1000 && me->query("jiali")>100 && me->query_skill("kumu-shengong",1) > 500  &&  me->query_skill_mapped("force") == "kumu-shengong" )
	{
		return ([
			"action": HIW"$N内息急转，不断催动真气，"HIY"「六脉神剑」"HIW"使得奥妙无方，剑气破空之声更为凌厉，袭向$n的命门大穴" NOR,
			"damage_type": "刺伤",
			"attack":	1000,
			"parry":	1000,
			"dodge":	1000,
			"damage":	1000,
			"force":	1000,
			"weapon" : "无形剑气",
			]);
    }

	return action[random(sizeof(action))];
}
string perform_action_file(string action)
{
    return __DIR__"liumai-shenjian/" + action;
}

