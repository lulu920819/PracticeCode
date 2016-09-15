extern "C" void bubblesort(int *a, int n)
{

    for(int k  = 0;k<n-1;k++)  // k: [0,n-2], 第一位到倒数第二个，循环，第K个位置
    {
        bool exchange = false;  // 记录本趟是否有交换
        for(int i = n-1;i>k;i--)  // i: [n-1,i+1];  最后一个数到k之后的那个数，循环，以为要i-1，所以不是等于
        {
            if(a[i]<a[i-1])
            {
                exchange = true;
                int tmp = a[i];
                a[i ] = a[i-1];
                a[i-1] = tmp;
            }
        }

        if(!exchange )
            return;
//        else  //可以不需要，因为循环开始都会赋值为false的
//            exchange = false;
    }

}
