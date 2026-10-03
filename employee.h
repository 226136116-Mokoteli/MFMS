#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "utils.h"

float calculateTotalSalary(Employee e) {
    return e.basicSalary + e.housingAllowance + e.transportAllowance;
}

void addEmployee(Employee employees[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("\nCannot add more employees (limit of %d reached).\n", MAX_EMPLOYEES);
        return;
    }

    Employee e;
    e.id = readPositiveInt("Employee ID: ");

    for (int i = 0; i < *count; i++) {
        if (employees[i].id == e.id) {
            printf("An employee with this ID already exists.\n");
            return;
        }
    }

    readNonEmptyString("Full name: ", e.name, sizeof(e.name));
    readNonEmptyString("Department: ", e.department, sizeof(e.department));
    e.basicSalary = readNonNegativeFloat("Basic salary (N$): ");
    e.housingAllowance = readNonNegativeFloat("Housing allowance (N$): ");
    e.transportAllowance = readNonNegativeFloat("Transport allowance (N$): ");

    employees[*count] = e;
    (*count)++;

    printf("\nEmployee added successfully! Total salary: N$%.2f\n",
           calculateTotalSalary(e));
}

void displayEmployees(const Employee employees[], int count) {
    if (count == 0) {
        printf("\nNo employees registered yet.\n");
        return;
    }

    printf("\n%-5s %-20s %-15s %-12s %-12s\n", "ID", "Name", "Department", "Basic", "Total");
    printf("---------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-20s %-15s %-12.2f %-12.2f\n",
               employees[i].id,
               employees[i].name,
               employees[i].department,
               employees[i].basicSalary,
               calculateTotalSalary(employees[i]));
    }
}

void searchEmployee(const Employee employees[], int count) {
    if (count == 0) {
        printf("\nNo employees registered yet.\n");
        return;
    }

    int option = readInt("\nSearch by (1) ID or (2) Name? ");
    int found = 0;

    if (option == 1) {
        int id = readInt("Enter the ID: ");
        for (int i = 0; i < count; i++) {
            if (employees[i].id == id) {
                found = 1;
                printf("\n--- Employee found ---\n");
                printf("ID: %d\nName: %s\nDepartment: %s\n", employees[i].id, employees[i].name, employees[i].department);
                printf("Basic salary: N$%.2f\n", employees[i].basicSalary);
                printf("Total salary: N$%.2f\n", calculateTotalSalary(employees[i]));
                break;
            }
        }
    } else {
        char name[50];
        readNonEmptyString("Enter the name: ", name, sizeof(name));
        for (int i = 0; i < count; i++) {
            if (strcmp(employees[i].name, name) == 0) {
                found = 1;
                printf("\n--- Employee found ---\n");
                printf("ID: %d\nName: %s\nDepartment: %s\n", employees[i].id, employees[i].name, employees[i].department);
                printf("Total salary: N$%.2f\n", calculateTotalSalary(employees[i]));
            }
        }
    }

    if (!found) {
        printf("\nNo matching employee was found.\n");
    }
}

void employeeMenu(Employee employees[], int *count) {
    int choice;
    do {
        printf("\n---- EMPLOYEE MANAGEMENT ----\n");
        printf("1. Add employee\n");
        printf("2. Display employees\n");
        printf("3. Search employee\n");
        printf("0. Back to main menu\n");
        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1: addEmployee(employees, count); break;
            case 2: displayEmployees(employees, *count); break;
            case 3: searchEmployee(employees, *count); break;
            case 0: break;
            default: printf("Invalid option.\n");
        }
    } while (choice != 0);
}