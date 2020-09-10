#include<stdio.h>    // Calling the appropriate libraries
#include<string.h>

struct engineparts{    // Structure definition . It has been kept global to pass the structure pointers as arguments to the functions
	char sernum[4] ;
	char material[6];
	int  weight;
	int  date;
	int  month;
	int  year;
	int  k ;
};

int t = 0 ,v=0,b=0 ;    // variables declared to be used later in the function WLT5
typedef struct engineparts EP ;    //Using typedef to make a short name for the structure
void WLT5( EP *egp1 ) ;    //Function definition to carry out the different tasks as per the questions
void YMI( EP *egp2 );
void EPI( EP *egp3 ) ;

enum serialnumber {    // This enumerator has been initialized to store the numbers corresponding to serial numbers entered .
	AA0 = 0, AA1,AA2,AA3,AA4,AA5,AA6,AA7,AA8,AA9,
	BB0,BB1,BB2,BB3,BB4,BB5,BB6,BB7,BB8,BB9,
	CC0,CC1,CC2,CC3,CC4,CC5,CC6,CC7,CC8,CC9,DD0,DD1,
	DD2,DD3,DD4,DD5,DD6,DD7,DD8,DD9,EE0,EE1,EE2,EE3,EE4,EE5,
	EE6,EE7,EE8,EE9,FF0,FF1,FF2,FF3,FF4,FF5,FF6,FF7,FF8,FF9
} ;

char *serialnum[] = { "AA0","AA1","AA2","AA3","AA4","AA5","AA6","AA7","AA8","AA9",    // This array stores the allowed names of the serialnames
	"BB0","BB1","BB2","BB3","BB4","BB5","BB6","BB7","BB8","BB9",
	"CC0","CC1","CC2","CC3","CC4","CC5","CC6","CC7","CC8","CC9","DD0","DD1",
	"DD2","DD3","DD4","DD5","DD6","DD7","DD8","DD9","EE0","EE1","EE2","EE3","EE4","EE5",
	"EE6","EE7","EE8","EE9","FF0","FF1","FF2","FF3","FF4","FF5","FF6","FF7","FF8","FF9"
} ;

int main()
{
	int j ;
	printf("Enter the number of parts :");    //Promt to the user to enter the number of parts he/she wants to enter
	scanf(" %d",&j);

	while(j<1 || j>5)    //Check that the number of parts entered does not exceed 5 or is less than 1
	{
	    printf("You can only enter the part between 1 and 5 . Enter again :");
	    scanf(" %d",&j);
	}

	EP *eptr=NULL;    // Pointer to structure using which all the operations have been carried out
	EP engp[j];

	for(int i=0; i<j; ++i)    //This for loop goes the number of parts entered
	{
		eptr = &engp[i];    //Pointer to structure taking the address of the structure instance in which part information is stored
		printf("\nEnter the serialnumber of part %d :",i+1);    // Prompt to the user to enter the serial number
		scanf(" %s",eptr->sernum) ;
		enum serialnumber sn = AA0 ;
		int r=0 ;
		while(r==0)    //This while loop equates the serial number entered to its corresponding operation number in the system as initialized in the enumerator above
		{
			if( strcmp(eptr->sernum,serialnum[sn])==0 )
			{
				eptr->k = sn;
				r=1;
			}
			else
			{
				++sn;
			}
		}

		printf("\nEnter the date of manufacture for part %d",i+1);    //Prompt to the user to enter the date of manufacturing
        printf("\nEnter date :") ;                                    // Date ,month ,year have been stored seperately for the ease of operation in the functions
        scanf( " %d",&eptr->date);
        printf("\nEnter month :");
        scanf(" %d",&eptr->month);
        printf("\nEnter year :");
        scanf(" %d",&eptr->year);

        int d = eptr->date ;
        int m = eptr->month ;
        int y = eptr->year ;

        while( (d<1 || d>31) || (d==31 && (m==2||m==4||m==6||m==9||m==11)) || (d==29 && m==2 && y%4!=0) || (d>29 && m==2) || (y<2000 || y>2019) || (m>12 || m<1))    //This while loop checks all the constraint to be used to enter the date month and year
        {
            printf("\nInvalid Input .Enter date again :");
            printf("\nEnter date :") ;
            scanf( " %d",&eptr->date);
            printf("\nEnter month :");
            scanf(" %d",&eptr->month);
            printf("\nEnter year :");
            scanf(" %d",&eptr->year);

            d = eptr->date ;
            m = eptr->month ;
            y = eptr->year ;
        }

        printf("Enter Material of part %d :",i+1);    //Prompt to the user enter the material to be used
        scanf(" %s",&(eptr->material));

        while( strcmp(eptr->material,"steel")!=0 && strcmp(eptr->material,"iron")!=0 && strcmp(eptr->material,"Steel")!=0 && strcmp(eptr->material,"Iron")!=0)    //This while loop chekcs that the material entered is steel or iron only
        {
             printf("\nInvalid Input .Only Steel and Iron are accepted.Enter again :");
             scanf(" %s",&(eptr->material));
        }

        printf("Enter the weight of the part %d :", i+1);    // Prompt to the user ot enter the weight of the material
        scanf(" %d", &eptr->weight);

        while(eptr->weight <1 || eptr->weight>10)    //This while loop checks that the weight entered is not less than 1 or greater than 10
        {
             printf("Invalid Input. Weight should be between 1 to 10 kgs .Enter Again :");
             scanf(" %d", &eptr->weight);
        }

     }
     printf("\nSerial number where weight is more than 5kg :");    //From here the call to the functions starts for the desired operations

     for(int i = 0 ;i<j ; ++i)    // Call to the function to find the serial number of the parts having weight more than 5 kg
     {
         eptr = &engp[i];
         WLT5(eptr);
     }

     if(t==0)
     {
          printf("No entries found!!");
     }

     printf("\nYear of manufacture of parts having serial number between AA2 and BB7 :");
     for(int i = 0 ;i<j ; ++i)    //Call to the function to find the year of manufacture of parts having serial number between AA2 and BB7
     {
         eptr = &engp[i];
         YMI(eptr);
     }

     if(v==0)
     {
          printf("No entries found!!");
     }

     printf("\nDetails of the part manufactured within three years of 15th November 2019 : \n");
     for(int i = 0 ;i<j ; ++i)    // Call to the function to find the details of the componenents manufactured within three years of 15th November 2019
     {
         eptr = &engp[i];
         EPI(eptr);
     }
     if(b==0)
     {
          printf("No entries found!!");
     }
}

