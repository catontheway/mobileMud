// kuangshi.h
// by augx@sj  10/22/2001
//

void change_state();
void create()
{
        set_name("矿石", ({ "kuangshi" , "shi" }));
        set_weight(1000+random(2000));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "这是一块普通的矿石。\n");
               // set("value", 3000);
                set("kuangshi",1);
                set("material_attrib",1);
                //set("kuangcai",0);
                set("no_sell","稀奇古怪的一块石头，要来何用？");// add by LinuX@SJ
                set("level",0);
        }
        setup();
        initlvl();
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
k=4;
if (j >=3) k=5;
if (j >=5) k=6;
if (j >=8) k=8;
if (random(k)>=3)
{
           newgem = new("/p/newweapon/weaponobj/kuangshi"+j);
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




int set_level(int i)
{
 set("kuangshi",1);
set("material_attrib",1);
        switch (i) {
                case 1:
                        set_name(GRN"青铜矿石"NOR, ({"qingtong kuangshi","kuangshi","shi"}));
                        set("long",GRN"普通的青铜矿石。\n"NOR);
                        set("material","qingtong");
                        set("value",250000);
                        break;
                case 2:
                        set_name(YEL"生铁矿石"NOR, ({"shengtie kuangshi","kuangshi","shi"}));
                        set("long",YEL"普通的生铁矿石。\n"NOR);
                        set("material","shengtie");
                        set("value",800);
                        break;
                case 3:
                        set_name(YEL"软铁矿石"NOR, ({"ruantie kuangshi","kuangshi","shi"}));
                        set("long",YEL"普通的软铁矿石。\n"NOR);
                        set("material","ruantie");
						set("jhxk", 20);
                        set("value",1200);
                        break;
                case 4:
                        set_name(HIG"绿石矿"NOR, ({"lukuang shi","kuangshi","shi"}));
                        set("long",HIG"少有的绿石矿石。\n"NOR);
                        set("material","lushi");
						set("jhxk", 30);
                        set("value",1800);
                        break;
                case 5:
                        set_name(RED"流花石矿"NOR, ({"liuhuashi kuang","kuangshi","shi"}));
                        set("long",RED"少有的流花石矿石。\n"NOR);
                        set("material","liuhuashi");
						set("jhxk", 40);
                        set("value",2500);
                        break;
                case 6:
                        set_name(HIW"软银矿石"NOR, ({"ruanyin kuangshi","ruanying","kuangshi","shi"}));
                        set("long",HIW"稀有的软银矿石。\n"NOR);
                        set("material","ruanying");
						set("jhxk", 60);
                        set("value",3900);
                        break;
                case 7:
                        set_name(HIY"金铁矿石"NOR, ({"jintie kuangshi","kuangshi","shi"}));
                        set("long",HIY"稀有的金铁矿石。\n"NOR);
                        set("material","jintie");
						set("jhxk", 80);
                        set("value",7000);
                        break;
                case 8:
                        set_name(RED"万年神铁矿石"NOR, ({"shentie kuangshi","kuangshi","shi"}));
                        set("long",RED"极其罕见的万年神铁矿石。\n"NOR);
                        set("material","shentie");
						set("jhxk", 90);
                        set("value",10000);
                        break;
                case 9:
                        set_name(WHT"玄铁矿石"NOR, ({"xuantie kuangshi","kuangshi","shi"}));
                        set("long",WHT"绝无仅有的玄铁矿石。\n"NOR);
                        set("material","xuantie");
						set("jhxk", 100);
                        set("value",20000);
                        break;
                case 10:
                	set_name(HIC"万年陨铁石"NOR, ({"hanbing kuangshi","kuangshi","shi"}));
                        set("long",HIC"出产在雪山之巅的冰雪淬炼万年铁。\n"NOR);
                        set("material","hantie");
						set("jhxk", 120);
                        set("value",40000);
                        break;
                case 11:
                        set_name(MAG"未知矿石"NOR, ({"weizhi kuangshi","kuangshi","shi"}));
                        set("long",MAG"这是一块还没有人能够识别的新奇矿石。\n"NOR);
                        set("material","xuantie");
						set("jhxk", 200);
                        set("no_sell",1);
                        set("value",1);
                        set("kuangshi",0);
                        set("kuangcai",0);
                        set("job_kuangshi",1);
                        break;
                 default:
                 	call_out("destroying", 1, this_object());
                 	return 0;                 
        }
        //跳过datie
        set("level",i);
        if(i!=11) change_state();
        return 1;
}

int query_level()
{
        return query("level");
}

void change_state()
{
        //set("kuangshi",0);
        set("kuangcai",1);
        set("value",query("value") * 40/10);

        switch (query_level()) {
                case 1:
                        set_name(GRN"青铜"NOR, ({"qingtong"}));
                        set("long",GRN"斑斑铜锈绿中透着古意，这是一块青铜。\n"NOR);
                        break;
                case 2:
                        set_name(YEL"生铁"NOR, ({"shengtie"}));
                        set("long",YEL"乌亮两色集与一身，这是矿工常用的生铁。\n"NOR);
                        break;
                case 3:
                        set_name(YEL"软铁"NOR, ({"ruantie"}));
                        set("long",YEL"这种产自南方的软铁，质地不如生铁坚硬，但却韧性更足。\n"NOR);
                        break;
                case 4:
                        set_name(HIG"绿石"NOR, ({"lushi"}));
                        set("long",HIG"绿石原产云南，石中带骨，声如洪种，是打造上乘武器的原料。\n"NOR);
						set("jhxk", 20);
                        break;
                case 5:
                        set_name(RED"流花石"NOR, ({"liuhuashi"}));
                        set("long",RED"其色斑斓，其质刚劲，其型瑞合，是为流花石也。\n"NOR);
						set("jhxk", 30);
                        break;
                case 6:
                        set_name(HIW"软银"NOR, ({"ruanyin","ruanying"}));
                        set("long",HIW"这种金属外柔而内刚，卸劲于无形，因为色白，江湖人称软银。\n"NOR);
						set("jhxk", 40);
                        break;
                case 7:
                        set_name(HIY"金铁"NOR, ({"jintie"}));
                        set("long",HIY"有三分金，五分铁，两分黑石，传说中的金铁极其罕见。\n"NOR);
						set("jhxk", 60);
                        break;
                case 8:
                        set_name(RED"万年神铁"NOR, ({"shentie"}));
                        set("long",RED"铁入地母，沉睡百年以上而有魂，人们称赞之为“万年神铁”。\n"NOR);
						set("jhxk", 80);
                        break;
                case 9:
                        set_name(WHT"玄铁"NOR, ({"xuantie"}));
                        set("long",WHT"此铁原产瑶池仙境，随恶煞气洒落人间，内含玄机无数，凡人莫能知其究竟。\n"NOR);
						set("jhxk", 90);
                        break;
                case 10:
                	set_name(HIC"万年寒冰铁"NOR, ({"hantie"}));
                        set("long",HIC"不知出处，铁质冰寒，消魂噬骨，有万年造化之力的一块寒冰铁。\n"NOR);
						set("jhxk", 100);
                        break;
        }
        //WORKER_D->get_status(this_object(),1,query_level(),random(5)?1:0);
        //msg = WORKER_D->get_msg(query("material_prop"));
        //if(stringp(msg) && msg!="")  set_temp("apply/long",({short()+"\n"+query("long")+msg}));
}

void destroying(object obj)
{
	if (!obj) return;
	if (userp(obj))
		command("drop "+obj->parse_command_id_list()[0]);
	else
		destruct(obj);
}