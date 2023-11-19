#include <ansi.h>
#include <armor.h>
inherit EQUIP; 
inherit F_UNIQUE;

string *names=({ 
        HIG"一品青莲"NOR,"qing lian", HIW"须弥白莲"NOR,"bai lian", HIY"三寸金莲"NOR,"jin lian",
        HIM"菩提粉莲"NOR,"fen lian",  HIR"比丘赤莲"NOR,"chi lian", 
});

void randomName()
{
        string name,id,*ids;
        int i = random(sizeof(names)/2)*2;
        name = names[i];
        id = names[i+1];
        ids = ({id,id+" lianhua","lianhua","hua"});
        set_name(name,ids);
}

nosave int check_env(object who)
{
        object env;
        if( !who || who!=environment() )
                return 0;
        if( who->query("combat_exp")>=2500000 )
        {
                tell_object(who,"你的武学过高，不能使用新手莲花\n");
                return 0;
        }
        if( who->query("daoxing")>=2000000 )
        {
                tell_object(who,"你的道行过高，不能使用新手莲花\n");
                return 0;
        }
        if( who->query("莲花") )
        {
                tell_object(who,"你已经开始使用八部莲花了，不能使用新手莲花了。\n");
                return 0;
        }
        if( who->query("zhuanshi") )
        { 
                tell_object(who,"你不是新手了吧。\n");
                return 0;
        }       
        return 1;
}

void check_func(string temp)
{
        int i;  
        object me = environment();
        string msg = "";
        if( !me || !living(me) )
                return;
        if( !query("equipped") )
                return;
        i = query("新手/lvl");
        i*= 300;
        i = i/2+random(i/2);  
//任务地点对莲花恢复有影响
        if( environment(me) && environment(me)->query("lianhua") )
        {   
                int p =  environment(me)->query("lianhua");
                if( p>=100 ) p = 100;  //起作用的%
                i = i*p/100;
        }
        switch(temp)
        {
                case "qi" : 
                        if( me->query("qi")<me->query("eff_qi") )
                        {
                        msg+= "$n在$N身后隐隐约约摆动，$P立刻觉得气血充沛起来！\n";
                        me->add("qi",i);
                        if( me->query("qi")>me->query("eff_qi") )   
                                me->set("qi",(int)me->query("eff_qi") );
                        }
                        break;
                case "eff_qi" :
                        if( me->query("eff_qi")<me->query("max_qi") )
                        {
                        msg+= "$n在$N身后隐隐约约摆动，$P立刻觉得气血充沛起来！\n";
                        me->add("eff_qi",i);
                        if( me->query("eff_qi")>me->query("max_qi") )   
                                me->set("eff_qi",(int)me->query("max_qi") );
                        }
                        break;
                case "jing"  : 
                        if( me->query("jing")<me->query("eff_jing") )
                        {
                        msg+= "$n在$N身后隐隐约约摆动，$P精神一振！\n"NOR;
                        me->add("jing",i);
                        if( me->query("jing")>me->query("eff_jing") )   
                                me->set("jing",(int)me->query("eff_jing") );
                        }       
                        break;
                case "eff_jing" :
                        if( me->query("eff_jing")<me->query("max_jing") )
                        {
                        msg+= "$n在$N身后隐隐约约摆动，$P精神一振！\n";   
                        me->add("eff_jing",i);
                        if( me->query("eff_jing")>me->query("max_jing") )   
                                me->set("eff_jing",(int)me->query("max_jing") );
                        }
                        break;
                case "neili" :
                        if( me->query("neili")/2<me->query("max_neili") )
                        {
                        msg+= "$n在$N身后隐隐约约摆动，$P顿时觉得内力充沛起来！\n";
                        me->add("neili",i);
                        if( me->query("neili")/2>me->query("max_neili") )
                                me->set("neili",(int)me->query("max_neili")*2 );
                        }
                        break;                        
                case "jingli" :
                        if( me->query("jingli")/2<me->query("max_jingli") )
                        {
                        msg+= "$n在$N身后隐隐约约摆动，$P顿时觉得法力充沛起来！\n";
                        me->add("jingli",i);
                        if( (int)me->query("jingli")/2>(int)me->query("max_jingli") )
                                me->set("jingli",(int)me->query("max_jingli")*2 );
                        }
                        break;
                }
        message_vision(msg,me,this_object());
        return;
}
        
void lianhua_func()
{
        int k;
        mixed tt;        
        string temp;
        object me = environment();
        if( !me || !living(me) )
                return;
        if( !query("equipped") )
                return;
        if( !check_env(me) )
                return;
if( environment(me)->query("no_lianhua") )  return; 
        tt = query("新手/addType");
        if( !tt )
                return;
        if( stringp(tt) )
                return check_func(tt);
        else if( arrayp(tt) )
        {               
                for(k=0;k<sizeof(tt);k++)
                {
                        temp = tt[k];
                        if( !temp ) continue;
                        check_func(temp);
                }
        }
        return; 
}

void create()
{
        randomName();
        set_weight(2000);       
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "steel");
                set("no_put",1);
                set("no_give",1);
                set("no_get",1);
                set("no_steal",1);
                set("value",0);
                set("unequip_msg","$N低诵我佛，$n随风碎成片片花瓣。\n"NOR);
                set("wear_msg","$N背后现出一朵$n护住了$P的妙严肉身。\n");
                set("unit","朵");
                set("新手",([
                        "lvl"           : 1+random(5),
                        "addType"       : ({"qi","eff_qi","jing","eff_jing","neili","jingli"}),
                ]));    
                set("long",HIC"一朵新手莲花，可以恢复所有的HP\n"NOR);
                set("armor_prop/armor",28);
        }
        setup();        
        set("armor_type", "newbie_lianhua");    
}

int is_lianhua() { return 1; }

int wear()
{
        object who = environment();
        if( !check_env(who) )
        {
                tell_object(who,"你不能使用新手莲花。\n");
                return 0;
        }
        else    return ::wear();
}
