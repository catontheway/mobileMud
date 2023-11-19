#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{

	object who;
	object env;
	int v;

	if (!arg)
		return notify_fail("你要去哪里？\n");

	who = find_player(arg);
	if (!objectp(who))
		who = find_living(arg);
	if (!objectp(who))
		return notify_fail("没有这个人啊！\n");
	if (who->query("id") == "fanbang wushi")
	{
		me->add("balance", -50000);
		return notify_fail("扣除黄金5两！\n");
	}
	if (userp(who))
		return notify_fail("不能传送玩家！\n");
	if (!objectp(env = environment(who)))
		return notify_fail("这个人不知道在那里耶！\n");

	me = this_player();
	if (env == environment(me))
		return notify_fail("你在原地乱蹦哒的啥？\n");

	if (me->is_busy())
		return notify_fail("等你忙完了再说。\n");

	if (me->query("doing"))
		return notify_fail("等你计划完了再说。\n");
	if (me->query("xkxvip/times") == 0)
	{
		if (me->query("balance") < 10000)
			return notify_fail("钱庄存款不多了，留点吧。\n");
		v = 3000 + random(2000);
		me->add("balance", -v);
	}
	message_vision(HIM "$N随手扔了几十两银子然后" HIM "一手指天一手指地，口中默默低语，随机"
					   "喝道：“太上老君急急如律敕令！疾！”\n"
					   "只听“呼”的一下，$N" HIM "不见了！" NOR "\n",
				   me);
	message("vision", HIM "忽见一阵亮光渐闪，" + me->name() + HIM "出现在你面前。" NOR "\n", env);
	tell_object(me, HIM "天大地大，随处可去..." NOR "\n");
	me->move(env);
	me->add("balance", -v);

	// add_amount(-1);
	return 1;
}
int help(object me)
{
	write(@HELP
			  指令格式 : goto[-i]<目标>

							 这个指令会将你传送到指定的目标.目标可以是一个living 或房间
								 的档名.如果目标是living,
						 你会被移到跟那个人同样的环境.如果有加上 - i 参数且目标是 living, 则你会被移到该 living 的 的 inventory 中.

																						  HELP);
	return 1;
}
