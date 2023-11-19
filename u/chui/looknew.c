// look.c

#include <room.h>
#include <ansi.h>
#include <combat.h>
#include <color.h>

inherit F_CLEAN_UP;

int webmain(object me, string arg);//用网页玩的
int weblook_room(object me, object env);//用网页玩的
int weblook_item(object me, object obj);//用网页玩的
int weblook_living(object me, object obj, string arg);//用网页玩的
int weblook_room_item(object me, string arg);//用网页玩的

int mudmain(object me, string arg);//用ZMUD连入的
int mudlook_room(object me, object env);//用ZMUD连入的
int mudlook_item(object me, object obj);//用ZMUD连入的
int mudlook_living(object me, object obj);//用ZMUD连入的
int mudlook_room_item(object me, string arg);//用ZMUD连入的
string getper(object me, object obj);
string tough_level(int power, int hide_level);
string gettof(object obj);
string getdam(object obj);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object ob = this_player();     	
	int result;


if( ob->query("position") == "zmuduser" ) 
result = mudmain(me, arg);//如果身上有这个记号就调用MUDMAIN
	else 
result = webmain(me, arg);//如果身上没有记号就调用WEBMAIN
	return result;
}

void realtime_map(object me,object env)
{
    object room_obj;
    mapping exits;
    int i;
    string ln1,ln2,ln3,ln4,ln5,ln6;
    string map_room, map_room2,jiantou,msg;
    string setforroom;
    string *dirs;
    mapping alldirs=([      
        "northwest" : "          ",
        "north"     : "          ",
        "northup"   : "          ",
        "northeast" : "          ",
        "west"      : "          ",
        "east"      : "          ",
        "southeast" : "          ",
        "south"     : "          ",
        "southwest" : "          ",
        "southdown" : "          ",
        "eastup" : "          ",
        "southup" : "          ",
        "northdown" : "          ",
        "eastdown" : "          ",
        "westup" : "          ",
        "westdown" : "          ",
        "enter" : "          ",
        "out" : "          ",
        "up" : "          ",
        "down" : "          ",
        "left" : "          ",
        "right" : "          ",
        ]);  
        //add for save time
        msg = env->query("realmap");
        if(msg&&msg!="")
        {
            printf(msg);
            return;
        }
        msg = "";
        if( mapp(exits = env->query("exits")) ) 
        {                       
            if (me->query("position") != "zmuduser")
                printf("\n");
            dirs=keys(exits);
            for(i=0;i< sizeof(dirs);i++)
            {
                if(!room_obj=find_object(exits[dirs[i]]))
                    room_obj=load_object(exits[dirs[i]]);
                if(room_obj){
                    if (room_obj->query("short"))
                        alldirs[dirs[i]]=room_obj->query("short");
                }        
            }
            jiantou="  ";
            map_room2=alldirs["enter"];
            if(alldirs["enter"]!="          "){
                map_room2=alldirs["enter"];
                jiantou=HIR+"∧"+NOR;
            }
            if(alldirs["up"]!="          "){
                map_room2=alldirs["up"];
                jiantou=HIC+"〓"+NOR;
            }
            if(alldirs["northdown"]!="          "){
                map_room2=alldirs["northdown"];
                jiantou="↓";
            }
            if(alldirs["northup"]!="          "){
                map_room2=alldirs["northup"];
                jiantou="↑";
            }
            if(alldirs["north"]!="          "){
                map_room2=alldirs["north"];
                jiantou="｜";
            }
            map_room=map_room2;
            for(i=0;i<(10-strwidth(map_room2))/2;i++)
            {
                map_room =map_room+" ";
                map_room =" "+map_room;
            }
            if (me->query("position") == "zmuduser")
            {
                msg = sprintf("             %10s  %-10s  %-10s\n",
                        alldirs["northwest"],map_room,alldirs["northeast"]);
                printf(msg);
                setforroom = msg;
            }
            else{
                msg = sprintf("%10s %-10s  %-10s\n",
                        alldirs["northwest"],map_room,alldirs["northeast"]);
                msg = replace_string(msg," ","&nbsp");
                msg = replace_string(msg,alldirs["northwest"],
                        "<a target=nothing href=\\\"../Command/go northwest\\\">" + alldirs["northwest"] + "</a>");
                msg = replace_string(msg,alldirs["north"],
                        "<a target=nothing href=\\\"../Command/go north\\\">" + map_room + "</a>");
                msg = replace_string(msg,alldirs["northeast"],
                        "<a target=nothing href=\\\"../Command/go northeast\\\">" + alldirs["northeast"] + "</a>");
                msg = replace_string(msg,alldirs["northup"],
                        "<a target=nothing href=\\\"../Command/go northup\\\">" + alldirs["northup"] + "</a>");
                msg = replace_string(msg,alldirs["northdown"],
                        "<a target=nothing href=\\\"../Command/go northdown\\\">" + alldirs["northdown"] + "</a>");
                msg = replace_string(msg,alldirs["enter"],
                        "<a target=nothing href=\\\"../Command/go enter\\\">" + alldirs["enter"] + "</a>");
                msg = replace_string(msg,alldirs["up"],
                        "<a target=nothing href=\\\"../Command/go up\\\">" + alldirs["up"] + "</a>");
                //write(msg);
                ln1 = msg;
            }
            msg = sprintf("%s   %s   %s\n",
                    alldirs["northwest"]=="          " ? "  ":"＼",
                    jiantou,
                    alldirs["northeast"]=="          " ? "  ":"／");
            setforroom = setforroom + "                        " + msg;
            if (me->query("position") == "zmuduser")
                printf("                        " + msg);
            else
                ln2 = (replace_string("           "+msg," ","&nbsp"));
            jiantou="  ";
            map_room2=alldirs["westdown"];
            if(map_room2!="          ")
                jiantou="→";
            if(alldirs["left"]!="          "){
                map_room2=alldirs["left"];
                jiantou="〈";
            }
            if(alldirs["westup"]!="          "){
                map_room2=alldirs["westup"];
                jiantou="←";
            }
            if(alldirs["west"]!="          "){
                map_room2=alldirs["west"];
                jiantou="--";
            }
            msg = sprintf("             %10s%s",map_room2,jiantou);        
            setforroom += msg;
            if (me->query("position") == "zmuduser")
                printf(msg);
            else
            {
                msg = sprintf("%10s%s",map_room2,jiantou);
                msg = replace_string(msg," ","&nbsp");
                msg = replace_string(msg,alldirs["westdown"],
                        "<a target=nothing href=\\\"../Command/go westdown\\\">" + alldirs["westdown"] + "</a>");
                msg = replace_string(msg,alldirs["left"],
                        "<a target=nothing href=\\\"../Command/go left\\\">" + alldirs["left"] + "</a>");
                msg = replace_string(msg,alldirs["westup"],
                        "<a target=nothing href=\\\"../Command/go westup\\\">" + alldirs["westup"] + "</a>");
                msg = replace_string(msg,alldirs["west"],
                        "<a target=nothing href=\\\"../Command/go west\\\">" + alldirs["west"] + "</a>");
                ln3 = msg;
            }
            map_room2=env->query("short") ? env->query("short"): "----------";
            map_room=HIG+map_room2+NOR;
            for(i=0;i<(10-strwidth(map_room2))/2;i++)
            {
                if(alldirs["east"]=="          ")
                    map_room =map_room + " ";
                else map_room=map_room + "-";
                if(alldirs["west"]=="          ")
                    map_room =" "+ map_room;
                else map_room ="-"+map_room;
            }
            msg = sprintf("%s",map_room);
            setforroom +=msg;
            if (me->query("position") == "zmuduser")
                printf(msg);
            else
            {
                msg = replace_string(msg," ","&nbsp");
                msg = replace_string(msg,map_room,
                        "<a target=nothing href=\\\"../Command/look\\\">" + map_room + "</a>");
                ln3 += msg;
            }
            jiantou="  ";
            map_room2=alldirs["eastup"];
            if(map_room2!="          ")
                jiantou="→";
            if(alldirs["right"]!="          "){
                map_room2=alldirs["right"];
                jiantou="〉";
            }
            if(alldirs["eastdown"]!="          "){
                map_room2=alldirs["eastdown"];
                jiantou="←";
            }
            if(alldirs["east"]!="          "){
                map_room2=alldirs["east"];
                jiantou="--";
            }
            msg = sprintf("%s%-10s\n",jiantou,map_room2);
            setforroom += msg;
            if (me->query("position") == "zmuduser")
                printf(msg);
            else
            {
                msg = replace_string(msg," ","&nbsp");
                msg = replace_string(msg,alldirs["eastdown"],
                        "<a target=nothing href=\\\"../Command/go eastdown\\\">" + alldirs["eastdown"] + "</a>");
                msg = replace_string(msg,alldirs["left"],
                        "<a target=nothing href=\\\"../Command/go right\\\">" + alldirs["right"] + "</a>");
                msg = replace_string(msg,alldirs["eastup"],
                        "<a target=nothing href=\\\"../Command/go eastup\\\">" + alldirs["eastup"] + "</a>");
                msg = replace_string(msg,alldirs["east"],
                        "<a target=nothing href=\\\"../Command/go east\\\">" + alldirs["east"] + "</a>");
                ln3 += msg;
            }
            jiantou="  ";
            map_room2=alldirs["out"];
            if(alldirs["out"]!="          "){
                map_room2=alldirs["out"];
                jiantou=HIR+"∨"+NOR;
            }
            if(alldirs["down"]!="          "){
                map_room2=alldirs["down"];
                jiantou=HIC+"〓"+NOR;
            }
            if(alldirs["southdown"]!="          "){
                map_room2=alldirs["southdown"];
                jiantou="↑";
            }
            if(alldirs["southup"]!="          "){
                map_room2=alldirs["southup"];
                jiantou="↓";
            }
            if(alldirs["south"]!="          "){
                map_room2=alldirs["south"];
                jiantou="｜";
            }
            map_room=map_room2;
            for(i=0;i<(10-strwidth(map_room2))/2;i++)
            {
                map_room =map_room + " ";
                map_room =" "+map_room;
            }
            msg = sprintf("%s   %s   %s\n",
                    alldirs["southwest"]=="          " ? "  ":"／",
                    jiantou,
                    alldirs["southeast"]=="          " ? "  ":"＼");
            setforroom = setforroom + "                        " + msg;
            if (me->query("position") == "zmuduser")
                printf("                        "+msg);
            else
                ln4 = replace_string("           "+msg," ","&nbsp");
            msg = sprintf("%10s  %-10s  %-10s\n",
                    alldirs["southwest"],map_room,alldirs["southeast"]);
            setforroom = setforroom + "             " + msg;
            if (me->query("position") == "zmuduser")
                printf("             "+msg);
            else
            {
                msg = sprintf("%10s %-10s  %-10s\n",
                        alldirs["southwest"],map_room,alldirs["southeast"]);
                msg = replace_string(msg," ","&nbsp");
                msg = replace_string(msg,alldirs["southdown"],
                        "<a target=nothing href=\\\"../Command/go southdown\\\">" + alldirs["southdown"] + "</a>");
                msg = replace_string(msg,alldirs["down"],
                        "<a target=nothing href=\\\"../Command/go down\\\">" + alldirs["down"] + "</a>");
                msg = replace_string(msg,alldirs["southup"],
                        "<a target=nothing href=\\\"../Command/go southup\\\">" + alldirs["southup"] + "</a>");
                msg = replace_string(msg,alldirs["south"],
                        "<a target=nothing href=\\\"../Command/go south\\\">" + map_room + "</a>");
                msg = replace_string(msg,alldirs["out"],
                        "<a target=nothing href=\\\"../Command/go out\\\">" + alldirs["out"] + "</a>");
                msg = replace_string(msg,alldirs["southeast"],
                        "<a target=nothing href=\\\"../Command/go southeast\\\">" + alldirs["southeast"] + "</a>");
                msg = replace_string(msg,alldirs["southwest"],
                        "<a target=nothing href=\\\"../Command/go southwest\\\">" + alldirs["southwest"] + "</a>");
                ln5 = msg;
            }
        }
        else
        {
            map_room2=env->query("short") ? env->query("short"): "----------";
            map_room=HIG+map_room2+NOR;
            for(i=0;i<(10-strwidth(map_room2))/2;i++)
            {
                if(alldirs["east"]=="          ")
                    map_room =map_room + " ";
                else map_room=map_room + "-";
                if(alldirs["west"]=="          ")
                    map_room =" "+ map_room;
                else map_room ="-"+map_room;
            }
            msg = sprintf("\n                            %s\n",map_room);
            //        setforroom += msg;
            if (me->query("position") == "zmuduser")
                printf(msg);
        }
        if (me->query("position") != "zmuduser")
        {
            if( mapp(exits = env->query("exits")) ) {
                dirs = keys(exits);
                for(i=0; i<sizeof(dirs); i++)
                    if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
                        dirs[i] = 0;
                dirs -= ({ 0 });
                if( sizeof(dirs)==0 )
                    ln6 = "    这里没有任何明显的出路。";
                else if( sizeof(dirs)==1 )
                    ln6 = "    这里唯一的出口是 <a target=nothing href=\\\"../Command/go "  + dirs[0] + "\\\"" + WEBRED + dirs[0]  + "</a>" + WEBNOR + "。";
                else {
                    ln6 = "    这里明显的出口是 ";
                    for (i = 0; i < sizeof(dirs) - 2; i++)
                        ln6 += sprintf("<a target=nothing href=\\\"../Command/go %s\\\">%s</a>、", dirs[i], dirs[i]);
                    ln6 += sprintf("<a target=nothing href=\\\"../Command/go %s\\\">%s</a>和", dirs[sizeof(dirs) - 2], dirs[sizeof(dirs) - 2]);
                    ln6 += sprintf("<a target=nothing href=\\\"../Command/go %s\\\">%s</a>", dirs[sizeof(dirs) - 1], dirs[sizeof(dirs) - 1]);
                    ln6 += "。";
                }
            }
            printf(JSP "parent.look_map(\"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\")" NSP, 
                    ln1,ln2,ln3,ln4,ln5,ln6);	
        }
        env->set("realmap",setforroom);
        return;
}

