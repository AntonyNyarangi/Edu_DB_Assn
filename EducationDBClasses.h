#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Staff class
class Staff{
public:
  string staffCode;
  string firstName;
  string lastName;

  void getData(){
    cout << "\nPlease enter the following information" << endl;
    cout << "Staff Code: ";
    getline(cin,staffCode);
    cout << "First Name: ";
    getline(cin,firstName);
    cout << "Last Name: ";
    getline(cin,lastName);    
  }
  
  void showData(){
    cout << "Staff Code: " << staffCode << endl;
    cout << "Name: " << firstName + " " + lastName << endl;
  }

  void writeToFile(){
    ofstream myFile;
    myFile.open("staff.txt",ofstream::out | ofstream::app);
    myFile << staffCode << ",";
    myFile << firstName << ",";
    myFile << lastName << endl;    
    myFile.close();  
  }
};

//Education class
class Education{
public:
  string highestQualificationGenEd;
  string highestQualificationProfessional;

  void getData(){
    cout << "Highest general education qualification: ";
    getline(cin,highestQualificationGenEd);
    cout << "Highest Professional qualification: ";
    getline(cin,highestQualificationProfessional);
  }

  void showData(){
    cout << "Highest GenEd qualification: " << highestQualificationGenEd << endl;
    cout << "Highest professional qualification: " << highestQualificationProfessional << endl;    
  }

  void writeToFile(){
    ofstream myFile;
    myFile.open("education.txt",ofstream::out | ofstream::app);
    myFile << highestQualificationGenEd << ",";
    myFile << highestQualificationProfessional << endl;
  }
};


//Teacher class. Derived from Staff class
class Teacher:public Staff,public Education{
public:
  string subject;
  string publication;

  void getData(){
    cin.ignore();
    Staff::getData();
    Education::getData();
    cout << "Subject: ";
    getline(cin,subject);
    cout << "Publication: ";
    getline(cin, publication);    
  }

  void showData(){
    Staff::showData();
    Education::showData();
    cout << "Subject: " << subject << endl;
    cout << "Publication: " << publication << endl;
  }

  void writeToFile(){
    Staff::writeToFile();
    Education::writeToFile();
    ofstream myFile;
    myFile.open("teacher.txt",ofstream::out | ofstream::app);
    myFile << staffCode << ",";
    myFile << firstName << ",";
    myFile << lastName << ",";
    myFile << highestQualificationGenEd << ",";
    myFile << highestQualificationProfessional << ",";
    myFile << subject << ",";
    myFile << publication << endl;
    myFile.close();
  }
};

//Officer class. Derived from Staff class
class Officer:public Staff, public Education{
public:
  string grade;

  void getData(){
    cin.ignore();
    Staff::getData();
    Education::getData();
    cout << "Grade: ";
    getline(cin,grade);
  }

  void showData(){
    Staff::showData();
    Education::showData();
    cout << "Grade: " << grade << endl;
  }

  void writeToFile(){
    Staff::writeToFile();
    Education::writeToFile();
    ofstream myFile;
    myFile.open("officer.txt",ofstream::out | ofstream::app);
    myFile << staffCode << ",";
    myFile << firstName << ",";
    myFile << lastName << ",";
    myFile << highestQualificationGenEd << ",";
    myFile << highestQualificationProfessional << ",";
    myFile << grade << endl;
    myFile.close();
  }
};

//Typist class. Derived from Staff class
class Typist:public Staff{ //Regular Typist
public:
  string speedWPM;

  void getData(){
    Staff::getData();
    cout <<"Speed (WPM): ";
    getline(cin,speedWPM);
  }

  void showData(){
    Staff::showData();
    cout << "Speed (WPM): " << speedWPM << endl;
  }

  void writeToFile(){
    Staff::writeToFile();
    ofstream myFile;
    myFile.open("typist.txt",ofstream::out | ofstream::app);
    myFile << staffCode << ",";
    myFile << firstName << ",";
    myFile << lastName << ",";
    myFile << speedWPM << endl;
    myFile.close();
  }
};

//Casual typist class. Derived from typist class
class CasualTypist:public Typist{
public:
  string dailyWages;

  void getData(){
    cin.ignore();
    Typist::getData();
    cout << "Daily Wage: ";
    getline(cin,dailyWages);
  }

  void showData(){
    Typist::showData();
    cout << "Daily Wages: " << dailyWages << endl;
  }

  void writeToFile(){
    Typist::writeToFile();
    ofstream myFile;
    myFile.open("casualTypist.txt",ofstream::out | ofstream::app);
    myFile << staffCode << ",";
    myFile << firstName << ",";
    myFile << lastName << ",";
    myFile << speedWPM <<",";
    myFile << dailyWages << endl;
    myFile.close();
  }
};