#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define SIZE 1000

void init_array(double *array, int n, int a, int b);
void print_array(double *array, int n);
void swap(double *a, double *b);
void bubble_sort(double *array,int n);


int main()
{
    double array[SIZE];
    int N = 15;



    // 1. Arxikopoiisi pinaka 20 thesewn me tuxaioys arithmous apo 1 ews 50

    init_array(array,N,1,50);

    // ektipwsi pinaka

    printf("\t\tEpeidiksi BUBBLE SORT\n\n");
    printf("Arxi  : ");
    print_array(array,N);


    // Taksinomisi pinaka

    bubble_sort(array,N);

    printf("\n\nTelos : ");
    print_array(array,N);

}

void init_array(double *array, int n, int a, int b)
{
    srand(time(NULL));

    for(int i = 0; i < n; i++)
    {
        array[i] = a+rand()%(b-a + 1) + rand()%100/ 100.0;      //Add another number from 0 to 99 and divide him with a real number (100.0) (rand()%100
    }
}

void print_array(double *array, int n)
{
    printf("[");
    for(int i = 0; i < n - 1; i++)
    {
        printf("%2.2lf ", array[i]);

    }
    printf("%2.2lf]", array[n - 1]);

}

void swap(double *a, double *b)
{
    double temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(double *array,int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = n - 1; j >= i + 1; j--)
        {
            if(array[j] < array[j - 1])
                swap(&array[j], &array[j - 1]);
        }
    }

}