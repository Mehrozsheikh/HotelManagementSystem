#include "Hotel.h"

// Functions For loginging in.
void Hotel::Login()
{
	bool flag = false;
login:
	cout << "|" << " " << "Enter Login Details: \n\n";
	cout << left;
	cout << "|" << " " << setw(17) << "Enter Username:" << setw(3) << "|";
	cin >> enter_username;
	cout << "|" << " " << setw(17) << "Enter Passwords:" << setw(3) << "|";
	cin >> enter_password;
	if (enter_username == FD_username && enter_password == FD_password) {
		flag = true;
	}
	if (flag == true) {
		system("cls");;
		cout << "\n\n";
		cout << "__________Correct Username And Passwords.___________\n";
		_getch();
	}
	else {
		system("cls");
		cout << "\n\n";
		cout << "__________In-Correct Username & Password.__________\n";
		goto login;
		_getch();
	}
}