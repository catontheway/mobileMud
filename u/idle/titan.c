#include <ansi.h>

inherit NPC;

int do_hp(string arg);
int do_skills(string arg);
int do_score(string arg);
void heal();
void auto_perform();

void create()
{
set_name("泰坦",({"titan"}));
set("nickname",MAG"★云中城堡★"HIY"高级生物"NOR);
set("long", @LONG
他曾是全真派首屈一指的高手，内定的王重阳接班人，
却在最辉煌的时候急流勇退，享受平淡惬意的隐居生活，
成为一个超脱于门派之外，浪迹于江湖的之间的散仙。
但是你如果想做什么为非作歹之事的话，可要想想他手
中的宝剑哦。
LONG
                );
set("title",HIB"全真派"RED"散仙"NOR);
set("gender","男性");
set("age",39);
set("attitude", "heroism");
set("shen",470262);
set("rank_info/respect",MAG"堡主"NOR);

set("str", 40);
set("con", 40);
set("int", 40);
set("dex", 40);
set("per", 40);

set("max_jing",3090);
set("jing",3090);
set("max_qi",2742);
set("qi",2742);
set("max_jingli",9401);
set("jingli",9401);
set("max_neili",8010);
set("neili",8010);
set("jiali",100);
set("combat_exp",35300773);

set_skill("array",151);
set_skill("blade",177);
set_skill("chuforce",245);
set_skill("cuff",603);
set_skill("daoxue-xinfa",301);
set_skill("dodge",503);
set_skill("fanwen",206);
set_skill("finger",706);
set_skill("flatter",175);
set_skill("force",702);
set_skill("fx-step",502);
set_skill("hero-jianfa",700);
set_skill("kongming-quan",603);
set_skill("literate",1015);
set_skill("medical-skill",387);
set_skill("parry",705);
set_skill("qishang-quan",60);
set_skill("qixing-array",200);
set_skill("quanzhen-jian",703);
set_skill("sword",701);
set_skill("tiangang-beidou",100);
set_skill("tonggui-jian",705);
set_skill("xiake-jianfa",160);
set_skill("xiake-quanjiao",160);
set_skill("xiake-shengong",155);
set_skill("xiake-strike",160);
set_skill("xiantian-gong",450);
set_skill("yangxin-quan",603);
set_skill("yiyang-zhi",700);
set_skill("yunu-xinfa",100);

map_skill("parry","tonggui-jian");
map_skill("cuff","kongming-quan");
map_skill("sword","tonggui-jian");
map_skill("force","xiantian-gong");
map_skill("dodge","fx-step");
map_skill("finger","yiyang-zhi");
map_skill("array","qixing-array");

prepare_skill("finger","yiyang-zhi");

        set("inquiry", ([
                "hp"    : (: do_hp :),
	        "skills" : (: do_skills :),
        	"score" : (: do_score :),
        ]));
	set("chat_chance_combat", 100);  
	set("chat_msg_combat", ({
		(: auto_perform :),
                      }) );
    	set("chat_chance",100);
    	set("chat_msg",({
	        (: heal :),
        }));
setup();
	carry_object(__DIR__"obj/titangladius.c")->wield();
        carry_object(__DIR__"obj/titan1")->wear();
        carry_object(__DIR__"obj/titan2")->wear();
        carry_object(__DIR__"obj/titan3")->wear();
        carry_object(__DIR__"obj/titan4")->wear();
        carry_object(__DIR__"obj/titan5")->wear();
        carry_object(__DIR__"obj/titan6")->wear();
        carry_object(__DIR__"obj/titan7")->wear();
        carry_object(__DIR__"obj/titan8")->wear();
        carry_object(__DIR__"obj/titan9")->wear();
}
void init()
{
	add_action("do_hp","hp");
	add_action("do_skills","skills");
	add_action("do_skills","cha");
	add_action("do_skills","skill");
	add_action("do_score","sc");
	add_action("do_score","score");
}
int do_hp(string arg)
{
	if (!arg || arg != "titan") return 0;
	message_vision("$N说： 我的基本状态如下：\n\n", this_object());
	printf(HIC"≡"HIY"──────────────────────────────────"HIC"≡\n"NOR);
        message_vision(
"  精 ： 3090/ 3090 (100%)        精力： 9401 / 9401 (+0)            \n"+
"  气 ： 2742/ 2742 (100%)        内力： 8010 / 8010 (+0)            \n"+
" 食物：  400/  400               潜能：   90073                     \n"+
" 饮水：  400/  400               经验：   35300773                  \n", this_object());
printf(HIC"≡"HIY"──────────────────────────────────"HIC"≡\n"NOR);

        return 1;
}

