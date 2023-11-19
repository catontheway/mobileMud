//中立门牌的门忠任务列表：包括（"taohua", "gumu", "lingjiu", "murong", "mingjiao" ）
// the quest format is the following mapping:
 // exp :    type     name           id            objname  objid     time 

#include <ansi.h>
int iszhengpai() {return 0;}

mapping quests_list = ([
     402 : ({ "kill","野狗",              "dog" ,  "",  "", "120" }),
     602 : ({ "kill","野兔",              "ye tu",  "",  "", "120" }), 
     222 : ({ "kill","麻雀",              "maque" ,  "",  "", "120" }),
     102 : ({ "kill","书生",              "shu sheng",  "",  "", "120" }),
     105 : ({ "kill","小孩",              "kid" ,  "",  "", "120" }),
     140 : ({ "kill","回族妇女",      "woman" ,  "",  "", "160" }), 
     232 : ({ "kill","药铺伙计",          "yaopu huoji", "", "", "160" }),
     740 : ({ "kill","挑夫",              "tiao fu",  "",  "", "160" }), 
     478 : ({ "kill","阿庆嫂",            "aqing sao", "", "", "160"}),
     101 : ({ "give","店小二",            "xiao er",  "花雕酒袋",  "jiudai", "120" }), 
     501 : ({ "give","老大娘",            "old woman",  HIW"白银"NOR,  "silver", "120" }), 
     101 : ({ "give","老妇人",              "oldwoman" ,  HIW"白银"NOR,  "silver", "120" }), 
     301 : ({ "give","地保",               "dibao" ,  "铁棍",  "tiegun", "120" }),  
     501 : ({ "give","挑夫",              "tiao fu",  "手杖",      "walking stick", "180" }),      
     201 : ({ "give","小孩",              "kid" ,  YEL"铜板"NOR,  "coin", "120" }),
     502 : ({ "win","书生",              "shu sheng",  "",  "", "120" }),
        
    1012 : ({ "kill","流氓",               "liu mang", "","","120" }),
    3012 : ({ "kill","华山弟子",               "dizi", "","","120" }),  
    5012 : ({ "kill","知客道长",               "zhike daozhang", "","","120" }),  
    5012 : ({ "kill","知客道长",               "zhike daozhang", "","","120" }),        
    9072 : ({ "kill","衙役",               "ya yi", "","","120" }),
    3701 : ({ "give","赵狗儿",              "zhao gouer", "肥鸭","fei ya","120"}),
    1000 : ({"find","道德经「下卷」",      "jing","",    "",        "120" }), 
    4000 : ({"find",CYN"拳脚入门"NOR,     "unarmed book","",    "",        "120" }), 
    4000 : ({"find",CYN"指法入门"NOR,     "finger book","",    "",        "120" }),
    4000 : ({"find",CYN"拳法入门"NOR,     "cuff book","",    "",        "120" }),
    4000 : ({"find",CYN"手法入门"NOR,     "hand book","",    "",        "120" }),
    4000 : ({"find",CYN"掌法入门"NOR,     "strike book","",    "",        "120" }),
    4000 : ({"find",CYN"爪法入门"NOR,     "claw book","",    "",        "120" }),
    1000 : ({"find","榴莲",                "durian","",    "",        "120" }),    
    1000 : ({"find",HIR"苹果"NOR,           "apple","",    "",        "120" }),  
    1000 : ({"find",HIY"香蕉"NOR,                "banana","",    "",        "120" }),  
    1000 : ({"find",BLU"菠萝"NOR,                "pineapple","",    "",        "120" }),  
    1000 : ({"find",HIY"橙子"NOR,           "orange","",    "",        "120" }), 
    1000 : ({"find",HIG"西瓜"NOR,           "watermelon","",    "",        "120" }), 
    1000 : ({"find",MAG"荔枝"NOR,           "lichee","",    "",        "120" }), 
    1250 : ({"find","旧竹片",            "bamboo",         "",       "",        " 60" }),
    1300 : ({"find","麻鞋",              "gunny shoes",    "",       "",        "120" }), 
    1500 : ({"find","火折",              "fire",       "",       "",        "120" }), 
    1600 : ({"find","熏田鸡",            "tian ji",        "",       "",        "200" }), 
    1610 : ({"find","好逑汤",            "haoqiu tang",    "",       "",        "200" }), 
    2000 : ({"find","六脉神剑剑谱",      "liumai-shenjian jianpu", "", "",    "160" }),          
    2100 : ({"find","粽子",              "zongzi",         "",       "",        "200" }), 
    2140 : ({"find","少林英雄令",        "yingxiong ling", "",       "",        "120" }), 
    2300 : ({"find","短剑",              "duanjian",       "",       "",        "120" }), 
    5835 : ({ "kill","星宿派鼓手",               "gushou","","","220" }),
    5835 : ({ "kill","星宿派钹手",               "boshou","","","220" }),
    5835 : ({ "kill","星宿派号手",               "haoshou","","","220" }),
    2102 : ({ "kill","小喽罗",            "xiao louluo",  "",  "", "400" }),
    1939 : ({ "kill","小土匪",               "xiao tufei",  "",  "", "300" }),
    5201 : ({ "give","商人",               "shang ren",HIY"黄金"NOR,"gold","180"}),
    3102 : ({ "win","农妇",              "woman" ,  "",  "", "120" }), 
    3502 : ({ "win","药铺伙计",          "yaopu huoji", "", "", "120" }),
        
   25032 : ({ "kill","日月教众",               "riyue jiaozhong", "","","400"}),
   10222 : ({ "kill","打手",                 "da shou","","","600"}),
3000000 : ({ "kill","海公公",              "hai gonggong", "","","300"}),
   25002 : ({ "kill","崔员外",               "cui yuanwai", "","","600" }),
   25502 : ({ "kill","采花子",               "caihua zi",   "",  "", "600" }),
   42002 : ({ "kill","霍都",               "huo du",  "",  "", "300" }),
   55022 : ({ "win","阿紫",               "a zi" ,"",  "", "300" }),
   81202 : ({ "kill","黑老板",                 "hei laoban","","","220"}),
   31202 : ({ "kill","舞蛇人",                 "snaker","","","220"}),
   11202 : ({ "kill","花匠",                 "gardener","","","220"}),
   10202 : ({ "kill","蛇奴",                 "she nu","","","220"}),
   10402 : ({ "kill","烧饭僧",              "seng","","","240"}),
   10402 : ({ "kill","虚通",              "xu tong","","","240"}),
   20402 : ({ "kill","虚明",              "xu ming","","","240"}),
   50402 : ({ "kill","清法比丘",              "qingfa biqiu","","","240"}),
   10402 : ({ "kill","守寺僧兵",              "seng bing","","","240"}),
   30402 : ({ "kill","清善比丘",              "qingshan biqiu","","","240"}),   
   20402 : ({ "kill","巡山弟子",              "xunshan dizi","","","240"}),     //emei
   10402 : ({ "kill","文心师太",              "wenxin shitai","","","240"}),    
   10402 : ({ "kill","文月师太",              "wenyue shitai","","","240"}),    
   10402 : ({ "kill","文虚师太",              "wenxu shitai","","","240"}),     
   10202 : ({ "kill","裘万家",              "qiu wanjia","","","240"}),
   20202 : ({ "kill","莫不收",              "mo bushou","","","240"}),
   60202 : ({ "kill","快活三",              "kuaihuo san","","","240"}),
   60202 : ({ "win","本尘大师",              "benchen dashi","","","240"}),
   95202 : ({ "kill","本相大师",              "benxiang dashi","","","240"}),
   90202 : ({ "kill","本参大师",              "bencan dashi","","","240"}),
//   20172 : ({ "kill","岳灵珊",                 "yue lingshan","","","240"}),
   25172 : ({ "win","梁发",                 "liang fa","","","240"}),
   30001 : ({ "give","药铺伙计",          "yaopu huoji", "毒蛇胆", "shedan", "500" }),
   50001 : ({ "give","书生",              "shu sheng",  "说文解字",  "shu", "500" }),
   52001 : ({ "give","牧羊人",             "muyang ren", "长鞭","changbian","400" }),
   54001 : ({ "give","梁发",               "liang fa", "华山剑谱","sword book","400"}),  
   55001 : ({ "give","陆大有",               "lu dayou", "华山剑谱","sword book","400"}),  
   60001 : ({ "give","渔夫",               "yu fu","鱼","fish","400" }),
   12000 : ({"find","衙役服",            "yayi cloth",     "",       "",        "200" }),  
   50000 : ({"find","牢房钥匙",          "laofang key",    "",       "",        "200" }), 
   58000 : ({"find","雷震挡",            "leizhendang",    "",       "",        "200" }), 
   17000 : ({"find","天山雪莲",            "xue lian",        "",       "",  "470" }), 
   38000 : ({"find","道德经「第十三章」","jing","",    "",        "520" }), 
   90000 : ({"find","大金刚拳法",        "shaolin wuji",   "",       "",        "640" }),   
   52000 : ({"find","水靠",              "shui kao",       "",       "",        "120" }), // dex>25
   57000 : ({"find","手信",              "letter",          "",       "",        "120" }), 
   51000 : ({ "win","空空儿",           "kong kong",  "",  "", "520" }),
   30402 : ({ "win",HIC"眼镜蛇"NOR,       "snake",  "",  "", "200" }),
   30502 : ({ "win",GRN"竹青蛇"NOR,       "snake",  "",  "", "200" }),
   51202 : ({ "win","金环蛇",             "jin she",  "",  "", "200" }), 
   51302 : ({ "win",HBWHT+BLK"七寸子蛇"NOR,     "snake",   "",  "", "200" }),
   10402 : ({ "win","烧饭僧",              "seng","","","240"}),
   15022 : ({ "win","庄仆",               "zhuang pu","","","240"}),
   20202 : ({ "win","王铁匠",             "wang tiejiang", "","","240" }),
   20902 : ({ "win","阿牧",               "a mu","","","240"}),
   30022 : ({ "win","家丁",               "jia ding", "","","240" }),
   30302 : ({ "win","小翠",               "xiao cui",  "",  "", "240" }), 
   50302 : ({ "win","净慈",              "xiao shami","","","240" }),  
   10072 : ({ "win","衙役",               "ya yi", "","","240" }),
   20122 : ({ "win","托钵僧",              "tuobo seng","","","240"}),
   20172 : ({ "win","岳灵珊",                 "yue lingshan","","","240"}),
   10202 : ({ "win","裘万家",              "qiu wanjia","","","240"}),

  152002 : ({ "kill","田伯光",               "tian boguang","",  "", "400" }),
//  152002 : ({ "kill",HIW"大轮寺护法喇嘛"NOR,  "hufa lama","",  "", "400" }),
  153002 : ({ "kill","李莫愁",               "li mochou","",  "", "800" }),
  154002 : ({ "kill","天狼子",               "tianlang zi", "",  "",  "400"  }),
  235002 : ({ "kill","狮吼子",               "shihou zi","",  "", "900" }),
  305002 : ({ "kill","摘星子",               "zhaixing zi", "",  "", "900"  }),
  500120 : ({ "win","欧阳克",               "ouyang ke", "",  "", "800" }),
  354002 : ({ "kill","任盈盈",               "ren yingying","",  "", "900"  }),
  352002 : ({ "kill","秃笔翁",               "tubi weng","",  "", "900" }),
  353002 : ({ "kill","丹青生",               "danqing sheng","",  "", "900" }),
  123002 : ({ "kill","丁坚",               "ding jian","",  "", "900" }),
  453002 : ({ "kill","黑白子",               "heibai zi","",  "", "900" }),
  853002 : ({ "kill","黄钟公",               "huangzhong gong","",  "", "900" }),
  850002 : ({ "kill","向问天",               "xiang wentian","",  "","900"}),
  557022 : ({ "kill","武三通",               "wu santong", "",  "", "300" }),
  253002 : ({ "kill","慧空尊者",               "huikong zunzhe","",  "", "600" }), 
  256002 : ({ "kill","慧色尊者",             "huise zunzhe","",  "", "600" }), 
  259002 : ({ "kill","慧真尊者",             "huizhen zunzhe","",  "", "600" }), 
  148002 : ({ "kill","谷虚道长",               "guxu daozhang","",  "", "800"  }),
  658002 : ({ "kill","宋远桥",               "song yuanqiao","",  "", "800"  }),
  558002 : ({ "win","张松溪",               "zhang songxi","",  "", "800"  }),
  858002 : ({ "kill","俞莲舟",               "yu lianzhou","",  "", "800"  }),
  658002 : ({ "kill","张翠山",               "zhang cuishan","",  "", "800"  }),
  458002 : ({ "kill","何不净",               "he bujing","",  "", "800"  }),
  908002 : ({ "kill","余洪兴",               "yu hongxing","",  "", "800"  }),
  258002 : ({ "kill","李斧头",               "li futou","",  "", "800"  }),
  122002 : ({ "kill","道成禅师",             "daocheng chanshi","",  "", "600" }),  
  125002 : ({ "kill","道品禅师",              "daopin chanshi","",  "", "600" }),       
  128002 : ({ "kill","道一禅师",             "daoyi chanshi","",  "", "600" }),         
  125002 : ({ "kill","本观大师",               "benguan dashi","",  "", "600" }),
  805002 : ({ "kill","徐天川",               "xu tianchuan","",  "", "600" }),
  985002 : ({ "win","宁中则",               "ning zhongze","",  "", "600" }),
  605002 : ({ "kill","丘处机",               "qiu chuji","",  "", "600" }),
  505002 : ({ "kill","马钰",               "ma yu","",  "", "600" }), 
  250000 : ({ "win","王处一",           "wang chuyi",  "",  "", "520" }),       
  350000 : ({ "win","郝大通",           "hao datong",  "",  "", "520" }),
  400000 : ({ "win","孙不二",           "sun bu er","",  "", "800" }),  
  550000 : ({ "win","关安基",           "guan anji","",  "", "800" }),
  200022 : ({ "win","静道师太",               "jingdao shitai", "",  "", "900" }),
  550022 : ({ "win","静风师太",               "jingfeng shitai", "",  "", "900"  }),
  100022 : ({ "win","静心师太",               "jingxin shitai","",  "", "900"  }),
  450000 : ({ "win","胖头陀",           "pang toutuo",  "",  "", "520" }),
  450000 : ({ "win","瘦头陀",           "shou toutuo",  "",  "", "520" }),
  400000 : ({ "win","梅超风",           "mei chaofeng","",  "", "800" }),
  450000 : ({ "win","陈玄风",           "chen xuanfeng","",  "", "800" }),
  100022 : ({ "win","鲍大楚",               "bao dachu", "",  "", "900" }),
  550022 : ({ "win","上官云",               "shangguan yun", "",  "", "900"  }),
  100022 : ({ "win","童百熊",               "tong baixiong","",  "", "900"  }),
  100001 : ({ "give","阿拉木罕",               "alamuhan", "天山雪莲","xue lian","400" }),
  150001 : ({ "give","李铁嘴",             "fortune teller",MAG "马屁宝典" NOR,"mapi baodian", "400" }),
  120001 : ({ "give","澄识",                   "chengshi luohan","大般涅磐经",  "shu", "600" }), 
  140001 : ({ "give","宋远桥",               "song yuanqiao","道德经「第十六章」",  "jing", "600" }),
  210001 : ({ "give","洪七公",              "hong qigong",GRN"玉竹杖"NOR,"yuzhu zhang", "600" }),  
  230001 :  ({ "give","裘万家",              "qiu wanjia","竹叶青","zhuye qing","600"}),
  240001 : ({ "give","王铁匠",             "wang tiejiang", "烧红的铁锤","hot hammer","600" }),
  245001 : ({ "give","打铁僧",               "datie seng",   "烧红的铁锤",  "hot hammer", "600" }),
  305001 : ({ "give","游客",               "youke","野果","ye guo","600" }),
  315001 : ({ "give","媒婆",               "mei_po" ,HIW "玉白露" NOR,  "flower", "600" }), 
  330001 : ({ "give","道童",               "daotong", "拂尘","fuchen","600" }),
  334001 : ({ "give","本观大师",               "benguan dashi", "凌波微步图谱","lingbo-weibu", "600" }),
  350001 : ({ "give","周伯通",                 "zhou botong","玉蜂浆",  "yufeng jiang", "600" }),       
  520001 : ({ "give","慧修尊者",                "huixiu zunzhe","韦陀棍法",  "shaolin wuji", "600" }), 
  620001 : ({ "give","黄药师",               "huang yaoshi","洗髓经",  "book", "600"  }),
  660001 : ({ "give","史青山",               "shi qingshan", "伏魔刀",  "fumo dao", "600"  }),
  320001 : ({ "give","波斯商人",               "bosi shangren","圣火令","shenghuo ling","400" }),
  105000 : ({"find","道德经「第十八章」","jing","",    "",        "300" }), //change
  110000 : ({"find","无量寿经",          "shu",            "",       "",        "300" }), 
  130000 : ({"find","军服",              "junfu",          "",       "",        "300" }), //kill bing
  210000 : ({"find",GRN"玉竹杖"NOR,      "yuzhu zhang","",       "",        "600" }),  //kill hu du
  309000 : ({"find","红玫瑰",            "red rose",       "",       "",        "600" }), //dodge>100
  330000 : ({"find","拂尘",              "fuchen",         "",       "",        "600" }), //kill li mochou 
  515000 : ({"find","普渡杖法",          "shaolin wuji",     "",       "",        "600" }), 
  120000 : ({"find","飞沙走石十三式",    "blade book", "",       "",        "350" }), 
  
 2000002 : ({ "kill","丁春秋",               "ding chunqiu","",  "", "1000" }),
 1000020 : ({ "kill","黑冠巨蟒",               "snake",  "",  "", "800" }),
 1020000 : ({"find","《广陵散》",      "guangling san",   "",       "",        "600" }),     
 3100000 : ({"find",HIR"日月神刀"NOR,    "riyue dao",          "",       "",        "600" }), 
 1500000 : ({"find",HIG"日月神剑"NOR,    "riyue jian", "",       "",        "1500" }), 
 5000000 : ({"find","菩提子",            "puti zi",        "",       "",        "600" }), 
 2010000 : ({"find",HIB "冰魄杖" NOR,    "bingpo zhang","",      "",        "500" }), 
 1010000 : ({"find","软猬甲",            "ruanwei jia",    "",       "",        "900" }),      //要求桃花岛
 2010000 : ({"find",YEL"九转熊胆丸"NOR,    "shanling wan","",      "",        "900" }), 
 2510000 : ({"find","白衣",              "white",          "",       "",        "900" }), 
 2520000 : ({"find","淑女剑",            "shunu sword",    "",       "",        "900" }), 
 3000000 : ({"find","叫化鸡",            "jiaohua ji",    "",       "",        "900" }),
 1000000 : ({"find",YEL"女娲石"NOR,            "nvwa shi",    "",       "",        "900" }),
 1000000 : ({"find","老山参",            "laoshan shen",    "",       "",        "900" }),
 6000220 : ({ "win","白自在",               "bai zizai","",  "", "900"  }),
        
12500002 : ({ "kill","李秋水",               "li qiushui","",  "", "1000" }),
12500002 : ({ "kill","欧阳锋",                 "ouyang feng","",  "", "1000" }),
13500002 : ({ "kill","鸠摩智",                 "jiumo zhi","",  "", "1000" }),
15500002 : ({ "kill","张三丰",               "zhang sanfeng","",  "", "1000" }),
12500002 : ({ "win","灭绝师太",                 "miejue shitai","",  "", "1000" }),
12500002 : ({ "kill","洪七公",                 "hong qigong","",  "", "1000" }),
13500002 : ({ "kill","段誉",                 "duan yu","",  "", "1000" }),
12500002 : ({ "win","陈近南",               "chen jinnan","",  "", "1000" }),
15500002 : ({ "win","王重阳",               "wang chongyang","",  "", "1000" }),
]);
   