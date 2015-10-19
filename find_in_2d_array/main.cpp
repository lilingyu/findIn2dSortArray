//
//  main.cpp
//  find_in_2d_array
//
//  Created by LiLingyu on 15/10/19.
//  Copyright © 2015年 LiLingyu. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include <time.h>

bool find_in_2d_array(int *a, int rows, int columns, int number)
{
    bool result = false;
    
    assert(NULL != a && rows>0 && columns>0);
    
    int x=columns-1, y=0;
    while (y<rows && x>=0) {
        if (a[y*columns+x]==number) {
            return true;
        }
        else if(a[y*columns+x]>number)
        {
            x--;
        }
        else
        {
            y++;
        }
    }
    
    return result;
}
static inline int max(int a, int b)
{
    return (a>b)?a:b;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    const int COLUMNS = 4;
    const int ROWS = 4;
    int a[COLUMNS*ROWS];
    
    srand((unsigned int)time(NULL));
    
    
    for (int i=0; i<ROWS*COLUMNS; i++) {
        a[i] = rand()%(ROWS*COLUMNS);
    }
    
    a[0]=rand()%(COLUMNS*ROWS);
    for (int i=1; i<COLUMNS; i++) {
        a[i] = a[i-1]+rand()%3;
    }
    
    for (int i=1; i<ROWS; i++) {
        a[i*COLUMNS]=a[(i-1)*COLUMNS]+rand()%3;
    }
    
    for (int y=1; y<ROWS; y++) {
        for (int x=1; x<COLUMNS; x++) {
            a[y*COLUMNS+x] = max(a[(y-1)*COLUMNS+x],a[y*COLUMNS+x-1])+rand()%3;
        }
    }
    
    
    int number = rand()%(ROWS*COLUMNS);
    
    printf("number: %d\n", number);
    printf("array:\n");
    for (int y=0; y<ROWS; y++) {
        for (int x=0; x<COLUMNS; x++) {
            printf("%d\t", a[y*COLUMNS+x]);
        }
        printf("\n");
    }
    printf("answer:\t");
    printf("%d\n", find_in_2d_array(a, ROWS, COLUMNS, number));
    
    return 0;
}
