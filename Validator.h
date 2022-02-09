#pragma once
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<iomanip>
#include<string>
using namespace std;

class Validator
{

public:
	bool Names_Validator(string name);
	bool CNIC_Validator(string CNIC);
	bool email_Validator(string e_mail);
	bool Phone_Validator(string phone_number);
	bool arrival_Validator(string date_arrival);
	bool integar_validator(string days);
	bool username_valiadator(string enter_username);
	bool password_validator(string enter_password);
};

