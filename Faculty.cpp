
#include "Faculty.h"
#include "Student.h"

Faculty::Faculty(){
  int FacultyID = 0;
}
Faculty::~Faculty(){
}
//GETTTER AND SETTER FUNCTIONS , simply just assigning values
void Faculty::setFacultyName(string n){
  FacultyName = n;
}
string Faculty::getFacultyName(){
  return FacultyName;
}
void Faculty::setFacultyID(int f){
  FacultyID = f;
}
int Faculty::getFacultyID(){
  return FacultyID;
}
void Faculty::setDept(string d){
  Dept = d;
}
string Faculty::getDept(){
  return Dept;
}
void Faculty::setAdviseesID(int adviseesID, int s_ID){
  adviseesID = s_ID;
}
int Faculty::getAdviseesID(){
  return adviseesID;
}
