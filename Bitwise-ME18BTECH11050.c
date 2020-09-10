#include<stdio.h>
#include<limits.h>    // Required libraries called .Limits.h is called for the function CHAR_BIT .

void hammingd(unsigned int x, unsigned int y) ;    // Function prototype

int main()    // Main function starts here
{
    unsigned int a,b ;    // Variables to store the two number
    int c=0 ;    // Constant to run the while loop

    while(c == 0)    //While loop to control the input
    {

        printf("Enter the first number :") ;    // Prompt to the user to enter the first number
        scanf(" %d", &a) ;

        while(a>=1024 || a<0)    //Checking the digit if it is greater than 1024
        {
            printf("Enter positive number less than 1024 :") ;
            scanf(" %d", &a) ;
        }

        printf("\nEnter the second number :") ;  //Prompt to the user to enter the second number
        scanf(" %d", &b) ;

        while(b>=1024 || b<0)     //Checking the digit if it is greater than 1024
        {
            printf("Enter positive number less than 1024 :") ;
            scanf(" %d", &b) ;
        }

        hammingd(a,b);    // Call to the function to carry out the operation

        printf("\nDo you want to continue calulating more hamming distances ?.press -1 if not and 0 if yes :") ;    //Asking the user if he wants to continue the operation
        scanf(" %d", &c) ;

        while(c!=0 && c!=-1)    // Loop to control the exit from the above loop
        {
            printf("\nInvalid input .Input either -1 or 0 :") ;
            scanf(" %d", &c);
        }
    }

}

void hammingd(unsigned int x, unsigned int y)    //Function definition
{
    int count = 0 ;    //count to store the hamming distance
    int k = CHAR_BIT*sizeof(unsigned int) ;    // 'k' stores the number of bits of the unsigned int data type for a given architecture
    unsigned int dispm = 1 << k-1 ;    // This variable helps masks off the digits to the left of the MSB to carry out the comparison
    unsigned int res = x^y ;    // The variable x and y are XOR'ed to get the 1
    for(int i=1; i<=k; ++i)
    {
        if((dispm&res)!=0)    // Using & operator to carry out the count operation if the corresponding bits in dispm and res are 1 .
        {
            ++count ;
        }
        res <<= 1 ;
    }

    printf("\nThe hamming distance is : %d  " ,count) ;    //Displaying the hammimg distance
}
