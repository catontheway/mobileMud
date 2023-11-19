#include <ansi.h>

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

string *typew=({
"sword",
"blade",
"hammer",
"whip",
"club",
"staff",
"throwing",
"dagger",
"axe",
});
string *typea=({
"hands",
"cloth",
"armor",
"boots",
"head",
"neck",
"surcoat",
"shield",
"waist",
"wrists",
});
mapping *TYPE1 = ({
        (["TYPE1":"SWORD","TYPE2":"sword","TYPE3":"剑","TYPE4":"把"]),
        (["TYPE1":"BLADE","TYPE2":"blade","TYPE3":"刀","TYPE4":"柄"]),
        (["TYPE1":"HAMMER","TYPE2":"hammer","TYPE3":"锤","TYPE4":"柄"]),
        (["TYPE1":"WHIP","TYPE2":"whip","TYPE3":"鞭","TYPE4":"根"]),
        (["TYPE1":"CLUB","TYPE2":"club","TYPE3":"棍","TYPE4":"根"]),
        (["TYPE1":"STAFF","TYPE2":"staff","TYPE3":"杖","TYPE4":"根"]),
        (["TYPE1":"THROWING","TYPE2":"throwing","TYPE3":"暗器","TYPE4":"支"]),        	        	        	
        (["TYPE1":"DAGGER","TYPE2":"dagger","TYPE3":"匕首","TYPE4":"把"]),        	        	        	        	
        (["TYPE1":"AXE","TYPE2":"axe","TYPE3":"斧","TYPE4":"柄"]), 	
});

mapping *TYPE2 = ({
        (["TYPE1":"HANDS","TYPE2":"hands","TYPE3":"手套","TYPE4":"副"]),
        (["TYPE1":"CLOTH","TYPE2":"cloth","TYPE3":"服装","TYPE4":"件"]),
        (["TYPE1":"ARMOR","TYPE2":"armor","TYPE3":"披风","TYPE4":"件"]),
        (["TYPE1":"BOOTS","TYPE2":"boots","TYPE3":"靴","TYPE4":"双"]),
        (["TYPE1":"HEAD","TYPE2":"head","TYPE3":"头盔","TYPE4":"顶"]),
        (["TYPE1":"NECK","TYPE2":"neck","TYPE3":"项链","TYPE4":"串"]),
        (["TYPE1":"SURCOAT","TYPE2":"surcoat","TYPE3":"肚带","TYPE4":"条"]),
        (["TYPE1":"SHIELD","TYPE2":"shield","TYPE3":"盾","TYPE4":"面"]),
        (["TYPE1":"WAIST","TYPE2":"waist","TYPE3":"腰带","TYPE4":"条"]),        	        	        	
        (["TYPE1":"WRISTS","TYPE2":"wrists","TYPE3":"护腕","TYPE4":"双"]),        	        	        	        	
        	
});


mapping *TYPE3 = ({
        (["TYPE1":HIY"金"NOR,"TYPE2":"wtypeA"]),
        (["TYPE1":CYN"木"NOR,"TYPE2":"wtypeB"]),
        (["TYPE1":GRN"水"NOR,"TYPE2":"wtypeC"]),
        (["TYPE1":RED"火"NOR,"TYPE2":"wtypeD"]),
        (["TYPE1":YEL"土"NOR,"TYPE2":"wtypeE"]),
        (["TYPE1":HIM"风"NOR,"TYPE2":"wtypeF"]),
        (["TYPE1":HIW"雷"NOR,"TYPE2":"wtypeG"]),
        (["TYPE1":HIB"电"NOR,"TYPE2":"wtypeH"]),
        (["TYPE1":WHT"天"NOR,"TYPE2":"wtypeI"]),
        (["TYPE1":BBLK"地"NOR,"TYPE2":"wtypeJ"]),
        (["TYPE1":HIC"人"NOR,"TYPE2":"wtypeK"]),
        (["TYPE1":HIR"魔"NOR,"TYPE2":"wtypeL"]),        	        	        	        	        	        	        	        	        	        	        	    	        	        	        	
        	
});

nosave mapping	Special_Class =	([
RED"干将" : ([	"id": "ganjiang",
		"long2"	: RED"干将威力无比，能开天辟地，荡妖除魔！\n"NOR,
		"weapon_prop":         ([ "damage":70 ]),//180
		"sharpness":	       10,
		"rigidity":	       9,
		]),
RED"莫邪" : ([	"id": "moye",
		"long2"	: RED"莫邪锋利无比，能开天辟地，荡妖除魔！\n"NOR,
		"weapon_prop":         ([ "damage":70 ]),//130
		"sharpness":	       15,
		"rigidity":	       9,
		]),
RED"鱼肠" : ([	"id": "yuchang",
		"long2"	: RED"鱼肠轻巧无比，能开天辟地，荡妖除魔！\n"NOR,
		"weapon_prop":         ([ "damage":70 , "attack":150 ]),//100
		"sharpness":	       8,
		"rigidity":	       7,
		]),
RED"太阿" : ([	"id": "taie",
		"long2"	: RED"太阿帝王之兵，持之能号令天下，莫有不从！\n"NOR,
		"weapon_prop":         ([ "damage":70 , "qi":2000 , "jing":1000 ]),//100
		"sharpness":	       7,
		"rigidity":	       9,
		]),
RED"巨阙" : ([	"id": "juque",
		"long2"	: RED"巨阙坚硬无比，能开天辟地，荡妖除魔！\n"NOR,
		"weapon_prop":         ([ "damage":70 ]),//120
		"sharpness":	       7,
		"rigidity":	       20,
		]),
RED"纯钩" : ([	"id": "chungou",
		"long2"	: RED"纯钩将帅之兵，持之能挥军百万，克敌制胜！\n"NOR,
		"weapon_prop":         ([ "damage":70 , "jingli":1000 , "neili":2000 ]),//120
		"sharpness":	       7,
		"rigidity":	       8,
		]),
RED"湛卢" : ([	"id": "zhanlu",
		"long2"	: RED"湛卢威力、锋利、坚硬都冠绝当世，乃千古神兵！\n"NOR,
		"weapon_prop":         ([ "damage":70 ]),//160
		"sharpness":	       12,
		"rigidity":	       12,
		]),
RED"工布" : ([	"id": "gongbu",
		"long2"	: RED"工布天生怪异，功能参商！\n"NOR,
		"weapon_prop":         ([ "damage":70 , "attack":100 , "parry":75 , "dodge":75 ]),//70
		"sharpness":	       10,
		"rigidity":	       9,
		]),
RED"胜邪" : ([	"id": "shengxie",
		"long2"	: RED"胜邪威力巨大而无任何要求！\n"NOR,
		"weapon_prop":         ([ "damage":70 ]),//70
		"sharpness":	       8,
		"rigidity":	       9,
		"wield_maxneili":      0,
		"wield_neili":	       0,
		"wield_str":	       0,
		]),
RED"龙泉" : ([	"id": "longquan",
		"long2"	: RED"龙泉人间极品，武林至宝！\n"NOR,
		"weapon_prop":         ([ "damage":100 , "dexerity":5 , "strength":5 , "constitution":5 , "intelligence":5 ]),
		"sharpness":	       9,
		"rigidity":	       7,
		]),
]);

