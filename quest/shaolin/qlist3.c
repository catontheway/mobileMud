#include <ansi.h>

inherit SKILL;

mapping *quest = ({
        ([      "quest":		"杨逍",               
                "quest_type":           "杀",
                "time":  		1200,
                "score"	:		20,
                "reason" :              "由于现在名教极为嚣张，" 
        ]),
        ([      "quest":		"摘星子",               
                "quest_type":           "杀",
                "time":  		9000,
                "score"	:		15,
                "reason" :              "现在星宿派摘星子作恶多端，" 
        ]),

        ([      "quest":                "黛绮丝",
                "quest_type":           "杀",
                "time":                 1200,
                "score" :               20,
                "reason" :              "由于现在名教极为嚣张，" 
        ]),
        ([      "quest":                "韦一笑",
                "quest_type":           "杀",
                "time":                 1000,
                "score" :               16,
                "reason" :              "由于现在名教极为嚣张，" 
        ]),
        ([      "quest":		"丁春秋",               
                "quest_type":           "杀",
                "time":  		1200,
                "score"	:		20,
                "reason" :              "现在星宿派极为嚣张，为了遏制这股势力，\n" 
        ]),
       
        ([      "quest":                "伏魔刀",
                "quest_type":           "寻",
                "time":                 1200,
                "score" :               15,
                "reason" :              "玄痛大师急需一件衬手的兵器，"  
        ]),
        ([      "quest":                "金刚罩",
                "quest_type":           "寻",
                "time":                 1200,
                "score" :               15,
                "reason" :              "玄苦大师急需一件合适的护具，"  
        ]),       
        ([      "quest":                "谢逊",
                "quest_type":           "杀",
                "time":                 1200,
                "score" :               18,
                "reason" :              "由于现在名教极为嚣张，" 
        ]),  
        ([      "quest":                "殷天正",
                "quest_type":           "杀",
                "time":                 1200,
                "score" :               20,
                "reason" :              "由于现在名教极为嚣张，" 
        ]),
        ([      "quest":                HIG"玄铁剑"NOR,
                "quest_type":           "寻",
                "time":                 700,
                "score" :               10,
                "reason" :              "听说"HIG"玄铁剑是天下少有的利器，我想照样打造一柄，" 
        ]),
        ([      "quest":                "金刚伏魔圈",
                "quest_type":           "扫",
                "time":                 300,
                "score" :               10,
                "reason" :              "我少林三位渡字辈前辈坐禅的金刚伏魔圈需要人打扫，\n"               
        ]),
        
           
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
