#include <stdio.h>
#include <string.h>


void enterTenants(char names[][50], int rent[], int elec[], int water[], int total[], int n);
void displayBills(char names[][50], int rent[], int elec[], int water[], int total[], int n);
void updateAllBills(char names[][50], int rent[], int elec[], int water[], int total[], int n);
void searchTenant(char names[][50], int rent[], int elec[], int water[], int total[], int n);
void recordPayment(char names[][50], int total[], int n);
void showBalance(char names[][50], int total[], int n);
void clearInput(); 

int main() {
    int n, choice;

    printf("===== BOARDING HOUSE BILLING SYSTEM =====\n");
    printf("\n");
    printf("%28s\n", "-- Welcome! --");
    printf("\n");
    printf("How many tenants? ");
    while (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input! Enter a valid number: ");
        clearInput();
    }

    char names[n][50];
    int rent[n], elec[n], water[n], total[n];

    enterTenants(names, rent, elec, water, total, n);

    while (1) {
        printf("\n===== BOARDING HOUSE BILLING SYSTEM =====\n");
        printf("\n");
        printf("%28s\n", "-- DASHBOARD --");
        printf("\n");
        printf("1. Display All Bills\n");
        printf("2. Update Bills (Rent, Electricity & Water)\n");
        printf("3. Record Payment\n");
        printf("4. Search Tenant\n");
        printf("5. View Remaining Balance\n");
        printf("6. Exit\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1) {
            clearInput();
            printf("Invalid input! Try again.\n");
            continue;
        }

        if (choice == 1) displayBills(names, rent, elec, water, total, n);
        else if (choice == 2) updateAllBills(names, rent, elec, water, total, n);
        else if (choice == 3) recordPayment(names, total, n);
        else if (choice == 4) searchTenant(names, rent, elec, water, total, n);
        else if (choice == 5) showBalance(names, total, n);
        else if (choice == 6) {
            printf("Exiting system...\n");
            break;
        }
        else printf("Invalid choice! Try again.\n");
    }

    return 0;
}


void clearInput() {
    while (getchar() != '\n');
}

// Enter tenant names
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


void updateAllBills(char names[][50], int rent[], int elec[], int water[], int total[], int n) {
    int num, r, e, w;

    printf("\nSelect tenant to update:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s\n", i + 1, names[i]);
    }

    printf("Enter tenant number: ");
    if (scanf("%d", &num) != 1 || num < 1 || num > n) {
        clearInput();
        printf("Invalid tenant number!\n");
        return;
    }

    num--; 

    printf("Enter Rent: ");
    scanf("%d", &r);

    printf("Enter Electricity: ");
    scanf("%d", &e);

    printf("Enter Water: ");
    scanf("%d", &w);

    rent[num] = r;
    elec[num] = e;
    water[num] = w;

    total[num] = rent[num] + elec[num] + water[num];

    printf("Bills updated successfully!\n");
}


void recordPayment(char names[][50], int total[], int n) {
    int num, pay;

    printf("\nSelect tenant to record payment:\n");
    for (int i = 0; i < n; i++)
        printf("%d. %s\n", i + 1, names[i]);

    printf("Enter tenant number: ");
    if (scanf("%d", &num) != 1 || num < 1 || num > n) {
        clearInput();
        printf("Invalid tenant number!\n");
        return;
    }

    num--;

    printf("Enter amount paid by %s: ", names[num]);
    scanf("%d", &pay);

    if (pay > total[num]) {
        printf("Payment exceeds total bill!\n");
    } else {
        total[num] -= pay;
        printf("Payment recorded! Remaining balance: %d\n", total[num]);
    }
}


void searchTenant(char names[][50], int rent[], int elec[], int water[], int total[], int n) {
    char search[50];
    int found = 0;

    printf("\nEnter tenant name to search: ");
    scanf("%s", search);

    for (int i = 0; i < n; i++) {
        if (strcmp(names[i], search) == 0) {
            printf("\n--- Tenant Found ---\n");
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


void showBalance(char names[][50], int total[], int n) {
    int num;

    printf("\nSelect tenant to view balance:\n");
    for (int i = 0; i < n; i++)
        printf("%d. %s\n", i + 1, names[i]);

    printf("Enter tenant number: ");
    if (scanf("%d", &num) != 1 || num < 1 || num > n) {
        clearInput();
        printf("Invalid tenant number!\n");
        return;
    }

    num--;

    printf("\nRemaining Balance for %s: %d pesos\n", names[num], total[num]);
}