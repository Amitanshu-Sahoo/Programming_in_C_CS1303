#include<stdio.h>
#include<string.h>

int main(void)

{ float weight ;
  float height ;
  char category[100] ;

printf("please enter the height in meters\n") ;
scanf( "%f" , &height ) ; 

printf("please enter the weight in kilograms \n " ) ;
scanf( "%f" , &weight );

while ( (weight<=0) || (height<=0) )
{ printf ("you have entered a negative value for height or weight \n" ) ;
printf ( "enter height again \n ") ;
scanf ( "%f" , &height ) ;
printf ( "enter weight again \n") ;
scanf ( "%f" , &weight ) ;
} 

float BMI ;

BMI = weight/ (height*height) ; 

if ( BMI>=30) strcpy(category,"obese") ; 
if ( (BMI>=25) && (BMI<=29.9) ) strcpy( category, "Overweight") ;
if ( (BMI>=18.5) && (BMI<=24.9) ) strcpy (category,"Normal") ;
if ( BMI <= 18.5) strcpy(category ,"Underweight" ) ;

printf ( "The BMI of the person is %f \n category is %s ", BMI ,category) ;

}
