#include <stdio.h>
#include "reports.h"
#include "utils.h"

void employeeReport(const Employee employees[], int count) {
    printf("\n===== EMPLOYEE REPORT =====\n");
    if (count == 0) {
        printf("No employees registered.\n");
        return;
    }

    float total = 0;
    float highest = calculateTotalSalary(employees[0]);
    float lowest = calculateTotalSalary(employees[0]);

    for (int i = 0; i < count; i++) {
        float salary = calculateTotalSalary(employees[i]);
        total += salary;
        if (salary > highest) highest = salary;
        if (salary < lowest) lowest = salary;
    }

    printf("Total employees: %d\n", count);
    printf("Average salary: N$%.2f\n", total / count);
    printf("Highest salary: N$%.2f\n", highest);
    printf("Lowest salary: N$%.2f\n", lowest);
}

void budgetReport(const Budget budgets[], int count) {
    printf("\n===== BUDGET REPORT =====\n");
    if (count == 0) {
        printf("No budgets registered.\n");
        return;
    }

    float totalAllocated = 0, totalExpenditure = 0;
    for (int i = 0; i < count; i++) {
        totalAllocated += budgets[i].allocatedBudget;
        totalExpenditure += budgets[i].expenditure;
    }

    printf("Total allocated budget: N$%.2f\n", totalAllocated);
    printf("Total expenditure: N$%.2f\n", totalExpenditure);
    printf("Total remaining budget: N$%.2f\n", totalAllocated - totalExpenditure);

    printf("\nDepartments that exceeded their budget:\n");
    int anyExceeded = 0;
    for (int i = 0; i < count; i++) {
        if (!isWithinBudget(budgets[i])) {
            printf(" - %s (exceeded by N$%.2f)\n", budgets[i].department, -calculateRemaining(budgets[i]));
            anyExceeded = 1;
        }
    }
    if (!anyExceeded) {
        printf(" No department exceeded its budget.\n");
    }
}

void supplierReport(const Supplier suppliers[], int count) {
    printf("\n===== SUPPLIER REPORT =====\n");
    if (count == 0) {
        printf("No suppliers registered.\n");
        return;
    }
    printf("Total suppliers registered: %d\n", count);
    displaySuppliers(suppliers, count);
}

void assetReport(const Asset assets[], int count) {
    printf("\n===== ASSET REPORT =====\n");
    if (count == 0) {
        printf("No assets registered.\n");
        return;
    }

    float totalValue = 0;
    for (int i = 0; i < count; i++) {
        totalValue += assets[i].purchaseValue;
    }

    printf("Total assets registered: %d\n", count);
    printf("Total asset value: N$%.2f\n", totalValue);
    displayAssets(assets, count);
}

void reportsMenu(const Employee employees[], int employeeCount,
                  const Budget budgets[], int budgetCount,
                  const Supplier suppliers[], int supplierCount,
                  const Asset assets[], int assetCount) {
    int choice;
    do {
        printf("\n---- REPORTS ----\n");
        printf("1. Employee report\n");
        printf("2. Budget report\n");
        printf("3. Supplier report\n");
        printf("4. Asset report\n");
        printf("0. Back to main menu\n");
        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1: employeeReport(employees, employeeCount); break;
            case 2: budgetReport(budgets, budgetCount); break;
            case 3: supplierReport(suppliers, supplierCount); break;
            case 4: assetReport(assets, assetCount); break;
            case 0: break;
            default: printf("Invalid option.\n");
        }
    } while (choice != 0);
}
