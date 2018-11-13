#ifndef _EMPORIUM_H
#define _EMPORIUM_H
#include"manager.h"
#include"customer.h"
#include"server.h"
#include"scoop.h"
#include"container.h"
#include"order.h"
#include"topping.h"
#include"owner.h"
#include<string>
#include<vector>
#include<iostream>

#include<fstream>
using namespace std;

class Emporium
{
 public:
 Emporium(){}
 void get_data();
 void fill_data();
 void update_order(Order orders);
 void update_server(Server servers);
 void update_topping(Topping toppings);
 void update_scoop(Scoop scoops);
 void update_customer(Customer customers);
 void update_container(Containerss conatiners);
 void update_manager(Manager managers);
 vector<Scoop> get_scoop();
 vector<Topping> get_topping();
 vector<Containerss> get_container();
 vector<Server> get_server();
 vector<Customer> get_customer();
 vector<Order> get_order();
 vector<Manager> get_manager();
 vector<Owner> get_owner();
 
 private:
 vector<string> cost_type;//get the type of item and server
 vector<string> cost_name;//get the name of the type
 vector<double> cost_real;//get the real cost

 vector<Scoop> scoop;
 vector<Topping> topping;
 vector<Containerss> container;
 vector<Manager> manager;
 vector<Server> server;
 vector<Customer> customer;
 vector<Order> order;
 vector<Owner> owner;
};
#endif
