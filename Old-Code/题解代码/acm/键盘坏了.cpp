#include <stdio.h>
#include <string.h>

//��s2�嵽s1���ײ� 
void headinsert(char s1[], char s2[]);
int main()
{
	char s[100005];
	
	while (gets(s))
	{
		//��ʼ�� 
		int s_length = strlen(s);
		char x[100005] = {0}, new_s[100005] = {0};
		char *p = s;
		int flag[2] = {0};	//flag == 1 �������ͷ����flag == 0�������β��
		int signal = 0; //�Ƿ�����ַ������źţ�1��ʾ����
		
		//�����ַ���
		for (int i = 0; i <= s_length + 1; i++)
		{
			//�в����ź�ʱ�������ַ���
			if (flag[0] == 0 && signal)
			{
				strcat(new_s, x);
			}
			else if(flag[0] == 1 && signal)
			{
				headinsert(new_s, x);
			}
			
			signal = 0;
			
			if (i <= s_length)
			if (s[i] == '[' || s[i] == ']' || s[i] == '\0')
			{
				//���²��뷽ʽ
				if (s[i] == '[')
				{
					flag[0] = flag[1];
					flag[1] = 1;
				}
				else if (s[i] == ']')
				{
					flag[0] = flag[1];
					flag[1] = 0;
				}
				else
					flag[0] = flag [1];
				
				//printf ("****\n");
				//�ָ��ַ���
				s[i] = '\0';
				strcpy(x, p);
				//puts(x);
				
				if (i + 1 < s_length)
					p = s + i + 1;
				signal = 1;
			}
		}
		
		//���
		puts(new_s); 
	}
}
void headinsert(char s1[], char s2[])
{
	char x[100005];
	
	strcpy(x, s2);
	strcat(x, s1);
	strcpy(s1, x);
}


