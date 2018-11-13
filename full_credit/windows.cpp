#include"windows.h"

Windows::Windows(Emporium& _empo,string _type, int _position):position{_position},empo{_empo}, scoops{empo.get_scoop()}, toppings{empo.get_topping()}, containers{empo.get_container()}, customer{empo.get_customer()}, server{empo.get_server()}, order{empo.get_order()},manager{empo.get_manager()}, type{_type}, order_number{0}, owner{empo.get_owner()}
{ 
    set_default_size(800,400);
       // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);
     // ///////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //     F I L E
    Gtk::MenuItem *menuitem_FILE = Gtk::manage (new Gtk::MenuItem("FILE",true));
    menubar->append(*menuitem_FILE);
    Gtk::Menu *FILEmenu = Gtk::manage(new Gtk::Menu());
    menuitem_FILE->set_submenu(*FILEmenu);

    //NEW Emporium
    Gtk::MenuItem *menuitem_new_emporium = Gtk::manage(new Gtk::MenuItem("_NEW_EMPORIUM",true));
 // Set Call function for new emporium
    FILEmenu->append(*menuitem_new_emporium);
    if(type == "server" || type=="customer"){ menuitem_new_emporium->set_sensitive(false);}

    //Open Emporium
   Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_OPEN_EMPORIUM",true));
 //Set call function for opening emporium
   FILEmenu->append(*menuitem_open);
    if(type == "server" || type=="customer"){ menuitem_open->set_sensitive(false);}


   //Save 		Data for current Emporium
   Gtk::MenuItem *menuitem_save = Gtk::manage (new Gtk::MenuItem("_SAVE_CURRENT_DATA",true));
   menuitem_save->signal_activate().connect(sigc::mem_fun(*this, &Windows::save_data)); 
   FILEmenu->append(*menuitem_save);
   if(type == "customer"){ menuitem_save->set_sensitive(false);}
     
    //Exit the Application
   Gtk::MenuItem *menuitem_exit = Gtk::manage(new Gtk::MenuItem("_EXIT", true));
    menuitem_exit->signal_activate().connect(sigc::mem_fun(*this,&Windows::on_quit_click));
    FILEmenu->append(*menuitem_exit);
    
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("CREATE", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);
    if(type=="customer"){ menuitem_file->set_sensitive(false);}


    //        Create New Item
    // Appending Create New Item
    Gtk::MenuItem *menuitem_create_item = Gtk::manage(new Gtk::MenuItem("_NEW_ITEM", true));
    menuitem_create_item->signal_activate().connect(sigc::mem_fun(*this, &Windows::create_new_item_click));
    filemenu->append(*menuitem_create_item);
    if(type == "server" || type=="customer"){ menuitem_create_item->set_sensitive(false);}
    
    //Create new Manager
     Gtk::MenuItem *menuitem_create_manager = Gtk::manage(new Gtk::MenuItem("_NEW_MANAGER", true));
     menuitem_create_manager->signal_activate().connect(sigc::mem_fun(*this, &Windows::create_new_manager_click));
     filemenu->append(*menuitem_create_manager);
     if(type == "server" || type=="customer" || type == "manager"){ menuitem_create_manager->set_sensitive(false);}

    //Create New Server
    Gtk::MenuItem *menuitem_create_server = Gtk::manage(new Gtk::MenuItem("_NEW_SERVER", true));
    menuitem_create_server->signal_activate().connect(sigc::mem_fun(*this, &Windows::create_new_server_click));
    filemenu->append(*menuitem_create_server);
     if(type == "server" || type=="customer"){ menuitem_create_server->set_sensitive(false);}

   //Create New Customer
    Gtk::MenuItem *menuitem_create_customer = Gtk::manage(new Gtk::MenuItem("_NEW_CUSTOMER", true));
    menuitem_create_customer->signal_activate().connect(sigc::mem_fun(*this, &Windows::create_new_customer_click));
    filemenu->append(*menuitem_create_customer);
    
    //Create New Serving / Order
    Gtk::MenuItem *menuitem_create_serving = Gtk::manage(new Gtk::MenuItem("_NEW_ORDER", true));
    menuitem_create_serving->signal_activate().connect(sigc::mem_fun(*this, &Windows::create_new_order_click));
    filemenu->append(*menuitem_create_serving);
   
    // Manage order
    Gtk::MenuItem *menuitem_order = Gtk::manage(new Gtk::MenuItem("_MANAGE_ORDER", true));
    menubar->append(*menuitem_order);
    Gtk::Menu *order_menu = Gtk::manage(new Gtk::Menu());
    menuitem_order->set_submenu(*order_menu);
     if(type=="customer"){ menuitem_order->set_sensitive(false);}

    //Pay and fill order
    Gtk::MenuItem *fill_order = Gtk::manage(new Gtk::MenuItem("_FILL_ORDER", true));
    fill_order->signal_activate().connect(sigc::mem_fun(*this, &Windows::fill_order_click));
    order_menu->append(*fill_order);
    
    
    //Pay and fill order
    Gtk::MenuItem *pay_order = Gtk::manage(new Gtk::MenuItem("_PAY_ORDER", true));
    pay_order->signal_activate().connect(sigc::mem_fun(*this, &Windows::pay_order_click));
    order_menu->append(*pay_order);
    
    //SEE ORDER STATUS
    Gtk::MenuItem *state_order = Gtk::manage(new Gtk::MenuItem("_SEE_ORDER_STATE", true));
    state_order->signal_activate().connect(sigc::mem_fun(*this, &Windows::order_state_order_click));
    order_menu->append(*state_order);
    
    //Edit Order
    Gtk::MenuItem *edit_order = Gtk::manage(new Gtk::MenuItem("_EDIT_ORDER", true));
//SET FUNCTION FOR EDITING ORDER
    order_menu->append(*edit_order);
   
    // Manage Server
    Gtk::MenuItem *menuitem_server = Gtk::manage(new Gtk::MenuItem("_MANAGE_SERVER", true));
    menubar->append(*menuitem_server);
    Gtk::Menu *server_menu = Gtk::manage(new Gtk::Menu());
    menuitem_server->set_submenu(*server_menu);
     if(type == "server" || type=="customer"){ menuitem_server->set_sensitive(false);}

   //Pay Server
   Gtk::MenuItem *server_pay = Gtk::manage(new Gtk::MenuItem("_SERVER_PAY",true));
   server_pay->signal_activate().connect(sigc::mem_fun(*this, &Windows::pay_server_click));
   server_menu->append(*server_pay);
   //SERVER REPORT
   Gtk::MenuItem *server_report = Gtk::manage(new Gtk::MenuItem("_SERVER_REPORT",true));
//set function for server report
  server_menu->append(*server_report);
    
    //Edit server details
    Gtk::MenuItem *edit_server = Gtk::manage(new Gtk::MenuItem("_EDIT_SERVER", true));
//SET FUNCTION FOR Edit Details for Server
    server_menu->append(*edit_server);
    
    
    //Reset Server Pass
    Gtk::MenuItem *reset_server_pass = Gtk::manage(new Gtk::MenuItem("_RESET_SERVER_LOGIN", true));
//SET FUNCTION FOR Reset Server Pass
    server_menu->append(*reset_server_pass);
    
    //Dlete Server
    Gtk::MenuItem *delete_server = Gtk::manage(new Gtk::MenuItem("_DELETE_SERVER", true));
//SET FUNCTION FOR DELETING SERVER
    server_menu->append(*delete_server);
   
   
    // Manage CUSTOMER
    Gtk::MenuItem *menuitem_customer = Gtk::manage(new Gtk::MenuItem("_MANAGE_CUSTOMER", true));
    menubar->append(*menuitem_customer);
    Gtk::Menu *customer_menu = Gtk::manage(new Gtk::Menu());
    menuitem_customer->set_submenu(*customer_menu);
     if(type=="customer"){ menuitem_customer->set_sensitive(false);}

    //CUSTOMER REPORT
   Gtk::MenuItem *customer_report = Gtk::manage(new Gtk::MenuItem("_CUSTOMER_REPORT",true));
//set function for customer report
  customer_menu->append(*customer_report);
     if(type == "server" || type=="customer"){ customer_report->set_sensitive(false);}

    //Edit customer details
    Gtk::MenuItem *edit_customer = Gtk::manage(new Gtk::MenuItem("_EDIT_CUSTOMER", true));
//SET FUNCTION FOR Edit Details for CUSTOMER
    customer_menu->append(*edit_customer);
    
    //Dlete CUSTOMER
    Gtk::MenuItem *delete_customer = Gtk::manage(new Gtk::MenuItem("_DELETE_CUSTOMER", true));
//SET FUNCTION FOR DELETING CUSTOMER
    customer_menu->append(*delete_customer);
   
    // Manage ITEM
    Gtk::MenuItem *menuitem_item = Gtk::manage(new Gtk::MenuItem("_MANAGE_ITEM", true));
    menubar->append(*menuitem_item);
    Gtk::Menu *item_menu = Gtk::manage(new Gtk::Menu());
    menuitem_item->set_submenu(*item_menu);
    if(type=="customer"){ menuitem_item->set_sensitive(false);}

    //ITEM REPORT
   Gtk::MenuItem *item_report = Gtk::manage(new Gtk::MenuItem("_ITEM_REPORT",true));
//set function for item report
   item_menu->append(*item_report);
  
   //RESTOCK ITEM
   Gtk::MenuItem *item_restock = Gtk::manage(new Gtk::MenuItem("_ITEM_RESTOCK",true));
   item_menu->append(*item_restock);
   Gtk::Menu *item_restock_menu = Gtk::manage(new Gtk::Menu());
   item_restock->set_submenu(*item_restock_menu);
   
   //item choose
   Gtk::MenuItem *container_restock = Gtk::manage(new Gtk::MenuItem("_CONTAINER",true));
   container_restock->signal_activate().connect(sigc::mem_fun(*this, &Windows::restock_container));    
   item_restock_menu->append(*container_restock);
    
   Gtk::MenuItem *scoop_restock = Gtk::manage(new Gtk::MenuItem("_SCOOP",true));
   scoop_restock->signal_activate().connect(sigc::mem_fun(*this, &Windows::restock_scoop));
   item_restock_menu->append(*scoop_restock);
 
   Gtk::MenuItem *topping_restock = Gtk::manage(new Gtk::MenuItem("_TOPPING",true));
   topping_restock->signal_activate().connect(sigc::mem_fun(*this, &Windows::restock_topping));
   item_restock_menu->append(*topping_restock);

    //Edit item details
   Gtk::MenuItem *edit_item = Gtk::manage(new Gtk::MenuItem("_EDIT_ITEM_DETAIL", true));
   item_menu->append(*edit_item);
   Gtk::Menu *edit_item_menu = Gtk::manage(new Gtk::Menu());
   edit_item->set_submenu(*edit_item_menu);
    if(type == "server" || type=="customer"){ edit_item->set_sensitive(false);}

   //item choose
   Gtk::MenuItem *ccontainer_restock = Gtk::manage(new Gtk::MenuItem("_CONTAINER",true));
//Set call funcction for conatiner restock
   edit_item_menu->append(*ccontainer_restock);
    
   Gtk::MenuItem *sscoop_restock = Gtk::manage(new Gtk::MenuItem("_SCOOP",true));
//Set call funcction for conatiner restock
   edit_item_menu->append(*sscoop_restock);

Gtk::MenuItem *ttopping_restock = Gtk::manage(new Gtk::MenuItem("_TOPPING",true));
//Set call funcction for conatiner restock
   edit_item_menu->append(*ttopping_restock);

    
    //Dlete item1
    Gtk::MenuItem *delete_item = Gtk::manage(new Gtk::MenuItem("_DELETE_ITEM", true));
//SET FUNCTION FOR DELETING item
    item_menu->append(*delete_item);
     Gtk::Menu *delete_item_menu = Gtk::manage(new Gtk::Menu());
   delete_item->set_submenu(*delete_item_menu);
    if(type == "server" || type=="customer"){ delete_item->set_sensitive(false);}

   //item choose
   Gtk::MenuItem *cccontainer_delete = Gtk::manage(new Gtk::MenuItem("_CONTAINER",true));
//Set call funcction for conatiner restock
   delete_item_menu->append(*cccontainer_delete);
    
   Gtk::MenuItem *ssscoop_delete= Gtk::manage(new Gtk::MenuItem("_SCOOP",true));
//Set call funcction for conatiner restock
   delete_item_menu->append(*ssscoop_delete);

Gtk::MenuItem *tttopping_delete = Gtk::manage(new Gtk::MenuItem("_TOPPING",true));
//Set call funcction for conatiner restock
   delete_item_menu->append(*tttopping_delete);

   
    //see REPORTS
    Gtk::MenuItem *menuitem_report = Gtk::manage(new Gtk::MenuItem("_REPORTS",true));
    menubar->append(*menuitem_report);
    Gtk::Menu *report_menu = Gtk::manage(new Gtk::Menu());
    menuitem_report->set_submenu(*report_menu);
    if(type=="customer"){ menuitem_report->set_sensitive(false);}

    
    //Financial Report
    Gtk::MenuItem *financial_report = Gtk::manage(new Gtk::MenuItem("_FINANCIAL_REPORT",true));
    financial_report->signal_activate().connect(sigc::mem_fun(*this, &Windows::show_financial));     
    report_menu->append(*financial_report);
     if(type == "server" || type=="customer"){ financial_report->set_sensitive(false);}

    //Server Report
   Gtk::MenuItem *serverr_report = Gtk::manage(new Gtk::MenuItem("_SERVER_REPORT",true));
//set call function for financial report    
    report_menu->append(*serverr_report);
     if(type == "server" || type=="customer"){ serverr_report->set_sensitive(false);}
    

   //Item Report
   Gtk::MenuItem *itemm_report = Gtk::manage(new Gtk::MenuItem("_ITEM_INVENTORY_REPORT",true));
   itemm_report->signal_activate().connect(sigc::mem_fun(*this, &Windows::show_inventory));  
    report_menu->append(*itemm_report);
   
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar);

     //     C R E A T E   O R D E R
    // Add a Create Order icon
    Gtk::Image *create_order_button_image = Gtk::manage(new Gtk::Image("create_order.jpg"));
    Gtk::ToolButton *create_order_button = Gtk::manage(new Gtk::ToolButton(*create_order_button_image));
    create_order_button->set_tooltip_markup("Create a new order");
    create_order_button->signal_clicked().connect(sigc::mem_fun(*this, &Windows::create_new_order_click));
    toolbar->append(*create_order_button);

    // Add a Show Inventory icon
    Gtk::Image *create_inventory_button_image = Gtk::manage(new Gtk::Image("inventory1.jpg"));
    Gtk::ToolButton *create_inventory_button = Gtk::manage(new Gtk::ToolButton(*create_inventory_button_image));
    create_inventory_button->set_tooltip_markup("SHOW INVENTORY REPORT");
    create_inventory_button->signal_clicked().connect(sigc::mem_fun(*this, &Windows::show_inventory));
    toolbar->append(*create_inventory_button);
    
    // Add a Show financial icon
    Gtk::Image *create_financial_button_image = Gtk::manage(new Gtk::Image("financial.jpg"));
    Gtk::ToolButton *create_financial_button = Gtk::manage(new Gtk::ToolButton(*create_financial_button_image));
    create_financial_button->set_tooltip_markup("SHOW FINANCIAL REPORT");
    create_financial_button->signal_clicked().connect(sigc::mem_fun(*this, &Windows::show_financial));
    toolbar->append(*create_financial_button);
    if(type == "customer" || type == "server"){create_financial_button->set_sensitive(financial_report->get_sensitive());}

     //Add ITEM BUTTON
   // Add a Create customer icon
    Gtk::Image *create_item_button_image = Gtk::manage(new Gtk::Image("add_item.jpg"));
    Gtk::ToolButton *create_item_button = Gtk::manage(new Gtk::ToolButton(*create_item_button_image));
    create_item_button->set_tooltip_markup("Create a NEW ITEM");
    create_item_button->signal_clicked().connect(sigc::mem_fun(*this, &Windows::create_new_item_click));
    toolbar->append(*create_item_button);
    if(type == "customer"){    create_item_button->set_sensitive(false); }
    
    
    //Order Status
    Gtk::Image *create_order_status_button_image = Gtk::manage(new Gtk::Image("order_status.jpg"));
    Gtk::ToolButton *create_order_status_button = Gtk::manage(new Gtk::ToolButton(*create_order_status_button_image));
    create_order_status_button->set_tooltip_markup("SEE ORDER STATUS");
    create_order_status_button->signal_clicked().connect(sigc::mem_fun(*this, &Windows::order_state_order_click));
    toolbar->append(*create_order_status_button);
    //if(type == "customer"){    create_item_button->set_sensitive(false); }
    

       
     //     C R E A T E   customer
    // Add a Create customer icon
    Gtk::Image *create_customer_button_image = Gtk::manage(new Gtk::Image("customer.jpg"));
    Gtk::ToolButton *create_customer_button = Gtk::manage(new Gtk::ToolButton(*create_customer_button_image));
    create_customer_button->set_tooltip_markup("Create a NEW CUSTOMER");
    create_customer_button->signal_clicked().connect(sigc::mem_fun(*this, &Windows::create_new_customer_click));
    toolbar->append(*create_customer_button);
    if(type == "customer"){    create_customer_button->set_sensitive(false); }
   
    // Create Server
    Gtk::Image *create_server_button_image = Gtk::manage(new Gtk::Image("server.jpg"));
    Gtk::ToolButton *create_server_button = Gtk::manage(new Gtk::ToolButton(*create_server_button_image));
    create_server_button->set_tooltip_markup("Create a NEW SERVER");
    create_server_button->signal_clicked().connect(sigc::mem_fun(*this, &Windows::create_new_server_click));
    toolbar->append(*create_server_button);
    if(type == "customer" || type == "server"){create_server_button->set_sensitive(financial_report->get_sensitive());}
    // Create Manager
    Gtk::Image *create_manager_button_image = Gtk::manage(new Gtk::Image("manager.jpg"));
    Gtk::ToolButton *create_manager_button = Gtk::manage(new Gtk::ToolButton(*create_manager_button_image));
    create_manager_button->set_tooltip_markup("Create a NEW MANAGER");
    create_manager_button->signal_clicked().connect(sigc::mem_fun(*this, &Windows::create_new_manager_click));
    toolbar->append(*create_manager_button);
    if(type == "customer" || type == "server" || type == "manager"){create_manager_button->set_sensitive(false);}

     //     Q U I T
    // Add a icon for quitting
    Gtk::ToolButton *quit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
    quit_button->set_tooltip_markup("Exit MICE");
    quit_button->signal_clicked().connect(sigc::mem_fun(*this, &Windows::on_quit_click));
    Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
    sep->set_expand(true);  // The expanding sep forces the Quit button to the right
    toolbar->append(*sep);
    toolbar->append(*quit_button);
    //show all
    vbox->show_all();
}
 Windows::~Windows() { }

 void Windows::pay_server_click()
 {
    int result;
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_default_size(200, 110);
    dialog->set_title("CHOOSE SERVER TO PAY ");
   
    //Chossing the Container
    Gtk::HBox b_container;

    Gtk::Label l_container{"SERVER"};
    l_container.set_width_chars(22);
    b_container.pack_start(l_container, Gtk::PACK_SHRINK);

    Gtk::ComboBoxText c_container;
    c_container.set_size_request(160);
    for(int i=0; i<server.size();i++)
    {
      c_container.append(server[i].get_name());
    }
    b_container.pack_start(c_container, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_container, Gtk::PACK_SHRINK);
     
    // Show dialog
    dialog->add_button("Cancel", 0);
    dialog->add_button("GET SERVER PAY", 1);
    dialog->show_all();
    result = dialog->run();
    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();
    if( result == 1)
    {
      double total = server[c_container.get_active_row_number()].total_salary();
       
      string messaage = server[c_container.get_active_row_number()].get_name()+ " total is $"+to_string(total)+"\nClick PAY to pay to the server";
      Gtk::MessageDialog *message = Gtk::manage (new Gtk::MessageDialog{messaage});
      message->add_button("Cancel",0);
      message->add_button("PAY", 1);
      int choice = message->run();
      message->close();
      while (Gtk::Main::events_pending())  Gtk::Main::iteration();
      if( choice = 1)
      { 
          server[c_container.get_active_row_number()].set_orders();
          fstream file;
                         try
                         {
                              //filling conatiner data
                              
                              file.open("Cost.txt",ios_base::app);
                              string line="SERVER PAID\n"+ to_string(total)+"\n";
                              file<<line;
                              file.close();
                            Gtk::MessageDialog *message = Gtk::manage (new Gtk::MessageDialog{"SERVER PAID"});
                              message->run();
                              message->close();
                              while (Gtk::Main::events_pending())  Gtk::Main::iteration();
                         }
                         catch(...)
                         { cerr<<"file not found error"<<endl;}
 
       }
    }
 }
 void Windows::show_financial()
 {
   fstream file;
   int c =0;
   string line;
   string ORDER="",CUSTOMER="",COST = "",PROFIT = "",SERVER_ID="";
   double cost =0; double profit =0;
   //Getting Conatiner data
   file.open("Profit.txt", ios_base::in);
   while(getline(file,line))
   {
    if(c == 0){ORDER +="ORDER "+ line+"\n"; c++;}
    else if(c == 1){CUSTOMER += line+"\n";c++;}
    else if(c == 2){SERVER_ID += line+"\n";c++;}
    else if(c == 3){COST += line+"\n";cost += stod(line);c++;}
    else if(c == 4){PROFIT += line+"\n";profit += stod(line);c = 0;}
   }
   file.close();
    
   c =0;
   string TYPE="",COST_I = "", statement;
   cost =0; 
   //Getting Conatiner data
   file.open("Cost.txt", ios_base::in);
   while(getline(file,line))
   {
    if(c == 0){TYPE +=line+"\n"; c++;}
    else if(c == 1){COST_I += line+"\n";cost+=stod(line);c = 0;}
   }
   file.close();
   if(cost > profit){statement = "\nYou have to sell more products as shop is in depth of $"+to_string(cost-profit)+".\n";}
   else {statement = "\nShop is doing good with the profit of $"+to_string(profit-cost)+", KEEP IT UP:):)\n";}
   
    Gtk::Dialog *dialog = Gtk::manage (new Gtk::Dialog());
    dialog->set_default_size(640, 500);
    dialog->set_title("PROFIT_LOSS_REPORT");
  
    
    Gtk::HBox b_cost;
    Gtk::Label l_c_type{"TOTAL COST FROM ITEM and SERVER"};
    l_c_type.set_width_chars(60);
    b_cost.pack_start(l_c_type, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_cost, Gtk::PACK_SHRINK);
    
      
    Gtk::HBox b_cost_type;
    Gtk::Label l_cC_type{"INVESTMENT TYPE"};
    l_cC_type.set_width_chars(30);
    b_cost_type.pack_start(l_cC_type, Gtk::PACK_SHRINK);
    
    Gtk::Label l_cCc_type{"INVESTMENT COST"};
    l_cCc_type.set_width_chars(30);
    b_cost_type.pack_start(l_cCc_type, Gtk::PACK_SHRINK);
    
    dialog->get_vbox()->pack_start(b_cost_type, Gtk::PACK_SHRINK);
    
    
    Gtk::HBox b_cost_cost;
    
    Gtk::Label l_cb_type{TYPE};
    l_cb_type.set_width_chars(30);
    b_cost_cost.pack_start(l_cb_type, Gtk::PACK_SHRINK);
    
    Gtk::Label l_cbc_type{COST_I};
    l_cbc_type.set_width_chars(30);
    b_cost_cost.pack_start(l_cbc_type, Gtk::PACK_SHRINK);
    
    dialog->get_vbox()->pack_start(b_cost_cost, Gtk::PACK_SHRINK);
    
    Gtk::HBox b_order;
    Gtk::Label l_o_type{"TOTAL PROFIT FROM ORDERS"};
    l_o_type.set_width_chars(60);
    b_order.pack_start(l_o_type, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_order, Gtk::PACK_SHRINK);
        
    Gtk::HBox b_inventory;
     
     Gtk::Label l_I_type{"\nORDER_NO"};
     l_I_type.set_width_chars(30);
     b_inventory.pack_start(l_I_type, Gtk::PACK_SHRINK);
     
     Gtk::Label l_I_name{"\nCUSTOMER_NAME"};
     l_I_name.set_width_chars(30);
     b_inventory.pack_start(l_I_name, Gtk::PACK_SHRINK);
     
     Gtk::Label l_I_descrip{"\nSERVER_ID"};
     l_I_descrip.set_width_chars(30);
     b_inventory.pack_start(l_I_descrip, Gtk::PACK_SHRINK);
     
     Gtk::Label l_I_price{"\nORDER_PROFIT"};
     l_I_price.set_width_chars(30);
     b_inventory.pack_start(l_I_price, Gtk::PACK_SHRINK);
     
     dialog->get_vbox()->pack_start(b_inventory, Gtk::PACK_SHRINK);
    
     Gtk::HBox b_container;
     
     Gtk::Label l_type{ORDER};
     l_type.set_width_chars(30);
     b_container.pack_start(l_type, Gtk::PACK_SHRINK);
     
     Gtk::Label l_name{CUSTOMER};
     l_name.set_width_chars(30);
     b_container.pack_start(l_name, Gtk::PACK_SHRINK);
     
     Gtk::Label l_descrip{SERVER_ID};
     l_descrip.set_width_chars(30);
     b_container.pack_start(l_descrip, Gtk::PACK_SHRINK);
     
     Gtk::Label l_cost{PROFIT};
     l_cost.set_width_chars(30);
     b_container.pack_start(l_cost, Gtk::PACK_SHRINK);
     dialog->get_vbox()->pack_start(b_container, Gtk::PACK_SHRINK);
    
     Gtk::HBox b_Oorder;
     Gtk::Label l_Oo_type{("\nTOTAL PROFIT FROM ORDERS IS $"+to_string(profit)+".\n")};
     l_Oo_type.set_width_chars(60);
     b_Oorder.pack_start(l_Oo_type, Gtk::PACK_SHRINK);
     dialog->get_vbox()->pack_start(b_Oorder, Gtk::PACK_SHRINK);
    
     
    Gtk::HBox b_statement;
    Gtk::Label l_statement{statement};
    l_statement.set_width_chars(100);
    b_statement.pack_start(l_statement, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_statement, Gtk::PACK_SHRINK);
    
    dialog->add_button("OK", 1);
    dialog->show_all();
    dialog->run();
    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();
 }
 void Windows::show_inventory()
 {
   int c = containers.size();
   int s = scoops.size();
   int t = toppings.size();
  
   string type="";string name=""; string cost=""; string price=""; string quantity="";string description="";
   Gtk::Dialog *dialog = Gtk::manage (new Gtk::Dialog());
   dialog->set_default_size(640, 500);
   dialog->set_title("INVENTORY REPORT");
   
   Gtk::HBox b_inventory;
     
     Gtk::Label l_I_type{"TYPE"};
     l_I_type.set_width_chars(30);
     b_inventory.pack_start(l_I_type, Gtk::PACK_SHRINK);
     
     Gtk::Label l_I_name{"NAME"};
     l_I_name.set_width_chars(30);
     b_inventory.pack_start(l_I_name, Gtk::PACK_SHRINK);
     
     Gtk::Label l_I_descrip{"DESCRIPTION"};
     l_I_descrip.set_width_chars(60);
     b_inventory.pack_start(l_I_descrip, Gtk::PACK_SHRINK);
     
     Gtk::Label l_I_cost{"COST"};
     l_I_cost.set_width_chars(20);
     b_inventory.pack_start(l_I_cost, Gtk::PACK_SHRINK);
     
     Gtk::Label l_I_price{"PRICE"};
     l_I_price.set_width_chars(20);
     b_inventory.pack_start(l_I_price, Gtk::PACK_SHRINK);
     
     Gtk::Label l_I_quantity{"QUANTITY"};
     l_I_quantity.set_width_chars(20);
     b_inventory.pack_start(l_I_quantity, Gtk::PACK_SHRINK);
     dialog->get_vbox()->pack_start(b_inventory, Gtk::PACK_SHRINK);
    
     
   //Gtk::VBox v_container;
   for( int i=0;i<c;i++)
   {
     type += containers[i].type()+"\n";
     name += containers[i].name()+"\n";
     description +=containers[i].description()+"\n";
     cost += to_string(containers[i].cost())+"\n";
     price += to_string(containers[i].price())+"\n";
     quantity +=to_string(containers[i].quantity())+"\n";
   }
   
    for( int i=0;i<s;i++)
   {
     description +=scoops[i].description()+"\n";
     type += scoops[i].type()+"\n";
     name += scoops[i].name()+"\n";
     cost += to_string(scoops[i].cost())+"\n";
     price += to_string(scoops[i].price())+"\n";
     quantity +=to_string(scoops[i].quantity())+"\n";
   }
   
   for( int i=0;i<t;i++)
   {
     description +=toppings[i].description()+"\n";
     type += toppings[i].type()+"\n";
     name += toppings[i].name()+"\n";
     cost += to_string(toppings[i].cost())+"\n";
     price += to_string(toppings[i].price())+"\n";
     quantity +=to_string(toppings[i].quantity())+"\n";
   }
   
   
     Gtk::HBox b_container;
     
     Gtk::Label l_type{type};
     l_type.set_width_chars(30);
     b_container.pack_start(l_type, Gtk::PACK_SHRINK);
     
     Gtk::Label l_name{name};
     l_name.set_width_chars(30);
     b_container.pack_start(l_name, Gtk::PACK_SHRINK);
     
     Gtk::Label l_descrip{description};
     l_descrip.set_width_chars(60);
     b_container.pack_start(l_descrip, Gtk::PACK_SHRINK);
     
     Gtk::Label l_cost{cost};
     l_cost.set_width_chars(20);
     b_container.pack_start(l_cost, Gtk::PACK_SHRINK);
     
     Gtk::Label l_price{price};
     l_price.set_width_chars(20);
     b_container.pack_start(l_price, Gtk::PACK_SHRINK);
     
     Gtk::Label l_quantity{quantity};
     l_quantity.set_width_chars(20);
     b_container.pack_start(l_quantity, Gtk::PACK_SHRINK);
     dialog->get_vbox()->pack_start(b_container, Gtk::PACK_SHRINK);
    
    dialog->add_button("OK", 1);
    dialog->show_all();
    dialog->run();
    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();
          
 }
 void Windows::save_data()
 { 
   empo.fill_data();
   int c = containers.size();
   for(int i=0;i<c;i++)
   {
     empo.update_container(containers[i]);
   }
   
   c = scoops.size();
    for(int i=0;i<c;i++)
   {
     empo.update_scoop(scoops[i]);
   }
   
   c = toppings.size();
    for(int i=0;i<c;i++)
   {
     empo.update_topping(toppings[i]);
   }
   
   c = server.size();
    for(int i=0;i<c;i++)
   {
     empo.update_server(server[i]);
   }
   
   c = manager.size();
    for(int i=0;i<c;i++)
   {
     empo.update_manager(manager[i]);
   }

   c = customer.size();
    for(int i=0;i<c;i++)
   {
     empo.update_customer(customer[i]);
   }
 }
 void Windows::restock_container()
 {
    int result = 1;
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_default_size(400, 110);
    dialog->set_title("CHOOSE CONTAINER FOR RESTOCK ");
   
    //Chossing the Container
    Gtk::HBox b_container;

    Gtk::Label l_container{"Container"};
    l_container.set_width_chars(22);
    b_container.pack_start(l_container, Gtk::PACK_SHRINK);

    Gtk::ComboBoxText c_container;
    c_container.set_size_request(160);
    for(int i=0; i<containers.size();i++)
    {
      c_container.append(containers[i].name());
    }
    b_container.pack_start(c_container, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_container, Gtk::PACK_SHRINK);
     
    Gtk::HBox b_quantity;

    Gtk::Label l_quantity{"Enter The Quantity"};
    l_quantity.set_width_chars(22);
    b_quantity.pack_start(l_quantity, Gtk::PACK_SHRINK);

    Gtk::Entry *e_quantity = Gtk::manage (new Gtk::Entry{});
    e_quantity->set_max_length(20);
    b_quantity.pack_start(*e_quantity, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_quantity, Gtk::PACK_SHRINK);
     
    // Show dialog
    dialog->add_button("Cancel", 0);
    dialog->add_button("ADD STOCK", 1);
    dialog->show_all();
    while(result)
    {
      if(dialog->run() == 1)
      {
       try{
            int quantity = stoi(e_quantity->get_text());
            containers[c_container.get_active_row_number()].restock(quantity);
            result =0;
            dialog->close();
            while (Gtk::Main::events_pending())  Gtk::Main::iteration();
            double overall_cost = containers[c_container.get_active_row_number()].cost()*(double)quantity;
            fstream file;
                         try
                         {
                              //filling conatiner data
                              
                              file.open("Cost.txt",ios_base::app);
                              string line="Item Restock\n"+ to_string(overall_cost)+"\n";
                              file<<line;
                              file.close();
				if(type == "server"){ for(int i=0;i<4;i++){server[position].server_order_fill();}}
                         }
                         catch(...)
                         { cerr<<"file not found error"<<endl;}
           }
       catch(...)
       { 
         e_quantity->set_text("**Invalid Input**");dialog->close();
         while (Gtk::Main::events_pending())  Gtk::Main::iteration();
       }
     }
      else{result =0; break;}
    }
 }
 void Windows::restock_scoop()
 {
  int result = 1;
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_default_size(400, 110);
    dialog->set_title("CHOOSE SCOOP FOR RESTOCK ");
   
    //Chossing the Container
    Gtk::HBox b_container;

    Gtk::Label l_container{"Scoop"};
    l_container.set_width_chars(22);
    b_container.pack_start(l_container, Gtk::PACK_SHRINK);

    Gtk::ComboBoxText c_container;
    c_container.set_size_request(160);
    for(int i=0; i<scoops.size();i++)
    {
      
      c_container.append(scoops[i].name());
    }
    b_container.pack_start(c_container, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_container, Gtk::PACK_SHRINK);
     
    Gtk::HBox b_quantity;

    Gtk::Label l_quantity{"Enter The Quantity"};
    l_quantity.set_width_chars(22);
    b_quantity.pack_start(l_quantity, Gtk::PACK_SHRINK);

    Gtk::Entry *e_quantity = Gtk::manage (new Gtk::Entry{});
    e_quantity->set_max_length(20);
    b_quantity.pack_start(*e_quantity, Gtk::PACK_SHRINK);
     dialog->get_vbox()->pack_start(b_quantity, Gtk::PACK_SHRINK);
    // Show dialog
    dialog->add_button("Cancel", 0);
    dialog->add_button("ADD STOCK", 1);
    dialog->show_all();
    while(result)
    {
      if(dialog->run() == 1)
      {
       try{
            int quantity = stoi(e_quantity->get_text());
            scoops[c_container.get_active_row_number()].restock(quantity);
            result =0;
            dialog->close();
            while (Gtk::Main::events_pending())  Gtk::Main::iteration();
             double overall_cost = scoops[c_container.get_active_row_number()].cost()*(double)quantity;
            fstream file;
                         try
                         {
                              //filling conatiner data
                              
                              file.open("Cost.txt",ios_base::app);
                              string line="Item Restock\n"+ to_string(overall_cost)+"\n";
                              file<<line;
                              file.close();
                              if(type == "server"){ for(int i=0;i<4;i++){server[position].server_order_fill();}}
                         }
                         catch(...)
                         { cerr<<"file not found error"<<endl;}
           }
       catch(...)
       { 
         e_quantity->set_text("**Invalid Input**");dialog->close();
         while (Gtk::Main::events_pending())  Gtk::Main::iteration();
       }
     }
      else{result =0; break;}
    }
 }
 void Windows::restock_topping()
 {
  int result = 1;
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_default_size(400, 110);
    dialog->set_title("CHOOSE TOPPING FOR RESTOCK ");
   
    //Chossing the Container
    Gtk::HBox b_container;

    Gtk::Label l_container{"TOPPING"};
    l_container.set_width_chars(22);
    b_container.pack_start(l_container, Gtk::PACK_SHRINK);

    Gtk::ComboBoxText c_container;
    c_container.set_size_request(160);
    for(int i=0; i<toppings.size();i++)
    {
      c_container.append(toppings[i].name());
    }
    b_container.pack_start(c_container, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_container, Gtk::PACK_SHRINK);
    Gtk::HBox b_quantity;

    Gtk::Label l_quantity{"Enter The Quantity"};
    l_quantity.set_width_chars(22);
    b_quantity.pack_start(l_quantity, Gtk::PACK_SHRINK);

    Gtk::Entry *e_quantity = Gtk::manage (new Gtk::Entry{});
    e_quantity->set_max_length(20);
    b_quantity.pack_start(*e_quantity, Gtk::PACK_SHRINK);
     dialog->get_vbox()->pack_start(b_quantity, Gtk::PACK_SHRINK);
    // Show dialog
    dialog->add_button("Cancel", 0);
    dialog->add_button("ADD STOCK", 1);
    dialog->show_all();
    while(result)
    {
      if(dialog->run() == 1)
      {
       try{
            int quantity = stoi(e_quantity->get_text());
            toppings[c_container.get_active_row_number()].restock(quantity);
            result =0;
            dialog->close();
            while (Gtk::Main::events_pending())  Gtk::Main::iteration();
             double overall_cost = toppings[c_container.get_active_row_number()].cost()*(double)quantity;
            fstream file;
             try
                         {
                              //filling conatiner data
                              
                              file.open("Cost.txt",ios_base::app);
                              string line="Item Restock\n"+ to_string(overall_cost)+"\n";
                              file<<line;
                              file.close();
                              if(type == "server"){ for(int i=0;i<4;i++){server[position].server_order_fill();}}
                         }
                         catch(...)
                         { cerr<<"file not found error"<<endl;}
           }
       catch(...)
       { 
         e_quantity->set_text("**Invalid Input**");dialog->close();
         while (Gtk::Main::events_pending())  Gtk::Main::iteration();
       }
     }
      else{result =0; break;}
    }
 }
 void Windows::order_state_order_click()
 {
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_default_size(400, 110);
    dialog->set_title("CHOOSE ORDER TO SEE ITS STATE ");
   
    //Chossing the Container
    Gtk::HBox b_container;

    Gtk::Label l_container{"ORDERS"};
    l_container.set_width_chars(20);
    b_container.pack_start(l_container, Gtk::PACK_SHRINK);

    Gtk::ComboBoxText c_container;
    c_container.set_size_request(160);
    for(int i=0; i<order.size();i++)
    {
      c_container.append(("ORDER "+to_string(order[i].get_order_number())));
    }
    b_container.pack_start(c_container, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_container, Gtk::PACK_SHRINK);
     
    // Show dialog
      	dialog->add_button("SELECT", 1);
        dialog->show_all();
    	dialog->run();
    
    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();
    order[c_container.get_active_row_number()].show_order_status();    
 }
 void Windows::fill_order_click()
 {
    Server ser{"","",""};
    if(type == "server"){ ser = server[position];}
    else if(type == "manager"){ Server s{"manager","manager","manager"};ser =s;}
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_default_size(400, 110);
    dialog->set_title("CHOOSE ORDER TO FILL ");
   
    //Chossing the Container
    Gtk::HBox b_container;

    Gtk::Label l_container{"ORDERS"};
    l_container.set_width_chars(20);
    b_container.pack_start(l_container, Gtk::PACK_SHRINK);

    Gtk::ComboBoxText c_container;
    c_container.set_size_request(160);
    for(int i=0; i<order.size();i++)
    {
      if( order[i].order_status() == Order_state::Unfilled){
      c_container.append(("ORDER"+to_string(order[i].get_order_number())));
      }
    }
    b_container.pack_start(c_container, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_container, Gtk::PACK_SHRINK);
     
    // Show dialog
      	dialog->add_button("CANCEl", 0);
      	dialog->add_button("SELECT", 1);
        dialog->show_all();
    	int result = dialog->run();
    
    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();
    if(result == 1)
    {
      int orderee = c_container.get_active_row_number();
      int k=-1;
      for(int i=0; i<order.size();i++)
    {
      if( order[i].order_status() == Order_state::Unfilled)
      { k++; if(k == orderee){k=i;break;}      }
    }
       order[k].order_fill(ser);
    }
    
 }
 void Windows::pay_order_click()
 {
  Server ser{"","",""};
    if(type == "server"){ ser = server[position];}
    else if(type == "manager"){ Server s{"manager","manager","manager"};ser =s;}
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_default_size(400, 110);
    dialog->set_title("CHOOSE ORDER TO PAY ");
   
    //Chossing the Container
    Gtk::HBox b_container;

    Gtk::Label l_container{"ORDERS"};
    l_container.set_width_chars(20);
    b_container.pack_start(l_container, Gtk::PACK_SHRINK);

    Gtk::ComboBoxText c_container;
    c_container.set_size_request(160);
    for(int i=0; i<order.size();i++)
    {
      if( order[i].order_status() == Order_state::Filled){
      c_container.append(("ORDER"+to_string(order[i].get_order_number())));
      }
    }
    b_container.pack_start(c_container, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_container, Gtk::PACK_SHRINK);
     
    // Show dialog
      	dialog->add_button("CANCEl", 0);
      	dialog->add_button("SELECT", 1);
        dialog->show_all();
    	int result = dialog->run();
    
    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();
    if(result == 1)
    {
      int orderee = c_container.get_active_row_number();
      int k=-1;
      for(int i=0; i<order.size();i++)
    {
      if( order[i].order_status() == Order_state::Filled)
      { k++; if(k == orderee){k=i;break;}      }
    }
       order[k].order_pay(ser);
    }
 }

