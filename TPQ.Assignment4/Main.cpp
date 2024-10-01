#include <iostream>
#include <conio.h>

using namespace std;

struct Employee {
    int ID;
    string FirstName;
    string LastName;
    float HoursWorked;
    float HourlyRate;
};

Employee* GetEmployeeInfo(int employeeNum)
{
    Employee* pE = new Employee;
    cout << "Enter the ID for Employee " << employeeNum << ": ";
    cin >> pE->ID;
    cout << "Enter the First Name for Employee " << employeeNum << ": ";
    cin >> pE->FirstName;
    cout << "Enter the Last Name for Employee " << employeeNum << ": ";
    cin >> pE->LastName;
    cout << "Enter the Hours Worked for Employee " << employeeNum << ": ";
    cin >> pE->HoursWorked;
    cout << "Enter the Hourly Rate for Employee " << employeeNum << ": ";
    cin >> pE->HourlyRate;
    cout << "\n";
    return pE;    
}

float CalculateWeeklyPay(Employee* pE)
{
    return (pE->HoursWorked * pE->HourlyRate);
}

int main()
{
    cout << "Enter the number of employees: ";
    int numEmployees = 0;
    cin >> numEmployees;
    cout << "\n";

    Employee* employees = new Employee[numEmployees];

    for (int i = 0; i < numEmployees; i++)
    {
        employees[i] = *GetEmployeeInfo(i+1);
    }

    cout << "Pay Report" << "\n" << "----------" << "\n";  
    float totalPay = 0;

    for (int i = 0; i < numEmployees; i++)
    {
        float weeklyPay = CalculateWeeklyPay(&employees[i]); 
        cout << employees[i].ID << ". " << employees[i].FirstName << " "
            << employees[i].LastName << ": $" << weeklyPay << "\n"; 
        totalPay = totalPay + weeklyPay;
    }
    cout << "\n" << "Total Pay for all employees: $" << totalPay;

    delete[] employees;
    
    

	(void)_getch();
	return 0;
}