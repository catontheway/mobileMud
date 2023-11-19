//生死相搏
//made by mudy

inherit NPC
#include <ansi.h>


void create()
{
      set_name("搏击者",({"boji zhe","zhe"}));
     setup();
}

void init()
{
object me;
mapping armor;
object weapon,ar;
mapping hp_status, skill_status, map_status, prepare_status;
string *sname, *mname, *pname;
int i, temp;
object zhe;
zhe=this_object();
me=this_player();
if(zhe->is_fighting()) 
      return;
        if ( mapp(skill_status = zhe->query_skills()) ) {
                sname  = keys(skill_status);
                temp = sizeof(skill_status);
                for(i=0; i<temp; i++) {
                        zhe->delete_skill(sname[i]);
                }
        }
        if ( mapp(skill_status = me->query_skills()) ) {
                skill_status = me->query_skills();
                sname  = keys(skill_status);
                for(i=0; i<sizeof(skill_status); i++) {
                        zhe->set_skill(sname[i], skill_status[sname[i]]);
                }
        }


        if ( mapp(map_status = zhe->query_skill_map()) ) {
                mname  = keys(map_status);
                temp = sizeof(map_status);
                for(i=0; i<temp; i++) {
                        zhe->map_skill(mname[i]);
                }
        }
        if ( mapp(map_status = me->query_skill_map()) ) {
                mname  = keys(map_status);
                for(i=0; i<sizeof(map_status); i++) {
                        zhe->map_skill(mname[i], map_status[mname[i]]);
                }
        }


        if ( mapp(prepare_status = zhe->query_skill_prepare()) ) {
                pname  = keys(prepare_status);
                temp = sizeof(prepare_status);
                for(i=0; i<temp; i++) {
                        zhe->prepare_skill(pname[i]);
                }
        }
        if ( mapp(prepare_status = me->query_skill_prepare()) ) {
                pname  = keys(prepare_status);
                for(i=0; i<sizeof(prepare_status); i++) {
                        zhe->prepare_skill(pname[i], prepare_status[pname[i]]);
                }
        }


        hp_status = me->query_entire_dbase();
                zhe->set("str", hp_status["str"]);
                zhe->set("int", hp_status["int"]);
                zhe->set("con", hp_status["con"]);
                zhe->set("con", hp_status["dex"]);
                zhe->set("max_qi",    hp_status["max_qi"]*10);
                zhe->set("eff_qi",    hp_status["eff_qi"]*10);
                zhe->set("qi",        hp_status["qi"]*10);
                zhe->set("max_jing",  hp_status["max_jing"]*10);
                zhe->set("eff_jing",  hp_status["eff_jing"]*10);
                zhe->set("jing",      hp_status["jing"]*10);
                zhe->set("max_neili", hp_status["max_neili"]*10);
                zhe->set("neili",     hp_status["neili"]*10);
                zhe->set("jiali",     hp_status["jiali"]);
                zhe->set("combat_exp",hp_status["combat_exp"]*(me->query_temp("xiangbo_level")+0.5));
if(query_temp("weapon"))
{
destruct(zhe->query_temp("weapon"));
zhe->delete_temp("weapon");
}
if(zhe->query_temp("second_weapon"))
{
destruct(zhe->query_temp("secondary_weapon"));
zhe->delete_temp("secondary_weapon");
}
if(armor=zhe->query_temp("armor"))
{
 pname=keys(armor);
 for(i=sizeof(armor)-1;i>=0;i--)
{
   destruct(armor[pname[i]]);
}
zhe->delete_temp("armor");
}
if(me->query_temp("weapon"))
{
  weapon=new(base_name(me->query_temp("weapon")));
 weapon->set("weapon_prop/damage", weapon->query("weapon_prop/damage")/3);
weapon->set("owner",query("id"));
 weapon->set("value",0);
 weapon->set("no_get",1);
 weapon->set("no_give",1);
 weapon->set("no_drop",1);
 weapon->set("no_store",1);
weapon->move(zhe);

command("wield all");
}

if(me->query_temp("secondary_weapon"))
{
  weapon=new(base_name(me->query_temp("secondary_weapon")));
 weapon->set("weapon_prop/damage", weapon->query("weapon_prop/damage")/3);
weapon->set("owner",query("id"));
 weapon->set("value",0);
 weapon->set("no_get",1);
 weapon->set("no_give",1);
 weapon->set("no_drop",1);
 weapon->set("no_store",1);
weapon->move(zhe);
command("wield all");
}

if(armor=me->query_temp("armor"))
{
pname=keys(armor);
for(i=0;i<sizeof(armor);i++)
{
ar=new(base_name(armor[pname[i]]));
ar->set("value",0);
ar->set("no_get",1);
ar->set("no_drop",1);
ar->set("no_give",1);
ar->set("no_store",1);
ar->set("owner",query("id"));
ar->move(zhe);
}

command("wear all");
}
add_action("do_change","wield");
add_action("do_change","wear");
add_action("do_change","unwield");
add_action("do_change","remove");
add_action("do_change","drop");
add_action("do_change","enable");
add_action("do_change","jifa");
add_action("do_change","bei");
add_action("do_change","wbei");
add_action("do_change","call");
add_action("do_change","summon");
add_action("do_change","goto");
add_action("do_change","fly");
add_action("do_change","chat");
add_action("do_change","rumor");
add_action("do_change","hslj");
add_action("do_change","sys");
add_action("do_change","drink");
add_action("do_change","eat");
add_action("do_change","full");
add_action("do_change","quit");
add_action("do_change","halt");
return;
}
int do_change(string arg)
{
   write(HIR"生死相搏，岂能儿戏？\n"NOR);
  return 1;
}
