#include<iostream>
using namespace std;

typedef struct BTNode
{
    int data;
    struct BTNode *lchild,*rchild;
}BTNode,*BTree;

void Create_Tree(BTree *T)
{
    int cd;
    cin>>cd;
    if(-1==cd) *T=NULL;
    else 
    {
        (*T)=new BTNode;
        (*T)->data=cd;
        Create_Tree(&(*T)->lchild);
        Create_Tree(&(*T)->rchild);
    }
}

void LDR(BTree T)
{
    if(T)
    {
        LDR(T->lchild);
        cout<<T->data<<" ";
        LDR(T->rchild);
    }
}

void InsertBST(BTree *T,int key)
{
    while((*T)!=NULL)
    {
        if((*T)->data>key)   T=&(*T)->lchild;
        else if((*T)->data<key) T=&(*T)->rchild;
    }

    (*T)=new BTNode;
    (*T)->lchild=NULL;
    (*T)->rchild=NULL;
    (*T)->data=key;
}

void Insert_LDR(BTree T1,BTree T2)
{
    if(T2)
    {
        Insert_LDR(T1,T2->lchild);
        InsertBST(&T1,T2->data);
        Insert_LDR(T1,T2->rchild);
    }
}

int main()
{

    BTree T1,T2;
    Create_Tree(&T1);
    Create_Tree(&T2);
    Insert_LDR(T1,T2);

    LDR(T1);
    cout<<endl;

    return 0;
}