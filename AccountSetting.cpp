#include "AccountSetting.h"
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<iomanip>
#include<string>
using namespace std;

void AccountSetting::Account() {
choose4:
    string optio;
    system("CLS");
    cout << setw(30) << " " << "|" << " " << "Account Setting of The Program." << " " << "|\n";
    cout << setw(30) << " " << "-----------------------------------\n";
    cout << "***********************************************************\n";
    cout << "|" << " " << left << setw(48) << "1. TO Change Username And Password." << "         |\n";
    cout << "***********************************************************\n";
    cout << "|" << " " << left << setw(48) << "3. To Return to Main Menu." << "|\n";
    cout << "***********************************************************\n";
    cout << "Enter Your Option: ";
    cin >> optio;
    if (optio >= "1" && optio <= "2")
    {
        // for account setting
        char option1;
    menu7:
        //for changing username and passwords
        if (optio == "1")
        {
        pass:
            flag1 = current_pass_user();
            if (flag1 == true)
            {
                cout << setw(30) << " " << "Username And password Verified\n\n";
            usern:
                cout << "> Enter New Username(it should be without space): ";
                cin.ignore();
                getline(cin, enter_username);
                AccountSetting obj;
                flag1 = obj.Validator::username_valiadator(enter_username);
                if (flag1 == false)
                {
                    cout << "> Invalid Username. Please Enter Again.\n\n";
                    goto usern;
                }
            passs:
                cout << "\n>  Password requirements(atleast 8 elements long,1 uppercase alphabet,1 special character)\n";
                cout << "> Enter New Password: ";
                cin >> enter_password;
                flag1 = obj.Validator::password_validator(enter_password);
                if (flag1 == false)
                {
                    cout << "> Invalid Password. Please Enter Again.\n\n";
                    goto passs;
                }
                change_userpass();
            }
            else
            {
                cout << "> Entered Username And Password Doesn't Match with current Username and password.\n";
                cout << "\n>  Want to Enter Username & password again?(Y/N): ";
                cin >> option1;
                if (option1 == 'Y' || option1 == 'y')
                {
                    goto pass;
                }
                else if (option1 == 'N' || option1 == 'n')
                {
                    goto menu7;
                }
                else
                {
                    cout << "> INVALID INPUT.\n";
                }
            }

        }
        
        else if (optio == "2")
        {

        }

        _getch();
    }
    else
    {
        cout << "Entered Option is Unavailable Please Choose Again.\n";
        _getch();
        goto choose4;
    }
}

void AccountSetting::change_userpass()
{
    bool flag = false;
    int len_user = enter_username.length();
    int len_pass = enter_password.length();

    for (short i = 0; i < len_user; i++)
    {
        FD_username[i] = enter_username[i];
    }
    for (short i = 0; i < len_pass; i++)
    {
        FD_password[i] = enter_password[i];
    }

    for (short i = 0; i < size; i++)
    {
        username[i] = enter_username;
        password[i] = enter_password;
    }

    cout << "\n" << setw(35) << " " << "|  ==============================  |";
    cout << "\n" << setw(35) << " " << "|  PASSWORD CHANGED SUCCESSFULLY.  |";
    cout << "\n" << setw(35) << " " << "|  ==============================  |";
}

bool AccountSetting::current_pass_user()
{
    bool flag = false;
    cout << setw(30) << " " << "|" << " " << "PASSWORD VERIFICATION" << " " << "|\n";
    cout << setw(30) << " " << "---------------------\n";
    cout << "\n> Enter Current Username: ";
    cin >> enter_username;
    cout << "> Enter Current Password: ";
    cin >> enter_password;
    if (enter_username == FD_username && enter_password == FD_password)
    {
        flag = true;
    }
    return flag;
}

