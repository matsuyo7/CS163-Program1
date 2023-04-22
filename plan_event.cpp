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
	daynode * current = head;
	while (current)
	{
		current = current->next;
		delete [] head->name;
		head->name = nullptr;
		delete head;
		head = current;
	}
	head = nullptr;
	tail = nullptr;
}

//Add a new day to the end of the LLL
int travel_list::add_day(char day[])
{
	//If the client sent in the wrong information
	if (day[0] == '\0' || day == nullptr)
		return 0;
	//If there's nothing in the list then add a new day
	if (!head)
	{
		head = new daynode;
		tail = head;
		head->next = nullptr;
		head->name = new char[strlen(day) + 1];
		strcpy(head->name, day);
		return 1;
	}
	//Goes through the list to see if there's already a day in there
	daynode * current = head;
	bool found = false;
	while (current && !found)
	{
		if (strcmp(current->name, day) == 0)
		{
			found = true;
		}
		current = current->next;
	}
	//If the input day matches with the list day then we exit
	if (found)
		return 2;
	//Adds a day to the end of the list
	tail->next = new daynode;
	tail = tail->next;
	tail->next = nullptr;
	tail->name = new char [strlen(day) + 1];
	strcpy(tail->name, day);
	return 3;
}

//Display all the days in the list
int travel_list::display_all()
{
	if (!head)
		return 0;
	display_all(head);
	return 1;
}

//Displays the days recursively
int travel_list::display_all(daynode * & head)
{
	if (!head)
		return 0;
	cout << "\n" << head->name;
	head->activities.display_act();
	return display_all(head->next);
}

//Add an activity for a given day at the end of the activity LLL
int travel_list::add_activity(client & in_client)
{
	if (!head || in_client.c_day[0] == '\0')
		return 0;
	daynode * current= head;
	bool found = false;
	//Loops through the list
	while (current)
	{
		if (strcmp(current->name, in_client.c_day) == 0)
		{
			current->activities.copy_act(in_client);
			found = true;
		}
		current = current->next;

	}
	if (found)
		return 1;
	else
		return 0;
}
//Finds a day match with the client's day
bool travel_list::day_match(client & in_client)
{
	if (!head)
		return false;
	daynode * current = head;
	bool match = false;
	while (current && !match)
	{
		if(strcmp(in_client.c_day, current->name) == 0)
			match = true;
		current = current->next;
	}
	return match;
}
//Finds a day to then display the acivities within that day
int travel_list::find_act_day(char matching_day[])
{
	if (!head)
		return 0;
	daynode * current = head;
	bool found = false;
	while (current && !found)
	{
		if (strcmp(current->name, matching_day) == 0)
		{
			found = true;
		}
		else
		{
			current = current->next;
		}
	}
	if (found && current)
	{
		current->activities.display_act();
		return 1;
	}
	return 0;
}
int travel_list::find_day(char matching_act[])
{
	if (!head || matching_act[0] == '\0')
		return 0;
	daynode * current = head;
	bool found = false;
	bool match = false;
	while (current)
	{
		match = current->activities.act_match(matching_act);
		if (match)
			found = true;
		else
			current = current->next;
	}
	if (!found)
		return 0;
	cout << current->name << endl;
	return 1;
}

//Finds a match to the day and then removes it and its activities
int travel_list::remove_day(char matching_day[])
{
	//if list is empty
	if (!head)
		return 0;
	daynode * current = head;
	daynode * previous = head;
	bool found = false;
	while (current && !found)
	{
		//if the name in the list matches the day the client wants to remove
		if (strcmp(current->name, matching_day) == 0)
		{
			found = true;
		}
		else 
		{
			previous = current;
			current = current->next;
		}
	}
	//If not found
	if (!found)
		return 0;

	//if the day they want to remove is the first day
	if (current == head)
	{
		head = current->next;
	}
	else
		previous->next = current->next;
	//if they found the day to remove
	current->activities.remove_act();
	delete [] current->name;
	delete current;
	return 1;
}
//Activity constructor to initiate the data members
activity_list::activity_list()
{
	head = nullptr;
}
//Activity destructor to deallocate the data members
activity_list::~activity_list()
{
	activitynode * current = head;
	while (head)
	{
		current	= current->next;
		head->time = 0;
		delete [] head->activity_name;
		head->activity_name = nullptr;
		delete [] head->location;
		head->location = nullptr;
		delete [] head->description;
		head->description = nullptr;
		delete head;
		head = current;
	}
	head = nullptr;
}
//Adds the activities into the list sorted by the time
int activity_list::copy_act(const client & in_client)
{
	//If there's nothing
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
		return 1;
	}

	bool same = false;
	bool less = false;
	activitynode * current = head;
	activitynode * previous = head;
	activitynode * temp = head;
	while (current && !same && !less)
	{
		//If the time is the same
		if (in_client.c_time == current->time)
			same = true;
		//if the client's time is less than the current time
		else if (in_client.c_time < current->time)
			less = true;
		else
		{
			previous = current;
			current = current->next;
		}
	}
	//if the time is the same then return an error
	if (same)
		return 1;
	//if there is only one item in the list and it's less than the time already in the list
	if (current == head && less)
	{
		temp = new activitynode;
		temp->next = current;
		head = temp;
		temp->time = in_client.c_time;
		temp->activity_name = new char [strlen(in_client.c_act) + 1];
		strcpy(temp->activity_name, in_client.c_act);
		temp->location = new char [strlen(in_client.c_locat) + 1];
		strcpy(temp->location, in_client.c_locat);
		temp->description = new char [strlen(in_client.c_desc) + 1];
		strcpy(temp->description, in_client.c_desc);
		return 1;
	}
	//add to the list
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
	return 1;
}
//Dislpays the activities and is called from the travel_list
int activity_list::display_act()
{
	if (!head)
		return 0;
	int display = display_act(head);
	return display;
	
}
//Displays the activities recursively
int activity_list::display_act(activitynode * head)
{
	if (!head)
		return 1;
	cout << "\n" << head->time << ":00"
		<< "\tActivity: " << head->activity_name
		<< "\n\tLocation: " << head->location
		<< "\n\tDescription: " << head->description << endl;
	return display_act(head->next);
}
//Removes activities within a day
int activity_list::remove_act()
{
	if (!head)
		return 0;
	activitynode * current = head;
	while (current)
	{
		activitynode * temp = current;
		current = current->next;
		temp->time = 0;
		delete [] temp->activity_name;
		delete [] temp->location;
		delete [] temp->description;
		delete temp;
	}
	head = nullptr;
	return 1;
}
		
//Finds a day to match and then displays the activities within the day
bool activity_list::act_match(char matching_activity[])
{
	if (!head)
		return false;
	activitynode * current = head;
	bool found = false;
	while (current && !found)
	{
		if (!strcmp(current->activity_name, matching_activity))
		{
			found = true;
		}
		else
		{
			current = current->next;
		}
	}
	return found;
}

