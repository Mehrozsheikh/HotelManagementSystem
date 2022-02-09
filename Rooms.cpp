#include "Rooms.h"

void Rooms::room_details()
{
	short option;
option_selection:
	system("CLS");
	cout << setw(30) << " " << "|" << " " << "Welcome TO Rooms Menu." << " " << "|\n";
	cout << setw(30) << " " << "-----------------------------------\n";
	cout << "***********************************************\n";
	cout << "|" << " " << left << setw(45) << "1. To Add A Room." << "|\n";
	cout << "***********************************************\n";
	cout << "|" << " " << left << setw(45) << "2. To Delete Details Of a Room." << "|\n";
	cout << "***********************************************\n";
	cout << "|" << " " << left << setw(45) << "3. View All Rooms." << "|\n";
	cout << "***********************************************\n";
	cout << "> Enter Your Option: ";
	cin >> option;
	if (option >= 1 && option <= 3)
	{
		if (option == 1) // To add a room
		{
			cout << " =========================================================================================\n";
			cout << "|" << " " << "Rooms Types are:            1.Suite           2.Delux          3.Standard.              |\n";
			cout << " =========================================================================================\n";
			cout << "|" << " " << setw(25) << "> Room Type(1/2/3): " << setw(3) << "|";
			cin >> room_type;
			cout << "> Enter Room Number: ";
			cin >> room_number;

			flag_option8 = adding_room();
			if (option == true)
			{
				cout << "\n" << setw(40) << " " << "|  =================================  |";
				cout << "\n" << setw(40) << " " << "|  ROOM HAS BEEN ADDED SUCCESSFULLY.  |";
				cout << "\n" << setw(40) << " " << "|  =================================  |";
			}
			else
			{
				cout << "\n" << setw(40) << " " << "|  ===========================  |";
				cout << "\n" << setw(40) << " " << "|  NO MORE ROOMS ARE AVAILABLE  |";
				cout << "\n" << setw(40) << " " << "|  ===========================  |";
			}
			_getch();
		}
		else if (option == 2)
		{
			cout << " =========================================================================================\n";
			cout << "|" << " " << "Rooms Types are:            1.Suite           2.Delux          3.Standard.              |\n";
			cout << " =========================================================================================\n";
			cout << "|" << " " << setw(25) << "> Room Type(1/2/3): " << setw(3) << "|";
			cin >> room_type;
			cout << "> Enter Room Number: ";
			cin >> room_number;

			flag_option8 = delete_room();
			if (flag_option8 == true)
			{
				cout << "\n" << setw(40) << " " << "|  ===================================  |";
				cout << "\n" << setw(40) << " " << "|  ROOM HAS BEEN DELETED SUCCESSFULLY.  |";
				cout << "\n" << setw(40) << " " << "|  ===================================  |";
			}
			else
			{
				cout << "> ROOM NUMBER U ENTERED DOESN'T EXIST. PLEASE TRY AGAIN.\n";
			}
			_getch();
		}
		else if (option == 3)
		{
			view_rooms_added();
		}
	}
	else
	{
		cout << "> Your Have Enter Un-Available Option.\n Press Any Key to Select Option Again From Rooms Menu.\n";
		_getch();
		goto option_selection;
	}

}

// Functions For deleting added room

bool Rooms::delete_room()
{
	bool flag = false;
	if (room_type == "1")
	{
		for (short i = 0; i < 20; i++)
		{
			if (add_room[0][i] == room_number)
			{
				add_room[0][i] = "0";
				flag = true;
				break;
			}
		}
	}
	else if (room_type == "2")
	{
		for (short i = 0; i < 20; i++)
		{
			if (add_room[1][i] == room_number)
			{
				add_room[1][i] = "0";
				flag = true;
				break;
			}
		}
	}
	else if (room_type == "3")
	{
		for (short i = 0; i < 20; i++)
		{
			if (add_room[2][i] == room_number)
			{
				add_room[2][i] = "3";
				flag = true;
				break;
			}
		}
	}
	return flag;
}
// Functions For adding rooms
bool Rooms::adding_room()
{
	bool flag = false;
	if (room_type == "1")
	{
		for (short i = 0; i < 20; i++)
		{
			if (add_room[0][i] == "0")
			{
				add_room[0][i] = room_number;
				flag = true;
				break;
			}
		}
	}
	else if (room_type == "2")
	{
		for (short i = 0; i < 20; i++)
		{
			if (add_room[1][i] == "0")
			{
				add_room[1][i] = room_number;
				flag = true;
				break;
			}
		}
	}
	else if (room_type == "3")
	{
		for (short i = 0; i < 20; i++)
		{
			if (add_room[2][i] == "0")
			{
				add_room[2][i] = room_number;
				flag = true;
				break;
			}
		}
	}
	return flag;
}

