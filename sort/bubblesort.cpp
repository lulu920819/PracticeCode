extern "C" void bubblesort(int *a, int n)
{

    for(int k  = 0;k<n-1;k++)  // k: [0,n-2], ��һλ�������ڶ�����ѭ������K��λ��
    {
        bool exchange = false;  // ��¼�����Ƿ��н���
        for(int i = n-1;i>k;i--)  // i: [n-1,i+1];  ���һ������k֮����Ǹ�����ѭ������ΪҪi-1�����Բ��ǵ���
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
//        else  //���Բ���Ҫ����Ϊѭ����ʼ���ḳֵΪfalse��
//            exchange = false;
    }

}
