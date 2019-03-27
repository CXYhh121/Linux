//1.将数组A中的内容和数组B中的内容进行交换。（数组一样大） 
#include<stdio.h> 
#include<stdlib.h>
/*void swap  (int arr1 [], int arr2  [], int  leng)
{
	int i = 0;
	for (i = 0; i < leng ;i++)
	{
		int t = arr1 [i];
		arr1[i] = arr2 [i];
		arr2[i] = t;
	}
}
 int main()
{
	int  i = 0;
	int arr1 [5] = { 1, 2, 3, 4, 5 };
	int arr2 [5] = { 5, 4, 3, 2, 1 };
	swap(arr1, arr2, sizeof(arr1) / sizeof(arr1[0]));
	for(i = 0;i < sizeof(arr1) / sizeof(arr1[0]); i++)
	{
	printf("%d", arr1[i]);
	}
	printf("\n");
	for(i = 0;i< sizeof(arr1) / sizeof(arr1[0]);i++)
	{
		printf("%d", arr2[i]);
	}
	return 0;
}*/
//2. 计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值。
/*int main()
{
   int i = 0;
   int flag = 1;
   double count = 0;
 
   for(i=1; i<=100; ++i)
     {
         count += flag*1.0/i;
         flag = -flag;
     }
     
    printf("%f",count);
 
   return 0;
}*/
//3. 编写程序数一下 1到 100 的所有整数中出现多少次数字9。
/*int main()
{
	int count = 0;
	int i = 0; 
	for (i = 0; i<100; i++)
	{
		if(i = _9)
		{
			count++;
		}
		if(i = 9_)
		{
			count**
		}
	printf("count=%d",count);	
	return 0;	
	}
	
}*/
//1.在屏幕上输出以下图案： 
int  main()
{
        int n=6;
        int i,a,b;
        //前4行.上半部分
        for( i=1;i<=n;i++)//控制行数
        {
            for(  a=n-1;a>=i;a--)//打印空格
            {
                printf(" ");
            }
            for(  b=1;b<=2*i-1;b++)//打印*
            {
                printf("*");
            }
            printf("\n");
        }
        //后3行,下半部分
        for( i=n-1;i>=1;i--)
        {
         for( a=i;a<=n-1;a++)
            {
                printf(" ");
            }
            for( b=1;b<=2*i-1;b++)
            {
                printf("*");
            }
            printf("\n");
       }
    }

//2.求出0～999之间的所有“水仙花数”并输出。“水仙花数”是指一个三位数，其各位数字的立方和确好等于该数本身，如；153＝1＋5＋3?，则153是一个“水仙花数”。 
/*int main()
{
    int i,j,k,n;
    printf("水仙花数：",n);
      for(n=100;n<1000;n++)
    {
         i=n/100;
         j=n/10-i*10;
         k=n%10;
      if(n==i*i*i+j*j*j+k*k*k)
            printf("%d\n ",n);
    }
          return 0;
}*/


//3. 求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字，例如：2+22+222+2222+22222
/*int main()
{
	int i = 0;
	int n = 0;
	int a = 0;
	int sum = 0;
	printf("请输入一个数：");
	scanf("%d", &n);
	for (i = 0; i < 5; i++)
	{
		a = n + a * 10;
		sum += a;
	}
	printf("sum=%d\n", sum);
	system("pause");
	return 0;
}*/
