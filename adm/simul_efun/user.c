// user.c

int playerp(object ob)
{
	return ob->is_player();
}

int ultrap(object ob)
{
	return ob->query("opinion/ultra");
}

int masterp(object ob)
{
	return ob->query("opinion/master");
}

// return the list of users
object *users()
{
	return filter_array(children(USER_OB), (: playerp :));
}

// return all the interactive users
object *all_interactive()
{
	return efun::users();
}

private int filter_player(object ob, string id)
{
	if (clonep(ob) && getuid(ob) == id)
		return 1;
}

// return a user, needn't interactive
/*object find_player(string id)
{
	object found;

	if((found = find_object(id))&&(base_name(found)==USER_OB))
		return found;
	return efun::find_player(id);
}
*/
