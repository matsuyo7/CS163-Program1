#include "plan_event.h"
using namespace std;

//Molina Nhoung, CS163, 4/13/23, Program 1
//The purpose of the code in this file is to act as the client program
//to send in information to the ADT to be used, and then be returned numbers
//for errors or successes.

int main()
{
	travel_list travel;
	//activity_list activities;
	client one_client;
	int option {0};
	int added {0};
	int display {0};
	int added_act {0};
	char rday[SIZE];
	char aday[SIZE];
	int see {0};
	int remove {0};
	char again {'y'};

	cout << "\n***TRAVEL PLANNING***"
		"\nPlan your trip up to an entire week filled with events"
		"\nand their descriptions at certain times of the day (24hr cycle)" << endl;

	do
	{
		option = menu();
		if (option == 1)
		{
			cout << "\n\nWhat day of the week are you adding?: ";
			cin.get(one_client.c_day, SIZE, '\n');
			cin.ignore(100, '\n');
			one_client.c_day[0] = toupper(one_client.c_day[0]);
			added = travel.add_day(one_client);
			if (added == 1)
				cout << "\n\nAdded day" << endl;
			else if (added == 2)
				cout << "\n\nDay already added" << endl;
			else if (added == 3)
				cout << "\n\nDay added to the end" << endl;
			else
				cerr << "\n\nDay not added" << endl;
		}
		if (option == 2)
		{
			cout << "\nWhat day do you want to add the activity?: ";
			cin.get(one_client.c_day, SIZE, '\n');
			cin.ignore(100, '\n');
			one_client.c_day[0] = toupper(one_client.c_day[0]);
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
			//activities.copy_act(one_client);
			added_act = travel.add_activity(one_client);
			if (added_act == 1)
				cout << "\nAdded activity" << endl;
			else
				cout << "\nActivity not added" << endl;
		}
		if (option == 3)
		{
			//activities.display_act();
			display = travel.display_all();
			if (display == 0)
				cout << "\nNothing to display" << endl;
		}
		if (option == 4)
		{
			cout << "\nWhat day do you want to see the activities: ";
			cin.get(aday, SIZE, '\n');
			cin.ignore(100, '\n');
			see = travel.find_act_day(aday);
			if (see == 0)
				cout << "\nCouldn't find the day" << endl;
		}

		if (option == 6)
		{
			cout << "\nWhat day do you want to remove?: ";
			cin.get(rday, SIZE, '\n');
			cin.ignore(100, '\n');
			remove = travel.remove_day(rday);
			if (remove == 1)
				cout << "\nRemove success" << endl;
			else
				cout << "\nUnable to remove" << endl;
		}
	/*	do
		{
			cout << "\nDo you want to do it again? (y/n): ";
			cin >> again;
			cin.ignore(100, '\n');
			if (toupper(again) != 'Y' && toupper(again) != 'N')
				cout << "\nInvalid response, try again" << endl;
		} while (toupper(again) != 'Y' && toupper(again) != 'N');*/
	} while (option != 7/* && toupper(again) == 'Y'*/);

	return 0;
}

//Functions
int menu()
{
	int option = 0;
	do
	{
		cout << "\n***MENU***"
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
