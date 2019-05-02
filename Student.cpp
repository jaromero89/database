#include "Student.h"
#include "Faculty.h"

Student::Student(){
  int studentID = 0;
  double GPA = 0;
  int facultyID = 0;
}
Student::~Student(){

}
//GETTTER AND SETTER FUNCTIONS , simply just assigning values
void Student::setStudentName(string n){
  studentName = n;
}
string Student::getStudentName(){
  return studentName;
}
void Student::setStudentID(int s){
  studentID = s;
}
int Student::getStudentID(){
  return studentID;
}
void Student::setGradelevel(string g_L){
  gradeLevel = g_L;
}
string Student::getGradelevel(){
  return gradeLevel;
}
void Student::setMajor(string m){
  major = m;
}
string Student::getMajor(){
  return major;
}
void Student::setGPA(double g){
  GPA = g;
}
double Student::getGPA(){
  return GPA;
}
void Student::setAdvisorID(int advisorsID, int f_ID){
  advisorsID = f_ID;
}
int Student::getAdvisorID(){
  return advisorsID;
}
