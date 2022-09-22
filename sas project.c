#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct Product {
    long int code ;
    char name [20];
    int quantity;
    float price;
    float price_TTC;
}prd;
typedef struct prsProduct {
    long int code ;
    char name [20];
    int quantity;
    float price_TTC;
    int day, month , year ;
}prsprd;

    prd p[5000];
    prsprd pp[5000];

    int op ;
    int counter = 0;
    int i,j;
    prd temp;

// functions prototyping:

    void addproduct();
    void addproducts();
    void showproducts();
    void sortbyprice();
    void sortbyname();
    void searchproducts();
    void searchsortcode();
    void searchsortquantity();
    void buyproduct();
    void addstock();


int main() {

    //variables

    while(1){

        //interface graphique;
        printf("\t\t\t\t\t\t========Pharmacy========\t\t\t\t\t\t\n");
        printf("\t\t\t\t\t     which operation do you desire?\t\t\t\t\t\n");
        printf("\n\t\t\t1)Add a product.        2)Add multiple products.        3)Show product list.\n");
        printf("\n\t\t\t4)Buy a product.        5)Search for a product.         6)Display stock status.\n");
        printf("\n\t\t\t7)Add to stock.         8)Delete a product.             9)Selling statistics.\n");
        printf("\n\t\t\t\t\t=======================================\n");
        printf("\t\t\t\t\ttype the number of the operation : ");
        scanf("%d", &op);
        // Prix TTC
        for (i = 0; i< counter ; i++){
            p[i].price_TTC =  p[i].price * 1.15;
        }

        //Add a product
        if ( op == 1) {

            addproduct();
        }

        //Add multiple products
        else if ( op == 2) {

            addproducts();
        }

        //Show product list
        else if ( op == 3) {

            showproducts();
        }
        //Buy a product
        else if ( op == 4) {

            buyproduct();
        }
        //Search for a product
        else if ( op == 5) {

            searchproducts();
        }
        //Stock
        else if ( op == 6) {
           /* int less ;
            for( i = 0; i < counter; i++){
                if( less <= 3 && less == p[i].quantity ){
                    printf("\n> Product code : %ld",p[i].code);
                    printf("\n> Product name : %s",p[i].name);
                    printf("\n> Product quantity : %d",p[i].quantity);
                    printf("\n> Product price : %.2f ",p[i].price_TTC);
                    printf("\n\t\t\t\t\t_________________________________\n");

                }
            }*/
    int c = 0;
    for( i = 0; i < counter; i++){
        if( p[i].quantity < 3){
        printf("\n> Product code : %ld",p[i].code);
        printf("\n> Product name : %s",p[i].name);
        printf("\n> Product quantity : %d",p[i].quantity);
        printf("\n> Product price : %.2f ",p[i].price_TTC);
        printf("\n\t\t\t\t\t_________________________________\n");
        c++;
        }
        if (c == 0){
            printf("all products are stocked!");
        }
    }}
        //Add to stock
        else if ( op == 7) {

            addstock();
        }
        //Delete a product
        else if ( op == 8) {
            long int code ;
            printf("please insert the product code desired : ");
            scanf("%ld", &code);
            for(i = 0 ;i < counter ;i++){
                if( p[i].code == code ){
                    for(j = i ;j < counter ;j++ ){
                        p[j] = p[j+1];}

                    printf("\n\t\t\t\t\t======Product deleted successfully!======\n");
                    counter--;

                }
            }
         }
        //selling statistics
        else if ( op == 9) {
            float Total;
            for (i = 0 ; i< counter ; i++){
            printf("%d %d %d ",pp[i].day,pp[i].month,pp[i].year);
            printf("product name: %s\n", pp[i].name);
            printf("product code: %ld\n", pp[i].code);
            printf("product quantity: %d\n",pp[i].quantity);
            printf("product price : %.2f \n\n\n",pp[i].price_TTC);
            Total += pp[i].price_TTC;
            printf("the total is : %.2f" , Total);
            }
        }
        //no option from the above
        else {
            printf("10");
        }
        }
return 0;
}

// functions :
void addproduct(){
    printf("\n\t\t\t\t\t> Please fill in product infos < \n");
    printf("\n\t\t\t\t\t> Product code : ");
    scanf("%ld", &p[counter].code);
    printf("\n\t\t\t\t\t> Product name : ");
    scanf("%s", &p[counter].name);
    printf("\n\t\t\t\t\t> Product quantity : ");
    scanf("%d", &p[counter].quantity);
    printf("\n\t\t\t\t\t> Product price : ");
    scanf("%f", &p[counter].price);
    printf("\n\t\t\t\t\t======Product added successfully!======\n");
    counter++;
}

void addproducts(){
    int P_Num;
        printf("how many products do you wanna add ? : ");
        scanf("%d", &P_Num);
        system("cls");
        for( i = counter; i < P_Num + counter; i++){
            printf("\t\t\t\t\t> Please fill in product[%d] infos < \n", i+1-counter);
            printf("\n\t\t\t> Product %d code : ",i+1-counter);
            scanf("%ld", &p[i].code);
            printf("\t\t\t> Product %d name : ",i+1-counter);
            scanf("%s", &p[i].name);
            printf("\t\t\t> Product %d quantity : ",i+1-counter);
            scanf("%d", &p[i].quantity);
            printf("\t\t\t> Product %d price : ",i+1-counter);
            scanf("%f", &p[i].price);
            printf("\n\t\t\t\t\t_________________________________\n");
        }
        printf("\n====Products added successfully!====\n");
        counter += P_Num;
}

