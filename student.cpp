#include "student.h"
#include <iostream>
#include <iomanip>
using std::cout;
using std::left;
using std::setw;
using std::endl;

//Empty constructor
Student::Student() 
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->studentAge = "";
	for (int i = 0; i < 3; i++) this->daysToComplete[i] = daysToComplete[i];
	this->dProgram = DegreeProgram::UNDECIDED; 
};

//Full constructor
Student::Student(string studentID, string firstName, string lastName, string emailAddress, string studentAge, int daysToComplete[], DegreeProgram program) 
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->studentAge = studentAge;
	for (int i = 0; i < 3; i++) this->daysToComplete[i] = daysToComplete[i];
	this->dProgram = program;
}

//Getters
string Student::getStudentID()
{
	return studentID;
}

string Student::getFirstName() 
{
	return firstName;
}

string Student::getLastName() 
{
	return lastName;
}

string Student::getEmailAddress() 
{
	return emailAddress;
}

string Student::getStudentAge() 
{
	return studentAge;
}

int* Student::getDaysToComplete() 
{
	return daysToComplete;
}

inline DegreeProgram Student::getDegreeProgram()
{
	return dProgram;
}

//Setters
void Student::setStudentID(string studentID) 
{
	this->studentID = studentID;
}

void Student::setFirstName(string firstName) 
{
	this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
	this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress)
{
	this->emailAddress = emailAddress;
}

void Student::setStudentAge(string studentAge)
{
	this->studentAge = studentAge;
}

void Student::setDaysToComplete(int daysToComplete[])
{

for (int i = 0; i < daysToCompleteSize; i++) this->daysToComplete[i] = daysToComplete[i];

}

void Student::setDegreeProgram(DegreeProgram d) 
{
	this->dProgram = d;
}

void Student::print() 
{
	cout << left << "Student ID: " << setw(1) << studentID;
	cout << left << "\tFirst Name: " << setw(5) << firstName;
	cout << left << "\tLast Name: " << setw(5) << lastName;
	cout << left << "\tEmail: " << setw(5) << emailAddress;
	cout << left << "Age: " << setw(5) << studentAge;
	cout << left << "\tDays In Course: {" << daysToComplete[0] << ", ";
	cout << left << daysToComplete[1] << ", ";
	cout << left << daysToComplete[2] << "}";
	cout << left << "\tDegree Program: " << setw(5) <<  DegreeProgramStrings[getDegreeProgram()] << endl << endl << endl;
}

Student::~Student() {

};