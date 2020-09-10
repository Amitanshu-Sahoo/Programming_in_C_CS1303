#include<stdio.h>

int addition(int c, int v) ;                 // The following are the function prototypes to be used in the program
int substraction(int s , int d);
long long int multi(int x, int y) ;
int div(int l , int m) ;
int modu(int p,int h) ;
long long int squar(int k) ;
int squaroot(int z);
int logtwo ( int q ) ;

int main()    // starting of the main function
{

  int a = 0 ,b = 1, c = 1;   // initialization of the variables.'a' is the choice variable .It has been initialized with a value to enable the working of the while loop .
  long long int ans ;                  // The variables b and c are assigned a value of 1 to prevent the already present garbage value in the variable which may cause irrational behaviour in variable comparisons .
  while ( a != 9)
  {
  printf( "MENU: \n Enter the number corresponding to the operation you want to perform. \n" ) ;
  printf( " 1: Add \n 2: Multiply \n 3: Divide \n 4: Substract \n 5: Modulus \n 6: Square \n 7: Square Root \n 8: Log ( Base : 2) \n 9: Exit \n " ) ; // prompts the user to enter their operation of choice
  scanf ( " %d" , &a) ;
  printf("Your Choice : %d ", a) ; // Displays the selected choice
  printf("\n") ;
  while ( (a<1) || (a>9))  // Sanity check to prevent the user from entering any other number for choice other than mentioned above
  { printf("Enter valid choice as directed above \n") ;
	scanf( " %d", &a) ;
  }

  if ( (a>=1) && (a<=5))                         // the operations 1 to 5 require two inputs .Hence this if statement helps to provide the option of two inputs
  {  printf("Enter the first number : ") ;
     scanf( " %d", &b) ;
     printf("\n") ;
     printf("Enter the second number : ") ;
     scanf(" %d" ,&c) ;
     printf("\n") ;
  }

  if (a>=6 && a<=8)                             // the operations 6 to 8 require only a single input . Hence this if statement restricts the user to a single input .
  { printf("Enter the number \n");
	scanf(" %d", &b);
  }

  if ( (b<0) || (c<0) )                         // As per the question ,this if statement checks that all the input are greater than or equal to 0
  { printf("Entered number must be positive \n") ;
	continue ;
  }

  else if (a==3 && c==0)                       // For the division operation chosen , this if statement checks that the denominator is not equal to zero
  { printf("2nd number must be positive \n") ;
	continue ;
  }
  else if (a==8 && b<=0)                       // For the logarithm operation chosen this if statement checks that the input is always greater than 0
  {printf("The value is not an acceptable value for chosen function \n");
  }

  else
  {


     switch (a)                                   // starting of switch case
        { case 1 : ans = addition(b,c);                                           // case for addition
			         printf( "The result is : %lld \n",ans);
	                 break ;

	      case 2 : ans = multi(b,c) ;                                             // case for multiplication
	                 printf( "The result is : %lld\n",ans);
	                 break ;

	      case 3 : ans = div(b,c);                                                // case for division
	                 printf( "The result is : %lld \n",ans);
	                 break ;

	      case 4 : ans = substraction(b,c) ;                                      // case for substraction
	                 printf( "The result is : %lld \n",ans);
	                 break ;

	      case 5 : ans = modu(b,c) ;                                              // case for modulus (Remainder)
	                 printf( "The result is : %lld \n",ans);
	                 break ;

	      case 6 : ans = squar(b) ;                                               // case for square of the input
	                 printf( "The result is : %lld \n",ans);
	                 break ;

	      case 7 : ans = squaroot(b) ;                                            // case for squareroot of the input
	                 printf( "The result is : %lld \n",ans);
	                 break ;

	      case 8 : ans = logtwo(b) ;                                              // case for logarithm of the input
	                 printf( "The result is : %lld \n",ans);
	                 break ;

	      case 9 : printf("You have exit the calculator \n" ) ;                   // case for leaving the calculator
	                 break ;
        }
	}
  }
}

int addition(int c, int v)            // function definitions have been given here
{ return c+v ;
}

int substraction(int s , int d)
{return s-d  ;
}

long long int multi(int x, int y)
{ long long int a = 0;
	for ( int i = 1 ; i <= x ; i++ )  // for carrying out multiplication a variable is initialized with value zero and one input is added to the variable as many times as the other input
	{ a = a + y ;
	}
  return a ;
}

int div(int l, int m )
{ int a = l;
	int i = 0;
	while ( (a-m) >= 0 )   // for carrying out division a variable is initialised with the value of numerator and the denominator is substracted from it until the diffrence between the two is not less than 0
	{ a = a - m;
	  i = i + 1 ;
    }
  return i ;
}

int modu(int p, int h)
{ int a = p ;            //  The same operation is carried out as above in division . except that the return value is the initialised variable itself
	while(a >= 0)
	{ a = a-h ;
	}
  return a+h ;
}
long long int squar(int k)
{ long long int prod = multi(k,k) ;  // The multiplication function is called here with same value of both the inputs to calculate the square
  return prod;
}

int squaroot(int z)
{ int y = 1 ;              // The idea used in the square root function is that a variable y is assigned with value 1 .Its square is assigned to another variable 'a'.
	int a = multi(y,y) ;   // a is compared with the input value . Until the input is not smaller than the value of 'a' , the variable y is incremented and its square is assigned to 'a'.
	while ( a <= z)        // In this way we obtain the floor value of the squareroot of the input
	{ y = y + 1 ;
		a = multi(y,y);
	}
	y = y-1 ;

  return y;
}

int logtwo(int q)
{
  int a = 1 ;
  int i = 0 ;              // A similar approach to squaroot function is used in making the logarithm function. Except that the ceil value is calculated here
  while (q > a)
  {a = multi(a,2) ;
   i = i + 1 ;
  }
  return i ;
}
