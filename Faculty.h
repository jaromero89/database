#include <iostream>
#ifndef FACULTY_H // include guard
#define FACULTY_H
#include <string>
using namespace std;
/*
Facultyclass is used to gather the required data
for which this program requires. Such as:
Faculty name, Faculty ID(MOST IMPORTANT ASPECT)
Department(Computer Science, Biology, Physics , and Math)
Faculty 's Advisees
*/

class Faculty{
public:
  friend class Student;
  Faculty();
  ~Faculty();

  void setFacultyName(string n);
  string getFacultyName();
  void setFacultyID(int f);
  int getFacultyID();
  void setDept(string d);
  string getDept();
  void setAdviseesID(int adviseesID, int s_ID);
  int  getAdviseesID();



private:

  string FacultyName;
  int FacultyID;
  int adviseesID;
  string facultyLevel;
  string Dept;



};
#endif
