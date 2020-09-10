#include<stdio.h>

int combination( int x , int y ) ; // Function prototype .It tells the program that this function will be used in the program 

int main () 
{ int a , b ;
  long ans ;
  printf("Please enter the number a \n") ; // Prompt to the user to input the number x
  scanf( " %d" , &a ) ;
  printf("Please enter the base \n") ; // Prompt to the user to input the number y
  scanf( " %d" , &b) ;
  
  if ( (a<b) || (a<=0) || (b<0) )  // The if statement checks if x is less than y, x is not less than or equals to 0 and y is not less than 0 
  { printf("Incorrect Input !!" ) ;
  }
  else {
  ans = combination(a,b) ; // function call . THe pointer moves to the function definition from here 
  printf("The answer is %ld \n" , ans) ;
}
}
int combination( int x , int y)  // This is the function definition
{ int z = x - y ; 
  int i ;
  long p = 1;
  long ans1 ;
  
  for ( i=1 ; i<=x ; i++)  // This for loop calculates x!
  { p = p*i ;
  }
  
  long l = 1 ;
  for ( i=1 ; i<=y ; i++) // This for loop calculates y!
  { l = l*i ;
  } 
  
  long m = 1 ;
  for ( i=1 ; i<=z ; i++) // This for loop calculates (x-y)!
  { m = m*i ;
  }
  
   ans1  = p/(l*m) ;
   return ans1 ; // This value is returned to the function call 
}
  
  

  
