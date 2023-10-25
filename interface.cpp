#include "interface.h"

void interface()
{
    item *a = new item("dildo",100,49999);
    _it.push_back(*a);
    a = new item("pocket pussy",100,599999);
    _it.push_back(*a);
    a = new item("porn tape",100,99999);
    _it.push_back(*a);
    customer *b = new customer("nguyen van a","TMA","911");
    _cs.push_back(*b);
    delete a; a = NULL;
    delete b; b = NULL;
    int _choice = 0;
    while(1)
    {
        cout << "=============MENU==============\n";
        cout << "1/ New customer\n";
        cout << "2/ New item\n";
        cout << "3/ List all customers\n";
        cout << "4/ List all items\n";
        cout << "5/ List all orders\n";
        cout << "6/ Make a new order\n";
        cout << "7/ Check order by customer ID\n";
        cout << "0/ Exit\n";
        cout << "===============================\n";
        cout << "Select a function: "; cin >> _choice;
        customer *cTemp = new customer;
        item *iTemp = new item;
        order *oTemp = new order;
        string *item_name = new string;
        char *con = new char;
        int *item_num = new int;
        long long *ctm_id = new long long;
        pair<string,int> *p = new pair<string,int>;
        vector<pair<string,int>> *vTemp = new vector<pair<string,int>>;
        bool *_continue = new bool;
        float *_total = new float;
        switch(_choice)
        {
            case 1:
                system("clear");
                cTemp->Input();
                _cs.push_back(*cTemp);
                delete cTemp;
                cTemp = NULL;
                break;
            case 2:
                system("clear");
                *_continue = iTemp->new_item();
                if(*_continue) _it.push_back(*iTemp);
                delete iTemp; iTemp = NULL;
                delete _continue; _continue = NULL;
                break;
            case 3:
                system("clear");
                for(auto x : _cs)
                 x.Output();
                break;
            case 4:
                system("clear");
                cout << "Item ID \t Name \t\t Price \t In stock \n" ;
                cout << "-----------------------------------------\n";
                for(auto x : _it)
                    x.list_item();
                break;
            case 5:
                system("clear");
                for(auto x : _ord)
                    x.list_order();
                break;
            case 6:
                system("clear");
                if(_it.size() == 0) 
                    {
                        cout << "Item list is empty. Use (2) to insert item first\n\n";
                        goto exitloop;
                    }
                cout << "List of available items: \n";
                cout << "Item ID \t Name \t\t Price \t In stock \n" ;
                cout << "-----------------------------------------\n";
                for(auto x : _it)
                    x.list_item();
                cout << "Type customer id: "; cin >> *ctm_id;
                while(1)
                {
                cout << "Type item's name: ";
                cin.ignore(); getline(cin,*item_name);
                for(auto x : _it)
                { 
                    if(x.get_name() == *item_name) break;
                    else continue;
                    cout << "\n\tItem not exits\n\n";
                    goto exitloop;
                }
                cout << "Quantities: "; cin >> *item_num;
                for(auto &x : _it)
                { 
                    if(x.get_name() == *item_name)
                    {
                    if(x.get_quantities() >= *item_num) 
                    {
                        x.set_quantities(x.get_quantities() - *item_num);
                        *_total = *item_num * x.get_price();
                        break;
                    }
                    cout << "\n\tItem " << *item_name << " have only " << x.get_quantities() << " in stock\n\n";
                    goto exitloop;
                    }
                }
                *p = make_pair(*item_name,*item_num);
                vTemp->push_back(*p);
                cout << "Continue shopping? (Y|N): "; cin >> *con;
                if(*con == 'Y') {continue;}
                else if(*con == 'N') {break;}
                }
                oTemp = make_order(*ctm_id,*vTemp);
                oTemp->set_total(*_total);
                _ord.push_back(*oTemp);
                delete item_name; item_name = NULL;
                delete item_num; item_num = NULL;
                delete ctm_id; ctm_id = NULL;
                delete p; p = NULL;
                delete con; con = NULL;
                delete vTemp; vTemp = NULL;
                delete oTemp; oTemp = NULL;    
                delete _total; _total = NULL;
                break;
            case 7:
                system("clear");
                cout << "Check by customer ID: "; cin >> *ctm_id;
                for(auto x : _ord)
                if(x.get_customer().get_c_id() == *ctm_id)
                oTemp = search_by_c_id(*ctm_id);
                break;
            case 0:
                return ;
            default:
                break;         
        }
    exitloop: ;
    }
}