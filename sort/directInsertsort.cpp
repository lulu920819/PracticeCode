extern "C" void directInsertsort(int * a, int n)
{
    for(int i = 1;i<n;i++)
    {
        int tmp = a[i];
        int j = i-1;
        while(j>=0&&tmp<a[j])
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = tmp;  //j+1的位置才是插入位置
    }
}
