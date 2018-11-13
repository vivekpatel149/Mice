#include"manager.h"
using namespace std;
Manager::Manager(string _name,string _phone, string _Id): Person(_name, _phone, _Id), name{_name}, phone{_phone}, Manager_id{ _Id}{}

string Manager::get_pass()
{return login_pass;}

void Manager::set_login(string login)
{
 login_pass = login;
}

void Manager::generate_login()
 {
  string pass = "M"+to_string(Manager_id[0])+to_string(Manager_id[1])+to_string(Manager_id[2])+to_string(phone[6])+to_string(phone[8])+to_string(phone[9]);
  string overall ="New Password for Manager : "+name+"\n"+"Manager id : "+ Manager_id+"\nPassword: "+pass+"\nPlease change the pass word after first Login";
  login_pass = pass;
  Gtk::MessageDialog *messagee = Gtk::manage (new Gtk::MessageDialog{overall});
         messagee->run();
         messagee->close();
  while (Gtk::Main::events_pending())  Gtk::Main::iteration(); 
 }
 
 void Manager::reset_loginpass()
 {  
    bool choices = true;
    while(choices)
    {
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title("RESET PASSWORD");
    //name
    Gtk::HBox *b_name = Gtk::manage (new Gtk::HBox);

    Gtk::Label *l_name = Gtk::manage (new Gtk::Label("ENTER NAME "));
    l_name->set_width_chars(30);
    b_name->pack_start(*l_name, Gtk::PACK_SHRINK);

    Gtk::Entry *e_name = Gtk::manage (new Gtk::Entry{});
    e_name->set_max_length(50);
    b_name->pack_start(*e_name, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(*b_name, Gtk::PACK_SHRINK);
    //id
    Gtk::HBox *b_id = Gtk::manage (new Gtk::HBox);

    Gtk::Label *l_id = Gtk::manage (new Gtk::Label("ENTER MANAGER ID "));
    l_id->set_width_chars(30);
    b_id->pack_start(*l_id, Gtk::PACK_SHRINK);

    Gtk::Entry *e_id = Gtk::manage (new Gtk::Entry{});
    e_id->set_max_length(50);
    b_id->pack_start(*e_id, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(*b_id, Gtk::PACK_SHRINK);
    //phone
    Gtk::HBox *b_phone = Gtk::manage (new Gtk::HBox);

    Gtk::Label *l_phone = Gtk::manage (new Gtk::Label("ENTER MANAGER PHONE "));
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
       if( e_name->get_text() == name && e_id->get_text() == Manager_id && e_previous->get_text() == login_pass && e_phone->get_text() == phone)
       {
         login_pass = e_pass->get_text(); 
         Gtk::MessageDialog *messagee = Gtk::manage (new Gtk::MessageDialog{"Password Reset"});
         messagee->run();
         messagee->close();
         choices = false;
       }
       else
        {
           Gtk::Dialog *dialogss = new Gtk::Dialog();
           dialogss->set_title("RESET PASSWORD ERROR MESSAGE");
           Gtk::HBox *b_passs = Gtk::manage (new Gtk::HBox);

           Gtk::Label *l_passs= Gtk::manage (new Gtk::Label("The Data you entered is not matched with the information\nWOULD you like to try again? "));
           l_passs->set_width_chars(30);
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
  
 void Manager::reset_server_pass(vector<Server> server)
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
    //buttons
    dialog->add_button("Cancel Reset", 0);
    dialog->add_button("RESET PASSWORD", 1);
    dialog->show_all();
    int result = dialog->run();
    

    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration(); 
    if(result == 1)
    {   
        int c =0; 
        string server_name = e_name->get_text();
        string server_id = e_id->get_text();
        for(int i=0; i<server.size();i++)
        {
            if(server[i].get_name() == server_name && server[i].get_id() == server_id)
             {
               server[i].genrate_login();
               c++;
               choices = false;break;
             }
        }
        if(c == 0)  
        {
         Gtk::Dialog *dialogss = new Gtk::Dialog();
           dialogss->set_title("RESET PASSWORD ERROR MESSAGE");
           Gtk::HBox *b_passs = Gtk::manage (new Gtk::HBox);

           Gtk::Label *l_passs= Gtk::manage (new Gtk::Label("The Data you entered is not matched with the information\nWOULD you like to try again? "));
           l_passs->set_width_chars(30);
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
            else {choices = true;}
        }
    }
    else {choices = false;}
    }
}
//string Manager::type() {return "Manager";}
