#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS 30

typedef struct {
    int id;
    char name[50];
    char type[30];
    float purchaseValue;
    char department[30];
    char condition[20];
} Asset;

void addAsset(Asset assets[], int *count);
void displayAssets(const Asset assets[], int count);
void searchAsset(const Asset assets[], int count);

void assetMenu(Asset assets[], int *count);

#endif
