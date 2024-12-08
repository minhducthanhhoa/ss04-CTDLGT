#include<stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createList(int n) {
    if (n == 0) return NULL;  

    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));  
        if (newNode == NULL) {
            printf("Phân bo bo nho không thành công!\n");
            return NULL;
        }

        printf("Nhap giá tri phan tu %d: ", i + 1);
        scanf("%d", &newNode->data);  
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;  // Neu là nút dau tiên, gán head
        } else {
            tail->next = newNode;  // Noi nút moi vào cuoi danh sách
        }

        tail = newNode;  // Cap nhat tail
    }

    return head;
}

// Hàm tim kiem phan tu trong danh sách liên ket
int searchInList(Node* head, int target) {
    int index = 0;
    Node* current = head;

    while (current != NULL) {
        if (current->data == target) {
            return index;  // Tra ve vi trí neu tim thay
        }
        current = current->next;
        index++;
    }

    return -1;  // Tra ve -1 neu không tim thay
}

// Hàm in danh sách liên ket
void printList(Node* head) {
    if (head == NULL) {
        printf("Danh sách trong\n");
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf(" -> NULL\n");
}

int main(){
	int n, searchValue;

    printf("Nhap so luong phan tu n: ");
    scanf("%d", &n);

    Node* list = createList(n);  // Tao danh sách voi n ph?n t?

    // In danh sách
    printf("Danh sách liên ket: ");
    printList(list);

    printf("Nhap giá tri can tìm ki?m: ");
    scanf("%d", &searchValue);

    // Tìm kiem giá tri trong danh sách
    int result = searchInList(list, searchValue);

    // In ket qua
    if (result != -1) {
        printf("Giá tri %d duoc tìm thay tai vi trí %d\n", searchValue, result);
    } else {
        printf("Giá tri %d không ton tai trong danh sách\n", searchValue);
    }

	return 0;
}