nosave mapping	Super_Class = ([
	HIM"轩辕" : ([	"id":	"xuanyuan",	
			"long2": HIM"昔日黄帝持此物立于指南车上，驱迷雾，扫阴霾，率应龙旱魃，御百兽而战蚩尤！\n"NOR,
		]),
	HIR"神通" : ([	"id":	"shentong",
			"long2":	HIR"天兵神通，走势要平善，气要随行，两眼顾尖，气沉两足稳，身法需自然，身行如飞燕，身落如停风，收如花絮，刺如钢钉！\n"NOR,
		]),
	HIG"无极" : ([	"id":	"wuji",		
			"long2": HIG"此物已达出神入化，登峰造极，神乎其神之境界！俗说万物归宗，便是这“无极”！\n"NOR,
		]),
	HIW"八卦" : ([	"id":	"bagua",	
			"long2": HIW"八卦有“休”“生”“伤”“杜”“死”“景”“惊”“开”之别，创自诸葛武候，集天下万变于一身！\n"NOR,
		]),
	HIB"乔依乌斯" :	([	"id":	"joeywus",	
			"long2": HIB"在西方查理曼统治的时代，最简朴的剑也能值三头母牛的价钱。而查理大帝自己的那把传奇式的神兵“乔依乌斯”据说是半人半神的“韦兰铁匠”所造，乃当世界神兵！\n"NOR,
		]),
	HIW"太白" : ([	"id":	"taibai",	
			"long2": HIW"赵客缦胡缨  吴钩霜雪明\n"
			             "银鞍照白马  飒沓如流星\n"
		"十步杀一人  千里不留行	\n"	
		"事了拂衣去  深藏身与名\n"
		"闲过信陵饮  脱剑膝前横	\n"
		"将炙□朱亥  持觞劝侯嬴\n"
		"三杯吐然诺  五狱倒为轻\n"
		"眼花耳热後  意气素霓生\n"
		"救赵挥金槌  邯郸先震惊\n"
		"千秋二壮士  喧赫大梁城\n"
		"纵死侠骨香  不惭世上英\n"
		"谁能书阁下  白首太玄经\n"NOR,
		]),
	HIY"乾坤" : ([	"id":	"qiankun",	
			"long2": HIY"此物左右两边分别以黑白两种奇铁溶铸而成，一黑一白，切合乾坤，包含阴阳之气，好一柄宝物！\n"NOR,
		]),
	HIY"太极" : ([	"id":	"taiji",	
			"long2": HIY"太极者，无极而生，阴阳之母也。动之则分，静之则合。无过不及，随曲就伸。人刚我柔谓之走，我顺人背谓之粘。动急则急应，动缓则缓随。虽变化万端，而理为一贯！\n"NOR,
		]),
	HIC"天地" : ([	"id":	"tiandi",	
			"long2": HIC"天地之初，女娲补天所留下的天地间至尊之物之一经千秋万载所制，功能开天劈地！\n"NOR,
		]),
	HIM"风云" : ([	"id":	"fengyun",	
			"long2": HIM"所谓风云际会，天地变色！仗此行千里，老魔小丑，岂堪一击！\n"NOR,
		]),
	HIG"浩气" : ([	"id":	"haoqi",	
			"long2": HIG"天地浩气之神兵，扫魔除妖，为国为民，侠之大者！\n"NOR,
		]),
	HIR"炼狱" : ([	"id":	"lianyu",	
			"long2": HIR"三十三天下有地，地下有城，城名鬼城，大小妖魔，人神畜生都在此轮回往返，谓之“炼狱”！\n"NOR,
		]),
	HIC"三清" : ([	"id":	"sanqing",	
			"long2": HIC"大道无名，聚气成形，功参造化，一是三清！这便是“老子一罡化三清。”\n"NOR,
		]),
	HIC"昆仑" : ([	"id":	"kunlun",	
			"long2": HIC"	笑江湖浪迹十年游，空负少年头。\n"
	"对铜陀巷泊，吟情渺渺，心事悠悠！ \n"
	"酒令诗残梦断，南国正清愁。 \n"
	"把剑凄然望，无处招归舟。 \n"
 
	"明月天涯路远，问谁留楚佩，弄影中洲？\n"
	"数英雄儿女，俯仰古今愁。\n"
	"难消受灯昏罗帐，伥昙花一现恨难休！\n"
	"飘零惯，金戈铁马，拼葬荒丘！ \n"NOR,
		]),
]);


nosave mapping	Great_Class = ([
	CYN"帝王":	"diwang",	CYN"王者":	"wangzhe",
	CYN"天后":	"tianhou",	CYN"霸王":	"bawang",   
	CYN"天圣":	"tiansheng",	CYN"神王":	"shenwang",   
	CYN"妖后":	"yaohou",	BLU"公侯":	"gonghou", 
	BLU"魔王":	"mowang",	BLU"七星":	"qixing", 
	BLU"恶鬼":	"egui",		GRN"玉龙":	"yulong", 
	GRN"玉凤":	"yufeng",	GRN"松鹤":	"songhe",
	GRN"天龙":	"tianlong",	GRN"地龙":	"dilong",
	GRN"天凤":	"tianfeng",	GRN"地凤":	"difeng",
	GRN"龙翔":	"longxiang",	GRN"凤舞":	"fengwu",
	HIG"无影":	"wuying",	HIG"破甲":	"pojia",
	HIG"飞龙":	"feilong",	HIG"武翼":	"wuyi",
	HIG"鸟翔":	"niaoxiang",	HIG"婉盘":	"wanpan",
	HIG"青萍":	"qingping",	YEL"黄龙":	"huanglong",
	WHT"云梯":	"yunti",	WHT"太渊":	"taiyuan",
	WHT"太风":	"taifeng",	WHT"虚灵":	"xuling",
	WHT"霹雳":	"pili",		WHT"雷电":	"leidian",
	WHT"风雷":	"fenglei",	WHT"震电":	"zhendian",
	WHT"白玉":	"baiyu",	WHT"青玉":	"qingyu",
	WHT"紫玉":	"ziyu",		WHT"蓝玉":	"lanyu",
	WHT"绿玉":	"luyu",		WHT"黄玉":	"huangyu",
	WHT"赤玉":	"chiyu",	WHT"红玉":	"hongyu",
	CYN"青虹":	"qinghong",	CYN"白虹":	"baihong",
	CYN"紫虹":	"zihong",	CYN"蓝虹":	"lanhong",
	CYN"绿虹":	"luhong",	CYN"赤虹":	"chihong",
	CYN"幻影":	"huanying",	CYN"凝霜":	"ningshuang",
	CYN"青索":	"qingsuo",	MAG"天龙":	"tianlong",
	MAG"紫电":	"zidian",	MAG"凤凰":	"fenghuang",
	MAG"天枢":	"tianqu",	MAG"天璇":	"tianxuan",
	MAG"天玑":	"tianji",	MAG"天权":	"tianquan",
	MAG"玉衡":	"yuheng",	MAG"开阳":	"kaiyang",
	MAG"摇光":	"yaoguang",	MAG"北斗":	"beidou",
	HIR"天火":	"tianhuo",	HIR"麒麟":	"qilin",
	HIR"辟邪":	"pixie",	YEL"鸿钧":	"hongjun",
	YEL"广成":	"guangcheng",	YEL"金光":	"jinguang",
	YEL"修罗":	"xiuluo",	YEL"夜叉":	"yecha",
	YEL"瑶池":	"yaochi",	YEL"泪痕":	"leiheng",
	HIR"火龙":	"huolong",	HIC"冰龙":	"binglong",
	HIB"黑龙":	"heilong",	HIR"炎龙":	"yanlong",
	HIC"青龙":	"qinglong",	HIR"朱雀":	"zhuque",
	HIW"白虎":	"baihu",	HIB"玄武":	"xuanwu",	
	GRN"玄机":	"xuanji",	HIG"九天":	"jiutian",
	HIG"九幽":	"jiuyou",	MAG"九龙":	"jiulong",
	MAG"五龙":	"wulong",	MAG"三龙":	"sanlong",
	WHT"生死":	"shengsi",
]);

nosave string *G_3_class = ({
	"春雨",	"夏雨",	"秋雨",	"冬雨",	"春兰",	"夏荷",	"秋菊",	"冬梅",
	"玉泉",	"羽泉",	"风泉",	"虎泉",	"怒涛",	"江河",	"漩流",	"清水",
	"青锋",	"双锋",	"锐气",	"必胜",	"吴钩",	"桃花",	"无敌",	"双手",	
	"吉祥",	"天女",	"花纹",	"暗光",	"松纹",	"蟠钢",	"龟文",	"盘古",
	"缦理",	"流水",	"芙蓉",	"深渊",	"高山",	"大川",	"流波",	"冰释",
	"鱼鳞",	"兽皮",	"开山",	"倒海",	"复体",	"锯齿",	"沧海",	"天门",	
	"地门",	"雁翎",	"飞燕",	"燕尾",	"慑魂",	"夺魂",	"弦月",	"连衡",	
	"鬼号",	"厉鬼",	"鬼头",	"鬼王",	"牛头",	"拘魂",	"魂魄",	"寒光",	
	"阴蛇",	"照海",	"地狱",	"龙头",	"猛虎",	"曙光",	"泼水",	"暗光",
	"晦光",	"明光",	"天光",	"神光",	"鬼气",	"仙品",	"天水",	"地水",
	"天锋",	"地锋",	"天雨",	"神雨",	"鬼雨",	"地雨",	"仙雨",	"魔雨",
	"神水",	"仙水",	"魔水",	"毒蛇",	"五步",	"竹叶",	"柳叶",	"天竹",
	"地竹",	"神竹",	"魔竹",	"伤痕",	"飞武",	"猛虎",	"猛狮",	"啸天",
	"幻风",	"望月",	"明月",	"赶月",	"弯月",	"豹枭",	"虎枭",	"狮枭",
	"野狼",	"狂狼",	"狂龙",	"神狼",	"神狮",	"神虎",	"神豹",	"神鹰",
	"天羽",	"地羽",	"泪痕",	"浪云",	"乌发",	"蝉鬓",	"云髻",	"雾鬟",
	"娥眉",	"青黛",	"明眸",	"流盼",	"朱唇",	"皓齿",	"玉指",	"素臂",
	"晓翠",	"春江",	"夜月",	"啼莺",	"慈云",	"浮云",	"青云",	"朝云",
	"夜云",	"飞云",	"卷云",	"白云",	"蓝云",	"紫云",	"红云",	"赤云",
	"鸿门",	"蛟龙",	"雷霆",	"狮吼",	"卧虎",	"青羊",	"老君",	"斗母",
	"贺兰",	"日月",	"玉门",	"阡陌",	"纵横",	"承天",	"延永",	"玉皇",
});


