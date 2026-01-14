#include"LinkedList.hpp"
#include<iostream>
void LinkedList::addHead(LinkedNode node)
{
    if(!node || initFirstNode(node)) return;
    node->next = this->head;
    this->head = node;
}
void LinkedList::addTail(LinkedNode node)
{
    if(!node || initFirstNode(node)) return;
    this->tail = this->tail->next = node;
}

int LinkedList::searchNode(LinkedNode node)
{
    if(!node) return -1;
    LinkedNode temp = this->head;
    int index = 0;
    while(temp && node != temp){temp=temp->next; index++;}
    return (temp)?index:-1;
}
int LinkedList::deleteFinalyNode()
{
    if(!isOnlyOneNode()) return 0;
    delete this->head;
    this->head = this->tail = nullptr;
    return 1;
}
void LinkedList::deleteHead()
{
    if(isEmpty() || deleteFinalyNode()) return;
    LinkedNode tempNode;
    this->head = this->head->next;
    delete tempNode;
}
void LinkedList::deleteTail()
{
    if(isEmpty() || deleteFinalyNode()) return;
    LinkedNode preTail = this->head;
    while(preTail->next != tail) preTail = preTail->next;
    delete this->tail;
    this->tail = preTail;
}
/*
con tro truyen vao phai la con tro cua Node truoc!!!
node bat buoc phai la mot node trong linkedlist!!!
*/
int LinkedList::deleteNode(LinkedNode *node)
{
    if(!*node) return 0;
    if(*node == this->head) {deleteHead(); return 1;}
    if(*node == this->tail) {deleteTail(); return 1;}
    LinkedNode tempNode;
    tempNode = *node;
    *node = (*node)->next;
    delete tempNode;
    return 1;
}
int LinkedList::addAfter(LinkedNode node, int data)
{
    if(node) return 0;
    LinkedNode n_node = createNode(data);
    if(!n_node) return 0;
    if(node == tail) {addTail(n_node);return 1;}
    n_node->next = node->next;
    node->next = n_node;
    return 1;
}
int LinkedList::initFirstNode(LinkedNode node)
{
    if(!isEmpty()) return 0;
    this->head = this->tail = node;
    return 1;
}
int LinkedList::isEmpty() {return this->head == nullptr;}
int LinkedList::isOnlyOneNode() {return (!isEmpty() && this->head == this->tail);}
void LinkedList::addHead(int data) {addHead(createNode(data));}
void LinkedList::addTail(int data) {addTail(createNode(data));}
int LinkedList::searchNode(int value)
{
    LinkedNode curNode = this->head;
    for(int i = 0; curNode; curNode = curNode->next, i++)
        if(curNode->data == value) return i;
    return -1;
}
void LinkedList::searchAndDeleteNode(int value)
{
    LinkedNode *curNode = &(this->head);
    while(*curNode && (*curNode)->data != value) curNode = &((*curNode)->next);
    deleteNode(curNode);
}
void LinkedList::deleteNode(int value)
{
    if(value < 0) return;
    LinkedNode *curNode = &(this->head);
    for(int i = 0; *curNode && i < value; curNode = &(*curNode)->next, i++);
    deleteNode(curNode);
}
void printList(const LinkedList &l)
{
    LinkedList::LinkedNode CurNode = l.head;
    while(CurNode)
    {
        std::cout << CurNode->data << " ";
        CurNode = CurNode->next;
    }
    std::cout << "\n";
}
void insertList(LinkedList& l)
{
    int n, x;
    std::cout << "Enter the lenght of List: ";
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> x;
        l.addTail(x);
    }
}
