#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 50

typedef struct {
    int id;
    char name[50];
    char department[30];
    float basicSalary;
    float housingAllowance;
    float transportAllowance;
} Employee;

void addEmployee(Employee employees[], int *count);
void displayEmployees(const Employee employees[], int count);
void searchEmployee(const Employee employees[], int count);
float calculateTotalSalary(Employee e);

void employeeMenu(Employee employees[], int *count);

#endif