string getper(object me, object obj)
{
    int per;
    int age;
    string str;
    string gender;

    per = obj->query("per");
    age = obj->query("age");

    if (random(2)) per = per + 1;
    if (obj->query_temp("apply/gender"))
        gender = obj->query_temp("apply/gender")[0];
    else
        gender = obj->query("gender");

    if(age > 80 ) per = per/3;
    else if(age > 70 ) per = per/2;
    else if(age > 60 ) per = per*2/3;
    else if(age > 50 ) per = per*3/4;

    if (gender == "男性") {
        if (per >39) str= HIG"他现在一派神人气度，仙风道骨，举止出尘。\n";
        else if (per > 38) str=HIG"他现在神清气爽，骨格清奇，宛若仙人。\n";
        else if (per > 37) str=HIG"他现在丰神俊朗，长身玉立，宛如玉树临风。\n"NOR;
        else if (per > 36) str=HIG"他现在飘逸出尘，潇洒绝伦。\n"NOR;
        else if (per > 35) str=HIG"他现在面如美玉，粉妆玉琢，俊美不凡。\n"NOR;
        else if (per > 34) str=HIG"他现在丰神如玉，目似朗星，令人过目难忘。\n"NOR;
        else if (per > 33) str=HIY"他现在粉面朱唇，身姿俊俏，举止风流无限。\n"NOR;
        else if (per > 32) str=HIY"他现在双目如星，眉梢传情，所见者无不为之心动。\n"NOR;
        else if (per > 31) str=HIY"他现在举动如行云游水，独蕴风情，吸引所有异性目光。\n"NOR;
        else if (per > 30) str=HIY"他现在双眼光华莹润，透出摄人心魄的光芒。\n"NOR;
        else if (per > 29) str=HIY"他生得英俊潇洒，风流倜傥。\n"NOR;
        else if (per > 28) str=MAG"他生得目似点漆，高大挺俊，令人心动。\n"NOR;
        else if (per > 27) str=MAG"他生得面若秋月，儒雅斯文，举止适度。\n"NOR;
        else if (per > 26) str=MAG"他生得剑眉星目，英姿勃勃，仪表不凡。\n"NOR;
        else if (per > 25) str=MAG"他生得满面浓髯，环眼豹鼻，威风凛凛，让人倾倒。\n"NOR;
        else if (per > 24) str=MAG"他生得眉如双剑，眼如明星，英挺出众。\n"NOR;
        else if (per > 23) str=CYN"他生得虎背熊腰，壮健有力，英姿勃发。\n"NOR;
        else if (per > 22) str=CYN"他生得肤色白皙，红唇墨发，斯文有礼。\n"NOR;
        else if (per > 21) str=CYN"他生得浓眉大眼，高大挺拔，气宇轩昂。\n"NOR;
        else if (per > 20) str=CYN"他生得鼻直口方，线条分明，显出刚毅性格。\n"NOR;
        else if (per > 19) str=CYN"他生得眉目清秀，端正大方，一表人才。\n"NOR;
        else if (per > 18) str=YEL"他生得腰圆背厚，面阔口方，骨格不凡。\n"NOR;
        else if (per > 17) str=YEL"他生得相貌平平，不会给人留下什么印相。\n"NOR;
        else if (per > 16) str=YEL"他生得膀大腰圆，满脸横肉，恶形恶相。\n"NOR;
        else if (per > 15) str=YEL"他生得獐头鼠须，让人一看就不生好感。\n"NOR;
        else if (per > 14) str=YEL"他生得面颊深陷，瘦如枯骨，让人要发恶梦。\n"NOR;
        else if (per > 13) str=RED"他生得肥头大耳，腹圆如鼓，手脚短粗，令人发笑。\n"NOR;
        else if (per > 12) str=RED"他生得贼眉鼠眼，身高三尺，宛若猴状。\n"NOR;
        else if (per > 11) str=RED"他生得面如桔皮，头肿如猪，让人不想再看第二眼。\n"NOR;
        else if (per > 10) str=RED"他生得呲牙咧嘴，奇丑无比。\n"NOR;
        else str=RED"他生得眉歪眼斜，瘌头癣脚，不象人样。\n"NOR;
    }
    else
    {
        if (per >39) str =HIW"她现在宛如玉雕冰塑，似梦似幻，已不再是凡间人物\n"NOR;
        else if (per > 38)  str =HIG"她现在美若天仙，不沾一丝烟尘。\n"NOR;
        else if (per > 37)  str =HIG"她现在灿若明霞，宝润如玉，恍如神妃仙子。\n"NOR;
        else if (per > 36)  str =HIG"她现在气质美如兰，才华馥比山，令人见之忘俗。\n"NOR;
        else if (per > 35)  str =HIG"她现在丰润嫩白，婴桃小口，眉目含情，仿佛太真重临。\n"NOR;
        else if (per > 34)  str =HIG"她现在鲜艳妩媚，袅娜风流，柔媚姣俏，粉光脂艳。\n"NOR;
        else if (per > 33)  str =HIY"她现在鬓若刀裁，眉如墨画，面如桃瓣，目若秋波。\n"NOR;
        else if (per > 32)  str =HIY"她现在凤眼柳眉，粉面含春，丹唇贝齿，转盼多情。\n"NOR;
        else if (per > 31)  str =HIY"她现在眉目如画，肌肤胜雪，真可谓闭月羞花。\n"NOR;
        else if (per > 30)  str =HIY"她现在娇若春花，媚如秋月，真的能沉鱼落雁。。\n"NOR;
        else if (per > 29)  str =HIY"她生得闲静如姣花照水，行动似弱柳扶风，体态万千。\n"NOR;
        else if (per > 28)  str =MAG"她生得娇小玲珑，宛如飞燕再世，楚楚动人。\n"NOR;
        else if (per > 27)  str =MAG"她生得鸭蛋秀脸，俊眼修眉，黑发如瀑，风情万种。\n"NOR;
        else if (per > 26)  str =MAG"她生得削肩细腰，身材苗条，娇媚动人，顾盼神飞。\n"NOR;
        else if (per > 25)  str =MAG"她生得丰胸细腰，妖娆多姿，让人一看就心跳不已。\n";
        else if (per > 24)  str =MAG"她生得粉嫩白至，如芍药笼烟，雾里看花。\n"NOR;
        else if (per > 23)  str =CYN"她生得腮凝新荔，目若秋水，千娇百媚。\n"NOR;
        else if (per > 22)  str =CYN"她生得鲜艳妍媚，肌肤莹透，引人遐思。\n"NOR;
        else if (per > 21)  str =CYN"她生得巧笑嫣然，宛约可人。\n"NOR;
        else if (per > 20)  str =CYN"她生得如梨花带露，清新秀丽。\n"NOR;
        else if (per > 19)  str =CYN"她生得风姿楚楚，明丽动人。\n"NOR;
        else if (per > 18)  str =YEL"她生得肌肤微丰，雅淡温宛，清新可人。\n"NOR;
        else if (per > 17)  str =YEL"她生得虽不标致，倒也白净，有些动人之处。\n"NOR;
        else if (per > 16)  str =YEL"她生得身材瘦小，肌肤无光，两眼无神。\n"NOR;
        else if (per > 15)  str =YEL"她生得干黄枯瘦，脸色腊黄，毫无女人味。\n"NOR;
        else if (per > 14)  str =YEL"她生得满脸疙瘩，皮色粗黑，丑陋不堪。\n"NOR;
        else if (per > 13)  str =RED"她生得一嘴大暴牙，让人一看就没好感。\n"NOR;
        else if (per > 12)  str =RED"她生得眼小如豆，眉毛稀疏，手如猴爪，不成人样。\n"NOR;
        else if (per > 11)  str =RED"她生得八字眉，三角眼，鸡皮黄发，让人一见就想吐。\n"NOR;
        else if (per > 10)  str =RED"她生得歪鼻斜眼，脸色灰败，直如鬼怪一般。\n"NOR;
        else str =RED"她生得丑如无盐，状如夜叉，女人长成这样真是人生悲剧。\n"NOR;
    }
    return str;
}

