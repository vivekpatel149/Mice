#include"order.h"
//Order::Order(Customer _customer, Server _server): customer{_customer}, server{_server}, fill{false}, confirm{false} {}
using namespace std;
Order::Order(Customer _customer,vector<Serving> serving, int _order_number, Server _ser):customer{_customer}, servings{serving}, order_number{_order_number}, server{_ser}{}

void Order::order_pay(Server serve)
{ 
   server = serve;
   Gtk::Dialog *message = Gtk::manage(new Gtk::Dialog());
             message->set_default_size(300, 300);
             message->set_title("PAY FOR THE ORDER");
   
             //Confirming the order
             Gtk::HBox b_message;

             Gtk::Label l_message{(customer.get_name()+": TOTAL FOR ORDER IS : "+to_string(price()))};
             l_message.set_width_chars(100);
             b_message.pack_start(l_message, Gtk::PACK_SHRINK);
             message->get_vbox()->pack_start(b_message, Gtk::PACK_SHRINK);
     
             // Show dialog
             message->add_button("Cancel Order",0);
             message->add_button("PAy In CASH", 1);
             message->show_all();
             int user_choice = message->run();

             message->close();
             while (Gtk::Main::events_pending())  Gtk::Main::iteration();
             if(user_choice == 1)
             {
                confirm = Order_state::Paid;
                total_profit_save();
                server.server_order_paid();
             }
             else {   confirm = Order_state::Canceled;}
}
void Order::add_serving(Serving servi)
{
  servings.push_back(servi);
}

void Order::add_customer_total()
{
  customer.add_total(price());
}
 void Order::order_fill(Server _server)
{
 server = _server; 
 if(confirm == Order_state::Unfilled)
 {
   string user_choice="SERVINGS TO FILL ARE AS FOLLOW\n\n";
   for(int i=0;i<servings.size();i++)
   {
    user_choice += "SERVING " + to_string(i+1) + " as follow\n"+ servings[i].get_serving()+"\n";
   }
    user_choice += "\nPLEASE CLICK FILL BUTTON AFTER FILLING THE ORDER";
   Gtk::Dialog *message = Gtk::manage(new Gtk::Dialog());
             message->set_default_size(300, 300);
             message->set_title("Serving to Fill");
   
             //Confirming the order
             Gtk::HBox b_message;

             Gtk::Label l_message{user_choice};
             //l_message.set_width_chars(100);
             b_message.pack_start(l_message, Gtk::PACK_SHRINK);
             message->get_vbox()->pack_start(b_message, Gtk::PACK_SHRINK);
     
             // Show dialog
             message->add_button("CANCEL", 0);
             message->add_button("FILL",1);
             message->show_all();
             int result = message->run();

             message->close();
             while (Gtk::Main::events_pending())  Gtk::Main::iteration();
             if(result == 1)
             {  
                bool order_consume;
                for(int i=0;i<servings.size();i++){order_consume = servings[i].serving_consume(); }
                if( order_consume == true)
                { 
                    server.server_order_fill();
                    confirm = Order_state::Filled;
                }
                else {    Gtk::MessageDialog *message = Gtk::manage (new Gtk::MessageDialog{"Item Quantity is Less Please Restock the Item First"});
                          message->run();
                          message->close();
                          while (Gtk::Main::events_pending())  Gtk::Main::iteration();
                          confirm = Order_state::Unfilled;} 
             } 
             else{confirm = Order_state::Unfilled;}
 }
 /*else
 {
   Gtk::Dialog *message = Gtk::manage(new Gtk::Dialog());
             message->set_default_size(300, 300);
             message->set_title("CONFIRM THE ORDER");
   
             //Confirming the order
             Gtk::HBox b_message;

             Gtk::Label l_message{"Order is not confirmed.\nPlease confirm order first before filling it!!!!!!"};
             l_message.set_width_chars(100);
             b_message.pack_start(l_message, Gtk::PACK_SHRINK);
             message->get_vbox()->pack_start(b_message, Gtk::PACK_SHRINK);
     
             // Show dialog
             message->add_button("CANCEL", 0);
             message->show_all();
             message->run();

             message->close();
             while (Gtk::Main::events_pending())  Gtk::Main::iteration();
 }*/
}
int Order::get_order_number(){return order_number;}
Order_state Order::confirm_order()
{
 string user_choice = "";
 double user_total=0;
 if(servings.size() == 0)
 {confirm = Order_state::Canceled;}
 else
 {
   for(int i=0;i<servings.size();i++)
   {
    user_choice += "SERVING " + to_string(i+1) + " as follow\n"+ servings[i].get_serving()+"\n";
    user_total += servings[i].serving_total();
   }
  // ostringstream in;
   //in <<setprecision(2) << user_total;
   //string names =customer.get_name();
   //string last = R"(<span font='18' weight='bold'>"+ customer.get_name() + "</span>" +" : Total is for your order is : <span font = '18' wieght = 'bold' underline = 'single'> $"+to_string(user_total)+"</span> \n<span weight='bold'>Click Confirm Button to Confirm</span>)";
   user_choice +="\n"+customer.get_name()+":  Total for your order is $"+to_string(user_total)+"\n\nYOUR ORDER NUMBER IS "+to_string(order_number)+"\nClick Confirm Button to confirm";
   //user_choice +=last;
   Gtk::Dialog *message = Gtk::manage(new Gtk::Dialog());
             message->set_default_size(300, 300);
             message->set_title("CONFIRM THE ORDER");
   
             //Confirming the order
             Gtk::HBox b_message; 

             Gtk::Label l_message{user_choice};
             l_message.set_width_chars(100);
             b_message.pack_start(l_message, Gtk::PACK_SHRINK);
             message->get_vbox()->pack_start(b_message, Gtk::PACK_SHRINK);
     
             // Show dialog
             message->add_button("CANCEL", 0);
             message->add_button("CONFIRM", 1);
             message->show_all();
             int last_choice  =message->run();

             message->close();
             while (Gtk::Main::events_pending())  Gtk::Main::iteration();
    if(last_choice == 1)
    {
     confirm = Order_state::Unfilled;
    }
    else {confirm = Order_state::Canceled;}
  }
 return confirm;
} 

