#include <stdio.h>
#include <math.h>          // math library is invoked for the power function used in the program 

int sumprime(unsigned long long int x) ;          // Function prototype .The return type of the function is int as the returned value will be the sum of prime numbers which will be less .       
                                                  // the parameter type is unsigned long long int in order to take up 10 digit values without behaving irrationally 
int main()          //start of the main function

{ 
  unsigned long long int a ;          //Initialization of the variable that will accept the value of the 10 digit number . Hence it has the type unsigned long long int  
  int sum ;
	
  printf(" PLease enter the number \n ") ;          // Prompt to the user to enter the number
  scanf ( " %llu" , &a ) ;
  
  while ( !((a/pow(10,10)<1)&&(a/pow(10,9)>1)) || a<0 )          // Condition check that the number entered is only of 10 digits and non negative .If not ,the program asks for the correct input through while loop
  {   printf("INCORRECT INPUT .Please enter again \n" ) ;
      scanf (" %llu" , &a ) ;
  }
  
  sum = sumprime(a) ;          // function call to calculate the sum of prime digits in the number
  printf(" The sum of prime digits = %d ", sum ) ;          // Displaying the value of the sum of prime numbers 
     
}          // End of main

int sumprime(unsigned long long int x)          // Function definition 
{   
	int b = x%10 ;          // The value stored in variable 'b' is the last digit of x . This value is compared to see if its prime or not .
	
	// The base case starts form here
	
	if ((x/10 == 0) && ( b==2 || b==3 || b==5 || b==7) )          //In the base case it is tested if x has only one digit left and if the last digit ( which is actually the first digit of the entered number) is prime or not
	{   return b ; 
	}
	
	if ((x/10 == 0) && !( b==2 || b==3 || b==5 || b==7) ) 
	{   return 0 ; 
	}
	
	// THe base case ends here 
	
	// The recursion case starts here
	
	if ( b==2 || b==3 || b==5 || b==7)          //Here the last digit is checked if its prime or not . If it is prime then the return statement adds b to the recursion
	{   x = (x-b)/10 ;          //Before the recursion statement is executed the number 'x' is reduced by one digit and its second last digit becomes its last digit (Detail procedure in design)
		return b + sumprime(x) ;            //The recursion statement
	}
	else
	{   x = (x-b)/10 ;          // If 'b' is not prime then it is not added in the recursion statement 
		return sumprime(x) ;          // The recursion statement
	}
	
	// End of recursion case
} 
