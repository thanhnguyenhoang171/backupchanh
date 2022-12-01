#include <iostream>
#define M 100
using namespace std;
struct Sinhvien
{
    int maso;
    string ho;
    string ten;
    int tuoi;
};
void Input(Sinhvien sv[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "STT: " << i + 1 << endl;
        cout << "Nhap ma so: ";
        cin >> sv[i].maso;
        cout << "Nhap ho: ";
        cin >> sv[i].ho;
        cout << "Nhap ten: ";
        cin >> sv[i].ten;
        cout << "Nhap tuoi: ";
        cin >> sv[i].tuoi;
    }
}
void Output(Sinhvien sv[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "STT: " << i + 1 << " ";
        cout << "Ma so: " << sv[i].maso << " ";

        cout << "Ho: " << sv[i].ho << " ";
        cout << "Ten: " << sv[i].ten << " ";
        cout << "Tuoi: " << sv[i].tuoi << endl;
    }
}
void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}
void MaxHeapify(Sinhvien sv[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l<n && sv[l].ten> sv[largest].ten)
        largest = l;
    if (r<n && sv[r].ten > sv[largest].ten)
        largest = r;
    if (largest!=i)
    {
        swap(sv[largest], sv[i]);
        MaxHeapify(sv, n, largest);
    }
}
void BuildSmallHeap(Sinhvien sv[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        MaxHeapify(sv, n, i);
    }
}
void HeapSort(Sinhvien sv[], int n)
{
    BuildSmallHeap(sv, n);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(sv[0], sv[i]);
        MaxHeapify(sv, i, 0);
    }
}
int main()
{
    Sinhvien sv[M];
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    Input(sv, n);
    cout << "\nDanh sach sinh vien ban dau:\n";
    Output(sv, n);
    cout << "\nHeap sort tang dan danh sach theo ten sinh vien:\n ";
    HeapSort(sv, n);
    Output(sv, n);
    return 0;
}