// Functions For viewing added room.
void Rooms::view_rooms_added()
{

	for (short i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			cout << setw(60) << " " << "|" << " " << "~~~~Suite~~~~" << " " << "|\n";
			cout << " ======================================================================================================================\n";
			cout << "|      ";
		}

		if (i == 1)
		{
			cout << setw(60) << " " << "|" << " " << "~~~~Deluxe~~~~" << " " << "|\n";
			cout << " ======================================================================================================================\n";
			cout << "|      ";
		}

		if (i == 2)
		{
			cout << setw(60) << " " << "|" << " " << "~~~~Standard~~~~" << " " << "|\n";
			cout << " ======================================================================================================================\n";
			cout << "|      ";
		}
		for (short j = 0; j < 10; j++)
		{
			if (available_rooms[i][j] == '*')
			{
				cout << "Vacant::";
			}
			else
			{
				cout << "Booked::";
			}
			cout << add_room[i][j] << "  ";
		}
		cout << "  |" << endl;
		cout << " ======================================================================================================================\n";
		cout << "|      ";
		for (short j = 10; j < 20; j++)
		{
			if (available_rooms[i][j] == '*')
			{
				cout << "Vacant::";
			}
			else
			{
				cout << "Booked::";
			}
			cout << add_room[i][j] << "  ";
		}
		cout << "  |" << endl;
		cout << " ======================================================================================================================\n";

	}
	_getch();
}
void Rooms::initialization_of_Arrays()
{
	for (short i = 0; i < 3; i++)
	{
		for (short j = 0; j < 20; j++)
		{
			add_room[i][j] = "0";
		}
	}
	for (short i = 0; i < 3; i++)
	{
		for (short j = 0; j < 20; j++)
		{
			available_rooms[i][j] = '*';
		}
	}
	for (short i = 0; i < 60; i++)
	{
		for (short j = 0; j < 11; j++)
		{
			cus_info[i][j] = "NV";
		}
	}
	for (short i = 0; i < 100; i++)
	{
		for (short j = 0; j < 11; j++)
		{
			cus_history[i][j] = "NV";
		}
	}
	for (short i = 0; i < size; i++)
	{
		username[i] = "NV";
		password[i] = "NV";
	}
}


void Rooms::rooms_specification()
{
	system("cls");
	cout << setw(30) << " " << "|" << " " << "There Are 3 Types Of Rooms" << " " << "|\n";
	cout << setw(30) << " " << "------------------------------\n\n";
	cout << " " << "========================================================================\n";
	cout << setw(5) << "|" << setw(20) << "1: Suite " << setw(7) << "|" << setw(20) << "2: Delux " << setw(7) << "|" << setw(14) << "3: Standard" << "|\n";
	cout << "|" << "========================================================================|\n";
	cout << setw(5) << "|" << "Specifications: \n";
	cout << "|" << "========================================================================|\n";
	cout << setw(5) << "|" << setw(20) << "2 Rooms" << setw(7) << "|" << setw(20) << "1 Room" << setw(7) << "|" << setw(14) << "1 Room" << "|\n";
	cout << setw(5) << "|" << setw(20) << "Double Bed" << setw(7) << "|" << setw(20) << "Single bed" << setw(7) << "|" << setw(14) << "Single bed" << "|\n";
	cout << setw(5) << "|" << setw(20) << "Attach Bathroom" << setw(7) << "|" << setw(20) << "Washroom" << setw(7) << "|" << setw(14) << "Washroom" << "|\n";
	cout << setw(5) << "|" << setw(20) << "T.V Lounge" << setw(7) << "|" << setw(20) << "T.V" << setw(7) << "|" << setw(14) << "T.V " << "|\n";
	cout << setw(5) << "|" << setw(20) << "2 Sofa sets" << setw(7) << "|" << setw(20) << "Sofa" << setw(7) << "|" << setw(14) << "Single Chair" << "|\n";
	cout << setw(5) << "|" << setw(20) << "2 CupBoards" << setw(7) << "|" << setw(20) << "1 CupBoards" << setw(7) << "|" << setw(14) << "1 Cupboard" << "|\n";
	cout << setw(5) << "|" << setw(20) << "Kitchen" << setw(7) << "|" << setw(20) << "None" << setw(7) << "|" << setw(14) << "None" << "|\n";
	cout << setw(5) << "|" << setw(20) << "10k/night" << setw(7) << "|" << setw(20) << "6k/night" << setw(7) << "|" << setw(14) << "4k/night" << "|\n";
	cout << " " << "======================================================================== \n";
	_getch();
}

// Functions For  viewing room status .
void Rooms::room_status()
{
	string option;
choose1:
	system("cls");
	cout << setw(30) << " " << "|" << " " << "Rooms Status." << " " << "|\n";
	cout << setw(30) << " " << "-----------------\n";
	cout << " *************************************************\n";
	cout << "|" << " " << left << setw(48) << "1. Available Rooms of 'Suite' Type." << "|\n";
	cout << " *************************************************\n";
	cout << "|" << " " << left << setw(48) << "2. Available Rooms of 'Deluxe' Type." << "|\n";
	cout << " *************************************************\n";
	cout << "|" << " " << left << setw(48) << "3. Available Rooms of 'Standard' Type." << "|\n";
	cout << " *************************************************\n";
option_menu:
	cout << "Enter Your Option: ";
	cin >> option;
	if (option >= "1" && option <= "3")
	{
		if (option == "1")
		{
			cout << setw(55) << " " << "|" << " " << "Suite" << " " << "|\n";

			cout << " ======================================================================================================================\n";
			cout << "|      ";
			for (short i = 0; i < 10; i++)
			{
				if (available_rooms[0][i] == '*')
				{
					cout << "Vacant::";
				}
				else
				{
					cout << "Booked::";
				}
				cout << add_room[0][i] << "  ";
			}
			cout << "  |" << endl;
			cout << " ======================================================================================================================\n";
			cout << "|      ";
			for (short i = 10; i < 20; i++)
			{
				if (available_rooms[0][i] == '*')
				{
					cout << "Vacant::";
				}
				else
				{
					cout << "Booked::";
				}
				cout << add_room[0][i] << "  ";
			}
			cout << "  |" << endl;
			cout << " ======================================================================================================================\n";
			_getche();
		}
		if (option == "2")
		{
			cout << setw(55) << " " << "|" << " " << "Deluxe" << " " << "|\n";
			cout << " ======================================================================================================================\n";
			cout << "|      ";
			for (short i = 0; i < 10; i++)
			{
				if (available_rooms[1][i] == '*')
				{
					cout << "Vacant::";
				}
				else
				{
					cout << "Booked::";
				}
				cout << add_room[1][i] << "  ";
			}
			cout << "  |" << endl;
			cout << " ======================================================================================================================\n";
			cout << "|      ";
			for (short i = 10; i < 20; i++)
			{
				if (available_rooms[1][i] == '*')
				{
					cout << "Vacant::";
				}
				else
				{
					cout << "Booked::";
				}
				cout << add_room[1][i] << "  ";
			}
			cout << "  |" << endl;
			cout << " ======================================================================================================================\n";
			_getche();
		}
		if (option == "3")
		{
			cout << setw(60) << " " << "|" << " " << "Standard" << " " << "|\n";
			cout << " ======================================================================================================================\n";
			cout << "|      ";
			for (short i = 0; i < 10; i++)
			{
				if (available_rooms[2][i] == '*')
				{
					cout << "Vacant::";
				}
				else
				{
					cout << "Booked::";
				}
				cout << add_room[2][i] << "  ";
			}
			cout << "  |" << endl;
			cout << " ======================================================================================================================\n";
			cout << "|      ";
			for (short i = 10; i < 20; i++)
			{
				if (available_rooms[2][i] == '*')
				{
					cout << "Vacant::";
				}
				else
				{
					cout << "Booked::";
				}
				cout << add_room[2][i] << "  ";
			}
			cout << "  |" << endl;
			cout << " ======================================================================================================================\n";
		}
	}
	else
	{
		cout << setw(30) << "Entered Option is Unavailable Please Choose Again.\n";
		_getch();
		goto choose1;
	}
}

