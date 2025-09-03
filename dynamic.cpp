#include<iostream> // cin , cout , ...
#include<vector> // vectors
#include<iomanip> // input/output format , boolalpha , ...
#include<cmath> // ceil , floor , ...
#include <algorithm> // beging , end , reverse , ...
#include <climits> // INT_MIN , INT_MAX , ...
#include <cctype> // for digit functions
#include <stack> // PUSH , POP , ...
#include <string> // empty() , ...
using namespace std; // Using the standard namespace

// Write a program to dynamically allocate memory for a character, string and array of integer. Input all of them from the user.

void printChar(string &str){
    // validation
    if(str.empty()){
        cout<<"You didn't enter any character!";
    }else if(isdigit(str[0])){
        cout<<"Enter only one character and not an integer.";
    }else if(str.length() > 1){
        cout << "An invalid input.";
    }else{
    // Display the dynamically allocated character
    cout<<"The character is "<<str[0]; // K
    }cout<<endl;
}
void printString(string &st){
    bool hasDigit = false;
    cout<<"The string is ";
    // Validation
    if(st.empty()){
        cout<<"empty"<<endl;
    }for(char c : st){
        if(isdigit(c)){
            hasDigit = true;
            break;
        }
    }if (hasDigit ==true){
        cout<<"invalid. Enter a string not a digit"<<endl;
    }else{
        cout<<st;
    }cout<<endl;
}
void printIntegers(int array[],int size){
    if (size == 0)
    {
        cout<<"There's no size to enter the elements";
    }else{
        cout<<"The array is ";
        for(int i = 0;i<size;i++){
            // Validation
            if(array[i]<INT_MIN || array[i]>INT_MAX){
            cout<<"invalid!"<<endl;
            }else{
            // Display the elements of the dynamically allocated integer array
            cout<<array[i]<<" "; // 1 2 3 4 5
            }
        }
    }cout<<endl;
}
int main(){
    // Pointer to character in heap
    string *ch;
    ch = new string;
    cout<<"Enter the character : ";
    getline(cin,*ch); // K

    // Pointer to string in heap

    string *s;
    s = new string;
    cout<<"Enter the string : ";
    getline(cin,*s); // Khaled

    // Pointer to array of integers in heap

    //Taking the size of the array from the user
    int size;
    int *arrayOfInt = nullptr;
    cout<<"Enter the size of the array : ";

    // Validation
    if(!(cin>>size) || size == 0){
        cout<<"An invalid size!"<<endl;
    }else{
        arrayOfInt = new int[size];
        cout<<"Enter the array of integers : ";
        for(int i =0;i<size;i++){ // Taking the elements of the array from the user
            cin>>arrayOfInt[i]; // 1 2 3 4 5
        }
    }

    // Display the dynamically allocated character
    printChar(*ch); // The character is k

    // Display the dynamically allocated string
    printString(*s); // The string is Khaled
    
    // Deallocate the character and the string
    delete ch;
    delete s;
    // Display the elements of the dynamically allocated integer array and dealocate it
    if(arrayOfInt != nullptr){
        printIntegers(arrayOfInt, size); // The array is 1 2 3 4 5
        delete[] arrayOfInt;
    }
}