// huashan-neigong.c 华山内功
inherit FORCE;
int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	if ( ((int)me->query_skill("huashan-xinfa", 1)) < 100 )
		return notify_fail("你的华山心法火候还不够，无法领会华山内功。\n");
        return 1;
}
int practice_skill(object me)
{
        return notify_fail("华山内功只能用学(learn)的来增加熟练度。\n");
}
string exert_function_file(string func)
{
        return __DIR__"huashan-neigong/" + func;
}

string query_yinyang()
{
	return "少阳";
}
