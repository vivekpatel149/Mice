#ifndef _SERVER_H
#define _SERVER_H

#include<string>
#include<gtkmm.h>
#include"person.h"
using namespace std;
class Server: public Person{
public:
 Server(string _name, string _phone,string _Id);
 //Server() {}
 void genrate_login();
 void reset_loginpass();
 void server_order_fill();
 double total_salary();
 void set_salary(double _salary);
 void server_order_paid();
 string get_pass();
 void set_login(string login);
 void set_orders();
 void set_order(int ord);
 double salaryi();
 int orders();
 //string type() override;
private:
 
 int orders_fill;
 int orders_paid;
 string name;
 string Server_id;
 string login_pass;
 string phone;
 string types;
 double salary;
};
#endif
