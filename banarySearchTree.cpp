#include <iostream>

#include <map>
#include <string.h>

using namespace std;


int size = 1;
struct Node
{
    Node * left = NULL;
    Node * right = NULL;
    int val;

    Node(){}
    Node(int val) : val(val) {}
};

Node * createNode(int data)
{
    Node *node = new Node(data);
    return node;
}

// tao node

struct Root
{
    Node * node;
    Root(int data)
    {
        this->node = createNode(data);
    }
};

// them node vao cay nhi phan(banary search tree)
void insert(Root & root, int data)
{
    Node * nodeAdd = createNode(data);
    //cout << nodeAdd->val << " ";
    //con tro duong di
    Node * path = root.node;
    while(true)
    {
        if(path->val < data)
        {
            if(!path->right)
            {
                path->right = nodeAdd;
                //cout << "them thanh cong" << endl;
                ++size;
                return;
            }
            else path = path->right;
        }
        else if(path->val > data){
            if(!path->left)
            {
                path->left = nodeAdd;
                //cout << "them thanh cong" << endl;
                ++size;
                return;
            }
            else path = path->left;
        }
        else break;
    }
}   

// print BST
void dfs_print(Node * path, map<string, int> & check)
{
    check[to_string(int(path))] = 1;
    cout << path->val << " ";
    if(check[to_string(int(path->left))] != 1 && path->left) dfs_print(path->left, check);
    if(check[to_string(int(path->right))] != 1 && path->right) dfs_print(path->right, check);
}

void print(Root root)
{
    map<string, int> check;
    dfs_print(root.node, check);
}


// find node
Node * find(Root root, int data)
{
    Node * current = root.node;
    while(current)
    {
        if(current->val == data) return current;
        else if(current->val > data) current = current->left;
        else current = current->right;
    }
    cout << "Not found!";
    return NULL;
}

// remove node
void remove(Root & root, int data)
{
    Node * nodeRemove = find(root, data);
    if(!nodeRemove) return;
    if(nodeRemove->left == NULL) // node khong co nhanh trai
    {
        //xoa node la
        /*node la khong co node con nen chi can xoa no bang cach 
         cho thang cha thay vi tro den no thi cho ve NULL va delete no*/
        if(nodeRemove->right == NULL)
        {
            Node * faNodeCurrent = root.node;
            Node * current = root.node;
            while(current)
            {
                if(current->val == data) break;
                faNodeCurrent = current;
                if(current->val > data) current = current->left;
                else current = current->right;
                
            }
            if(data > faNodeCurrent->val) faNodeCurrent->right = NULL;
            else faNodeCurrent->left = NULL;
            delete nodeRemove;
        }
        else // xoa node cha chi co nhanh ben phai
        {
            /*lay node con nho nhat cua thang con o ben cua node cha*/
        Node * faNodeCurrent = nodeRemove;
        Node * current = nodeRemove->right;
        while(current->left)
        {
            faNodeCurrent = current;
            current = current->left;
        }
        if(nodeRemove->val == faNodeCurrent->val) nodeRemove->right = current->right;
        else faNodeCurrent->left = NULL;
        nodeRemove->val = current->val;
        delete current;
        }
    }
    else // node co nhanh trai
    {
        Node * faNodeCurrent = nodeRemove;
        Node * current = nodeRemove->left;
        while(current->right)
        {
            faNodeCurrent = current;
            current = current->right;
        }
        if(nodeRemove->val == faNodeCurrent->val) nodeRemove->left = current->left;
        else faNodeCurrent->right = NULL;
        nodeRemove->val = current->val;
        delete current;
    }
}