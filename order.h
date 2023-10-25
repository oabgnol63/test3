#ifndef ORDER_H
#define ORDER_H
#pragma once

#include <iostream>
#include "customer.h"
#include "item.h"

using namespace std;

vector<order> _ord;

class order
{
    protected:
        long long o_id;
        float total;
        string status;
        customer _ctm;
        vector<pair<string,int>> pd;
    public:
        order(){};
        void set_customer(customer);
        void set_product_list(vector<pair<string,int>> pd);
        void set_id(long long);
        void set_status(string);
        customer get_customer();
        //void search_by_o_id(order a);
        friend order *search_by_c_id(long long _id);
        void list_order();
        string get_status();
        long long get_o_id();
        vector<pair<string,int>> get_product();
        void set_total(float);
        float get_total();
};

#endif