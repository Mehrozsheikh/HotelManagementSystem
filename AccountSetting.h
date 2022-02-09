#pragma once
#include"Validator.h"
#include"Rooms.h"
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<iomanip>
#include<string>
using namespace std;

class AccountSetting : public Validator, public Rooms
{
private:
	char FD_username[30] = "admin";
	char FD_password[30] = "0000";
	int sizee; 
	int size = 1;
	char option1; 
	string enter_username; 
	string enter_password;
	bool flag1;
public:
	void Account();
	void change_userpass();
	bool current_pass_user();
};

