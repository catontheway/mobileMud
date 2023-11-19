// shutdown.c
#include <ansi.h>
#include <net/daemons.h>

inherit F_CLEAN_UP;
inherit __DIR__"user_weapondtz.c";

int main(object me, string arg)
{
	string wiz_status;
	object *user, link_ob;
	int i,tp,lv,lb;
  int a,b,c,d;
	if( me != this_player(1) ) return 0;
	
	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" && wiz_status != "(arch)" )
		return notify_fail("只有 (arch) 以上的巫师才能使用!\n");
CHANNEL_D->do_channel(me, "rw", HIR"请注意，随机装备系统正在生成首饰装备，可能会有略微卡顿。");
//weaponmake(i,tp,lv);
//i为数量,tp为类别参数0-8,lv为等级1-6

//armormake(i,tp,lv);
//i为数量,tp为类别参数0-9,lv为等级1-6
//lb为0为weapon 为1为armor

a=sizeof(Special_Class);
b=sizeof(Super_Class);
c=sizeof(Great_Class);

lb=0;
tp=8;
for(tp = 0; tp<=8; tp++) {



lv=6;
				for(i = 0; i<a; i++) {
if (lb==0) weaponmake(i,tp,lv,i,"ritemtz1"); else if (lb==1) armormake(i,tp,lv,i,"ritemtz1");
					}
					

}

lb=1;
tp=9;
for(tp = 0; tp<=9; tp++) {
lv=6;
				for(i = 0; i<a; i++) {
if (lb==0) weaponmake(i,tp,lv,i,"ritemtz1"); else if (lb==1) armormake(i,tp,lv,i,"ritemtz1");
					}
}


//开始
lb=0;
tp=8;
for(tp = 0; tp<=8; tp++) {

lv=5;
				for(i = 0; i<b; i++) {
if (lb==0) weaponmake(i,tp,lv,i,"ritemtz2"); else if (lb==1) armormake(i,tp,lv,i,"ritemtz2");
					}
					

}

lb=1;
tp=9;
for(tp = 0; tp<=9; tp++) {
lv=5;
				for(i = 0; i<b; i++) {
if (lb==0) weaponmake(i,tp,lv,i,"ritemtz2"); else if (lb==1) armormake(i,tp,lv,i,"ritemtz2");
					}
}

//结束


//开始
lb=0;
tp=8;
for(tp = 0; tp<=8; tp++) {

lv=4;
				for(i = 0; i<c; i++) {
if (lb==0) weaponmake(i,tp,lv,i,"ritemtz3"); else if (lb==1) armormake(i,tp,lv,i,"ritemtz3");
					}
					

}

lb=1;
tp=9;
for(tp = 0; tp<=9; tp++) {
lv=4;
				for(i = 0; i<c; i++) {
if (lb==0) weaponmake(i,tp,lv,i,"ritemtz3"); else if (lb==1) armormake(i,tp,lv,i,"ritemtz3");
					}
}

					



					
	return 1;
}
int help (object me)
{
        write(@HELP
指令格式: shutdown
 
刷新随机武器系统
 
HELP
);
        return 1;
}
 
