// buliao.h
// by augx@sj 10/22/2001

void create()
{
        set_name("布匹", ({ "buliao" }));
        set_weight(1000+random(2000));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "茧");
                set("long", "这是一捆普通的布料。\n");
                set("material_attrib",1);
               // set("value", 3000);
                set("buliao",1);
                set("no_sell",query("name")+"可以用来做出布，你还是自己留着吧");// add by LinuX@SJ
        }
        setup();
        initlvl();
}

int query_level()
{
        return query("level");
}

int set_level(int i)
{       
        set("level",i);
        set("buliao",0);
        set("bu",1);        
        set("buliao",1);
        set("material_attrib",1);
        switch (i) {
                case 1:
                        set_name(HIW"棉花"NOR, ({"mianhua","mianhua","hua"}));
                        set("long",HIW"这是一块普通棉，人们最常用的廉价衣料的原料。\n"NOR);
                        set("material","mianhua");
                        set("value",250000);
                        break;
                case 2:
                        set_name(YEL"亚麻"NOR, ({"yama","yama","ma"}));
                        set("long",YEL"这是一块亚麻，由亚麻的茎皮纤维纺织而成的布料质地疏松手感粗糙。\n"NOR);
                        set("material","yama");
                        set("value",800);
                        break;
                case 3:
                        set_name(YEL"大麻"NOR, ({"dama","dama","ma"}));
                        set("long",YEL"这是一块大麻,选用大麻的细纤维精织而成的夏布，可做衣料。\n"NOR);
                        set("material","dama");
                        set("value",1200);
                        break;
                case 4:
                        set_name(HIY"苎麻"NOR, ({"zhuma","zhuma","ma"}));
                        set("long",HIY"这是一块上等的苎麻,选用上等的苎麻精织而成的布料，其纤维洁白有光泽，耐热且抗拉力。\n"NOR);
                        set("material","zhuma");
						set("jhxk", 20);
                        set("value",1800);
                        break;
                case 5:
                        set_name(HIW"蚕丝"NOR, ({"cansi","si" }));
                        set("long",HIW"这是寻常家蚕吐的丝，看上去纤细柔滑。\n"NOR);
                        set("material","cansi");
						set("jhxk", 30);
                        set("value",2500);
                        break;
                case 6:
                        set_name(HIY"木棉花"NOR, ({"mumianhua","hua"}));
                        set("long",HIY"少有的木棉花。\n"NOR);
                        set("material","mumianhua");
						set("jhxk", 40);
                        set("value",3900);
                        break;
                case 7:
                        set_name(GRN"玉蚕丝"NOR, ({"yucansi","si"}));
                        set("long",GRN"这是产自百毒谷的玉蚕丝。看上去比一般的丝略粗，具有极高的弹性及柔韧性，通体透白，是蚕丝中的精品。\n"NOR);
                        set("material","yucansi");
						set("jhxk", 60);
                        set("value",7000);
                        break;
                case 8:
                        set_name(HIW"冰蚕丝"NOR, ({"bingcansi","si"}));
                        set("long",HIW"传说中昆仑山巅某种冰蚕吐的丝，粘性极强、伸缩自如。若不得解法，一旦沾上再难脱身，犹如被恶鬼缠身。\n"NOR);
                        set("material","bingcansi");
						set("jhxk", 80);
                        set("value",10000);
                        break;
                case 9:
                        set_name(WHT"天蚕丝"NOR, ({"tiancansi","si"}));
                        set("long",WHT"这是天山蚕王所吐的丝，坚韧无比，寻常刀剑不能将其斩断。\n"NOR);
                        set("material","tiancansi");
						set("jhxk", 90);
                        set("value",20000);
                        break;
                case 10:
                	set_name(HIY"龙茧蚕丝"NOR,({"longcansi","si"}));
                	set("long",HIY"一种形如盘龙的毒蚕所产之丝。\n"NOR);
                	set("material","longcansi");
					set("jhxk", 100);
                	set("value",40000);
                	break;
                case 11:
                        set_name(MAG"波斯彩丝"NOR, ({"bosi caisi","caisi","si"}));
                        set("long",MAG"这是一块匹从西域波斯运来的波斯彩丝。\n"NOR);
                        set("material","bosicaisi");
						set("jhxk", 200);
                        set("no_sell",1);
                        set("no_drop",1);
                        set("no_get",1);
                        set("no_give",1);
                        set("value",1);
                        set("job_buliao",1);
                        set_weight(1000+random(2000));
                        break;
                default:call_out("destroying", 1, this_object());
                 	return 0;     
        }
        set("value",query("value") * 40/10);
        //WORKER_D->get_status(this_object(),1,query_level(),random(5)?1:0);
        //msg = WORKER_D->get_msg(query("material_prop"));
        //if(stringp(msg) && msg!="") set_temp("apply/long",({short()+"\n"+query("long")+msg}));
        return 1;
}

