// by canoe

#include <ansi.h>
#define LINES_PER_PAGE	  35

void zj_more(string tab,string topic,string *text, int line, int page)
{
	int i, j, now, all;
	string show;

	show = tab;
	if(page<1) page = 1;
	all = sizeof(text)/line;
	if(page>(all+1)) page = all+1;
	
	i = page*line;
	if (i >= sizeof(text)) i = sizeof(text) - 1;
	j = (page-1)*line+1;
	if( j<0 ) j = 0;
	now = i/line;
	if(i%line) now += 1;
	if(now<1) now = 1;
	if(sizeof(text)%line) all += 1;
	if(all>1)
	show += sprintf("========= "HIY"%d/%d页"NOR" ========="ZJBR NOR,now,all);
show += implode(text[j..i], ZJBR);
//show += desinq();
		show += "\n"ZJOBACTS2+ZJMENUF(2,2,9,30)"上一页:help "+topic+" "+(page-1)+ZJSEP"下一页:help "+topic+" "+(page+1);	
	
	
	write(show+"\n");
}

void morefile(string cmd, string *text, int line)
{
        int i;
        
        switch(cmd) {
                case "b":
                        if(line<24) {
                                write(ESC+"[1A"+ESC+"[2002D"+ESC+"[K");
                                break;
                        }
                        if(line>23 && line<47) line = 0;
                        if(line>46) line -= 46;
                        write(ESC+"[1A"+ESC+"[2002D"+ESC+"[K\n\n");
                        for(i=line + 23; line < i;line++)
                        { 
//                      if ( this_player()->query("env/more") && wizardp(this_player()) ) 
                                if ( line <= 8 )
                                    write(HIR + "[000" + (line+1) + "]"+ NOR);
                                else
                                {
                                        if ( line <= 98 )
                                                write(HIR + "[00" + (line+1) + "]"+ NOR);
                                        else
                                        {
                                                if ( line <= 998 )
                                                        write(HIR + "[0" + (line+1) + "]"+ NOR);
                                                else
                                                        write(HIR + "[" + (line+1) + "]"+ NOR);
                                        }
                                }
                        write(text[line]+"\n");
                        }
                        break;
                case "q":
                        write(ESC+"[1A"+ESC+"[2002D"+ESC+"[K\n\n");
                        return;
                default :
                        write(ESC+"[1A"+ESC+"[2002D"+ESC+"[K");
                        for(i=line + 23; line<sizeof(text) && line<i; line++) 
                        {
//                              if ( this_player()->query("env/more") && wizardp(this_player()) ) 
                                if ( line <= 8 )
                                    write(HIR + "[000" + (line+1) + "]"+ NOR);
                                else
                                {
                                        if ( line <= 98 )
                                                write(HIR + "[00" + (line+1) + "]"+ NOR);
                                        else
                                        {
                                                if ( line <= 998 )
                                                        write(HIR + "[0" + (line+1) + "]"+ NOR);
                                                else
                                                        write(HIR + "[" + (line+1) + "]"+ NOR);
                                        }
                                }
                        write(text[line]+"\n");
                        }
                        if( line>=sizeof(text) ) return write(sprintf(HIW"-----------------------   [    文   件   结   束    ]   -----------------------\n"NOR));
;
                        break;
        }
        write(sprintf(HIM MUD_NAME + HIW + " >> 未完继续 " HIY "%d%%" HIW " << " NOR "(" HIC "ENTER" NOR " 继续下一页，" HIC 
                "q" NOR " 离开，" HIC "b" NOR " 前一页)\n", (line*100/sizeof(text))));
        input_to("morefile", text, line);
}
void more(string cmd, string *text, int line)
{
	int i;
	string show;

	show = ZJMORETXT;

	switch (cmd)
	{
	default:
		i = line + LINES_PER_PAGE;
		if (i >= sizeof(text)) i = sizeof(text) - 1;
		show += implode(text[line..i], ZJBR);
		if (i == sizeof(text) - 1)
		{
			write(show+"\n");
			return;
		}
		line = i + 1;
		break;

	case "b":
		line -= LINES_PER_PAGE * 2;
		if (line <= 0)
		{
			line = 0;
			show += WHT "-------- 文件的顶部 --------"NOR ZJBR;
		}

		i = line + LINES_PER_PAGE;
		if (i >= sizeof(text)) i = sizeof(text) - 1;
		show += implode(text[line..i], ZJBR);
		line = i + 1;
		break;

	case "q":
		write("\n");
		return;
	}
//	show += sprintf(ZJBR NOR WHT "== 未完继续 " HIY "%d%%" NOR WHT " == (ENTER 继续下一页，q 离开，b 前一页)" NOR,line * 100 / sizeof(text));
	show += sprintf(ZJBR WHT "======== 未完继续 " HIY "%d/%d页" NOR WHT " ========== " NOR,line / LINES_PER_PAGE,sizeof(text)/LINES_PER_PAGE+1);
	write(show+"\n");
	input_to("more", text, line);
}
void s_write(string msg)
{
	message("vision", msg, this_object());
}

