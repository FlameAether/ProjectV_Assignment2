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

#define STUDENT_NAME_FILE "C:\\Users\\Ryan\\Desktop\\Conestoga\\Year 3\\Project V\\Assignment 2\\StudentData.txt"

using namespace std; 

struct STUDENT_DATA 
{
	string firstName; 
	string lastName; 
};

int main()
{
	ifstream inputFile(STUDENT_NAME_FILE); 
	if (!inputFile)
	{
		cout << "Error reading file, unable to open!" << endl; 
		return -1; 
	}

	vector<STUDENT_DATA> students; 
	string line; 

	while (getline(inputFile, line))
	{
		istringstream iss(line); 
		string firstName, lastName; 
		string space; // get rid of the space in the name 

		if (getline(iss, lastName, ',') && getline (iss, space, ' ') && getline(iss, firstName))
		{
			STUDENT_DATA student; 
			student.firstName = firstName; 
			student.lastName = lastName; 
			students.push_back(student); 
		}
	}

	inputFile.close(); 

	cout << "[Last Name, First Name]\n" << endl; 

	for (STUDENT_DATA& student : students)
	{
		std::cout << student.lastName << ", " << student.firstName << std::endl;
	}

	return 1; 

}