string gettof(object ob)
{
    object weapon;
    string skill_type;
    int attack_points, hide_level;
    mapping prepare;
    if( objectp(weapon = ob->query_temp("weapon")) )
    {
        skill_type = weapon->query("skill_type");
    }
    else
    {
        prepare = ob->query_skill_prepare();
        if (!sizeof(prepare)) skill_type = "parry";
        else skill_type = keys(prepare)[0];
    }
    attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
    if( intp(hide_level = ob->query("hide_level")) && hide_level > 0)
        return tough_level(attack_points, hide_level);
    return tough_level(attack_points, 0);
}

string tough_level(int power, int hide_level)
{
    int lvl, rawlvl;
    string *tough_level_desc = ({
    BLU "不堪一击" NOR,BLU "毫不足虑" NOR,BLU "不足挂齿" NOR,BLU "初学乍练" NOR,BLU "勉勉强强" NOR,
    HIB "初窥门径" NOR,HIB "初出茅庐" NOR,HIB "略知一二" NOR,HIB "普普通通" NOR,HIB "平平淡淡" NOR,
    CYN "平淡无奇" NOR,CYN "粗通皮毛" NOR,CYN "半生不熟" NOR,CYN "马马虎虎" NOR,CYN "略有小成" NOR,
    HIC "已有小成" NOR,HIC "鹤立鸡群" NOR,HIC "驾轻就熟" NOR,HIC "青出于蓝" NOR,HIC "融会贯通" NOR,
    GRN "心领神会" NOR,GRN "炉火纯青" NOR,GRN "了然于胸" NOR,GRN "略有大成" NOR,GRN "已有大成" NOR,
    YEL "豁然贯通" NOR,YEL "出类拔萃" NOR,YEL "无可匹敌" NOR,YEL "技冠群雄" NOR,YEL "神乎其技" NOR,
    HIY "出神入化" NOR,HIY "非同凡响" NOR,HIY "傲视群雄" NOR,HIY "登峰造极" NOR,HIY "无与伦比" NOR,
    RED "所向披靡" NOR,RED "一代宗师" NOR,RED "精深奥妙" NOR,RED "神功盖世" NOR,RED "举世无双" NOR,
    WHT "惊世骇俗" NOR,WHT "撼天动地" NOR,WHT "震古铄今" NOR,WHT "超凡入圣" NOR,WHT "威镇寰宇" NOR,
    HIW "空前绝后" NOR,HIW "天人合一" NOR,MAG "深藏不露" NOR,HIM "深不可测" NOR,HIR "返璞归真" NOR
    });
    if(power<0) power=0;
    rawlvl = (int) pow( (float) 1.0 * power, 0.2);
    lvl = to_int(rawlvl);
    if(hide_level)
        lvl = hide_level;
    if( lvl >= sizeof(tough_level_desc) )
        lvl = sizeof(tough_level_desc)-1;
    return tough_level_desc[lvl];
}

