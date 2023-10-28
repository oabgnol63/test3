#ifndef CUSTOMER_H
#define CUSTOMER_H
#pragma once

#include <iostream>
#include <vector>
#include "order.h"
#include "item.h"
#include <iomanip>


using namespace std;

class order;

class Person
{
    protected:
        string name, addr, tel;
    public:
        Person(){};
        Person(string ,string ,string );
        void Input();
        void Output();
        string get_info(string type);

};

class customer : public Person
{
    private:
        string c_rank;
        static long long c_num;
        long long c_id;
        vector<long long> ordered;
        float total_spent = 0;
    public:
        customer(){};
        customer(string,string,string);
        void Input();
        string Output();
        long long get_c_id();
        friend order *make_order(long long id, vector<pair<string,int>> v, vector<customer>*);
        void set_total_spent(float);
        float get_total_spent();
        vector<long long> *get_order_list();
};

order *make_order(long long id, vector<pair<string,int>> v, vector<customer>*);

#endif