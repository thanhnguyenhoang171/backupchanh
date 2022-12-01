#include <iostream>
using namespace std;
struct Node
{
    int info;
    Node *link;
};
struct stack
{
    Node *top;
};
void init(stack &s)
{
    s.top = NULL;
}
void push(stack &s, int x)
{
    Node *p = new Node;
    p->info = x;
    p->link = s.top;
    s.top = p;
}
int Pop(stack &s, int &x)
{
    if (s.top != NULL)
    {
        Node *p = s.top;
        x = p->info;
        s.top = p->link;
        delete p;
        return 1;
    }
    return 0;
}
void convert(stack &s, int num, int dec)
{
    while (dec != 0)
    {
        int x = dec % num;
        push(s, x);
        dec /= num;
    }
}
void show(stack &s)
{
    while (s.top != NULL)
    {
        int x;
        Pop(s, x);
        if (x < 10)
        {
            cout << x;
        }
        else
        {
            if (x == 10)
            {
                cout << "A";
            }
            else if (x == 11)
            {
                cout << "B";
            }
            else if (x == 12)
            {
                cout << "C";
            }
            else if (x == 13)
            {
                cout << "D";
            }
            else if (x == 14)
            {
                cout << "E";
            }
            else if (x == 15)
            {
                cout << "F";
            }
        }
    }
    cout << " ";
}
int main()
{
    stack s, l;
    init(s);
    init(l);
    int num, n;
    cout << "Enter the length of the list: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        push(l, x);
    }
    do
    {
        cout << "\nEnter the number to convert (2, 8, 16):  ";
        cin >> num;
    } while (num != 2 && num != 8 && num != 16);
    Node *t = l.top;
    cout << "Result: ";
    while (t != NULL)
    {
        cout << t->info << " = ";
        convert(s, num, t->info);
        t = t->link;
        show(s);
        if (t != NULL)
            cout << "; ";
        else
            cout << ". ";
    }
    cout << endl;
    system("pause");
    return 0;
}