nosave string *G_4_class = ({
	"松柏",	"须弥",	"秀骨",	"清相",	"洛神",	"璎络",	"圣母",	"文昌",
	"武圣",	"南天",	"北天",	"西天",	"东天",	"飞雪",	"飘雪",	"落雪",
	"白雪",	"梦雪",	"雪花",	"烟雨",	"霞蔚",	"赤霞",	"潇湘",	"瀚海",
	"牡丹",	"百合",	"白荷",	"龙菊",	"幽兰",	"翡翠",	"寒梅",	"青竹",
	"相思",	"云竹",	"海棠",	"芍药",	"杜鹃",	"玫瑰",	"月季",	"四季",
	"芙蓉",	"蔷薇",	"苍岩",	"天师",	"洗心",	"常青",	"翻天",	"降魔",
	"風鈴",	"風信",	"紫陽",	"丹陽",	"紫薇",	"木樨",	"富貴",	"太陽",
	"火鶴",	"青鶴",	"白鶴",	"紫鶴",	"白薇",	"蓝薇",	"青薇",	"火薇",
	"冰薇",	"青陽",	"白陽",	"火陽",	"冰陽",	"天秤",	"巨蟹",	"金牛",
	"扣骨",	"渡心",	"含翠",	"蝙蝠",	"月形",	"黑云",	"铁鲨",	"撼山",
	"断玉",	"摘星",	"探星",	"飞星",	"黑魅",	"绿影",	"玉魔",	"银铃",
	"金铃",	"千仞",	"晶电",	"千芒",	"阴霾",	"魔袱",	"戈壁",
	"蚁峻",	"矗页",	"睚眦",	"螭吻",	"蒲牢",	"饕餮",	"蜍夏",	"椒图",
	"血斩", "天威", "旋风", "紫芒", "削岩", "万丈", "星龙", "月龙",
	"巨威", "影残", "璨星", "裂心", "双星", "望霞", "翠屏", "朝云",
	"松峦", "集仙", "聚鹤", "净坛", "上升", "起云", "飞凤", "登龙",
	"聚泉",
});

nosave string *G_5_class = ({
	"巨",	"大",	"小",	"怪",	"阖",	"阔",	"宾",	"叠",
	"钢",	"铁",	"竹",	"柔",	"韧",	"铁",	"铜",	"巧",

});

mapping *BOOK1 = ({
        (["TYPE1":"轻功","TYPE2":"dodge"]),
        (["TYPE1":"斧法","TYPE2":"axe"]),
        (["TYPE1":"刀法","TYPE2":"blade"]),
        (["TYPE1":"爪法","TYPE2":"claw"]),
        (["TYPE1":"棍法","TYPE2":"club"]),
        (["TYPE1":"拳法","TYPE2":"cuff"]),
        (["TYPE1":"指法","TYPE2":"finger"]),
        (["TYPE1":"内功","TYPE2":"force"]),
        (["TYPE1":"锤法","TYPE2":"hammer"]),
        (["TYPE1":"手法","TYPE2":"hand"]),
        (["TYPE1":"腿法","TYPE2":"leg"]),
        (["TYPE1":"招架","TYPE2":"parry"]),
        (["TYPE1":"杖法","TYPE2":"staff"]),        	        	        	        	        	        	        	        	        	        	        	    	        	        	        	
        (["TYPE1":"掌法","TYPE2":"strike"]),
        (["TYPE1":"剑法","TYPE2":"sword"]),
        (["TYPE1":"暗器","TYPE2":"throwing"]),
        (["TYPE1":"拳脚","TYPE2":"unarmed"]),
        (["TYPE1":"鞭法","TYPE2":"whip"]),  
        	
});



string s_good(int i)
{
	switch(i){
		case 10..60:	return "无比";	
		case 9:		return "无比";	
		case 8:		return "极其";	
		case 7:		return "绝对";	
		case 6:		return "极为";	
		case 5:		return "相当";	
		case 4:		return "十分";	
		case 3:		return "非常";	
		case 2:		return "比较";	
		case 1:		return "还算";	
		case -1:	return "不怎么";	
		case -2:	return "很不";	
		case -3:	return "极不";	
		default:	return "一般";	
	}
}


nosave mapping MDESC_WEAPON = ([
	"hantie":         HIC"万年寒冰铁"NOR,
	"xuantie":	  WHT"玄铁"NOR,
	"shentie":        RED"万年神铁"NOR,
	"jintie":         HIY"金铁"NOR,
	"ruanying":       HIW"软银"NOR,
	"liuhuashi":      RED"流花石"NOR,
	"lushi":          HIG"绿石"NOR,
	"ruantie":        YEL"软铁"NOR,
	"shengtie":       YEL"生铁"NOR,
	"qingtong":       GRN"青铜"NOR,
	"default":        "精钢",
]);

nosave mapping MDESC_ARMOR = ([
	"longcansi":      HIY"龙茧蚕丝"NOR,
	"tiancansi":      WHT"天蚕丝"NOR,
	"bingcansi":      HIW"冰蚕丝"NOR,
	"yucansi":        GRN"玉蚕丝"NOR,
	"mumianhua":      HIY"木棉花"NOR,
	"cansi":          HIW"蚕丝"NOR,
	"zhuma":          HIY"苎麻"NOR,
	"dama":           YEL"大麻"NOR,
	"yama":           YEL"亚麻"NOR,
	"mianhua":        HIW"棉花"NOR,
	"default":        "布料",
]);

nosave mapping MDESC_WYU = ([
	"youyu":          HIW"岫玉"NOR,
	"duyu":           YEL"独玉"NOR,
	"nanyu":          HIY"南玉"NOR,
	"miyu":        HIB"密玉"NOR,
	"fengleiyu":      GRN"风雷玉"NOR,
	"longlingyu":          HIY"龙鳞玉"NOR,
	"default":        HIW"岫玉"NOR,
]);

nosave mapping MDESC_AYU = ([
	"banyu":          HIW"癍玉"NOR,
	"liuyu":           YEL"琉玉"NOR,
	"zhiyu":          HIY"脂玉"NOR,
	"xiangniyu":        HIB"香凝玉"NOR,
	"lvyusui":      GRN"绿玉髓"NOR,
	"fenglingyu":          GRN"凤瓴玉"NOR,
	"default":        HIW"癍玉"NOR,
]);

string s_power(int i)
{
	if( i >= 300 )	return HIR"毁天灭地"NOR;
	if( i >= 280 )	return HIR"开元创世"NOR;	
	if( i >= 260 )	return HIR"天下无双"NOR;	
	if( i >= 240 )	return HIM"绝世罕见"NOR;	
	if( i >= 220 )	return HIY"举世无匹"NOR;
	if( i >= 200 )	return HIG"开天劈地"NOR;
	if( i >= 180 )	return HIB"倚天屠龙"NOR;
	if( i >= 160 )	return HIC"斩妖伏魔"NOR;
	if( i >= 140 )	return RED"无与伦比"NOR;
	if( i >= 120 )	return MAG"极其可怕"NOR;
	if( i >= 100 )	return YEL"很高"NOR;
	if( i >= 80 )	return GRN"水准以上"NOR;
	if( i >= 70 )	return BLU"不错"NOR;
	if( i >	60 )	return CYN"不小"NOR;
	if( i >= 1 )	return CYN"一般"NOR;	
	if( i <= 0 )	return "极差";
	if( i <= -20 )	return "低劣";
	return "一般";
}


string s_powera(int i)
{
	if( i >= 300 )	return HIR"毁天灭地"NOR;
	if( i >= 280 )	return HIR"开元创世"NOR;	
	if( i >= 260 )	return HIR"天下无双"NOR;	
	if( i >= 240 )	return HIM"绝世罕见"NOR;	
	if( i >= 220 )	return HIY"举世无匹"NOR;
	if( i >= 200 )	return HIG"开天劈地"NOR;
	if( i >= 180 )	return HIB"倚天屠龙"NOR;
	if( i >= 160 )	return HIC"斩妖伏魔"NOR;
	if( i >= 140 )	return RED"无与伦比"NOR;
	if( i >= 120 )	return MAG"极其可怕"NOR;
	if( i >= 100 )	return YEL"很高"NOR;
	if( i >= 90 )	return GRN"水准以上"NOR;
	if( i >= 80 )	return BLU"不错"NOR;
	if( i >	50 )	return CYN"不小"NOR;
	if( i >= 1 )	return CYN"一般"NOR;	
	if( i <= 0 )	return "极差";
	if( i <= -20 )	return "低劣";
	return "一般";
}


