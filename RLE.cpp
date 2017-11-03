#include<stdio.h>

int input_buffer[6];
int output_buffer[6];

int main()
{
	int i,j,k;
//initilaizing the input buffer	
	printf("Enter the input buffer:\n");
	for ( i= 0; i<4;i++)
	{
		input_buffer[i] = 1;	
	}
	
	for(j = 4; j<6; j++)
	{
		input_buffer[j] = 5;
	}

 int* p; 
 int temp;
 p = input_buffer;
 temp = *p; 
 k = 0; 
 
 while(p < input_buffer + 6)
 {
 	if(*p == temp)
 	{
 		output_buffer[k]++;
	 }
	 else
	 {
	 	k++;
	 	temp = *p;
	 	output_buffer[k]++;
	 }
	 p++;
  } 
  
  for (i=0; i<6; i++)
  {
	  printf("%d\n", output_buffer[i]);  	
  }
  
  while(getchar()!='\n');
  
  return 0;
}


