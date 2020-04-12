#include<stdio.h>
#include <string.h>

// car number minimum 3 digit
//small car position 1-6  31-36    BigCar  position  13-24

int smallCarPos(int,int);
int bigCarPos(int,int);
void displayRowColumn();
double parkChargeS(int,int);
double parkChargeB(int,int);
int carSearch(int);
int parkingSize[6][6];
FILE *q ;
struct CarParking
{
 char Car[20];
 int num;
 double charge;
 int hr,min;
 };


int main(){

    q = fopen("car.txt", "w+");
    struct CarParking C[30];

    char name[20];
    int number,position,hours,minutes;

    int TotalCar;
    int i,j,s=1,numberOfCar=0,a,temp;
    double chr;

    for( i=0;i<6;i++){
           for(j=0;j<6;j++){
            if(i==0 || i==5){
                parkingSize[i][j]=s;
                s++;
            }
            else if(i==2 || i==3){
                parkingSize[i][j]=s;
                s++;
            }
            else{
                parkingSize[i][j]=0;
                s++;
            }
           }
    }

    int p;
    while(1){
        printf("CAR PARKING SYSTEM\n");

        printf("1.ENTRY CAR\n");
        printf("2.TOTAL CAR PARKED\n");
        printf("3.FREE ROW AND COLUM\n");
        printf("4.CAR EXIT\n");
        printf("5.ALL INFORMATION\n");
        printf("PRESS 1 TO 5 AND 0 FOR EXIT\n");
        scanf("%d",&p);

     switch(p) {
      case 1 :
         printf("1.Small Car\n" );
         printf("2.Large Car\n" );
         printf("0.Main\n" );
         printf("PRESS 0 TO 2\n");
         scanf("%d",&p);
         if(p==1){
             printf("ENTER  CAR MODEL\n" );
             scanf("%s",name);
             strcpy( C[numberOfCar].Car,name);



             printf("ENTER  CAR NUMBER\n" );
             scanf("%d",&number);
             C[numberOfCar].num=number;
             op1:
             printf("small car position 1-6.\n");
             printf("ENTER  THE POSITION YOU WANTED TO PARK\n" );
             scanf("%d",&position);

             fprintf(q,"Car Name:%s\nCar Number:%d\nCar Position:%d\n ", name, number, position);

             int pos = smallCarPos(position,number);
             if(pos==1){
                printf("YOU CAN PARK THIS CAR\n");
             }
             else{
                printf("YOU NEED TO CHOSE OTHER POSITION\n");
                 goto op1;
             }

            printf("PARKING CHARGE 0.40 TAKA PER MINUTE\n");
            h1:
            printf("HOW MANY HOURES WILL YOU NEED \n");
            scanf("%d",&hours);

            if(hours>12){
                printf("Invalid\n");
                goto h1;
            }
            m1:
            printf("HOW MANY MINUTES WILL YOU NEED \n");
            scanf("%d",&minutes);

            if(minutes>60){
                printf("Invalid\n");
                goto m1;
            }

            C[numberOfCar].hr=hours;
            C[numberOfCar].min=minutes;
            chr = parkChargeS(hours,minutes);
            C[numberOfCar].charge=chr;

            numberOfCar++;
            printf("CAR PARKING SUCCESSFULLY\n");
            fprintf(q,"Time:\n");
            fprintf(q,"Hours:%d\nMinutes:%d\n",hours,minutes);
         }
         else if(p==2){
            printf("ENTER  CAR MODEL\n" );
            scanf("%s",name);
            strcpy(  C[numberOfCar].Car,name);

            printf("ENTER  CAR NUMBER\n" );
            scanf("%d",&number);
            C[numberOfCar].num=number;

            op2:
            printf("BigCar  position  13-24.\n");
            printf("ENTER  THE POSITION YOU WANTED TO PARK\n" );
            scanf("%d",&position);

            fprintf(q,"Car Name:%s\nCar Number:%d\nCar Position:%d\n ", name, number, position);

            int pos = bigCarPos(position,number);
            if(pos==1){
                printf("YOU CAN PARK THIS CAR\n");
             }
             else{
                printf("YOU NEED TO CHOSE OTHER POSITION\n");
                 goto op2;
             }

            h2:
            printf("PARKING CHARGE 0.50 TAKA PER MINUTE\n");
            printf("HOW MANY HOURES WILL YOU NEED \n");
            scanf("%d",&hours);

            if(hours>12){
                printf("Invalid\n");
                goto h2;
            }

            m2:
            printf("HOW MANY MINUTES WILL YOU NEED \n");
            scanf("%d",&minutes);
            if(minutes>60){
                printf("Invalid\n");
                goto m2;
            }


            C[numberOfCar].hr=hours;
            C[numberOfCar].min=minutes;
            chr = parkChargeB(hours,minutes);
            C[numberOfCar].charge=chr;

            printf("CAR PARKING SUCCESSFULLY\n");
            numberOfCar++;
            fprintf(q,"Time:\n");
            fprintf(q,"Hours:%d\nMinutes:%d\n",hours,minutes);

         }

         break;
      case 2 :
            printf("TOTAL CAR PARKED %d\n",numberOfCar);
            break;
      case 3 :
         printf("ONE OR TWO DIGITS NUMBER ARE FREE &  ZERO IS EMPTY SPACE\n" );
         displayRowColumn();
         break;
      case 4 :
         printf("ENTER THE NUMBER OF YOUR CAR\n" );
         int id;
         scanf("%d",&id);
         int found= carSearch(id);

         for( a =0;a<numberOfCar;a++){
            if( C[a].num==id){
                temp=a;
                break;
            }
         }

         if(found!=0){
            printf("YOU HAVE TO PAY %0.2f Taka\n",C[temp].charge);
            fprintf(q,"Taka:%.2f\n",C[temp].charge);
         }
         else{
              printf("INVALID NUMBER\n");
         }
         break;
      case 5 :
          printf("NO. CAR NAME      NUMBER    HOURS     MINUTES     CHARGE\n");
           for( a =0;a<numberOfCar;a++){
            printf("%d . ",a+1);
            printf("%-14s %-9d %-9d %-11d %-16.2f",C[a].Car,C[a].num,C[a].hr,C[a].min,C[a].charge);
            printf("\n\n");
            }


         break;
      case 0 :
            return 0;
      default :
         printf("Invalid \n" );
     }


    printf("\n\n\n" );
    }

   return 0;


}

