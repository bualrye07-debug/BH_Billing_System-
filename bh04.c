#include <stdio.h>
#include <string.h>


void enterTenants(char names[][50], int rent[], int elec[], int water[], int total[], int n);
void displayBills(char names[][50], int rent[], int elec[], int water[], int total[], int n);
void updateBill(char names[][50], int rent[], int elec[], int water[], int total[], int n);
void recordPayment(char names[][50], int total[], int n);
void searchTenant(char names[][50], int rent[], int elec[], int water[], int total[], int n);
void viewBalance(char names[][50], int total[], int n);

int main() {
    int n, choice;
    
    printf("===== BOARDING HOUSE BILLING SYSTEM =====\n");
    printf("\n");
    printf("%28s\n", "-- Welcome! --");
    printf("\n");
    printf("How many tenants? ");
    scanf("%d", &n);

    char names[n][50];
    int rent[n], elec[n], water[n], total[n];

    enterTenants(names, rent, elec, water, total, n);

    while (1) {
        printf("\n===== BOARDING HOUSE BILLING SYSTEM =====\n");
        printf("Dashboard: \n");
        printf("1. Display All Bills\n");
        printf("2. Update Bills (Rent/Electricity/Water)\n");
        printf("3. Record Payment\n");
        printf("4. Search Tenant\n");
        printf("5. View Remaining Balance\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 1) displayBills(names, rent, elec, water, total, n);
        else if (choice == 2) updateBill(names, rent, elec, water, total, n);
        else if (choice == 3) recordPayment(names, total, n);
        else if (choice == 4) searchTenant(names, rent, elec, water, total, n);
        else if (choice == 5) viewBalance(names, total, n);
        else if (choice == 6) {
            printf("\n");
            printf("%28s\n", "-- Thank You! --\n");
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
        printf("Enter tenant %d name: ", i + 1);
        scanf("%s", names[i]);
        rent[i] = elec[i] = water[i] = total[i] = 0;
    }
}


void displayBills(char names[][50], int rent[], int elec[], int water[], int total[], int n) {
    int i;
    printf("\n--- BILLING LIST ---\n");
    printf("No.   Name        Rent   Elec   Water   TOTAL\n");

    for (i = 0; i < n; i++) {
        printf("%d    %-10s  %5d  %5d  %5d  %6d\n",
               i+1, names[i], rent[i], elec[i], water[i], total[i]);
    }
}


void updateBill(char names[][50], int rent[], int elec[], int water[], int total[], int n) {
    int num, newRent, newElec, newWater;

    printf("\nSelect a tenant to update:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s\n", i+1, names[i]);
    }
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 1 || num > n) {
        printf("Invalid tenant number!\n");
        return;
    }

    num--;

    printf("Enter new rent for %s: ", names[num]);
    scanf("%d", &newRent);

    printf("Enter new electricity bill for %s: ", names[num]);
    scanf("%d", &newElec);

    printf("Enter new water bill for %s: ", names[num]);
    scanf("%d", &newWater);

    rent[num] = newRent;
    elec[num] = newElec;
    water[num] = newWater;

    total[num] = rent[num] + elec[num] + water[num];

    printf("Bills updated successfully!\n");
}


void recordPayment(char names[][50], int total[], int n) {
    int num, amount;

    printf("\nSelect tenant to record payment:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s\n", i+1, names[i]);
    }
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 1 || num > n) {
        printf("Invalid tenant number!\n");
        return;
    }

    num--; 

    printf("Enter amount paid by %s: ", names[num]);
    scanf("%d", &amount);

    if (amount > total[num]) {
        printf("Error: Payment exceeds total balance!\n");
    } else {
        total[num] -= amount;
        printf("Payment recorded! New balance: %d\n", total[num]);
    }
}


void searchTenant(char names[][50], int rent[], int elec[], int water[], int total[], int n) {
    char search[50];
    int found = 0;

    printf("\nSearch tenant by name: ");
    scanf("%s", search);

    for (int i = 0; i < n; i++) {
        if (strcmp(names[i], search) == 0) {
            found = 1;
            printf("\n--- Tenant Found ---\n");
            printf("Name: %s\n", names[i]);
            printf("Rent: %d\n", rent[i]);
            printf("Electricity: %d\n", elec[i]);
            printf("Water: %d\n", water[i]);
            printf("Total Balance: %d\n", total[i]);
            break;
        }
    }

    if (!found) {
        printf("Tenant not found.\n");
    }
}


void viewBalance(char names[][50], int total[], int n) {
    int num;

    printf("\nSelect tenant to view remaining balance:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s\n", i+1, names[i]);
    }
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 1 || num > n) {
        printf("Invalid tenant number!\n");
        return;
    }

    num--;

    printf("Remaining balance for %s: %d\n", names[num], total[num]);
}