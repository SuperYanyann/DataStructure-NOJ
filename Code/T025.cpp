    #include<stdio.h>  
    #include<stdlib.h>  
      
    typedef struct BinNode{  
        int data;  
        struct BinNode *lchild;  
        struct BinNode *rchild;  
    }BinNode,*BinTree;  
      
    void CreateBinTree(BinTree *tree)  
    {  
        int ch;  
        scanf("%d",&ch);  
      
        if(ch == -1)  
        {  
            (*tree) = NULL;  
        }  
        else  
        {  
            *tree = (BinTree)malloc(sizeof(BinNode));  
            (*tree)->data = ch;  
            CreateBinTree(&((*tree)->lchild));  
            CreateBinTree(&((*tree)->rchild));  
        }  
    }  
      
    void Search(BinTree T,int m,int n)  
    {  
        if(T)  
        {  
            Search(T->lchild,m,n);  
            if(T->data > m&& T->data < n)printf("%d ",T->data);  
            Search(T->rchild,m,n);  
        }  
    }  
      
    void Inorder(BinTree T)  
    {  
        if(T)  
        {  
            Inorder(T->lchild);  
            printf("%d ",T->data);  
            Inorder(T->rchild);  
        }  
    }  
    void Insert(BinTree *T,int key)  
    {  
        if(!(*T))  
        {  
            (*T) = (BinTree)malloc(sizeof(BinNode));  
            (*T)->data = key;  
            (*T)->lchild = (*T)->rchild = NULL;  
            return;  
        }  
        if(key == (*T)->data )  
            return;  
        if(key > (*T)->data )  
            Insert( &((*T)->rchild), key );  
        else  
            Insert( &((*T)->lchild), key );  
    }  
      
    bool Delete(BinTree *T)  
    {  
        BinTree L;  
        if (!(*T)->lchild && !(*T)->rchild)  
            *T = NULL;  
        else if (!(*T)->lchild)  
            *T = (*T)->rchild;  
        else if (!(*T)->rchild)  
            *T = (*T)->lchild;  
        else  
        {  
            L = (*T)->lchild;  
            while (L->rchild)  
                L = L->rchild;  
            L->rchild = (*T)->rchild;  
            *T = (*T)->lchild;  
        }  
        return true;  
    }  
    bool DeleteBST(BinTree *T, int key)  
    {  
        if (!*T)  
            return false;  
        else if (key == (*T)->data)  
        {  
            Delete(T);  
            return true;  
        }  
        else if (key < (*T)->data)  
        {  
            return DeleteBST(&((*T)->lchild), key);  
        }  
        else  
        {  
            return DeleteBST(&((*T)->rchild), key);  
        }  
    }  
      
    int main(){  
        BinTree T = NULL;  
        CreateBinTree(&T);  
        int m,n,w,k;  
        scanf("%d %d",&m,&n);  
        scanf("%d",&w);  
        scanf("%d",&k);  
        Search(T,m,n);  
        printf("\n");  
        Insert(&T,w);  
        Inorder(T);  
        printf("\n");  
        DeleteBST(&T,w);  
        DeleteBST(&T,k);  
        Inorder(T);  
        printf("\n");  
        return 0;  
    }  