#include<stdio.h>
#include<string.h>

int main()
{
	int i, j, match;
	int len;
	char str[256];
	
	printf("Insert a string: \n");
	scanf("%s", str);
	printf("%s\n", str);
	
	len = strlen(str);
	printf("%d\n", len);
	match =1;	
	for(i=0; i<=(len/2); i++)
	{
	  if(str[i] == str[len-i-1])
	  {printf("%c ", str[i]);
	   printf("%c\n", str[len-i-1]);
	  }
	  else
	  { match = 0;
	    break;
	  }
	} 
	
	if(match ==0)
	{printf("Not a Palindrome");
	}
	else
	{
		printf("Palindrome found!");
	}
	
	while(getch()!=0);
}
