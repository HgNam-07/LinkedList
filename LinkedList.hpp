#ifndef MyLinkedList
#define MyLinkedList
class LinkedList
{
    private:
        typedef struct Node
        {
            int data;
            Node *next;
            Node(int data = 0): data(data), next(nullptr){}
            ~Node(){data = 0; next = nullptr;}
        } *LinkedNode;
        LinkedNode createNode(int data) {return new Node(data);}
        LinkedNode head, tail;
        int initFirstNode(LinkedNode);
        int deleteFinalyNode();
        void deleteHead();
        void deleteTail();
    public:
        LinkedList():head(nullptr), tail(nullptr){};
        ~LinkedList()
        {
            LinkedNode tempNode = nullptr;
            while(head)
            {
                tempNode = head;
                head = head->next;
                delete tempNode;
            }
            this->tail = nullptr;
        }  
        //check
        int isEmpty();
        int isOnlyOneNode(); 

        //add node
        void addHead(LinkedNode);
        void addHead(int);
        void addTail(LinkedNode);
        void addTail(int);
        int addAfter(LinkedNode, int);

        //search
        int searchNode(LinkedNode);
        int searchNode(int);
        void searchAndDeleteNode(int);

        //delete index node
        void deleteNode(int);
        int deleteNode(LinkedNode*);

        //input output
        friend void printList(const LinkedList&);
        friend void insertList(LinkedList&);
};
#endif