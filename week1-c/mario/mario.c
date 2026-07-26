#include<stdio.h>
#include<cs50.h>


int main(void){
int height, row, column;
int sizeOfHole = 2;
    do
    {
   height = get_int("height\n");
    }
     while (height < 1 || height > 8);

    for (row=0; row < height; row++)
    {

        for ( int space=0; space <= height - row - 2; space++) {
                printf(" ");
        }

        for (column=0; column <= row; column++ ) {
            printf("#");
        }

        for (int hole =0; hole < sizeOfHole; hole++) {
            printf(" ");
        }


        for (column=0; column <= row; column++ ) {
            printf("#");
        }
    printf("\n");
    }


    }
