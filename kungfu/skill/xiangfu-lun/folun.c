// 佛轮转
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
string query_name() { return "五轮"ZJBR"大法 "; }
int perform(object me, object target)
{
//	object *inv
	object weapon;
    mapping skill_status;	
	string msg,*sname;
	int extra,ap, dp,damage,siz,level;
//	int equip,app,dpp;
	
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("这门绝学只能对战斗中的对手使用。\n");
	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "hammer")
		return notify_fail("兵器不是这个！\n");
	if (me->query_skill_mapped("hammer") != "xiangfu-lun")
		return notify_fail("你没正确激发该技能 。\n");
	
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	if( (int)me->query("max_neili") < 5000  )
		return notify_fail("你的内力修为不够。\n");
	if( (int)me->query("max_jingli") < 5000  )
		return notify_fail("你的精力修为不够。\n");
	if( (int)me->query("neili") < 5000 )
		return notify_fail("你的内力不够。\n");
	if( (int)me->query("jingli") < 5000 )
		return notify_fail("你的精力不够了。\n");	
	if( (int)me->query_skill("huoyan-dao", 1) < 300 )
		return notify_fail("你的火焰刀等级不够!不能贯通使用！\n");
	if( (int)me->query_skill("xiangfu-lun", 1) < 300)
		return notify_fail("你的降伏轮法等级不够!不能贯通使用！\n");
	if((int)me->query_skill("longxiang-boruo", 1) < 300 )
		return notify_fail("你的龙象般若功不够高!不能贯通使用！\n");
	if ( me->query_skill_mapped("force") != "longxiang-boruo" )
		return notify_fail("不使用本门内功，如何使用本门绝学!\n");
	
	if (me->query_temp("autolian"))
		return notify_fail("你正在发动自动连招！\n"); 
	if ( me->query_temp("cooldown") )	//CD写法	2017.9.7添加
		return notify_fail("你处于技能冷却状态中，过会在使用吧。\n");
		
	message_vision(HBWHT "$N贯通雪山寺武学，使出了雪山寺的绝学之精髓！\n" NOR, me, target);
	me->set_temp("cooldown", 1);	//CD写法	2017.9.7添加
	call_out("del_cooldown", 5, me);	//CD写法1
	ap = me->query("xyzx_sys/level") + me->query_skill("riyue-lun", 1) +me->query_skill("huoyan-dao",1)+ me->query_skill("hammer") + me->query_skill("force");
	dp = target->query("xyzx_sys/level") + target->query_skill("dodge") + target->query_skill("parry");
	ap = ap*((int)me->query("breakup")+(int)me->query("breakup")*(int)me->query("breakup")+100)/100;
	dp = dp*((int)target->query("breakup")+(int)target->query("breakup")*(int)target->query("breakup")+100)/100;
	extra = me->query_skill("riyue-lun",1)/10;
	
	me->add_temp("apply/strength", extra);
	me->add_temp("apply/attack", extra);
	me->add_temp("apply/damage", extra);
	msg = HIY "$N纵跃退後，立时呜呜、嗡嗡、轰轰之声大作，金光闪闪，银光烁烁，五只轮子从五个不同方位飞袭出来！\n" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	msg =  HIC  "$N伸手搭在法轮上往斜里一拨，法轮在空中划出一道弧线，向$n飞去。\n" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	msg =  HIR  "$N吐气发力，双掌齐推，法轮去势劲急，呜的一声冲向$n。 \n" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	msg =  YEL  "$N双手箕张，拦在$n身前，法轮在空中旋转而回，袭向$n的后脑。 \n" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	msg =  BLU   "$N霹雳般一声断喝，侧身单拳硬生生击在法轮上，法轮方向猛的一转，直追向$n。\n" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/strength", -extra);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->add("neili", -1000);
	me->add("jingli", -1000);

