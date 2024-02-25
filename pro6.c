/*A Call centre phone system has to hold the phone calls from customers and provide service based on the arrival time of the calls. Design and implement a C program to simulate this system using a Circular queue. Program should have options to add and remove the phone calls in appropriate order for their service. (Array Implementation of Queue with maximum size MAX). Include C functions to perform the following operations.
a.	Add a call
b.	Delete a call 
c.	Display the current status of  calls 
Demonstrate Overflow and Underflow conditions .*/


#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Queue {
    int front, rear;
    long int calls[MAX];
};

void initializeQueue(struct Queue *q) {
    q->front = q->rear = -1;
}

int isFull(struct Queue *q) {
    return (q->front == (q->rear + 1) % MAX);
}

int isEmpty(struct Queue *q) {
    return (q->front == -1);
}

void enqueue(struct Queue *q, long int phoneNumber) {
    if (isFull(q)) {
        printf("Overflow: Queue is full. Cannot add more calls.\n");
    } else {
        if (isEmpty(q)) {
            q->front = q->rear = 0;
        } else {
            q->rear = (q->rear + 1) % MAX;
        }
        q->calls[q->rear] = phoneNumber;
        printf("Call added successfully.\n");
    }
}

void dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Underflow: Queue is empty. No calls to remove.\n");
    } else {
        printf("Call %ld removed.\n", q->calls[q->front]);
        if (q->front == q->rear) {
            initializeQueue(q);
        } else {
            q->front = (q->front + 1) % MAX;
        }
    }
}

void displayQueue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Current status of calls: ");
        int i = q->front;
        do {
            printf("%ld ", q->calls[i]);
            i = (i + 1) % MAX;
        } while (i != (q->rear + 1) % MAX);
        printf("\n");
    }
}

int main() {
    struct Queue callQueue;
    initializeQueue(&callQueue);

    int choice;
    long int phoneNumber;

    do {
        printf("\n----- Call Center Simulation -----\n");
        printf("1. Add a call\n");
        printf("2. Delete a call\n");
        printf("3. Display current status of calls\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the phone number (10 digits): ");
                scanf("%ld", &phoneNumber);
                enqueue(&callQueue, phoneNumber);
                break;
            case 2:
                dequeue(&callQueue);
                break;
            case 3:
                displayQueue(&callQueue);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}
