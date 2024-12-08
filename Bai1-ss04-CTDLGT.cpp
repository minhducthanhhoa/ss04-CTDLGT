#include<stdio.h>
#include <stdlib.h>
#include <time.h>

// Ðinh nghia cau trúc cua mot nút trong danh sách liên ket
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Hàm tao danh sách liên ket voi n phan tu
Node* createList(int n) {
    if (n == 0) return NULL;  // Truong hop danh sách trung

    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));  // Cap phát bo nho cho nút moi
        if (newNode == NULL) {
            printf("Phân bo bo nho không thành công!\n");
            return NULL;
        }

        // Sinh giá tri ngau nhiên tu 1 den 100
        newNode->data = rand() % 100 + 1; 
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;  // Neu là nút dau tiên, head tro den nút này
        } else {
            tail->next = newNode;  // Thêm vào cuoi danh sách
        }

        tail = newNode;  // Cap nhat nút cuoi cùng
    }

    return head;
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

// Hàm giai phóng bo nho dã cap phát cho danh sách
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);  // Giai phóng bo nho
    }
}

int main(){
	srand(time(NULL));  // Khoi tao bo sinh so ngau nhiên

    int n;
    printf("So luong phan tu: ");
    scanf("%d", &n);

    // Tao danh sách liên ket
    Node* list = createList(n);

    // In danh sách
    printList(list);

    // Giai phóng bo nho
    freeList(list);
	return 0;
}

