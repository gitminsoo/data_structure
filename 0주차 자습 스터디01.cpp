// 링크드리스트 기초

/* #include <stdio.h>             //링크드 리스트 기초 
#include <stdlib.h> // 이거는 malloc
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
    else // 지금 너가 해야할것은 첫번째 노드가 두번째 노드를 가리키게 하는것.
    {
        Node* Temp = Head; // 3. 3 -> 4 -> 5 -> ... -> 10 -> (NewNode)

        while (Temp->NextNode != NULL) // Temp->NextNode == NULL 이면 끝.
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