// Functions For  booking all rooms

bool Rooms::book_room()
{
	bool flag = false;
	bool flag1 = false;
	short index = 10;
	short j = 0;
	for (short i = 0; i < 60; i++)
	{
		if (cus_info[i][0] == "NV")
		{
			cus_info[i][0] = cus_name;
			cus_info[i][1] = father_name;
			cus_info[i][2] = CNIC;
			cus_info[i][3] = gender;
			cus_info[i][4] = city;
			cus_info[i][5] = e_mail;
			cus_info[i][6] = phone_number;
			cus_info[i][7] = room_type;
			cus_info[i][8] = date_arrival;
			cus_info[i][9] = room_number;
			cus_info[i][10] = days_stay;
			flag = true;
			break;
		}
	}

	for (short j = 0; j < 60; j++)
	{
		if (cus_history[j][0] == "NV")
		{
			cus_history[j][0] = cus_name;
			cus_history[j][1] = father_name;
			cus_history[j][2] = CNIC;
			cus_history[j][3] = gender;
			cus_history[j][4] = city;
			cus_history[j][5] = e_mail;
			cus_history[j][6] = phone_number;
			cus_history[j][7] = room_type;
			cus_history[j][8] = date_arrival;
			cus_history[j][9] = room_number;
			cus_history[j][10] = days_stay;
				if (cus_history[j][0] != "NV")
				{
					ofstream cus_data("CostumerDetails.txt", ios::app);
					cus_data << setw(18) << "\n> Name: " << setw(30) << cus_history[j][0] << setw(19) << "> Father Name:" << setw(30) << cus_history[j][1];
					cus_data << setw(18) << "\n> CNIC: " << setw(30) << cus_history[j][2] << setw(19) << "> Gender:" << setw(30) << cus_history[j][3];
					cus_data << setw(18) << "\n> City: " << setw(30) << cus_history[j][4] << setw(19) << "> E-Mail:" << setw(30) << cus_history[j][5];
					cus_data << setw(18) << "\n> Phone Number: " << setw(30) << cus_history[j][6] << setw(19) << "> Room Type:" << setw(30) << cus_history[j][7];
					cus_data << setw(18) << "\n> Date of Arrival:" << setw(30) << cus_history[j][8] << setw(19) << "> Room Number:" << setw(30) << cus_history[j][9];
					cus_data << setw(18) << "\n> Night's Stay: " << setw(30) << cus_history[j][10] << endl;
					cus_data.close();
					ofstream backend("backend.txt", ios::app);
					backend << cus_history[j][0] << cus_history[j][1];
					backend << cus_history[j][2] << cus_history[j][3];
					backend << cus_history[j][4] << cus_history[j][5];
					backend << cus_history[j][6] << cus_history[j][7];
					backend << cus_history[j][8] << cus_history[j][9];
					backend << cus_history[j][10] << endl;
				}
			break;
		}
	}

	return flag;
}
bool Rooms::reservation()
{
	bool flag = false;
	int j = 0;

	if (room_type == "1")
	{
		if (available_rooms[j][index] == '*')
		{
			flag = true;
			available_rooms[j][index] = 'X';
		}
		else
		{
			flag = false;
		}
	}
	if (room_type == "2")
	{
		if (available_rooms[j + 1][index] == '*')
		{
			flag = true;
			available_rooms[j + 1][index] = 'X';
		}
		else
		{
			flag = false;
		}
	}
	if (room_type == "3")
	{
		if (available_rooms[j + 2][index] == '*')
		{
			flag = true;
			available_rooms[j + 2][index] = 'X';
		}
		else
		{
			flag = false;
		}
	}
	return flag;
}
// Functions For getting index of entered room number
short Rooms::roomindex()
{
	short index = -1;
	short j = 0;
	if (room_type == "1")
	{
		for (short i = 0; i < 20; i++)
		{
			if (add_room[j][i] == room_number)
			{
				index = i;
				break;
			}
		}
	}
	if (room_type == "2")
	{
		for (short i = 0; i < 20; i++)
		{
			if (add_room[j + 1][i] == room_number)
			{
				index = i;
				break;
			}
		}
	}
	if (room_type == "3")
	{
		for (short i = 0; i < 20; i++)
		{
			if (add_room[j + 2][i] == room_number)
			{
				index = i;
				break;
			}
		}
	}
	return index;
}