void change_state2(string type)
{
        if( query_level() != 11 ) return;

        set("buliao",0);
        set("bu",0);
        set("job_cloth",1);
        set("no_give",0);
        set("value",query("value") * 40/10);

        switch (type) {
                case "coat":
                        set_name(MAG"波斯彩衣"NOR, ({"bosi caiyi","caiyi","bosi cai"}));
                        set("unit", "件");
                        break;
                case "armor":
                        set_name(MAG"波斯彩甲"NOR, ({"bosi caijia","caijia","bosi cai"}));
                        set("unit", "件");
                        break;
                case "boot":
                        set_name(MAG"波斯彩靴"NOR, ({"bosi caixue","caixue","bosi cai"}));
                        set("unit", "双");
                        break;
                case "belt":
                        set_name(MAG"波斯彩带"NOR, ({"bosi caidai","caidai","bosi cai"}));
                        set("unit", "条");
                        break;
                case "cap":
                        set_name(MAG"波斯彩帽"NOR, ({"bosi caimao","caimao","bosi cai"}));
                        set("unit", "顶");
                        break;
                case "mantle":
                        set_name(MAG"波斯披风"NOR, ({"bosi pifeng","pifeng","bosi cai"}));
                        set("unit", "件");
                        break;
                case "glove":
                        set_name(MAG"波斯手套"NOR, ({"bosi shoutao","shoutao","bosi cai"}));
                        set("unit", "双");
                        break;
        }
        set("long",MAG"这是一"+query("unit")+"用从西域波斯运来的波斯彩绸制成的"+name()+MAG"。\n"NOR);
}

void destroying(object obj)
{
	if (!obj) return;
	if (userp(obj))
		command("drop "+obj->parse_command_id_list()[0]);
	else
		destruct(obj);
}

