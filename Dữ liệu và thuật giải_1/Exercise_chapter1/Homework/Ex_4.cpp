#include <iostream>
using namespace std;
struct Node
{
    int info;
    Node *link;
};
struct linkedlist
{
    Node *first;
};
void init(linkedlist &l)
{
    l.first = NULL;
}
Node *createnode(int x)
{
    Node *p = new Node;
    p->info = x;
    p->link = NULL;
    return p;
}
void addlast(linkedlist &l, Node *node)
{
    if (l.first == NULL)
    {
        l.first = node;
    }
    else
    {
        Node *p = l.first;
        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link = node;
    }
}
int findelement(linkedlist l, int x)
{
    Node *p = l.first;
    while (p!=NULL)
    {
        if (p->info==x)
        {
            return 0;
        }
        p = p->link;
    }
    return 1;
}
void removeelement(linkedlist &l, int data)
{
    Node *p = new Node;
    if (l.first->info == data)
    {
        Node *rf = l.first;
        l.first = l.first->link;
        delete rf;
    }
    Node *d = l.first;
    Node *ta;
    while (d->link != NULL)
    {
        ta = d;
        d = d->link;
    }
    if (d->info == data)
    {
        ta->link = NULL;
        delete d;
        return;
    }
    for (Node *k = l.first; k != NULL; k = k->link)
    {
        if (k->info == data)
        {
            p->link = k->link;
            delete k;
            return;
        }
        p = k;
    }
}
void Display(linkedlist l)
{
    cout << "Display list: ";
    Node *p = l.first;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->link;
    }
    cout << endl;
}
int main()
{
    linkedlist l;
    init(l);
    int n;
    cout << "Enter the length of the list: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "Enter element: ";
        cin >> x;
        Node *p = createnode(x);
        addlast(l, p);
    }
    Display(l);
    int f;
    cout << "Enter element to find and remove: ";
    cin >> f;
    if (findelement(l,f)!=1)
    {
        cout << "Found it!\n";
        removeelement(l, f);
        Display(l);
    }
    else
    {
        cout << "Not Found!\n";
    }
    system("pause");
    return 0;
}