void start_more(string msg)
{
     write("\n");
     more("", explode(msg, "\n"), 0);
}
/*void start_more(string msg)
{
	int len;

	if (! stringp(msg) || (len = strlen(msg)) < 1)
		// 没有内容
		return;

	if (query("env/no_more"))
	{
		s_write(msg);
		if (msg[len - 1] != '\n') write("\n");
		return;
	}

	write("\n");
	more("", explode(msg, "\n"), 0);
}*/
void more_file(string cmd, string file, int line, int total)
{
	int i;
	string show;
	string content;
	string *text;
	int goto_line;
	int page;
	int not_show;

	show = "";

	page = LINES_PER_PAGE;
	goto_line = line;

	if (! cmd) cmd = "";
	if (sscanf(cmd, "%d,%d", goto_line, page) == 2)
	{
		if (page < goto_line)
		{
			i = goto_line;
			goto_line = page;
			page = i;
		}
		page = page - goto_line + 1;
	} else
	if (sscanf(cmd, "n%d", page))
		;
	else
	if (sscanf(cmd, "%d", goto_line))
		; else
	{
		switch (cmd)
		{
		default:
			cmd = "";
			break;

		case "b":
			goto_line = line - LINES_PER_PAGE * 2;
			if (goto_line > 1)
				break;
			// else continue to run selection "t"
		case "t":
			goto_line = 1;
			break;

		case "q":
			write(show);
			return;
		}
	}

	if (page > 301)
	{
		show += "连续显示的行数必须小于等于300。\n";
		not_show = 1;
	} else
	{
		not_show = 0;

		if (! goto_line) goto_line = 1;
		if (! page) page = 1;

		if (goto_line < 0)
		{
			// The goto line < 0, mean look bottom
			goto_line += total;
			if (goto_line  < 1)
				goto_line = 1;
		}

		if (page < 0)
		{
			// The page size < 0, mean look previous page
			goto_line += page;
			if (goto_line < 1)
			{
				page -= goto_line - 1;
				goto_line = 1;
			}
			page = -page;
		}
	}

	line = goto_line;

	if (! not_show)
	{
		if (line == 1)
			show += WHT "-------- 文件的顶部 --------"NOR"\n";
		else
		if (cmd != "")
			show += sprintf(HIW "-------- 从第 %d 行开始 %d 行 --------"NOR"\n",
					goto_line, page);
	
		content = read_file(file, line, page);
		if (! content)
		{
			i = 0;
		} else
		{
			text = explode(replace_string(content, "\n", " \n") + " ", "\n");
			if (page > sizeof(text))
				page = sizeof(text);
			for (i = 0; i < page; i++)
				text[i] = sprintf(NOR "%-8d%s", i + line, text[i]);
			content = implode(text[0..i - 1], "\n") + "\n";
		
			show += content;
		}
	}

	if (not_show || i > 1)
	{
		show += NOR WHT "- 未完(" HIY + total +
			NOR WHT ") - (回车继续，"
			HIY "q" NOR WHT " 离开，"
			HIY "b" NOR WHT " 前一页，"
			HIC "<num>" NOR WHT " 到第 "
			HIC "n" NOR WHT " 行，"
			HIY "n" HIC "<num>" NOR WHT
			"显示接下 " HIC "n" NOR WHT " 行)" NOR;
		s_write(show);
		input_to("more_file", file, line + page, total);
	} else
	{
		show += WHT "阅读完毕。"NOR"\n";
		s_write(show);
	}
}
/*void more(string cmd, string *text, int line)
{
    int i;
    switch(cmd) {
    case "b":
        line = line - 46;
        if(line<0) line=0;
		write(ESC+"[1A"+ESC+"[2001D"+ESC+"[K\n\n"); 
        for(i=line + 23; line < i;line++)
        write(text[line]+"\n");
        break;
    case "q":
            write(ESC+"[1A"+ESC+"[200D"+ESC+"[K\n\n");
        return;
    default:
                write(ESC+"[1A"+ESC+"[200D"+ESC+"[K");
        for(i=line + 23; line<sizeof(text) && line<i; line++)
            write(text[line] + "\n");
        if( line>=sizeof(text) ) return;
        break;
    }
    write(sprintf("== 未完继续 " HIY "%d%%" NOR " == ("+HIC+"q"+NOR+" 离开，"+HIC+"b"+NOR+" 前一页，其他继续下一页)\n",
        (line*100/sizeof(text)) ));
    input_to("more", text, line);
}*/
/*void start_more(string msg)
{
     write("\n");
     more("", explode(msg, "\n"), 0);
}
*/
void start_more_file(string msg,string file)
{
//        if (!stringp(msg)) return;
        write(HIW"-----------------------   [    文   件   开   始    ]   -----------------------\n"+
                  "文件名： "+file+HIW" 。\n-------------------------------------------------------------------------------\n"NOR);
        write("\n");
        morefile("", explode(msg, "\n"), 0);
}

