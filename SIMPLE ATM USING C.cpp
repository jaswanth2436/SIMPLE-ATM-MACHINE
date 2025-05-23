#include <stdio.h>

int main() {
int password = 2437;
int  option , deposit , withdrawl , balance = 100000 ;
printf("enter your password : ");
scanf("%d" , &password);
if( password==2437){

    printf("Select your option:\n");
    printf("1.deposit\n");
    printf("2.withdrawl\n");
    printf("3.check balance\n");
    printf("4.cancel\n");
    
    scanf("%d", &option);

switch(option){
    case 1 :
     printf("Enter the money to deposit :\n");
     scanf("%d", &deposit);
     balance = balance + deposit;
     printf("your Total balance = %d",balance);
     break;
     case 2 :
     printf("Enter the money to withdrawl :\n");
     scanf("%d" , &withdrawl);
     balance = balance - withdrawl;
     printf(" Your remaining balance :%d",balance);
     break;
     case 3 :
     printf( "Total amount : 100000\n");
     break;
     case 4 :
     printf("thanks for visiting our atm\n");
    break;
    default :
    printf("invalid input");
}
}
else 
printf("Incorrect password");

printf("\n*************** THANK YOU FOR VISITING COME AGAIN ******************");

    return 0;
}