#include <stdio.h>
#include <stdlib.h>

#define MAX 8
#define SWAP(x,y) t = x; x = y; y = t;

void compare();
void bitonicmerge(int, int, int);
void recbitonic(int, int, int);
void sort();

int data[MAX];
int up = 1;
int down = 0;

int main()

{

    int i;
 

    printf("\nEnter the data");

    for (i = 0;i < MAX ;i++)
    {
        scanf("%d", &data[i]);
    }

    sort();

    for (i = 0;i < MAX;i++)
    {
        printf("%d ", data[i]);
    }

}


void compare(int i, int j, int dir)
{

    int t;

    if (dir == (data[i] > data[j]))
    {
        SWAP(data[i], data[j]);
    }
}


void bitonicmerge(int low, int c, int dir)
{

    int k, i;

    if (c > 1)
    {
         k = c / 2;

        for (i = low;i < low+k ;i++)

            compare(i, i+k, dir);    

        bitonicmerge(low, k, dir);

        bitonicmerge(low+k, k, dir);    
    }
}

void recbitonic(int low, int c, int dir)
{
    int k;

    if (c > 1)
    {

        k = c / 2;

        recbitonic(low, k, up);

        recbitonic(low + k, k, down);

        bitonicmerge(low, c, dir);

    }
}

 
void sort()
{
    recbitonic(0, MAX, up);
}
