#include <iostream>
using namespace std;
struct Node
{
    int val;
    int expo;
    Node *link;
};
Node *CreateNode(int v, int e)
{
    Node *p = new Node;
    p->val = v;
    p->expo = e;
    p->link = NULL;
    return p;
}
struct LinkedList
{
    Node *fisrt;
};
void CreateList(LinkedList &l)
{
    l.fisrt = NULL;
}
void AddLast(LinkedList &l, Node *n)
{
    Node *p = l.fisrt;
    if (l.fisrt == NULL)
    {
        l.fisrt = n;
    }
    else
    {
        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link = n;
    }
}
void FrintList(LinkedList l)
{
    Node *p = l.fisrt;
    if (l.fisrt != NULL)
    {
        while (p != NULL)
        {
            cout << p->val << "^" << p->expo;
            if (p->link == NULL)
            {
                cout << " = 0";
            }
            else
            {
                if (p->val < 0)
                    cout << " ";
                else
                    cout << " + ";
            }
            p = p->link;
        }
    }
    cout << endl;
}
void Add(LinkedList l, LinkedList k)
{
}
int main()
{
    LinkedList l, k;
    CreateList(l);
    CreateList(k);
    int n, x, e;
    Node *node;
    cout << "Enter the first polynomial\n";
    cout << "Enter the number of terms: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the coefficient for term " << i + 1 << " : ";
        cin >> x;
        cout << "Enter the exponent for term " << i + 1 << " : ";
        cin >> e;
        node = CreateNode(x, e);
        AddLast(l, node);
    }
    FrintList(l);
    //
    cout << "Enter the second polynomial\n";
    cout << "Enter the number of terms: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the coefficient for term " << i + 1 << " : ";
        cin >> x;
        cout << "Enter the exponent for term " << i + 1 << " : ";
        cin >> e;
        node = CreateNode(x, e);
        AddLast(k, node);
    }
    FrintList(k);
    return 0;
}