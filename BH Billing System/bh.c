#include <stdio.h>
#include <string.h>

struct Room {
    int roomNumber;
    char boarder[50];
    float rent, water, electricity, internet, others, total;
};

int main() {

    // ==== PRE-SET 10 ROOMS ====
    struct Room rooms[10] = {
        {101, "Juan Dela Cruz", 3000, 200, 350, 500, 100, 0},
        {102, "Maria Santos",   2800, 180, 320, 500,  50, 0},
        {103, "Mark Reyes",     2500, 150, 300, 400,  80, 0},
        {104, "Ana Cruz",       2700, 160, 330, 500, 120, 0},
        {105, "Carlo Dizon",    2600, 140, 310, 400,  70, 0},
        {106, "Jenny Antolin",  2900, 200, 360, 500,  90, 0},
        {107, "Lito Geron",     2400, 130, 280, 400,  50, 0},
        {108, "Claire Robles",  3100, 210, 390, 500, 130, 0},
        {109, "Paul Mendoza",   2550, 150, 305, 400,  85, 0},
        {110, "Grace Velasco",  2950, 190, 345, 500,  60, 0}
    };

    // compute totals
    for (int i = 0; i < 10; i++) {
        rooms[i].total = rooms[i].rent + rooms[i].water + rooms[i].electricity +
                         rooms[i].internet + rooms[i].others;
    }

    int search;

    while (1) {
        printf("\n====================================\n");
        printf(" ENTER ROOM NUMBER TO VIEW BILL: ");
        scanf("%d", &search);

        int found = 0;

        for (int i = 0; i < 10; i++) {
            if (rooms[i].roomNumber == search) {
                found = 1;

                printf("\n===== ROOM %d INFORMATION =====\n", search);
                printf("Boarder: %s\n", rooms[i].boarder);

                printf("\nBills This Month:\n");
                printf("Rent: %.2f\n", rooms[i].rent);
                printf("Water: %.2f\n", rooms[i].water);
                printf("Electricity: %.2f\n", rooms[i].electricity);
                printf("Internet: %.2f\n", rooms[i].internet);
                printf("Others: %.2f\n", rooms[i].others);
                printf("TOTAL BILL: %.2f\n", rooms[i].total);
                break;
            }
        }

        if (!found)
            printf("\nRoom not found. Try again.\n");
    }

    return 0;
}