void Rooms::checkIn() {
	short index;
	system("cls");

	cout << setw(35) << " " << "|" << " " << "Enter The Details Of The Room." << " " << "|\n";
	cout << setw(35) << " " << "----------------------------------\n\n";
	cout << " =========================================================================================\n";
	cout << "|" << " " << "Rooms Types are:            1.Suite           2.Delux          3.Standard.              |\n";
	cout << " =========================================================================================\n";
	cout << "|" << " " << setw(25) << "Room Type(1/2/3): " << setw(3) << "|";
	cin >> room_type;

	cout << "\nList of Rooms of Selected Type.\n";
	room_status();
	cout << "\n|" << " " << setw(20) << "Room Number: " << setw(7) << "|";
	cin >> room_number;

	index = roomindex();
	if (index != -1)
	{
		bool flag1 = reservation();
		_getch();
		if (flag1 == true)
			// Every Input will be validated here and if input is wrong
			// it will instantly ask for correct input.
			//bcz its a long form and no one will filling it complete again.
		{
			system("CLS");
			cout << setw(40) << " " << "|" << " " << "Enter The Details Of The Customer." << " " << "|\n";
			cout << setw(40) << " " << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		name:
			cout << "|" << " " << setw(20) << "Name: " << setw(7) << "|";
			cin.ignore();
			getline(cin, cus_name);
			flag1 = Names_Validator(cus_name);
			if (flag1 == false)
			{
				cout << setw(40) << " " << "Invalid Name. Please Enter Your Name Again.\n";
				goto name;
			}
		f_name:
			cout << "|" << " " << setw(20) << "Father Name: " << setw(7) << "|";
			getline(cin, father_name);
			flag1 = Names_Validator(father_name);
			if (flag1 == false)
			{
				cout << setw(40) << " " << "Invalid Father Name . Please Enter Again.\n";
				goto f_name;
			}

		cnic:
			cout << "|" << " " << setw(20) << "CNIC: " << setw(7) << "|";
			cin >> CNIC;
			flag1 = CNIC_Validator(CNIC);
			if (flag1 == false)
			{
				cout << setw(40) << " " << "Invalid CNIC. Please Enter Again in given format(XXXXX-XXXXXXX-X).\n";
				goto cnic;
			}

		gender:
			cout << "|" << " " << setw(20) << "Gender: " << setw(7) << "|";
			cin >> gender;
			flag1 = Names_Validator(gender);
			if (flag1 == false)
			{
				cout << setw(40) << " " << "Invalid Gender . Please Enter Again.\n";
				goto gender;
			}

		city:
			cout << "|" << " " << setw(20) << "City: " << setw(7) << "|";
			cin >> city;
			flag1 = Names_Validator(city);
			if (flag1 == false)
			{
				cout << setw(40) << " " << "Invalid City . Please Enter Again.\n";
				goto city;
			}

		email:
			cout << "|" << " " << setw(20) << "E-Mail: " << setw(7) << "|";
			cin >> e_mail;
			flag1 = email_Validator(e_mail);
			if (flag1 == false)
			{
				cout << setw(40) << " " << "Invalid email. Please Enter Again.\n";
				goto email;
			}

		phonenumber:
			cout << "|" << " " << setw(20) << "Phone Number: " << setw(7) << "|";
			cin >> phone_number;
			flag1 = Phone_Validator(phone_number);
			if (flag1 == false)
			{
				cout << setw(40) << " " << "Invalid Phone Number. Please Enter Again.\n";
				goto phonenumber;
			}

		datearrival:
			cout << "|" << " " << setw(20) << "Date of Arrival:" << setw(7) << "|";
			cin >> date_arrival;
			flag1 = arrival_Validator(date_arrival);
			if (flag1 == false)
			{
				cout << setw(40) << " " << "Invalid Date. Please Enter In Given Format (XX/XX/XXXX).\n";
				goto datearrival;
			}

		days:
			cout << "|" << " " << setw(20) << "NO. Of Days of Stay" << setw(7) << "|";
			cin >> days_stay;
			flag1 = integar_validator(days_stay);
			if (flag1 == false)
			{
				cout << setw(40) << " " << "Invalid Date. Please Enter Integer.\n";
				goto days;
			}


			flag1 = book_room();

			if (flag1 == true)
			{
				cout << "\n" << setw(40) << " " << "|  ======================  |";
				cout << "\n" << setw(40) << " " << "|  Room Have Been Booked.  |";
				cout << "\n" << setw(40) << " " << "|  ======================  |";
				
			}
			else
			{
				cout << "Soory Room is not booked because of some issue.\n";
			}

		}
		else
		{
			cout << "Room is Already Booked.\n";
		}
	}
	else
	{
		cout << "> Room isn't Available";
	}
	_getch();
}
void Rooms::checkoutBill() {
slip:
	char opt;
	cout << setw(30) << " " << "|" << " " << "Checking Out Slip Of The Customer." << " " << "|\n";
	cout << setw(30) << " " << "--------------------------------------\n";

	cout << "|" << " " << setw(25) << "Room Number: " << setw(7) << "|";
	cin >> room_number;

	bool flag1 = info_of_customer();
	if (flag1 == true)
	{
		cout << "\n Is This the Customers Who wants to Check-Out?(Y/N).";
		cin >> opt;
		if (opt == 'Y' || opt == 'y')
		{
			checkout();
		}
		else if (opt == 'N' || opt == 'n')
		{
			goto slip;
		}
		else
		{
			cout << "INVALID INPUT.\n";
		}
	}
	_getch();
}

