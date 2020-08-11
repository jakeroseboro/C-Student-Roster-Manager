#include "roster.h"
using std::cout;
using std::cerr;
using std::endl;

const int numStudents = 5;
string studentData[numStudents] =
{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Jacob,Roseboro,jros253@wgu.edu,20,30,30,30,SOFTWARE"
};

Roster::Roster()
{
	this->capacity = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}

Roster::Roster(int capacity)
{
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new Student * [capacity];
}

void Roster::parseAdd(string row)
{
	if (lastIndex < capacity)
	{
		lastIndex++;

		int dArray[Student::daysToCompleteSize];

		if (row.back() == 'Y')
		{
			this->classRosterArray[lastIndex] = new Student();
			classRosterArray[lastIndex]->setDegreeProgram(DegreeProgram::SECURITY);
		}
		else if (row.back() == 'K')
		{
			this->classRosterArray[lastIndex] = new Student();
			classRosterArray[lastIndex]->setDegreeProgram(DegreeProgram::NETWORK);
		}
		else if (row.back() == 'E')
		{
			this->classRosterArray[lastIndex] = new Student();
			classRosterArray[lastIndex]->setDegreeProgram(DegreeProgram::SOFTWARE);
		}
		else if (row.back() == 'D')
		{
			this->classRosterArray[lastIndex] = new Student();
			classRosterArray[lastIndex]->setDegreeProgram(DegreeProgram::UNDECIDED);
		}
		else
		{
			cerr << "Invalid degree type, exiting now...\n";
			exit(-1);
		}

		//Set ID
		int rhs = studentData[lastIndex].find(",");
		classRosterArray[lastIndex]->setStudentID(studentData[lastIndex].substr(0, rhs));

		//Set first name
		int lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->setFirstName(studentData[lastIndex].substr(lhs, rhs - lhs));

		//Set last name
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->setLastName(studentData[lastIndex].substr(lhs, rhs - lhs));

		//Set email address
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->setEmailAddress(studentData[lastIndex].substr(lhs, rhs - lhs));

		//Set age
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->setStudentAge(studentData[lastIndex].substr(lhs, rhs - lhs));

		//Set days to complete
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		dArray[0] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		//Set days to complete
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		dArray[1] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		//Set days to complete
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		dArray[2] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		//Set all of the days
		classRosterArray[lastIndex]->setDaysToComplete(dArray);

	}
	else
	{
		cerr << "Error, list has exceeded capacity!\n Now exiting...";
		exit(-1);
	}

}

void Roster::print_All()
{
	for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray)[i]->print();
}

bool Roster::remove(string studentID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->getStudentID() == studentID)
		{
			found = true;
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			lastIndex--;
		}
	}
	return found;
}


void Roster::printAverageDays(string studentID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->getStudentID() == studentID)
		{
			found = true;
			int* days = classRosterArray[i]->getDaysToComplete();
			cout << "Average number of days of student " << studentID << " is " << (days[0] + days[1] + days[2]) / 3 << "." << endl;
		}
	}
	if (!found) cout << "Student not found!\n";
}

void Roster::printInvalidEmails()
{
	cout << "Displaying invalid email addresses: \n" << endl;
	for (int i = 0; i <= lastIndex; i++)
	{
		bool any = false;
		string iEmail = classRosterArray[i]->getEmailAddress();
		for (int j = 0; j < classRosterArray[i]->getEmailAddress().length(); j++)
		{
			if (iEmail[j] == ' ')
			{
				cout << '"' << iEmail << '"' << " is an invalid email!\n";
			}
		}
		if (iEmail.find("@") == string::npos)
		{
			cout << '"' << classRosterArray[i]->getEmailAddress() << '"' << " is an invalid email!\n";
		}
		else if (iEmail.find(".") == string::npos)
		{
			cout << '"' << classRosterArray[i]->getEmailAddress() << '"' << " is an invalid email!\n";
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram d)
{
	cout << "Printing students with degree type: " << DegreeProgramStrings[d] << endl << endl;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (classRosterArray[i]->getDegreeProgram() == d)
		{
			classRosterArray[i]->print();
		}
	}
}

Roster::~Roster()
{
	for (int i = 0; i <= lastIndex; i++)
	{
		delete this->classRosterArray[i];
	}
	delete classRosterArray;
}
