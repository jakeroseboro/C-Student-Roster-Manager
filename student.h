#pragma once
#include "degree.h"
#include <string>
using std::string;

class Student 
{
public: 
	const static int daysToCompleteSize = 3;

protected: 
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	string studentAge;
	int daysToComplete[daysToCompleteSize];
	DegreeProgram dProgram;

public:

	//Empty constructor
	Student();

	//Full constructor
	Student(string studentID, string firstName, string lastName, string emailAddress, string studentAge, int daysToComplete[], DegreeProgram program);

	//Accessors
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	string getStudentAge();
	int* getDaysToComplete();
	DegreeProgram getDegreeProgram();

	//Mutators
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setStudentAge(string studentAge);
	void setDaysToComplete(int daysToComplete[]);
	void setDegreeProgram(DegreeProgram d);

	void print();

	//Deconstructor
	~Student();
};