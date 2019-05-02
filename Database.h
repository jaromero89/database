#include <iostream>
#include "BST.h"
#include "Student.h"
#include "Faculty.h"
/*
Brains of the database, Hence Database class. This class
pulls from each and every class in order to
store Faculty and students information.
A BST tree is used to store and keep record of all the pertinant
data. 
*/

#ifndef DATABASE_H
#define DATABASE_H

using namespace std;

class Database{
public:
  Database();//contructor
  ~Database();//destructor
//User dispaly
  void menu();//User Prompt
  void startProgram();//Base function : used to run the program
  //----------------------------------------------------------------
/////////Menu Choices(1-14)/////////
  void printStudent();
  void printFaculty();

  void displayStudent(int studentID);
  void displayFaculty(int facultyID);

  void printAdvisor(int studentID);
  void printAdvisee(int facultyID);

  Student findStudent(int sID)
  Faculty findFaculty(int fID);

  void addStudent(string studentName, string gradeLevel, string Major, double GPA, int advisorID);
  void deleteStudent(int sID);

  void addFaculty(string FacultyName, int FacultyID, int adviseesID, string facultyLevel, string Dept);
  void deleteFaculty(int facultyID);

  void findAdvisor(int sID);
  void findAdvisees(int fID);

  void changeAdvisor(int studentID, int facultyID);
  void removeAdvisee(int facultyID);

  void rollback();
//-----------------------------------------------------------------
///Validates the ID numbers of both faculty and student
  bool studentcheckID (unsigned int cID);
  bool facultycheckID (unsigned int cID);

};
#endif
