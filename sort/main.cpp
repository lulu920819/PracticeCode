#include <iostream>
#include"sort.h"

#define N 10

using namespace std;

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

//    cout<<"====quicksort===="<<endl;
//    quicksort(a,0,N-1);
//    display(a,N);

//    cout<<"====bubblesort===="<<endl;
//    bubblesort(a,N);
//    display(a,N);

//    cout<<"====directInsertsort===="<<endl;
//    directInsertsort(a,N);
//    display(a,N);

//    cout<<"====binaryInsertsort===="<<endl;
//    binaryInsertsort(a,N);
//    display(a,N);

    int b[N+1] = {-1,6,8,7,9,0,1,3,2,4,5};
    cout<<"====heapsort===="<<endl;
    // 下标从1开始的
    heapsort(b,N);
    display(b,N+1);
    return 0;
}
