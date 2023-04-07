// Name: ³¯«Û¾§ B11115004
// Date: March 9, 2023
// Last Update: March 9, 2023
// Problem statement: Print_Standard_Format

#include <iostream>
#include <vector> 
#include <iomanip> 
using namespace std;

// defined a struct "Employee" to store every input person easier.
struct Employee
{
	string name;
	string salary;
	string award;
};

int main()
{
	for (int n; cin >> n;)
	{
		vector<Employee> input;
		int maxNameSize(0), maxSalarySize(0), maxAwardSize(0); // delcare three variables to record the max length for each column 

		for (int i(0); i < n; i++)
		{
			Employee person;
			cin >> person.name >> person.salary >> person.award;
			// if the new person that had recorded's data's length
			// is longer than all the previous ones, just change the origin max length
			maxNameSize = max(maxNameSize, (int)(person.name.size())); 
			maxSalarySize = max(maxSalarySize, (int)(person.salary.size()));
			maxAwardSize = max(maxAwardSize, (int)(person.award.size()));
			input.push_back(person);
		}

		for (auto& ite : input)
		{
			// print the data, if its data size is smaller than the max one
			// then print space in front of the data
			// (salary,award) need two mores space
			cout << setw(maxNameSize) << ite.name << '|';
			cout << setw(maxSalarySize + 2) << ite.salary << '|';
			cout << setw(maxAwardSize + 2) << ite.award << endl;
		}
	}
	return 0;
}