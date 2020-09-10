#include<stdio.h>
#include<math.h>

int t = 0 ;                                                             // Declaration of global variables and function prototypes
int b,d ;
void matrixmultiplication(float arr1[][b], float arr2[][d], int a ,int c) ;
float deter( float arr[][d],int a);
void inversematrix( float arr[][d],int a);

int main()
{
	int a,c ;
	printf("Enter the order of matrix A :") ;        // prompt to the user to enter the order of the matrix A
	scanf( " %d", &a) ;
	scanf( " %d", &b) ;
	printf("\nEnter the order of matrix B :") ;      // prompt to the user to enter the order of the matrix B
	scanf( " %d", &c) ;
	scanf( " %d", &d) ;
	
while( a==1 || b==1 )                                                  // checks to see that the matric does not have any dimension as 1
{
	printf("Enter dimensions greater than 1 for matrix A :") ;
    scanf( " %d", &a) ;
	scanf( " %d", &b) ;
}

while( c==1 || d==1 )
{
	printf("\nEnter dimensions greater than 1 for matrix B :") ;
	scanf( " %d", &c) ;
	scanf( " %d", &d) ;
}
				
while( b!=c)                                                           // multiplication is not possible if b is not equal to c 
{
	printf("The column dimension of Matrix A does not Match with row dimension of Matrix B. Enter the common dimension for both \n") ;
	printf("Column dimension of Matrix A :") ;
	scanf( " %d",&b) ;
	printf("\nRow dimension of Matrix B :") ;
	scanf( " %d",&d) ;
}

float arr1[a][b], arr2[c][d] ;                                         // Matrices to store the Matrix A and Matrix B

for( int i = 0 ; i < a; ++i)                                           // For loop for taking elements into Matrix A
{
	for(int j = 0 ; j < b; ++j)
	{
		printf("\nEnter the element (%d,%d) of Matrix A :",i+1,j+1);
		scanf(" %f", &arr1[i][j]);
	}
}


for( int i = 0 ; i < c; ++i)                                           // For loop for taking elements into Matrix B
{
	for(int j = 0 ; j < d; ++j)
	{
		printf("\nEnter the element (%d,%d) of Matrix B :",i+1,j+1);
		scanf(" %f", &arr2[i][j]);
	}
}

printf("\n\n") ;
matrixmultiplication(arr1,arr2,a,c) ;                                  // Call  to the multiplication function to cary out multiplication and also do the inverse operation 

}

void matrixmultiplication( float arr1[][b] ,float arr2[][d], int a, int c) 
{
	float arr3[a][d];                                                  // Matrix to store the product 
	
	for(int i=0 ;i<a;++i)                                              // Nested for loop to calculate the product matrix 
	{
		for(int j=0;j<d;++j)
		{
			arr3[i][j]=0;
			for(int l=0;l<c;++l)
			{
				arr3[i][j] += arr1[i][l]*arr2[l][j] ;
			}
		}
	}
	
	printf("The resultant product matrix is :\n" ) ;                   
	for(int i=0;i<a;++i)                                               // Printing the product matrix
	{
		for(int j=0;j<d;++j)
		{
			printf(" %f ",arr3[i][j]) ;
		}
		
		printf("\n") ;
	}
	
	if(a==d)                                                           // This if statement tests if the row of matrix A and column of matrix B is equal or not  
	{                                                                  // If they are equal inverse exists else it doesnt exist.
	    inversematrix( arr3 ,a) ;                                      
    }
    else
    {
		printf(" \n Inverse does not exist as it is not a square matrix \n") ;
	}
}

float deter( float arr[][d], int a)                                    // Determinant function definition 
{
	// finding the determinant starts here
	
	if(a==1)
		return arr[0][0];
	//base class starts here
	if(a==2)
	{
		int r = ( arr[0][0]*arr[1][1] - arr[1][0]*arr[0][1] ) ;
		return r ;
	}
	// base class ends here 
	
	// recursion part starts here 
	else
	{
		
		
		float s=0;                                                     // The logic behind the recursion is finding the minor matrix of the given matrix for the first row of the elements
		for(int n=0; n<a; ++n)                                         // The variable 'n' runs through the first row of the main matrix
		{
			float arr4[a-1][a-1];
			int x=0 ,y=0;
			for(int i=1;i<a;++i)                                       // The nested for loop transfers the value fromm 'arr' to 'arr4' at the correct places 
			{
				for(int j=0;j<a;++j)
				{
					if(j!=n)
					{
						arr4[x][y] = arr[i][j] ;
						y = y + 1 ;
					}
					
				}
				y=0;
				x = x + 1;
			}

			if(n%2==0)                                                 // This statement convert the minor matrix into cofactor matrix and helps to store the value of the matrix  
	    	{
	    		d=a-1;
	    		float r=deter(arr4,a-1);
				s = s + arr[0][n]*r;				
			}
			else
			{
				d=a-1;
				float r=deter(arr4,a-1);
				s = s - arr[0][n]*r;				
			}
			
	
		}
	return s ;                                                         // returning the determinant value 
	}
	// Recursion part stops here 
	
}
					
void inversematrix( float arr[][d],int a)                              // Inverse and Cofactor function function definition 
{
    float determ = deter(arr,a);                                       // Calculating the determinant of the matrix  
    
    float cof[a][a];
    if( determ != 0)
	{
	for(int m=0; m<a; ++m)
	{
		for(int n=0; n<a; ++n)
		{
			                                                           // The cofactor calculation starts here
			float arr4[a-1][a-1];
			int x=0 ,y=0;
			for(int i=0;i<a;++i)
			{			
				  for(int j=0;j<a;++j)
				  {
					  if(j!=n && i!=m)                                 //Calculation of the cofactor has the same logic behind it as the calculation of the determinant  
					  {                                                //except that the all the rows are operated upon for finding out the cofactor  
						  arr4[x][y] =0;
						  arr4[x][y] = arr[i][j] ;
						  y = y + 1 ;
					  }
					  if(y==a-1)
					  {
					  	y=0;
					  	x = x+1;

					  }				
				  }			 		    
			}

                                                                       // The cofactor calculation ends here          
                                                                       // Inverse calculation starts here
			if((m+n)%2==0)
			{
				d=a-1;
				float f = deter(arr4,a-1);
				cof[m][n] = f/determ ;
			}
			else
			{
				d=a-1;
				float f = deter(arr4,a-1);
				cof[m][n] = (-1*f)/determ ;
			}
			                                                           //Inverse calculation ends here 
	        
		}
	}
	// transpose below
	
	float inverse[a][a];                                               // Transpose of the cofactor matrix divided by the determinant gives the inverse
	for(int i=0; i<a; ++i)
	{
		for(int j=0; j<a; ++j)
		{
			inverse[i][j]=cof[j][i];
	
	    }
    }
    
    printf("The inverse of the matrix is : \n") ;                      // Printing the inverse
    
    for(int i=0; i<a; ++i)
	{
		for(int j=0; j<a; ++j)
		{
			printf(" %f ",inverse[i][j]) ;
		}
		printf("\n") ;
	
    }
    }
    else
    {
		printf("Inverse does not exist as determinant is 0 \n") ; 
	
    }
}
		
	
				
				
					
				
				
			

	
	
	
				
			
	
	
