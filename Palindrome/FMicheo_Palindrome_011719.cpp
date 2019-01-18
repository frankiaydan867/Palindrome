/* 
 * File:   FMicheo_Palindrome_011719.cpp
 * Author: Franki Micheo
 * Course: COP2570C - Programming Data Structures 
 * Created on January 17, 2019, 7:08 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stack>


using namespace std;

//Functions
void ProgramHeader();
void isPalindrome(string w, bool &t);

/*
 * main Method
 */
int main() {
   
    //Variables
    string input;
    bool Is;
    string s;
    do{
    
    //Draw header
    ProgramHeader();
    
    //Start Program
    cout << "\nPlease enter a word or a "
            "phrase to test if it is a PALINDROME!\n";
    
    cout << "->";
    getchar();
    getline(cin, input); //Input to get words or phrases including spaces
    
    isPalindrome(input, Is); //Test if it is a palindrome

        if(Is){
            cout << "\n" << input << " is a Palindrome!\n";
            cout << "Try again? (Y/N):";
            cin >> s;
        }
        else{
            cout << "\n" << input << " is not a Palindrome...\n";
            cout << "Try again? (Y/N):";
            cin >> s;
        }
    }while(s == "Y" || s == "y"); //Repeat while it is Y, else end program.
    
    
    return 0;
}

//Draw header
void ProgramHeader(){
    system("clear");
    
    for(int i = 0;i < 33;i++){
        cout << "*";
    }
    cout << "\n*\tPalindrome Tester\t*\n";
    for(int i = 0;i < 33;i++){
        cout << "*";
    }
    cout << endl;
}

void isPalindrome(string w, bool &t){
    
    //Variables
    char firstletter = w[0];
    char lastletter = w[w.size()-1];
    int size = w.size();
               
    //Check if there is one character or none left
    if(size <= 1){
        t = true; //True if it went thru all of them
    }
    else if(size > 1 && firstletter != lastletter){
        cout << firstletter << " - " << lastletter << endl;
        t = false; //false if any of them dont match
    }
    else if (firstletter == lastletter){
        cout << firstletter << " - " << lastletter << endl;
        isPalindrome(w.substr(1,size-2), t); //Recursion to continue to test 
    }
}

