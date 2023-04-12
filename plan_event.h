#include <iostream>
#include <cctype>
#include <cstring>

//Molina Nhoung, CS162, 4/11/23, Program 1
//The purpose of this file is to organize data and functions into classes and structs
//so that other programers are able to examine them and know how to use the program to
//allow the user to enter in days and activities within these days.

//Constants
int const SIZE {200};

//Structs
struct day
{
	char * name;		//name of the day of the week
	day * next;		//a next pointer for the day node
	activity * head;	//a head pointer to the list of activities
};

struct activity
{
	int time;		//the time of the activity
	char * activity_name;	//name of the activity
	char * location; 	//location of the activity
	char * description;	//description of the activity
};

//Classes
class day_list
{
	public:
		day_list();	//constructor
		~day_list();	//ddestructor
		int add_day(day & day_to_add)	//add a new day to the list by passing the struct and returning a number for error or success
		int display_all();	//display all of the days and return a number for success or error
		int add_activity(activity & act_to_add)	//add a new activity to the day by passing the struct and returning a number for error or success
		int find_day(char matching_day[]);	//pass in a day from the user to display all activities in that day
		int find_act_day(char matching_activity[])	//pass in the activity to find the day it has the activity and display it, return success or error
	private:
		node * head;
		node * tail;
};

//I wanted to test out having two classes, would I need to migrate whats in the activity struct into the private section of this class? Same with day?
/*
class activity_list
{
	public:
		activity_list();	//constructor
		~activity_list();	//destructor
		int add_activity(activity & act_to_add)	//add a new activity to the day passing the struct and returning a number for error or success
		int find_act_day(char matching_activity[])	//pass in the activity to find the day it has the activity and display it, return success or error
	private:
		node * head;
		node * tail;
};*/