string getdam(object obj)
{
    int level;
    string *heavy_level_desc= ({
        MAG"极轻"NOR,HIC"很轻"NOR,HIY"不重"NOR,HIG"不轻"NOR,HIB"很重"NOR,HIR"极重"NOR,
        });
    level = obj->query("jiali");
    if(obj->query_temp("apply/damage") > 0)
        level += obj->query_temp("apply/damage")/3;  // weapon 加力效果等于 unarmed / 3
    level /= 30;
    if( level >= sizeof(heavy_level_desc) )
        level = sizeof(heavy_level_desc)-1;
    return heavy_level_desc[((int)level)];
}
string inventory_look(object obj, int flag)
{
    string str;

    str = obj->short();
    if( obj->query("equipped") )
        str = HIC "  □" NOR + str;
    else if( !flag )
        str = "    " + str;
    else
        return 0;
    return str;
}


//******************************************************
//如果是用网页玩的执行这一部份的LOOK
int webmain(object me, string arg)
{
        object obj;
        int result;
        string str;

	if (me->query("position") != "zmuduser")
	{
write("<html>");
write("<head>");
write("<meta http-equiv=\\\"Content-Type\\\" content=\\\"text/html; charset=gb2312\\\">");
write("<title>status</title>");
write("<STYLE type=text/css>BODY {");
write("	COLOR: #000000; FONT-FAMILY: \\\"宋体\\\"; ");
write("FONT-SIZE: 11pt");
write("}");
write("TD {");
write("	FONT-FAMILY: \\\"宋体\\\"; FONT-SIZE: ");
write("9pt");
write("}");
write("A:link {");
write("	COLOR=\\\"#00ff00\\\"; TEXT-DECORATION: none");
write("}");
write("A:visited {");
write("	COLOR=\\\"#00ff00\\\"; TEXT-DECORATION: none");
write("}");
write("A:active {");
write("	COLOR=\\\"#00ff00\\\"; TEXT-DECORATION: none");
write("}");
write("A:hover {");
write("	COLOR=\\\"#006666\\\"; TEXT-DECORATION: none");
write("}");
write("</style>");
write("</head>");
		str = "parent.document.forms[\'commandForm\'].input.select(); parent.document.forms[\'commandForm\'].input.focus();";
        	printf(JSP + str + NSP);
        }

  	if( me->query_temp("blind") ) return notify_fail("你现在是个瞎子,看不见东西。\n");
        if( !arg ) result = weblook_room(me, environment(me));
        else if( (obj = present(arg, me)) || (obj = present(arg, environment(me)))) {
                if( obj->is_character() ) result = weblook_living(me, obj,arg);
                else result = weblook_item(me, obj);
        } else result = weblook_room_item(me, arg);

        return result;
}

