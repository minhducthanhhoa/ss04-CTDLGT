#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Loi cap ph�t bo nho\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// H�m ch�n mot n�t v�o vi tr� x�c dinh
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);

    // Neu ch�n o dau danh s�ch
    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Tim n�t ngay truoc vi tr� ch�n
    struct Node* temp = *head;
    for (int i = 0; i < position - 1; i++) {
        if (temp == NULL) { // N?u v? tr� v�?t qu� danh s�ch
            printf("Vi tr� nam ngo�i pham vi danh s�ch\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }

    // Ch�n n�t v�o vi tr� x�c �?nh
    newNode->next = temp->next;
    temp->next = newNode;
}

// H�m hien thi danh s�ch li�n ket
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) {
            printf(" -> ");
        }
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Tao danh s�ch li�n ket: 10 -> 20 -> 30
    head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);

    printf("Danh s�ch ban dau: ");
    printList(head);

    // Ch�n gi� tri 25 v�o vi tr� 2
    insertAtPosition(&head, 25, 2);
    printf("Danh s�ch sau khi ch�n 25 o vi tr� 2: ");
    printList(head);

    // Ch�n gi� tri 5 v�o vi tr� 0
    insertAtPosition(&head, 5, 0);
    printf("Danh s�ch sau khi ch�n 5 o vi tr� 0: ");
    printList(head);

    return 0;
}

