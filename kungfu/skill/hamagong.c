// hamagong.c 蛤蟆功
// By vast
// Modified by iszt@pkuxkx, 2006-12-12, added zouhuo
// Modified by iszt@pkuxkx, 2007-03-27, no other force allowed

#include <ansi.h>

inherit FORCE;
#include "/kungfu/skill/force.h"

string* query_base_kongshou()
{
	return ({ "strike" });
}

mapping *action = ({
([      "action": "$N劲由心生，蛤蟆功内劲迸发，一股热气从丹田中直冲上来，双腿一弯，口中阁的一声叫喝，手掌 便朝$n推出",
        "dodge": 100,
        "parry": 100,
        "force": 100,
        "lvl" : 0,
        "damage": 100,
        "damage_type": "内伤"
]),
([      "action":"$N猛喝一声，双掌倏向$n$l推出，掌力疾冲而去，劲力十分猛恶，祗隐听得呼呼风响，声音 劲急，非同寻常",
        "parry": 150,
        "force": 150,
        "lvl" : 60,
        "damage": 150,
        "damage_type": "内伤"
]),
([      "action":"$N蹲下身子，“咕”的一声大叫，猛地双掌推出，掌风沉雄凌厉。$n突觉一股排山倒海般的力道撞来，猛迅无伦",
        "dodge": 200,
        "force": 200,
        "lvl" : 80,
        "damage": 200,
        "damage_type": "内伤"
]),
([      "action":"$N蹲低身子，发掌向$n击去，左掌右掌，连环邀击，双掌连绵而上，掌法愈厉，乘 势不住追击，後著凌厉之极",
        "dodge": 250,
        "force": 250,
        "lvl" : 60,
        "damage": 250,
        "damage_type": "瘀伤"
]),
([      "action":"$N“阁”的一声大叫，发劲急推，双掌一上一下，一放一收，斗然击出，朝著$n排山倒海般劈将过来",
        "dodge": 300,
        "force": 300,
        "lvl" : 80,
        "damage": 300,
        "damage_type": "瘀伤"
]),
([      "action":"$N身子蹲下，双掌平推而出，口中咯咯大叫，身子一幌一幌。这一推劲力极大，去势却慢，看来平平无奇，内中却是暗藏极大潜力",
        "dodge": 400,
        "force": 400,
        "lvl" : 150,
        "damage": 400,
        "damage_type": "内伤"
]),
([      "action":"$N蹲在地下，咕咕咕的叫了几声，内力崩涌，丹田中一股热气激升而上，身子猛跃而起，双掌推出，一股凌厉之极的掌风随之朝$n压到",
        "dodge": 600,
        "force": 600,
        "lvl" : 180,
        "damage": 600,
        "damage_type": "内伤"
]),
});

mapping *reverse_action = ({
([      "action": WHT"忽听$N"WHT"大叫三声，三个筋斗翻将出来，大吼一声，恶狠狠的朝$n"WHT"扑将上来"NOR,
        "dodge": 400,
        "parry": 400,
        "force": 400,
        "damage": 400,
        "damage_type": "跌伤"
]),
([      "action":HIG"但见$N"HIG"疯势更加厉害，口吐白沫，举头朝$n"HIG"猛撞"NOR,
        "parry": 450,
        "force": 450,
        "damage": 450,
        "damage_type": "瘀伤"
]),
([      "action":HIC"$N"HIC"蓦地张口，白牙一闪，已向$n"HIC"$l咬落，又快又准"NOR,
        "dodge": 450,
        "force": 450,
        "damage": 450,
        "weapon": "牙齿",
        "damage_type": "咬伤"
]),
([      "action":YEL"$N"YEL"一口唾沫急吐，势挟劲风，竟将痰涎唾沫也当作了攻敌利器"NOR,
        "dodge": 500,
        "force": 500,
        "damage": 500,
        "weapon":"唾沫",
        "damage_type": "刺伤"
]),
([      "action":MAG"$N"MAG"忽然张嘴，一口唾沫往$n"MAG"脸上吐去，发掌击向$n"MAG"趋避的方位，同时又是一口浓痰吐将过来"NOR,
        "dodge": 550,
        "force": 550,
        "damage": 550,
        "weapon" : "浓痰",
        "damage_type": "刺伤"
]),
([      "action":HIW"此时$N"HIW"所使的招数更是希奇古怪，诡异绝伦，身子时而倒竖，时而直立，忽然一手撑地，身子横挺，一手出掌打向$n"HIW"$l"NOR,
        "dodge": 600,
        "force": 600,
        "damage": 600,
        "damage_type": "瘀伤"
]),
});

