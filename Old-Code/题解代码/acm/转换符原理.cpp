//打印字符原理以及错误使用转换符的结果.cpp 
#include <stdio.h>

int main(void)
{
	int i=291;//291%256=35    c primer plus 第五版 page.74
	char c=35;
	printf("**%c**%c**\n",i,c);
}