void Rooms::checkout()
{
	bool flag = false;
	int index;
	float bill_suite = 10000;
	float bill_delux = 6000;
	float bill_standard = 4000;
	float bill = 1;
	short days;
	short index1;
	float gst;
	float t_bill = 0;

	for (short i = 0; i < 60; i++)
	{
		if (cus_info[i][9] == room_number)
		{
			days = stoi(cus_info[i][10]);
			index1 = i;
			break;
		}
	}
	for (short i = 0; i < 3; i++)
	{
		for (short j = 0; j < 20; j++)
		{
			if (add_room[i][j] == room_number)
			{
				index = i;
				flag = true;
				break;
			}
		}
	}
	if (index == 0)
	{
		bill = bill_suite * days;
	}
	else if (index == 1)
	{
		bill = bill_delux * days;
	}
	else if (index == 2)
	{
		bill = bill_standard * days;
	}
	gst = bill * 0.16;
	t_bill = gst + bill;
	ofstream checkoutslip("checkout.txt", ios::app);
	checkoutslip << "\n =======================================================================================================\n";
	checkoutslip << setw(40) << "| " << "~~~~Check-Out Slip~~~~                                          |\n";
	checkoutslip << " =======================================================================================================\n";
	checkoutslip << setw(103) << "| " << " |\n";
	checkoutslip << setw(10) << "| " << "> Guest name:   " << setw(20) << cus_info[index1][0] << setw(26) << " " << "> Check-In Date:   " << setw(12) << cus_info[index1][8] << " |\n";
	checkoutslip << setw(10) << "| " << "> Room #:       " << setw(20) << cus_info[index1][9] << setw(26) << " " << "> No. Of Nights:   " << setw(12) << cus_info[index1][10] << " |\n";
	checkoutslip << setw(103) << "| " << " |\n";
	checkoutslip << "|-------------------------------------------------------------------------------------------------------|";
	checkoutslip << endl << setw(10) << "|" << setw(25) << "Description" << setw(10) << "|" << setw(13) << "Food" << setw(10) << "|" << setw(13) << "Depit" << setw(10) << "|" << setw(13) << "Credit" << setw(10) << "|";
	checkoutslip << "\n|-------------------------------------------------------------------------------------------------------|";
	checkoutslip << endl << setw(10) << "|" << setw(25) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|";
	checkoutslip << "\n|-------------------------------------------------------------------------------------------------------|";
	checkoutslip << endl << setw(10) << "|" << setw(25) << "Room Rent " << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << bill << setw(10) << "|";
	checkoutslip << endl << setw(10) << "|" << setw(25) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|";
	checkoutslip << endl << setw(10) << "|" << setw(25) << "Matress" << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << "0" << setw(10) << "|";
	checkoutslip << endl << setw(10) << "|" << setw(25) << "Extra's" << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << "0" << setw(10) << "|" << setw(13) << "0" << setw(10) << "|";
	checkoutslip << endl << setw(10) << "|" << setw(25) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|";
	checkoutslip << endl << setw(10) << "|" << setw(25) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|";
	checkoutslip << endl << setw(10) << "|" << setw(25) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|";
	checkoutslip << endl << setw(10) << "|" << setw(25) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|";
	checkoutslip << endl << setw(10) << "|" << setw(25) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|";
	checkoutslip << "\n|-------------------------------------------------------------------------------------------------------|";
	checkoutslip << endl << setw(10) << "|" << setw(25) << "Sub Total" << setw(10) << " " << setw(13) << " " << setw(10) << " " << setw(13) << " " << setw(10) << " " << setw(13) << bill << setw(10) << "|";
	checkoutslip << endl << setw(10) << "|" << setw(25) << "G.S.T 16%" << setw(10) << " " << setw(13) << " " << setw(10) << " " << setw(13) << " " << setw(10) << " " << setw(13) << gst << setw(10) << "|";
	checkoutslip << "\n|-------------------------------------------------------------------------------------------------------|";
	checkoutslip << endl << setw(10) << "|" << setw(25) << "Total" << setw(10) << " " << setw(13) << " " << setw(10) << " " << setw(13) << " " << setw(10) << "|" << setw(13) << t_bill << setw(10) << "|";
	checkoutslip << "\n|-------------------------------------------------------------------------------------------------------|";
	checkoutslip << endl << setw(10) << "|" << setw(25) << "Advance" << setw(10) << " " << setw(13) << " " << setw(10) << " " << setw(13) << " " << setw(10) << "|" << setw(13) << "0" << setw(10) << "|";
	checkoutslip << endl << setw(10) << "|" << setw(25) << " " << setw(10) << " " << setw(13) << " " << setw(10) << " " << setw(13) << " " << setw(10) << " " << setw(13) << " " << setw(10) << "|";
	checkoutslip << "\n|-------------------------------------------------------------------------------------------------------|";
	checkoutslip << endl << setw(10) << "|" << setw(25) << "Grand Total" << setw(10) << " " << setw(13) << "0" << setw(10) << " " << setw(13) << " " << setw(10) << "|" << setw(13) << t_bill << setw(10) << "|";
	checkoutslip << "\n|_______________________________________________________________________________________________________|\n\n";
	checkoutslip.close();
	cout << " =======================================================================================================\n";
	cout << setw(40) << "| " << "~~~~Check-Out Slip~~~~                                          |\n";
	cout << " =======================================================================================================\n";
	cout << setw(103) << "| " << " |\n";
	cout << setw(10) << "| " << "> Guest name:   " << setw(20) << cus_info[index1][0] << setw(26) << " " << "> Check-In Date:   " << setw(12) << cus_info[index1][8] << " |\n";
	cout << setw(10) << "| " << "> Room #:       " << setw(20) << cus_info[index1][9] << setw(26) << " " << "> No. Of Nights:   " << setw(12) << cus_info[index1][10] << " |\n";
	cout << setw(103) << "| " << " |\n";
	cout << "|-------------------------------------------------------------------------------------------------------|";
	cout << endl << setw(10) << "|" << setw(25) << "Description" << setw(10) << "|" << setw(13) << "Food" << setw(10) << "|" << setw(13) << "Depit" << setw(10) << "|" << setw(13) << "Credit" << setw(10) << "|";
	cout << "\n|-------------------------------------------------------------------------------------------------------|";
	cout << endl << setw(10) << "|" << setw(25) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|";
	cout << "\n|-------------------------------------------------------------------------------------------------------|";
	cout << endl << setw(10) << "|" << setw(25) << "Room Rent " << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << bill << setw(10) << "|";
	cout << endl << setw(10) << "|" << setw(25) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|";
	cout << endl << setw(10) << "|" << setw(25) << "Matress" << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << "0" << setw(10) << "|";
	cout << endl << setw(10) << "|" << setw(25) << "Extra's" << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << "0" << setw(10) << "|" << setw(13) << "0" << setw(10) << "|";
	cout << endl << setw(10) << "|" << setw(25) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|";
	cout << endl << setw(10) << "|" << setw(25) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|";
	cout << endl << setw(10) << "|" << setw(25) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|";
	cout << endl << setw(10) << "|" << setw(25) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|";
	cout << endl << setw(10) << "|" << setw(25) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|" << setw(13) << " " << setw(10) << "|";
	cout << "\n|-------------------------------------------------------------------------------------------------------|";
	cout << endl << setw(10) << "|" << setw(25) << "Sub Total" << setw(10) << " " << setw(13) << " " << setw(10) << " " << setw(13) << " " << setw(10) << " " << setw(13) << bill << setw(10) << "|";
	cout << endl << setw(10) << "|" << setw(25) << "G.S.T 16%" << setw(10) << " " << setw(13) << " " << setw(10) << " " << setw(13) << " " << setw(10) << " " << setw(13) << gst << setw(10) << "|";
	cout << "\n|-------------------------------------------------------------------------------------------------------|";
	cout << endl << setw(10) << "|" << setw(25) << "Total" << setw(10) << " " << setw(13) << " " << setw(10) << " " << setw(13) << " " << setw(10) << "|" << setw(13) << t_bill << setw(10) << "|";
	cout << "\n|-------------------------------------------------------------------------------------------------------|";
	cout << endl << setw(10) << "|" << setw(25) << "Advance" << setw(10) << " " << setw(13) << " " << setw(10) << " " << setw(13) << " " << setw(10) << "|" << setw(13) << "0" << setw(10) << "|";
	cout << endl << setw(10) << "|" << setw(25) << " " << setw(10) << " " << setw(13) << " " << setw(10) << " " << setw(13) << " " << setw(10) << " " << setw(13) << " " << setw(10) << "|";
	cout << "\n|-------------------------------------------------------------------------------------------------------|";
	cout << endl << setw(10) << "|" << setw(25) << "Grand Total" << setw(10) << " " << setw(13) << "0" << setw(10) << " " << setw(13) << " " << setw(10) << "|" << setw(13) << t_bill << setw(10) << "|";
	cout << "\n|_______________________________________________________________________________________________________|";

}