mapping query_action(object me, object weapon)
{
        int i, level;
        string *reverse_msg = 
        ({
                HIR"$N蹲下身来，运起蛤蟆功，双手平推，吐气扬眉，阁阁阁三声叫喊。这三推之力带有风疾雷迅的 猛劲，实是非同小可"NOR,
                WHT"$N阁阁两声怒吼，蹲下身来，呼的双掌齐出，掌力未到，掌风已将地下尘土激起，一股劲风直扑$n面门，势道雄强无比"NOR,
                HIR"$N脸色阴沉，脸颊上两块肌肉微微牵动，两臂弯曲，阁的一声大叫，双手挺出，一股巨力横冲直撞的朝$n推将过来"NOR,
                WHT"$N蹲低身子，口中咕咕咕的叫了三声，双手推出，以蛤蟆功向$n猛攻。$n身周在$P掌力笼罩之下，只激得灰泥弥漫，尘土飞扬"NOR,
                HIM"但见$N招术奇特，怪异无伦，忽尔伸手在自己脸上猛抓一把，忽尔反足在自己臀上狠踢一脚，每一掌打将出来，中途方向必变，实不知打将何处"NOR,
                HIM"$N忽然反手拍拍拍连打自己三个耳光，大喊一声，双手据地，爬向$n，忽地翻身一滚，骤然间飞身跃起，双足向$n连环猛踢"NOR,
                HIM"突然之间，$N俯身疾攻，上盘全然不守，出招怪异无比，将蛤蟆功逆转运用，上者下之，左者右之，招数难以捉摸"NOR,
                HIM"$N全身经脉忽顺忽逆，手上招数虽然走了错道，但是错有错着，出手怪诞，竟教$n差愕难解"NOR,
        });

        level   = (int) me->query_skill("hamagong",1);

        if (me->query_skill_mapped("force") == "hamagong" ) {
                if ( me->query_temp("hmg_dzjm") && random(me->query_skill("force")) > 400  && random(me->query_skill("strike")) > 300 && me->query("neili") > 1000 )
                        return ([
                        "action": reverse_msg[random(sizeof(reverse_msg))],
                        "dodge": 1000,
                        "parry": 1000,
                        "force": 900+random(100),
                        "damage": 1000+random(20),
                        "damage_type": random(2)?"内伤":"瘀伤"
                        ]);
        }
        if ( me->query_temp("hmg_dzjm") )
                return reverse_action[random(sizeof(reverse_action))];
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int valid_enable(string usage)
{
        if (usage == "force") return 1;
        if (usage == "strike")
        {
/*                if (this_player()->query_skill("hamagong",1) < 100)
                {
                        message_vision("$N蹲下身来，口中咕咕咕的叫了几声，要将蛤蟆功口诀用在拳脚之上，但无论如何使用不上。\n", this_player() );
                        write("你的蛤蟆功火候不足，无法运用它到掌法中。\n");
                        return 0;
                }*/
                return 1;
        }
        return 0;
}

int valid_learn(object me)
{
        mapping skills;
        int i;

        if ( me->query("gender") == "无性" )
                return notify_fail("你无根无性，阴阳不调，难以领会高深的蛤蟆功。\n");

        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("你的基本内功火候不足，不能学蛤蟆功。\n");

        skills = me->query_skills();
        for(i=0; i<sizeof(skills); i++)
                if(load_object(SKILL_D(keys(skills)[i]))->valid_enable("force")
                        && keys(skills)[i] != "beiming-shengong"
                        && keys(skills)[i] != "bahuang-gong"
                        && keys(skills)[i] != "xixing-dafa"
                        && keys(skills)[i] != "huagong-dafa"
                        && keys(skills)[i] != "yunu-xinfa"
                        && keys(skills)[i] != "guangming-shenghuogong"
                        && keys(skills)[i] != "jiuyin-shengong"
                        && keys(skills)[i] != "yijin-jing"
                        && keys(skills)[i] != "riyue-shengong"
                        && keys(skills)[i] != "xiake-shengong"
                        && keys(skills)[i] != "hamagong"
						&& keys(skills)[i] != "xiaowuxiang-gong")
                        return notify_fail("你体内多种内功无法调和，还是先散了别派内功为好。\n");

        if ( ((int)me->query_skill("hamagong", 1) >180 ) && ((int)me->query_skill("force", 1) <= (int)me->query_skill("hamagong",1)) )
                return notify_fail("你的基本内功修为还不够，你应该先在基本内功上下点功夫。\n");
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("蛤蟆功只能用学(learn)的来增加熟练度。\n");
}
string exert_function_file(string func)
{
        return __DIR__"hamagong/" + func;
}
string perform_action_file(string action)
{
        return __DIR__"hamagong/" + action;
}

//Because hamagong inherits both FORCE and SKILL, when it is called
//to return the hit_ob() function, it is confused. So, we have to
//add the hit_ob() here.  Ryu.
//由于蛤蟆功同时继承了FORCE和SKILL，所以当返回 hit_ob()函数时，会出现混乱。
//因此在此处添加hit_ob()

varargs mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        if ( !factor )
          return 0;
        else
          return ::hit_ob(me, victim, damage_bonus, factor);
}
/*
mixed hit_by(object me, object victim, int damage, int damage_bonus, int factor)
{
        return damage;
}

mapping curing_msg(object me)
{
        return ([
                "unfinish_self" : "你闭目运气，忽觉内力不继，哇哇两声，喷出几口鲜血，站了起来。\n",
                "unfinish_other": HIW+me->name()+"运功良久，呕出几口黑血，站了起来。\n"NOR,
        ]);
}
*/

