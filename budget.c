#include <stdio.h>
#include <string.h>
#include "budget.h"
#include "utils.h"

float calculateRemaining(Budget b) {
    return b.allocatedBudget - b.expenditure;
}

int isWithinBudget(Budget b) {
    return calculateRemaining(b) >= 0;
}

void addBudget(Budget budgets[], int *count) {
    if (*count >= MAX_BUDGETS) {
        printf("\nDepartment limit reached (%d).\n", MAX_BUDGETS);
        return;
    }

    Budget b;
    readNonEmptyString("Department name: ", b.department, sizeof(b.department));

    for (int i = 0; i < *count; i++) {
        if (strcmp(budgets[i].department, b.department) == 0) {
            printf("This department already exists. Use the display option to view it.\n");
            return;
        }
    }

    b.allocatedBudget = readNonNegativeFloat("Allocated budget (N$): ");
    b.expenditure = readNonNegativeFloat("Expenditure (N$): ");

    budgets[*count] = b;
    (*count)++;

    printf("\nBudget registered! Remaining balance: N$%.2f (%s)\n",
           calculateRemaining(b),
           isWithinBudget(b) ? "WITHIN BUDGET" : "BUDGET EXCEEDED");
}

void displayBudgets(const Budget budgets[], int count) {
    if (count == 0) {
        printf("\nNo budgets registered yet.\n");
        return;
    }

    printf("\n%-15s %-12s %-12s %-12s %-18s\n", "Department", "Allocated", "Expenditure", "Remaining", "Status");
    printf("-------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        float remaining = calculateRemaining(budgets[i]);
        printf("%-15s %-12.2f %-12.2f %-12.2f %-18s\n",
               budgets[i].department,
               budgets[i].allocatedBudget,
               budgets[i].expenditure,
               remaining,
               isWithinBudget(budgets[i]) ? "WITHIN BUDGET" : "EXCEEDED");
    }
}

void budgetMenu(Budget budgets[], int *count) {
    int choice;
    do {
        printf("\n---- BUDGET MANAGEMENT ----\n");
        printf("1. Add department budget\n");
        printf("2. Display budgets\n");
        printf("0. Back to main menu\n");
        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1: addBudget(budgets, count); break;
            case 2: displayBudgets(budgets, *count); break;
            case 0: break;
            default: printf("Invalid option.\n");
        }
    } while (choice != 0);
}
