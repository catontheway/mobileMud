//此技能显示方案是根据笑世的技能显示框架进行改版的尽作用于zjmud手机适配使用。
//修复玩家没有技能打开乱码问题。
//添加武学境界显示，组合准备方式暂时没添加有需要自行添加吧！！！
//原作者 ： 笑世
//最后更改与2020.1.15
//by 幕后黑手

#include <skill.h>
#include <ansi.h>
inherit F_CLEAN_UP;
void create() { seteuid(getuid()); }
string skill_level(string, int);
string *skillje = ({
	HIW"【第壹层前期】",
	HIC"【第壹层中期】",
	MAG"【第壹层后期】",
	HIR"【第壹层圆满】",
	HIW"【第贰层前期】",
	HIC"【第贰层中期】",
	MAG"【第贰层后期】",
	HIR"【第贰层圆满】",
	HIW"【第叁层前期】",
	HIC"【第叁层中期】",
	MAG"【第叁层后期】",
	HIR"【第叁层圆满】",
	HIW"【第肆层前期】",
	HIC"【第肆层中期】",
	MAG"【第肆层后期】",
	HIR"【第肆层圆满】",
	HIW"【第伍层前期】",
	HIC"【第伍层中期】",
	MAG"【第伍层后期】",
	HIR"【第伍层圆满】",
	HIW"【第陆层前期】",
	HIC"【第陆层中期】",
	MAG"【第陆层后期】",
	HIR"【第陆层圆满】",
	HIW"【第柒层前期】",
	HIC"【第柒层中期】",
	MAG"【第柒层后期】",
	HIR"【第柒层圆满】",
	HIW"【第捌层前期】",
	HIC"【第捌层中期】",
	MAG"【第捌层后期】",
	HIR"【第捌层圆满】",
	HIW"【第玖层前期】",
	HIC"【第玖层中期】",
	MAG"【第玖层后期】",
	HIR"【第玖层圆满】",
	HBRED+HIW"【大圆满】",
});
string *s1 = ({
	"force",//内功
	"dodge",//轻功
	"unarmed",//拳脚
	"cuff",//拳法
	"strike",//掌法
	"finger",//指法
	"hand",//手法
	"claw",//爪法
	"sword",//剑法
	"blade",//刀法
	"staff",//丈法
	"hammer",//锤法
	"club",//棍法
	"whip",//鞭法
	"dagger",//短兵
	"throwing",//暗器
	"axe",//斧法
	"arrow",
	"spear",
	"magic",
    "medical",
    "poison",
    "cooking",
    "chuixiao-jifa",//吹箫
     "guzheng-jifa",//古筝
    "tanqin-jifa" ,//弹琴
    "array",
    "taoism",
	"parry",//招架
	"knowledge",//知识类技能
	"basic",//其他武功综合
	
});
string *s2 = ({
	CYN"内功"NOR,//内功
CYN	"轻功"NOR,//轻功
CYN	"拳脚"NOR,//拳脚
CYN	"拳法"NOR,//拳法
CYN	"掌法"NOR,//掌法
CYN	"指法"NOR,//指法
CYN	"手法"NOR,//手法
CYN	"爪法"NOR,//爪法
CYN	"剑法"NOR,//剑法
CYN	"刀法"NOR,//刀法
CYN	"杖法"NOR,//丈法
CYN	"锤法"NOR,//锤法
CYN	"棍法"NOR,//棍法
CYN	"鞭法"NOR,//鞭法
CYN	"短兵"NOR,//短兵
CYN	"暗器"NOR,//暗器
CYN	"斧法"NOR,//暗器
CYN	"箭法"NOR,//暗器
CYN	"枪法"NOR,//暗器
CYN	"法术"NOR,//暗器
CYN	"医术"NOR,//暗器
CYN	"毒技"NOR,//暗器
CYN	"厨艺"NOR,//暗器
CYN	"吹萧"NOR,//暗器
CYN	"古筝"NOR,//暗器
CYN	"弹琴"NOR,//暗器
CYN	"阵法"NOR,//暗器
CYN	"道术"NOR,//暗器
CYN	"招架"NOR,//招架
//YEL"知识类技能"NOR,//知识类技能
//	"全部类型",//武功以及其他
	});
