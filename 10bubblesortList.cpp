#include <iostream>
using namespace std;

class node
{
    int data;
    node *next;
    node(int d) : data(d), next(NULL)
    {
    }
};

node *createLL()
{
    node *head = NULL;
    int d;
    cin >> d;
    while (d != -1)
    {
        node *n = new node(d);
        n->next = head;
        head = n;
        cin >> d;
    }

    return head;
};

int length(node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}
node *bubble_sort_LinkedList_itr(node *head)
{
    int n = len(head) - 1;

    while (n--)

    {
        node *prev = NULL;
        node *cur = head;
        while (cur->next != NULL)
        {
            if (cur->data >= cur->next->data)
            {

                if (prev == NULL)
                {
                    //first node
                    node *nxt = cur->next;
                    cur->next = nxt->next;
                    nxt->next = cur;
                    prev = nxt;
                    head = prev;
                }

                else
                {

                    node *nxt = cur->next;
                    prev->next = nxt;
                    cur->next = nxt->next;
                    nxt->next = cur;
                    prev = nxt;
                }
            }
            else
            {

                prev = cur;
                cur = cur->next;
            }
        }
    }

    return head;
}
void BubbleSort(node *head)
{
    int n = length(head);
    for (int i = 0; i < n - 1; i++)
    {
        node *prev = NULL;
        node *current = head;
        node *n;
        while (current != NULL && current->next != NULL)
        {
            if (current->data > current->next->data)
            {
                if (prev == NULL)
                {
                    n = current->next;
                    current->next = n->next;
                    n->next = current;
                    head = prev = n;
                }
                else
                {
                    n = current->next;
                    prev->next = n;
                    current->next = n->next;
                    n->next = current;
                    prev = n;
                }
            }

            else
            {
                n = current->next;
                prev = current;
                current = n;
            }
        }
    }
}

void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << endl;
}

int main()
{

    return 0;
}