#include<stdio.h>
#include<string.h>
int main()
{
	int l;
	char string[100];
	printf("enter the string : ");
	scanf("%s",string);
	l=strlen(string);
	if(string[0]=='b' && string[l-1]=='a')
	{
		for(int i=0;i<l;i++)
		{
			if(string[i]=='0' || string[i]=='1')
			{
				printf("invalid");
				return 0;
			}
		}
		printf("string is accepted");
	}
	else
	{
		printf("string is not accepted");
	}
}
