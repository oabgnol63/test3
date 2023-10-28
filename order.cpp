#include "order.h"

vector<order> _ord;

void order::set_customer(customer* x)
{
    this->_ctm = new customer;
    (this->_ctm) = x;
}

void order::set_product_list(vector<pair<string,int>> _pd)
{
    this->pd = _pd;
}

void order::set_id(long long _id)
{
    this->o_id = _id;
}

void order::set_status(string stt)
{
    this->status = stt;
}

customer* order::get_customer()
{
    return this->_ctm;
}

void order::list_order()
{
    cout << "************************************\n";
    cout << "Order ID: " << this->get_o_id() << endl;
    cout << "Item/Quantities:\n";
    for(auto x : this->get_product())
        cout << "\t-- " << x.first << "/" << x.second << endl;
    cout << fixed << setprecision(2);
    cout << "Total: " << this->total << endl;
    cout << "Status: " << this->get_status() << endl;
    this->get_customer()->Output();
}

string order::get_status()
{
    return this->status;
}

long long order::get_o_id()
{
    return this->o_id;
}

vector<pair<string,int>> order::get_product()
{
    return this->pd;
}

order *search_by_c_id(long long _id)
{
    for(auto &x : _ord)
    {
        if(x.get_customer()->get_c_id() == _id)
        {   
            x.list_order();
            return &x;
        }
    }
    return NULL;
}

void order::set_total(float _total)
{
    this->total = _total;
}

float order::get_total()
{
    return this->total;
}