#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "EducationDBClasses.h"

using namespace std;

void newAddition();
void viewExisting();
void welcomeScreen();
char chooseCategory();
void typistType_Add();
char chooseTypistCategory();
void addTeacher();
void addOfficer();
void addRegularTypist();
void addCasualTypist();
void viewTeacher();
void viewOfficer();
void typistType_View();
void viewRegularTypist();
void viewCasualTypist();
void exitCondition();

int main(){
	//displays welcome message and calls the welcome screen
	cout <<"EDU Database: Welcome!"<<endl;
	welcomeScreen();
}

//user makes choice to view or add to the DB
void welcomeScreen(){
	char welcomeScrnSelection;
	cout <<"\nWhat would you like to do today?"<<endl;
	cout <<"1) Add new staff"<<endl;
	cout <<"2) View Existing"<<endl;
	cout <<"3) Exit"<<endl;

	cout << "Choice: ";
	cin >>welcomeScrnSelection;

	switch (welcomeScrnSelection){
		case '1': newAddition();
		break;
		case '2': viewExisting();
		break;
		case '3': exit(1);
		default: cout <<"Invalid Entry"<<endl;
		cin.ignore();
		welcomeScreen();
	}
}

/**/
//methods for choosing categories

//called by new addition and view existing methods
/*used to choose the appropriate category that the user wants to interact
	with when adding to or viewing the DB*/
char chooseCategory(){
	char choice;
	cout <<"Please Choose a category"<<endl;
	cout <<"1) Teacher"<<endl;
	cout <<"2) Officer"<<endl;
	cout <<"3) Typist"<<endl;
	cout <<"4) Back"<<endl;
	cout <<"5) Exit"<<endl;

	cout<<"Choice: ";
	cin >>choice;

	return choice;
}

//called by chooseTypist_Add and chooseTypist_View.
//used to choose the appropriate category of typist when adding or viewing
char chooseTypistCategory(){
	char choice;
	cout <<"Please Choose a category"<<endl;
	cout <<"1) Regular Typist"<<endl;
	cout <<"2) Casual Typist"<<endl;
	cout <<"3) Back"<<endl;
	cout <<"4) Exit"<<endl;

	cout << "Choice: ";
	cin >> choice;

	return choice;
}
/**/


/****/
//Methods for addition

//This one is called by the welcomeScreen.
//depending on the category the user chooses, it makes appropriate calls.
void newAddition(){
	char newAddSelection;

	cout <<"\nNew Addition."<<endl;

	newAddSelection = chooseCategory();

	switch (newAddSelection){
		case '1': addTeacher();
		break;
		case '2': addOfficer();
		break;
		case '3': typistType_Add();
		break;
		case '4': welcomeScreen();
		break;
		case '5': exit(1);
		default: cout <<"Invalid Entry"<<endl;
		newAddition();
	}
}

//called by the newAddition method and it adds teacher info to the DB
void addTeacher(){
	Teacher myTeacher;
	myTeacher.getData();
	myTeacher.writeToFile();
	cout << "\nThe following data has been saved "<< endl;
	myTeacher.showData();
	exitCondition();
}

//called by the newAddition method and it adds officer info to the DB
void addOfficer(){
	Officer myOfficer;
	myOfficer.getData();
	myOfficer.writeToFile();
	cout << "\nThe following data has been saved "<< endl;
	myOfficer.showData();
	exitCondition();	
}

//called by the newAddition method
/*it calls the choose typist category method for conditional adding
	since there are 2 typist types*/
//calls the respective typist add methods
void typistType_Add(){
	char choice;

	cout <<"\nNew Typist."<<endl;
	
	choice = chooseTypistCategory();
	
	switch (choice){
		case '1': addRegularTypist();
		break;
		case '2': addCasualTypist();
		break;
		case '3': newAddition();
		break;
		case '4': exit(1);
		default: cout <<"Invalid Entry"<<endl;
		typistType_Add();
	}
}

//called by typistType_Add method.
//adds a regular typist
void addRegularTypist(){
	cin.ignore();
	Typist myTypist;
	myTypist.getData();
	myTypist.writeToFile();
	cout << "\nThe following data has been saved "<< endl;
	myTypist.showData();
	exitCondition();
}

//called by typistType_Add method.
//adds a casual typist
void addCasualTypist(){
	CasualTypist myCTypist;
	myCTypist.getData();
	myCTypist.writeToFile();
	cout << "\nThe following data has been saved "<< endl;
	myCTypist.showData();
	exitCondition();
}

/****/


/******/
//Methods for viewing

//This one is called by the welcomeScreen.
//depending on the category the user chooses, it makes appropriate calls.
void viewExisting(){
	char newViewSelection;

	cout <<"\nView Existing."<<endl;

	newViewSelection = chooseCategory();

	switch (newViewSelection){
		case '1': viewTeacher();
		break;
		case '2': viewOfficer();
		break;
		case '3': typistType_View();
		break;
		case '4': welcomeScreen();
		break;
		case '5': exit(1);
		default: cout <<"Invalid Entry"<<endl;
		viewExisting();
	}
}

