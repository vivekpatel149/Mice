#ifndef _MANAGER_H
#define _MANAGER_H
#include"person.h"
#include"server.h"
#include<vector>
#include<gtkmm.h>
using namespace std;
class Manager : public Person
{
  public:
  Manager(std::string _name, std::string _phone, std::string _Id);
  void create_server();
  void set_login(string login);
  void generate_login();
  void reset_loginpass();
  //string type() override;
  void reset_server_pass(vector<Server> server);
  string get_pass();
  
  private:
  string name;
  string phone;
  string Manager_id;
  string login_pass;
};

#endif
