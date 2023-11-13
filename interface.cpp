#include "interface.h"

string get_line(int i, string a, int line_num)
{
    if(i==0) getline(cin,a);
    else if(i==1)
    {
        ifstream filename;
        filename.open(_url);
        for(int k=0;k<line_num - 1;k++) getline(filename,a);
        getline(filename,a);
        filename.close();
    }
    return a;
}

Interface::~Interface()
{
    delete item_name; item_name = NULL;
    delete item_num; item_num = NULL;
    delete ctm_id; ctm_id = NULL;
    delete p; p = NULL;
    delete con; con = NULL;
    delete vTemp; vTemp = NULL;
    delete oTemp; oTemp = NULL;    
}

void Interface::new_customer(vector<customer> *c)
{
    cTemp->Input();
    c->push_back(*cTemp);
    delete cTemp;
    cTemp = NULL;
}

void Interface::new_item(vector<item> *i)
{        
    *_continue = iTemp->new_item();
    if(*_continue) i->push_back(*iTemp);
    delete iTemp; iTemp = NULL;
    delete _continue; _continue = NULL;
}

void Interface::list_all_customer(vector<customer> c)
{
    for(auto x : c)
        x.Output();
}

void Interface::list_all_item(vector<item> i)
{
    cout << "Item ID \t Name \t\t\t Price \t In stock \n" ;
    cout << "--------------------------------------------------\n";
    for(auto x : i)
        x.list_item();
}

void Interface::list_all_order(vector<order> o)
{
    for(auto x : o)
        x.list_order();
}

void Interface::make_new_order(vector<item> *i, vector<order> *o, vector<customer> *c)
{
    if(i->size() == 0) 
        {
            cout << "Item list is empty. Use (2) to insert item first\n\n";
            goto exitloop;
        }
    cout << "List of available items: \n";
    cout << "Item ID \t Name \t\t\t Price \t In stock \n" ;
    cout << "-----------------------------------------\n";
    for(auto x : *i)
        x.list_item();
    cout << "Type customer's ID (numbers only): "; cin >> *ctm_id;
    while(1)
    {
    cout << "Type item's name: ";
    cin.ignore(); getline(cin,*item_name);
    for(auto x : *i)
    { 
        if(x.get_name() == *item_name)  break;
        if(x.get_name() != *item_name && x.get_name() != i->back().get_name()) continue;
        else {
        cout << "\n\tItem not exits\n\n";
        goto exitloop; }
    }
    cout << "Quantities: "; cin >> *item_num;
    for(auto &x : *i)
    { 
        if(x.get_name() == *item_name)
        {
        if(x.get_quantities() >= *item_num) 
        {
            x.set_quantities(x.get_quantities() - *item_num);
            _total += *item_num * x.get_price();
            //cout << fixed << x.get_price() << "---" << *item_num<< endl;
            break;
        }
        cout << "\n\tItem " << *item_name << " have only " << x.get_quantities() << " in stock\n\n";
        goto exitloop;
        }
    }
    *p = make_pair(*item_name,*item_num);
    vTemp->push_back(*p);
    cout << "Continue shopping? (Y|N): "; cin >> *con;
    if(*con == "Y" || *con == "y") {continue;}
    else if(*con == "N" || *con == "n") {break;}
    else { cout << "Invalid input\n"; return ;}
    }
    oTemp = make_order(*ctm_id,*vTemp,c);
    cout << "Assigned order's ID: "  << oTemp->get_o_id() << endl;
    oTemp->set_total(_total);
    cout << "Total: " << fixed << setprecision(2) << _total << endl;
    oTemp->get_customer()->set_total_spent(_total + oTemp->get_customer()->get_total_spent() );
    o->push_back(*oTemp);
    exitloop:
    delete item_name; item_name = NULL;
    delete item_num; item_num = NULL;
    delete ctm_id; ctm_id = NULL;
    delete p; p = NULL;
    delete con; con = NULL;
    delete vTemp; vTemp = NULL;
    delete oTemp; oTemp = NULL;    
    _total = 0;
}

order* Interface::check_by_id(vector<order> o)
{
    cout << "Check by customer's ID: "; cin >> *ctm_id;
    for(auto x : o)
    if(x.get_customer()->get_c_id() == *ctm_id)
    oTemp = search_by_c_id(*ctm_id);
    return oTemp;
}




