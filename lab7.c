#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a student
typedef struct Student {
    char USN[20];
    char Name[50];
    int Sem;
    char PhNo[15];
    struct Student* link;
} Student;

// Function prototypes
void createFront(Student** head, int n);
void displayList(Student* head);
int countNodes(Student* head);
void insertEnd(Student** head);
void deleteEnd(Student** head);
void insertFront(Student** head);
void deleteFront(Student** head);

int main() {
    Student* head = NULL;
    int choice, n;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create SLL of N Students Data by using front insertion\n");
        printf("2. Display the status of SLL and count the number of nodes in it\n");
        printf("3. Perform Insertion at End of SLL\n");
        printf("4. Perform Deletion at End of SLL\n");
        printf("5. Perform Insertion at Front of SLL\n");
        printf("6. Perform Deletion at Front of SLL\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of students: ");
                scanf("%d", &n);
                createFront(&head, n);
                break;
            case 2:
                displayList(head);
                printf("Number of nodes: %d\n", countNodes(head));
                break;
            case 3:
                insertEnd(&head);
                break;
            case 4:
                deleteEnd(&head);
                break;
            case 5:
                insertFront(&head);
                break;
            case 6:
                deleteFront(&head);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void createFront(Student** head, int n) {
    for (int i = 0; i < n; i++) {
        Student* new_student = (Student*)malloc(sizeof(Student));
        printf("Enter USN: ");
        scanf("%s", new_student->USN);
        printf("Enter Name: ");
        scanf("%s", new_student->Name);
        printf("Enter Semester: ");
        scanf("%d", &new_student->Sem);
        printf("Enter Phone Number: ");
        scanf("%s", new_student->PhNo);
        new_student->link = *head;
        *head = new_student;
    }
}

void displayList(Student* head) {
    Student* temp = head;
    while (temp != NULL) {
        printf("USN: %s, Name: %s, Semester: %d, Phone Number: %s\n",
               temp->USN, temp->Name, temp->Sem, temp->PhNo);
        temp = temp->link;
    }
}

int countNodes(Student* head) {
    int count = 0;
    Student* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->link;
    }
    return count;
}

void insertEnd(Student** head) {
    Student* new_student = (Student*)malloc(sizeof(Student));
    printf("Enter USN: ");
    scanf("%s", new_student->USN);
    printf("Enter Name: ");
    scanf("%s", new_student->Name);
    printf("Enter Semester: ");
    scanf("%d", &new_student->Sem);
    printf("Enter Phone Number: ");
    scanf("%s", new_student->PhNo);
    new_student->link = NULL;

    if (*head == NULL) {
        *head = new_student;
        return;
    }

    Student* temp = *head;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = new_student;
}

void deleteEnd(Student** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Student* temp = *head;
    Student* prev = NULL;

    if (temp->link == NULL) {
        *head = NULL;
        free(temp);
        return;
    }

    while (temp->link != NULL) {
        prev = temp;
        temp = temp->link;
    }
    prev->link = NULL;
    free(temp);
}

void insertFront(Student** head) {
    Student* new_student = (Student*)malloc(sizeof(Student));
    printf("Enter USN: ");
    scanf("%s", new_student->USN);
    printf("Enter Name: ");
    scanf("%s", new_student->Name);
    printf("Enter Semester: ");
    scanf("%d", &new_student->Sem);
    printf("Enter Phone Number: ");
    scanf("%s", new_student->PhNo);
    new_student->link = *head;
    *head = new_student;
}

void deleteFront(Student** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Student* temp = *head;
    *head = temp->link;
    free(temp);
}