if(me->query_skill("riyue-lun",1)>2000 && me->query_skill("huoyan-dao",1)>2000)	
{
	
	message_vision(RED"\n$N使出降伏轮之「五轮大法」绝技，五个轮子同时飞出，交叉穿行，进攻$n五处要害！\n"NOR,me,target);
	msg = HIC "$N鼓起全身真气，控制五轮，一个接一个，连绵不息。\n"NOR;
	message_vision(msg, me, target);
	damage = me->query_skill("riyue-lun",1) + me->query_skill("huoyan-dao",1) + me->query_skill("longxiang",1)*5+ me->query_skill("force",1)+ me->query_skill("hammer",1)+ me->query_skill("unarmed",1);
	damage = damage/3 + random(damage/3);
	damage = damage*(100-target->query_meridian())/100;
	if( random(ap) > dp/3 )
	{
	extra = me->query_skill("riyue-lun",1)/10+ me->query_skill("longxiang",1)/10;
	me->add_temp("apply/strength", extra);
	me->add_temp("apply/attack", extra);
	me->add_temp("apply/damage", extra);	
	msg = HIY "$N五轮齐出，立时呜呜、嗡嗡、轰轰之声大作，金轮，银轮，铜轮，铁轮，锡轮，五只轮子从五个不同方位飞袭出来！\n" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/strength", -extra);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	
	weapon->unequip();
	extra = me->query_skill("huoyan-dao",1)/10+ me->query_skill("longxiang",1)/10;
	me->add_temp("apply/strength", extra);
	me->add_temp("apply/attack", extra);
	me->add_temp("apply/damage", extra);	
	msg = HIY "$N收起五轮，长吸一口气，内力运聚双掌，只见$N双掌热气滚滚，挥舞之际有火焰滞空！\n" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/strength", -extra);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);	
	weapon->wield();
	
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		me->add("neili", -3000);
		me->add("jingli", -3000);
		target->add("neili", -damage);
		msg = HIR "$n一个不慎，接连被金轮击中，身体被火焰掌扫中，“哇”的一声喷出一口鲜血！\n"NOR;
		message_vision(msg, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法
//		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
	}
	else
	{
		msg = HIG "只见$n不慌不忙，左拨右挡，轻松抵挡了$N的这一招！\n"NOR;
		message_vision(msg, me, target);
		me->add("neili", -1000);
	}
	
}

	
	
if(me->query_skill("riyue-lun",1)>3000 && me->query_skill("huoyan-dao",1)>3000)	
{	
	msg = HIC "$N聚气于掌，使出一招「焚心以火」，向$n的胸口击去。\n"NOR;
	message_vision(msg, me, target);
	if (me->query("jm/xueshan")) damage = me->query_skill("riyue-lun",1)*me->query("str",1)*3/20 + me->query_skill("huoyan-dao",1)*me->query("str",1)*3/20 + me->query_skill("longxiang",1)*me->query("str",1)*3/20+ me->query_skill("force",1)+ me->query_skill("hammer",1)+ me->query_skill("unarmed",1);
	else damage = me->query_skill("riyue-lun",1)*me->query("str",1)/10 + me->query_skill("huoyan-dao",1)*me->query("str",1)/10 + me->query_skill("longxiang",1)*me->query("str",1)/10+ me->query_skill("force",1)+ me->query_skill("hammer",1)+ me->query_skill("unarmed",1);
	damage = damage/3 + random(damage/3) + target->query("qi")*1/100;
	damage = damage*(100-target->query_meridian())/100;
	if( random(ap) > dp/3 )
	{
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		me->add("neili", -3000);
		me->add("jingli", -3000);
		msg = HIR "$n只觉得眼前一黑，一阵热焰扑面而来，“哇”的一声喷出一口鲜血！\n"NOR;
		message_vision(msg, me, target, damage, HBWHT+HIM"气血伤害"NOR);	//2018.10.2阿飞改，优化化学伤害显示的写法	
//		if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"，内伤为"+ damage/2 +"。\n" NOR);
	//鉴于日月轮太强势了，这个碎装备就取消掉算了
/*		inv = all_inventory(target);
		app = sizeof(inv);
		if (app>3) app=3;
		dpp=random(app);
		for(equip=0; equip<dpp; equip++)
		{
			if( inv[equip]->query("equipped") && !inv[equip]->query("weapon_prop") && inv[equip]->query("armor_prop/armor") < 1500)
			{
				msg = HIR "$n闻到一股焦味，发现身上的"+inv[equip]->query("name")+HIR"已被烧得残破不堪，掉在了地上！\n"NOR;
				message_vision(msg, me, target);
				inv[equip]->unequip();
//				inv[equip]->reset_action();
				inv[equip]->move(environment(target));
				inv[equip]->set("name", "破碎的" + inv[equip]->query("name"));
				inv[equip]->set("item_old_value", inv[equip]->query("value"));
				inv[equip]->set("value", 0);
				inv[equip]->set("backold_armor_prop", inv[equip]->query("armor_prop"));
				inv[equip]->set("armor_prop", 0);
//				inv[equip]->set("long", "一堆破碎物事，好象是布片铁片什么的。\n");
			}
		}*/	
	}
	else
	{
		if (me->query("jm/xueshan"))
		{	
		weapon->unequip();
		extra = me->query_skill("huoyan-dao",1)/10+me->query_skill("longxiang",1)/10;
		me->add_temp("apply/strength", extra);
		me->add_temp("apply/attack", extra);
		me->add_temp("apply/damage", extra);	
		msg = HIY "$N发完五轮之后，龙象之力凝聚于双臂，紧跟着就是一记火焰掌刀！\n" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		me->add_temp("apply/strength", -extra);
		me->add_temp("apply/attack", -extra);
		me->add_temp("apply/damage", -extra);
		weapon->wield();
		me->add("neili", -1000);
		}
		else
		{
		msg = HIG "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！\n"NOR;
		message_vision(msg, me, target);	
		}		
	}
if(me->query_skill("riyue-lun",1)>4000 && me->query_skill("huoyan-dao",1)>4000)	
{	//鉴于日月轮太强势了，降技能改成4000级才能出
	message_vision(RED"\n$N祭起火焰刀之「红莲火」绝技，精纯的内力呈红色缓缓涌出，于身前三尺之处，便即停住不动，将这飘荡无定的真气定在半空，它虽是虚无缥缈，不可捉摸，却能杀人于无形，实是厉害不过！\n"NOR,me,target);
	if( random(ap) > dp/3 )
	{
		if ( skill_status = target->query_skills() )
		{
			sname  = keys(skill_status);
			siz = random(sizeof(skill_status));		
			if (skill_status[sname[siz]]>10)
			{
				level = skill_status[sname[siz]] - 2;
				if (!userp(target)) level = skill_status[sname[siz]]/2 - 1;
			}
			else
				level = 5;
			if(level <= 0)
			target->delete_skill(sname[siz]);
			else
			target->set_skill(sname[siz], level);	
			message_vision(HIM"\n$n身陷「红莲火」之中，红莲业火如地狱轮回，让$n回想起生前万般罪孽，经过地狱火的焚烧，$n将生前所学忘记了一部分！\n"NOR,me,target);
			if( !target->is_killing(me) ) target->kill_ob(me);
			if( !me->is_killing(target) ) me->fight_ob(target);
			message_vision( HIW"$N摧毁了$n的技能！坏人道行，不死不休啊！\n"+NOR,me,target);				
		}
	}
	else
	{
		msg = HIG "只见$n口绽莲花，喷出一口清新玉露，浇灭了红莲业火！\n"NOR;
		message_vision(msg, me, target);		
	}
}	
}
	me->start_busy(1);
	return 1;
}

void del_cooldown(object me)	//CD写法1
{ 
	if ( !objectp(me) ) return;
	if ( me->query_temp("cooldown") )	
	{
		me->delete_temp("cooldown");
		tell_object(me, HIM"你呼出一口气，缓缓的将内力收回丹田。\n"NOR);
	}	
}