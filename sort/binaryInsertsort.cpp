extern "C" void binaryInsertsort(int * a, int n)
{
    for(int i = 1;i<n;i++)
    {
        int s = 0;
        int t = i-1;
        int tmp = a[i];
        while(s<=t)  //相等是结束条件
        {
            int mid = (t+s)/2 ;
            if(tmp<a[mid])
                t = mid-1;
            else
                s = mid+1;
        }
        for(int j = i-1;j>=t+1;j--)
            a[j+1] = a[j];
        a[t+1] = tmp;   // t+1是插入位置记得
    }
}
