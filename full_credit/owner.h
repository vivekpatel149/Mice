#ifndef _OWNER_H
#define _OWNER_H
#include"person.h"
//#include"server.h"
#include<vector>
#include<gtkmm.h>
using namespace std;
class Owner : public Person
{
  public:
  Owner(string _name, string _phone, string _Id);
 // void create_server();
  void set_login(string login);
 // void generate_login();
  //void reset_loginpass();
  //string type() override;
//  void reset_server_pass(vector<Server> server);
  string get_pass();
  
  private:
  string name;
  string phone;
  string Owner_id;
  string login_pass;
};

#endif
