// store.c
// by luoyun

#include <ansi.h>
inherit ITEM;
inherit F_SAVE;

mapping baowus;

void create()
{
	set_name(HIW"储物袋"NOR, ({ "chuwu dai" }) );
	set("long",HIW"一个神奇的袋子，可以存取许多宝贝。"NOR"\n");
	set("unit", "个");
	set("no_lose", 1);
	set("no_save", 1);
	set("no_get", 1);
	set("no_put", 1);
	set("no_give", 1);
	set("no_drop", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	seteuid(getuid());
}

string query_save_file()
{
	string id;

	if( !stringp(id = query("owner_id")) || id != this_player()->query("id")) return 0;

	return sprintf(DATA_DIR"baibao/%c/%s", id[0], id);
}

int set_owner(string id)
{
	set("owner_id", id);
	return 1;
}

void init()
{
	add_action ("do_travel", "jiaoche");
	add_action ("do_travel1", "rwcs");
	if(!query("owner_id") || query("owner_id") != this_player()->query("id"))
	{
		set_owner(this_player()->query("id"));
	}

	if(this_player()->query("id")==query("owner_id"))
	{
		restore();
	}
}
int do_travel1(string arg)
{

            object* inv;
	        string destin,str, destch, destmg;
	        int i;
            object me = this_player();

          if (!arg)
          {
              str = ZJOBLONG"你要到哪里去？\n"ZJOBACTS2+ZJMENUF(2,2,9,35);
        str += "韩员外复仇:rwcs hyw"+ZJSEP;
		str += "胡一刀任务:rwcs hyd"+ZJSEP;
	    str += "萧峰任务:rwcs xf"+ZJSEP;
		str += "慕容玉玺:rwcs mryx"+ZJSEP;
		str += "萧半和任务:rwcs xbh"+ZJSEP;
		str += "韩世忠任务:rwcs hsz"+ZJSEP;
		str += "投名状任务:rwcs tmz"+ZJSEP;
		str += "铜雀台任务:rwcs tqt"+ZJSEP;
		str += "临安府剿匪:rwcs lafjf"+ZJSEP;
		str += "万安塔:rwcs wat"+ZJSEP;
		str += "公孙止任务:rwcs gsz"+ZJSEP;
		str += "孟之经任务:rwcs mzj"+ZJSEP;

		
		
		
write(str+"\n");

              return 1;
        	}



if( me->query("jing") < 10 )
        return notify_fail("你精神不够旺盛，没力气瞎逛了！\n");

//if(!environment(me)->query("outdoors"))
  //      return notify_fail("请先到室外在使用此命令！所谓室外，就是能看到天气描述的地方啦。\n");

if( me->query_temp("pending/exercising"))
        return notify_fail("你打完坐在走吧！\n");
if (environment(me)->query("pigging"))
		return notify_fail("你还是专心拱猪吧！\n");

if (me->is_fighting())
        return notify_fail("你正打的热闹着呢!\n");
if (me->is_busy())
        return notify_fail("你正忙着呢!\n");
if(me->query("xkxvip/times") == 0){
inv = deep_inventory(me);
        for(i=sizeof(inv)-1; i>=0; i--)
        if(inv[i]->is_character() || userp(inv[i]))
        return notify_fail("你不能背着个活物到处逛！\n");
		
if(me->query_encumbrance()*100/me->query_max_encumbrance()>50)
             return notify_fail("你身上的东西太多了，把没用的东西都扔了吧!\n");
}
        if(arg=="韩员外复仇" || arg == "hyw")
	{
		destin = "/d/jiangzhou/dating.c";
		destch = "韩员外";
		destmg = "任务有风险，小心谨慎哦。";
	}
     else if(arg=="公孙止任务" || arg == "gsz")
	{
		destin = "/d/wudang/jueqingroad1.c";
		destch = "公孙止";
		destmg = "任务有风险，小心谨慎哦。";
	}
	else if(arg=="孟之经任务" || arg == "mzj")
	{
		destin = "/d/yingtiansouth/dufu/dating.c";
		destch = "孟之经";
		destmg = "任务有风险，小心谨慎哦。";
	}
	 else if(arg=="胡一刀任务" || arg == "hyd")
	{
		destin = "/d/beijing/gaoliangdi.c";
		destch = "胡一刀";
		destmg = "任务有风险，小心谨慎哦。";
	}
	 else if(arg=="万安塔任务" || arg == "wat")
	{
		destin = "/d/luoyang/wananta.c";
		destch = "万安塔";
		destmg = "任务无风险，假死而已。";
	}
	else if(arg=="铜雀台任务" || arg == "tqt")
	{
		destin = "/d/beijing/tongque.c";
		destch = "铜雀台";
		destmg = "任务略肝，小心谨慎哦。";
	}
	 else if(arg=="萧峰任务" || arg == "xf")
	{
		destin = "/d/luoyang/wangxinglou2.c";
		destch = "萧峰";
		destmg = "任务风险较大，小心谨慎哦。";
	}
	 else if(arg=="慕容玉玺" || arg == "mryx")
	{
		destin = "/d/city/chaguan.c";
		destch = "慕容玉玺";
		destmg = "任务风险较小，小心谨慎哦。";
	}
	 else if(arg=="临安府剿匪" || arg == "lafjf")
	{
		destin = "/d/jiaofei/shanjiao.c";
		destch = "临安府";
		destmg = "任务风险较大，小心谨慎哦。";
	}
	 else if(arg=="萧半和任务" || arg == "xbh")
	{
		destin = "/d/jinyang/xiaofu.c";
		destch = "萧半和";
		destmg = "任务风险较小，小心谨慎哦。";
	}
	else if(arg=="韩世忠任务" || arg == "hsz")
	{
		destin = "/d/hangzhou/hw_dating.c";
		destch = "韩世忠";
		destmg = "任务风险较大，小心谨慎哦。";
	}
	else if(arg=="投名状任务" || arg == "tmz")
	{
		destin = "/d/changjiangnorth/tingzi.c";
		destch = "投名状";
		destmg = "任务风险较小，小心谨慎哦。";
	}

	else
   	{
 	return notify_fail("没有这个地方吧？？？\n");
	}

    message_vision(HIW"$N"+HIW+"拿出储物袋，从里面掏出来一辆大车！\n"NOR, me);
    message_vision(HIW"大车载着$N向" + HIW+destch + HIW"方向离开...\n"NOR, me);
    me->move(__DIR__"dache");
	if(me->query("xkxvip/times") > 0)
    call_out("traveling",1,me,destch,destin,destmg);
	else call_out("traveling",6+random(4),me,destch,destin,destmg);
    return 1;
}
int do_travel(string arg)
{

            object* inv;
	        string destin,str, destch, destmg;
	        int i;
            object me = this_player();

          if (!arg)
          {
              str = ZJOBLONG"你要到哪里去？\n"ZJOBACTS2+ZJMENUF(2,2,9,35);
        str += "扬州:jiaoche yz"+ZJSEP;
		str += "少林:jiaoche sl"+ZJSEP;
	    str += "武当:jiaoche wd"+ZJSEP;
		str += "星宿:jiaoche xx"+ZJSEP;
		str += "全真:jiaoche qz"+ZJSEP;
		str += "华山:jiaoche hs"+ZJSEP;
		str += "灵鹫:jiaoche lj"+ZJSEP;
		str += "桃花岛:jiaoche thd"+ZJSEP;
		str += "明教:jiaoche mj"+ZJSEP;
		str += "天龙:jiaoche tls"+ZJSEP;
		str += "峨嵋:jiaoche em"+ZJSEP;
		str += "古墓:jiaoche gm"+ZJSEP;
		str += "白驼山:jiaoche bt"+ZJSEP;  
		str += "嘉兴:jiaoche jx"+ZJSEP;
		str += "泉州:jiaoche quan"+ZJSEP;
		str += "临安府:jiaoche laf"+ZJSEP;
		str += "苏州:jiaoche sz"+ZJSEP;
		str += "北京:jiaoche bj"+ZJSEP;
		str += "平西王府:jiaoche px"+ZJSEP;
		str += "襄阳:jiaoche xy"+ZJSEP;
		str += "泰山:jiaoche ts"+ZJSEP;
		str += "镇江:jiaoche zj"+ZJSEP;
		str += "江州:jiaoche jz"+ZJSEP;
		str += "岳阳:jiaoche yy"+ZJSEP;
		str += "晋阳:jiaoche jy"+ZJSEP;
		str += "长安:jiaoche ca"+ZJSEP;
		str += "昆明:jiaoche km"+ZJSEP;
		str += "神龙岛:jiaoche sld"+ZJSEP;
		str += "钓鱼岛:jiaoche dyd"+ZJSEP;
		str += "凌霄城:jiaoche lxc"+ZJSEP;
		str += "灵州:jiaoche lz"+ZJSEP;
		str += "归云庄:jiaoche gy"+ZJSEP;
		str += "丐帮:jiaoche gb"+ZJSEP;
		str += "侠客岛:jiaoche xkd"+ZJSEP;
		str += "慕容:jiaoche mr"+ZJSEP;
		str += "洛阳:jiaoche ly"+ZJSEP;
		str += "成都:jiaoche cd"+ZJSEP;
		str += "信阳:jiaoche xin"+ZJSEP;
		str += "张家口:jiaoche zjk"+ZJSEP;
		str += "应天府:jiaoche ytf"+ZJSEP;
		str += "大理城:jiaoche dl"+ZJSEP;
		str += "大轮寺:jiaoche dls"+ZJSEP;
		str += "杀手帮:jiaoche pker"+ZJSEP;
		str += "日月:jiaoche ry"+ZJSEP;
		
		
		
write(str+"\n");

              return 1;
        	}



if( me->query("jing") < 10 )
        return notify_fail("你精神不够旺盛，没力气瞎逛了！\n");

if(!environment(me)->query("outdoors"))
        return notify_fail("请先到室外在使用此命令！所谓室外，就是能看到天气描述的地方啦。\n");

if( me->query_temp("pending/exercising"))
        return notify_fail("你打完坐在走吧！\n");
if (environment(me)->query("pigging"))
		return notify_fail("你还是专心拱猪吧！\n");

if (me->is_fighting())
        return notify_fail("你正打的热闹着呢!\n");
if (me->is_busy())
        return notify_fail("你正忙着呢!\n");
if(me->query("xkxvip/times") == 0){
inv = deep_inventory(me);
        for(i=sizeof(inv)-1; i>=0; i--)
        if(inv[i]->is_character() || userp(inv[i]))
        return notify_fail("你不能背着个活物到处逛！\n");
		
if(me->query_encumbrance()*100/me->query_max_encumbrance()>50)
             return notify_fail("你身上的东西太多了，把没用的东西都扔了吧!\n");
}
        if(arg=="凌霄城" || arg == "lxc")
	{
		destin = "/d/lingxiao/chengmen.c";
		destch = "雪山派";
		destmg = "此处就是雪山派所在地凌霄城的城门。";
	}
     else if(arg=="武当" || arg == "wd")
	{
		destin = "/d/wudang/sanqing.c";
		destch = "武当";
		destmg = "此处就是武当的三清殿，不是武当弟子到这就进不去了，武当弟子要下山需要向宋远桥打听“下山”的消息。";
	}
     else if(arg=="少林" || arg == "sl")
	{
		destin = "/d/shaolin/shanmen";
		destch = "少林";
		destmg = "这是少林山门，女客不能再上了，男香客可以去广场。进少林寺只有少林弟子和持有英雄令的客人们才行。";
	}
    else if(arg=="星宿" || arg == "xx")
        {
		destin = "/d/xingxiu/xxgate.c";
		destch = "星宿";
		destmg = "这星宿海人烟稀少，附近倒是有个维吾尔族小镇。可是您别乱走，小心碰到不讲理的星宿弟子，或是走到沙漠里迷了路。";
	}
    else if(arg=="明教" || arg == "mj")
        {
		destin = "/d/mingjiao/damen";
		destch = "明教";
		destmg = "这里就是明教山门，不是本派弟子就上不去了，如果硬闯进去要千万小心，青翼蝠王韦一笑可是见人就杀。";
	}
    else if(arg=="华山" || arg == "hs")
	{
		destin = "/d/huashan/path1";
		destch = "华山";
		destmg = "华山派就在南边，山上风景不错，您自己上去转转吧。";
	}
    else if(arg=="全真" || arg == "qz")
	{
		destin = "/d/quanzhen/gongmen.c";
		destch = "全真";
		destmg = "全真派可是个不错的门牌，有很多好东西，如果男弟子要拜尹志平需要发誓“忠于全真”。";
	}
    else if(arg=="归云庄" || arg == "gy")
	{
		destin = "/d/guiyunzhuang/gate";
		destch = "归云庄";
		destmg = "拜桃花岛需要先入归云庄，要注意桃花岛的弟子不要随意pk同时要注意自己的道德哦，否则会被师傅开除的。";
	}
    else if(arg=="桃花岛" || arg == "thd")
	{
		destin = "/d/taohuadao/haian";
		destch = "桃花岛";
		destmg = "只能到海港这里了，要坐船才能去桃花岛(enter boat)，你自己试试吧。";
	}
    else if(arg=="峨眉" || arg == "em")
	{
                destin = "/d/emei/shanmen";
		destch = "峨嵋";
		destmg = "这是峨嵋山脚啦，不是本门弟子就进不去啦。爬峨嵋山可累人了，您悠着点儿。";
	}
    else if(arg=="扬州" || arg == "yz")
	{
		destin = "/d/city/kedian";
		destch = "扬州";
		destmg = "这是扬州客店。这里人多事儿多，好玩儿的地方也多着呐。";
	}
    else if(arg=="天龙" || arg == "tls")
	{
		destin = "/d/tianlong/foothill.c";
		destch = "天龙";
		destmg = "这里就是天龙寺了。据说大理王子段誉在琅缳福地，不知道是个什么地方。";
	}
    else if(arg=="嘉兴" || arg == "jx")
	{
		destin = "/d/quanzhou/nanhu.c";
		destch = "嘉兴";
		destmg = "这里是嘉兴南湖。江湖谣传西毒欧阳锋曾经在这附近出现过，不知道是真是假。";
	}
    else if(arg=="泉州" || arg == "quan")
	{
		destin = "/d/quanzhou2/zhongxin.c";
		destch = "泉州";
		destmg = "这里是泉州城中心。附近有一幢向阳老宅，听说闹鬼，你还是不要过去的好。";
	}
    else if(arg=="古墓" || arg == "gm")
	{
		destin = "/d/gumu/caodi";
		destch = "古墓";
		destmg = "这里就是杨过与小龙女双宿双栖的古墓了，要拜师的话，你去向杨女打听“进墓”吧。";
	}
    else if(arg=="襄阳" || arg == "xy")
	{
		destin = "/d/xiangyang/sgate";
		destch = "襄阳";
		destmg = "这里是北方重镇襄阳城，目前正受到蒙古军队的攻击，如果你想加入襄阳保卫战，就向守将打听“投军”的消息吧。";
	}
    else if(arg=="泰山" || arg == "ts")
	{
		destin = "/d/taishan/daizong";
		destch = "泰山";
		destmg = "您自己上去吧。轻功如果太低上山小心别摔着。山上有当今武林盟主，赏善罚恶使者。";
	}
    else if(arg=="灵州" || arg == "lz")
	{
		destin = "/d/lingzhou/center.c";
		destch = "灵州";
		destmg = "您自己到处逛逛吧，不过别乱闯西夏皇宫啊。";
	}
    else if(arg=="平西王府" || arg == "px")
	{
		destin = "/d/pingxiwangfu/wangfugate";
		destch = "平西王府";
		destmg = "要进去就向亲兵头打听“自立为王”的消息，据说平西王的宝库里面有很多好东西。";
	}
    else if(arg=="灵鹫" || arg == "lj")
	{
		destin = "/d/lingjiu/jian";
		destch = "灵鹫宫";
		destmg = "要上山必须余婆婆带你去了，向她打听一下“上山”的消息吧，不过灵鹫宫只收女弟子哦。";
	}
    else if(arg=="杀手帮" || arg == "pker")
	{
		destin = "/d/pker/guangchang.c";
		destch = "杀手帮";
		destmg = "杀手帮是江湖中的一个秘密门牌，据说帮助楚云飞行凶会得到意想不到的奖励。";
	}
    else if(arg=="侠客岛" || arg == "xkd")
	{
		destin = "/d/xiakedao/nanhaibin";
		destch = "侠客岛";
		destmg = "侠客岛是无数武林人事梦寐以求想去的地方，不过只有得到赏善罚恶令的人才有资格去，你可以问问这里的黄衣大汉(wave dahan)。";
	}
    else if(arg=="丐帮" || arg == "gb")
	{
		destin = "/d/city/gbxiaowu.c";
		destch = "丐帮小屋";
		destmg = "新手加入丐帮应该算是成长最快的了，升袋会有很多经验奖励，而且丐帮弟子可以随地睡觉，真是爽啊！";
	}
    else if(arg=="临安府" || arg == "laf")
	{
		destin = "/d/hangzhou/bazi";
		destch = "临安府";
		destmg = "临安府是大宋的都城。";
	}
    else if(arg=="日月" || arg == "ry")
	{
		destin = "/d/riyuejiao/rukou.c";
		destch = "日月教";
		destmg = "日月教有很多秘密，如果自己实在摸索不出，也可以问问高手。";
	}
    else if(arg=="钓鱼岛" || arg == "dyd")
	{
		destin = "/d/diaoyudao/matou0";
		destch = "泉州港";
		destmg = "只能到这里了，要去钓鱼岛也要自己解开秘密才行，听说要有罗盘才不会在海上迷路。";
	}
    else if(arg=="姑苏慕容" || arg == "mr")
	{
		destin = "/d/murong/hubian1";
		destch = "太湖";
		destmg = "姑苏慕容在太湖之上，必须要坐船才能过去，你向绿衣女郎打听一下“拜庄”的消息吧。";
	}
    else if(arg=="苏州" || arg == "sz")
	{
		destin = "/d/suzhou/kedian.c";
		destch = "苏州";
		destmg = "要去姑苏慕容必须要经过苏州，你最好熟悉一下这里的地图。";
	}
    else if(arg=="白驼山" || arg == "bt")
	{
		destin = "/d/baituo/gebi";
		destch = "白驼山";
		destmg = "去白驼山的路上有一片大沙漠很危险，以后你来此地最好是骑上骆驼。";
	}
    else if(arg=="北京" || arg == "bj")
	{
                destin = "/d/beijing/yonganmen";
                destch = "北京城";
                destmg = "北京城晚上要关城门，要进城可要赶白天啊，晚上翻墙小心被官兵发现，被通缉了可不好办。";
	}
    else if(arg=="大轮寺" || arg == "dls")
	{
                destin = "/d/dalunsi/guangchang";
                destch = "大轮寺";
                destmg = "大轮寺终年积雪，没有一定轻功很难直接爬上来，可以做缆车，不过最好还是走丐帮密道啦。";
	}
    else if(arg=="神龙岛" || arg == "sld")
	{
                destin = "/d/shenlongdao/matou";
                destch = "神龙岛";
                destmg = "神龙岛要走塘沽坐船过来，岛上神龙（其实就是蛇啦）众多，如果不想被蛇咬就跟沐姑娘讨杯雄黄酒喝。";
	}
    else if(arg=="洛阳" || arg == "ly")
	{
                destin = "/d/luoyang/center";
                destch = "洛阳";
                destmg = "洛阳可是一个好地方，听说天地会搬到这里来了，对了，萧峰帮主也在这里。";
	}
    else if(arg=="大理" || arg == "dl")
	{
                destin = "/d/dalicheng/northgate";
                destch = "大理";
                destmg = "大理山清水秀，景色怡人，还有很多美食。大理王府就在这大理城中。";
	}
    else if(arg=="江州" || arg == "jz")
	{
                destin = "/d/jiangzhou/eastgate";
                destch = "江州";
                destmg = "江州据说有隐居的高手韩员外坐镇，宵小之辈不得作祟。";
	}
    else if(arg=="镇江" || arg == "zj")
	{
                destin = "/d/zhenjiang/southgate";
                destch = "镇江";
                destmg = "镇江扼守长江之滨，地势险要，金山寺里有个老和尚。";
	}
    else if(arg=="岳阳" || arg == "yy")
	{
                destin = "/d/yueyang/southgate";
                destch = "岳阳";
                destmg = "岳阳是一座古城，城内有岳阳楼等古迹。";
	}
    else if(arg=="昆明" || arg == "km")
	{
                destin = "/d/kunming/westgate";
                destch = "昆明";
                destmg = "昆明地处西南边陲，平西王府就在城北。";
	}
    else if(arg=="成都" || arg == "cd")
	{
                destin = "/d/chengdu/eastgate";
                destch = "成都";
                destmg = "成都是西南第一大城，天府之国，四通八达，交通便利。";
	}
    else if(arg=="晋阳" || arg == "jy")
	{
                destin = "/d/jinyang/jinsumen";
                destch = "晋阳";
                destmg = "晋阳城内有家药铺，据说隐藏着一些秘密。";
	}
    else if(arg=="长安" || arg == "ca")
	{
                destin = "/d/changan/southgate";
                destch = "长安";
                destmg = "长安十朝古都，是一座雄城，据八百里秦川形胜之地。";
	}
    else if(arg=="信阳" || arg == "xin")
	{
                destin = "/d/xinyang/southgate";
                destch = "信阳";
                destmg = "信阳是扬州和襄阳之间一座重要的城市，城南的汤泉池据说可以泡泡温泉。";
	}
    else if(arg=="张家口" || arg == "zjk")
	{
                destin = "/d/saiwai/southgate";
                destch = "张家口";
                destmg = "张家口是连接蒙古草原的关隘。";
	}
    else if(arg=="应天府" || arg == "ytf")
	{
                destin = "/d/yingtiannorth/machehang";
                destch = "应天府";
                destmg = "应天府是大宋的重要城市，只能先送到城外。";
	}
	else
   	{
 	return notify_fail("没有这个地方吧？？？\n");
	}

    message_vision(HIW"$N"+HIW+"拿出储物袋，从里面掏出来一辆大车！\n"NOR, me);
    message_vision(HIW"大车载着$N向" + HIW+destch + HIW"方向离开...\n"NOR, me);
    me->move(__DIR__"dache");
	if(me->query("xkxvip/times") > 0)
    call_out("traveling",1,me,destch,destin,destmg);
	else call_out("traveling",6+random(4),me,destch,destin,destmg);
    return 1;
}
int traveling(object me,string destch,string destin,string destmg)
{
    object pla=load_object(destin);
    if (pla)
    {
        me->move(pla);
        message_vision(HIW"$N从大车上下来了。\n", me);
	    tell_object(me, "车夫告诉你：“到啦，这里就是" + destch + "。”\n");
	    tell_object(me, CYN "车夫又说：“再免费告诉你点东西，" + destmg + "”\n" NOR);
        me->add("jing", -5);
    }
    return 1;
}

varargs int do_store(string arg, int index)
{
	object me,ob;
	string *item_nb,nb;
	int i, snum;
	mapping info=([]);
	string type;

	me = this_player();
	if(!arg)
	{
		write("你要向袋子中存什么物品？\n");
		return 1;
	}

	if(!objectp(ob=present(arg,me)))
	{
		write("你身上没有这种物品吧？\n");
		return 1;
	}

//特殊物品不能保存
	if (ob->query("unique") || ! clonep(ob) )
	{
		tell_object(me, ob->name() + "不能储存在袋子里。\n");
		return 1;
	}

//装备中物品不能保存
	switch((string)ob->query("equipped")) 
	{
	case "worn":
		tell_object(me, ob->name() + "必须先脱下来才能存放。\n");
		return 1;
	case "wielded":
		tell_object(me, ob->name() + "必须先解除装备才能存放。\n");
		return 1;
	}

//内含物品的容器物品不能保存
	if (sizeof(all_inventory(ob))) 
	{
		tell_object(me, "请你先把" + ob->query("name") + "里面的东西先拿出来。\n");
		return 1;
	}

	if (ob->is_character()) 
	{
		tell_object(me, "你想把一个大活物硬塞到柜子里？\n");
		return 1;
	}

	if (ob->query("money_id"))
	{
		tell_object(me, "存钱的话还是到钱庄去吧！\n");
		return 1;
	}
	if (ob->query("no_cun"))
	{
		tell_object(me, "这属于特殊物品，袋子无法保存！\n");
		return 1;
	}
	if (ob->is_corpse()) 
	{
		tell_object(me, "这东西放里面会发臭的吧？\n");
		return 1;
	}
//这里可以加入更多不能保存物品的判断
//////尸体，活物，等等。。。
if( !ob->query("systemmake") )
{
	if(!clonep(ob)
	||ob->query("unique")
	||ob->query("treasure")
	||ob->query("owner")
	||ob->query("no_put")
	||ob->query("u_times")
	||ob->query("quest")
	||ob->is_corpse()
	||ob->query("food_remaining")
	||ob->query("liquid")
	||ob->query("material")=="meat"
	||ob->query("money_id")
	||ob->is_character()
	||(stringp(ob->query("owner")) && ob->query("owner")!="0")
	||ob->query("credit")
	) {
		tell_object(me, "这个东西不能存入储物袋。\n");
		return 1;
	}
}
	snum = 20 + me->query("zjvip/all_pay")/10 + me->query("combat_exp")/50000;
	if (snum>100) snum=100;

	if (mapp(baowus)&&(sizeof(keys(baowus))>=snum)) {
		tell_object(me, "你的储物袋已经放不下更多物品了，赶紧整理一下吧。\n");
		return 1;
	}
	
	if (!index && ob->query_amount()) {
		write(INPUTTXT("请输入存放"+ob->name()+NOR"的数量：","mystore put "+file_name(ob)+" $txt# ")+"\n");
		return 1;
	}
	if (index && index > ob->query_amount()) {
		tell_object(me, "你身上没有这么数量。\n");
		return 1;
	}
	if (index && index < 1){
		tell_object(me, "你存入的数量不正确。\n");
		return 1;
	}
	
	if(ob->query("weapon_prop"))
		type="武器";
	else if(ob->query("armor_prop"))
		type="防具";
	else
		type="杂货";
	
	info["short"] = ob->query("name");
	
	if (index) {
		info["base_unit"] = ob->query("base_unit");
		info["amount"] = index;
	} 
	
	info["id"] = ob->parse_command_id_list();
	info["file"] = base_name(ob);
	info["type"] = type;
	info["data"] = save_variable(ob->query_entire_dbase());

	if( !mapp(baowus)) baowus = ([]);
	if( baowus == ([]))
	{
		baowus["1"] = info;
		if (index)
			ob->add_amount(-index);
		else
			destruct(ob);
		save();
	}
	else
	{
		item_nb = sort_array( keys(baowus), (: strcmp :) );
		for(i=1; i<(sizeof(item_nb)+2); i++) {
			nb = sprintf("%d",i);
			
			if (index && baowus[nb] && baowus[nb]["file"] == info["file"] && baowus[nb]["amount"] > 0) {
				baowus[nb]["amount"] += index;
				tell_object(me,"你把"+ob->query("name") + "，数量"+(index?index:1)+"，存进了袋子！\n");
				log_file("baibao/cun", sprintf("%-24s%-40s%s\n", 
							me->name() + "("+me->query("id")+")", 
								"存入"+filter_color(ob->name())+"("+ob->query("id")+")数量:"+(index?index:1), ctime(time())));
				if (index)
					ob->add_amount(-index);
				else
					destruct(ob);
				break;
			}
			else
			if(undefinedp(baowus[nb]))
			{
				baowus[nb] = info;
				tell_object(me,"你把"+ob->query("name") + "存进了袋子！\n");
				log_file("baibao/cun", sprintf("%-24s%-40s%s\n", 
							me->name() + "("+me->query("id")+")", 
								"存入"+filter_color(ob->name())+"("+ob->query("id")+")数量:"+(index?index:1), ctime(time())));
				if (index)
					ob->add_amount(-index);
				else
					destruct(ob);
				break;
			}
			/*
			baowus = ([]);
			*/
		}
		save();
	}
	me->save();
	if(!index && objectp(ob))
		tell_object(me,"物品存入失败！\n");
	else
		tell_object(me,"物品存入成功！\n");
	me->force_me("mystore put");
	return 1;
}
string long()
{
	object me = this_player();
	tell_object(me, ZJFORCECMD("mystore"));
	return "";
}

varargs int get_item(string arg, int index)
{
	object me,ob;
	string *item_nb;
	int i;

	me = this_player();

	if( !mapp(baowus) || baowus==([]))
	{
		write("你的袋子中没什么东西可取的。\n");
		return 1;
	}
	if(!arg)
	{
		write("你要从袋子中取出什么物品？\n");
		return 1;
	}

	if(undefinedp(baowus[arg]))
	{
		write("你的袋子中没没有这个编号的物品。\n");
		return 1;
	}

	if (!index && baowus[arg]["amount"] > 0) {
		write(INPUTTXT("请输入取出的数量：","mystore get "+arg+" $txt# ")+"\n");
		return 1;
	} 
		
	if (index && index < 1){
		tell_object(me, "你想取的数量不正确。\n");
		return 1;
	}
		
	if (index && baowus[arg]["amount"] < index)
	{
		tell_object(me, "你袋子里并没有存放这么多数量。\n");
		return 1;
	}
	
	ob = new(baowus[arg]["file"]);
	if (!ob)
	{
		tell_object(me, "你袋子里这件物品文件已经消失，请联系巫师。\n");
		return 1;
	}
	ob->set_dbase(restore_variable(baowus[arg]["data"]));
	ob->set_name(baowus[arg]["short"],baowus[arg]["id"]);
	if (index && baowus[arg]["amount"])
		ob->set_amount(index);
	tell_object(me,"你把"+ob->query("name")+"从袋子中取出！\n");

	if(ob->move(me))
	{
		if (index && baowus[arg]["amount"] > index)
		{
			baowus[arg]["amount"] -= index;
		} else
			map_delete(baowus, arg);
		me->save();
		save();
		tell_object(me,"物品取出成功！\n");
		log_file("baibao/qu", sprintf("%-24s%-40s%s\n", 
					me->name() + "("+me->query("id")+")", 
						"取出"+filter_color(ob->name())+"("+ob->query("id")+")数量:"+(index?index:1), ctime(time())));
	}
	else
		tell_object(me,"物品取出失败！\n");
	me->force_me("mystore");
	return 1;
}

int query_item(string arg)
{
	object me;
	string *item_nb;
	string *msg, ob_name, type, name;
	int ye, yeall, j, i;
	string str,line;

	me = this_player();

	if( !mapp(baowus) )
	{
		write("你目前没有存放任何物品在袋子里。\n");
		return 1;
	}

	item_nb = sort_array( keys(baowus), (: strcmp :) );

	if( sizeof(item_nb)<1 )
	{
		write("你目前没有存放任何物品在袋子里。\n");
		return 1;
	}
	msg = ({});
	if (!arg)
		arg = "全部 1";
	
	if( sscanf(arg, "%s %s %d", type, name, ye) != 3)
		if( sscanf(arg, "%s %d", type, ye) != 2) {
			write("你要查看什么？\n");
			return 1;
		}
		
	for (i = 0; i < sizeof(item_nb); i++) 
	{
		if (type == "全部" || type == baowus[item_nb[i]]["type"] 
			|| (type == "名称" && strsrch(baowus[item_nb[i]]["short"], name) != -1))
		{
			ob_name = baowus[item_nb[i]]["short"];
					
			if (baowus[item_nb[i]]["amount"] /*&& baowus[item_nb[i]]["base_unit"]*/)
				ob_name = baowus[item_nb[i]]["amount"] +"" + (baowus[item_nb[i]]["base_unit"] ? baowus[item_nb[i]]["base_unit"] : "件")+ ob_name;
			else
			if(baowus[item_nb[i]]["unit"])
				ob_name = baowus[item_nb[i]]["unit"] + ob_name;
			
			line = sprintf("%s:%s", ob_name,"mystore get "+item_nb[i]);
			msg += ({ line, });
		}
	}

	if(msg==({})) {
		write("没有你要找的物品！\n");
		return 1;
	}
	msg -=({0});
	str = ZJOBLONG+sprintf("袋子中【%s】的物品有(%d件)："+"\n", name ? name : type+"类型", sizeof(msg));
	str += ZJOBACTS2+ZJMENUF(2,2,9,30);

	yeall = sizeof(msg)/20;
	if(sizeof(msg)%20) yeall += 1;
	if(ye<1) ye = 1;
	if(ye>yeall) ye = yeall;
	j = (ye-1)*20;
	i = ye*20;
	if (i >= sizeof(msg)) i = sizeof(msg);
	i--;
	if(yeall>1)
		str += "上一页:mystore "+type+" "+(ye-1)+ZJSEP"下一页("+(ye)+"/"+(yeall)+"):mystore "+type+" "+(ye+1)+ZJSEP;
	str += implode(msg[j..i], ZJSEP);

	write(str+"\n");
	return 1;
}	
int query_autoload() { return 1; }
