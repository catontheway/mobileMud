#include <ansi.h>
#include <armor.h>
inherit EQUIP; 
inherit F_SAVE;
 
string *names=({ 
        HIY"静心莲花"NOR,"jingxin",     HIW"如意莲花"NOR,"ruyi",
        HIY"金身莲花"NOR,"jinshen",     WHT"孤禅莲花"NOR,"guchan",
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
          "kee"         :  HIG"增加气血"NOR,
          "eff_kee"     :  HIR"治疗气血"NOR,
          "sen"         :  HIM"增加精神"NOR,
          "eff_sen"     :  HIW"治疗精神"NOR,
          "force"       :  HIY"内力补充"NOR,
          "mana"        :  HIB"法力补充"NOR,
]);

string anong = "";


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
add_action("do_wear","wear");
add_action("do_remove", "remove");
add_action("do_dest", "dest");
}

int do_wear (string arg)
{
object me = this_player();
object jia = this_object();
string name = jia->query("name");
string msg;

if ( !present(jia,me) )                         //不在身上 
        return 0;
if ( arg!="all" && !id(arg) )                   //不是穿此
        return 0;
if ( query("equipped") || query("use")==1 )     //已穿此
        return 0;
if ( me->query_temp("armor/"+jia->query("armor_type")) )        //同类型已穿
        return 0;

msg = "$N背后现出一朵$n护住了$P的妙严肉身。\n";
jia->set("wear_msg",msg);
me->apply_condition("lianhua",1);
return 0;
}

int do_remove (string arg)
{
object me = this_player();
object jia = this_object();
string msg;

if ( !present(jia,me) )
        return 0;

if ( arg!= "all" && !id(arg) )
        return 0;

if ( !query("equipped") || query("use")==0 )
        return 0;

msg = "$N低诵我佛，$n随风碎成片片花瓣。\n"NOR;
jia->set("unequip_msg",msg);
return 0;
}

void check_long()
{
string t_str;
int k;
mixed temp;     
temp = query("莲花/addType");
if ( stringp(temp) )
        anong = "它能"+t_msg[temp];
else if ( arrayp(temp) )
        {
        k = sizeof(temp);
        t_str = "它能";
        while(k--)
                {
                t_str+= t_msg[temp[k]]+" ";
                if ( k )
                        t_str+="、";
                }
        anong = t_str;          
        }
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
        "addType"       : ({"kee","eff_kee","sen","eff_sen","force","mana"})[random(6)],
]));    
set("long",HIC"一"+unit+"莲花，可以"+long+"\n"NOR);
set_weight(we);
set("armor_prop/base", p);
p+= random(p/2);
set("armor_prop/armor", p);
check_long();
i = query("莲花/lvl")*3;
i = i/2+random(i);
if ( random(5)==1 )
        set("armor_prop/dodge",1+random(i)-random(i/2));
if ( random(5)==1 )
        set("armor_prop/parry",1+random(i)-random(i/2));
if ( random(5)==1 )
        set("armor_prop/force",1+random(i)-random(i/2));
if ( random(5)==1 )
        set("armor_prop/spells",1+random(i)-random(i/2));
if ( random(5)==1 )
        set("armor_prop/literate",1+random(i)-random(i/2));
}       

void create()
{
randomName();
set("material", "steel");
set("value",0);
}

string short()
{
int i = query("莲花/lvl");
string str;
if ( i<=5 )  str = YEL"平凡"NOR;
else if ( i<=10 )  str = CYN"俗世"NOR;
else if ( i<=20 )  str = HIW"长老"NOR;
else if ( i<=50 )  str = HIY"脱俗"NOR;
else str = HIW"圣佛"NOR;
return str+"的"+::short();
}

int is_lianhua()
{
return 1;
}

string long()
{
string str = ::long();  
check_long();
if ( stringp(anong) )
      str+= HIG"另外"+anong+"\n";
str+=  HIG"如果你想注销该莲花，可以用 "HIR"dest [ id ] "HIG"命令来清除。\n"NOR;
return str;
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

