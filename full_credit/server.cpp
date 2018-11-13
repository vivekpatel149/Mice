#include"server.h"
using namespace std;
Server::Server(string _name, string _phone, string _Id): Person(_name, _phone, _Id) ,name{_name}, phone{_phone}, Server_id{_Id},login_pass{"pass"},  orders_fill{0}, orders_paid{0}{}

void Server::set_orders()
{ orders_fill = 0;
  orders_paid = 0;}
void Server::set_login(string login)
{
 login_pass = login;
}

 void Server::genrate_login()
 {
  string pass = "S"+to_string(Server_id[1])+to_string(Server_id[2])+to_string(phone[2])+to_string(phone[5]);
  string overall ="New Password for Serever : "+name+"\n"+"Server id : "+ Server_id+"\nPassword: "+pass+"\nPlease change the pass word after first Login";
  login_pass = pass;
  Gtk::MessageDialog *messagee = Gtk::manage (new Gtk::MessageDialog{overall});
         messagee->run();
         messagee->close();
         while (Gtk::Main::events_pending())  Gtk::Main::iteration(); 
 }
 
 string Server::get_pass()
 {
   return login_pass;
 }
 void Server::reset_loginpass()
 {  
    bool choices = true;
    while(choices)
    {
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title("RESET PASSWORD");
    //name
    Gtk::HBox *b_name = Gtk::manage (new Gtk::HBox);

    Gtk::Label *l_name = Gtk::manage (new Gtk::Label("ENTER SERVER NAME "));
    l_name->set_width_chars(30);
    b_name->pack_start(*l_name, Gtk::PACK_SHRINK);

    Gtk::Entry *e_name = Gtk::manage (new Gtk::Entry{});
    e_name->set_max_length(50);
    b_name->pack_start(*e_name, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(*b_name, Gtk::PACK_SHRINK);
    //id
    Gtk::HBox *b_id = Gtk::manage (new Gtk::HBox);

    Gtk::Label *l_id = Gtk::manage (new Gtk::Label("ENTER SERVER ID "));
    l_id->set_width_chars(30);
    b_id->pack_start(*l_id, Gtk::PACK_SHRINK);

    Gtk::Entry *e_id = Gtk::manage (new Gtk::Entry{});
    e_id->set_max_length(50);
    b_id->pack_start(*e_id, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(*b_id, Gtk::PACK_SHRINK);
    //phone
    Gtk::HBox *b_phone = Gtk::manage (new Gtk::HBox);

    Gtk::Label *l_phone = Gtk::manage (new Gtk::Label("ENTER SERVER PHONE "));
    l_phone->set_width_chars(30);
    b_phone->pack_start(*l_phone, Gtk::PACK_SHRINK);

    Gtk::Entry *e_phone = Gtk::manage (new Gtk::Entry{});
    e_phone->set_max_length(50);
    b_phone->pack_start(*e_phone, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(*b_phone, Gtk::PACK_SHRINK);
    //Enter Previous Pass
    Gtk::HBox *b_previous = Gtk::manage (new Gtk::HBox);

    Gtk::Label *l_previous = Gtk::manage (new Gtk::Label("ENTER PREVIOUS PASSWORD "));
    l_previous->set_width_chars(30);
    b_previous->pack_start(*l_previous, Gtk::PACK_SHRINK);

    Gtk::Entry *e_previous = Gtk::manage (new Gtk::Entry{});
    e_previous->set_max_length(50);
    b_previous->pack_start(*e_previous, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(*b_previous, Gtk::PACK_SHRINK);
    
    //new Pass
    Gtk::HBox *b_pass = Gtk::manage (new Gtk::HBox);

    Gtk::Label *l_pass= Gtk::manage (new Gtk::Label("ENTER NEW PASSWORD "));
    l_pass->set_width_chars(30);
    b_pass->pack_start(*l_pass, Gtk::PACK_SHRINK);

    Gtk::Entry *e_pass = Gtk::manage (new Gtk::Entry{});
    e_pass->set_max_length(50);
    b_pass->pack_start(*e_pass, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(*b_pass, Gtk::PACK_SHRINK);
    //Buttons
    dialog->add_button("Cancel Reset", 0);
    dialog->add_button("RESET PASSWORD", 1);
    dialog->show_all();
    int result = dialog->run();
    

    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration(); 
    
    if(result == 2)
    { 
       if( e_name->get_text() == name && e_id->get_text() == Server_id && e_previous->get_text() == login_pass && e_phone->get_text() == phone)
       {
         login_pass = e_pass->get_text(); 
         Gtk::MessageDialog *messagee = Gtk::manage (new Gtk::MessageDialog{"Password Reset"});
         messagee->run();
         messagee->close();
         while (Gtk::Main::events_pending())  Gtk::Main::iteration(); choices = false;
       }
       else
        {
           Gtk::Dialog *dialogss = new Gtk::Dialog();
           dialogss->set_title("RESET PASSWORD ERROR MESSAGE");
           Gtk::HBox *b_passs = Gtk::manage (new Gtk::HBox);

           Gtk::Label *l_passs= Gtk::manage (new Gtk::Label("The Data you entered is not matched with the information\nWOULD you like to try again? "));
           l_passs->set_width_chars(60);
           b_passs->pack_start(*l_passs, Gtk::PACK_SHRINK);
           dialogss->get_vbox()->pack_start(*b_passs, Gtk::PACK_SHRINK);
           dialogss->add_button("NO", 0);
           dialogss->add_button("YES RESET PASSWORD", 1);
           dialogss->show_all();
           int results = dialogss->run();
    
            dialogss->close();
            while (Gtk::Main::events_pending())  Gtk::Main::iteration();
            if(results == 0)
            { choices = false;} 
             
        }
    }else { choices = false;}
     }
 }
 void Server::server_order_fill(){orders_fill +=1;}
 void Server::server_order_paid(){orders_paid +=1;}
 int Server::orders(){ return orders_fill+orders_paid;}
 double Server::salaryi(){ return salary;}
 double Server::total_salary()
 { 
    double orr = (double)((orders_fill+orders_paid)/2); 
     return (orr*salary);}
 void Server::set_order(int ord){ orders_fill = ord;}
 void Server::set_salary(double _salary){salary = _salary;}
 //string Server::type() {return "Server";}
