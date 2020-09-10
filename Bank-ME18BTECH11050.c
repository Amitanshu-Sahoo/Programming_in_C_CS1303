#include <stdio.h>

int main() 
{
	int N ;
	double bal , am ,wid ;
	
	printf("PLease enter the required number of operations you want to perform \n ") ;
	scanf(" %d", &N) ;
	
	while( N < 0 )
	{ printf("Invalid Input. PLease enter again \n" );
	  scanf(" %d", &N) ; 
	}
	

	  printf("please enter your initial balance \n ") ;
	  scanf(" %lf" , &bal) ;
	
	while (bal < 0) 
	{ printf("invalid input. Please enter the correct balance amount \n " );
		scanf(" %lf", &bal) ;
	}
	
	char r ;
	
	for(int i=1; i<=N ; ++i)
	{    
		printf(" PLease enter desired operation \n Enter a or A for adding money to the account \n Enter b or B for withdraw \n Enter c or C for checking your current account balance \n ") ;
		scanf(" %c" , &r) ;
		
		while ( r!='a' && r!='A' && r!='b' && r!='B' && r!='c' && r!='C' )
		{ printf(" Invalid character input . PLease enter the correct characters asked above \n") ;
			scanf(" %c" ,&r) ;
		}
		
		switch (r) 
		{
		  case 'a' : case 'A' :
		  
		  { printf("AddAmount \n ") ;
		    scanf(" %lf", &am);
		    if(am<0)
		    {printf("Invalid input \n") ;} 
		    
		    else
		    {bal = bal + am ;
		    printf("success \n") ;}
		  }
		  
		  break ;
		  
		  case 'b' : case 'B' :
		  
		 { printf("WithdrawAmount \n ") ;
		   scanf(" %lf" , &wid) ;
		   if (bal<wid)
		      printf("error \n ") ;
		   else 
			  {  bal = bal - wid ;
			     printf("success \n ") ; } 
			  
		 }
		 
		 break ; 
			
		 case 'c' : case 'C' : 
		 
		 { 
			 printf(" GetBalance \n %lf \n ",bal) ;
		 } 
		 
		 break ;   
		 
	 }
    }
} 			  
	
	
	