void Rooms::costumer() {
	int option = 0;
	system("CLS");
choose2:
	cout << setw(30) << " " << "|" << " " << "Records OF The Customers." << " " << "|\n";
	cout << setw(30) << " " << "-----------------------------\n";
	cout << " *************************************************\n";
	cout << "|" << " " << left << setw(48) << "1. View Record Of a Specific Customer." << "|\n";
	cout << " *************************************************\n";
	cout << "|" << " " << left << setw(48) << "2. Update Record of a Specific Customer." << "|\n";
	cout << " *************************************************\n";
	cout << "|" << " " << left << setw(48) << "3. Delete Record of a Specific Customer." << "|\n";
	cout << " *************************************************\n";
	cout << "|" << " " << left << setw(48) << "4. Return To Main Menu." << "|\n";
	cout << " *************************************************\n";
	cout << "Enter Your Option: ";
	cin >> option;
	if (option >= 1 && option <= 4)
	{
		//Records of every customer.
		char op;
	repeat:
		//for viewing specific record
		if (option == 1)
		{
			system("cls");
			cout << setw(30) << " " << "|" << " " << "Record of a Specific Customer." << " " << "|\n";
			cout << setw(30) << " " << "-----------------------------------\n\n";
			cout << "> Enter Room Number: ";
			cin >> room_number;
			info_of_customer();
		}
		//for update specific record
		else if (option == 2)
		{
		update:
			system("cls");
			cout << setw(30) << " " << "|" << " " << "Update Record of a Specific Customer." << " " << "|\n";
			cout << setw(30) << " " << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			cout << "> Enter Room Number: ";
			cin >> room_number;
			bool flag1 = info_of_customer();
			if (flag1 == true)
			{
				cout << "\n\n> Is This the Customers Data You want to Update?(Y/N): ";
				cin >> op;
				cout << endl;
				if (op == 'Y' || op == 'y')
				{
					cout << setw(30) << " " << "|" << " " << "Enter The Details Of The Customer." << " " << "|\n";
					cout << setw(30) << " " << "--------------------------------------\n";
				name1:
					cout << "|" << " " << setw(20) << "Name: " << setw(7) << "|";
					cin.ignore();
					getline(cin, cus_name);
					flag1 = Names_Validator(cus_name);
					if (flag1 == false)
					{
						cout << setw(40) << " " << "Invalid Name. Please Enter Your Name Again.\n";
						goto name1;
					}
				f_name1:
					cout << "|" << " " << setw(20) << "Father Name: " << setw(7) << "|";
					cin.ignore();
					getline(cin, father_name);
					flag1 = Names_Validator(father_name);
					if (flag1 == false)
					{
						cout << setw(40) << " " << "Invalid Father Name . Please Enter Again.\n";
						goto f_name1;
					}

				cnic1:
					cout << "|" << " " << setw(20) << "CNIC: " << setw(7) << "|";
					cin >> CNIC;
					flag1 = CNIC_Validator(CNIC);
					if (flag1 == false)
					{
						cout << setw(40) << " " << "Invalid CNIC. Please Enter Again in given format(XXXXX-XXXXXXX-X).\n";
						goto cnic1;
					}

				gender1:
					cout << "|" << " " << setw(20) << "Gender: " << setw(7) << "|";
					cin >> gender;
					flag1 = Names_Validator(gender);
					if (flag1 == false)
					{
						cout << setw(40) << " " << "Invalid Gender . Please Enter Again.\n";
						goto gender1;
					}

				city1:
					cout << "|" << " " << setw(20) << "City: " << setw(7) << "|";
					cin >> city;
					flag1 = Names_Validator(city);
					if (flag1 == false)
					{
						cout << setw(40) << " " << "Invalid City . Please Enter Again.\n";
						goto city1;
					}

				email1:
					cout << "|" << " " << setw(20) << "E-Mail: " << setw(7) << "|";
					cin >> e_mail;
					flag1 = email_Validator(e_mail);
					if (flag1 == false)
					{
						cout << setw(40) << " " << "Invalid email. Please Enter Again.\n";
						goto email1;
					}

				phonenumber1:
					cout << "|" << " " << setw(20) << "Phone Number: " << setw(7) << "|";
					cin >> phone_number;
					flag1 = Phone_Validator(phone_number);
					if (flag1 == false)
					{
						cout << setw(40) << " " << "Invalid Phone Number. Please Enter Again.\n";
						goto phonenumber1;
					}

				datearrival1:
					cout << "|" << " " << setw(20) << "Date of Arrival:" << setw(7) << "|";
					cin >> date_arrival;
					flag1 = arrival_Validator(date_arrival);
					if (flag1 == false)
					{
						cout << setw(40) << " " << "Invalid Date. Please Enter In Given Format (XX/XX/XXXX).\n";
						goto datearrival1;
					}

				days1:
					cout << "|" << " " << setw(20) << "NO. Of Days of Stay" << setw(7) << "|";
					cin >> days_stay;
					flag1 = integar_validator(days_stay);
					if (flag1 == false)
					{
						cout << setw(40) << " " << "Invalid Date. Please Enter Integer.\n";
						goto days1;
					}

					flag1 = update_info();
					if (flag1 == true)
					{
						cout << "\n" << setw(35) << " " << "|  =================================  |";
						cout << "\n" << setw(35) << " " << "|  INFORMATION SUCCESSFULLY UPDATED.  |";
						cout << "\n" << setw(35) << " " << "|  =================================  |";

					}
					else
					{
						cout << "Error\n";
					}

				}
				else if (op == 'N' || op == 'n')
				{
					goto update;
				}
				else
				{
					cout << "> INVALID INPUT.\n";
				}

			}


		}
		//for delete specific record
		else if (option == 3)
		{
			system("cls");
			cout << setw(30) << " " << "|" << " " << "Delete Record of a Specific Customer." << " " << "|\n";
			cout << setw(30) << " " << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			cout << "> Enter Room Number: ";
			cin >> room_number;

			bool flag1 = info_of_customer();
			if (flag1 == true)
			{
				cout << "\n\n> Is This the Customers Data You want to Delete?(Y/N): ";
				cin >> op;
				cout << endl;
				if (op == 'Y' || op == 'y')
				{
					flag1 = delete_info();
					if (flag1 == true)
					{
						cout << "\n" << setw(35) << " " << "|  =================================  |";
						cout << "\n" << setw(35) << " " << "|  INFORMATION SUCCESSFULLY DELETED.  |";
						cout << "\n" << setw(35) << " " << "|  =================================  |";
					}
					else
					{
						cout << "> Error\n";
					}
				}
				else if (op == 'N' || op == 'n')
				{
					goto update;
				}
				else
				{
					cout << "> INVALID INPUT.\n";
				}

			}
		}
	}
	else
	{
		cout << "Entered Option is Unavailable Please Choose Again.\n";
		_getch();
		goto choose2;
	}
}

