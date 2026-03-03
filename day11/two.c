#include <stdio.h>

int main(){

    // Two Dimensional arrays are the arrays which have two kinds of element numbers.Defined as number of rows and number of columns

    int table[5][7];
    int rows = sizeof(table) / sizeof(table[0]);
    int cols = sizeof(table[0]) / sizeof(table[0][0]);

    printf("This table will have %drows and %dcolumns\n",rows,cols);
    // The table will have 3 rows and 2 columns.

    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            int num;
            printf("Enter the value of row %d and column %d:",i+1,j+1);
            scanf("%d",&table[i][j]);
        }
    }

    printf("Data you entered:\n");

    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++ ) {
            printf("%d\t",table[i][j]);
        }
        printf("\n");
    }


    return 0;
}