string skill_level(string type, int level)
	{
			int grade;
	
	
			switch(type)
			{
					case "knowledge":
							grade = level / 50;
							if( grade >= sizeof(skillje) )
									grade = sizeof(skillje)-1;
							return skillje[grade];
					default:
							grade = level / 50;
							if( grade < 0 ) grade = 0;
							if( grade >= sizeof(skillje) )
									grade = sizeof(skillje)-1;
							return skillje[grade];
			}
	}
int main(object me,string arg)
{
	object ob;
	mapping map,skl,pmap;
string sks;
int i,j,is,js;
string *s3,*s4,cs,sa,str;
string pops;
int flag = 0, parents = 0;
s4 = ({ });//空数组

s3 = keys(me->query_skills());//传回玩家的全部技能

if (! sizeof(s3))
{
	write((ob==me ? "你" : me->name()) + "目前并没有学会任何技能。\n");
	return 1;
}
		str=ZJOBACTS2+ZJMENUF(2,2,6,33);
if (!arg)//当没有参数进入主函数时，调用选择界面
{
	skl = me->query_skills();
	map = me->query_skill_map();
	
	pmap = me->query_skill_prepare();

for (i=0;i <sizeof(s2);i++)
{
sa =  s2[i];
if (me->query_skill(s1[i],1))
{
	//if (!undefinedp(map[s1[i]]))
	//continue;
//if (! me->query_skill(s1[i]))
	//continue;
/*sa += sprintf("%-10s"NOR+" "ZJBR"激发："HIM" %-20s " NOR,
skill_level(SKILL_D(s1[i])->type(), skl[s1[i]]),//武功的境界显示
undefinedp(map[s1[i]]) ? "无" : to_chinese(map[s1[i]]),//武功的激发显示
me->query_skill(s1[i]));*/
sa +=HIC"【"+me->query_skill(s1[i],1)+"级】"+NOR;
}

else
sa +=HIC"【未学习】"NOR;
str += sa+":expeal "+ s1[i]+ZJSEP;//指令主函数参数循环，用来识别和选择技能种类
}
str =ZJOBLONG+HIC"请你选择类型\n"+str;
str += HIY"旧版技能UI"NOR":skills"ZJSEP;

}

else//参数导入，技能分类开始
{
	s3 = keys(me->query_skills());
	skl = me->query_skills();
		for (i = 0; i < sizeof(s2); i++)//选择分类
		{
		if (arg==s1[i])
		{
		for (is = 0; is < sizeof(s3); is++)//选择符合这个类型的特殊武功
		{
		cs = s3[is];
			sa = to_chinese(s3[is]);
			sa += sprintf("%-10s"NOR,
skill_level(SKILL_D(cs)->type(), skl[cs]));
			

if (SKILL_D(s3[is])->valid_enable(s1[i]))
{	//识别类型
	pops = ZJPOPMENU+ZJMENUF(1,3,9,30);

pops += "激发 "+to_chinese(s3[is])+"|jifa "+ s1[i]+" "+s3[is]+ZJSP2;
pops += "准备"+to_chinese(s3[is])+"|prepare "+s3[is]+ZJSP2;
pops += "查看"+to_chinese(s3[is])+"|chaski "+s3[is]+ZJSP2;
pops += HIG"快捷修炼"NOR+to_chinese(s3[is])+"|alias kjxl xiulian "+s3[is]+ZJSP2;
pops += HIG"快捷练习"NOR+to_chinese(s3[is])+"|alias kjlx lian "+s3[is]+" 999"+ZJSP2;
pops += "忘记"+to_chinese(s3[is])+"|abandon "+s3[is]+ZJSP2;
str += sprintf(sa+""NOR":%s"ZJSEP,pops);

}
else
 if ((SKILL_D(s3[is])->type()=="knowledge"||SKILL_D(s3[is])->type()=="special")&&s1[i]=="knowledge")//知识类技能分开导入
str += sa+":jifa "+ s1[i] +" "+s3[is]+ZJSEP;
		}
		break;				//跳出循环
		}		
		}
		str += HIY"取消准备"NOR":bei none"ZJSEP;
		str += HIY"返回列表"NOR":expeal"ZJSEP+"\n";
	    str =ZJOBLONG"请你选择激发类型\n"+str;
		}
	write(str+"\n");
	return 1;
}

