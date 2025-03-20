#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE -1
#define TRUE 1

typedef struct Node {
	int data;
	struct Node* nextNode;
}Node;

typedef struct LinkedList {
	int curCount; //현재 이 List에 들어있는 노드 개수
	Node headNode; //List의 시작 Node (포인터가 아니네?)
}LinkedList;

//typedef가 없으면 struct Node, struct LinkedList로 계속 써야됨
//typedef를 통해 저들을 간단하게 쓸 수 있는 별칭을 만듦
//-> Node, LinkedList

int addNode(LinkedList* pList, int pos, int data);
int removeNode(LinkedList* pList, int pos);
int showNode(LinkedList* pList);
int isEmpty(LinkedList* pList);
int findPos(LinkedList* pList, int data);
void makeEmpty(LinkedList* pList);

int addNode(LinkedList* pList, int pos, int data) 
{
	int i = 0;
    Node* pNewNode = NULL, *pTmpNode = NULL;
    
    if (pList == NULL) {
        printf("addNode() error1: 잘못된 리스트");
        return FALSE;
    }

    pNewNode = (Node*)malloc(sizeof(Node));
    if (!pNewNode) {
        printf("addNode() error3 \n");
        return FALSE;
    }

    pNewNode->data = data;
    pNewNode->nextNode = NULL;

    pTmpNode = &(pList->headNode);
    for (int i = 0; i < pos - 1; i++)
        pTmpNode = pTmpNode->nextNode;

    pNewNode->nextNode = pTmpNode->nextNode;
    pTmpNode->nextNode = pNewNode;

    pList->curCount--;

    return TRUE;
}
	
	
int removeNode(LinkedList* pList, int pos)
{
	int i = 0;
	Node* pDelNode = NULL, *pTmpNode = NULL;
	
	if (pList == NULL) {
		printf("removeNode() error1: 잘못된 리스트\n");
		return FALSE;
	}
	
	if (pos < 0 || pos >= pList->curCount) {
        printf("removeNode() error2: 삭제 범위 초과\n");
        //pos -> (index)0부터 시작, pList->curCount -> (개수)1부터 시작
        return FALSE;
    }
	
	//삭제될 노드 직전 위치로 이동
	pTmpNode = &(pList->headNode);
	for (int i = 0; i < pos - 1; i++) 
		pTmpNode = pTmpNode->nextNode;
		
	//삭제할 노드 = 직전 노드의 nextNode
	//직전 노드의 nextNode = 삭제할 노드의 nextNode
	pDelNode = (pTmpNode->nextNode)->nextNode;
    pTmpNode->nextNode = pDelNode;
    
    //free(pDelNode); 이거 왜함?
    (pList->curCount)--;
    
    return TRUE;
}
	
int showNode(LinkedList* pList)
{
    int i = 0;
    Node *pNode = NULL;
    
    
}
