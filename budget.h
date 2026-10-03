#ifndef BUDGET_H
#define BUDGET_H

#define MAX_BUDGETS 30

typedef struct {
    char department[30];
    float allocatedBudget;
    float expenditure;
} Budget;

float calculateRemaining(Budget b);
int isWithinBudget(Budget b);

void addBudget(Budget budgets[], int *count);
void displayBudgets(const Budget budgets[], int count);

void budgetMenu(Budget budgets[], int *count);

#endif
