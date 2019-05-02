#include <iostream>

using namespace std;
void printArray(int myArray[], int Arraysize);
int main(){
int James[3] = {3, 2, 1};
int Laura[5] = {14, 11, 7, 6};

printArray(Laura, 3);

return 0;
}

void printArray(int myArray[], int Arraysize){
for(int x= 0; x< Arraysize; x++)
{
cout << myArray[x] << endl;
}
}