// Functions For viewing information of customer

bool Rooms::info_of_customer()
{
	bool flag = false;
	int row_index;

	for (short j = 0; j < 3; j++)
	{
		for (short k = 0; k < 20; k++)
		{
			if (add_room[j][k] == room_number)
			{

				for (short i = 0; i < 60; i++)
				{
					if (cus_info[i][9] == room_number)
					{
						row_index = i;
						flag = true;
						break;
					}
				}
				if (flag == true)
				{
					cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
					cout << "\nDetail's Of the Customer Living in that Room\n";
					cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					cout << setw(18) << "\n> Name: " << setw(30) << cus_info[row_index][0] << setw(19) << "> Father Name:" << setw(30) << cus_info[row_index][1];
					cout << setw(18) << "\n> CNIC: " << setw(30) << cus_info[row_index][2] << setw(19) << "> Gender:" << setw(30) << cus_info[row_index][3];
					cout << setw(18) << "\n> City: " << setw(30) << cus_info[row_index][4] << setw(19) << "> E-Mail:" << setw(30) << cus_info[row_index][5];
					cout << setw(18) << "\n> Phone Number: " << setw(30) << cus_info[row_index][6] << setw(19) << "> Date of Arrival:" << setw(30) << cus_info[row_index][8];
					cout << setw(18) << "\n> Night's Stay: " << setw(30) << cus_info[row_index][10];

				}
				else if (flag == false)
				{
					cout << "\n" << setw(27) << " " << "   ======================   ";
					cout << "\n" << setw(27) << " " << "|  Entered Room Is Vacant  |";
					cout << "\n" << setw(27) << " " << "   ======================   ";
					_getch();
					return flag;
				}
			}

		}

	}
	if (flag == false)
	{
		cout << "\n" << setw(27) << " " << "   ======================   ";
		cout << "\n" << setw(27) << " " << "|  Room Is Not Available.  |";
		cout << "\n" << setw(27) << " " << "   ======================   ";
	}
	_getch();
	return flag;
}

