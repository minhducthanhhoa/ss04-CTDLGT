#include<stdio.h>
#include <stdlib.h>

// �inh nghia cau tr�c cua mot n�t trong danh s�ch li�n ket
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// H�m tao danh s�ch li�n ket voi n phan tu
Node* createList(int n) {
    if (n == 0) return NULL;  // Truong hop danh s�ch trong

    Node* head = NULL;

    // Nhap c�c phan tu cho danh s�ch
    for (int i = 0; i < n; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));  // Cap ph�t bo nho cho n�t moi
        if (newNode == NULL) {
            printf("Ph�n bo bo nho kh�ng th�nh c�ng!\n");
            return NULL;
        }
        
        scanf("%d", &newNode->data);  // Nhap gi� tri cho phan tu
        newNode->next = head;  // Ch�n n�t v�o dau danh s�ch
        head = newNode;  // Cap nhat head tro den nut moi
    }

    return head;
}

// H�m th�m mot phan tu v�o dau danh s�ch li�n ket
Node* insertAtHead(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // Cap ph�t bo nho cho n�t moi
    if (newNode == NULL) {
        printf("Ph�n bo bo nho kh�ng th�nh c�ng!\n");
        return head;
    }

    newNode->data = value;  // G�n gi� tri cho phan tu
    newNode->next = head;  // Con tro next cua n�t moi tro den head cu
    head = newNode;  // Cap nhat head tro den n�t moi

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
	int n, value;
    
    printf("Nhap so luong phan tu n: ");
    scanf("%d", &n);

    Node* list = createList(n);  // Tao danh s�ch voi n phan tu

    printf("Gi� tri ch�n v�o dau danh s�ch: ");
    scanf("%d", &value);

    list = insertAtHead(list, value);  // Th�m phan tu v�o dau danh s�ch

    printList(list);

	return 0;
}