string *gems_level = ({
	"细碎的",
	"粗糙的",
	"标准的",
	"精致的",
	"完美的",
        "帝王的",
        "魔王的",
        "天圣的",
});

string w_power(int i)
{
	if( i >= 16 )	return HIY"灭世"NOR;
  if( i >= 15 )	return HIR"毁天"NOR;
	if( i >= 14 )	return HIR"创世"NOR;
	if( i >= 13 )	return HIR"开元"NOR;	
	if( i >= 12 )	return HIR"无双"NOR;	
	if( i >= 11 )	return HIM"绝世"NOR;	
	if( i >= 10 )	return HIY"天圣"NOR;
	if( i >= 9 )	return HIG"魔王"NOR;
	if( i >= 8 )	return HIB"举世"NOR;
	if( i >= 7 )	return HIC"完美"NOR;
	if( i >= 6 )	return RED"精致"NOR;
	if( i >= 5 )	return MAG"标准"NOR;
	if( i >= 4 )	return YEL"很高"NOR;
	if( i >= 3 )	return GRN"粗糙"NOR;
	if( i >= 2 )	return BLU"细碎"NOR;
	if( i >=	1  )	return CYN"不错"NOR;
	if( i <= 0 )	return "无有";
	return "无有";
}

string w_power2(int i)
{
	if( i >= 100 )	return HIY"灭世"NOR;
  if( i >= 80 )	return HIR"毁天"NOR;
	if( i >= 70 )	return HIR"创世"NOR;
	if( i >= 60 )	return HIR"开元"NOR;	
	if( i >= 50 )	return HIR"无双"NOR;	
	if( i >= 40 )	return HIM"绝世"NOR;	
	if( i >= 35 )	return HIY"天圣"NOR;
	if( i >= 30 )	return HIG"魔王"NOR;
	if( i >= 25 )	return HIB"举世"NOR;
	if( i >= 20 )	return HIC"完美"NOR;
	if( i >= 15 )	return RED"精致"NOR;
	if( i >= 10 )	return MAG"标准"NOR;
	if( i >= 5 )	return YEL"很高"NOR;
	if( i >= 4 )	return GRN"粗糙"NOR;
	if( i >= 3 )	return BLU"细碎"NOR;
	if( i >	2  )	return CYN"不错"NOR;
	if( i >	1  )	return YEL"一般"NOR;
	if( i >=	1  )	return GRN"极差"NOR;
	if( i <= 0 )	return "无有";
	return "无有";
}

string s_good2(int i)
{
	switch(i){
    case 6:		return MAG"毁天灭地"NOR;	
		case 5:		return HIC"无双无对"NOR;	
		case 4:		return WHT"绝世无双"NOR;	
		case 3:		return HIB"举世罕见"NOR;	
		case 2:		return RED"完美精致"NOR;	
		case 1:		return GRN"精致细美"NOR;	
		default:	return YEL"一般粗劣"NOR;	
	}
}



string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"qx_snake_poison",
"anqi_poison",
"yf_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});


int weaponmake(int sl,int ty,int lv,int zl,string path)
{
    string weaponname,weaponid,weaponlong,material,strnf,material2;
	object *user, newob,me;
	object *inv;
	int i,rigidity,w;
  object conc;
	//object env;
	string this_file;
	string my_file;
	string name;
	string file;
	string str = "";
	string strn = "";
	//string c_name,o_name;
  mapping type;
  int weighttext;
  int valuetext;
  int weilitext;
  int sharpness;
  int gifttext;
  int sztest;
  int fhtest;
  int skilllevtext;
  int is,lev;
  int basegifttext,basesztest,basefhtest;
  int yushi,color;
  me=this_player();
	

  color=random(13);

//message_vision("$N点头，对$n说：颜色是第"+color+"种！\n", this_object(), me);
//return notify_fail("你先找我妻子吧。\n");


	//wiz_status = SECURITY_D->get_status(me);
seteuid(getuid());

//	if( wiz_status != "(admin)" && wiz_status != "(arch)" )
//		return notify_fail("只有 (arch) 以上的巫师才能使用!\n");


//	name = (string)me->query("id")+"_w"+me->query_temp("item/dzwz");

//write("AAA");
//write(TYPE3[0]["TYPE1"]);
//return 1;
//		i = random(sizeof(Great_Class));
//write(keys(Great_Class)[i]);
//write(Great_Class[keys(Great_Class)[i]]);

my_file = read_file("/obj/ritem/WEAPON.o");
//类别参数0-8
type = TYPE1[ty];

//等级参数1-6
lev = lv;
//材料决等级定

//玉石参数
yushi=lv/2+2;
//玉石决等级定

//材料参数

//材料参数
//if (lv>3) lv=lv+random(4);

	switch(lv){
		case 1:	material="qingtong"; break;
		case 2:	material="shengtie"; break;
case 3:	material="ruantie"; break;
case 4:	material="lushi"; break;				
case 5:	material="liuhuashi"; break;
case 6:	material="ruanying"; break;				
case 7:	 material="jintie"; break;	
case 8:	material="shentie";	 break;	
case 9:	material="xuantie";	 break;	
case 10:	material="hantie";	 break;	
		default: material="qingtong";	break;
	}
	
		






//重量由材料决定
weighttext=1000+random(15000);




//write(lev+"");
//return 1;
if (lev==6)
{
		i = random(sizeof(Special_Class));
		weaponname	= keys(Special_Class)[i];
    weaponid	=  Special_Class[weaponname]["id"] + " " + type["TYPE2"];
    weaponlong = Special_Class[weaponname]["long2"];
		weaponname	= keys(Special_Class)[i] + "之" + type["TYPE3"]+NOR;
//可以学习的种类
i=random(sizeof(BOOK1));		
//硬度
rigidity=6+random(25);
//价值
valuetext=6000*lev;
//威力
weilitext=100+random(300);
//锋利
sharpness=3*lev+random(10);
//基本属性附加
basegifttext=3*lev+random(15);
//基本符号
basesztest=3*lev+random(15);
//基本符字
basefhtest=3+random(15);
//可以学习武功的等级
skilllevtext=80*lev;
//出现的机率
is=3;
}
else
if (lev==5)
{
		i = random(sizeof(Super_Class));
		weaponname	= keys(Super_Class)[i];
    weaponid	=  Super_Class[weaponname]["id"] + " " + type["TYPE2"];
    weaponlong = Super_Class[weaponname]["long2"];
		weaponname	= keys(Super_Class)[i] + "之" + type["TYPE3"]+NOR;

//可以学习的种类
i=random(sizeof(BOOK1));		
//硬度
rigidity=5+random(25);
//价值
valuetext=5000*lev;
//威力
weilitext=100+random(260);
//锋利
sharpness=3*lev+random(8);
//基本属性附加
basegifttext=3*lev+random(10);
//基本符号
basesztest=3*lev+random(10);
//基本符字
basefhtest=3+random(10);
//可以学习武功的等级
skilllevtext=60*lev;
//出现的机率
is=5;

}		
else
if (lev==4)
{
		i = random(sizeof(Great_Class));
		weaponname	= keys(Great_Class)[i];
    weaponid	=  Great_Class[keys(Great_Class)[i]] + " " + type["TYPE2"];
    weaponlong = keys(Great_Class)[i] + "之" + type["TYPE3"]+NOR;
		weaponname	= keys(Great_Class)[i] + "之" + type["TYPE3"]+NOR;
//可以学习的种类
i=random(sizeof(BOOK1));		
//硬度
rigidity=4+random(22);
//价值
valuetext=4000*lev;
//威力
weilitext=100+random(240);
//锋利
sharpness=3*lev+random(7);
//基本属性附加
basegifttext=3*lev+random(8);
//基本符号
basesztest=3*lev+random(8);
//基本符字
basefhtest=3+random(8);
//可以学习武功的等级
skilllevtext=80*lev;
//出现的机率
is=6;
}		
else
if (lev==3)
{
		i = random(sizeof(G_3_class));
		weaponname	= G_3_class[i];
    weaponid	=  "good " + type["TYPE2"];
    weaponlong = G_3_class[i] + "之" + type["TYPE3"]+NOR;
		weaponname	= order[color] +G_3_class[i] + "之" + type["TYPE3"]+NOR;
//可以学习的种类
i=random(sizeof(BOOK1));		
//硬度
rigidity=3+random(20);
//价值
valuetext=3000*lev;
//威力
weilitext=100+random(200);
//锋利
sharpness=3*lev+random(5);
//基本属性附加
basegifttext=3+random(6);
//基本符号
basesztest=3+random(6);
//基本符字
basefhtest=3+random(6);
//可以学习武功的等级
skilllevtext=80*lev;
//出现的机率
is=7;

}		
else
if (lev==2)
{
		i = random(sizeof(G_4_class));
		weaponname	= G_4_class[i];
    weaponid	=  "general " + type["TYPE2"];
    weaponlong = G_4_class[i] + "之" + type["TYPE3"]+NOR;
		weaponname	= order[color] +G_4_class[i] + "之" + type["TYPE3"]+NOR;
//可以学习的种类
i=random(sizeof(BOOK1));		
//硬度
rigidity=2+random(15);
//价值
valuetext=2000;
//威力
weilitext=100+random(180);
//锋利
sharpness=3+random(4);
//基本属性附加
basegifttext=2+random(6);
//基本符号
basesztest=2+random(6);
//基本符字
basefhtest=2+random(6);
//可以学习武功的等级
skilllevtext=120;
//出现的机率
is=8;

}
else
if (lev==1)
{
		i = random(sizeof(G_5_class));
		weaponname	= G_5_class[i];
    weaponid	=  "bad " + type["TYPE2"];
    weaponlong = G_5_class[i] + "之" + type["TYPE3"]+NOR;
		weaponname	= order[color] +G_5_class[i] + "之" + type["TYPE3"]+NOR;
//可以学习的种类
i=random(sizeof(BOOK1));		
//硬度
rigidity=1+random(10);
//价值
valuetext=2000;
//威力
weilitext=50+random(150);
//锋利
sharpness=1+random(5);
//基本属性附加
basegifttext=1;
//基本符号
basesztest=1;
//基本符字
basefhtest=1;
//可以学习武功的等级
skilllevtext=50;
//出现的机率
is=9;
}
is=is+5-yushi;
if (yushi==6 && is>6) is=6;
if (yushi==5 && is>7) is=7;
if (yushi==4 && is>8) is=8;
if (yushi==3 && is>9) is=9;


  if (type["TYPE2"]=="throwing" )
{
if (strsrch(my_file,"weaponamount")> 1)
{
	weighttext=weighttext/20+1;
    my_file= replace_string(my_file,"weaponamount","1");
}
}
else
{
if (strsrch(my_file,"set_amount(weaponamount);")> 1)
{
	my_file= replace_string(my_file,"set_amount(weaponamount);","");
}
}






//my_file= replace_string(my_file,"materialtext","default");

my_file= replace_string(my_file,"sharpnesstext",""+sharpness+"");
strn="锋利:"+w_power(sharpness)+" ";


my_file= replace_string(my_file,"weighttext",weighttext+"");


	my_file= replace_string(my_file,"ownertext",	me->query("id"));
	my_file= replace_string(my_file,"ownernametext",	me->query("name"));
  my_file= replace_string(my_file,"valuetext",	valuetext+"");
  my_file= replace_string(my_file,"weilitext",	weilitext+"");
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"aaatext",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"aaatext","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"bbbtext",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"bbbtext","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"aatext",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"aatext","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"bbtext",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"bbtext","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"cctext",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"cctext","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"ddtext",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"ddtext","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"eetext",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"eetext","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"fftext",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"fftext","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"clawtext",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"clawtext","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"cufftest",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"cufftest","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"fingertest",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"fingertest","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"handtest",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"handtest","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"striketest",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"striketest","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"unarmedtest",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"unarmedtest","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"bladetest",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"bladetest","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"whiptest",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"whiptest","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"stafftest",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"stafftest","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"forcetest",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"forcetest","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"daggetest",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"daggetest","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"hammertest",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"hammertest","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"speartest",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"speartest","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"throwingtest",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"throwingtest","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"magictest",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"magictest","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev+8);
  my_file= replace_string(my_file,"inttext",	gifttext+"");
strn +="天灵:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"inttext","0");		
}

