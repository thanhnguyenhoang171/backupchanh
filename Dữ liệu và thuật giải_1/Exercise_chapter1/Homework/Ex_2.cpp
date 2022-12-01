#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX 100

void Input(int A[], int &n)
{
    cout << "Enter the length of the list: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        A[i] = rand() % 100 + 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (A[i] != A[j])
                continue;
            else
            {
                A[i] = rand() % 100 + 1;
                j = i;
            }
        }
    }
}
void Output(int A[], int n)
{
    cout << "Display list: ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
int Sequential_Search(int A[], int n, int x)
{
    int res = -1;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == x)
            res = i;
    }
    return res;
}
void Odered_List(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n - 1; i++)
        {
            if (A[i] > A[j])
                A[i] = A[j];
        }
    }
}
int Binary_Search(int A[], int n, int x)
{
    int left = 0, right = n - 1, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (A[mid] == x)
            return mid;
        if (x > A[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
void Removei(int A[], int &n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (i == x)
        {
            for (int j = i; j < n - 1; j++)
            {
                A[j] = A[j + 1];
            }
            n--;
        }
    }
}
int main()
{
    int A[MAX], n, a;
    Input(A, n);
    Output(A, n);
    cout << "***Find an element by sequential search***\n";
    cout << "Enter element to find and remove: ";
    cin >> a;
    if (Sequential_Search(A,n,a)!=-1)
    {
        cout << "Element " << a << " is in the list at the position " << Sequential_Search(A,n,a) << endl;
        Removei(A,n, Sequential_Search(A,n,a));
        Output(A, n);
    }
    else
        cout << "Not Found!\n";
    cout << "***Find an element by binary search***\n";
    cout << "Enter element to find and remove: ";
    cin >> a;
    if (Binary_Search(A, n, a) != -1)
    {
        cout << "Element " << a << " is in the list at the position " << Binary_Search(A, n, a) << endl;
        Removei(A, n, Binary_Search(A, n, a));
        Output(A, n);
    }
    else
        cout << "Not Found!\n";
    system("pause");    
    return 0;
}