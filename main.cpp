#include "plan_event.h"
using namespace std;

//Molina Nhoung, CS163, 4/13/23, Program 1
//The purpose of the code in this file is to act as the client program
//to send in information to the ADT to be used, and then be returned numbers
//for errors or successes.

//Prototypes
int menu();
void add_day(travel_list & travel, char day[]);
void add_act(travel_list & travel, client & one_client);
void all_display(travel_list & travel);
void see_act(travel_list & travel, char aday[]);
void see_day(travel_list & travel, char act[]);
void remove_day(travel_list & travel, char rday[]);

int main()
{
	travel_list travel;
	//activity_list activities;
	client one_client;
	int option {0};
	char day[SIZE];
	char rday[SIZE];
	char aday[SIZE];
	char act[SIZE];

	cout << "\n***TRAVEL PLANNING***"
		"\nPlan your trip up to an entire week filled with events"
		"\nand their descriptions at certain times of the day (24hr cycle)"
	     	"\nThe activities will be in numerical order from 1hr to 24 hr" << endl;

	do
	{
		option = menu();
		//When user picks to add a day
		if (option == 1)
		{
			add_day(travel, day);
		}
		//When user picks to add an activity
		if (option == 2)
		{
			add_act(travel, one_client);
		}
		//When user picks to display all days and their activities
		if (option == 3)
		{
			all_display(travel);
		}
		//When user picks to see activities within a day
		if (option == 4)
		{
			see_act(travel, aday);
		}
		//When user pick to see a day matching the activity
		if (option == 5)
		{
			see_day(travel, act);
		}
		//When user picks to remove a day
		if (option == 6)
		{
			remove_day(travel, rday);
		}
	} while (option != 7);

	return 0;
}

//Functions
int menu()
{
	int option = 0;
	do
	{
		cout << "\n\n***MENU***"
			"\n1. Add a new day"
			"\n2. Add an activity"
			"\n3. Display all days"
			"\n4. Display all activities for a particular day"
			"\n5. Display what day has a particular activity"
			"\n6. Remove a particular day"
			"\n7. Quit" 
			"\n\nPick an option (1-7): ";
		cin >> option;
		cin.ignore(100,'\n');
		if (option < 1 || option > 7)
			cerr << "\nOption out of range, try again" << endl;
	} while (option < 1 || option > 7);
	return option;
}
//Ask the user what day they want to add
void add_day(travel_list & travel, char day[])
{
	cout << "\n\nWhat day of the week are you adding?: ";
	cin.get(day, SIZE, '\n');
	cin.ignore(100, '\n');
	day[0] = toupper(day[0]);
	int added = travel.add_day(day);
	if (added == 1)
		cout << "\n\nAdded day" << endl;
	else if (added == 2)
		cout << "\n\nDay already added" << endl;
	else if (added == 3)
		cout << "\n\nDay added to the end" << endl;
	else
		cerr << "\n\nDay not added" << endl;
}
//Ask the user what day they want to add the activities to
void add_act(travel_list & travel, client & one_client)
{
	cout << "\nWhat day do you want to add the activity?: ";
	cin.get(one_client.c_day, SIZE, '\n');
	cin.ignore(100, '\n');
	one_client.c_day[0] = toupper(one_client.c_day[0]);
	bool match = travel.day_match(one_client);
	if (match)
	{
		do
		{
			cout << "\n\nWhat time do you want to add the activity (24hr cycle): ";
			cin >> one_client.c_time;
			cin.ignore(100, '\n');

			if (one_client.c_time < 1 || one_client.c_time > 24)
				cout << "\nTime is not within 24hr" << endl;
		} while (one_client.c_time < 1 || one_client.c_time > 24);
		cout << "\n\nWhat's the name of the acivity?: ";
		cin.get(one_client.c_act, SIZE, '\n');
		cin.ignore(100, '\n');
		cout << "\n\nWhere is it located?: ";
		cin.get(one_client.c_locat, SIZE, '\n');
		cin.ignore(100 ,'\n');
		cout << "\n\nDescription of activity: ";
		cin.get(one_client.c_desc, SIZE, '\n');
		cin.ignore(100, '\n');
		int added_act = travel.add_activity(one_client);
		if (added_act == 1)
			cout << "\nAdded activity" << endl;
		else
			cout << "\nActivity not added" << endl;
	}
	else
		cout << "\nDay not found" << endl;
}
//Display the days and the activities to the user
void all_display(travel_list & travel)
{
	//activities.display_act();
	int display = travel.display_all();
	if (display == 0)
		cout << "\nNothing to display" << endl;
}
//Display the activities from one day
void see_act(travel_list & travel, char aday[])
{
	cout << "\nWhat day do you want to see the activities: ";
	cin.get(aday, SIZE, '\n');
	cin.ignore(100, '\n');
	aday[0] = toupper(aday[0]);
	int see = travel.find_act_day(aday);
	if (see == 0)
		cout << "\nCouldn't find the day" << endl;
}
//Displays the day that the activity is from
void see_day(travel_list & travel, char act[])
{
	cout << "\nWhat activity do you want to see the day: ";
	cin.get(act, SIZE, '\n');
	cin.ignore(100, '\n');
	int see = travel.find_day(act);
	if (see == 0)
		cout << "\nCouldn't find the activity" << endl;
}
	
//Removes a day the user picks
void remove_day(travel_list & travel, char rday[])
{
	cout << "\nWhat day do you want to remove?: ";
	cin.get(rday, SIZE, '\n');
	cin.ignore(100, '\n');
	rday[0] = toupper(rday[0]);
	int remove = travel.remove_day(rday);
	if (remove == 1)
		cout << "\nRemove success" << endl;
	else
		cout << "\nUnable to remove" << endl;
}
