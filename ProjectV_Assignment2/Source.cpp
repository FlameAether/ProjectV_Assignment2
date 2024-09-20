/*
Ryan Tu 
Fall 2024 
Project V - Assignment 2 
Main Source File 
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

// local path to the student data file 
#define STUDENT_NAME_FILE "C:\\Users\\Ryan\\Desktop\\Conestoga\\Year 3\\Project V\\Assignment 2\\StudentData.txt"

using namespace std;

struct STUDENT_DATA
{
    string firstName;
    string lastName;
};

// function to process the students and add them from the txt file to a vector 
vector<STUDENT_DATA> processStudents() 
{
    vector<STUDENT_DATA> students; // vector to store students 

    // open file, print error message if unable to 
    ifstream inputFile(STUDENT_NAME_FILE);
    if (!inputFile)
    {
        cout << "Error reading file, unable to open!" << endl;
        return students; // return empty vector
    }

    string line; // used to store one line of data from file 

    while (getline(inputFile, line))
    {
        istringstream iss(line);
        string firstName, lastName;
        string space; // get rid of the space in the name 

        // assign first and last names and push it back to the vector 
        if (getline(iss, lastName, ',') && getline(iss, space, ' ') && getline(iss, firstName))
        {
            STUDENT_DATA student;
            student.firstName = firstName;
            student.lastName = lastName;
            students.push_back(student);
        }
    }

    inputFile.close();
    return students; // return the vector of students
}

int main() {
    vector<STUDENT_DATA> students = processStudents(); // call the function to process students

// print out the names only if in debug mode 
#ifdef _DEBUG
    cout << "[Last Name, First Name]\n" << endl;

    for (const STUDENT_DATA& student : students)
    {
        std::cout << student.lastName << ", " << student.firstName << std::endl;
    }
#endif

    return 1;
}