void showproducts(){
    int Mode;

    printf("how do you wanna sort your list ?\n");
    printf("1) By name              2) By price ");
    scanf("%d",&Mode);

    switch(Mode) {
    case 1 :
        sortbyname();
        break;
    case 2 :
        sortbyprice();
        break;
}
}

void sortbyname(){
    for ( i = 0; i < counter ; i++){
        for(j= i + 1; j <counter ;j++){
            if (strcmp(p[i].name, p[j].name) ==1){
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    for(i=0;i<counter;i++){
        printf("\n\t\t\t\t Code     : %ld",p[i].code);
        printf("\n\t\t\t\t Product  : %s",p[i].name);
        printf("\n\t\t\t\t Quantity : %d",p[i].quantity);
        printf("\n\t\t\t\t Price    : %.2f",p[i].price_TTC);
        printf("\n\t\t\t\t----------------------------------------------------\n");
    }
}

void sortbyprice(){
    for ( i = 0 ;i<counter ;i++){
            for(j= i + 1; j <counter ;j++){
            if(p[i].price < p[j].price){
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
            }
        }
        for(i =0; i<counter;i++){
            printf("\n\t\t\t\t Code     : %ld",p[i].code);
            printf("\n\t\t\t\t Product  : %s",p[i].name);
            printf("\n\t\t\t\t Quantity : %d",p[i].quantity);
            printf("\n\t\t\t\t Price    : %.2f",p[i].price_TTC);
            printf("\n\t\t\t\t----------------------------------------------------\n");
        }
        }

void searchproducts(){
    int mode;
            printf("Which of the following methods you want to search by ?\n");
            printf("1) Code             2) Quantity   ");
            scanf("%d",&mode);
            switch(mode){

            case 1:
                searchsortcode();
                break;
            case 2 :
                searchsortquantity();
                break;
        }
}

void searchsortcode() {
    long int searchc;
    int c = 0;
    printf("\nPlease enter the code of the product you are looking for : ");
    scanf("%ld", &searchc);
    for (i = 0 ; i < counter; i++){
        if(searchc == p[i].code) {
            printf("\n\t\t\t\t Code     : %ld",p[i].code);
            printf("\n\t\t\t\t Product  : %s",p[i].name);
            printf("\n\t\t\t\t Quantity : %d",p[i].quantity);
            printf("\n\t\t\t\t Price    : %.2f",p[i].price_TTC);
            printf("\n\t\t\t\t----------------------------------------------------\n");
            c++;
        }
    }
    if (c == 0){
        printf("Product not found!\n");
        }
}

void searchsortquantity(){
    int searchq;
    int c = 0;
    printf("\nPlease enter the quantity of the products you are looking for : ");
    scanf("%d", &searchq);
    for( i = 0; i < counter; i++){
        if( searchq == p[i].quantity ){
        printf("\n> Product code : %ld",p[i].code);
        printf("\n> Product name : %s",p[i].name);
        printf("\n> Product quantity : %d",p[i].quantity);
        printf("\n> Product price : %.2f ",p[i].price_TTC);
        printf("\n\t\t\t\t\t_________________________________\n");

        }
    }
    if (c == 0){
        printf("Product not found!\n");
        }
}

void buyproduct(){
     long int code = 0;
     int qty = 0;
buytryagain:
     printf("please insert the product code desired : ");
     scanf("%ld", &code);
     for(i = 0 ;i < counter ;i++){
         if(code!=p[i].code){
             printf("product not found");
             printf("\n_______________________________________________________________________________________\n");
             goto buytryagain;
         }
buyagain:
         if(code == p[i].code){
             printf("%d units available\n",p[i].quantity);
             printf("How many do you desire to buy: ");
             scanf("%d",&qty);

             if(qty <= 0){
                 printf("incompatible value Please try again \n");
                 printf("_______________________________________________________________________________________\n");
                 goto buyagain;

             }
             else if( qty > p[i].quantity){
                 printf("Not enough in stock\n");
                 printf("Please try again after restock\n");
                 printf("_______________________________________________________________________________________\n");

             }
             else if(qty <= p[i].quantity ){
                 p[i].quantity = p[i].quantity - qty;
                 printf("\n purchase successful \n");
                 printf("_______________________________________________________________________________________\n");
                 timer();
                    p[i].name == pp[i].name;
                    p[i].code == pp[i].code;
                    qty == p[i].quantity;
                    p[i].price_TTC == pp[i].price_TTC * qty;
             }
         }
     }
}

void addstock(){
        long int code = 0;
        int qty = 0;
addtryagain:
        printf("please insert the product code desired : ");
        scanf("%ld", &code);
        for(i = 0 ;i < counter ;i++){
            if(code!=p[i].code){
                printf("product not found");
                printf("\n_______________________________________________________________________________________\n");
                goto addtryagain;
            }
addagain:
            if(code == p[i].code){
                printf("%d units available\n",p[i].quantity);
                printf("How many products do you desire to add: ");
                scanf("%d",&qty);

                if(qty <= 0){
                    printf("incompatible value Please try again \n");
                    printf("_______________________________________________________________________________________\n");
                    goto addagain;

                }
                else {
                    p[i].quantity = p[i].quantity + qty;
                    printf("\n Quantity added successfully \n");
                    printf("_______________________________________________________________________________________\n");

                }
            }
        }
}

void timer () {
   time_t rawtime;
   struct tm *info;
   time( &rawtime );
   info = localtime( &rawtime );
   printf("Date d'achat: %s", asctime(info));
}
