//Muhammad_Abdullah_Abdullah_Iqbal_22i2504
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <typename T>
struct EmployeeData {
    T name;
    T employeeID;
    double salary;
    double dateOfJoining;
    T designation;

    EmployeeData(const T& name, const T& employeeID, double salary, double dateOfJoining, const T& designation)
        : name(name), employeeID(employeeID), salary(salary), dateOfJoining(dateOfJoining), designation(designation) {}

    EmployeeData() = default;
};

template <typename T>
int ReadEmployeeData(const char* filename, EmployeeData<T> employees[], int maxEmployees) {
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cout << "Failed to open the file." << endl;
        return 1;
    }
    int lowestSalaryEmployeeIndex=0;
    int highestSalaryEmployeeIndex=0;
    int employeeCount = 0;
    double highestSalary = 0.0;
    double lowestSalary = 100; 
    double *salaries= new double[10];
    int salaryCount = 0;

    for(int i = 0 ; i< maxEmployees;i++) {
        inputFile.ignore(100, ':');
        getline(inputFile, employees[i].name);

        inputFile.ignore(100, ':');
        getline(inputFile, employees[i].employeeID);

        inputFile.ignore(100, '$');
        inputFile >> employees[i].salary;
        salaries[salaryCount++] = employees[i].salary;

        inputFile.ignore(100, ':');
        inputFile >> employees[i].dateOfJoining;

        inputFile.ignore(100, ':');
        getline(inputFile, employees[i].designation);

        inputFile.ignore(2, '\n');
        employeeCount++;
    }

    inputFile.close();

    cout << "Total number of employees: " << employeeCount << endl;
    for (int i = 1; i < maxEmployees; i++) {
        if (employees[i].salary > highestSalary) {
            highestSalaryEmployeeIndex = i;
            highestSalary = employees[i].salary;
        }
    }
    for (int i = 0; i < maxEmployees; i++) {
        if (employees[i].salary < lowestSalary) {
            lowestSalaryEmployeeIndex = i;
            lowestSalary = employees[i].salary;
        }
    }
    double salaryRange;
    if (employeeCount > 0) {
        cout << "Employee with the highest salary: " << employees[highestSalaryEmployeeIndex].name << endl;
        cout << "Employee with the lowest salary: " << employees[lowestSalaryEmployeeIndex].name << endl;
        salaryRange = highestSalary - lowestSalary;
        cout << "The salary range: $" << salaryRange << "K" << endl;
        if (salaryCount > 0) {
            for (int i = 0; i < salaryCount - 1; i++) {
                for (int j = 0; j < salaryCount - i - 1; j++) {
                    if (salaries[j] > salaries[j + 1]) {
                        double temp = salaries[j];
                        salaries[j] = salaries[j + 1];
                        salaries[j + 1] = temp;
                    }
                }
            }
            double medianSalary;
            int middle1 = salaryCount / 2;
            int middle2 = (salaryCount - 1) / 2;
            medianSalary = (salaries[middle1] + salaries[middle2]) / 2.0;
            cout << "Median salary: $" << medianSalary << "K" << endl;
        }
        for (int i = 0; i < 40; i++) {
            cout << "-";
       }
        cout << endl;
        double TotalSalaryAccordingToDesignation[10] = { 0 };
        double CountAccordingToDesignation[10] = { 0 };

        for (int i = 0; i < maxEmployees; i++) {
            for (int j = 0; j < maxEmployees; j++) {
                if (employees[i].designation == employees[j].designation) {
                    TotalSalaryAccordingToDesignation[i] += employees[j].salary;
                    CountAccordingToDesignation[i]++;
                }
            }
        }
       
        cout << "Average Salary according to Designation\n";
        for (int i = 0; i < 8; i++) {
            if (CountAccordingToDesignation[i] > 0&& i!=6) {
                double averageSalary = TotalSalaryAccordingToDesignation[i] / CountAccordingToDesignation[i];
                cout << employees[i].designation << ": $" << averageSalary <<"K" << endl;
            }
        }
        for (int i = 0; i < 40; i++) {
            cout << "-";
        }
        cout << endl;


    }
    else {
        cout << "No employee data found." << endl;
    }

    return 0;
}
