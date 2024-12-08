#include<stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// H�m tao danh s�ch li�n ket voi n phan tu
Node* createList(int n) {
    if (n == 0) return NULL;  

    Node* head = NULL;

    for (int i = 0; i < n; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));  
        if (newNode == NULL) {
            printf("Ph�n bo bo nho kh�ng th�nh c�ng!\n");
            return NULL;
        }

        scanf("%d", &newNode->data);  
        newNode->next = head;  
        head = newNode;  
    }

    return head;
}

// H�m x�a phan tu dau danh s�ch
Node* deleteHead(Node* head) {
    if (head == NULL) {
        printf("Danh s�ch trong\n");
        return NULL;
    }

    Node* temp = head;
    head = head->next; 
    free(temp);  

    return head;
}

// H�m in danh s�ch li�n ket
void printList(Node* head) {
    if (head == NULL) {
        printf("Danh s�ch trong\n");
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

    // X�a phan tu dau ti�n
    list = deleteHead(list);  

    // In danh s�ch sau khi x�a phan tu dau
    printList(list);
	return 0;
}

