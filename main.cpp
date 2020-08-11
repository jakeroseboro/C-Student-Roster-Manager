#include "roster.h"
using std::cout;
using std::endl;

int numStudents = 5;
static string studentData[5] =
{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Jacob,Roseboro,jros253@wgu.edu,20,30,30,30,SOFTWARE"
};
int main()
{
	cout << "WGU Scripting and Programming-Applications - C867\nWritten in C++ on Visual Studio \nWGU Student ID: #001307315 \nJacob Roseboro\n\n\n";

	//Creating a new roster
	Roster* classRoster = new Roster(numStudents);

	//Parsing through the data
	for (int i = 0; i < numStudents; i++)
	{
		classRoster->parseAdd(studentData[i]);
	}

	//Printing all of the data
	cout << "Print all:\n\n";
	classRoster->print_All();

	//Printing invalid emails
	cout << "\n\n";
	classRoster->printInvalidEmails();

	//Printing the average days
	cout << "\n\n";
	cout << "Print all student's average days\n";


	for (int i = 1; i <= numStudents; i++)
	{
		classRoster->printAverageDays("A" + std::to_string(i));
		cout << "\n";
	}


	cout << "\n\n";
	classRoster->printByDegreeProgram(SOFTWARE);


	cout << "\n\n";
	cout << "Removing A3\n";
	if (classRoster->remove("A3"))
	{
		classRoster->print_All();
		numStudents--;
	}
	else cout << "Student not found!\n";

	cout << "Trying to remove A3 agian\n";
	if (classRoster->remove("A3")) classRoster->print_All();
	else cout << "Student not found!\n";

	classRoster->~Roster();
}