#include <stdio.h>
#include <string.h>

#define MAX_COURIERS 100
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_PHONE_LENGTH 15

struct Courier {
    int id;
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char phone[MAX_PHONE_LENGTH];
};

struct Courier couriers[MAX_COURIERS];
int num_couriers = 0;

void add_courier() {
    struct Courier new_courier;
    new_courier.id = num_couriers + 1;

    printf("Enter name: ");
    scanf("%s", new_courier.name);

    printf("Enter address: ");
    scanf("%s", new_courier.address);

    printf("Enter phone: ");
    scanf("%s", new_courier.phone);

    couriers[num_couriers] = new_courier;
    num_couriers++;

    printf("Courier added successfully.\n");
}

void list_couriers() {
    printf("ID\tName\t\tAddress\t\tPhone\n");
    for (int i = 0; i < num_couriers; i++) {
        printf("%d\t%s\t\t%s\t\t%s\n", couriers[i].id, couriers[i].name, couriers[i].address, couriers[i].phone);
    }
}

void delete_courier() {
    int id;
    printf("Enter ID of courier to delete: ");
    scanf("%d", &id);

    int index = -1;
    for (int i = 0; i < num_couriers; i++) {
        if (couriers[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Courier with ID %d not found.\n", id);
    } else {
        for (int i = index; i < num_couriers - 1; i++) {
            couriers[i] = couriers[i + 1];
        }
        num_couriers--;
        printf("Courier with ID %d deleted successfully.\n", id);
    }
}

int main() {
    int choice;
    do {
        printf("Courier Management System\n");
        printf("-------------------------\n");
        printf("1. Add courier\n");
        printf("2. List couriers\n");
        printf("3. Delete courier\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_courier();
                break;
            case 2:
                list_couriers();
                break;
            case 3:
                delete_courier();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}