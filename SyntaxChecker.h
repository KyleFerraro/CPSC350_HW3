#include <fstream>
#include <iostream>

using namespace std;

class SyntaxChecker{
public:
    //constructor
    SyntaxChecker();
    //destructor
    ~SyntaxChecker();

    //set variables and functions up;
    string filename;
    string textLine;
    void check_errors();
    void get_filename();

private:
    string mFilename;
};

int main(int argc, char** argv) {

    //creating a delimiter
    SyntaxChecker* prog = new SyntaxChecker();

    prog->get_filename();
    
    //goes through the file, checking for syntax errors
    prog->check_errors();
    return 0;
}