// ConsoleApplication7.cpp : Defines the entry point for the console application.
//

// Support Ticket revised.cpp : Defines the entry point for the console application.
//

// Support Ticket .cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

static int idGenerator = 1;

class Ticket {

private:

	int id;
	string issueStatus;
	string issueType;
	string issuePriority;
	string callerName;
	string descriptionofIssue;
	int numberofusersimpacted;

public:

	Ticket() {
		id = idGenerator++;
		issueStatus = "";
		issueType = "";
		issuePriority = "";
		callerName = "";
		descriptionofIssue = "";
		numberofusersimpacted = 0;
	}

	//void idGeneratorSetter() {   ++idGenerator;  id = idGenerator; }
	//int Ticket::idGenerator = 1;

	void get_ID() {
		cout << " " << endl;
		cout << "Your Ticket ID is  ";
		cout << id << endl;
	}

	string get_Priority() { return issuePriority; }
	string get_Type() { return issueType; }
	

	void ShowTicket() {
		cout << "Ticket ID ";
		cout << id << endl;
		cout << "CustomerName: " + callerName << endl;
		cout << "Type of Issue: " + issueType << endl;
		cout << "Status: " + issueStatus << endl;
		cout << "Ticket Description: " + descriptionofIssue << endl;
		cout << "Priority: " + issuePriority << endl;
		
		cout << "Number of Users Impacted ";
		cout << numberofusersimpacted << endl;
	}
	void  CaptureTicket( string y,  string w, string v, int u) {
		 issueType = y;
		 callerName = w;
		 descriptionofIssue = v;
		 numberofusersimpacted = u;

		 if (numberofusersimpacted < 10) { issuePriority = "low"; }
		 if (numberofusersimpacted >= 10 && numberofusersimpacted < 50) { issuePriority = "medium"; }
		 if (numberofusersimpacted >= 50) { issuePriority = "high"; }


	}
	void CloseTicket() { issueStatus = "Closed"; }
	void OpenTicket() { issueStatus = "Open"; }
};



int main()
{

	int z = 0;
	int count = 0;
	char quit = 'a';
	string delay;

	
	
	




	Ticket stackofTickets[100];

	while (count < 101 && quit != 'n')
	{
		

		string name;
		string issue;
		string description;
		int usersaffected;
	
		cout << "*************************"<<endl;

		cout << "Please enter Name "<<endl;
		getline(cin,name);
		
		cout << "please enter type of issue (server,application,access)"<<endl;
		cin >> issue;


		if (issue != "server" && issue != "application" && issue != "access")
		{
			while (issue != "server" && issue != "application" && issue != "access") { cout << "Please input the issue you are experiencing" << endl; cin >> issue; }
			
		}
		

		cout << "please enter Description ";
		cin >> description;
		cout << "Please enter number of users affected by the issue ";
		cin >> usersaffected;

		cout << "*************************"<<endl;



		stackofTickets[count].CaptureTicket( issue, name, description, usersaffected);  
		stackofTickets[count].OpenTicket();
		stackofTickets[count].get_ID();
		
		count++;


		cout << "Would you like to input another ticket any key for yes  n for no" << endl;
		
		cin >> quit;

	}
	cout << "Total number of Tickets collected ";
	cout << count << endl;

	for (int i = 0; i < count; i++) { stackofTickets[i].ShowTicket(); }

	stackofTickets[0].CloseTicket();
	cout << " " << endl;
	cout << "Here is the First Ticket";
	stackofTickets[0].ShowTicket();
	
	
	cout << "THis is the end of program" << endl;
	cin >> delay;

	return 0;
}

