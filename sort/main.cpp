#include <iostream>
#include"sort.h"
using namespace std;
#define N 10

void display(int * a, int n)
{
    for(int i = 0;i<n;i++)
        cout<<a[i]<<"  ";
    cout<<endl;
}

int main()
{
    cout << "Hello world!" << endl;

    int a[N] ={6,8,7,9,0,1,3,2,4,5};
    display(a,N);

    cout<<"====quicksort===="<<endl;
    quicksort(a,0,N-1);
    display(a,N);

    return 0;
}
