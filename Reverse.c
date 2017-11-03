#include<stdio.h>
#include<string.h>

int main()
{
	int i, j;
	char temp;
	char str[256];
	
	printf("Enter a string");
	scanf("%s", str); 
	
    int len;
    len = strlen(str);
    
    for(i=0; i<len/2; i++)
	{
    	temp = str[i];
    	str[i] = str[len-1 -i];
    	str[len-1-i] = temp;
    }
    
    printf("%s", str);
    
    while(getch()!=0);
    	
}
