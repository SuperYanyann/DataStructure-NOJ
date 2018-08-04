/*
#include <iostream>
#include <vector>

using namespace std;

struct listNode
{
    char data;
    int freq;
    int no;
    listNode* pre;
    listNode* next;
};

void creatList(listNode* list , int len)
{
    listNode* tempNode1 = new listNode;
    tempNode1 = list;
    int num = 0;


    for (int i = 0; i<len; i++)
    {
        listNode* newNode = new listNode;
        newNode->freq = 0;
        newNode->no = ++num;
        cin >> newNode->data;
        newNode->pre = tempNode1;
        tempNode1->next = newNode;
        tempNode1 = tempNode1->next;
    }

}

void creatVec(char* aimSet,int len)
{
    for(int i =0;i<len;i++)
        cin >> aimSet[i];
}

// my method
void Locate(listNode* list, char aim,int len)
{
    listNode* tempNode = new listNode;
    listNode*tempNode2 = new listNode;
    listNode*tempNode3 = new listNode;
    tempNode = list;
    char temp1;
    int temp2;
    int temp3;

    for (int i =0;i<len;i++)
    {
        tempNode = tempNode->next;
        if ( aim == tempNode->data)
            {
               tempNode->freq ++;
               tempNode2 = tempNode;

               for (tempNode2;tempNode2->pre->data!=NULL;tempNode2 = tempNode2->pre)
               {
               if (tempNode2->freq  > tempNode2->pre->freq)
               {
                tempNode3 = tempNode2->pre;
                temp1 = tempNode3->data;
                temp2 = tempNode3->freq;
                temp3 = tempNode3->no;
                tempNode3->data = tempNode2->data;
                tempNode3->freq = tempNode2->freq;
                tempNode3->no = tempNode2->no;
                tempNode2->data = temp1;
                tempNode2->freq = temp2;
                tempNode2->no = temp3;

              }
              if ((tempNode2->freq == tempNode2->pre->freq) && (tempNode2->no < tempNode2->pre->no))
              {
                tempNode3 = tempNode2->pre;
                temp1 = tempNode3->data;
                temp2 = tempNode3->freq;
                temp3 = tempNode3->no;
                tempNode3->data = tempNode2->data;
                tempNode3->freq = tempNode2->freq;
                tempNode3->no = tempNode2->no;
                tempNode2->data = temp1;
                tempNode2->freq = temp2;
                tempNode2->no = temp3;
              }
               }
            }

    }

}

// YanWemin's method from book
int Locate2(listNode* list,char aim)
{
    listNode* p = new listNode;
    listNode* q = new listNode;
    p = list;
    if (list == NULL)
        return 0;
    while (p->data != aim && p->next != NULL)
        p = p->next;

    if (p->data != aim)
        return 0;

    p->freq++;
    q = p->pre;
    while (q->data!= NULL && q->freq <= p->freq)
        q = q->pre;
    if (q->data == NULL && q->freq <= p->freq)
    {
        p->pre->next = p->next;
        p->next->pre = p->pre;
        p->next = list->next;
        p->pre = list;
        list->next = p;
    }
    else if (q!= p->pre)
    {
        p->pre->next = p->next;
        p->next->pre = p->pre;
    }

    return 1;

}

void sortList(listNode* list)
{
    listNode* loop1 = new listNode;
    listNode* loop2 = new listNode;
    char temp1;
    int temp2;

    loop1 = list;
    loop1 = loop1->next;

    for (loop1 ; loop1 != NULL ; loop1 = loop1->next)
        for (loop2 = loop1->next ; loop2 != NULL ; loop2 = loop2->next)
        if (loop1->freq < loop2->freq)
        {
            temp1 = loop1->data;
            temp2 = loop1->freq;
            loop1->data = loop2->data;
            loop1->freq = loop2->freq;
            loop2->data = temp1;
            loop2->freq = temp2;
        }
}

void printList(listNode* list , int len)
{
    listNode* tempNode = new listNode;
    tempNode = list;
    for(int i =1;i<len;i++)
    {
        tempNode = tempNode->next;
        cout << tempNode->data << " ";
    }
    tempNode = tempNode->next;
    cout << tempNode->data;
}

int main()
{
    int lenList = 0;
    int lenLocate = 0;
    listNode* head = new listNode;
    char locSet[100000];
    int result = 0;

    cin >> lenList;
    cin >> lenLocate;
    creatList(head,lenList);
    creatVec(locSet,lenLocate);

    for (int i =0;i<lenLocate;i++)
        Locate(head,locSet[i],lenList);

    printList(head,lenList);


    return 0;
}
*/
// 我先用链表实现了一遍算法，在CB上测试正常，但是评阅一直判WA
// 然后我又用连续表实现了一遍相同的算法，就AC了
// 上面注释掉的是我的链表实现方法，因为Noj没有不通过的测试点提示
// 所以不知道自己错在哪个测试点上了，就先用连续表的版本提交了一份
// 如果您有时间，您可以帮我检查下链表实现为什么错误吗？谢谢！
#include <iostream>

using namespace std;

int main()
{
    int lenList = 0;
    int lenLoc = 0;
    char loopList[3][10000];
    char findList[10000];
    char temp[3];

    cin >> lenList;
    cin >> lenLoc;
    for (int i =0 ;i<lenList;i++)
    {
        cin >> loopList[0][i];
        loopList[2][i] = i+1;
    }
    for (int j =0 ;j<lenLoc;j++)
        cin >> findList[j];


    for (int m = 0;m<lenLoc;m++)
    {
        for (int n = 0;n<lenList;n++)
        {
            if (findList[m] == loopList[0][n])
            {
                loopList[1][n]++;

                for (int h = n;h>=1;h--)
                {
                    if ( loopList[1][h] > loopList[1][h-1])
                    {
                        temp[0] = loopList[0][h];
                        temp[1] = loopList[1][h];
                        temp[2] = loopList[2][h];
                        loopList[0][h] = loopList[0][h-1];
                        loopList[1][h] = loopList[1][h-1];
                        loopList[2][h] = loopList[2][h-1];
                        loopList[0][h-1] = temp[0];
                        loopList[1][h-1] = temp[1];
                        loopList[2][h-1] = temp[2];
                    }
                    else if ((loopList[1][h] == loopList[1][h-1]) &&
                             (loopList[2][h] < loopList[2][h-1]))
                     {
                        temp[0] = loopList[0][h];
                        temp[1] = loopList[1][h];
                        temp[2] = loopList[2][h];
                        loopList[0][h] = loopList[0][h-1];
                        loopList[1][h] = loopList[1][h-1];
                        loopList[2][h] = loopList[2][h-1];
                        loopList[0][h-1] = temp[0];
                        loopList[1][h-1] = temp[1];
                        loopList[2][h-1] = temp[2];
                    }
                }

            }
        }
    }

    for (int k = 0;k<lenList-1;k++)
        cout << loopList[0][k] << " ";
    cout << loopList[0][lenList-1];

    return 0;
}