void WLT5(EP *egp1)    // Function definition
{
    if(egp1->weight>5)    // Simple if statement to see if the weight is more than 5 or not
    {
        puts(egp1->sernum);
        t = 1;
    }

}

void YMI( EP *egp2)    //Function definition
{
    if(egp2->k >= AA2 && egp2->k <= BB7)    //If statement to checks the serial number of the parts
    {
         printf("%d",egp2->year);
         v=1;
    }
}

void EPI( EP *egp3)    //Function definition
{
     if(egp3->year==2017 || egp3->year==2018)    // For the years 2017 and 2018 we have no restriction on the dates and months and hence they can be simply printed
     {
          b=1;
          printf("\nSerial number of the part :");
          puts(egp3->sernum);
          printf("Date of manufacture :%d-%d-%d ",egp3->date,egp3->month,egp3->year);
          printf("\nMaterial of the part :");
          puts(egp3->material);
          printf("Weight of the material :%d",egp3->weight);
          printf("\n");
     }
     else if(egp3->year == 2016)    // For the year 2016 we cant show details for the days before 15 november 2016 .Hence the nested if statement constraint the output.
     {
          if(egp3->month<11)
          {;}
          else if(egp3->month==11 && egp3->date<15)
          {;}
          else
          {
               b=1;
               printf("\nSerial number of the part :");
               puts(egp3->sernum);
               printf("Date of manufacture :%d-%d-%d ",egp3->date,egp3->month,egp3->year);
               printf("\nMaterial of the part :");
               puts(egp3->material);
               printf("Weight of the material :%d",egp3->weight);
               printf("\n");
          }
     }
     else if(egp3->year == 2019)    //Similar as in the case of year 2016
     {

          if(egp3->month>11)
          {;}
          else if(egp3->month==11 && egp3->date > 15)
          {;}
          else
          {
               b=1;
               printf("\nSerial number of the part :");
               puts(egp3->sernum);
               printf("Date of manufacture :%d-%d-%d ",egp3->date,egp3->month,egp3->year);
               printf("\nMaterial of the part :");
               puts(egp3->material);
               printf("Weight of the material :%d",egp3->weight);
               printf("\n");
          }
     }

}
























