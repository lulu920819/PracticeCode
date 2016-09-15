extern "C" void quicksort(int *a, int s, int t)
{
    int i =s, j = t;
    int tmp;
    if(s<t)
    {
        tmp = a[s];
        while(i!=j)
        {
            while(j>i&&a[j]>tmp)
                j--;
            a[i] = a[j];

            while(i<j&&a[i]<tmp)
                i++;
            a[j] = a[i];
        }
        a[i] = tmp;

        quicksort(a,s,i-1);
        quicksort(a,i+1,t);
    }
}
