#include "plan_event.h"
using namespace std;

//Molina Nhoung, CS163, 4/13/23, Program 1
//The purpose of this code in this file is to implement the day functions
//and LLL of the days and the activities LLL within the days LLL implemented
//with a tail pointer

//Constructor is setting the data members to their equivalent zeros
travel_list::travel_list()
{
	head = nullptr;
	tail = nullptr;
}

//Destructor will deallocate the memory by deleting them
travel_list::~travel_list()
{
}

//Add a new day to the end of the LLL
int travel_list::add_day(const client & in_client)
{
	if (in_client.c_day[0] == '\0' || in_client.c_day == nullptr)
		return 0;

	if (!head)
	{
		head = new daynode;
		tail = head;
		head->next = nullptr;
		head->name = new char[strlen(in_client.c_day) + 1];
		strcpy(head->name, in_client.c_day);
		return 1;
	}

	daynode * current = head;
	bool found = false;
	while (current && !found)
	{
		if (strcmp(current->name, in_client.c_day) == 0)
		{
			found = true;
		}
		current = current->next;
	}

	if (found)
		return 2;

	tail->next = new daynode;
	tail = tail->next;
	tail->next = nullptr;
	tail->name = new char [strlen(in_client.c_day) + 1];
	strcpy(tail->name, in_client.c_day);
	return 3;
}

//Display all the days in the list
int travel_list::display_all()
{
	if (!head || head->name[0] == '\0')
		return 0;
	daynode * current = head;
	while (current)
	{
		cout << "\nDay: " << current->name << endl;
		current = current->next;
	}
	return 1;
}

//Add an activity for a given day at the end of the activity LLL
int travel_list::add_activity(client & in_client)
{
	if (!head)
		return 0;
	daynode * current = head;
	while (current)
	{
		if (strcmp(current->name, in_client.c_day) == 0)
			current->head->activities->copy_act(in_client);
		current = current->next;

	}
	return 1;
}



activity_list::activity_list()
{
	head = nullptr;
}
activity_list::~activity_list()
{
}
int activity_list::copy_act(const client & in_client)
{

	if (!head)
	{
		head = new activitynode;
		head->next = nullptr;
		head->time = in_client.c_time;
		head->activity_name = new char [strlen(in_client.c_act) + 1];
		strcpy(head->activity_name, in_client.c_act);
		head->location = new char [strlen(in_client.c_locat) + 1];
		strcpy(head->location, in_client.c_locat);
		head->description = new char [strlen(in_client.c_desc) + 1];
		strcpy(head->description, in_client.c_desc);
		return 0;
	}

	bool found = false;
	activitynode * current = head;
	activitynode * previous = head;
	while (current && !found)
	{
		if (in_client.c_time < current->time)
			found = true;
		previous = current;
		current = current->next;
	}
	
	previous->next = new activitynode;
	previous = previous->next;
	previous->next = current;
	previous->time = in_client.c_time;
	previous->activity_name = new char [strlen(in_client.c_act) + 1];
	strcpy(previous->activity_name, in_client.c_act);
	previous->location = new char [strlen(in_client.c_locat) + 1];
	strcpy(previous->location, in_client.c_locat);
	previous->description = new char [strlen(in_client.c_desc) + 1];
	strcpy(previous->description, in_client.c_desc);
	return 0;
}

int activity_list::find_act_day(char matching_activity[])
{return 0;}

