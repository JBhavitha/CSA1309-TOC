#include<stdio.h>
#include<string.h>
int main()
{
	int l;
	char string[50];
	printf("enter the string : ");
	scanf("%s",string);
	l=strlen(string);
	if(string[0]=='0'&& string[l-1]=='1')
	{
		for(int i=0;i<l;i++)
		{
			if(string[i] > '1')
			{
				printf("invalid \n");
				return 0;
			}
		}
		printf("string is accepted ");
	}
	else 
	{
		printf("string is not accepted");
	}
}