if (random(is)==0)
{
gifttext=basegifttext+random(lev+8);
  my_file= replace_string(my_file,"strtext",	gifttext+"");
strn +="天宇:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"strtext","0");
}

if (random(is)==0)
{
gifttext=basegifttext+random(lev+8);
  my_file= replace_string(my_file,"kartext",	gifttext+"");
strn +="福源:"+w_power2(gifttext)+" "+"\n";
}
else
{
  my_file= replace_string(my_file,"kartext",	"0");
}

if (random(is)==0)
{
gifttext=basegifttext+random(lev+8);
  my_file= replace_string(my_file,"pertext",	gifttext+"");
strn +="绝代:"+w_power2(gifttext)+" ";
}
else
{
my_file= replace_string(my_file,"pertext",	"0");
}

if (random(is)==0)
{
gifttext=basegifttext+random(lev+8);
  my_file= replace_string(my_file,"dextext",	gifttext+"");
strn +="天渊:"+w_power2(gifttext)+" ";
}
else
{
my_file= replace_string(my_file,"dextext",	"0");
}

if (random(is)==0)
{
gifttext=basegifttext+random(lev+8);
  my_file= replace_string(my_file,"context",	gifttext+"");      
strn +="天玄:"+w_power2(gifttext)+" ";
}
else
{
my_file= replace_string(my_file,"context",	"0");      
}

if (random(is)==0)
{
sztest=basesztest+random(lev*10);
my_file= replace_string(my_file,"armortext",	sztest+"");  
strn +="巧制:"+w_power2(sztest)+" "+"\n";
}
else
{
my_file= replace_string(my_file,"armortext",	"0");      
}

if (random(is)==0)
{
sztest=basesztest+random(lev*10);
my_file= replace_string(my_file,"defensetext",	sztest+""); 
strn +="体灵:"+w_power2(sztest)+" ";
}
else
{
my_file= replace_string(my_file,"defensetext",	"0");      
}

if (random(is)==0)
{
sztest=basesztest+random(lev*10);
my_file= replace_string(my_file,"dodgetext",	sztest+"");  
strn +="白石:"+w_power2(sztest)+" ";
}
else
{
my_file= replace_string(my_file,"dodgetext",	"0");      
}

if (random(is)==0)
{
sztest=basesztest+random(lev*10);
my_file= replace_string(my_file,"parrytest",	sztest+"");  
strn +="紫石:"+w_power2(sztest)+" ";
}
else
{
my_file= replace_string(my_file,"parrytest",	"0");      
}

if (random(is)==0)
{
sztest=basesztest+random(lev*10);
my_file= replace_string(my_file,"attacktest",	sztest+"");  
strn +="闪电:"+w_power2(sztest)+" "+"\n";
}
else
{
my_file= replace_string(my_file,"attacktest",	"0");      
}

if (random(is)==0)
{ 
sztest=basesztest+random(lev*10);
my_file= replace_string(my_file,"neilitext",	sztest+"");  
strn +="周天:"+w_power2(sztest)+" ";
}
else
{
my_file= replace_string(my_file,"neilitext",	"0");      
}

if (random(is)==0)
{ 
sztest=basesztest+random(lev*10);
my_file= replace_string(my_file,"qitext",	sztest+"");  
strn +="长生:"+w_power2(sztest)+" ";
}
else
{
my_file= replace_string(my_file,"qitext",	"0");      
}

if (random(is)==0)
{ 
sztest=basesztest+random(lev*10);
my_file= replace_string(my_file,"jingtext",	sztest+"");  
my_file= replace_string(my_file,"jinglitext",	sztest+"");  
strn +="不老:"+w_power2(sztest)+" ";
}
else
{
my_file= replace_string(my_file,"jingtext",	"0");   
my_file= replace_string(my_file,"jinglitext",	"0");      
}

if (random(is)==0)
{
sztest=basesztest+random(lev*10);
my_file= replace_string(my_file,"damagetext",	sztest+"");  
strn +="威力:"+w_power2(sztest)+" ";
}
else
{
my_file= replace_string(my_file,"damagetext",	"0");      
}

my_file= replace_string(my_file,"skillnametext",	BOOK1[i]["TYPE2"]);  
my_file= replace_string(my_file,"skilllevtext",	skilllevtext+""); 


strnf="";
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"atext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"atext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"btext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"btext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"ctext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"ctext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"dtext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"dtext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"etext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"etext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"ftext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"ftext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"gtext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"gtext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"htext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"htext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"itext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"itext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"jtext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"jtext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"ktext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"ktext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"mtext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"mtext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"ltext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"ltext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"ntext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"ntext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"otext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"otext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"ptext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"ptext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"qtext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"qtext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"rtext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"rtext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"stext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"stext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"ttext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"ttext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"utext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"utext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"vtext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"vtext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"xtext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"xtext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"ytext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"ytext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"ztext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"ztext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"btest",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"btest",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"atest",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"atest",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeAtext",	fhtest+"");
strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeAtext",	"0");
}

