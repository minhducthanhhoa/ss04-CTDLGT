#include<stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Hàm tao danh sách liên ket voi n phan tu
Node* createList(int n) {
    if (n == 0) return NULL;  

    Node* head = NULL;

    for (int i = 0; i < n; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));  
        if (newNode == NULL) {
            printf("Phân bo bo nho không thành công!\n");
            return NULL;
        }

        scanf("%d", &newNode->data);  
        newNode->next = head;  
        head = newNode;  
    }

    return head;
}

// Hàm xóa phan tu dau danh sách
Node* deleteHead(Node* head) {
    if (head == NULL) {
        printf("Danh sách trong\n");
        return NULL;
    }

    Node* temp = head;
    head = head->next; 
    free(temp);  

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
	int n;

    printf("Nhap so luong phan tu n: ");
    scanf("%d", &n);

    Node* list = createList(n);  

    // Xóa phan tu dau tiên
    list = deleteHead(list);  

    // In danh sách sau khi xóa phan tu dau
    printList(list);
	return 0;
}

