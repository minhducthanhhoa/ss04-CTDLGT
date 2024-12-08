#include<stdio.h>
#include <stdlib.h>
#include <time.h>

// �inh nghia cau tr�c cua mot n�t trong danh s�ch li�n ket
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// H�m tao danh s�ch li�n ket voi n phan tu
Node* createList(int n) {
    if (n == 0) return NULL;  // Truong hop danh s�ch trung

    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));  // Cap ph�t bo nho cho n�t moi
        if (newNode == NULL) {
            printf("Ph�n bo bo nho kh�ng th�nh c�ng!\n");
            return NULL;
        }

        // Sinh gi� tri ngau nhi�n tu 1 den 100
        newNode->data = rand() % 100 + 1; 
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;  // Neu l� n�t dau ti�n, head tro den n�t n�y
        } else {
            tail->next = newNode;  // Th�m v�o cuoi danh s�ch
        }

        tail = newNode;  // Cap nhat n�t cuoi c�ng
    }

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

// H�m giai ph�ng bo nho d� cap ph�t cho danh s�ch
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);  // Giai ph�ng bo nho
    }
}

int main(){
	srand(time(NULL));  // Khoi tao bo sinh so ngau nhi�n

    int n;
    printf("So luong phan tu: ");
    scanf("%d", &n);

    // Tao danh s�ch li�n ket
    Node* list = createList(n);

    // In danh s�ch
    printList(list);

    // Giai ph�ng bo nho
    freeList(list);
	return 0;
}

