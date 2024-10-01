#include <stdio.h>
#include <string.h>

#define MAX_CAKES 5

typedef struct {
    char code[6];
    char name[30];
    int available;
    int price;
} Cake;

void displayCakes(Cake cakes[]) {
    printf("No\tCake Code\tCake Name\tAvailable\tPrice\n");
    for (int i = 0; i < MAX_CAKES; i++) {
        printf("%d\t%s\t\t%s\t%d\t\tRp%d,-\n", i + 1, cakes[i].code, cakes[i].name, cakes[i].available, cakes[i].price);
    }
}

int findCakeByCode(Cake cakes[], char code[]) {
    for (int i = 0; i < MAX_CAKES; i++) {
        if (strcmp(cakes[i].code, code) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    Cake cakes[MAX_CAKES] = {
        {"A001", "Chocolate Cake", 10, 50000},
        {"A002", "Vanilla Cake", 8, 45000},
        {"A003", "Cheesecake", 5, 60000},
        {"A004", "Strawberry Cake", 12, 55000},
        {"A005", "Blackforest Cake", 7, 70000}
    };

    int choice;

    do {
        printf("\n--- BLUE Cake Shop ---\n");
        printf("1. Sell\n");
        printf("2. Add Stock\n");
        printf("3. Exit\n");
        printf("Choose menu: ");
        scanf("%d", &choice);

        if (choice == 1) {
            char code[6];
            int quantity, idx;

            displayCakes(cakes);

            do {
                printf("\nEnter Cake Code to Sell (5 characters): ");
                scanf("%s", code);

                idx = findCakeByCode(cakes, code);
                if (idx == -1) {
                    printf("--- The Cake Code doesn’t exist ---\n");
                }
            } while (idx == -1);

            do {
                printf("Enter quantity to sell (max %d): ", cakes[idx].available);
                scanf("%d", &quantity);
                if (quantity > cakes[idx].available || quantity < 0) {
                    printf("...The quantity of cake is not enough...\n");
                }
            } while (quantity > cakes[idx].available || quantity < 0);

            int totalPrice = quantity * cakes[idx].price;
            printf("Total Price = Rp%d,-\n", totalPrice);

            cakes[idx].available -= quantity;
        }
        else if (choice == 2) {
            char code[6];
            int quantity, idx;

            displayCakes(cakes);

            do {
                printf("\nEnter Cake Code to Add Stock (5 characters): ");
                scanf("%s", code);

                idx = findCakeByCode(cakes, code);
                if (idx == -1) {
                    printf("--- The Cake Code doesn’t exist ---\n");
                }
            } while (idx == -1);

            do {
                printf("Enter quantity to add (1-10): ");
                scanf("%d", &quantity);
                if (quantity < 1 || quantity > 10) {
                    printf("Invalid quantity, must be between 1 and 10\n");
                }
            } while (quantity < 1 || quantity > 10);

            cakes[idx].available += quantity;
            printf("--- Adding Stock Success ---\n");
        }

    } while (choice != 3);

    printf("Program terminated.\n");
    return 0;
}