string* query_base_skills()
{
	return ({"strike"});
}

void skill_improved(object me)
{
        int skill = me->query_skill("hamagong", 1);
        if(  me->query("family/master_name") == "欧阳锋" 
        	|| me->query("chushi/last_family") == "白驼山") 
        //modified by whuan,20091226	
                return;
        if(skill >= 500)
        {
                tell_object(me, HIR"你的蛤蟆功已经不受你的控制了！\n"NOR);
                me->add_skill("hamagong", -random(2));
                me->add("max_neili", -100);
                me->set("attitude","aggressive");
				F_POISON->poison_attack(this_object(),me,"qishang", 900);
                return;
        }
        if(skill >= 300)
        {
                tell_object(me, HIB"你隐隐觉得真气运行有些异常，看来没有欧阳锋指点很难修习高深的蛤蟆功。\n"NOR);
                me->add("max_neili", -10);
                return;
        }
        if(skill >= 400)
        {
                tell_object(me, HIY"你感觉真气在体内上窜下跳，无法平息。\n"NOR);
                me->add("max_neili", -random(100));
                return;
        }
}
mapping buffer_applied(object ob)
{
    mapping buf, tbuf;
    int lv1, lv2, gint, pflv;
    
    lv1=ob->query_skill("hamagong",1);
    lv2=ob->query_skill("hamaquan",1);
    gint=ob->query("con");
    buf=([]);
    
 // if ( ob->query_attr_version()<140913 )
   //   return buf;

   // if ( lv1<=60 || lv2<=60 )
     // return buf;
      
    if ( mapp(ob->query_temp("passive/hamagong")) )
      return buf;
    
	

    buf["max_qi"]=(lv1/10 )*(100+gint)*4/5;
	 buf["strength"]=lv1*1/20;
    buf["max_jing"]=(lv1/10)*(100+gint)*4/5;
    ob->set_temp("passive/hamagong", buf);
    ob->set_temp("active_force_buffer/hamagong/name", "蛤蟆护体");                              //buff名称
    ob->set_temp("active_force_buffer/hamagong/effect1", "最大气血+"+(buf["max_qi"])+"点");     //效果描述1
    ob->set_temp("active_force_buffer/hamagong/effect2", "最大精神+"+(buf["max_jing"])+"点");
    ob->set_temp("active_force_buffer/hamagong/effect5", "战斗臂力+"+(buf["strength"])+"点");	//效果描述2
	
    return buf;
}
mapping buffer_removed(object ob)
{
    mapping buf;
    
    buf=ob->query_temp("passive/hamagong");;
    if ( mapp(buf) )
    {
      buf["max_qi"]=buf["max_qi"]*(-1);
      buf["max_jing"]=buf["max_jing"]*(-1);
	  buf["kf_hit_rate"]=buf["kf_hit_rate"]*(-1);
	  buf["deep_injure"] = buf["deep_injure"]*(-1);
	  buf["strength"] = buf["strength"]*(-1);
    }
    else
      buf=([]);

    ob->delete_temp("passive/hamagong");
    ob->delete_temp("active_force_buffer/hamagong");
    return buf;
}
int force_character(string char_type)
{
	int recv;
	recv=::force_character(char_type);
	switch(char_type)
	{
		case "TYPE_RECOVER":          //TYPE_RECOVER
			return 200;
	  case "TYPE_REC_CD":          //TYPE_REC_CD
	  	return 12;
	  case "TYPE_MIN_SPD":          //TYPE_MIN_SPD
	  	return 150;
	  case "TYPE_MAX_SPD":          //TYPE_MAX_SPD
	  	return 350;
	  case "TYPE_SPEED":          //TYPE_SPEED
	  	return 2;
	  case "TYPE_DEC_SPD":          //TYPE_DEC_SPD
	  	return 50;
	  case "TYPE_FORCE":     //TYPE_FORCE
	  	return 500;
    case "TYPE_ENFORCE":
      return 12;
	  default:
	  	return recv;
	}
}