void Windows::create_new_manager_click()
{
  Create create{empo};
  Manager ser = create.create_new_manager();
  if(ser.get_name() != "")
  {
    manager.push_back(ser);
    Gtk::MessageDialog *message = Gtk::manage (new Gtk::MessageDialog{"MANAGER ADDED"});
    message->run();
    message->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();
  }
}

void Windows::create_new_server_click()
{
  Create create{empo};
  Server ser = create.create_new_server();
  if(ser.get_name() != "")
  {
    server.push_back(ser);
    Gtk::MessageDialog *message = Gtk::manage (new Gtk::MessageDialog{"SERVER ADDED"});
    message->run();
    message->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();
  }
}

void Windows::create_new_customer_click()
{
  Create create{empo};
  Customer cus = create.create_new_customer();
  if(cus.get_name() != "")
  {
    customer.push_back(cus);
    Gtk::MessageDialog *message =Gtk::manage ( new Gtk::MessageDialog{"CUSTOMER ADDED"});
    message->run();
    message->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();
  }
}


void Windows::create_new_item_click()
{   
    //Creating Dialog for choosing type
    int choice;
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_title("Choose the Type for ITEM");
    dialog->add_button("CONTAINER", 1);
    dialog->add_button("SCOOP", 2);
    dialog->add_button("TOPPING", 3);
    dialog->show_all();
    choice = dialog->run();
    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration(); 
    //End of the options

    //getting the input
    if(choice == 1)
    {
      Dialoged dial{"Container","NEW_CONTAINER_DETAIL"};
      string name= dial.get_name();
      string description = dial.get_description();
      double cost = dial.get_cost();
      double price = dial.get_price();
      int max_scoop = dial.get_max_scoop();
   //    Container(std::string name, std::string description, double cost, double price,
      //        int max_scoops);
      if(name != "" && price != 0)
      {
      Containerss contain{name, description, cost, price, max_scoop};
      empo.update_container(contain);
      containers.push_back(contain);
    //  contain.restock(50);
       }
    }
    else if(choice == 2)
    {
      Dialoged dial{"Scoop", "NEW_SCOOP_DETAILS"};
      string name = dial.get_name();
      double price =dial.get_price();
      if(name !="" && price != 0)
      {
       Scoop scop{name, dial.get_description(), dial.get_cost(), price};
       empo.update_scoop(scop);
       scoops.push_back(scop);
      //scop.restock(50);
      }
    }
    else if(choice == 3)
    { 
     // int topping_amount ;
      Dialoged dial{"Topping","NEW_TOPPING_DETAILS"};
      string name = dial.get_name();
      double price =dial.get_price();
      if(name !="" && price != 0)
      {
      Topping topping{dial.get_name(), dial.get_description(), dial.get_cost(), dial.get_price(), 4};
      empo.update_topping(topping);
      toppings.push_back(topping);
     // topping.restock(50);
      }
    }

}

