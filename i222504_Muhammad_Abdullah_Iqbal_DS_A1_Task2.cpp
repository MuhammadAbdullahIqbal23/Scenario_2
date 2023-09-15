// i222504_Muhammad_Abdullah_Iqbal_DS_A1_Task2.cpp 

#include <iostream>
#include "task_2_Header.h"
using namespace std;

int main() {
    const char* filename = "Employeedata.txt";
    const int maxEmployees = 10; // Set the maximum number of employees to 10

    EmployeeData<string> employees[maxEmployees];

    int result = ReadEmployeeData(filename, employees, maxEmployees);
    return result;
}

