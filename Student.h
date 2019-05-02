#include <iostream>
#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;
/*
Student class is used to gather the required data
for which this program requires. Such as:
Students name, Student ID(MOST IMPORTANT ASPECT)
Grade level(Fresman, Sophmore, Junior, and Senior)
GPA(Students Grade Point Average, Format (X.XX)
Student's Advisor
*/
class Student{
friend class Faculty;
public:
  Student();
  ~Student();

  void setStudentName(string n);
  string getStudentName();
  void setStudentID(int s);
  int getStudentID();
  void setGradelevel(string g_L);
  string getGradelevel();
  void setMajor(string m);
  string getMajor();
  void setGPA(double g);
  double getGPA();
  void setAdvisorID(int advisorsID, int f_ID);
  int  getAdvisorID();



private:

  string studentName;
  int studentID;
  int advisorsID;
  string gradeLevel;
  string major;
  double GPA;



};
#endif
