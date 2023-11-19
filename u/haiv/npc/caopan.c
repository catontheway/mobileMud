// caopan.c  by hubo

inherit NPC;
inherit F_DEALER;
void create()
{
	set_name("操盘手", ({ "shou","caopan shou"}) );
	set("gender", "男性" );
	set("age", 30);
	set("long",
		"他是著名的预测球操盘手，场次赔率都是他定的，据说\n"
                "和欧洲预测博公司有很大瓜葛\n");
	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("rank_info/respect", "老板");
	setup();
}
