#include <ansi.h>
#include <armor.h>
inherit EQUIP; 
inherit F_SAVE;
 
string *names=({ 
        HIY"静心莲花"NOR,"jingxin",
        HIW"如意莲花"NOR,"ruyi",
        HIY"金身莲花"NOR,"jinjing",
        WHT"孤禅莲花"NOR,"guchan",
        RED"涅磐莲花"NOR,"niepan",
});

mapping a_types = ([
        "heads"          : ({"顶","装备在头上遮风挡雨。",8,1000}),
        "necks"          : ({"串","戴在脖子上驱恶辟邪。",3,500}),
        "cloths"         : ({"朵","穿在身上挡风御寒。",20,3000}),
        "armors"         : ({"抹","穿在身上抵挡刀箭。",40,5000}),
        "surcoats"       : ({"朵","披在身后遮风挡雨。",25,2000}),
        "waists"         : ({"串","佩在腰间驱恶辟邪。",5,1000}),
        "wristss"        : ({"串","戴在指间驱恶辟邪。",3,500}),
        "shields"        : ({"朵","拿中手中抵挡刀箭。",20,2500}),
        "fingers"        : ({"朵","捏在指尖驱恶辟邪。",3,500}),
        "bootss"         : ({"对","踩在脚下驱恶辟邪。",15,800}),  

]);     

mapping t_msg = ([
          "qi"         :  HIG"增加气血"NOR,
          "eff_qi"     :  HIR"治疗气血"NOR,
          "jing"         :  HIM"增加精神"NOR,
          "eff_jing"     :  HIW"治疗精神"NOR,
          "neili"       :  HIY"内力补充"NOR,
          "jingli"        :  HIB"精力补充"NOR,
]);



void randomName()
{
string name,id,*ids;
int i = random(sizeof(names)/2)*2;
name = names[i];
id = names[i+1];
ids = ({id,id+" lianhua","lianhua","hua"});
this_object()->set_name(name,ids);
setup();
}

void leave()
{
remove_call_out("leave");
if ( environment() && environment()->query("id")==query("owner_id") )   
        return;
write("\n"+this_object()->name()+HIY"化作一道金光冲天而去。\n\n"NOR);
destruct(this_object());
}

void _leave()
{
call_out("leave",2+random(5));
}               

void check_owner()
{
object ob = this_object();
object env = environment();
if ( !userp(env) || (stringp(query("owner_id"))&&env->query("id")!=query("owner_id")) )
        _leave();
return;
}

string query_save_file() 
{
string str;
if ( !stringp(str=this_object()->query("save_file")) )
        return 0;
return LIANHUA_DIR+str;
}

int save()
{
object env;
string str;
if ( this_object()->query("equipped") )
        {
        message("channel:sys",sprintf(WHT"【"NOR HIG"莲花"NOR WHT"】莲花物件%O因处于装备状态，无法存贮。\n"NOR,this_object()),users());
        tell_object(env,"你得将莲花脱下方可保存。\n");  
        return 0;       
        }
if ( !stringp(str=this_object()->query("save_file")) )    {
        message("channel:sys",sprintf(WHT"【"NOR HIG"莲花"NOR WHT"】莲花物件%O因无save_file data，无法存贮。\n"NOR,this_object()),users());
        return 0;
        }
return ::save();
}
        
int restore() 
{
object env;
string str;
env = environment();
if ( this_object()->query("equipped") )
        {
        tell_object(env,"你得将莲花脱下方可读取。\n");  
        return 0;       
        }
if ( !stringp(str=this_object()->query("save_file")) )
        return 0;       
return ::restore();     
}

void init()
{
check_owner();
//add_action("do_dest", "dest");
}