int weblook_room(object me, object env)
{
    int i,j;
    object *inv1;
    object ob;
    int *count,cnn;
    object *inv;
    mapping exits;
    string str, *dirs;
    string bfile;//file_name,name;
    mapping buffo = ([]), buffobj = ([]);
    string short, long, exit, desc;

    if( !env ) {
        write("你的四周灰蒙蒙地一片，什么也没有。\n");
        return 1;
    }
    short = sprintf(WEBBLK "【" WEBNOR WEBRED " %s"  WEBNOR WEBBLK "】" + WEBNOR, env->query("short"));
    short += wizardp(me)? file_name(env): "";
    desc = replace_string(env->query("long"),"\n","");
    long = desc + "<br>　　" + WEBYEL +
        replace_string(implode(explode((env->query("outdoors")?"":"窗外：") + NATURE_D->outdoor_room_description(), "\n"), ""),"[0m","")  + WEBNOR;

    str = sprintf( "%s - %s\n    %s%s",
            env->query("short"),
            wizardp(me)? file_name(env): "",
            env->query("long"),
            env->query("outdoors")? replace_string(NATURE_D->outdoor_room_description(),"[0m","") + WEBNOR: "" );

    if( mapp(exits = env->query("exits")) ) {
        dirs = keys(exits);
        for(i=0; i<sizeof(dirs); i++)
            if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
                dirs[i] = 0;
        dirs -= ({ 0 });
        if( sizeof(dirs)==0 )
            str += "    这里没有任何明显的出路。\n";
        else if( sizeof(dirs)==1 )
            str += "    这里唯一的出口是 <a target=nothing href=\"../Command/go "  + dirs[0] + "\"" + WEBRED + dirs[0]  + "</a>" + WEBNOR + "。";
        else {
            cnn = 0;
            str += "    这里明显的出口是 ";
            for (i = 0; i < sizeof(dirs) - 2; i++)
                str += sprintf("<a target=nothing href=\"../Command/go %s\">%s</a>、", dirs[i], dirs[i]);
            str += sprintf("<a target=nothing href=\"../Command/go %s\">%s</a>和", dirs[sizeof(dirs) - 2], dirs[sizeof(dirs) - 2]);
            str += sprintf("<a target=nothing href=\"../Command/go %s\">%s</a>", dirs[sizeof(dirs) - 1], dirs[sizeof(dirs) - 1]);
            str += "。";
        }
    }
    str += "\n";

    ob = env;
    inv = all_inventory(ob);
    for(i=0; i<sizeof(inv); i++) {
        if( inv[i]==me ) continue;
        if( inv[i]->query("no_show")) continue;
        if( !me->visible(inv[i]) ) continue;
        bfile=base_name(inv[i]);
        if ( member_array(bfile,keys(buffo)) == -1 )
        {
            buffo[bfile]=1;
            buffobj[bfile]=inv[i];
            str += sprintf("<a target=nothing href=\"../Command/look %s\">%s</a><br>",
                    inv[i]->query("id"), inv[i]->short());
        }
        else 
        {
            buffo[bfile] ++;
            str += sprintf("<a target=nothing href=\"../Command/look %s %d\">%s</a><br>",
                    inv[i]->query("id"), buffo[bfile], inv[i]->short());
        }
    }

    realtime_map(me,env);
    printf(str);

    printf(JSP "parent.look_room(\"%s\", \"%s\", \"%s\")" NSP, 
            short, long, exit);
    return 1;
}

