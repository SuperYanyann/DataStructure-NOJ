    #include<stdio.h>  
    #include<stdlib.h>  
      
    typedef struct BinNode  
    {  
        int data;  
        struct BinNode *lchild;  
        struct BinNode *rchild;  
    }BinNode,*BinTree;  
      
    void CreateBinTree(BinNode *tree)  
    {  
        int ch;  
        scanf("%d",&ch);  
        if(ch == -1)  
        {  
            tree = NULL;  
        }  
        else  
        {  
            tree = (BinTree)malloc(sizeof(BinNode));  
            tree->data = ch;  
            CreateBinTree(tree->lchild);  
            CreateBinTree(tree->rchild);  
        }  
    }  
      
    int judge(BinNode *t)  
    {  
        if(!t)  
            return 1;  
        else if(!(t->lchild) && !(t->rchild))  
            return 1;  
        else if((t->lchild) && !(t->rchild))  
        {  
            if(t->lchild->data>t->data)  
                return 0;  
            else  
                return judge(t->lchild);  
        }  
        else if((t->rchild) && !(t->lchild))  
        {  
            if(t->rchild->data<t->data)  
                return 0;  
            else  
                return judge(t->rchild);  
        }  
        else  
        {  
            if((t->lchild->data>t->data) || (t->rchild->data<t->data))  
                return 0;  
            else  
                return ( judge(t->lchild) && judge(t->rchild) );  
        }  
    }  
      
    int main()  
    {  
        BinNode *T = NULL;  
        CreateBinTree(T);  
        int flag=judge(T);  
        if(flag)printf("yes\n");  
        else printf("no\n");  
        return 0;  
    }  