void check_func(string temp)
{
int i;  
object me = environment();
string msg = "";
if ( !me || !living(me) )
        return;
if ( !query("equipped") )
        return;
i = query("莲花/lvl");
i*= 500;
i = i/2+random(i/2);  
//任务地点对莲花恢复有影响
if( environment(me) && environment(me)->query("lianhua") )
{   
          int p =  environment(me)->query("lianhua");
          if( p>=100 ) p = 50;  //起作用的%
          i = i*p/50;
}
switch(temp)
        {
        case "qi" : 
                if ( me->query("qi")<me->query("eff_qi") )
                        {
                        msg+= "$n在$N身后隐隐约约摆动，$P立刻觉得气血充沛起来！\n";
                        me->add("qi",i);
                        if ( me->query("qi")>me->query("eff_qi") )   
                                me->set("qi",(int)me->query("eff_qi") );
                        }
                break;
        case "eff_qi" :
                if ( me->query("eff_qi")<me->query("max_qi") )
                        {
                        msg+= "$n在$N身后隐隐约约摆动，$P立刻觉得气血充沛起来！\n";
                        me->add("eff_qi",i);
                        if ( me->query("eff_qi")>me->query("max_qi") )   
                                me->set("eff_qi",(int)me->query("max_qi") );
                        }
                break;
        case "jing"  : 
                if ( me->query("jing")<me->query("eff_jing") )
                        {
                        msg+= "$n在$N身后隐隐约约摆动，$P精神一振！\n"NOR;
                        me->add("jing",i);
                        if ( me->query("jing")>me->query("eff_jing") )   
                                me->set("jing",(int)me->query("eff_jing") );
                        }       
                break;
        case "eff_jing" :
                if ( me->query("eff_jing")<me->query("max_jing") )
                        {
                        msg+= "$n在$N身后隐隐约约摆动，$P精神一振！\n";   
                        me->add("eff_jing",i);
                        if ( me->query("eff_jing")>me->query("max_jing") )   
                                me->set("eff_jing",(int)me->query("max_jing") );
                        }
                break;
        case "neili" :
                if ( me->query("neili")/2<me->query("max_neili") )
                        {
                        msg+= "$n在$N身后隐隐约约摆动，$P顿时觉得内力充沛起来！\n";
                        me->add("neili",i);
                        if ( me->query("neili")/2>me->query("max_neili") )
                                me->set("neili",(int)me->query("max_neili")*2 );
                        }
                break;                        
        case "jingli" :
                if ( me->query("jingli")/2<me->query("max_jingli") )
                        {
                        msg+= "$n在$N身后隐隐约约摆动，$P顿时觉得法力充沛起来！\n";
                        me->add("jingli",i);
                        if ( (int)me->query("jingli")/2>(int)me->query("max_jingli") )
                                me->set("jingli",(int)me->query("max_jingli")*2 );
                        }
                break;
        }
if( !me->query("env/no_msg") )  message_vision(msg,me,this_object());
else {
     msg = replace_string(msg,"$n",this_object()->query("name"));
     msg = replace_string(msg,"$N","你");
     msg = replace_string(msg,"$P","你");
     tell_object(me,msg);
     }
return;
}
        
void lianhua_func()
{
int k;
mixed tt;        
string temp;
object me = environment();
if ( !me || !living(me) )
        return;
if ( !query("equipped") )
        return;
if( environment(me)->query("no_lianhua") )  return;
tt = query("莲花/addType");
if ( !tt )
        return;
if ( stringp(tt) )
        return check_func(tt);
else if ( arrayp(tt) )
        {               
        for(k=0;k<sizeof(tt);k++)
                {
                temp = tt[k];
                if ( !temp ) continue;
                check_func(temp);
                }
        }
return; 
}

void setup() 
{
string *a_t,type,long,unit;
mixed temp;
int p,we,i,k;     

//      "boots"         ：({"对","踩在脚下驱恶辟邪。",30,800}),  
a_t = keys(a_types);
type = a_t[random(sizeof(a_t))];
unit = a_types[type][0];
long = a_types[type][1];
p = a_types[type][2];
we = a_types[type][3];
set("armor_type", type);
set("unit",unit);
set("莲花",([
        "lvl"           : 1+random(5),
        "addType"       : ({"qi","eff_qi","jing","eff_jing","neili","jingli"})[random(6)],
]));    
set("long",HIC"一"+unit+"莲花，可以"+long+"\n"NOR);
set_weight(we);
set("armor_prop/base", p);
p+= random(p/2);
set("armor_prop/armor", p);
i = query("莲花/lvl")*3;
i = i/2+random(i);
if ( random(5)==1 )
        set("armor_prop/dodge",1+random(i)-random(i/2));
if ( random(5)==1 )
        set("armor_prop/parry",1+random(i)-random(i/2));
if ( random(5)==1 )
        set("armor_prop/neili",1+random(i)-random(i/2));
if ( random(5)==1 )
        set("armor_prop/spells",1+random(i)-random(i/2));
if ( random(5)==1 )
        set("armor_prop/literate",1+random(i)-random(i/2));
}       

void create()
{
randomName();
set("material", "steel");
set("no_put",1);
set("value",0);
set("unequip_msg","$N低诵我佛，$n随风碎成片片花瓣。\n"NOR);
set("wear_msg","$N背后现出一朵$n护住了$P的妙严肉身。\n");
}

