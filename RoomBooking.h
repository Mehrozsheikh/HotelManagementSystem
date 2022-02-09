#pragma once
#include<iostream>
#include"Validator.h"
#include"Rooms.h"
using namespace std;

class RoomBooking : public Validator, public Rooms
{
private:
	char available_rooms[3][20];
	
	string add_room[3][20];
public:
	
};