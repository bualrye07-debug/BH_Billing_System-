#include <stdio.h>
#include <string.h>

#define MAX_TENANTS 50 // maximum tenants allowed

// Function declarations
void addTenant(char names[][50], int rent[], int elec[], int water[], int total[], int *n);
void displayTenants(char names[][50], int n);
void displayBills(char names[][50], int rent[], int elec[], int water[], int total[], int n);
void updateAllBills(char names[][50], int rent[], int elec[], int water[], int total[], int n);
void recordPayment(char names[][50], int total[], int n);
void searchTenant(char names[][50], int rent[], int elec[], int water[], int total[], int n);
void showBalance(char names[][50], int total[], int n);
void clearInput(); // clears invalid input

int main() {
    int n = 0; // current number of tenants
    int choice;

    char names[MAX_TENANTS][50];    
    int rent[MAX_TENANTS], elec[MAX_TENANTS], water[MAX_TENANTS], total[MAX_TENANTS];

int introChoice;
    while (1) {
        printf("===== BOARDING HOUSE BILLING SYSTEM =====\n");
        printf("\n");
        printf("%28s\n", "-- Welcome! --");
        printf("\n");
        printf("1. Continue to Dashboard\n");
        printf("2. Exit\n");
        printf("Choose an option: ");
        
        if (scanf("%d", &introChoice) != 1) {
            clearInput();
            printf("Invalid input! Try again.\n");
            continue;
        }
    
    if (introChoice == 1) {
            break; // proceed to dashboard
        } else if (introChoice == 2) {
            printf("Exiting system...\n");
            return 0;
        } else {
            printf("Invalid choice! Please select 1 or 2.\n");
        }
    }


    while (1) {
        printf("\n===== BOARDING HOUSE BILLING SYSTEM =====\n");
        printf("\n");
        printf("%28s\n", "-- DASHBOARD --");
        printf("\n");
        printf("1. Add New Tenant\n");
        printf("2. Display Tenants List\n");
        printf("3. Display All Bills\n");
        printf("4. Update Bills (Rent, Electricity & Water)\n");
        printf("5. Record Payment\n");
        printf("6. Search Tenant\n");
        printf("7. View Remaining Balance\n");
        printf("8. Exit\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1) {
            clearInput();
            printf("Invalid input! Try again.\n");
            continue;
        }

        switch (choice) {
            case 1:
                if (n < MAX_TENANTS) {
                    addTenant(names, rent, elec, water, total, &n);
                } else {
                    printf("Tenant list is full!\n");
                }
                break;
            case 2:
                if (n == 0) {
                    printf("No tenants yet.\n");
                } else {
                    displayTenants(names, n);
                }
                break;    
            case 3:
                if (n == 0) {
                    printf("No tenants yet.\n");
                } else {
                    displayBills(names, rent, elec, water, total, n);
                }
                break;
            case 4:
                if (n == 0) {
                    printf("No tenants to update.\n");
                } else {
                    updateAllBills(names, rent, elec, water, total, n);
                }
                break;
            case 5:
                if (n == 0) {
                    printf("No tenants to record payment.\n");
                } else {
                    recordPayment(names, total, n);
                }
                break;
            case 6:
                if (n == 0) {
                    printf("No tenants to search.\n");
                } else {
                    searchTenant(names, rent, elec, water, total, n);
                }
                break;
            case 7:
                if (n == 0) {
                    printf("No tenants to view balance.\n");
                } else {
                    showBalance(names, total, n);
                }
                break;
            case 8:
                printf("\n");
                printf("%28s\n", "-- Thank You! --");
                printf("\n");
                printf("Exiting system...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

// clears invalid input
void clearInput() {
    while (getchar() != '\n'); // removes unwanted characters
}

// Add a new tenant
void addTenant(char names[][50], int rent[], int elec[], int water[], int total[], int *n) {
    printf("\nEnter tenant name: ");
    scanf("%s", names[*n]);
    rent[*n] = 0;
    elec[*n] = 0;
    water[*n] = 0;
    total[*n] = 0;
    (*n)++;
    printf("Tenant added successfully!\n");
}

 //Display tenant list only
void displayTenants(char names[][50], int n) {
    printf("\n--- TENANT LIST ---\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s\n", i + 1, names[i]);
    }
}
// Display bills
void displayBills(char names[][50], int rent[], int elec[], int water[], int total[], int n) {
    printf("\n--- FULL BILLING LIST ---\n");
    printf("No.   Name        Rent   Elec   Water   TOTAL\n");
    for (int i = 0; i < n; i++) {
        printf("%d    %-10s  %5d  %5d  %5d  %6d\n",
               i+1, names[i], rent[i], elec[i], water[i], total[i]);
    }
}

// COMBINED UPDATE (rent, water, electricity)
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

    num--; // convert to array index

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

// Payment
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

// Search tenant by name
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

// View remaining balance
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