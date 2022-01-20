#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define SIZE 100

void init_array(int *array, int n, int a, int b);
void print_array(int *array, int n);
void swap(int *a, int *b);
void mergesort(int *array, int start, int finish);
void merge(int *array, int start, int finish);


int main()
{
    int array[SIZE];
    int N = 15;



    // 1. Arxikopoiisi pinaka 15 thesewn me tuxaioys arithmous apo 1 ews 50

    init_array(array,N,1,50);

    // ektipwsi pinaka

    printf("\t\tEpeidiksi MERGE SORT\n\n");
    printf("Arxi  : ");
    print_array(array,N);


    // Taksinomisi pinaka

    mergesort(array,0,N - 1);

    printf("\n\nTelos : ");
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

void mergesort(int *array, int start, int finish)
{
    int middle;

    if(start == finish)                         // RECURSION
        return;
    else if(start == finish - 1)
    {
        if(array[start] < array[finish])
            swap(&array[start], &array[finish]);
    }
    else
    {
        middle = (start + finish) / 2;
        mergesort(array, start, middle);
        mergesort(array,middle + 1,finish);
        merge(array,start,finish);

    }
}

void merge(int *array, int start, int finish)
{
    int C[SIZE];
    int middle = (start + finish) / 2;

    int i = start;
    int n = middle;              // 1os pinakas

    int j = middle + 1;          // 2os pinakas
    int m = finish;


    int k = 0;                  // metavliti C pinaka
    while(i <= n && j <= m)     // Merge 2 arrays
    {
        if(array[i] > array[j])
        {
            C[k] = array[i];
            k++;
            i++;
        }

        else
        {
            C[k] = array[j];
            k++;
            j++;
        }

    }
                        // Antigrafi pinaka pou perisseuei 
    if(i == n + 1)      // Eksantlithike o 1os pinakas
    {
        while(j <= m)
        {
            C[k] = array[j];
            k++;
            j++;
        }
    }
    else                     // Eksantlithike o 2os pinakas
        {
            while(i <= n)
            {
                C[k] = array[i];
                k++;
                i++;
            }
        }
    // 3. Antigrafi tou C ston pinaka

    k = 0;

	i = start;
	while(i <= finish)
	{
		array[i] = C[k];
		i++;
		k++;
	}


}