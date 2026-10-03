#include <stdio.h>
#include <string.h>
#include "suppliers.h"
#include "utils.h" 

void addSupplier(Supplier suppliers[], int *count) {
    if (*count >= MAX_SUPPLIERS) {
        printf("\nSupplier limit reached (%d).\n", MAX_SUPPLIERS);
        return;
    }

    Supplier s;
    s.id = readPositiveInt("Supplier ID: ");

    for (int i = 0; i < *count; i++) {
        if (suppliers[i].id == s.id) {
            printf("A supplier with this ID already exists.\n");
            return;
        }
    }

    readNonEmptyString("Supplier name: ", s.name, sizeof(s.name));
    readNonEmptyString("Email: ", s.email, sizeof(s.email));
    readNonEmptyString("Phone: ", s.phone, sizeof(s.phone));
    readNonEmptyString("Town/Location: ", s.town, sizeof(s.town));

    suppliers[*count] = s;
    (*count)++;

    printf("\nSupplier added successfully!\n");
}

void displaySuppliers(const Supplier suppliers[], int count) {
    if (count == 0) {
        printf("\nNo suppliers registered yet.\n");
        return;
    }

    printf("\n%-5s %-20s %-25s %-15s %-15s\n", "ID", "Name", "Email", "Phone", "Town");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-20s %-25s %-15s %-15s\n",
               suppliers[i].id, suppliers[i].name, suppliers[i].email,
               suppliers[i].phone, suppliers[i].town);
    }
}

void searchSupplier(const Supplier suppliers[], int count) {
    if (count == 0) {
        printf("\nNo suppliers registered yet.\n");
        return;
    }

    char name[50];
    readNonEmptyString("\nEnter the supplier name to search: ", name, sizeof(name));

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(suppliers[i].name, name) == 0) {
            found = 1;
            printf("\n--- Supplier found ---\n");
            printf("ID: %d\nName: %s\nEmail: %s\nPhone: %s\nTown: %s\n",
                   suppliers[i].id, suppliers[i].name, suppliers[i].email,
                   suppliers[i].phone, suppliers[i].town);
        }
    }

    if (!found) {
        printf("No supplier with that name was found.\n");
    }
}

void supplierMenu(Supplier suppliers[], int *count) {
    int choice;
    do {
        printf("\n---- SUPPLIER MANAGEMENT ----\n");
        printf("1. Add supplier\n");
        printf("2. Display suppliers\n");
        printf("3. Search supplier\n");
        printf("0. Back to main menu\n");
        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1: addSupplier(suppliers, count); break;
            case 2: displaySuppliers(suppliers, *count); break;
            case 3: searchSupplier(suppliers, *count); break;
            case 0: break;
            default: printf("Invalid option.\n");
        }
    } while (choice != 0);
}