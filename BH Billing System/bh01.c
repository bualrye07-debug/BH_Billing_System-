#include <stdio.h>
#include <string.h>


void enterTenants(char names[][50], int rent[], int elec[], int water[], int total[], int n);
void displayBills(char names[][50], int rent[], int elec[], int water[], int total[], int n);
void updateElectricity(char names[][50], int elec[], int total[], int n);
void updateWater(char names[][50], int water[], int total[], int n);
void updateRent(char names[][50], int rent[], int total[], int n);
void searchTenant(char names[][50], int rent[], int elec[], int water[], int total[], int n);
void recordPayment(char names[][50], int total[], int n);

int main() {
    int n, choice;

    printf("How many tenants? ");
    scanf("%d", &n);

    char names[n][50];
    int rent[n], elec[n], water[n], total[n];

    enterTenants(names, rent, elec, water, total, n);

    while (1) {
        printf("\n===== ADVANCED BOARDING HOUSE BILLING SYSTEM =====\n");
        printf("1. Display All Bills\n");
        printf("2. Update Rent\n");
        printf("3. Update Electricity Bill\n");
        printf("4. Update Water Bill\n");
        printf("5. Record Payment\n");
        printf("6. Search Tenant\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 1) displayBills(names, rent, elec, water, total, n);
        else if (choice == 2) updateRent(names, rent, total, n);
        else if (choice == 3) updateElectricity(names, elec, total, n);
        else if (choice == 4) updateWater(names, water, total, n);
        else if (choice == 5) recordPayment(names, total, n);
        else if (choice == 6) searchTenant(names, rent, elec, water, total, n);
        else if (choice == 7) {
            printf("Exiting system...\n");
            break;
        }
        else printf("Invalid choice! Try again.\n");
    }

    return 0;
}


void enterTenants(char names[][50], int rent[], int elec[], int water[], int total[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("\nEnter tenant %d name: ", i + 1);
        scanf("%s", names[i]);

        rent[i] = 0;
        elec[i] = 0;
        water[i] = 0;
        total[i] = 0;
    }
}


void displayBills(char names[][50], int rent[], int elec[], int water[], int total[], int n) {
    int i;

    printf("\n--- FULL BILLING LIST ---\n");
    printf("No.   Name        Rent   Elec   Water   TOTAL\n");

    for (i = 0; i < n; i++) {
        printf("%d    %-10s  %5d  %5d  %5d  %6d\n", 
            i+1, names[i], rent[i], elec[i], water[i], total[i]);
    }
}


void updateRent(char names[][50], int rent[], int total[], int n) {
    int num, newRent;

    printf("\nSelect tenant number to update rent: ");
    scanf("%d", &num);

    if (num < 1 || num > n) {
        printf("Invalid tenant number!\n");
        return ;
    }

    printf("Enter new rent for %s: ", names[num - 1]);
    scanf("%d", &newRent);

    rent[num - 1] = newRent;
    total[num - 1] = rent[num - 1] + total[num - 1] - (total[num - 1] - rent[num - 1]);

    printf("Rent updated successfully!\n");
}


void updateElectricity(char names[][50], int elec[], int total[], int n) {
    int num, amount;

    printf("\nSelect tenant number to update electricity bill: ");
    scanf("%d", &num);

    if (num < 1 || num > n) {
        printf("Invalid tenant number!\n");
        return ;
    }

    printf("Enter electricity bill for %s: ", names[num - 1]);
    scanf("%d", &amount);

    elec[num - 1] = amount;
    total[num - 1] = elec[num - 1] + total[num - 1] - (total[num - 1] - elec[num - 1]);

    printf("Electricity bill updated!\n");
}


void updateWater(char names[][50], int water[], int total[], int n) {
    int num, amount;

    printf("\nSelect tenant number to update water bill: ");
    scanf("%d", &num);

    if (num < 1 || num > n) {
        printf("Invalid tenant number!\n");
        return;
    }

    printf("Enter water bill for %s: ", names[num - 1]);
    scanf("%d", &amount);

    water[num - 1] = amount;
    total[num - 1] = water[num - 1] + total[num - 1] - (total[num - 1] - water[num - 1]);

    printf("Water bill updated!\n");
}


void recordPayment(char names[][50], int total[], int n) {
    int num, pay;

    printf("\nSelect tenant to record payment: ");
    scanf("%d", &num);

    if (num < 1 || num > n) {
        printf("Invalid tenant number!\n");
        return;
    }

    printf("Enter amount paid by %s: ", names[num - 1]);
    scanf("%d", &pay);

    if (pay > total[num - 1]) {
        printf("Payment exceeds total bill!\n");
    } else {
        total[num - 1] -= pay;
        printf("Payment recorded! Remaining balance: %d\n", total[num - 1]);
    }
}


void searchTenant(char names[][50], int rent[], int elec[], int water[], int total[], int n) {
    char search[50];
    int i, found = 0;

    printf("\nEnter tenant name to search: ");
    scanf("%s", search);

    for (i = 0; i < n; i++) {
        if (strcmp(names[i], search) == 0) {
            printf("\n--- Tenant Found ---\n");
            printf("Name: %s\n", names[i]);
            printf("Rent: %d\n", rent[i]);
            printf("Electricity: %d\n", elec[i]);
            printf("Water: %d\n", water[i]);
            printf("Total Balance: %d\n", total[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Tenant not found!\n");
    }
    
}