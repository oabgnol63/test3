#include "customer.h"

long long customer::c_num = 2023000;
vector<customer> _cs;

Person::Person(string name,string address,string tel)
{
    this->name = name;
    this->addr = address;
    this->tel = tel;
}

void Person::Input()
{      
    cout << "Input your name: "; cin.ignore(); getline(cin,this->name); 
    cout << "Input your address: "; getline(cin,this->addr);
    cout << "Input your phone num: "; getline(cin,this->tel);
}

void Person::Output()
{
    cout << "Name: " << name << endl;
    cout << "Address: " << addr << endl;
    cout << "Phone num: " << tel << endl;
}

string Person::get_info(string type)
{
    if(type=="name") return this->name;
    else if(type=="address") return this->addr;
    else if(type=="phone") return this->tel;
    else return "";
}

customer::customer(string name, string address, string tel)
{
    this->name = name;
    this->tel = tel;
    this->addr = address;
    this->c_num++;
    this->c_id = this->c_num;
    this->c_rank = "Bronze";
}

void customer::Input()
{
    Person::Input();
    this->c_num++;
    this->c_id = this->c_num;
    this->c_rank = "Bronze";
}

string customer::Output()
{
    Person::Output();
    cout << "Id: " << this->c_id << endl;
    cout << "Ordered list: ";
    for(auto x : this->ordered) cout << x << " ";
    cout << endl;
    cout << fixed << setprecision(2);
    cout << "Total spent: " << this->total_spent << endl;
    if(this->total_spent > 2000000 && this->total_spent < 10000000) this->c_rank = "Silver";
    else if(this->total_spent >= 10000000 && this->total_spent < 20000000) this->c_rank = "Gold";
    else if(this->total_spent > 20000000) this->c_rank = "Platinum";
    cout << "Rank: " << this->c_rank << endl;
    cout << "-----------------------------\n";
    return this->c_rank;
}

vector<long long> *customer::get_order_list()
{
    return &this->ordered;
}

order *make_order(long long id, vector<pair<string,int>> v,vector<customer> *c)
{
    order *temp = new order;
    temp->set_product_list(v);
    srand(time(NULL));
    temp->set_id(rand());
    temp->set_status("On going");
    bool _already = false;
    for(auto &x : *c)
        if (x.get_c_id() == id) 
            {
                temp->set_customer(&x);
                x.get_order_list()->push_back(temp->get_o_id());
                _already = true;
            }
    if(!_already) 
    {
        cout << "Customer not found! Create new... \n";
        customer *ctemp = new customer;
        ctemp->Input();
        cout << "Assigned ID: " << ctemp->get_c_id() << endl;
        (ctemp->get_order_list())->push_back(temp->get_o_id());
        c->push_back(*ctemp);
        temp->set_customer(&c->back());
        delete ctemp; ctemp = NULL;
        
    }

    return temp;
}

long long customer::get_c_id()
{
    return this->c_id;
}

void customer::set_total_spent(float tt)
{
    this->total_spent = tt;
}

float customer::get_total_spent()
{
    return this->total_spent;
}