if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeBtext",	fhtest+"");
strnf +=TYPE3[1]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeBtext",	"0");
}

if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeCtext",	fhtest+"");
strnf +=TYPE3[2]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeCtext",	"0");
}

if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeDtext",	fhtest+"");
strnf +=TYPE3[3]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeDtext",	"0");
}

if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeEtext",	fhtest+"");
strnf +=TYPE3[4]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeEtext",	"0");
}

if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeFtext",	fhtest+"");
strnf +=TYPE3[5]["TYPE1"]+":"+ w_power(fhtest) + " \n";
}
else
{
my_file= replace_string(my_file,"wtypeFtext",	"0");
}

if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeGtext",	fhtest+"");
strnf +=TYPE3[6]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeGtext",	"0");
}

if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeHtext",	fhtest+"");
strnf +=TYPE3[7]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeHtext",	"0");
}

if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeItext",	fhtest+"");
strnf +=TYPE3[8]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeItext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeJtext",	fhtest+"");
strnf +=TYPE3[9]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeJtext",	"0");
}

if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeKtext",	fhtest+"");
strnf +=TYPE3[10]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeKtext",	"0");
}

if (random(is)==0 )
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeLtext",	fhtest+"");  
strnf +=TYPE3[11]["TYPE1"]+":"+ w_power(fhtest) +	" ";
}
else
{
my_file= replace_string(my_file,"wtypeLtext",	"0");
}

	if( stringp(weaponlong) )
		str = weaponlong;
	str += "这是一"+type["TYPE4"]+"由" + s_good(rigidity) + "坚硬的";

	switch(material){
		case "hantie":	str += HIC"万年寒冰铁"NOR; break;
		case "xuantie":	str += WHT"玄铁"NOR; break;
case "shentie":	str += RED"万年神铁"NOR; break;
case "jintie":	str += HIY"金铁"NOR; break;				
case "ruanying":	str += HIW"软银"NOR; break;
case "liuhuashi":	str += RED"流花石"NOR; break;				
case "lushi":	str += HIG"绿石"NOR; break;	
case "ruantie":	str += YEL"软铁"NOR; break;	
case "shengtie":	str += YEL"生铁"NOR; break;	
case "qingtong":	str += GRN"青铜"NOR; break;				
		default: str +=	"精钢";	break;
	}
	w = weighttext;
	str +=	"制成，重"+sprintf("%s", chinese_number(w/500)+"斤"+chinese_number((w%500)/50)+"两"+chinese_number((w%50)/5)+"钱")+"的"+weaponname+"。\n";

	//mm = w_mp;
  //weili;
	
	//str += "综合评价"	+ s_good2(lev)+" 看起来"	+ ( s_good(rigidity)+"锋利，" ) + "具有"+ s_power(weilitext) + "的威力！\n";
if (strnf!="")
{
	str += "\n上面刻了几个古符号：\n"
		+strnf;
}
	//	str += "\n上面还刻了一些符字：\n"
	//	+strn+"\n";

      str = replace_string(str,"\n","")+"\n";
				write(ZJOBLONG+str+"\n");


		

  my_file= replace_string(my_file,"WEAPONTYPE",type["TYPE1"]);
  my_file= replace_string(my_file,"TYPEDM",type["TYPE2"]);

  my_file= replace_string(my_file,"WEAPON_SWORD",weaponname+"★");
  
  my_file= replace_string(my_file,"WEAPON_ID",weaponid);
	my_file= replace_string(my_file,"IDTYPE",type["TYPE2"]);
	my_file= replace_string(my_file,"LONG_TITLE",str);
  my_file= replace_string(my_file,"unittest",type["TYPE4"]);


// now we need to write out this file!
// do NOT change this one!
	//write_file("/p/residence/weapon/"+name+".o",my_file,1);
	
// change this one to write_file2
//rm("/p/residence/weapon/"+name+".c");
	
name="W"+type["TYPE2"]+sl;
        write_file("/p/item/"+path+"/"+name+".c",my_file,1);
//write("武器打造成功！！\n");
//if (!wizardp(me))
//{

//}
//message_vision(HIR "武器生成成功!。文件名为:"+"/p/residence/weapon/"+name+".c"+"\n" NOR, me);


//newob->move(me);
       return 1;
}