//this method reads the teacher.txt file and displays objects stored there
void viewTeacher(){
	int linesInFile = 0;
	int i;
	string line;
	ifstream myFile;

	myFile.open("teacher.txt");
	while (getline(myFile, line)){
		++linesInFile;
	}
	myFile.close();

	myFile.open("teacher.txt");
	Teacher myTeachers[linesInFile];
	if (myFile.is_open() ){
		for(i=0;i<linesInFile;i++){
			if(myFile.good()){
				cout << "\nTeacher "<<i+1<<endl;
				getline(myFile,myTeachers[i].staffCode, ',');
				getline(myFile,myTeachers[i].firstName, ',');
				getline(myFile,myTeachers[i].lastName, ',');
				getline(myFile,myTeachers[i].highestQualificationGenEd, ',');
				getline(myFile,myTeachers[i].highestQualificationProfessional, ',');
				getline(myFile,myTeachers[i].subject, ',');
				getline(myFile,myTeachers[i].publication,'\n');
				myTeachers[i].showData();
			}				
		}						
	}else{
		cout <<"Could not open file"<<endl;
	}
	myFile.close();
	exitCondition();
}

//this method reads the officer.txt file and displays objects stored there
void viewOfficer(){
	int linesInFile = 0;
	int i;
	string line;
	ifstream myFile;

	myFile.open("officer.txt");
	while (getline(myFile, line)){
		++linesInFile;
	}
	myFile.close();

	myFile.open("officer.txt");
	Officer myOfficers[linesInFile];
	if (myFile.is_open() ){
		for(i=0;i<linesInFile;i++){
			if(myFile.good()){
				cout << "\nOfficer "<<i+1<<endl;
				getline(myFile,myOfficers[i].staffCode, ',');
				getline(myFile,myOfficers[i].firstName, ',');
				getline(myFile,myOfficers[i].lastName, ',');
				getline(myFile,myOfficers[i].highestQualificationGenEd, ',');
				getline(myFile,myOfficers[i].highestQualificationProfessional, ',');
				getline(myFile,myOfficers[i].grade,'\n');
				myOfficers[i].showData();
			}				
		}						
	}else{
		cout <<"Could not open file"<<endl;
	}
	myFile.close();
	exitCondition();
}

//calls chooseTypistCategory to get user input about which typist to view
//makes appropriate calls to view the available typist categories
void typistType_View(){
	char choice;

	cout << "\nView Typist." << endl;

	choice = chooseTypistCategory();

	switch (choice){
		case '1': viewRegularTypist();
		break;
		case '2': viewCasualTypist();
		break;
		case '3': viewExisting();
		break;
		case '4': exit(1);
		default: cout <<"Invalid Entry"<<endl;
		typistType_View();
	}
}

////this method reads the typist.txt file and displays objects stored there
void viewRegularTypist(){
	int linesInFile = 0;
	int i;
	string line;
	ifstream myFile;

	myFile.open("typist.txt");
	while (getline(myFile, line)){
		++linesInFile;
	}
	myFile.close();

	myFile.open("typist.txt");
	Typist myTypists[linesInFile];
	if (myFile.is_open() ){
		for(i=0;i<linesInFile;i++){
			if(myFile.good()){
				cout << "\nRegular Typist "<<i+1<<endl;
				getline(myFile,myTypists[i].staffCode, ',');
				getline(myFile,myTypists[i].firstName, ',');
				getline(myFile,myTypists[i].lastName, ',');
				getline(myFile,myTypists[i].speedWPM,'\n');
				myTypists[i].showData();
			}				
		}						
	}else{
		cout <<"Could not open file"<<endl;
	}
	myFile.close();
	exitCondition();
}

////this method reads the casualTypist.txt file and displays objects stored there
void viewCasualTypist(){
	int linesInFile = 0;
	int i;
	string line;
	ifstream myFile;

	myFile.open("casualTypist.txt");
	while (getline(myFile, line)){
		++linesInFile;
	}
	myFile.close();

	myFile.open("casualTypist.txt");
	CasualTypist myTypists[linesInFile];
	if (myFile.is_open() ){
		for(i=0;i<linesInFile;i++){
			if(myFile.good()){
				cout << "\nCasual Typist "<<i+1<<endl;
				getline(myFile,myTypists[i].staffCode, ',');
				getline(myFile,myTypists[i].firstName, ',');
				getline(myFile,myTypists[i].lastName, ',');
				getline(myFile,myTypists[i].speedWPM,',');
				getline(myFile,myTypists[i].dailyWages,'\n');
				myTypists[i].showData();
			}				
		}						
	}else{
		cout <<"Could not open file"<<endl;
	}
	myFile.close();
	exitCondition();
}
/******/

/********/
//this method asks the user if they are done. exits if yes and starts over if no.
void exitCondition(){
	char choice;
	cout << "\nWould you like to exit?" << endl;
	cout << "1) No -- Go back to beginning" <<endl;
	cout << "2) Yes" << endl;

	cout<<"Choice: ";
	cin >> choice;

	switch(choice){
		case '1': welcomeScreen();
		case '2': exit(1);
		default: cout <<"Invalid Entry"<<endl;
		exitCondition();
	}
}
/********/