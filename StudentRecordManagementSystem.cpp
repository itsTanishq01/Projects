#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>


class StudentData
{   
    public:
    std::string name;
    std::string branch;
    int roll_number;
    int marks1;
    int marks2;
    int marks3;
};
StudentData s;

void userinput()
{
    std::cout << "enter your name" << std::endl;
    std::cin >> s.name;

    std::cout << "enter your Branch" << std::endl;
    std::cin >> s.branch;

    std::cout << "enter your Roll Number" << std::endl;
    std::cin >> s.roll_number;

    std::cout << "Enter marks obtained in Maths" << std::endl;
    std::cin >> s.marks1;

    std::cout << "Enter marks obtained in CS" << std::endl;
    std::cin >> s.marks2;
    
    std::cout << "Enter marks obtained in Chemistry" << std::endl;
    std::cin >> s.marks3;

}

void fileinput()
{
    userinput();

    std::fstream record("StudentRecord.txt",std::ios::out | std::ios::app);
    
        if(record.is_open())
        {   
        record << std::left << std::setw(20) << "NAME";
        record << std::left << std::setw(20) << "BRANCH";
        record << std::left << std::setw(20) << "ROLL NUMBER";
        record << std::left << std::setw(20) << "MATHS MARKS";
        record << std::left << std::setw(20) << "CS MARKS";
        record << std::left << std::setw(20) << "CHEM MARKS" << "\n";
        
        record << std::left << std::setw(20) << s.name;
        record << std::left << std::setw(20) << s.branch;
        record << std::left << std::setw(20) << s.roll_number;
        record << std::left << std::setw(20) << s.marks1;
        record << std::left << std::setw(20) << s.marks2;
        record << std::left << std::setw(20) << s.marks3 << "\n";

        record.close();
        }
        else
        {
            std::cout << "Error in opening file!" << std::endl;
        }
}
void clear()
{
system ("PAUSE");
system ("CLS");
}

int main()
{   
    std::cout <<  "WELCOME TO STUDENT RECORD MANAGEMENT" << std::endl;
    std::cout <<   "START ENTERING STUDENT RECORDS DOWN BELOW" << std::endl; 
    fileinput();
    clear();
    return 0;
}