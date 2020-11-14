#include <stdio.h>
#include <string.h>

int main()
{
	int n,i,han;
	char s[250];
	
	scanf("%d",&n);		//输入字符串的个数 
	while (getchar()!='\n');
	while (n--)
	{
		gets(s);
		han=0;
		for (i=0;i<strlen(s);i++)
		{
			if (s[i]<0)	han++;		/*这里实际上是统计汉字数目的两倍，
									并且汉字内码的所占两个字节的最高位都是1，
									表示十进制的负数 */
		}
		printf("合计:%d个中文字符\n",han/2);
	}
	return 0;
}
