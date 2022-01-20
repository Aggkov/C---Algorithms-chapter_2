#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define SIZE 100

void init_array(int *array, int n, int a, int b);
void print_array(int *array, int n);
void swap(int *a, int *b);
void quicksort(int *array, int start, int finish);
int partition(int *array,int start,int finish);



int main()
{
    int array[SIZE];
    int N = 15;



    // 1. Arxikopoiisi pinaka 20 thesewn me tuxaioys arithmous apo 1 ews 50

    init_array(array,N,1,50);

    // ektipwsi pinaka

    printf("\t\tEpeidiksi QUICK SORT\n\n");
    printf("Arxi  : ");
    print_array(array,N);


    // Taksinomisi pinaka

    quicksort(array,0,N - 1);

    printf("\n\nTELOS  : ");
    print_array(array,N);



}


void init_array(int *array, int n, int a, int b)
{
    srand(time(NULL));

    for(int i = 0; i < n; i++)
    {
        array[i] = a+rand()%(b-a+1);
    }
}

void print_array(int *array, int n)
{
    printf("[");
    for(int i = 0; i < n - 1; i++)
    {
        printf("%d ", array[i]);

    }
    printf("%d]", array[n - 1]);

}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int *array, int start, int finish)
{
    int pos;                                // Guide Point

    if(start < finish)
    {
        pos = partition(array,start,finish);
        quicksort(array,start,pos - 1);
        quicksort(array,pos + 1, finish);
    }
}

int partition(int *array,int start,int finish)      // Sorts elements smaller than pivot to the left pivot and bigger to the right
{
    int pivot = array[start];
    int i = start + 1;
    int j = finish;

    while(1)
    {
        while(array[i] <= pivot && i <= finish)
            i++;

        while(array[j] > pivot && j >= start)
            j--;

        if(i < j)
            swap(&array[i], &array[j]);

        else
        {
            swap(&array[start], &array[j]);
            return j;
        }
    }


}