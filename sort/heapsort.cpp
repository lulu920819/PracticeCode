void sift(int *a, int low, int high)
{
    int i = low,j = 2*i;
    int tmp = a[i];
    while(j<=high)
    {
        if(j<high&&a[j]<a[j+1])
            j++;
        if(tmp<a[j])
        {
            a[i] = a[j];
            i = j;
            j = 2*i;
        }
        else
            break;
    }
    a[i] = tmp;
}

extern "C" void heapsort(int *a , int n)
{
    for(int i = n/2; i>=1;i--) //Ñ­»·½¨¶Ñ
    {
        sift(a,i,n);
    }

    for(int i = n;i>=2;i--)
    {
        int tmp = a[1];
        a[1] = a[i];
        a[i] = tmp;
        sift(a,1,i-1);
    }
}
