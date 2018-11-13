#ifndef _CREATE_H
#define _CREATE_H
#include "manager.h"
#include "customer.h"
#include "server.h"
//#include "order.h"
//#include "serving.h"
#include<string>
#include<gtkmm.h>
#include"topping.h"
#include"scoop.h"
#include"container.h"
#include"emporium.h"
#include"serving.h"
using namespace std;

class Create
{
 public:
 Create(Emporium& _empo);
 Manager create_new_manager();
 Server create_new_server();
 Customer create_new_customer();
 void create_new_order();
 void create_new_serving(int n);
 private:
 Emporium& empo;
 vector<Containerss> containers;
 vector<Scoop> scoops;
 vector<Topping> toppings;
 vector<Serving> serving;
};
#endif