int armormake(int sl,int ty,int lv,int zl,string path)
{
	string weaponname,weaponid,weaponlong,material,strnf,material2;
	object *user, newob,me;
	object *inv;
	int i,rigidity,w;
  //object conc;
	//object env;
	//string this_file;
	string my_file;
	string file;
	string name;
	string str = "";
	string strn = "";
	//string c_name,o_name;
  mapping type;
  int weighttext;
  int valuetext;
  int weilitext,weilijc;
  int sharpness;
  int gifttext;
  int sztest;
  int fhtest;
  int skilllevtext;
  int is,lev;
  int basegifttext,basesztest,basefhtest,yushi,color;

  me=this_player();

  color=random(13);


seteuid(getuid());

//	if( wiz_status != "(admin)" && wiz_status != "(arch)" )
//		return notify_fail("只有 (arch) 以上的巫师才能使用!\n");


	name = (string)me->query("id")+"_a"+me->query_temp("item/dzwz");



my_file = read_file("/obj/ritem/ARMOR.o");


//类别参数0-9
type = TYPE2[ty];

//等级参数1-6
lev = lv;
//材料决等级定
//玉石参数
yushi=lv/2+2;



//材料参数
//if (lv>3) lv=lv+random(4);

	switch(lv){
		case 1:	material="qingtong"; break;
		case 2:	material="shengtie"; break;
case 3:	material="ruantie"; break;
case 4:	material="lushi"; break;				
case 5:	material="liuhuashi"; break;
case 6:	material="ruanying"; break;				
case 7:	 material="jintie"; break;	
case 8:	material="shentie";	 break;	
case 9:	material="xuantie";	 break;	
case 10:	material="hantie";	 break;	
		default: material="qingtong";	break;
	}

	switch(lv){
		case 1:	material2="mianhua"; break;
		case 2:	material2="yama"; break;
case 3:	material2="dama"; break;
case 4:	material2="zhuma"; break;				
case 5:	material2="cansi"; break;
case 6:	material2="mumianhua"; break;				
case 7:	 material2="yucansi"; break;	
case 8:	material2="bingcansi";	 break;	
case 9:	material2="tiancansi";	 break;	
case 10:	material2="longcansi";	 break;	
		
		default: material="mianhua";	break;
	}



//玉石决等级定

//重量由材料决定
weighttext=1000+random(15000);




//重量由材料决定

material=me->query_temp("item/kuangshi");
	switch(material){
		case "hantie":	weighttext=2000+random(5000); break;
		case "xuantie":	weighttext=1800+random(5000); break;
case "shentie":	weighttext=1500+random(5000); break;
case "jintie":	weighttext=1300+random(6000); break;				
case "ruanying":	weighttext=1200+random(6000); break;
case "liuhuashi":	weighttext=1000+random(5000);; break;				
case "lushi":	weighttext=950+random(4000); break;	
case "ruantie":	weighttext=900+random(3000); break;	
case "shengtie":	weighttext=800+random(2000); break;	
case "qingtong":	weighttext=700+random(1000); break;				
		default: weighttext=600+random(1000);	break;
	}

if (type["TYPE2"]!="cloth" && type["TYPE2"]!="shield" ) weighttext=weighttext/2+1;
	
//副材料威力成
	switch(material2){
		case "longcansi": weilijc=160;break;		
		case "tiancansi": weilijc=120; break;
		case "bingcansi": weilijc=100; break;
		case "yucansi":   weilijc=90; break;
		case "mumianhua": weilijc=80; break;
		case "cansi":     weilijc=70; break;
		case "zhuma":     weilijc=60; break;
		case "dama":      weilijc=50; break;
		case "yama":      weilijc=40; break;
		case "mianhua":   weilijc=20; break;
		default: weilijc=10;	break;
	}


//write(lev+"");
//return 1;
if (lev==6)
{
		i = random(sizeof(Special_Class));
		weaponname	= keys(Special_Class)[i];
    weaponid	=  Special_Class[weaponname]["id"] + " " + type["TYPE2"];
    weaponlong = Special_Class[weaponname]["long2"];
		weaponname	= keys(Special_Class)[i] + "之" + type["TYPE3"]+NOR;
//可以学习的种类
i=random(sizeof(BOOK1));		
//硬度
rigidity=6+random(18);
//价值
valuetext=6000*lev;
//威力
weilitext=60+weilijc;
//保护
sharpness=3*lev+random(10);
//基本属性附加
basegifttext=6+random(15);
//基本符号
basesztest=6+random(15);
//基本符字
basefhtest=6+random(15);
//可以学习武功的等级
skilllevtext=80*lev;
//出现的机率
is=5;
}
else
if (lev==5)
{
		i = random(sizeof(Super_Class));
		weaponname	= keys(Super_Class)[i];
    weaponid	=  Super_Class[weaponname]["id"] + " " + type["TYPE2"];
    weaponlong = Super_Class[weaponname]["long2"];
		weaponname	= keys(Super_Class)[i] + "之" + type["TYPE3"]+NOR;
//可以学习的种类
i=random(sizeof(BOOK1));		
//硬度
rigidity=5+random(18);
//价值
valuetext=5000*lev;
//威力
weilitext=50+weilijc;
//锋利
sharpness=3*lev+random(8);
//基本属性附加
basegifttext=5+random(12);
//基本符号
basesztest=5+random(12);
//基本符字
basefhtest=5+random(12);
//可以学习武功的等级
skilllevtext=60*lev;
//出现的机率
is=6;

}		
else
if (lev==4)
{
		i = random(sizeof(Great_Class));
		weaponname	= keys(Great_Class)[i];
    weaponid	=  Great_Class[keys(Great_Class)[i]] + " " + type["TYPE2"];
    weaponlong = keys(Great_Class)[i] + "之" + type["TYPE3"]+NOR;
		weaponname	= keys(Great_Class)[i] + "之" + type["TYPE3"]+NOR;
//可以学习的种类
i=random(sizeof(BOOK1));		
//硬度
rigidity=4+random(18);
//价值
valuetext=4000*lev;
//威力
weilitext=40+weilijc;
//锋利
sharpness=3*lev+random(7);
//基本属性附加
basegifttext=4+random(10);
//基本符号
basesztest=4+random(10);
//基本符字
basefhtest=4+random(10);
//可以学习武功的等级
skilllevtext=80*lev;
//出现的机率
is=7;
}		
else
if (lev==3)
{
		i = random(sizeof(G_3_class));
		weaponname	= G_3_class[i];
    weaponid	=  "good " + type["TYPE2"];
    weaponlong = G_3_class[i] + "之" + type["TYPE3"]+NOR;
		weaponname	= order[color] +G_3_class[i] + "之" + type["TYPE3"]+NOR;
//可以学习的种类
i=random(sizeof(BOOK1));		
//硬度
rigidity=3+random(18);
//价值
valuetext=3000*lev;
//威力
weilitext=30+weilijc;
//锋利
sharpness=3*lev+random(5);
//基本属性附加
basegifttext=3+random(8);
//基本符号
basesztest=3+random(8);
//基本符字
basefhtest=3+random(8);
//可以学习武功的等级
skilllevtext=80*lev;
//出现的机率
is=8;

}		
else
if (lev==2)
{
		i = random(sizeof(G_4_class));
		weaponname	= G_4_class[i];
    weaponid	=  "general " + type["TYPE2"];
    weaponlong = G_4_class[i] + "之" + type["TYPE3"]+NOR;
		weaponname	= order[color] +G_4_class[i] + "之" + type["TYPE3"]+NOR;
//可以学习的种类
i=random(sizeof(BOOK1));		
//硬度
rigidity=2+random(12);
//价值
valuetext=2000;
//威力
weilitext=20+weilijc;
//锋利
sharpness=3+random(4);
//基本属性附加
basegifttext=2+random(6);
//基本符号
basesztest=2+random(6);
//基本符字
basefhtest=2+random(6);
//可以学习武功的等级
skilllevtext=120;
//出现的机率
is=9;

}
else
if (lev==1)
{
		i = random(sizeof(G_5_class));
		weaponname	= G_5_class[i];
    weaponid	=  "bad " + type["TYPE2"];
    weaponlong = G_5_class[i] + "之" + type["TYPE3"]+NOR;
		weaponname	= order[color] +G_5_class[i] + "之" + type["TYPE3"]+NOR;
//可以学习的种类
i=random(sizeof(BOOK1));		
//硬度
rigidity=1+random(6);
//价值
valuetext=2000;
//威力
weilitext=20+weilijc;
//锋利
sharpness=1+random(3);
//基本属性附加
basegifttext=1;
//基本符号
basesztest=1;
//基本符字
basefhtest=1;
//可以学习武功的等级
skilllevtext=50;
//出现的机率
is=10;
}
//is=2
//非主要防具，出现特效可能减半
if (type["TYPE2"]!="cloth") is=is+5;
//is=1;

is=is+5-yushi;

if (yushi==6 && is>6) is=6;
if (yushi==5 && is>7) is=7;
if (yushi==4 && is>8) is=8;
if (yushi==3 && is>9) is=9;


//write(yushi+"A");
//write(is+"B");
/*  if (type["TYPE2"]=="throwing" )
{
    //my_file= replace_string(my_file,"weaponamount","1");
}
else
{
	//my_file= replace_string(my_file,"set_amount(weaponamount);","");
}*/






//my_file= replace_string(my_file,"materialtext","default");
if (!my_file) my_file = read_file("/obj/ritem/armor.o");
if (!my_file) my_file = read_file("/obj/ritem/ARMOR.o");
if (!my_file) my_file = read_file("/obj/ritem/armor.o");

my_file= replace_string(my_file,"sharpnesstext",""+sharpness+"");
strn="坚硬:"+w_power(sharpness)+" ";


my_file= replace_string(my_file,"weighttext",weighttext+"");


	my_file= replace_string(my_file,"ownertext",	me->query("id"));
	my_file= replace_string(my_file,"ownernametext",	me->query("name"));
  my_file= replace_string(my_file,"valuetext",	valuetext+"");
  //my_file= replace_string(my_file,"weilitext",	weilitext+"");
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"aaatext",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"aaatext","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"bbbtext",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"bbbtext","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"aatext",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"aatext","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"bbtext",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"bbtext","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"cctext",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"cctext","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"ddtext",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"ddtext","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"eetext",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"eetext","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"fftext",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"fftext","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"clawtext",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"clawtext","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"cufftest",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"cufftest","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"fingertest",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"fingertest","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"handtest",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"handtest","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"striketest",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"striketest","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"unarmedtest",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"unarmedtest","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"bladetest",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"bladetest","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"whiptest",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"whiptest","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"stafftest",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"stafftest","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"forcetest",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"forcetest","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"daggetest",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"daggetest","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"hammertest",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"hammertest","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"speartest",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"speartest","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"throwingtest",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"throwingtest","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"magictest",	gifttext+"");
//strn +="悟  性:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"magictest","0");		
}
if (random(is)==0)
{
gifttext=basegifttext+random(lev*6);
  my_file= replace_string(my_file,"inttext",	gifttext+"");
strn +="天灵:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"inttext","0");		
}

if (random(is)==0)
{
gifttext=basegifttext+random(lev+6);
  my_file= replace_string(my_file,"strtext",	gifttext+"");
strn +="天宇:"+w_power2(gifttext)+" ";
}
else
{
  my_file= replace_string(my_file,"strtext","0");
}

if (random(is)==0)
{
gifttext=basegifttext+random(lev+6);
  my_file= replace_string(my_file,"kartext",	gifttext+"");
strn +="福源:"+w_power2(gifttext)+" "+"\n";
}
else
{
  my_file= replace_string(my_file,"kartext",	"0");
}

if (random(is)==0)
{
gifttext=basegifttext+random(lev+6);
  my_file= replace_string(my_file,"pertext",	gifttext+"");
strn +="绝代:"+w_power2(gifttext)+" ";
}
else
{
my_file= replace_string(my_file,"pertext",	"0");
}

if (random(is)==0)
{
gifttext=basegifttext+random(lev+6);
  my_file= replace_string(my_file,"dextext",	gifttext+"");
strn +="天渊:"+w_power2(gifttext)+" ";
}
else
{
my_file= replace_string(my_file,"dextext",	"0");
}

if (random(is)==0)
{
gifttext=basegifttext+random(lev+6);
  my_file= replace_string(my_file,"context",	gifttext+"");      
strn +="天玄:"+w_power2(gifttext)+" ";
}
else
{
my_file= replace_string(my_file,"context",	"0");      
}
//write(lev+" ");
//write(weilitext+" ");
//不是服装为1/3
if (type["TYPE2"]!="cloth") weilitext=weilitext/3+1;
//write(type["TYPE2"]);
//write(weilitext+" ");
//return 1;
//if (random(is)==0)
//{
if (type["TYPE2"]=="cloth" || type["TYPE2"]=="shield") weilitext=weilitext+180;
sztest=basesztest+random(lev*10);
my_file= replace_string(my_file,"armortext",	weilitext+"");  
strn +="巧制:"+w_power2(sztest)+" "+"\n";
//}
//else
//{
//my_file= replace_string(my_file,"armortext",	"0");      
//}

