#include<stdio.h>
#include <stdlib.h>

// Ðinh nghia cau trúc cua mot nút trong danh sách liên ket
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Hàm tao danh sách liên ket voi n phan tu
Node* createList(int n) {
    if (n == 0) return NULL;  // Truong hop danh sách trong

    Node* head = NULL;

    // Nhap các phan tu cho danh sách
    for (int i = 0; i < n; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));  // Cap phát bo nho cho nút moi
        if (newNode == NULL) {
            printf("Phân bo bo nho không thành công!\n");
            return NULL;
        }
        
        scanf("%d", &newNode->data);  // Nhap giá tri cho phan tu
        newNode->next = head;  // Chèn nút vào dau danh sách
        head = newNode;  // Cap nhat head tro den nut moi
    }

    return head;
}

// Hàm thêm mot phan tu vào dau danh sách liên ket
Node* insertAtHead(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // Cap phát bo nho cho nút moi
    if (newNode == NULL) {
        printf("Phân bo bo nho không thành công!\n");
        return head;
    }

    newNode->data = value;  // Gán giá tri cho phan tu
    newNode->next = head;  // Con tro next cua nút moi tro den head cu
    head = newNode;  // Cap nhat head tro den nút moi

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

int main(){
	int n, value;
    
    printf("Nhap so luong phan tu n: ");
    scanf("%d", &n);

    Node* list = createList(n);  // Tao danh sách voi n phan tu

    printf("Giá tri chèn vào dau danh sách: ");
    scanf("%d", &value);

    list = insertAtHead(list, value);  // Thêm phan tu vào dau danh sách

    printList(list);

	return 0;
}

