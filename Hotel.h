#pragma once
#include"Rooms.h"
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<iomanip>
#include<string>

using namespace std;
class Hotel : public Rooms
{
private:
    // variables for function void login();
    char FD_username[100] = "admin";            //username for FD officer
    char FD_password[100] = "0000";             //password for FD officer
    string enter_username;
    string enter_password;
    string add_room[3][20];
    char available_rooms[3][20];
public:
    void Login(); 
};