double Order::price()
{
 double price = 0;
 for(int i=0;i<servings.size();i++)
 {
   price += servings[i].serving_total();
 }
 return price;
}
void Order::total_profit_save()
{
  double total_price = price();
  double cost = 0;
  for(int i=0;i<servings.size();i++)
   {
     cost += servings[i].serving_cost();
   } 
  double profit = total_price - cost;
  if(confirm == Order_state::Paid)
  {
    vector<string> overall;
    overall.push_back(to_string(order_number));
    overall.push_back(customer.get_name());
    overall.push_back(server.get_id());
    overall.push_back(to_string(cost));
    overall.push_back(to_string(profit));
    fstream file;
    try
     {
      //filling conatiner data
      file.open("Profit.txt",ios_base::app);
    
      {
          string line;
        for(int i;i<overall.size();i++)
        { 
          line=overall[i]+"\n";
          file<<line;
        }
      }
      file.close();
     }
  catch(...)
   { cerr<<"file not found error"<<endl;}
 }
}
void Order::show_order_status()
{ 
  string user_choice= "";
  double user_total = 0;
  for(int i=0;i<servings.size();i++)
   {
    user_choice += "SERVING " + to_string(i+1) + " as follow\n"+ servings[i].get_serving()+"\n";
    user_total += servings[i].serving_total();
   }
  user_choice +="\n"+customer.get_name()+":  Total for the order is $"+to_string(user_total);
  if(confirm == Order_state::Unfilled){user_choice += "\nTHE ORDER STATUS IS UNFILLED";} 
  else if(confirm == Order_state::Filled){user_choice += "\nTHE ORDER STATUS IS FILLED";}
  else if(confirm == Order_state::Paid){user_choice += "\nTHE ORDER STATUS IS PAID";}
  else if(confirm == Order_state::Canceled){user_choice += "\nTHE ORDER STATUS IS CANCELED";}
  //user_choice +=last;
   Gtk::Dialog *message = Gtk::manage(new Gtk::Dialog());
             message->set_default_size(300, 300);
             message->set_title("ORDER STATUS FOR ORDER NUMBER "+to_string(order_number));
   
             //Confirming the order
             Gtk::HBox b_message; 

             Gtk::Label l_message{user_choice};
             l_message.set_width_chars(100);
             b_message.pack_start(l_message, Gtk::PACK_SHRINK);
             message->get_vbox()->pack_start(b_message, Gtk::PACK_SHRINK);
     
             // Show dialog
             message->add_button("OK", 0);
            // message->add_button("CONFIRM", 1);
             message->show_all();
             message->run();

             message->close();
             while (Gtk::Main::events_pending())  Gtk::Main::iteration();
  
  }
 Order_state Order::order_status()
{return confirm;}
/*
vector<string> Order::operator+(Serving& serving1, Serving& serving2)
{
 vector<string> serve;
 string choice = serving1->get_serving() + serving2->get_serving();
 serve.Push_back( choice);
 sftring result = to_string(serving1->serving_total()) + to_string(serving2->serving_total())
 serve.push_back(result);
 return serve;

}*/
