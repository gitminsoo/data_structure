// ��ũ�帮��Ʈ ����

/* #include <stdio.h>             //��ũ�� ����Ʈ ���� 
#include <stdlib.h> // �̰Ŵ� malloc
#pragma warning (disable: 4996)

typedef struct tagNode {
    int Data;
    struct tagNode* NextNode;
} Node;

Node* Head = NULL;

void Create_Node(int Data)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->Data = Data;
    NewNode->NextNode = NULL;

    if (Head == NULL)
    {
        Head = NewNode;
    }
    else // ���� �ʰ� �ؾ��Ұ��� ù��° ��尡 �ι�° ��带 ����Ű�� �ϴ°�.
    {
        Node* Temp = Head; // 3. 3 -> 4 -> 5 -> ... -> 10 -> (NewNode)

        while (Temp->NextNode != NULL) // Temp->NextNode == NULL �̸� ��.
        {
            Temp = Temp->NextNode;
        }

        Temp->NextNode = NewNode;
    }
}

void Print()
{
    Node* Temp = Head;

    while (Temp != NULL)
    {
        printf("%d\n", Temp->Data);
        Temp = Temp->NextNode;
    }
}

// Head -> Node(1) -> NULL

int main(void)
{
    int n;

    scanf("%d\n", &n);
    int Data;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &Data);
        Create_Node(Data);
    }

    Print();

    return 0;
}   */


