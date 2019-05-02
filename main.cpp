#include "GenStack.h"
#include "TreeNode.h"
#include "GenDoublylinkedlist.h"
#include "GenTreeNode.h"
#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include "Database.h"
#include <iostream>
#include <string>
using namespace std;

/*
USER WILL FIRST NEED TO LOG IN (USERNAME/PASSWORD GIVEN).
ONCE LOGGED IN.
STAFF WILL SEE MENU PROVIDING THEM 14 CHOICE, 14 BEING THE EXIT KEY
*/

int main(){

  //citation for login cplusplus.com
  string userName;
  string userPassword;
  int loginAttempt = 0;

    while (loginAttempt < 5)
    {
        cout << "Please enter your user name(USERNAME IS 'bill or rene'): ";
        cin >> userName;
        cout << "Please enter your user password(PASSWORD IS 'compsci'): ";
        cin >> userPassword;

        if (userName == "bill" && userPassword == "compsci")
        {
            cout << "Welcome Dr.Bill!\n";
            break;
        }
        else if (userName == "rene" && userPassword == "compsci")
        {
            cout << "Welcome Dr.Rene!\n";
            break;
        }
        else
        {
            cout << "Invalid login attempt. Please try again.\n" << '\n';
            loginAttempt++;
        }
    }
    if (loginAttempt == 5)
    {
            cout << "Too many login attempts! The program will now terminate.";
            return 0;
    }

    cout << "Thank you for logging in.\n";
   //Run Program
    Database record_system;
    record_system.startProgram();
}

  //sobject.setStudentID(123456);
  //Faculty fobject;
  //fobject.setFacultyID(678905);

  //cout << "Student ID : "<< sobject.getStudentID();
  //cout << "Faculty ID : "<< fobject.getFacultyID();
  return 0;
}