int weblook_item(object me, object obj)
{
    mixed *inv;

    write(obj->long());
    inv = all_inventory(obj);
    if( sizeof(inv) ) {
        inv = map_array(inv, "inventory_look", this_object() );
        message("vision", sprintf("里面有：\n  %s\n", implode(inv, "\n  ") ), me);
    }
    return 1;
}

int weblook_living(object me, object obj, string arg)
{
    string str, limb_status, pro;
    mixed *inv;
    mapping my_fam, fam;
    int age;
    string gender;

    if( me!=obj && !wizardp(me))
        message("vision", me->name() + "正盯著你看，不知道打些什么主意。\n", obj);

    str = obj->long();

    if (obj->query_temp("apply/gender"))
        gender = obj->query_temp("apply/gender")[0];
    else
        gender = obj->query("gender");

    pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(gender);

    if (obj->query_temp("apply/age"))
        age = obj->query_temp("apply/age")[0];
    else
        age = obj->query("age");
    if( (string)obj->query("race")=="人类"
            &&      intp(obj->query("age")) )
        str += sprintf("%s看起来约%s多岁。\n", pro, chinese_number(age / 10 * 10));

    if (obj==me) str += "你看来很象镜子中的你呀!\n";
    else if ( me->query("age") <= 14 ) 
        str += "你才十四岁就要看吗,你什么也不懂呀.\n";
    else if(userp(obj))
    {
        if (obj->query("age") > 14)
            str += getper(me, obj);
        else
            str += "这么个小家伙有什么可看的呢?\n";
    }
    // If we both has family, check if we have any relations.
    if( obj!=me
            &&      !obj->query_temp("apply/name")
            &&      mapp(fam = obj->query("family"))
            &&      mapp(my_fam = me->query("family")) 
            &&      fam["family_name"] == my_fam["family_name"] ) {

        if( fam["generation"]==my_fam["generation"] ) {
            if( (string)obj->query("gender") == "男性" ||
                    (string)obj->query("gender") == "无性")
                str += sprintf( pro + "是你的%s%s。\n",
                        my_fam["master_id"] == fam["master_id"] ? "": "同门",
                        my_fam["enter_time"] > fam["enter_time"] ? "师兄": "师弟");
            else
                str += sprintf( pro + "是你的%s%s。\n",
                        my_fam["master_id"] == fam["master_id"] ? "": "同门",
                        my_fam["enter_time"] > fam["enter_time"] ? "师姐": "师妹");
        } else if( fam["generation"] < my_fam["generation"] ) {
            if( my_fam["master_id"] == obj->query("id") )
                str += pro + "是你的师父。\n";
            else if( my_fam["generation"] - fam["generation"] > 1 )
                str += pro + "是你的同门长辈。\n";
            else if( fam["enter_time"] < my_fam["enter_time"] )
                str += pro + "是你的师伯。\n";
            else
                str += pro + "是你的师叔。\n";
        } else {
            if( fam["generation"] - my_fam["generation"] > 1 )
                str += pro + "是你的同门晚辈。\n";
            else if( fam["master_id"] == me->query("id") )
                str += pro + "是你的弟子。\n";
            else
                str += pro + "是你的师侄。\n";

        }
    }

    str +=sprintf("%s的武艺看上去", pro);
    str +=gettof(obj);
    str +="，";
    str +=sprintf("出手似乎");
    str +=getdam(obj);
    str += sprintf("。\n");
    if( obj->query("max_qi") )
        str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_qi") * 100 / (int)obj->query("max_qi")) + "\n";

    inv = all_inventory(obj);
    if( sizeof(inv) ) {
        inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
        inv -= ({ 0 });
        if( sizeof(inv) )
            str += sprintf( obj->is_corpse() ? "%s的遗物有：\n%s\n" : "%s身上带著：\n%s\n",
                    pro, implode(inv, "\n") );
    }

    message("vision", str, me);

    if( obj!=me 
            &&      living(obj)
            &&      random((int)obj->query("shen")) < 0 - (int)me->query("int") * 10 ) {
        write( obj->name() + "突然转过头来瞪你一眼。\n");
        COMBAT_D->auto_fight(obj, me, "berserk");
    }

    return 1;
}