if (random(is)==0)
{
sztest=basesztest+random(lev*10);
my_file= replace_string(my_file,"defensetext",	sztest+""); 
strn +="体灵:"+w_power2(sztest)+" ";
}
else
{
my_file= replace_string(my_file,"defensetext",	"0");      
}

if (random(is)==0)
{
sztest=basesztest+random(lev*10);
my_file= replace_string(my_file,"dodgetext",	sztest+"");  
strn +="白石:"+w_power2(sztest)+" ";
}
else
{
my_file= replace_string(my_file,"dodgetext",	"0");      
}

if (random(is)==0)
{
sztest=basesztest+random(lev*10);
my_file= replace_string(my_file,"parrytest",	sztest+"");  
strn +="紫石:"+w_power2(sztest)+" ";
}
else
{
my_file= replace_string(my_file,"parrytest",	"0");      
}

if (random(is)==0)
{
sztest=basesztest+random(lev*10);
my_file= replace_string(my_file,"attacktest",	sztest+"");  
strn +="闪电:"+w_power2(sztest)+" "+"\n";
}
else
{
my_file= replace_string(my_file,"attacktest",	"0");      
}

if (random(is)==0)
{ 
sztest=basesztest+random(lev*10);
my_file= replace_string(my_file,"neilitext",	sztest+"");  
strn +="周天:"+w_power2(sztest)+" ";
}
else
{
my_file= replace_string(my_file,"neilitext",	"0");      
}

if (random(is)==0)
{ 
sztest=basesztest+random(lev*10);
my_file= replace_string(my_file,"qitext",	sztest+"");  
strn +="长生:"+w_power2(sztest)+" ";
}
else
{
my_file= replace_string(my_file,"qitext",	"0");      
}

if (random(is)==0)
{ 
sztest=basesztest+random(lev*10);
my_file= replace_string(my_file,"jingtext",	sztest+"");  
my_file= replace_string(my_file,"jinglitext",	sztest+"");  
strn +="不老:"+w_power2(sztest)+" ";
}
else
{
my_file= replace_string(my_file,"jingtext",	"0");   
my_file= replace_string(my_file,"jinglitext",	"0");      
}

if (type["TYPE2"]=="hands")
{
sztest=basesztest*2+(lev*20)+100;
my_file= replace_string(my_file,"damagetext",	sztest+"");  
strn +="威力:"+w_power2(basesztest+(lev*5))+" ";
}
else if (random(is)==0)
{
sztest=basesztest+random(lev*10);
my_file= replace_string(my_file,"damagetext",	sztest+"");  
strn +="威力:"+w_power2(sztest)+" ";
}
else
{
my_file= replace_string(my_file,"damagetext",	"0");      
}

my_file= replace_string(my_file,"skillnametext",	BOOK1[i]["TYPE2"]);  
my_file= replace_string(my_file,"skilllevtext",	skilllevtext+""); 


strnf="";
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"atext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"atext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"btext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"btext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"ctext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"ctext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"dtext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"dtext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"etext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"etext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"ftext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"ftext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"gtext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"gtext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"htext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"htext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"itext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"itext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"jtext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"jtext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"ktext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"ktext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"mtext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"mtext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"ltext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"ltext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"ntext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"ntext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"otext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"otext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"ptext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"ptext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"qtext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"qtext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"rtext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"rtext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"stext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"stext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"ttext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"ttext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"utext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"utext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"vtext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"vtext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"xtext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"xtext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"ytext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"ytext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"ztext",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"ztext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"btest",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"btest",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"atest",	fhtest+"");
//strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"atest",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeAtext",	fhtest+"");
strnf=TYPE3[0]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeAtext",	"0");
}

if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeBtext",	fhtest+"");
strnf +=TYPE3[1]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeBtext",	"0");
}

if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeCtext",	fhtest+"");
strnf +=TYPE3[2]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeCtext",	"0");
}

if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeDtext",	fhtest+"");
strnf +=TYPE3[3]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeDtext",	"0");
}

if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeEtext",	fhtest+"");
strnf +=TYPE3[4]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeEtext",	"0");
}

if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeFtext",	fhtest+"");
strnf +=TYPE3[5]["TYPE1"]+":"+ w_power(fhtest) + " \n";
}
else
{
my_file= replace_string(my_file,"wtypeFtext",	"0");
}

if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeGtext",	fhtest+"");
strnf +=TYPE3[6]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeGtext",	"0");
}

if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeHtext",	fhtest+"");
strnf +=TYPE3[7]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeHtext",	"0");
}

if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeItext",	fhtest+"");
strnf +=TYPE3[8]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeItext",	"0");
}
if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeJtext",	fhtest+"");
strnf +=TYPE3[9]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeJtext",	"0");
}

if (random(is)==0)
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeKtext",	fhtest+"");
strnf +=TYPE3[10]["TYPE1"]+":"+ w_power(fhtest) + " ";
}
else
{
my_file= replace_string(my_file,"wtypeKtext",	"0");
}

if (random(is)==0 )
{
fhtest=basefhtest+random(5+lev);
my_file= replace_string(my_file,"wtypeLtext",	fhtest+"");  
strnf +=TYPE3[11]["TYPE1"]+":"+ w_power(fhtest) +	" ";
}
else
{
my_file= replace_string(my_file,"wtypeLtext",	"0");
}

	if( stringp(weaponlong) )
		str = weaponlong;
	str += "这是一"+type["TYPE4"]+"由" + s_good(rigidity) + "坚硬的";

	switch(material){
		case "hantie":	str += HIC"万年寒冰铁"NOR; break;
		case "xuantie":	str += WHT"玄铁"NOR; break;
case "shentie":	str += RED"万年神铁"NOR; break;
case "jintie":	str += HIY"金铁"NOR; break;				
case "ruanying":	str += HIW"软银"NOR; break;
case "liuhuashi":	str += RED"流花石"NOR; break;				
case "lushi":	str += HIG"绿石"NOR; break;	
case "ruantie":	str += YEL"软铁"NOR; break;	
case "shengtie":	str += YEL"生铁"NOR; break;	
case "qingtong":	str += GRN"青铜"NOR; break;				
		default: str +=	"精钢";	break;
	}
	
	str += "加上";
	switch(material2){
		case "longcansi": str += HIY"龙茧蚕丝"NOR;break;		
		case "tiancansi": str += WHT"天蚕丝"NOR; break;
		case "bingcansi": str += HIW"冰蚕丝"NOR; break;
		case "yucansi":   str += GRN"玉蚕丝"NOR; break;
		case "mumianhua": str += HIY"木棉花"NOR; break;
		case "cansi":     str += HIW"蚕丝"NOR; break;
		case "zhuma":     str += HIY"苎麻"NOR; break;
		case "dama":      str += YEL"大麻"NOR; break;
		case "yama":      str += YEL"亚麻"NOR; break;
		case "mianhua":   str += HIW"棉花"NOR; break;
		default: str +=	"布料";	break;
	}
	
	w = weighttext;
	str +=	"制成，重"+sprintf("%s", chinese_number(w/500)+"斤"+chinese_number((w%500)/50)+"两"+chinese_number((w%50)/5)+"钱")+"的"+weaponname+"。\n";

	//mm = w_mp;
  //weili;
	
//	str += "综合评价"	+ s_good2(lev)+" 看起来"	+ ( s_good(rigidity)+"坚固，" ) + "具有"+ s_power(weilitext) + "的防护力！\n";
if (strnf!="")
{
	str += "\n上面刻了几个古符号：\n"
		+strnf;
}
	//	str += "\n上面还刻了一些符字：\n"
	//	+strn+"\n";
		str = replace_string(str,"\n",ZJBR)+"\n";
				write(ZJOBLONG+str+"\n");





		

  my_file= replace_string(my_file,"WEAPONTYPE",type["TYPE1"]);
  my_file= replace_string(my_file,"TYPEDM",type["TYPE2"]);

  my_file= replace_string(my_file,"WEAPON_SWORD",weaponname+"★");
  my_file= replace_string(my_file,"WEAPON_ID",weaponid);
	my_file= replace_string(my_file,"IDTYPE",type["TYPE2"]);
	my_file= replace_string(my_file,"LONG_TITLE",str);
  my_file= replace_string(my_file,"unittest",type["TYPE4"]);


// now we need to write out this file!
// do NOT change this one!
// change this one to write_file2
//rm("/p/residence/weapon/"+name+".c");

		       name="A"+type["TYPE2"]+sl;
        write_file("/p/item/"+path+"/"+name+".c",my_file,1);

//newob->move(me);
       return 1;
}