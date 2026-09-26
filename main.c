#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"
#include "utils.h"

void displayMenu(void);

int main(void) {
    Employee employees[MAX_EMPLOYEES];
    int employeeCount = 0;

    Budget budgets[MAX_BUDGETS];
    int budgetCount = 0;

    Supplier suppliers[MAX_SUPPLIERS];
    int supplierCount = 0;

    Asset assets[MAX_ASSETS];
    int assetCount = 0;

    int choice;

    printf("========================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");

    do {
        displayMenu();
        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1:
                employeeMenu(employees, &employeeCount);
                break;
            case 2:
                budgetMenu(budgets, &budgetCount);
                break;
            case 3:
                supplierMenu(suppliers, &supplierCount);
                break;
            case 4:
                assetMenu(assets, &assetCount);
                break;
            case 5:
                reportsMenu(employees, employeeCount,
                             budgets, budgetCount,
                             suppliers, supplierCount,
                             assets, assetCount);
                break;
            case 6:
                printf("\nA sair do sistema. Ate breve!\n");
                break;
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }
    } while (choice != 6);

    return 0;
}

void displayMenu(void) {
    printf("\n========================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
}