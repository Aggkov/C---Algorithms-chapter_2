#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define SIZE 1000

void init_array(int *array, int n, int a, int b);
void print_array(int *array, int n);
void swap(int *a, int *b);
void selection_sort(int *array, int n);


int main()
{
    int array[SIZE];
    int N = 15;



    // 1. Arxikopoiisi pinaka 20 thesewn me tuxaioys arithmous apo 1 ews 50

    init_array(array,N,1,50);

    // ektipwsi pinaka

    printf("\t\tEpeidiksi SELECTION SORT\n\n");
    printf("Arxi  : ");
    print_array(array,N);


    // Taksinomisi pinaka


    selection_sort(array,N);

    printf("\n\nTelos  : ");
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

void selection_sort(int *array, int n)
{
    for(int i = 0; i < n; i++)
    {
        int pos = i;

        for(int j = i + 1; j < n; j++)
        {
            if(array[j] < array[pos])
                pos = j;
        }
        swap(&array[i], &array[pos]);
    }
}