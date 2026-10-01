#include <stdio.h>
#include <string.h>
#include "assets.h"
#include "utils.h"

void addAsset(Asset assets[], int *count) {
    if (*count >= MAX_ASSETS) {
        printf("\nAsset limit reached (%d).\n", MAX_ASSETS);
        return;
    }

    Asset a;
    a.id = readPositiveInt("Asset ID: ");

    for (int i = 0; i < *count; i++) {
        if (assets[i].id == a.id) {
            printf("An asset with this ID already exists.\n");
            return;
        }
    }

    readNonEmptyString("Asset name: ", a.name, sizeof(a.name));
    readNonEmptyString("Type (e.g. Vehicle, Computer, Building): ", a.type, sizeof(a.type));
    a.purchaseValue = readNonNegativeFloat("Purchase value (N$): ");
    readNonEmptyString("Responsible department: ", a.department, sizeof(a.department));
    readNonEmptyString("Condition (e.g. New, Good, Damaged): ", a.condition, sizeof(a.condition));

    assets[*count] = a;
    (*count)++;

    printf("\nAsset registered successfully!\n");
}

void displayAssets(const Asset assets[], int count) {
    if (count == 0) {
        printf("\nNo assets registered yet.\n");
        return;
    }

    printf("\n%-5s %-18s %-15s %-12s %-15s %-12s\n", "ID", "Name", "Type", "Value", "Department", "Condition");
    printf("---------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-18s %-15s %-12.2f %-15s %-12s\n",
               assets[i].id, assets[i].name, assets[i].type,
               assets[i].purchaseValue, assets[i].department, assets[i].condition);
    }
}

void searchAsset(const Asset assets[], int count) {
    if (count == 0) {
        printf("\nNo assets registered yet.\n");
        return;
    }

    int id = readInt("\nEnter the asset ID to search: ");
    int found = 0;

    for (int i = 0; i < count; i++) {
        if (assets[i].id == id) {
            found = 1;
            printf("\n--- Asset found ---\n");
            printf("ID: %d\nName: %s\nType: %s\nValue: N$%.2f\nDepartment: %s\nCondition: %s\n",
                   assets[i].id, assets[i].name, assets[i].type,
                   assets[i].purchaseValue, assets[i].department, assets[i].condition);
            break;
        }
    }

    if (!found) {
        printf("No asset with that ID was found.\n");
    }
}

void assetMenu(Asset assets[], int *count) {
    int choice;
    do {
        printf("\n---- ASSET MANAGEMENT ----\n");
        printf("1. Add asset\n");
        printf("2. Display assets\n");
        printf("3. Search asset\n");
        printf("0. Back to main menu\n");
        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1: addAsset(assets, count); break;
            case 2: displayAssets(assets, *count); break;
            case 3: searchAsset(assets, *count); break;
            case 0: break;
            default: printf("Invalid option.\n");
        }
    } while (choice != 0);
}
