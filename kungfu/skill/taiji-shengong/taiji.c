// taiji.c 太极

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
//inherit F_CLEAN_UP;
int check_fight(object me);
string query_name() { return " 太极"ZJBR"无极 "; }
void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

    if (target != me)
        return notify_fail("你只能对自己使用「太极」意境。\n");		
	if (me->is_busy()) 
		return notify_fail("你现在正忙着呢！\n");
//	if (target && target->query_temp("apply/shade_vision")) 
//		return ("对方隐身了，你看不到"+target->query("name")+"。\n"); 		
    if( (int)me->query("neili") < 1000 )
        return notify_fail("你的内力不够！\n");
    if( (int)me->query("jingli") < 1000 )
        return notify_fail("你的精力不够！\n");
    if( (int)me->query("max_neili") < 1000 )
        return notify_fail("你的内力修为太差！\n");
    if( (int)me->query("max_jingli") < 1000 )
        return notify_fail("你的精力修为太差！\n");
	if ((int)me->query_skill("taiji-shengong", 1) < 200)
        return notify_fail("你的太极神功等级不够，还不能领会「太极」意境。\n");
	if (me->query_skill_mapped("force") != "taiji-shengong")
		return notify_fail("你的内功不对，根本不能发挥出「太极」的优势。\n");
	if (me->query_skill_mapped("parry") != "taiji-quan")
		return notify_fail("「太极」诀窍必须在太极拳招架的情况下才能使用。\n");
	if ((int)me->query_skill("taiji-quan", 1) < 200 )
		return notify_fail("你的太极拳不够娴熟，还不能领会「太极」意境。\n");
	if (me->query_temp("taiji"))
		return notify_fail("「太极」之意绵绵不绝，你已经在发挥它的威力了。\n");	
    if ( me->query_temp("powerup") )
		return notify_fail("你已经在运别的内功中了。\n");	
	if (me->query_temp("autolian"))
		return notify_fail("你正在发动自动连招！\n"); 	
	if ( me->query_temp("cooldown") )	//CD写法	2017.9.7添加
		return notify_fail("你处于技能冷却状态中，过会在使用吧。\n");
		
		me->set_temp("taijiwuji", 1);	
		me->set_temp("taiji", 1);	
        skill = (int)me->query_skill("taiji-shengong",1)/15+(int)me->query_skill("force", 1)/40;
        me->add("neili", -100);

		message_vision(HIR"$N"HIR"默念太极功法口诀: "
						"\n大道，在太极之上而不为高；在六极之下而不为深；"
						"\n先天地而不为久；长于上古而不为老。"
						"\n易有太极，始生两仪，两仪生四象，四象生八卦。"
						"\n天地未分之前，元气混而为一，即是太初、太一也。\n"NOR,me);       
       
		me->add_temp("apply/constitution", skill*13/10);
		me->add_temp("apply/intelligence",skill*8/10);
		me->add_temp("apply/parry",skill*15);
		me->add_temp("apply/cuff", skill*11);
		me->add_temp("apply/attack",skill*8);
		me->add_temp("apply/armor", skill*12);
		 me->set_temp("active_force_buffer/taiji-shengong.wuji/name", "无极");                                  //buff名称
        me->set_temp("active_force_buffer/taiji-shengong.wuji/last_time", time() + skill );              //持续时间
        me->set_temp("active_force_buffer/taiji-shengong.wuji/effect1", "根骨+"+(skill*13/10)+"级");       //效果描述1   
        me->set_temp("active_force_buffer/taiji-shengong.wuji/effect2", "悟性+"+(skill*8/10)+"级");   
 me->set_temp("active_force_buffer/taiji-shengong.wuji/effect3", "招架技能+"+(skill*15)+"级");
 me->set_temp("active_force_buffer/taiji-shengong.wuji/effect4", "拳法技能+"+(skill*11)+"级");
 me->set_temp("active_force_buffer/taiji-shengong.wuji/effect5", "命中技能+"+(skill*8)+"级");
 me->set_temp("active_force_buffer/taiji-shengong.wuji/effect6", "防御技能+"+(skill*12)+"级"); //效果描述2
       // check_fight(me);
		  call_out("check_fight", 1, me);
        me->start_call_out(__FILE__, "remove_effect", skill,me, skill);
		me->start_busy(1);
        return 1;
}

int check_fight(object me)
{	
	//if (!me || !(int)me->query_temp("taijiwuji")) return 0;
	//if (me && !living(me)) return 0;
    if (me->query("qi") < 1 || me->query("eff_qi") < 1) return 0;  //解决 气血为负数 不晕不死的bug
	if (me->query("jing") < 1 || me->query("eff_jing") < 1) return 0;
	
        if (living(me)
        && me->is_fighting() && me->query("neili") > 500
        && me->query_skill_mapped("force") == "taiji-shengong")
        {
            if(me->query("eff_qi") < (int)me->query("max_qi"))
			{
                message_vision(CYN"$N双手自然挥动，负阴而抱阳，身与心合，将"RED"「太极」"CYN"发挥得淋漓尽致！脸色红润了不少。\n"NOR,me);
                me->add("neili", -100);
                me->add("eff_qi",me->query_skill("taiji-shengong",1)*me->query("con",1)/3+me->query("max_qi")/50);
				if (me->query("eff_qi") > me->query("max_qi")) me->set("eff_qi", me->query("max_qi"));
                me->add("qi",me->query_skill("taiji-shengong",1)*me->query("con",1)/3+me->query("max_qi")/50);
				if (me->query("qi") > me->query("eff_qi")) me->set("qi", me->query("eff_qi"));
            }
			if(me->query("eff_jing") < (int)me->query("max_jing"))
			{
                message_vision(HIR"$N气定神闲，头顶阴阳二气流转，吸天地之灵气，顿时精神大振!\n"NOR,me);
                me->add("neili", -200);
                me->add("eff_jing",me->query_skill("taiji-shengong",1)*me->query("con",1)/3+me->query("max_jing")/50);
				if (me->query("eff_jing") > me->query("max_jing")) me->set("eff_jing", me->query("max_jing"));
                me->add("jing",me->query_skill("taiji-shengong",1)*me->query("con",1)/3+me->query("max_jing")/50);
				if (me->query("jing") > me->query("eff_jing")) me->set("jing", me->query("eff_jing"));
            }	
			
        }
        call_out("check_fight", 5, me);
        return 1;
}       

void remove_effect(object me, int amount)
{
	if (!me) return;
	if ( (int)me->query_temp("taijiwuji") )
	{
        me->delete_temp("taiji");	
		me->delete_temp("taijiwuji");
		me->add_temp("apply/constitution", -amount*13/10);
		me->add_temp("apply/intelligence",-amount*8/10);
		me->add_temp("apply/parry",-amount*15);
		me->add_temp("apply/unarmed", -amount*11);		
		me->add_temp("apply/attack",-amount*8);
		me->add_temp("apply/armor", -amount*12);
        tell_object(me, "你从太极意境中醒来，长吸一口气，舒泰至极。\n");
	}
}