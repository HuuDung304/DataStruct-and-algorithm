#include <iostream>

using namespace std;

class LinkList
{
    private: 
        int data;
        LinkList *next;
        LinkList* last;
    public:
        void setData(int data);
        int getData();

        void setNext(LinkList* next);
        LinkList* getNext();

        void setLast(LinkList* last);
        LinkList* getLast();

        void InList(); // tao 1 danh sach
        LinkList* createNode(int data); // tao 1 node trong list

        bool empty(); // kt xem lst co rong hay khong neu rong thi tra ve true
        void push(int data); // them vao dau danh sach
        void push(int data, int index); /*them vao sau vi tri chi dinh
        (vi tri dau tien la 0 va vi tri cuoi la lst.size() - 1)*/
        void print(); // xuat ra danh sach
        int size(); // tra ve kich thuc cua danh sah 

};


void LinkList::setData(int data)
{
    this->data = data;
}

int LinkList::getData()
{
    return data;
}

void LinkList::setLast(LinkList* last)
{
    this->last = last;
}

LinkList* LinkList::getLast()
{
    return last;
}

void LinkList::setNext(LinkList* next)
{
    this->next = next;
}

LinkList* LinkList::getNext()
{
    return next;
}

void LinkList::InList()
{
    this->next = NULL;
}

LinkList* LinkList::createNode(int data)
{
    LinkList *node = new LinkList;
    if(node == NULL) cout << "Khong du bo nho!" << endl;
    else
    {
    node->setData(data);
    node->setNext(NULL);
    node->setLast(NULL);
    }
}

bool LinkList::empty()
{
    if(this->next == NULL) return true;
    return false;
}

void LinkList::push(int data)
{
    LinkList* node = createNode(data);
    if(empty())
    {
        this->next = node;
    }
    else
    {
        node->next = this->next;
        node->last = this->next->last;
        this->next->last = node;
        this->next = node;
    }
}

void LinkList::print()
{
    LinkList* p = this->next;
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != this->next);
   a cout << endl;
}
