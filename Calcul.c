#include<stdio.h>
#include<math.h>

int main(){
int Mode;
    //variable declaration :
Code:

    printf("\n\t\t\t\t1) Basic calculator    2) 1st degree equation    \n\n\t\t\t\t3) 2nd degree equation    4)Other operation\n");
    printf("\n\t\t\t\t\t  Please chose your Mode: ");
    scanf("%d", &Mode);
    while(Mode < 1 || Mode > 4) {
                printf("\n\t\t\t\t\t\t  Error!!\n");
                printf("\n\t\t\t\t    Please select a number from 1 to 4: ");
                scanf("%d", &Mode);
    }
    //Operation Mode
    // 1)calculator :
    if( Mode == 1) {

            float X, Y, Result;
            int Op ;
            printf("\n\t\t\t\t------------Welcome to Basic calculator------------\n");
            printf("\n\t\t\t\t\t1) addition    2) subtraction \n\n\t\t\t\t\t3) multiplication    4) division \n");
            printf("\n\t\t\t\t\tplease choose Operation : ");
            scanf("%d", &Op);

            while(Op < 1 || Op > 4) {
                printf("\n\t\t\t\t\t\t  Error!!\n");
                printf("Please select a number from 1 to 4: ");
                scanf("%d", &Op);
            }

            printf("input X value : ");
            scanf("%f", &X);
            printf("input Y value : ");
            scanf("%f", &Y);

                if( Op == 1 ) {
                printf("\n\t\t\t\tyou chose addition ");
                Result = X + Y;
                }
                else if( Op == 2 ) {
                printf("\n\t\t\t\tyou chose subtraction ");
                Result = X - Y;
                }
                else if( Op == 3 ) {
                printf("\n\t\t\t\tyou chose multiplication ");
                Result = X * Y;
                }
                else if( Op == 4 ) {
                printf("\n\t\t\t\tyou chose division ");
                Result = X / Y;
                }
        printf("and your result is : %.2f", Result);
    }

    //2) equation 1er degrée:
    float a, b ,c ;
        float X;
    if ( Mode == 2 ){
            printf("Equation form: aX+b = c\n");
            printf("input a value : ");
            scanf("%f", &a);
            printf("input b value : ");
            scanf("%f", &b);
            printf("input c value : ");
            scanf("%f", &c);
            printf("your solution is : %.2f", X= (c-b)/a);
    }

    //3) equation 2eme degrée:

    else if ( Mode == 3 ) {
            float a, b ,c ;
            float  X ,X1, X2, DEL ;
            printf("Equation form: aX^2+bX+c = 0\n");
            printf("input a value : ");
            scanf("%f", &a);
            printf("input b value : ");
            scanf("%f", &b);
            printf("input c value : ");
            scanf("%f", &c);
            DEL = pow(b,2) - 4*a*c;
            printf("DELTA = %f\n", DEL);
            if( DEL > 0 ) {
                X1 = (-b+sqrt(DEL))/(2*a);
                X2 = (-b-sqrt(DEL))/(2*a);
                printf("X1 value is : %.2f\n", X1);
                printf("X2 value is : %.2f\n", X2);
            }
            else if( DEL == 0 ) {
                X = -b/(2*a);
                printf("X value is : %.2f\n", X);
            }
            else {
                printf("Solution Impossible!!");
            }

    }
    //4) Calcul trigonomitrique:
    else if ( Mode == 4 ) {
            float ang;
            float Result;
            int tri;
            printf("what is your angle? : ");
            scanf("%f", &ang);
            printf("1)cos        2)sin\n3)tan        4)log\n");
            printf("Which operation do you want? : ");
            scanf("%d",&tri);
            while(tri < 1 || tri > 4) {
                printf("Error!!\n");
                printf("Make sure you select an operation from above !");
                scanf("%d", &tri);
            }
                if( tri == 1 ) {
                printf("you chose cos ");
                Result = cos(ang);
                }
                else if( tri == 2 ) {
                printf("you chose sin ");
                Result = sin(ang);
                }
                else if( tri == 3 ) {
                printf("you chose tan ");
                Result = tan(ang);
                }
                else if( tri == 4 ) {
                printf("you chose log ");
                Result = log(ang);
                }
        printf("and your result is : %.2f", Result);
    }
    //process repeat
    char conf;
repeat:
    printf("\n\t\t\t\t\tDo you wanna repeat without exit? (Y/N)");
    scanf("%c", &conf);
    if (conf == 'y' || conf == 'Y') {
        goto Code;
    }
    else if (conf == 'n' || conf == 'N'){
        return 0;
    }
    else {
        printf("\n\t\t\t\t\tPlease enter Y or N.\n");
        goto repeat;
    }

 return 0;

}