void change_name()
{
        switch (query_level()) {
                case 1:
                        set_name(HIW"棉布"NOR, ({"mian bu","mianhua","bu"}));
                        set("long",HIW"这是一块由普通棉纱织成的布，人们最常用的廉价衣料。\n"NOR);
                        break;
                case 2:
                        set_name(YEL"亚麻布"NOR, ({"yama bu","yama","bu"}));
                        set("long",YEL"这是一块用亚麻的茎皮纤维纺织而成的布料，质地疏松手感粗糙。\n"NOR);
                        break;
                case 3:
                        set_name(YEL"大麻布"NOR, ({"dama bu","dama","bu"}));
                        set("long",YEL"这是一块选用大麻的细纤维精织而成的夏布，可做衣料。\n"NOR);
                        break;
                case 4:
                        set_name(HIY"苎麻布"NOR, ({"zhuma bu","zhuma","bu"}));
                        set("long",HIY"这是一块选用上等的苎麻精织而成的布料，其纤维洁白有光泽，耐热且抗拉力。\n"NOR);
						set("jhxk", 20);
                        break;
                case 5:
                        set_name(HIW"丝绸"NOR, ({"si chou","cansi","chou" }));
                        set("long",HIW"高价的丝绸。\n"NOR);
						set("jhxk", 30);
                        break;
                case 6:
                        set_name(HIY"木棉布"NOR, ({"mumian bu","mumianhua","bu"}));
                        set("long",HIY"少有的木棉布。\n"NOR);
						set("jhxk", 40);
                        break;
                case 7:
                        set_name(GRN"玉蚕丝绸"NOR, ({"yucan sichou","yucansi","sichou"}));
                      
					   set("long",GRN"这是产自百毒谷的玉蚕丝绸。看上去比一般的丝略粗，具有极高的弹性及柔韧性，通体透白，是蚕丝中的精品。\n"NOR);
					    set("jhxk", 60);
                        break;
                case 8:
                        set_name(HIW"冰蚕丝绸"NOR, ({"bingcan sichou","bingcansi","sichou"}));
                        set("long",HIW"极其罕见的冰蚕丝绸。\n"NOR);
						 set("jhxk", 80);
                        break;
                case 9:
                        set_name(WHT"天蚕丝绸"NOR, ({"tiancan sichou","tiancansi","sichou"}));
                        set("long",WHT"这是天山蚕王所吐的丝，坚韧无比，寻常刀剑不能将其斩断。\n"NOR);
						 set("jhxk", 90);
                        break;
                case 10:
                	set_name(HIY"龙茧丝绸"NOR,({"longjian sichou","longjiancansi","sichou"}));
                	set("long",HIY"一种形如盘龙的毒蚕所产之丝所制丝绸。\n"NOR);
					 set("jhxk", 100);
                	break;                
                case 11:
                        set_name(MAG"波斯彩绸"NOR, ({"bosi caichou","caichou","bosicansi","chou"}));
                        set("long",MAG"这是一匹从西域波斯运来的波斯彩绸。\n"NOR);
						 set("jhxk", 200);
                        break;
        }
}


void init()
{
	add_action("do_combine", "combine");
}

int do_combine(string arg)
{
	int i,j,k;
	object *inv, gem, me = this_player(),newgem;
 
	if (!arg || arg == "")
		return notify_fail("你想合并什么材料？\n");
	if (arg != query("id")) return 0;
	if (query("level") == 9)
		return notify_fail("这个材料已经是最高等级了！\n");
	if (me->query("max_neili") < 800 || me->query("neili") < 800)
		return notify_fail("以你现在的内力修为，还无法运功合并材料！\n");

	inv = all_inventory(me);
	for(i = 0; i < sizeof(inv); i++)
		if (inv[i] != this_object() && inv[i]->query("id") == query("id")) {
			if (!objectp(gem))
				gem = inv[i];
			else {
				message_vision(HIG"$N暗运内力劲透全身，但见" + name() + HIG"表面异彩流动，
渐渐的$N收回了内力，只觉" + name() + HIG"似乎变得更加完美了！\n", me);
				me->add("max_neili", -200);
				me->add("neili", -200);
				me->start_busy(1);
j=query("level");
j=j+1;

j=j+1;
k=4;
if (j >=3) k=5;
if (j >=5) k=6;
if (j >=8) k=8;
if (random(k)>=3)
{
           newgem = new("/p/newweapon/weaponobj/buliao"+j);
           newgem->move(me);
message_vision(HIG"在$N的内力下 " + name() + HIG"品质得到了提升变成"+newgem->query("name")+"\n"NOR, me);
//				new_gem(query("material"), query("level") + 1)->move(me);
}
else
{
				message_vision(RED"$N大叫一声不好! " + name() + RED"突然裂开了，失去了光泽！\n", me);
	
}
				destruct(gem);
				destruct(inv[i]);
				destruct(this_object());


				return 1;
			}
		}
	return notify_fail("你必须有三块同样的材料才能进行合并！\n");
}