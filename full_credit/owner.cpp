#include"owner.h"



Owner::Owner(string _name, string _phone, string _Id): Person(_name, _phone, _Id), name{_name}, phone{_phone}, Owner_id{ _Id}{}

string Owner::get_pass()
{return login_pass;}

void Owner::set_login(string login)
{
 login_pass = login;
}
