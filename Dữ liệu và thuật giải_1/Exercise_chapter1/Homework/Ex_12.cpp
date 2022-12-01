#include <iostream>
using namespace std;
struct Node
{
    int info;
    Node *next;
    Node *previous;
};
struct linkedlist
{
    Node *first, *last;
};
void init(linkedlist &l)
{
    l.first = NULL;
    l.last = NULL;
}
void display(linkedlist l)
{
    Node *p = l.first;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}
void addfirst(linkedlist &l, int x)
{
    Node *p = new Node;
    p->info = x;
    p->next = l.first;
    p->previous = NULL;
    if (l.first != NULL)
    {
        l.first->previous = p;
        l.first = p;
    }
    else
    {
        l.last = p;
        l.first = p;
    }
}
void addlast(linkedlist &l, int x)
{
    Node *p = new Node;
    p->info = x;
    p->next = NULL;
    p->previous = l.last;
    if (l.last != NULL)
    {
        l.last->next = p;
    }
    else
    {
        l.first = p;
    }
    l.last = p;
}
void removefirst(linkedlist &l)
{
    if (l.first != NULL)
    {
        Node *p = l.first;
        l.first = l.first->next;
        if (l.first != NULL)
            l.first->previous = NULL;
        else
            l.last = NULL;
        delete p;
    }
}
void removelast(linkedlist &l)
{
    if (l.last != NULL)
    {
        Node *p = l.last;
        l.last = l.last->previous;
        if (l.last != NULL)
            l.last->next = NULL;
        else
            l.first = NULL;
        delete p;
    }
}
Node *findelement(linkedlist l, int x)
{
    Node *p = l.first;
    while (p != NULL && p->info != x)
        p = p->next;
    return p;
}
void removeelement(linkedlist &l, int x)
{
    Node *p = findelement(l, x);
    if (p != NULL)
    {
        if (p->previous == NULL)
        {
            removefirst(l);
            return;
        }
        if (p->next == NULL)
        {
            removelast(l);
            return;
        }
        p->previous->next = p->next;
        p->next->previous = p->previous;
        p->previous = NULL;
        p->next = NULL;
        delete p;
    }
}
void addelement(linkedlist &l, int x, int b)
{
    Node *node = new Node;
    node->info = b;
    node->next = NULL;
    node->previous = NULL;
    Node *p = findelement(l, x);
    if (l.first != NULL && l.last != NULL)
    {
        if (p->previous == NULL)
        {
            addfirst(l, b);
        }
        else
        {
            p->previous->next = node;
            node->previous = p->previous;
            p->previous = p;
            node->next = p;
        }
    }
}
int main()
{
    linkedlist l;
    init(l);
    int n, a, b, e;
    cout << "Enter the length of the list: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "Enter element: ";
        cin >> x;
        addfirst(l, x); // addlast
    }
    cout << "Display list: ";
    display(l);
    cout << "Remove the first element: ";
    removefirst(l);
    display(l);
    cout << "Remove the last element: ";
    removelast(l);
    display(l);
    cout << "Enter an element to find and remove: ";
    cin >> a;
    if (findelement(l, a) != NULL)
    {
        cout << "Found it!\n";
        cout << "Remove " << a << " from the list: ";
        removeelement(l, a);
        display(l);
    }
    else
    {
        cout << "Not found!\n";
    }
    cout << "Enter an element to find and add new element before it: ";
    cin >> b;
    cout << "Enter an element to add: ";
    cin >> e;
    addelement(l, b, e);
    if (findelement(l,b)!=NULL)
    {
        cout << "Found it!\n";
        cout << "Add element " << e << " to the list: ";
        display(l);
    }
    else
    {
        cout << "Not found!\n";
    }
    system("pause");
    return 0;
}