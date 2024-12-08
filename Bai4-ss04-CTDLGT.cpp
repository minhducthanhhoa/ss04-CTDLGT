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
            printf("Ph�n bo bo nho kh�ng th�nh c�ng!\n");
            return NULL;
        }

        printf("Nhap gi� tri phan tu %d: ", i + 1);
        scanf("%d", &newNode->data);  
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;  // Neu l� n�t dau ti�n, g�n head
        } else {
            tail->next = newNode;  // Noi n�t moi v�o cuoi danh s�ch
        }

        tail = newNode;  // Cap nhat tail
    }

    return head;
}

// H�m tim kiem phan tu trong danh s�ch li�n ket
int searchInList(Node* head, int target) {
    int index = 0;
    Node* current = head;

    while (current != NULL) {
        if (current->data == target) {
            return index;  // Tra ve vi tr� neu tim thay
        }
        current = current->next;
        index++;
    }

    return -1;  // Tra ve -1 neu kh�ng tim thay
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
	int n, searchValue;

    printf("Nhap so luong phan tu n: ");
    scanf("%d", &n);

    Node* list = createList(n);  // Tao danh s�ch voi n ph?n t?

    // In danh s�ch
    printf("Danh s�ch li�n ket: ");
    printList(list);

    printf("Nhap gi� tri can t�m ki?m: ");
    scanf("%d", &searchValue);

    // T�m kiem gi� tri trong danh s�ch
    int result = searchInList(list, searchValue);

    // In ket qua
    if (result != -1) {
        printf("Gi� tri %d duoc t�m thay tai vi tr� %d\n", searchValue, result);
    } else {
        printf("Gi� tri %d kh�ng ton tai trong danh s�ch\n", searchValue);
    }

	return 0;
}

