#pragma once
#include"Validator.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<conio.h>
#include<iomanip>
#include<string>
using namespace std;

class Rooms : public Validator
{
protected:
    string add_room[3][20];
    bool flag_option8 = false;
    char available_rooms[3][20];    
    string username[30]; 
    string password[30]; 
    int size, index = 0;
    string cus_info[60][11], cus_history[100][11], cus_name, father_name, CNIC, gender, city, e_mail, phone_number, date_arrival, room_type, room_number, days_stay;
public:
    void initialization_of_Arrays();
    void room_details();
    bool adding_room();
    bool delete_room();
    void view_rooms_added();
    void rooms_specification();
    void room_status();
    bool book_room();
    bool reservation();
    short roomindex();
    void checkoutBill();
    void checkout();
    void costumer();
    bool info_of_customer();
    bool update_info();
    bool delete_info();
    void checkIn();
    void costumerHistory();
    void view_current();
    void view_all_cus();
};