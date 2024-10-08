#include <stdio.h>

#define ITEM_COUNT 3

typedef struct {
    char name[20];
    float price;
    int quantity; // Track inventory
} Item;

void displayMenu(Item items[], int itemCount) {
    printf("\nAvailable Items:\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d: %s - $%.2f (Available: %d)\n", i + 1, items[i].name, items[i].price, items[i].quantity);
    }
}

int main() {
    // Snack and beverage items
    Item snacks[ITEM_COUNT] = {
        {"Chips", 30.0, 10},
        {"Candy", 20.0, 5},
        {"Cookies", 15.0, 8}
    };

    Item beverages[ITEM_COUNT] = {
        {"Water", 20.0, 15},
        {"Soda", 25.0, 10},
        {"Juice", 30.0, 7}
    };

    int categoryChoice, itemChoice, quantity;
    float moneyInserted = 0.0;
    int paymentMethod;

    printf("Welcome to the Vending Machine!\n");
    printf("Select your category:\n");
    printf("0 - Snacks\n");
    printf("1 - Beverages\n");
    printf("Enter your choice (0 or 1): ");
    scanf("%d", &categoryChoice);

    if (categoryChoice == 0) {
        displayMenu(snacks, ITEM_COUNT); // Display snack menu

        // Ask for payment method
        printf("\nDo you want to pay with cash? (Enter 0 for Yes, 1 for No): ");
        scanf("%d", &paymentMethod);

        // Handle cash or online payment
        if (paymentMethod == 0) { // Cash payment
            printf("\nPlease insert cash (enter amount in Rs): ");
            scanf("%f", &moneyInserted);
            if (moneyInserted <= 0) {
                printf("Invalid amount entered. Please insert a positive amount.\n");
                return 1;
            }
        } else if (paymentMethod == 1) { // Online payment
            printf("\nPlease enter your online payment amount: ");
            scanf("%f", &moneyInserted);
            if (moneyInserted <= 0) {
                printf("Invalid amount entered. Please enter a positive amount.\n");
                return 1;
            }
        } else {
            printf("Invalid selection. Please enter 0 for cash or 1 for online payment.\n");
            return 1;
        }

        // Ask for item selection
        printf("Select your snack item (0, 1, or 2): ");
        scanf("%d", &itemChoice);
        
        if (itemChoice >= 0 && itemChoice < ITEM_COUNT) {
            printf("Enter quantity: ");
            scanf("%d", &quantity);

            if (quantity > snacks[itemChoice].quantity) {
                printf("Sorry, only %d of %s are available.\n", snacks[itemChoice].quantity, snacks[itemChoice].name);
                return 1;
            }

            float totalCost = quantity * snacks[itemChoice].price;

            // Check if sufficient funds are available
            if (moneyInserted >= totalCost) {
                printf("You selected: Snack %s - Rs %.2f (Quantity: %d) Total: Rs %.2f\n",
                       snacks[itemChoice].name, snacks[itemChoice].price, quantity, totalCost);
                float change = moneyInserted - totalCost;
                if (change > 0) {
                    printf("Here is your change: Rs %.2f\n", change);
                } else {
                    printf("No change to return.\n");
                }

                // Update inventory
                snacks[itemChoice].quantity -= quantity;
            } else {
                printf("Insufficient funds. You need Rs %.2f more to purchase %s.\n", totalCost - moneyInserted, snacks[itemChoice].name);
            }
        } else {
            printf("Invalid item choice.\n");
        }
        
    } else if (categoryChoice == 1) {
        displayMenu(beverages, ITEM_COUNT); // Display beverage menu

        // Ask for payment method
        printf("\nDo you want to pay with cash? (Enter 0 for Yes, 1 for No): ");
        scanf("%d", &paymentMethod);

        // Handle cash or online payment
        if (paymentMethod == 0) { // Cash payment
            printf("\nPlease insert cash (enter amount in Rs): ");
            scanf("%f", &moneyInserted);
            if (moneyInserted <= 0) {
                printf("Invalid amount entered. Please insert a positive amount.\n");
                return 1;
            }
        } else if (paymentMethod == 1) { // Online payment
            printf("\nPlease enter your online payment amount: ");
            scanf("%f", &moneyInserted);
            if (moneyInserted <= 0) {
                printf("Invalid amount entered. Please enter a positive amount.\n");
                return 1;
            }
        } else {
            printf("Invalid selection. Please enter 0 for cash or 1 for online payment.\n");
            return 1;
        }

        // Ask for item selection
        printf("Select your beverage item (0, 1, or 2): ");
        scanf("%d", &itemChoice);
        
        if (itemChoice >= 0 && itemChoice < ITEM_COUNT) {
            printf("Enter quantity: ");
            scanf("%d", &quantity);

            if (quantity > beverages[itemChoice].quantity) {
                printf("Sorry, only %d of %s are available.\n", beverages[itemChoice].quantity, beverages[itemChoice].name);
                return 1;
            }

            float totalCost = quantity * beverages[itemChoice].price;

            // Check if sufficient funds are available
            if (moneyInserted >= totalCost) {
                printf("You selected: Beverage %s - Rs %.2f (Quantity: %d) Total: Rs %.2f\n",
                       beverages[itemChoice].name, beverages[itemChoice].price, quantity, totalCost);
                float change = moneyInserted - totalCost;
                if (change > 0) {
                    printf("Here is your change: Rs %.2f\n", change);
                } else {
                    printf("No change to return.\n");
                }

                // Update inventory
                beverages[itemChoice].quantity -= quantity;
            } else {
                printf("Insufficient funds. You need Rs %.2f more to purchase %s.\n", totalCost - moneyInserted, beverages[itemChoice].name);
            }
        } else {
            printf("Invalid item choice.\n");
        }
        
    } else {
        printf("Invalid category choice.\n");
    }

    return 0;
}