#include <stdio.h>
#include <string.h>

int main()
{
	int n,i,han;
	char s[250];
	
	scanf("%d",&n);		//�����ַ����ĸ��� 
	while (getchar()!='\n');
	while (n--)
	{
		gets(s);
		han=0;
		for (i=0;i<strlen(s);i++)
		{
			if (s[i]<0)	han++;		/*����ʵ������ͳ�ƺ�����Ŀ��������
									���Һ����������ռ�����ֽڵ����λ����1��
									��ʾʮ���Ƶĸ��� */
		}
		printf("�ϼ�:%d�������ַ�\n",han/2);
	}
	return 0;
}
