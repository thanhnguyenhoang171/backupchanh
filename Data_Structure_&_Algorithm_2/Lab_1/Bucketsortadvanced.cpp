// bucket sort
#include <iostream>
#define M 100
using namespace std;
float a[M];
int n;

void Input(float a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void Output(float a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
struct Node
{
    float data;
    Node *next;
};
Node *CreateNode(float x)
{
    Node *node = new Node;
    node->data = x;
    node->next = NULL;
    return node;
}
struct Bucket
{
    Node *Buckets[10];
};
void InitBucket(Bucket &bk)
{
    for (int i = 0; i < 10; i++)
    {
        bk.Buckets[i] = NULL;
    }
}
void addhead(Node *&bk, float x)
{
    Node *node = CreateNode(x);
    if (bk == NULL)
    {
        bk = node;
    }
    else
    {
        node->next = bk;
        bk = node;
    }
}
int Funct(float data)
{
    return (data * 10);
}
void swap(float &a, float &b)
{
    float c = a;
    a = b;
    b = c;
}
float FindMax(float a[], int n)
{
    float max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (max < a[i])
            max = a[i];
    }
    return max;
}
float changenum(int n)
{
    float mul = 1;
    while (n != 0)
    {
        mul = mul * 10;
        n = n / 10;
    }
    return mul;
}
// so hang tram gan nhat cua so lon nhat trong mang

void Changearrbig(float a[], int n, int num)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = a[i] / num;
    }
}
void Changearrorigin(float a[], int n, int num)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = a[i] * num;
    }
}
void InsertNode(Bucket &bk, float x)
{
    int i = Funct(x);
    addhead(bk.Buckets[i], x);
}
void Bucketsort(Bucket &bk)
{
    for (int i = 0; i < 10; i++)
    {
        for (Node *p = bk.Buckets[i]; p != NULL; p = p->next)
        {
            for (Node *q = p->next; q != NULL; q = q->next)
            {
                if (p->data < q->data)
                {
                    swap(p->data, q->data);
                }
            }
        }
    }
}
void Insertintoarr(Bucket bk, float a[], int n)
{
    float b[M];
    int j = 0;
    for (int i = 9; i >= 0; i--)
    {
        for (Node *p = bk.Buckets[i]; p != NULL; p = p->next)
        {
            if (j < n)
                b[j++] = p->data;
            else
                break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
}
void Traverse(Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
void TraverseBucket(Bucket bk)
{
    for (int i = 0; i < 10; i++)
    {
        cout << "Bucket " << i << ": ";
        Traverse(bk.Buckets[i]);
    }
}
int main()
{
    float a[M];
    int n;
    Bucket bk;
    InitBucket(bk);
    cout << "Nhap vao so luong phan tu: ";
    cin >> n;
    Input(a, n);
    float num = changenum(FindMax(a, n));
    cout << "Mang ban dau la: ";
    Output(a, n);
    Changearrbig(a, n, num);
    cout << "Display:\n";
    for (int i = 0; i < n; i++)
    {
        InsertNode(bk, a[i]);
    }
    TraverseBucket(bk);
    cout << "Bucket sort:\n";
    Bucketsort(bk);
    TraverseBucket(bk);
    cout << "Mang sau khi sap xep la: ";
    Insertintoarr(bk, a, n);
    Changearrorigin(a, n, num);
    Output(a, n);
    return 0;
}