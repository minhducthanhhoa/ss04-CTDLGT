#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Loi cap phát bo nho\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Hàm chèn mot nút vào vi trí xác dinh
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);

    // Neu chèn o dau danh sách
    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Tim nút ngay truoc vi trí chèn
    struct Node* temp = *head;
    for (int i = 0; i < position - 1; i++) {
        if (temp == NULL) { // N?u v? trí vý?t quá danh sách
            printf("Vi trí nam ngoài pham vi danh sách\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }

    // Chèn nút vào vi trí xác ð?nh
    newNode->next = temp->next;
    temp->next = newNode;
}

// Hàm hien thi danh sách liên ket
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

    // Tao danh sách liên ket: 10 -> 20 -> 30
    head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);

    printf("Danh sách ban dau: ");
    printList(head);

    // Chèn giá tri 25 vào vi trí 2
    insertAtPosition(&head, 25, 2);
    printf("Danh sách sau khi chèn 25 o vi trí 2: ");
    printList(head);

    // Chèn giá tri 5 vào vi trí 0
    insertAtPosition(&head, 5, 0);
    printf("Danh sách sau khi chèn 5 o vi trí 0: ");
    printList(head);

    return 0;
}