void Windows::create_new_order_click()
{
    Customer customerr{"","",""};
  if(type == "customer")
  {
    customerr= customer[position];
  }
  else
  {
     Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_default_size(400, 110);
    dialog->set_title("CHOOSE CUSTOMER FOR ORDER: ");
   
    //Chossing the Container
    Gtk::HBox b_container;

    Gtk::Label l_container{"CHOOSE CUSTOMER"};
    l_container.set_width_chars(20);
    b_container.pack_start(l_container, Gtk::PACK_SHRINK);

    Gtk::ComboBoxText c_container;
    c_container.set_size_request(160);
    for(int i=0; i<customer.size();i++)
    {
      cout<<customer[i].get_phone()<<"      "<<customer[i].get_name()<<"\n"<<endl;
      c_container.append(customer[i].get_name());
    }
    b_container.pack_start(c_container, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_container, Gtk::PACK_SHRINK);
     
    // Show dialog
      	dialog->add_button("OLD CUSTOMER", 0);
      	dialog->add_button("ADD NEW CUSTOMER", 1);
    
        dialog->add_button("CONTINUE AS A GUEST", 2);
    	dialog->show_all();
    	int resultss = dialog->run();
    
    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();
    if(resultss == 0){ customerr = customer[c_container.get_active_row_number()];}
    else if(resultss == 1){Create created{empo};  customerr = created.create_new_customer(); customer.push_back(customerr);}
    else if(resultss == 2){Customer customss{"guest","guest","customer"}; customerr = customss;}
  }
  int value = 0;
  int num_serving =0;
  int final_choice = 0;
  string serves="";
  bool choices = true;
  while(choices)
  {
     if(value == 0)
     {   
       create_new_serving_click(num_serving+1);
       value++;
     }
     if(value > 0 && serving.size()>0)
     {          
             
          if(serving[num_serving].serving_total() == 0)
           {
            serving.pop_back();
            num_serving--;
           }
           else
           {
             serves += "\n"+serving[num_serving].get_serving();}
             num_serving++;
             Gtk::Dialog *ddialog = Gtk::manage(new Gtk::Dialog());
             ddialog->set_default_size(400, 150);
             ddialog->set_title("CREATE ORDER");
             Gtk::HBox b_show;

             Gtk::Label l_show{serves};
             l_show.set_width_chars(100);
             b_show.pack_start(l_show, Gtk::PACK_SHRINK);
             ddialog->get_vbox()->pack_start(b_show, Gtk::PACK_SHRINK);
             
   
             ddialog->add_button("ADD MORE SERVING",1);
             
             ddialog->add_button("Cancel",0);
             ddialog->add_button("FINALIZE and VIEW ORDER",2);
             ddialog->show_all();
             final_choice = ddialog->run();

             ddialog->close();
             while (Gtk::Main::events_pending())  Gtk::Main::iteration();
             if(final_choice == 1)
             { value =0; choices= true;}
             else
             { choices = false;}                 
            } 
   }
  if(final_choice == 2 && serving.size() !=0)
  {  
    order_number++;  
   // int order_num ;
   // if(order.size() == 0){ order_num =1;}
   // else { order_num = (order[(order.size()-1)].get_order_number())./+1;}
    Server ser{"","",""};
    if(type == "server"){ ser = server[position];}
    else if(type == "manager"){ Server s{"manager","manager","manager"};ser =s;}
    Order order1{customerr,serving, order_number,ser};
    Order_state o_confirm = order1.confirm_order();
    if(o_confirm == Order_state::Unfilled)
     {
      order.push_back(order1);
      empo.update_order(order1);
      Gtk::MessageDialog *message = Gtk::manage (new Gtk::MessageDialog{"ORDER CONFIRMED"});
      message->run();
      message->close();
      while (Gtk::Main::events_pending())  Gtk::Main::iteration(); 
      final_choice = 2;
     }
     else { final_choice =0; order_number--;}
    serving.clear();
  }
   if(final_choice == 0)
  {
     Gtk::MessageDialog *message = Gtk::manage (new Gtk::MessageDialog{"ORDER CANCELED"});
     message->run();
     message->close();
     while (Gtk::Main::events_pending())  Gtk::Main::iteration(); 
  }


}
void Windows::create_new_serving_click(int n)
{
    int container;
    vector<Scoop> scoop;
    vector<Topping> topping;
    //Creating Dialog for Creating Serving
    Gtk::Dialog *dialog = new Gtk::Dialog();
    dialog->set_default_size(400, 110);
    dialog->set_title("CHOOSE CONTAINER FOR ORDER SERVING "+to_string(n));
   
    //Chossing the Container
    Gtk::HBox b_container;

    Gtk::Label l_container{"Container"};
    l_container.set_width_chars(20);
    b_container.pack_start(l_container, Gtk::PACK_SHRINK);

    Gtk::ComboBoxText c_container;
    c_container.set_size_request(160);
    for(int i=0; i<containers.size();i++)
    {
      if(containers[i].quantity() > 0)
      {
        c_container.append(containers[i].name()); 
      }
    }
    b_container.pack_start(c_container, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_container, Gtk::PACK_SHRINK);
     
    // Show dialog
    if(n == 1)
    {
     	dialog->add_button("Cancel", 0);
    }
    else 
    {
     	dialog->add_button("Cancel Serving", 0);
    }
        dialog->add_button("ADD SCOOPS", 1);
    	dialog->show_all();
    	int result = dialog->run();
    
    dialog->close();
    while (Gtk::Main::events_pending())  Gtk::Main::iteration();
    //Taking care of the cancel button
    int RESULT = 0;
    int result2 = 0;
    if(result == 1){RESULT =1;}
    if(RESULT == 1)
    {  
       container =  c_container.get_active_row_number();
       bool choice = true;
       int choices =0;
      // int result2 =0;
         while(choice)
          {  result2 =0;
             //Creating Dialog for Creating Serving
             Gtk::Dialog *dialog = new Gtk::Dialog();
             dialog->set_default_size(400, 100);
             dialog->set_title("CHOOSE SCOOPS FOR SERVING "+to_string(n));
   
             //Chossing the sccop
             Gtk::HBox b_scoop;

             Gtk::Label l_scoop{"FLAVORS"};
             l_scoop.set_width_chars(20);
             b_scoop.pack_start(l_scoop, Gtk::PACK_SHRINK);

             Gtk::ComboBoxText c_scoop;
             c_scoop.set_size_request(160);
             for(int i=0; i<scoops.size();i++)
             {
               if(scoops[i].quantity() > 0){
               c_scoop.append(scoops[i].name());}
             }
             b_scoop.pack_start(c_scoop, Gtk::PACK_SHRINK);
             dialog->get_vbox()->pack_start(b_scoop, Gtk::PACK_SHRINK);
     
             // Show dialog
             dialog->add_button("Cancel", 0);
             if(choices < (containers[container].max_scoops()-1)){
             dialog->add_button("ADD ADDITIONAL SCOOP", 1);}
             dialog->add_button("ADD TOPPINGS",2);
             dialog->add_button("ORDER WITHOUT TOPPING",3);
             dialog->show_all();
             result2 = dialog->run();

             dialog->close();
             while (Gtk::Main::events_pending())  Gtk::Main::iteration();
             if(result2 == 1)
             {  
               scoop.push_back(scoops[c_scoop.get_active_row_number()]);
               choices++;
               choice = true;               
             }
	     else if(result2 == 2 || result2 == 3)
             {
              scoop.push_back(scoops[c_scoop.get_active_row_number()]);
              result = 1;
              choice = false;
             }
             else {result =0;choice = false;}         
         }
       if(result2 == 2 ){RESULT =1;}else{RESULT = 0;}
       if(RESULT ==1)
       { 
          
          choices = 0;
          int result4 =0;
          bool top_choice =true;
          while(top_choice)
          {  
             //Creating Dialog for Creating Serving
             Gtk::Dialog *dialog = Gtk::manage(new Gtk::Dialog());
             dialog->set_default_size(400, 150);

             dialog->set_title("CHOOSE TOPPING FOR SERVING "+to_string(n));
   
             //Chossing the topping
             Gtk::HBox b_topping;

             Gtk::Label l_topping{"TOPPING"};
             l_topping.set_width_chars(20);
             b_topping.pack_start(l_topping, Gtk::PACK_SHRINK);

             Gtk::ComboBoxText c_topping;
             c_topping.set_size_request(160);
             for(int i=0; i<toppings.size();i++)
             {
               if(toppings[i].quantity() > 0){  c_topping.append(toppings[i].name());}
             }
              b_topping.pack_start(c_topping, Gtk::PACK_SHRINK);
             dialog->get_vbox()->pack_start(b_topping, Gtk::PACK_SHRINK);
             
             //if type is tooping
               
             //Chosing amount              
	        Gtk::HBox b_amount;
              Gtk::Label l_amount{"Amount"};
              l_amount.set_width_chars(20);
              b_amount.pack_start(l_amount, Gtk::PACK_SHRINK);

              Gtk::ComboBoxText c_amount;
              c_amount.set_size_request(160);
              c_amount.append("LIGHT_AMOUNT");
              c_amount.append("NORMAL_AMOUNT");
              c_amount.append("EXTRA_AMOUNT");
              c_amount.append("DRENCHED_AMOUNT");
              b_amount.pack_start(c_amount, Gtk::PACK_SHRINK);
              dialog->get_vbox()->pack_start(b_amount, Gtk::PACK_SHRINK); 

              
              // Show dialog
             dialog->add_button("Cancel", 0);
             if(choices < 4)
             {
             dialog->add_button("ADD ADDITIONAL TOPPING", 1);
             }             
             dialog->add_button("Finalize SERVING",2);
             dialog->show_all();
             result4 = dialog->run();

             dialog->close();
             while (Gtk::Main::events_pending())  Gtk::Main::iteration();
             if(result4 == 1)
             {
               
               topping.push_back(toppings[c_topping.get_active_row_number()]);
               topping[choices]._set_amount(c_amount.get_active_row_number()+1);
               top_choice = true;
               choices++;
             } 
            else if(result4 == 2)
             {
               topping.push_back(toppings[c_topping.get_active_row_number()]);
               topping[choices]._set_amount(c_amount.get_active_row_number()+1);
               result = 1;
               top_choice = false;
            }
            else {result =0; top_choice = false;}
        } 
      }
    }

   if(result == 1)
  {
    Serving serve{containers[container], scoop, topping};
    //Creating Dialog for Creating Serving
             Gtk::Dialog *confirm = Gtk::manage(new Gtk::Dialog());
             confirm->set_default_size(400, 150);

             confirm->set_title("CONFIRM SERVING "+to_string(n));
   
             //Chossing the topping
             Gtk::HBox b_confirm;

             Gtk::Label l_confirm{serve.get_serving()};
             l_confirm.set_width_chars(50);
             b_confirm.pack_start(l_confirm, Gtk::PACK_SHRINK);
             confirm->get_vbox()->pack_start(b_confirm, Gtk::PACK_SHRINK);
             confirm->add_button("Cancel",0);
             confirm->add_button("CONFIRM",1);
             confirm->show_all();
             int final_choice = confirm->run();

             confirm->close();
             while (Gtk::Main::events_pending())  Gtk::Main::iteration();
             if(final_choice == 1)
             {
                serving.push_back(serve);
             }
             else
             {result == 0;}
           
  }
   if(result == 0)
   {
     Containerss con{"","",0,0,0};
     vector<Scoop> sscoop;
     vector<Topping> ttopping;
     Serving serve{con, sscoop, ttopping};
     serving.push_back(serve);
   } 
}


void Windows::on_quit_click() {
    hide();
}

