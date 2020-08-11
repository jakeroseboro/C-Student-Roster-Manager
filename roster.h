#pragma once
#include <string>
#include <iostream>
#include "student.h"

class Roster
{
private:
	//Index of last student in roster
	int lastIndex; 
	//The max size of the roster
	int capacity; 
	Student** classRosterArray; 
public:
	//Empty constructor
	Roster(); 
	Roster(int capacity);

	void parseAdd(string datarow);
	void print_All();
	bool remove(string studentID);
	void printAverageDays(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram d);

	//Deconstructor
	~Roster(); 
};