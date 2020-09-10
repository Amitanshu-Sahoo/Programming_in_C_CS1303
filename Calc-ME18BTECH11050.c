#include<stdio.h> 
#include<math.h>
#include<stdlib.h>

int main() 
{ 
	int number1,number2; // variable declaration for two numbers
	char c ; // variable declaration for character
	
	
    printf("please enter the operation you want perform  \n \"+\" for additon \n \"-\" for substraction  \n \"*\" for multiplication \n \"/\" for division \n ") ;
	scanf(" %c",&c) ;     // taking the character input
  
	
	if ( (c == '+') || (c =='-') || (c == '*') || (c == '/') ) // comparison used to identify the correct character 
	{  printf("enter the first number") ;
	   scanf("%d" ,&number1) ;
	   printf("enter the second number") ;
	   scanf("%d" ,&number2) ;
	}
	
	else
		
	{ printf("Error. Wrong character \n ") ;
	  exit ;
    }
     
     float r = abs(number1 * number2) ;
     
     while( r > pow(10,20))  // number should not be greater than 10 power 20 as given in the question
     
     { printf( "Error . Please enter smaller values of first number and second number ") ;
	   scanf( " %d" , &number1) ;
       scanf( " %d" , &number2) ;
     } 
     
     // from here we start the calculation based on the character entered using if statements
     
     if ( c == '+' )
     {   
		 printf( " Sum is %d \n" , number1 +number2 ) ;
	 }
	 
	 if ( c == '-' )
	 { 
		 printf( " Difference is %d \n" , number1 - number2) ;
	 }
	 
	 if ( c == '*' )
	 { 
		 printf( " Product is %d \n" , number1 * number2 ) ;
	 }
	 
	 if ( c == '/' )
	 { 
		 if (number2 == 0)  // This if statement tests if the denominater is 0 . If it is so then it displays error message 
		 { printf( "Error Division \n") ; 
		 } 
		 
		 else 
		{ 
		 printf( " Result is %f \n" ,(float)number1 / (float)number2 ) ; // Here typecast is used to convert the int value into float for division operation
	    }
	 }
	 
     return 0;	 
	    
}
        
