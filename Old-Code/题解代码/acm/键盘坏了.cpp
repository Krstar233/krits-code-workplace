#include <stdio.h>
#include <string.h>

//把s2插到s1的首部 
void headinsert(char s1[], char s2[]);
int main()
{
	char s[100005];
	
	while (gets(s))
	{
		//初始化 
		int s_length = strlen(s);
		char x[100005] = {0}, new_s[100005] = {0};
		char *p = s;
		int flag[2] = {0};	//flag == 1 代表插入头部，flag == 0代表插入尾部
		int signal = 0; //是否插入字符串的信号，1表示插入
		
		//历遍字符串
		for (int i = 0; i <= s_length + 1; i++)
		{
			//有插入信号时，插入字符串
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
				//更新插入方式
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
				//分割字符串
				s[i] = '\0';
				strcpy(x, p);
				//puts(x);
				
				if (i + 1 < s_length)
					p = s + i + 1;
				signal = 1;
			}
		}
		
		//输出
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


