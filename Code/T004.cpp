#include <iostream>

using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

void creatList(ListNode* head,int len)
{
    ListNode* p = head;
    for (int i = 1;i<=len;i++)
    {
        ListNode* newNode = new ListNode;
        cin >> newNode->data;
        newNode->next = p->next;
        p->next = newNode;
    }

}

void combine(ListNode* listA,ListNode* listB,ListNode* listC,int lenA,int lenB)
{
    int sumLen = lenA + lenB;
    ListNode* tempA = new ListNode;
    ListNode* tempB = new ListNode;
    ListNode* tempC = new ListNode;
    tempA = listA->next;
    tempB = listB->next;
    tempC = listC;

    for (int i = 1;i<=sumLen;i++)
    {
        if (tempA &&  tempB)
        {
            if (tempA->data > tempB->data)
            {
                tempC->next = tempA;
                tempC = tempC->next;
                tempA = tempA->next;
            }
            else
            {
                tempC->next = tempB;
                tempC = tempC->next;
                tempB = tempB->next;
            }
        }

        else if (tempB)
        {
            tempC->next = tempB;
        }

        else if (tempA)
        {
            tempC->next = tempA;
        }

    }

}

int main()
{
   int lenList1 = 0;
   int lenList2 = 0;
   cin >> lenList1;
   cin >> lenList2;

   ListNode* list1 = new ListNode;
   ListNode* list2 = new ListNode;
   ListNode* list3 = new ListNode;
   creatList(list1,lenList1);
   creatList(list2,lenList2);

   combine(list1,list2,list3,lenList1,lenList2);

   for (int i =0;i< lenList1+lenList2-1;i++)
   {
       list3 = list3->next;
       cout << list3->data << " ";
   }
   list3 = list3->next;
   cout << list3->data << endl;

   return 0;

}