string short()
{
int i = query("莲花/lvl");
string str,*temp,str2;
if ( i<=5 )  str = YEL"平凡"NOR;
else if ( i<=10 )  str = CYN"俗世"NOR;
else if ( i<=20 )  str = HIW"长老"NOR;
else if ( i<=50 )  str = HIY"脱俗"NOR;
else str = HIW"圣佛"NOR;
str = str+"的"+::short();
temp = ({
        "axe","blade","dagger","dodge","neili","fork","hammer",
        "literate","mace","magic","parry","rake","spear",
        "spells","staff","stick","sword","stealing","throwing",
        "unarmed","whip",
});
str2 = "";
for(i=0;i<sizeof(temp);i++)
        {
        if ( query("armor_prop/ad_"+temp[i])!=0 )
                str2+= "("HIY+to_chinese(temp[i])+NOR+HIR+(query("armor_prop/ad_"+temp[i])>0?"+":"")+query("armor_prop/ad_"+temp[i])+NOR")"; 
        }
str+= str2;
return str;
}

int is_lianhua()
{
return 1;
}

string check_data()
{
object env;
string *da,tmp,str,need;
int i,k;
mapping data;
mixed temp;     
env = environment();
if ( !env || !userp(env) )
        return "          隐藏";  
str = "";       
temp = query("莲花/addType");
if ( stringp(temp) )
        str+= "          "+t_msg[temp]+"\n";
else if ( arrayp(temp) )
        {
        for(i=0;i<sizeof(temp);i++)
                str+= "          "+t_msg[temp[i]]+"\n";
        }
data = query("armor_prop");
if ( data && mapp(data) )
        {
        da = keys(data);
        for(i=0;i<sizeof(da);i++)
                {
                if ( sscanf(da[i],"ad_%s",tmp) )
                        {
                        if ( file_size(SKILL_D(tmp)+".c")>0 )
                                str+= "          "+to_chinese(tmp)+(data["ad_"+tmp]>0?"+":"")+data["ad_"+tmp]+"\n";
                        }
                else    continue;
                }                               
        }
return str;             
}

string long()
{
        int i;
        mixed tmp;
        string msg,type,temp;  
        mapping ARR = ([
                "heads"          : "头盔",
                "necks"          : "护颈",
                "cloths"         : "战衣",
                "armors"         : "护甲",
                "surcoats"       : "披风",
                "waists"         : "护腰",
                "wristss"        : "护腕",
                "shields"        : "盾牌",
                "fingers"        : "指套",
                "bootss"         : "鞋类",
        ]);
        mapping his = query_entire_dbase();

        msg = his["long"]?his["long"]:"";
        msg+= "莲花为佛门法宝，无法注销，可以用 "HIR"莲花转换魄石"NOR"进行类型转换。\n";
        msg+= sprintf("防具等级：%d\n",his["莲花"]["lvl"]);
        msg+= sprintf("防具所属: %s\n",query("owner_id")?query("owner_id"):"--");
        msg+= sprintf("防具防御: %d\n",his["armor_prop"]["armor"]);
        
        type = query("armor_type");
        if( !type )
        {
                msg+= sprintf("附加属性: \n%s",check_data());
                return msg;
        }
        if( strsrch(type,"+")==-1 )
        {
                if( undefinedp(ARR[type]) )
                {
                        msg+= sprintf("附加属性: \n%s",check_data());            
                        return msg;
                }
                 msg+= sprintf("防具类型: %s\n",ARR[type]);
                 msg+= sprintf("附加属性: \n%s",check_data());
                 return msg;
        }                               
        tmp = explode(type,"+");
        if( !tmp || !arrayp(tmp) )
                return msg;
        temp = " ";
        for(i=0;i<sizeof(tmp);i++)
        {
                if( !tmp[i] || !stringp(tmp[i]) || strlen(tmp[i])<3 )
                        continue;
                if( undefinedp(ARR[tmp[i]]) )
                        continue;
                temp+= ARR[tmp[i]]+" ";
        }                                               
        msg+= sprintf("防具类型: %s\n",temp);
        msg+= sprintf("附加属性: \n%s",check_data());
        return msg;
}

int do_dest(string arg)
{
string str,temp;
object own = this_player();

if ( !arg || !id(arg) )
        return 0;
temp = query("armor_type");
if ( !temp || !stringp(temp) )
        error(sprintf("%O 错误：无盔甲类型！\n",this_object()));
                
if ( stringp(str=this_object()->query("save_file")) )
        {
        if ( stringp(read_file(LIANHUA_DIR+str+".o")) )
                {
                write("此莲花存在存档文件。\n");        
                if ( ("/cmds/wiz/rm.c")->main(this_object(),(LIANHUA_DIR+str+".o")) && own )
                        {
                        tell_object(own,"你的莲花存档文件删除成功。\n");      
                        own->delete("莲花/"+temp);
                        if ( sscanf(temp,"%s+%s",str,temp)==2 )
                                {
                                own->delete("莲花/"+str);       
                                own->delete("莲花/"+temp);
                                }
                        }
                else    write("莲花存档文件删除失败。\n");              
                }
        else    write("此莲花不存在存档文件。\n");
        return 1;
        }          
else    return 0;        
}
