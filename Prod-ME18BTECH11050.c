#include<stdio.h> // Including the required library

int main() // main function starts here

{   int N ; // The number to be entered by the user  
	double P = 1 ; //  This variable stores the product .Double is used instead of integer because the product of integer might exceed the limit of int type variable
	int f = 2 ; // Increment variable to be used in while loop 
	
	printf("Please enter the number \n ") ; 
	scanf (	" %d" , &N ) ;
    
    if (N <= 0)  // Error ckeck for N less than or equal to 1 . In this case ,as no positive even integer exists ,it will show error
    { printf("Error \n ") ;
	 
	}
	
	  else if ( N > 30) // N should also not cross 30 to prevent integer overflow
	  
	  { printf("Error.  Number is greter than 30") ;
		 
	  }
	  
	  else if ( N == 1 )
	  { printf("   \n") ;
	  }
	  
	  else  
	  {
	
          if ( N%2 != 0) // if the number entered is odd then the program substracts 1 from the entered number  
	         { N = N - 1 ;
             } 
    
    
          while(f<=N) // comparing the increment variable to number for the loop limit
          
          { P = P*f ; // storing the product
			  printf(" %d ",f) ; // printing out the even numbers whose product is being calculated
			  f=f+2; // incrementing f by 2
		  }
	
	                  printf(" The product of even numbers is %lf " , P) ;
	   }
}