int weblook_room_item(object me, string arg)
{
        object env;
        mapping item, exits;

        if( !objectp(env = environment(me)) )
                return notify_fail("这里只有灰蒙蒙地一片，什么也没有。\n");
        if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ) {
                if( stringp(item[arg]) )
                        write(item[arg]);
                else if( functionp(item[arg]) )
                        write((string)(*item[arg])(me));
                        
                return 1;
        }
        if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) {
                if( objectp(env = find_object(exits[arg])) )
                        weblook_room(me, env);
                else {
                        call_other(exits[arg], "???");
                        weblook_room(me, find_object(exits[arg]));
                }
                return 1;
        }
        return notify_fail("你要看什么？\n");
}

//######################################################
//如果是用ZMUD玩的执行这一部份的LOOK

int mudmain(object me, string arg)
{
    object obj;
    int result;

    if( me->query_temp("blind") ) return notify_fail("你现在是个瞎子,看不见东西。\n");
    if( !arg ) result = mudlook_room(me, environment(me));
    else if( (obj = present(arg, me)) || (obj = present(arg, environment(me)))) {
        if( obj->is_character() ) result = mudlook_living(me, obj);
        else result = mudlook_item(me, obj);
    } else result = mudlook_room_item(me, arg);

    return result;
}

int mudlook_room(object me, object env)
{
    int i,j;
    object *inv1;
    object ob;
    int *count,cnn;
    object *inv;
    mapping exits;
    string str, *dirs;

    if( !env ) {
        write("你的四周灰蒙蒙地一片，什么也没有。\n");
        tell_object(me, "由于你不知身在何处，你被送到了最后乐园...\n");
        me->move( VOID_OB );
        return 1;
    }
    str = sprintf( "%s - %s\n    %s%s",
            env->query("short"),
            wizardp(me)? file_name(env): "",
            env->query("long"),
            env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

    if( mapp(exits = env->query("exits")) ) {
        dirs = keys(exits);
        for(i=0; i<sizeof(dirs); i++)
            if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
                dirs[i] = 0;
        dirs -= ({ 0 });
        if( sizeof(dirs)==0 )
            str += "    这里没有任何明显的出路。\n";
        else if( sizeof(dirs)==1 )
            str += "    这里唯一的出口是 " + BOLD + dirs[0] + NOR + "。\n";
        else {
            cnn = 0;
            for (j = 0;j < sizeof(dirs); j++)
            {
                if (j != 0 && j % 6 ==0)
                    dirs[j]+= "\n";
            }
            str += sprintf("    这里明显的出口是 " + BOLD + "%s" + NOR + " 和 " + BOLD + "%s" + NOR + "。\n",
                    implode(dirs[0..sizeof(dirs)-2], "、"), dirs[sizeof(dirs)-1]);
        }
    }

    ob = env;
    inv = all_inventory(ob);
    for (i = 0; i < sizeof(inv); i++) 
    {
        if (!arrayp(inv1))
        {
            inv1=({inv[i]});
            count=({1});
        }
        else
        {
            for (j = 0; j < sizeof(inv1); j++)
                if  ( (base_name(inv[i])==base_name(inv1[j])) && (inv[i]->query("name") == inv1[j]->query("name")) && (inv[i]->query("disable_type") == inv1[j]->query("disable_type")) )
                    break;
            if (j == sizeof(inv1) || userp(inv[i]))
            {
                inv1+=({inv[i]});
                count+=({1});
            }
            else
                count[j]+=1;
        }                
    }
    for(i=0; i<sizeof(inv1); i++) 
    {
        if( inv1[i]==me ) continue;
        if( !userp(inv1[i]) && inv1[i]->query("no_show") ) continue;
        if( !me->visible(inv1[i]) ) continue;
        if(count[i]==1)
            str += "    "+inv1[i]->short()+"\n";
        else
            str +="    "+chinese_number(count[i]) +"" + inv1[i]->query("unit") +""+ inv1[i]->short()+"\n";
    }

    realtime_map(me,env);
    write(str);
    return 1;
}

int mudlook_item(object me, object obj)
{
    object *inv;
    object *inv1;
	string str;
    int rig;
	int i ,j ;
	int *count;
    write(obj->long());
    rig = obj->query("rigidity");
    if (rig > 0)	//已经坏了的就不管了。
        if (rig > 100)
            message("vision", obj->name() + "完好无损，宛如新的一般。\n", me);
        else if (rig > 80)
            message("vision", obj->name() + "已经轻微磨损，表面布满了细细的划痕。\n", me);
        else if (rig > 40)
            message("vision", obj->name() + "多次与其他兵器撞击，表面已是遍体鳞伤，但仍然可以凑合着用。\n", me);
        else if (rig > 10)
            message("vision", obj->name() + "已是严重受损，几道明显的裂纹已经危及了它的寿命。\n", me);
        else if (rig > 0)
            message("vision", obj->name() + "被几道深深的裂痕分割成几部份，几乎马上就要断了。\n", me);
       inv = all_inventory(obj);
       for (i = 0; i < sizeof(inv); i++) 
		{
		   if (!arrayp(inv1))
			{inv1=({inv[i]});
			 count=({1});}
		    else
		   {
			for (j = 0; j < sizeof(inv1); j++)
            if ((base_name(inv[i]) == base_name(inv1[j])) && (inv[i]->short() == inv1[j]->short()))
			break;
			if (j == sizeof(inv1))
			{
			inv1+=({inv[i]});
			count+=({1});
			}
			else
			count[j]+=1;
			}
		}
         for(i=0; i<sizeof(inv1); i++) {
         if(count[i]==1)
         str += ""+inv1[i]->short()+"\n";
         else
        str +=""+chinese_number(count[i]) +"" + inv1[i]->query("unit") +""+ inv1[i]->short()+"\n";
	}
    this_player()->start_more(str);
    return 1;
}


int mudlook_living(object me, object obj)
{
    string str, limb_status, pro;
    mixed *inv;
    mapping my_fam, fam;
    int age;
    string gender;

    if( me!=obj && !wizardp(me))
        message("vision", me->name() + "正盯著你看，不知道打些什么主意。\n", obj);

    str = obj->long();

    if (obj->query_temp("apply/gender"))
        gender = obj->query_temp("apply/gender")[0];
    else
        gender = obj->query("gender");

    pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(gender);

    if (obj->query_temp("apply/age"))
        age = obj->query_temp("apply/age")[0];
    else
        age = obj->query("age");
    if( (string)obj->query("race")=="人类"
            &&      intp(obj->query("age")) )
        str += sprintf("%s看起来约%s多岁。\n", pro, chinese_number(age / 10 * 10));

    if (obj==me) str += "你看来很象镜子中的你呀!\n";
    else if ( me->query("age") <= 14 ) 
        str += "你才十四岁就要看吗,你什么也不懂呀.\n";
    else if(userp(obj))
    {
        if (obj->query("age") > 14)
            str += getper(me, obj);
        else
            str += "这么个小家伙有什么可看的呢?\n";
    }
    // If we both has family, check if we have any relations.
    if( obj!=me
            &&      !obj->query_temp("apply/name")
            &&      mapp(fam = obj->query("family"))
            &&      mapp(my_fam = me->query("family")) 
            &&      fam["family_name"] == my_fam["family_name"] ) {

        if( fam["generation"]==my_fam["generation"] ) {
            if( (string)obj->query("gender") == "男性" ||
                    (string)obj->query("gender") == "无性")
                str += sprintf( pro + "是你的%s%s。\n",
                        my_fam["master_id"] == fam["master_id"] ? "": "同门",
                        my_fam["enter_time"] > fam["enter_time"] ? "师兄": "师弟");
            else
                str += sprintf( pro + "是你的%s%s。\n",
                        my_fam["master_id"] == fam["master_id"] ? "": "同门",
                        my_fam["enter_time"] > fam["enter_time"] ? "师姐": "师妹");
        } else if( fam["generation"] < my_fam["generation"] ) {
            if( my_fam["master_id"] == obj->query("id") )
                str += pro + "是你的师父。\n";
            else if( my_fam["generation"] - fam["generation"] > 1 )
                str += pro + "是你的同门长辈。\n";
            else if( fam["enter_time"] < my_fam["enter_time"] )
                str += pro + "是你的师伯。\n";
            else
                str += pro + "是你的师叔。\n";
        } else {
            if( fam["generation"] - my_fam["generation"] > 1 )
                str += pro + "是你的同门晚辈。\n";
            else if( fam["master_id"] == me->query("id") )
                str += pro + "是你的弟子。\n";
            else
                str += pro + "是你的师侄。\n";

        }
    }

    str +=sprintf("%s的武艺看上去", pro);
    str +=gettof(obj);
    str +="，";
    str +=sprintf("出手似乎");
    str +=getdam(obj);
    str += sprintf("。\n");
    if( obj->query("max_qi") )
        str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_qi") * 100 / (int)obj->query("max_qi")) + "\n";

    inv = all_inventory(obj);
    if( sizeof(inv) ) {
        inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
        inv -= ({ 0 });
        if( sizeof(inv) )
            str += sprintf( obj->is_corpse() ? "%s的遗物有：\n%s\n" : "%s身上带著：\n%s\n",
                    pro, implode(inv, "\n") );
    }

    message("vision", str, me);

    if( obj!=me 
            &&      living(obj)
            &&      random((int)obj->query("shen")) < 0 - (int)me->query("int") * 10 ) {
        write( obj->name() + "突然转过头来瞪你一眼。\n");
        COMBAT_D->auto_fight(obj, me, "berserk");
    }

    return 1;
}

int mudlook_room_item(object me, string arg)
{
        object env;
        mapping item, exits;

        if( !objectp(env = environment(me)) )
                return notify_fail("这里只有灰蒙蒙地一片，什么也没有。\n");
        if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ) {
                if( stringp(item[arg]) )
                        write(item[arg]);
                else if( functionp(item[arg]) )
                        write((string)(*item[arg])(me));
                        
                return 1;
        }
        if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) {
                if( objectp(env = find_object(exits[arg])) )
                        mudlook_room(me, env);
                else {
                        call_other(exits[arg], "???");
                        mudlook_room(me, find_object(exits[arg]));
                }
                return 1;
        }
        return notify_fail("你要看什么？\n");
}

int help (object me)
{
        write(@HELP
指令格式: look [<物品>|<生物>|<方向>]
 
这个指令让你查看你所在的环境、某件物品、生物、或是方向。
 
HELP
);
        return 1;
}
