#include"Hotel.h"
#include"Rooms.h"
#include"Validator.h"
#include"AccountSetting.h"
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<iomanip>
#include<string>
using namespace std;
int main() {
    AccountSetting account;
    Rooms obj;
    Hotel login;
    account.initialization_of_Arrays();
    obj.initialization_of_Arrays();
    login.initialization_of_Arrays();
    login.Login();
loop:
    system("cls");
    cout << setw(30) << " " << "|" << " " << "Welcome to the Hotel Management Program." << " " << "|\n";
    cout << setw(30) << " " << "--------------------------------------------\n";
    int option;
    cout << "---------------------------------------------------\n";
    cout << "|" << " " << left << setw(48) << "1. Check in(Booking a room) of Customer." << "|\n";
    cout << "---------------------------------------------------\n";
    cout << "|" << " " << left << setw(48) << "2. Check out(leaving the room) of Customer." << "|\n";
    cout << "---------------------------------------------------\n";
    cout << "|" << " " << left << setw(48) << "3. View Rooms Status." << "|\n";
    cout << "---------------------------------------------------\n";
    cout << "|" << " " << left << setw(48) << "4. View Room Type Specification." << "|\n";
    cout << "---------------------------------------------------\n";
    cout << "|" << " " << left << setw(48) << "5. Record Of Customers." << "|\n";     //will contain 3 types(view,edit,delete)
    cout << "---------------------------------------------------\n";
    cout << "|" << " " << left << setw(48) << "6. View All Records." << "|\n";        //will view records by rooms.
    cout << "---------------------------------------------------\n";
    cout << "|" << " " << left << setw(48) << "7. Account Setting." << "|\n";
    cout << "---------------------------------------------------\n";
    cout << "|" << " " << left << setw(48) << "8. Room Details." << "|\n";
    cout << "---------------------------------------------------\n";
    cout << "|" << " " << left << setw(48) << "9. Exit." << "|\n";
    cout << "---------------------------------------------------\n";
    cin >> option;
    switch (option) {
    case 1:
        obj.checkIn();
        goto loop;
    case 2:
        obj.checkoutBill();
        goto loop;
    case 3:
        obj.room_status();
        goto loop;
    case 4:
        obj.rooms_specification();
        goto loop;
    case 5:
        obj.costumer();
        goto loop;
    case 6:
        obj.view_all_cus();
        goto loop;
    case 7:
        account.Account();
        goto loop;
    case 8:
        obj.room_details();
        goto loop;
    case 9:
        break;
    default:
        cout << "Invalid Option.";
        goto loop;
    }
}