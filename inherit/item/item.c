// item.c
#include <ansi.h>
#include <dbase.h>
#include <move.h>
#include <name.h>

inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_MOVE;
inherit F_NAME;

nosave string s_name;

nosave string s_id;

string to_ch_desc(int status)
{
        if( status == 0 ) return HIW "普通" NOR;
        else if( status == 1 ) return HIW "普通" NOR;
        else if( status == 2 ) return HIB "优良" NOR;
        else if( status == 3 ) return HIC "珍稀" NOR;
        else if( status == 4 ) return HIM "史诗" NOR;
        else if( status == 5 ) return HIY "传说" NOR;
        else if( status == 6 ) return HBRED+HIW "神器" NOR;
        else return HBRED+HIY "仙器" NOR;
}

void setup()
{
        seteuid(getuid());
}
int query_autoload()
{
	//不需要存档物品标号
	/*if ( this_object()->query("owner_id") )
		return 0;
	else*/
		return 1;
}
void set_name(string name, string *id)
{
        ::set_name(name, id);
        s_name = query("name");
        s_id = query("id");
}

string short()
{
        string colorname;
        string modname, str;
        string status = "";

        if( query("quality_level") )
                status += " "+to_ch_desc(query("quality_level"));
    
/*
        if( stringp(modname = query("mod_name")) )
                status += " " + modname;
*/
                    
        if( !undefinedp(query("consistence")) && query("consistence") < 1 ) 
        //if( query("endurance") < 1 ) 
                status += HIW" 损"NOR WHT"坏"NOR;
                
        if( !stringp(colorname = query("colorname")) )
                str = s_name + "(" + s_id + ")";
        else
                str = colorname + "(" + s_id + ")";

        if( status != "" )
                str += status;

        return str;
}



string type()
{
        if( this_object()->is_weapon() )
                return "武器";
        if( this_object()->is_unarmed_weapon() )
                return "空手武器";
        else if( this_object()->is_armor() )
                return "防具";
        else if( this_object()->is_food() )
                return "食物";
        else if( this_object()->is_liquid() )
                return "饮具";
        else if( this_object()->is_container() )
                return "容器";
        else if( this_object()->is_book() )
                return "书物";
        else if( this_object()->is_money() )
                return "货币";
        else if( this_object()->is_charm() )
                return "护身符";
        else if( this_object()->is_rune() )
                return "符文";
        else if( this_object()->is_tessera() )
                return "镶嵌物";
        else if( this_object()->is_task() )
                return "任务物品";
        else    return "杂物";
}

/*mixed query_autoload()
{
        string param;
        mapping data;

        if( !query("auto_load") )
                return 0;

        if( !query("set_data") )
                return 1;

        data = copy(this_object()->query_entire_dbase());
        if( !undefinedp(data["equipped"]) )
                map_delete(data, "equipped");

        param = save_variable(data);
        param = replace_string(param, "\"", "~");
        return param;
}*/
