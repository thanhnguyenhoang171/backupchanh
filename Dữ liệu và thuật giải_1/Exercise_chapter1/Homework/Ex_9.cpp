#include <iostream>
using namespace std;
struct Node
{
    int info;
    Node *link;
};
struct Stack
{
    Node *top;
};
void init(Stack &s)
{
    s.top = NULL;
}
void Push(Stack &s, int x)
{
    Node *p = new Node;
    p->info = x;
    p->link = s.top;
    s.top = p;
}
int IsEmpty(Stack s)
{
    if (s.top == NULL)
        return 1;
    return 0;
}
int Pop(Stack &s)
{
    int x;
    if (IsEmpty(s) != 1)
    {
        Node *p = s.top;
        x = s.top->info;
        s.top = p->link;
        delete p;
    }
    return x;
}
void display(Stack s)
{
    Node *p = s.top;
    while (p != NULL)
    {
        if (p->info == 1)
            cout << "  A  ";
        if (p->info == 2)
            cout << "  B  ";
        if (p->info == 3)
            cout << "  C  ";
        p = p->link;
    }
    cout << endl;
}
void Display(Stack s)
{
    Node *p = s.top;
    cout << "Display:\n";
    while (p != NULL)
    {
        cout << p->info << endl;
        p = p->link;
    }
}
int Dec_Bin(int x)
{
    int sum = 0, i = 1, temp;
    while (x > 0)
    {
        temp = x % 2;
        sum = sum + (temp * i);
        x = x / 2;
        i = i * 10;
    }
    return sum;
}
void Convert_D_B(Stack &s)
{
    Node *p = s.top;
    while (p != NULL)
    {
        p->info = Dec_Bin(p->info);
        p = p->link;
    }
}

void show(Stack p1, Stack p2, Stack p3)
{
    cout << "-----------------------------\n";
    cout << "rod 1:---";
    display(p1);
    cout << "-----------------------------\n";
    cout << "rod 2:--- ";
    display(p2);
    cout << "-----------------------------\n";
    cout << "rod 3:--- ";
    display(p3);
    cout << "-----------------------------\n";
}
Stack p1;
Stack p2;
Stack p3;
void move(int n, int a, int c, int b)
{
    if (n == 1)
    {
        cout << "\nMove from rod 1 to rod 3";
        Push(p3, Pop(p1));
    }
    if (n == 2)
    {
        cout << "\nMove from rod 1 to rod 3\n";
        Push(p3, Pop(p1));
        show(p1, p2, p3);
        cout << "\nMove from rod 1 to rod 2\n";
        Push(p2, Pop(p1));
        show(p1, p2, p3);
        cout << "\nMove from rod 3 to rod 2\n";
        Push(p2, Pop(p3));
        show(p1, p2, p3);
    }
    if (n == 3)
    {
        cout << "\nMove from rod 1 to rod 3\n";
        Push(p3, Pop(p1));
        show(p1, p2, p3);
        cout << "\nMove from rod 1 to rod 2\n";
        Push(p2, Pop(p1));
        show(p1, p2, p3);
        cout << "\nMove from rod 3 to rod 2\n";
        Push(p2, Pop(p3));
        show(p1, p2, p3);
        cout << "\nMove from rod 1 to rod 3\n";
        Push(p3, Pop(p1));
        show(p1, p2, p3);
        cout << "\nMove from rod 2 to rod 1\n";
        Push(p1, Pop(p2));
        show(p1, p2, p3);
        cout << "\nMove from rod 2 to rod 3\n";
        Push(p3, Pop(p2));
        show(p1, p2, p3);
        cout << "\nMove from rod 1 to rod 3\n";
        Push(p3, Pop(p1));
        show(p1, p2, p3);
    }
}
int main()
{
    init(p2);
    init(p3);
    init(p1);
    int num;
    cout << "***Hanoi Tower***\n";
    cout << "How many disks (1-3): ";
    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        Push(p1, i);
    }
    cout << "\nInitial state \n";
    show(p1, p2, p3);
    move(num, 1, 3, 2);
    cout << "\nFinal state " << endl;
    show(p1, p2, p3);
    system("pause");
    return 0;
}