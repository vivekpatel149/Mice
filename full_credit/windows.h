#ifndef WINDOWS_H
#define WINDOWS_H

#include<gtkmm.h>
#include<vector>
#include<string>
#include"dialoged.h"
#include"item.h"
#include"scoop.h"
#include"container.h"
#include"topping.h"
#include"serving.h"
#include"order.h"
#include"create.h"
#include"emporium.h"
#include"manager.h"
#include"owner.h"
using namespace std;

class Windows : public Gtk::Window
{
  public:
     Windows(Emporium& _empo,string _type, int _position);
     virtual ~Windows();

  protected:
     void create_new_manager_click();
     void create_new_item_click();
     void create_new_server_click();
     void create_new_customer_click();
     void create_new_order_click();
     void fill_order_click();
     void pay_order_click();
     void order_state_order_click();
     void create_new_serving_click(int n);
     void on_quit_click();
     void restock_container();
     void restock_scoop();
     void restock_topping();
     void save_data();
     void show_inventory();
     void show_financial();
     void pay_server_click();
  private:
     Emporium& empo;
     vector<Containerss> containers;
     vector<Scoop> scoops;
     vector<Topping> toppings;
     vector<Serving> serving;
     vector<Order> order;
     vector<Customer> customer;
     vector<Server> server;
     vector<Manager> manager;
     vector<Owner> owner;
     string type;
     int order_number;
     int position;
};
#endif

