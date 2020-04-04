#include "SyntaxChecker.h"
#include "GenStack.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

//constructor
SyntaxChecker::SyntaxChecker(){
}
//destructor
SyntaxChecker::~SyntaxChecker(){
}


void SyntaxChecker::get_filename(){
    while (mFilename == ""){
        //prompt user to enter the name of the desired file
        cout << "Enter The File Name" << endl;
        string filename = "";
        cin >> filename;
        ifstream ifile;
        ifile.open(filename);
        if(ifile){
            mFilename = filename;
        }
    }
}

//set variables to be equal to 0 to be counted later
int par_c = 0;
int par_o = 0;
int bra_c = 0;
int bra_o = 0;
int brace_c = 0;
int brace_o = 0;

void SyntaxChecker::check_errors(){
    ifstream file(mFilename);
    int elem = 0;

    //open the file
    if(file.is_open()){
        string line;
        int leng_line = 0;
        typedef GenStack<char> CharStack;
        CharStack stack;
        while(getline(file, line)){
            //see how long the file is to know how many lines to go through
            leng_line = textLine.length();
                for(int i = 0; i<leng_line; ++i){
                    elem = textLine[i];
                    //counts how many time each of these elems appear in the file
                    if(elem == '(' || elem == '{' || elem == '[' || elem == ']' || elem == '}' || elem == ')'){
                        stack.push(elem);
                        if(elem == '('){
                            par_o++;
                        }
                        else if(elem == ')'){
                            par_c++;
                        }
                        else if(elem == '['){
                            bra_o++;
                        }
                        else if(elem == ']'){
                            bra_c++;
                        }
                        else if(elem == '{'){
                            brace_o++;
                        }
                        else if(elem == '}'){
                            brace_c++;
                        }
                    }
                }
        }
        //checks if number of similar elems are equal
        if(par_o > par_c || par_o < par_c){
            cout << "Number of parenthesis are off" << endl;
        }
        else if(bra_o > bra_c || bra_o < bra_c){
            cout << "Number of brackets are off" << endl;
        }
        else if(brace_o > brace_c || brace_o < brace_c){
            cout << "Number of braces are off" << endl;
        }
        else{
            cout << "No Syntax Errors" << endl;
        }

    }
    file.close();
}