// Functions For updating customers information

bool Rooms::update_info()
{
	bool flag = false;

	for (short i = 0; i < 60; i++)
	{
		if (cus_info[i][9] == room_number)
		{
			cus_info[i][0] = cus_name;
			cus_info[i][1] = father_name;
			cus_info[i][2] = CNIC;
			cus_info[i][3] = gender;
			cus_info[i][4] = city;
			cus_info[i][5] = e_mail;
			cus_info[i][6] = phone_number;
			cus_info[i][8] = date_arrival;
			cus_info[i][10] = days_stay;
			flag = true;
			break;
		}
	}
	return flag;
}

// Functions For deleteing customer information

bool Rooms::delete_info()
{
	bool flag = false;
	int index_row, index_col;
	for (short i = 0; i < 60; i++)
	{
		if (cus_info[i][9] == room_number)
		{
			cus_info[i][0] = "NV";
			cus_info[i][1] = "NV";
			cus_info[i][2] = "NV";
			cus_info[i][3] = "NV";
			cus_info[i][4] = "NV";
			cus_info[i][5] = "NV";
			cus_info[i][6] = "NV";
			cus_info[i][7] = "NV";
			cus_info[i][9] = "NV";
			cus_info[i][8] = "NV";
			cus_info[i][10] = "NV";
			flag = true;
			break;
		}
	}
	for (short i = 0; i < 3; i++)
	{
		for (short j = 0; j < 20; j++)
		{
			if (add_room[i][j] == room_number)
			{
				index_row = i;
				index_col = j;
				break;
			}
		}
	}
	available_rooms[index_row][index_col] = '*';

	return flag;
}

void Rooms::costumerHistory() {
	int option = 0;

	if (option == 1)
	{
		view_current();
	}
	else if (option == 2)
	{
		view_all_cus();
	}
	else if (option  ==  3)
	{

	}
	_getch();
}

void Rooms::view_current()
{
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << "\n" << setw(30) << " " << "DETAIL OF ALL THE CURRENTLY PRESENT CUSTOMERS\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

	for (int i = 0; i < 60; i++)
	{
		if (cus_info[i][0] != "NV")
		{
			cout << setw(18) << "\n> Name: " << setw(30) << cus_info[i][0] << setw(19) << "> Father Name:" << setw(30) << cus_info[i][1];
			cout << setw(18) << "\n> CNIC: " << setw(30) << cus_info[i][2] << setw(19) << "> Gender:" << setw(30) << cus_info[i][3];
			cout << setw(18) << "\n> City: " << setw(30) << cus_info[i][4] << setw(19) << "> E-Mail:" << setw(30) << cus_info[i][5];
			cout << setw(18) << "\n> Phone Number: " << setw(30) << cus_info[i][6] << setw(19) << "> Room Type:" << setw(30) << cus_info[i][7];
			cout << setw(18) << "\n> Date of Arrival:" << setw(30) << cus_info[i][8] << setw(19) << "> Room Number:" << setw(30) << cus_info[i][9];
			cout << setw(18) << "\n> Night's Stay: " << setw(30) << cus_info[i][10];
			cout << "\n====================================================================================";
		}
	}

}

// Functions For  viewing all history of customers.
void Rooms::view_all_cus()
{
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << "\n" << setw(30) << " " << "DETAIL OF ALL THE HISTORY CUSTOMERS\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	ifstream showdata("backend.txt");
	while (!showdata.eof()) {
		for (short j = 0; j < 60; j++)
		{
			if (cus_history[j][0] == "NV")
			{
				showdata >> cus_history[j][0];
				showdata >> cus_history[j][1];
				showdata >> cus_history[j][2];
				showdata >> cus_history[j][3];
				showdata >> cus_history[j][4];
				showdata >> cus_history[j][5];
				showdata >> cus_history[j][6];
				showdata >> cus_history[j][7];
				showdata >> cus_history[j][8];
				showdata >> cus_history[j][9];
				showdata >> cus_history[j][10];
				j++;
			}
		}
	}
	for (short i = 0; i < 60; i++)
	{
		if (cus_history[i][0] != "NV")
		{
			cout << setw(18) << "\n> Name: " << setw(30) << cus_history[i][0] << setw(19) << "> Father Name:" << setw(30) << cus_history[i][1];
			cout << setw(18) << "\n> CNIC: " << setw(30) << cus_history[i][2] << setw(19) << "> Gender:" << setw(30) << cus_history[i][3];
			cout << setw(18) << "\n> City: " << setw(30) << cus_history[i][4] << setw(19) << "> E-Mail:" << setw(30) << cus_history[i][5];
			cout << setw(18) << "\n> Phone Number: " << setw(30) << cus_history[i][6] << setw(19) << "> Room Type:" << setw(30) << cus_history[i][7];
			cout << setw(18) << "\n> Date of Arrival:" << setw(30) << cus_history[i][8] << setw(19) << "> Room Number:" << setw(30) << cus_history[i][9];
			cout << setw(18) << "\n> Night's Stay: " << setw(30) << cus_history[i][10];
			cout << "\n====================================================================================";
			i++;
		}
	}
	_getche();
}