#include<stdio.h>
#include<string.h>                                                     // Declaring the library string.h to use the gets and puts functions.

char revstring[11] ;
void revthestr(char *ptr,int k) ;                                      // Function prototype with arguments as the pointer that will point to the string location and the size of the string .

int main()                                                             // main function starts here .
{
	int r = 0;                                                         // variable to store size of the entered string.  
	printf("Enter the string to reverse: ") ;                          // prompt to the user to enter the string .
	gets(revstring) ;	                                               
    while(revstring[r]!='\0'){                                         // This while loop counts and stores the size of the string .
		r++ ;}	
		
	if(r==0)                                                           // This if statement checks if nothing has been entered and displays an error message .
	{
		printf("Invalid Input. Nothing has been entered !!") ;
	}
		
	while( r>10 )	                                                   // This while loop checks that the number of entered characters doesnt exceed 10 . If it does then it displays 
	{                                                                  // an error message and asks the user to enter the correct string again .
		printf("Invalid Input. Enter again !! \n") ;
		printf("Enter the string to reverse: ") ;
		gets(revstring) ;
		
		r = 0 ;
		while(revstring[r]!='\0'){
			++r;}
		
		if(r==0)                                                       // This if statement checks if nothing has been entered and displays an error message .
	   {
		   printf("Invalid Input. Nothing has been entered !!") ;
	   }	    		
	}

	revthestr( revstring,r ) ;                                         // Call to the function with the user entered string pointer and its size .
	printf("\nReversed string : "); 
	puts(revstring);
	printf("\n") ;
}                                                                      // Main function ends here .

void revthestr( char *ptr, int k )                                     // Function definition starts here .
{
	k=k-1;                                                             // Reducing the string size variable by 1 so that the size is logically counted from 0.
    char t ;
	for(char i=0; i<=k/2; ++i)                                         // This for loop carries out the pointer manipulation and reverses the order of the chararcters entered .
	{
		t = *(ptr+i) ;                                                 // The variable 't' stores the initial value of the *(ptr +i) .Then the position of *(ptr+i) is initialized with the value of
		*(ptr+i) = *(ptr + k -i) ;                                     // *(ptr +k-i) which is the character which occurs at the same position from the end as *(ptr+i) from the start. 
		*(ptr + k - i) = t;		                                       // Then the value of *(ptr +k-i) is initialized with the value stored in 't'.
	}
}                                                                      //Function definition ends here 
		
		
	
	 
	
			
			
			
			
	
	