int do_score(string arg)
{
	if (!arg || arg != "titan") return 0;
        message_vision("$N说: 我的基本状况如下: \n\n"+
"【盖世豪侠】全真派天仙「★云中城堡★高级生物」泰坦(Titan)             \n"+
"                                                                      \n"+
" 你是一位三十九岁的已婚男性人类，乙酉年十一月十三日戌时二刻生。       \n"+
"                                                                      \n"+
" 你的老婆是crystalfei。 可惜她现在不在连线中。                        \n"+
" 膂力：[100]  悟性：[141]  根骨：[110]  身法：[ 77]                   \n"+
"                                                                      \n"+
" <精>  ■■■■■■■■■■■■■■■■■■■■■■■■■             \n"+
" <气>  ■■■■■■■■■■■■■■■■■■■■■■■■■             \n"+
"                                                                      \n"+
" 攻击 688820 (+0)       躲闪 202906     招架 562411 (+2)              \n"+
"                                                                      \n"+
" 食物：□□□□□□□□□□□□□□□□□□□□□□□□□             \n"+
" 饮水：□□□□□□□□□□□□□□□□□□□□□□□□□             \n"+
"                                                                      \n"+
" 你到目前为止总共杀了 5539 个人，其中有 9 个是其他玩家。              \n"+
"                                                                      \n"+
" 道     德：  470262                                                  \n"+
" 潜     能：  90073 (96%)                                             \n"+
" 实战 经验：  35300773                                                \n"+
"                                                                      \n"+
" 师门忠诚度：1520                                                     \n"+
" 江湖声望： 34169                                                     \n"+
"
                                          \n"+
" 你这一生一共竞技八十八场,其中八十五胜三败                            \n"+
"
                                          \n"+
" 你单场最高奖励为三千零六十点经验和七十六点潜能                       \n"+
"
                                          \n"+
" 你连续竞技获胜的最高场数为四十七场!
      \n",this_object());
        return 1;
}
int do_skills(string arg)
{
	if (!arg || arg != "titan") return 0;
        message_vision("$N说: 我的所有的武功如下: \n\n",this_object());

printf(HIC"≡"HIY"──────────────────────────────────"HIC"≡\n"NOR);
        message_vision(
"  基本剑阵 (array)                         - 深不可测 151/  117     \n"+
"  基本刀法 (blade)                         - 深不可测 177/ 1348     \n"+
"  楚家内功 (chuforce)                      - 深不可测 245/    0     \n"+
"  基本拳法 (cuff)                          - 深不可测 603/    0     \n"+
"  道学心法 (daoxue-xinfa)                  - 深不可测 301/ 3561     \n"+
"  基本轻功 (dodge)                         - 深不可测 503/112678    \n"+
"  基础梵文 (fanwen)                        - 深不可测 206/    0     \n"+
"  基本指法 (finger)                        - 深不可测 706/455430    \n"+
"  马屁神功 (flatter)                       - 深不可测 175/    5     \n"+
"  基本内功 (force)                         - 深不可测 702/223114    \n"+
"□飞仙步法 (fx-step)                       - 深不可测 502/    0     \n"+
"  英雄剑法 (hero-jianfa)                   - 深不可测 700/91328     \n"+
"□空明拳 (kongming-quan)                   - 深不可测 603/    0     \n"+
"  读书写字 (literate)                      - 深不可测 1015/58552    \n"+
"  医    术 (medical-skill)                 - 深不可测 387/44370     \n"+
"  基本招架 (parry)                         - 深不可测 705/13939     \n"+
"  七伤拳 (qishang-quan)                    - 出神入化  60/  960     \n"+
"□北斗七星阵 (qixing-array)                - 深不可测 200/    1     \n"+
"□全真剑法 (quanzhen-jian)                 - 深不可测 703/178319    \n"+
"  基本剑法 (sword)                         - 深不可测 701/16493     \n"+
"  天罡北斗阵 (tiangang-beidou)             - 震古烁今 100/  225     \n"+
"□同归剑法 (tonggui-jian)                  - 深不可测 705/4193230   \n"+
"  侠客剑法 (xiake-jianfa)                  - 深不可测 160/10200     \n"+
"  侠客拳脚 (xiake-quanjiao)                - 深不可测 160/11490     \n"+
"  侠客神功 (xiake-shengong)                - 深不可测 155/   40     \n"+
"  侠客掌法 (xiake-strike)                  - 深不可测 160/ 7020     \n"+
"□先天功 (xiantian-gong)                   - 深不可测 450/41977     \n"+
"  养心拳 (yangxin-quan)                    - 深不可测 603/    0     \n"+
"□一阳指 (yiyang-zhi)                      - 深不可测 700/326780    \n"+
"  玉女心法 (yunu-xinfa)                    - 震古烁今 100/    7     \n"+
"——————————————————————————————————\n",this_object());
printf(HIC"≡"HIY"──────────────────────────────────"HIC"≡\n"NOR);
       return 1;
}

void auto_perform()
{
	object me = this_object();
	object target = me->select_opponent();
	object weapon = me->query_temp("weapon");
	command("exert powerup");

	if ( !objectp(target) ) return 0;

	if (me->query("qi") < me->query("eff_qi"))
 	command("exert recover");
 	if (me->query("jing") < me->query("eff_jing"))
	command("exert regenerate");

        command("enable sword quanzhen-jian");
        command("enable parry quanzhen-jian");
        command("perform sword.jianqi");
        command("perform sword.tonggui");
        command("enable sword tonggui-jian");
        command("enable parry tonggui-jian");

        switch( random(10) )
        {
        case 0:
                command("unwield sword");
                command("perform finger.qiankun-yizhi " + target->query("id"));
                command("wield sword");
                break;
        case 1:
                command("unwield sword");
                command("perform finger.fuxue " + target->query("id"));
                command("wield sword");
                break;
        case 2:
                command("perform sword.qixing");
                break;
        case 3:
                command("perform sword.qixing");
                break;
        case 4:
                command("enable sword quanzhen-jian");
                command("enable parry quanzhen-jian");
                command("perform sword.sanqing");
                command("enable sword tonggui-jian");
                command("enable parry tonggui-jian");
                break;
        case 5:
                command("enable sword quanzhen-jian");
                command("enable parry quanzhen-jian");
                command("perform sword.ding");
                command("enable sword tonggui-jian");
                command("enable parry tonggui-jian");
                break;
        case 6:
                command("enable sword quanzhen-jian");
                command("enable parry quanzhen-jian");
                command("perform sword.qixing");
                command("enable sword tonggui-jian");
                command("enable parry tonggui-jian");
                break;
        case 7:
                command("enable sword quanzhen-jian");
                command("enable parry quanzhen-jian");
                command("perform sword.jianzhen");
                command("enable sword tonggui-jian");
                command("enable parry tonggui-jian");
                break;
        case 8:
                command("enable sword hero-jianfa");
                command("enable parry hero-jianfa");
                command("perform sword.xiyang");
                command("enable sword tonggui-jian");
                command("enable parry tonggui-jian");
                break;
        case 9:
                command("perform sword.qixing");
                break;
        }
}
void heal()
{
	object ob=this_player();

	if (ob->query("eff_qi") < ob->query("max_qi"))
	{
		command("exert heal");
		command("enforce 100");
		return;
	}

	if (ob->query("qi") < ob->query("eff_qi"))
	{
		command("exert recover");
		return;
	}

	if (ob->query("jing") < ob->query("eff_jing"))
	{	command("exert regenerate");

               return;
               }

}
