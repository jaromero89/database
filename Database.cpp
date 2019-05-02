#include "Database.h"

Database::Database()
{
	stree = new BST<Student>();
	ftree = new BST<Faculty>();
}

Database::~Database(){}

Database::Database(BST<Student> &theStudDB, BST<Faculty> &theFacDB)
{
	student_tree = &theStudDB;
	faculty_tree = &theFacDB;
}
//startProgram is used as an all in one function to reduce code in the main function
void Database::startProgram()
{
	int input = -1;
//General Variables : Student ID , Faculty ID..all the required data
	int sID, fID;
	string name, level, major, department;
	int advisorID;
	double gpa;

///User will select from the 14 options , number 14 ia used as an exit method..Followed steps and procedures in Assigment 5 Document
    while(input != 14) {
         promptUser();
         cout << "Select one of the options within the menu(1-14): ";
         cin >> input;

         switch(input) {
              case 1:
                  printStudents();
                  break;
              case 2:
                  printFaculty();
                  break;
              case 3:
                  cout << "Please enter the ID number of the student you want the information of" << endl;
                  cin >> sID;
                  if (studentcheckID(sID) == false) {
                    cout << "This student is not present in the database!" << endl;
                  }
                  else {
                    cin.get();
                    cout << findStudent(id);
                  }
                  break;
              case 4:
                  cout << "Please enter the ID number of the faculty you want the information of" << endl;
                  cin >> fID;
                  if (facultycheckID(fID) == false) {
                  cout << "This faculty is not present in the database!" << endl;
                  }
                  else {
                   cin.get();
                   cout << findFaculty(id);
                  }
                  break;
              case 5:
                  cout << "Enter student ID number: " << endl
                  cin >> sID;
                  if (studentcheckID(sID) == false) {
                  cout << "This student is not present in the database!" << endl;}
                  else{
                  cin.get();
                  findAdvisor(sID);
                  break;
              case 6:
                  cout << "Enter faculty ID : " << endl;
                  if (facultycheckID(fID) == false) {
                  cout << "This faculty is not present in the database!" << endl;
                  }
                  else {
                  cin.get();
  				        findAdvisees(id);
                  break;
              case 7:
              cout << "Enter name of student: " << endl;
                  getline(cin,name);
                  cout << "Enter level of student: " << endl;
                  getline(cin,level);
                  cout << "Enter student's major" << endl;
                  getline(cin,major);
                  cout << "Enter student GPA(Format X.XX)" << endl;
                  cin >> gpa;
                  cin.get();
                  cout << "Enter advisor ID" << endl;
                  cin >> advisorID;
                  addStudent(name, level, major, gpa, advisorID);
                  break;
              case 8:
                  sdeletcout << "Enter student ID that you wish to deleted" << endl;
				          cin >> sID;
				          cin.get();
				          deleteStudent(sID);
                  break;
              case 9:
                  cout << "Enter faculty name" << endl;
                  getline(cin,name);
                  cout << "Enter faculty's level" << endl;
                  getline(cin,level);
                  cout << "Enter faculty's department" << endl;
                  getline(cin,department);
                  addFaculty(name,level,department);
                  break;
              case 10:
                  cout << "Enter Faculty ID to be deleted" << endl;
              	  cin >> id;
              		cin.get();
              		deleteFaculty(id);
              		break;
              case 11:
                  cout << "Enter Student ID whose advisor you want to change." << endl;
                  cin >> sID;
                  while (studentcheckID(sID) == false) {
                    cout << "The ID you entered is not in the database, please try again." << endl;
                    cin >> sID;
                  }
                  cout << "Please enter the new faculty ID that you would like to assign to the student." << endl;
                  cin >> fID;
                  while (facultycheckID(fID) == false) {
                    cout << " The faculty ID you entered is not in the database. Please try again" << endl;
                    cin >> fID;
                  }
                  changeAdvisor(sID, fID);
                  break;
              case 12:
                  cout << "Enter the ID of the faculty whose advisee you wish to remove." << endl;
                  cin >> fID;
                  while (facultycheckID(fID) == false) {
                    cout << "The ID you entered is not in the database. Please try again." << endl;
                    cin >> fID;
                  }
                  cout << "Please enter the ID of the advisee you want to remove." << endl;
                  cin >> sID;
                  removeAdvisee(fID, sID);
                  break;
              case 13:
                  rollback();
                  break;
              case 14:
                  break;
         }
    }
    //14.  exit message
    cout << endl << "Thank you for using the program. Bye." << endl << endl;
//DISPLAY MENU ONCE LOGGED IN
void Database::menu()
{
	cout << "--------------------------Assigment5_DATABASE--------------------------------------" << endl <<

	"1. Print all students and their information" << endl <<
	"2. Print all faculty and their information (sorted by ascending id #)" << endl <<
	"3. Find and display student information given the students id" << endl <<
	"4. Find and display faculty information given the faculty id" << endl <<
	"5. Given a student’s id, print the name and info of their faculty advisor" << endl <<
	"6. Given a faculty id, print ALL the names and info of his/her advisees." << endl <<
	"7. Add a new student" << endl <<
	"8. Delete a student given the id" << endl <<
	"9. Add a new faculty member" << endl <<
	"10. Delete a faculty member given the id." << endl <<
	"11. Change a student’s advisor given the student id and the new faculty id." << endl <<
	"12. Remove an advisee from a faculty member given the ids" << endl <<
	"13. Rollback" << endl <<
	"14. Exit" << endl << "-----------------------------------------------------------------------------" << endl;
}
//TREE IS USED TO STORE DATA FROM USER ENTRIES
void Database::printStudents()
{
	stree->printTree();
}

void Database::printFaculty()
{
	ftree->printTree();
}

Faculty Database::findFaculty(int ID)
{
	Faculty temp(ID, "", "");
	if(fac->contains(temp))
	{
		return *fac->search(temp);
	}
	else
	{
		Faculty fail;
		return fail;
	}
}

Student Database::findStudent(int ID)
{
	Student temp(ID, "", "");
	if(stud->contains(temp))
	{
		return *stud->search(temp);
	}
	else
	{
		Student fail;
		return fail;
	}
}

void Database::findAdvisor(int ID)
{
	Student temp = findStudent(ID);
	if(temp.getAdvisor() != -1)
	{
		int advisorID = temp.getAdvisor();
		cout << findFaculty(advisorID);
	}
	else
		cout << "Student does not have an advisor" << endl;
}

/*
iterate through the list of advisees
search the BST based on the IDs
print out value
*/
void Database::findAdvisees(int ID)
{
	Faculty tempFac = findFaculty(ID);
	DoublyLinkedList<int> deletedID;

	if(tempFac.adviseeList->isEmpty())
		cout << "No advisees to be displayed" << endl;
	while(!tempFac.adviseeList->isEmpty())
	{
		int tempID = tempFac.adviseeList->removeFront();
		cout << findFaculty(tempID);
		deletedID.insertBack(tempID);
	}
	while(!deletedID.isEmpty())
	{
		int tempID = deletedID.removeFront();
		tempFac.adviseeList->insertBack(tempID);
	}
}

void Database::addStudent(string studentName, string gradeLevel, string Major, double GPA, int advisorID)
{
	Faculty tempFac(advisorID,"","");
	if(fac->contains(tempFac))
	{
		Student s(studentName, gradeLevel, Major, GPA, advisorID);
		stud->insert(s);
		cout << studentName << " was successfully added" << endl;
	}
	else
		cout << "An advisor with given ID doesn't exist. Student not added." << endl;
}

void Database::deleteStudent(int sID)
{
	Student temp(sID, "", "");
	if(stud->contains(temp))
	{
		stud->deleteR(findStudent(sID));
		cout << "Student successfully deleted" << endl;
	}
	else
		cout << "A student with given ID doesn't exist. Student not deleted." << endl;
}

void Database::addFaculty(string studentName, string gradeLevel, string Major, double GPA, int advisorID)
{
	Faculty f(string studentName, string gradeLevel, string Major, double GPA, int advisorID);
	fac->insert(f);
	cout << theName << " was successfully added" << endl;
}

//adjust students advisor
//adjust facultys advisees
void Database::deleteFaculty(int ID)
{
	Faculty temp(ID, "", "");
	if(fac->contains(temp))
	{

		fac->deleteR(findFaculty(ID));



		cout << "Faculty successfully deleted" << endl;
	}
	else
		cout << "A faculty with given ID doesn't exist. Faculty not deleted." << endl;
}

void Database::changeAdvisor(int studentID, int facultyID)
{
	Student s(studentID,"", "");
	Student* temp = stud->search(s);
	Faculty f = findFaculty(facultyID);

	if(fac->contains(f))
	{
		temp->setAdvisor(facultyID);
		cout << "Advisor successfully changed" << endl;
	}
	else
		cout << "Faculty with given ID doesn't exist. Advisor not changed." << endl;
	temp = NULL;
}

void Database::removeAdvisee(int facultyID, int adviseeID)
{
	Faculty f = findFaculty(facultyID);
	if(f.adviseeList->find(adviseeID) != -1) //if the value was found in the list of advisees
		f.adviseeList->remove(adviseeID);
	else
		cout << "Given Advisee ID doesn't exist in list. Advisee not deleted" << endl;
}
//BOOLEAN FUNCTIONS ARE USED TO CHECK THE VALIDITY OF BOTH ID OF STUDENT AND FACULTY
bool Database::studentcheckID (unsigned int cID)
{
  Student stuCheck;
  stuCheck.setID(cID);
  if(stree -> contains(stuCheck))
       return true;
  return false;
}
bool Database::facultycheckID (unsigned int cID)
{
  Faculty facCheck;
  facCheck.setID(cID);
  if(ftree -> contains(facCheck))
       return true;
  return false;
}
