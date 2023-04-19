#include <iostream>
#include <cctype>
#include <cstring>

//Molina Nhoung, CS163, 4/11/23, Program 1
//The purpose of this file is to organize data and functions into classes and structs
//so that other programers are able to examine them and know how to use the program to
//allow the user to enter in days and activities within these days.

//Constants
int const SIZE {200};

//Structs
struct daynode
{
	char * name;		//name of the day of the week
	daynode * next;		//a next pointer for the day node
	struct activitynode * head;	//a head pointer to the list of activities
	class activity_list * activities;
};

struct activitynode
{
	int time;	//the time of the activity
	char * activity_name;	//name of the activity
	char * location; 	//location of the activity
	char * description;	//description of the activity
	//class activity_list * activities;
	activitynode * next;	//a next pointer for the activity node
};

struct client
{
	char c_day[SIZE];
	int c_time;
	char c_act[SIZE];
	char c_locat[SIZE];
	char c_desc[SIZE];
};
//Classes
class travel_list
{
	public:
		travel_list();	//constructor
		~travel_list();	//destructor
		int add_day(const client & in_client);	//add a new day to the list by passing the struct and returning a number for error or success
		int display_all();	//display all of the days and return a number for success or error
		int add_activity(client & in_client);	//add a new activity to the day by passing the needed info and returning a number for error or success
		int remove_day(char matching_day[]);	//pass in a day from the user to display all activities in that day
		int find_act_day(char matching_activity[]);	//pass in the activity to find the day it has the activity and display it, return success or error
	private:
		daynode * head;
		daynode * tail;
};

class activity_list
{
	public:
		activity_list();	//constructor
		~activity_list();	//destructor
		int copy_act(const client & in_client);	//add a new activity to the day by passing the needed info and returning a number for error or success
		int display_act();
		int find_act_day(char matching_activity[]);	//pass in the activity to find the day it has the activity and display it, return success or error
	private:
		activitynode * head;
};


//Functions
int menu();
