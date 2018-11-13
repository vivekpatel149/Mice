#ifndef _ORDER_H
#define _ORDER_H
#include"serving.h"
#include"customer.h"
#include"server.h"
#include<vector>
#include<gtkmm.h>
#include<fstream>
#include<iostream>
using namespace std;

enum class Order_state {Unfilled, Filled, Paid, Canceled};
//enum class Order_event {Fill, Pay, Cancel};
class Order
{
 public:
 Order(Customer _customer,vector<Serving> serving, int _order_number, Server _ser);
 double price();
 void add_serving(Serving servings);
 void add_customer_total();
 void order_fill(Server _server);
 void order_pay(Server serve);
 Order_state confirm_order();
 void total_profit_save();
 Order_state order_status();
 int get_order_number();
 void show_order_status();
 //vector<string> operator+(Serving& serving1, Serving& serving2); 
  
 private:
 double total; 
 Order_state confirm;
 vector<Serving> servings;
 Customer customer;
 Server server;
 int order_number;
};
#endif