int smallCarPos(int n,int num){
    int i,j;

     for( i=0;i<6;i++){
           for(j=0;j<6;j++){
            if( (parkingSize[i][j]>=1 &&  parkingSize[i][j]<=6) || (parkingSize[i][j]>=31 &&  parkingSize[i][j]<=36)){
                if(parkingSize[i][j]==n){
                   parkingSize[i][j]=num;
                    return 1;
                   }
            }

           }
    }
    return 0;

}

int bigCarPos(int n, int num){
    int i,j;

     for( i=0;i<6;i++){
           for(j=0;j<6;j++){
            if( (parkingSize[i][j]>=13 &&  parkingSize[i][j]<=24) ){
                if(parkingSize[i][j]==n){
                   parkingSize[i][j]=num;
                    return 1;
                   }
            }

           }
    }
    return 0;


}
int carSearch(int cnum){
    int i,j,k=0,s=1,temp;
     for( i=0;i<6;i++){
           for(j=0;j<6;j++){
            if( parkingSize[i][j]==cnum ){

                    parkingSize[i][j]=-5;
                    k++;

                    break;
                   }
            }

           }
     for( i=0;i<6;i++){
           for(j=0;j<6;j++){
            if( parkingSize[i][j]==-5){
                parkingSize[i][j]=s;
                break;
            }
            s++;
           }
    }

    return k;

}
void displayRowColumn(){
    int i,j;
    for( i=0;i<6;i++){
           for(j=0;j<6;j++){
                printf("%10d",parkingSize[i][j]);
           }
           printf("\n");
           printf("\n");
           printf("\n");
    }


}

double parkChargeS(int h,int m){
  int totalMin= h*60 + m;
  double totalTk= totalMin*0.40;
  return totalTk;


}
double parkChargeB(int h,int m){
  int totalMin= h*60 + m;
  double totalTk= totalMin*0.50;
return totalTk;
fclose(q);

}

