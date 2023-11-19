//Byzjb@ty|2002-6-17|
#include <ansi.h>
string desinq(object me,object ob)
{
	 string str;
	str = ZJOBACTS+ZJMENUF(1,4,10,32);

	

	if(str!=(ZJOBACTS+ZJMENUF(1,4,10,32))) str += ZJSEP;
	
	// str += "帮助列表:help list"ZJSEP; 
	 str +="地图列表:bz maps"ZJSEP; 
	 str +="门派简介:bz menpai"ZJSEP; 
	 str +="玩家相关:bz user"ZJSEP; 
	str += "任务系统:bz tasks"ZJSEP; 
	str += "功夫相关:bz kungfu"ZJSEP; 
	str += "秘密介绍:bz mimi"ZJSEP; 
	 



	if(str==(ZJOBACTS+ZJMENUF(1,4,9,32))) str = "";
	return str+"\n";
}
string desinq1(object me,object ob)
{
	 string str;
	str = ZJOBACTS+ZJMENUF(1,4,10,32);

	

	if(str!=(ZJOBACTS+ZJMENUF(1,4,10,32))) str += ZJSEP;
	
	// str += "帮助列表:help list"ZJSEP; 
	 str +="地图列表:bz maps"ZJSEP; 
	 str +="门派简介:bz menpai"ZJSEP; 
	 //str +="玩家相关:bz user"ZJSEP; 
	str += "任务系统:bz tasks"ZJSEP; 
	str += "功夫相关:bz kungfu"ZJSEP; 
	str += "秘密介绍:bz mimi"ZJSEP; 
	 



	if(str==(ZJOBACTS+ZJMENUF(1,4,9,32))) str = "";
	return str+"\n";
}
string desinq2(object me,object ob)
{
	 string str;
	str = ZJOBACTS+ZJMENUF(1,4,10,32);

	

	if(str!=(ZJOBACTS+ZJMENUF(1,4,10,32))) str += ZJSEP;
	
	// str += "帮助列表:help list"ZJSEP; 
	 str +="地图列表:bz maps"ZJSEP; 
	 str +="门派简介:bz menpai"ZJSEP; 
	 str +="玩家相关:bz user"ZJSEP; 
	//str += "任务系统:help tasks"ZJSEP; 
	str += "功夫相关:bz kungfu"ZJSEP; 
	str += "秘密介绍:bz mimi"ZJSEP; 
	 



	if(str==(ZJOBACTS+ZJMENUF(1,4,9,32))) str = "";
	return str+"\n";
}
string desinq3(object me,object ob)
{
	 string str;
	str = ZJOBACTS+ZJMENUF(1,4,10,32);

	

	if(str!=(ZJOBACTS+ZJMENUF(1,4,10,32))) str += ZJSEP;
	
	// str += "帮助列表:help list"ZJSEP; 
	 str +="地图列表:bz maps"ZJSEP; 
	 str +="门派简介:bz menpai"ZJSEP; 
	 str +="玩家相关:bz user"ZJSEP; 
	str += "任务系统:bz tasks"ZJSEP; 
	//str += "功夫相关:bz kungfu"ZJSEP; 
	str += "秘密介绍:bz mimi"ZJSEP; 
	 



	if(str==(ZJOBACTS+ZJMENUF(1,4,9,32))) str = "";
	return str+"\n";
}
string desinq4(object me,object ob)
{
	 string str;
	str = ZJOBACTS+ZJMENUF(1,4,10,32);

	

	if(str!=(ZJOBACTS+ZJMENUF(1,4,10,32))) str += ZJSEP;
	
	// str += "帮助列表:help list"ZJSEP; 
	 str +="地图列表:bz maps"ZJSEP; 
	 str +="门派简介:bz menpai"ZJSEP; 
	 str +="玩家相关:bz user"ZJSEP; 
	str += "任务系统:bz tasks"ZJSEP; 
	str += "功夫相关:bz kungfu"ZJSEP; 
	//str += "秘密介绍:bz mimi"ZJSEP; 
	 



	if(str==(ZJOBACTS+ZJMENUF(1,4,9,32))) str = "";
	return str+"\n";
}
string desinq5(object me,object ob)
{
	 string str;
	str = ZJOBACTS+ZJMENUF(1,4,10,32);

	

	if(str!=(ZJOBACTS+ZJMENUF(1,4,10,32))) str += ZJSEP;
	
	// str += "帮助列表:help list"ZJSEP; 
	 str +="地图列表:bz maps"ZJSEP; 
	 //str +="门派简介:bz menpai"ZJSEP; 
	 str +="玩家相关:bz user"ZJSEP; 
	str += "任务系统:bz tasks"ZJSEP; 
	str += "功夫相关:bz kungfu"ZJSEP; 
	str += "秘密介绍:bz mimi"ZJSEP; 
	 



	if(str==(ZJOBACTS+ZJMENUF(1,4,9,32))) str = "";
	return str+"\n";
}
string desinq6(object me,object ob)
{
	 string str;
	str = ZJOBACTS+ZJMENUF(1,4,10,32);

	

	if(str!=(ZJOBACTS+ZJMENUF(1,4,10,32))) str += ZJSEP;
	
	// str += "帮助列表:help list"ZJSEP; 
	 //str +="地图列表:bz maps"ZJSEP; 
	 str +="门派简介:bz menpai"ZJSEP; 
	 str +="玩家相关:bz user"ZJSEP; 
	str += "任务系统:bz tasks"ZJSEP; 
	str += "功夫相关:bz kungfu"ZJSEP; 
	str += "秘密介绍:bz mimi"ZJSEP; 
	 



	if(str==(ZJOBACTS+ZJMENUF(1,4,9,32))) str = "";
	return str+"\n";
}
int main(object me, string arg)
{
	object ob;
	
        string str;

        
	if ( !arg ) {
		str = ZJOBLONG+"综合帮助系统:"+ZJBR+NOR;
		str += "此系统含有大量的攻略以及教程，请耐心阅读，当你读完以后对此游戏的理解也就足够了"+ZJBR+NOR;
		str += "某些地方的改动导致帮助文件没有更新，不要介意"+ZJBR+NOR;
	    str += "\n" NOR;
		str += ZJOBACTS2+ZJMENUF(2,2,9,35);
		
	    str += "常见问题:help faq"+ZJSEP;
		str += "新手上路:help newbie"+ZJSEP;
		str += "游戏介绍:help intro"+ZJSEP;
		str += "留言板使用指南:help board"+ZJSEP;
		str += "频道说明:help channel"+ZJSEP;
		str += "帮助大高手:help grobot"+ZJSEP;
		
/*str = replace_string(str,"\n",ZJBR);
	if(str[(strlen(str)-4)..(strlen(str)-1)]=="$br#")
		str = str[0..(strlen(str)-5)];*/
	str += "\n";
	str += desinq(me,ob);
	write(str+"\n");
     return 1;


	}
	if ( arg== "user" ) {
		
		str = ZJOBLONG"玩家相关\n"ZJOBACTS2+ZJMENUF(2,2,9,35);
		
	    str += "命令说明:help cmds"+ZJSEP;
		str += "生活相关提示:help userlife"+ZJSEP;
		str += "游戏规则:help rules"+ZJSEP;
		str += "游戏参数等的设定:help settings"+ZJSEP;
		str += "商业:help business"+ZJSEP;
		str += "随从:help suicong"+ZJSEP;
		

	str += "\n";
	str += desinq1(me,ob);
	message("vision", str+"\n", me);
     return 1;
	}
	if ( arg== "kungfu" ) {
		str = ZJOBLONG"功夫相关\n"ZJOBACTS2+ZJMENUF(2,2,9,35);
	//	str = ZJOBACTS2+ZJMENUF(2,2,9,35);
		
	    str += "读书指南:help kungfu-book"+ZJSEP;
		str += "内功介绍:help kungfu-force"+ZJSEP;
		str += "级别介绍:help kungfu-level"+ZJSEP;
		str += "公共武功:help kungfu-public"+ZJSEP;
		str += "自创武功:help kungfu-selfcreate"+ZJSEP;
		str += "自创门派:help selfcreate-menpai"+ZJSEP;
		str += "特殊技能:help kungfu-special"+ZJSEP;
str += "\n";
str += desinq3(me,ob);		
write(str+"\n");
     return 1;
	}
	if ( arg== "menpai" ) {
		
		str = ZJOBLONG"门派系统\n"ZJOBACTS2+ZJMENUF(2,2,9,35);
		
	    str += "白驼:help menpai-baituo"+ZJSEP;
		str += "朝廷:help menpai-chaoting"+ZJSEP;
		str += "大轮寺:help menpai-dalunsi"+ZJSEP;
		str += "峨嵋:help menpai-emei"+ZJSEP;
		str += "丐帮:help menpai-gaibang"+ZJSEP;
		str += "古墓:help menpai-gumu"+ZJSEP;
		str += "华山:help menpai-huashan"+ZJSEP;
		str += "灵鹫:help menpai-lingjiu"+ZJSEP;
		str += "凌霄城（雪山）:help menpai-lingxiao"+ZJSEP;
		str += "明教:help menpai-mingjiao"+ZJSEP;
		str += "慕容:help menpai-murong"+ZJSEP;
		str += "全真:help menpai-quanzhen"+ZJSEP;
		str += "日月教:help menpai-riyuejiao"+ZJSEP;
		str += "少林:help menpai-shaolin"+ZJSEP;
		str += "神龙教:help menpai-shenlongjiao"+ZJSEP;
		str += "桃花岛:help menpai-taohuadao"+ZJSEP;
		str += "天龙:help menpai-tianlongsi"+ZJSEP;
		str += "天地会:help menpai-tiandihui"+ZJSEP;
		str += "武当:help menpai-wudang"+ZJSEP;
		str += "星宿:help menpai-xingxiu"+ZJSEP;
		
str += "\n";
str += desinq5(me,ob);		
write(str+"\n");
     return 1;
	}
	if ( arg== "maps" ) {
		
		
		str = ZJOBLONG"地图系统\n"ZJOBACTS2+ZJMENUF(2,2,9,35);
		
	    str += "白驼:help map-baituo"+ZJSEP;
		str += "北京:help map-beijing"+ZJSEP;
		str += "朝廷:help map-beijing"+ZJSEP;
		str += "冰火岛:help map-bhd"+ZJSEP;
		str += "长安:help map-changan"+ZJSEP;
		str += "关外:help map-changbai"+ZJSEP;
		str += "长江:help map-changjiang"+ZJSEP;
		str += "长江北岸:help map-changjiangnorth"+ZJSEP;
		str += "成都:help map-chengdu"+ZJSEP;
		str += "大理:help map-dalicheng"+ZJSEP;
		str += "大轮寺:help map-dalunsi"+ZJSEP;
		str += "钓鱼岛:help map-dyd"+ZJSEP;
		str += "峨嵋:help map-emei"+ZJSEP;
		str += "福州:help map-fuzhou"+ZJSEP;
		str += "丐帮:help map-gaibang"+ZJSEP;
		str += "归云庄:help map-guiyun"+ZJSEP;
		str += "古墓:help map-gumu"+ZJSEP;
		str += "临安府:help map-hangzhou"+ZJSEP;
		str += "黄河:help map-huanghe"+ZJSEP;
		str += "黄河北岸:help map-huanghenorth"+ZJSEP;
		str += "华山:help map-huashan"+ZJSEP;
		str += "江州:help map-jiangzhou"+ZJSEP;
		str += "铁掌峰:help map-jiaofei"+ZJSEP;
		str += "嘉兴:help map-jiaxing"+ZJSEP;
		str += "康亲王府:help map-kangqin"+ZJSEP;
		str += "昆明:help map-kunming"+ZJSEP;
		str += "灵鹫:help map-lingjiu"+ZJSEP;
		str += "凌霄城:help map-lingxiao"+ZJSEP;
		str += "灵州:help map-lingzhou"+ZJSEP;
		str += "洛阳:help map-luoyang"+ZJSEP;
		str += "江南梅庄:help map-meizhuang"+ZJSEP;
		str += "明教:help map-mingjiao"+ZJSEP;
		str += "慕容:help map-murong"+ZJSEP;
		str += "南昌:help map-nanchang"+ZJSEP;
		str += "平西王府:help map-pingxi"+ZJSEP;
		str += "杀手帮:help map-pker"+ZJSEP;
		str += "全真:help map-quanzhen"+ZJSEP;
		str += "泉州:help map-quanzhou"+ZJSEP;
		str += "曲阜:help map-qufu"+ZJSEP;
		str += "日月教:help map-riyuejiao"+ZJSEP;
		str += "张家口:help map-saiwai"+ZJSEP;
		str += "少林:help map-shaolin"+ZJSEP;
		str += "神龙岛:help map-shenlongdao"+ZJSEP;
		str += "苏州:help map-suzhou"+ZJSEP;
		str += "泰山:help map-taishan"+ZJSEP;
		str += "桃花:help map-taohuadao"+ZJSEP;
		str += "天地会:help map-tiandihui"+ZJSEP;
		str += "天龙寺:help map-tianlong"+ZJSEP;
		str += "天坛:help map-tiantan"+ZJSEP;
		str += "武当:help map-wudang"+ZJSEP;
		str += "襄阳:help map-xiangyang"+ZJSEP;
		str += "华山村:help map-xiaocun"+ZJSEP;
		str += "星宿:help map-xingxiu"+ZJSEP;
		str += "信阳:help map-xinyang"+ZJSEP;
		str += "侠客岛:help map-xkd"+ZJSEP;
		str += "扬州:help map-yangzhou"+ZJSEP;
		str += "牙山:help map-yashan"+ZJSEP;
		str += "桃源:help map-yideng"+ZJSEP;
		str += "建康府北城:help map-yingtiannorth"+ZJSEP;
		str += "建康府南城:help map-yingtiansouth"+ZJSEP;
		str += "建康府都府:help map-dufu"+ZJSEP;
		str += "岳王墓:help map-ywm"+ZJSEP;
		str += "镇江:help map-zhenjiang"+ZJSEP;
		str += "中原:help map-zhongyuan"+ZJSEP;
		str += "紫禁城:help map-zijin"+ZJSEP;
		
		
str += "\n";
str += desinq6(me,ob);		
write(str+"\n");
     return 1;
	}
	if ( arg== "mimi" ) {
		
		str = ZJOBLONG"解密系统\n"ZJOBACTS2+ZJMENUF(2,2,9,35);
		
	    str += "冰火岛:help mimi-bhd"+ZJSEP;
		str += "鹿鼎山:help mimi-book42"+ZJSEP;
		str += "出师:help mimi-chushi"+ZJSEP;
		str += "大明体系:help mimi-daming"+ZJSEP;
		str += "随机装备:help mimi-equip"+ZJSEP;
		str += "宝石系统:help mimi-gem"+ZJSEP;
		str += "杀手帮:help mimi-pker"+ZJSEP;
		str += "麒麟村:help mimi-qilincun"+ZJSEP;
		str += "侠客岛:help mimi-xkd"+ZJSEP;
		str += "岳王墓:help mimi-ywm"+ZJSEP;
		str += "一灯大师:help mimi-yideng"+ZJSEP;
		str += "高级兵器:help mimi-gaojibingqi"+ZJSEP;
		str += "左右互搏:help mimi-hubo"+ZJSEP;
		str += "江南八镇:help mimi-bazhen"+ZJSEP;
		str += "晋阳药铺:help mimi-yaopu"+ZJSEP;
		str += "易容术:help mimi-yirongshu"+ZJSEP;
		str += "游方和尚:help mimi-youfang"+ZJSEP;
		
str += "\n";
str += desinq4(me,ob);		
write(str+"\n");
     return 1;
	}
	if ( arg== "tasks" ) {
		
		str = ZJOBLONG"任务系统\n"ZJOBACTS2+ZJMENUF(2,2,9,35);
		
	    str += "门派独特任务:help task-menpai"+ZJSEP;
		str += "门派忠诚任务:help wiz"+ZJSEP;
		str += "新手任务:help task-newbie"+ZJSEP;
		str += "星宿新手任务:help newbie-xingxiu"+ZJSEP;
		str += "少林新手任务:help newbie-shaolin"+ZJSEP;
		str += "武当新手任务:help newbie-wudang"+ZJSEP;
		str += "明教新手任务:help newbie-mingjiao"+ZJSEP;
		str += "华山新手任务:help newbie-huashan"+ZJSEP;
		str += "峨嵋新手任务:help newbie-emei"+ZJSEP;
		str += "桃花新手任务:help newbie-taohua"+ZJSEP;
		str += "日月新手任务:help newbie-riyuejiao"+ZJSEP;
		str += "古墓新手任务:help newbie-gumu"+ZJSEP;
		str += "天龙新手任务:help newbie-tianlong"+ZJSEP;
		str += "全真新手任务:help newbie-quanzhen"+ZJSEP;
		str += "丐帮新手任务:help newbie-gaibang"+ZJSEP;
		str += "公共任务:help task-public"+ZJSEP;
		str += "百晓生:help task-bxs"+ZJSEP;
		str += "保卫襄阳:help task-baowei"+ZJSEP;
		str += "藏经阁:help task-cjg"+ZJSEP;
		str += "甲午海战:help task-haizhan"+ZJSEP;
		str += "韩元外复仇:help task-han"+ZJSEP;
		str += "护镖:help task-hubiao"+ZJSEP;
		str += "护送:help task-husong"+ZJSEP;
		str += "护卫:help task-huwei"+ZJSEP;
		str += "胡一刀:help task-huyidao"+ZJSEP;
		str += "剿匪:help task-jiaofei"+ZJSEP;
		str += "门派比武:help task-mpbiwu"+ZJSEP;
		str += "慕容玉玺:help task-murong"+ZJSEP;
		str += "鄱阳湖漂流:help task-piaoliu"+ZJSEP;
		str += "神尼:help task-shenni"+ZJSEP;
		str += "史可法:help task-skf"+ZJSEP;
		str += "华山送信:help task-songxin"+ZJSEP;
		str += "task任务:help task-task"+ZJSEP;
		str += "铜雀台:help task-tqt"+ZJSEP;
		str += "投名状:help task-tmz"+ZJSEP;
		str += "万安塔:help task-wananta"+ZJSEP;
		str += "萧半和鸳鸯刀:help task-xbh"+ZJSEP;
		str += "萧峰:help task-xiaofeng"+ZJSEP;
str += "\n";
str += desinq2(me,ob);		
write(str+"\n");
     return 1;
	}
}

