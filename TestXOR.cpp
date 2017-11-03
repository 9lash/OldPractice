/*
Program Description: 

Inputs from the User: 
1. Number of elements for the array (N)
2. The elements of the array

The program accepts the array and its elements, and then splits the array into two parts namely, 
Prefix and Suffix. Prefix is the first part of the array starting from 0 to L where L varies from 0 to N-1
and Suffix is the second part of the split array - can be expressed as r=L+1 to N-1. 
The program finds XOR of all the elements of all possible prefix and suffix arrays formed from the input 
array and calculates XOR of all of the elements of these arrays. The final output is the maximum XOR value 
of all the prefix and suffix arrays. 

*/

#include <stdlib.h>  // standard library
#include <iostream> // std::cout cin


int N;
int *input;
int *prefix; 
int *suffix;

// Function which returns the XOR of all the elements
int xorofarray(int*a, int size)
{
	int result = a[0]; 
	for (int i =0; i<(size-1); i++)
	{
		result = result ^ a[i+1];
	}
	
	return result;
}


int main()
{
	int XOR_prefix, XOR_suffix; 
	int XOR_max=0;
	
	// Ask the user to enter the length of the data
	std::cout<<"Enter the length of the data array"; 
	std::cin>>N;
	
	// Ask the user to enter the values of the input array 
	input = new  int[N];
	
	std::cout<<"Type your N numbers: \n";
	for (int i=0; i<N;i++)
	{
		std::cin>>input[i];
		}	
		
	// Print the values that are stored in the input array
	std::cout<<"Input array consists of : \n";
	for (int i=0;i<N;i++)
	{
		std:: cout<<input[i]<<'\t';
		
		 }

	if(N!=0) 												// Condition avoids XORing garbage values when N=0
	{
	int result = xorofarray(input, N);
	std::cout<<"\nXOR of all the elements of the array: \n";
	std::cout<< result;
	}
	
//Create a prefix array and Suffix array: 

	for (int index=0; index< N; index++)
	{
		// Make a Prefix array
		int size_prefix = index+1;
		int *prefix = new int[size_prefix]; 
		
		for (int l=0; l<= index; l++)
		{
			prefix[l] = input[l];
		}
		
		//Print Prefix Array:
	
		std::cout<<"\nPrefix array consists of : \n";
		for (int i=0;i<size_prefix;i++)
		{
			std:: cout<<prefix[i]<<'\t';
		 }
	
		
		// Make a Suffix Array
		int size_suffix = N - size_prefix;
		int*suffix = new int[size_suffix];
		
		for(int r= index+1; r<=N-1; r++)
		{
			suffix[r-(index+1)] = input[r];
			
		}
		
		//Print the suffix array
		std::cout<<"\nSuffix array consists of : \n";
		for (int i=0;i<size_suffix;i++)
		{
			std:: cout<<suffix[i]<<'\t';
		 }
					
		// Compute XOR of each arrays
		if(size_prefix!=0)							// This condition takes care of not XORing any garbage value when number of prefix elements =0
		{
		XOR_prefix = xorofarray(prefix, size_prefix);
		std::cout<<"\nXOR of prefix :"<<XOR_prefix;
		}
			
		if(size_suffix!=0)							// Condition takes care of not XORing any garbage while the suffix array becomes empty
		{
		XOR_suffix = xorofarray(suffix, size_suffix);
		std::cout<<"\nXOR of suffix :"<<XOR_suffix;
		}
			
		if (XOR_max < XOR_prefix)
		{XOR_max = XOR_prefix;
		}
		else
		{
		if(XOR_max < XOR_suffix)
		{
			XOR_max = XOR_suffix;
		}
	}
			
	}

	std::cout<< "\nThe greatest XOR of all the prefix and suffix arrays are: ";
	std::cout<<XOR_max;
			
	char c=getchar();	 
	while(getchar()!='\n');
	
	return 0;	  	
}

