#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void init_array(int *array, int n, int a, int b);
void print_array(int *array, int n);
void copy_array(int *dest, int *source,int n);
void swap(int *a, int *b);
int selection_sort(int *array,int n);
int insertion_sort(int *array,int n);
int bubble_sort(int *array,int n);
void mergesort(int *array, int start, int finish,int *count);
void merge(int *array, int start, int finish,int *count);
void quicksort(int *array, int start, int finish,int *count);
int partition(int *array,int start,int finish,int *count);

int main()
{
    int array[SIZE];
    int source[SIZE];
    int N = 50;
    int count;


    init_array(source,N,0,1000);
    printf("SELECTION_SORT\n\n");

    copy_array(array,source,N);

    count = selection_sort(array,N);
    print_array(array,N);

    printf("\nAmount of counts: %d",count);


    printf("\n\n----------------------\n");


    printf("\n\nINSERTION_SORT\n");

    copy_array(array,source,N);

    count = insertion_sort(array,N);
    print_array(array,N);

    printf("\n\nAmount of comparisons: %d", count);

    printf("\n\n----------------------\n\n");


    printf("BUBBLE SORT\n\n");
    copy_array(array,source,N);
    count = bubble_sort(array,N);
    print_array(array,N);

    printf("\n\nAmount of comparisons: %d", count);

    printf("\n\n-----------------------\n\n");


    printf("MERGE SORT\n\n");
    copy_array(array,source,N);
    count = 0;
    mergesort(array,0,N - 1, &count);
    printf("Count: %d", count);

    printf("\n\n-----------------------\n\n");


    printf("QUICK SORT\n\n");
    copy_array(array,source,N);
    count = 0;
    quicksort(array,0, N - 1, &count);
    printf("Count: %d", count);



}


void init_array(int *array, int n, int a, int b)
{
    srand(time(NULL));

    for(int i = 0; i < n; i++)
    {
        array[i] = rand()%999;
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

void copy_array(int *dest, int *source,int n)
{
    for(int i = 0; i < n; i++)
    {
        dest[i] = source[i];
    }
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


int selection_sort(int *array,int n)
{
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        int pos = i;

        for(int j = i + 1; j < n; j++)
        {
            count++;
            if(array[j] < array[pos])
            {
                pos = j;
            }
        }
        swap(&array[i], &array[pos]);

    }
    return count;
}

int insertion_sort(int *array,int n)
{
    int count = 0;

    for(int i = 1; i < n; i++)
    {
        for(int j = i; j >= 1; j--)
        {
            count++;
            if(array[j] < array[j - 1])
            {

                swap(&array[j], &array[j - 1]);
            }


            else
                break;
        }
    }
    return count;
}

int bubble_sort(int *array,int n)
{
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = n - 1; j >= i + 1; j--)
        {
            count++;
            if(array[j] < array[j - 1])
            {

                swap(&array[j], &array[j - 1]);
            }

        }
    }
    return count;

}

void mergesort(int *array, int start, int finish, int *count)
{

    int middle;

    if(start == finish)
    {
        return;
    }

    else if(start == finish - 1)
    {
        (*count)++;
        if(array[start] > array[finish])
        {

            swap(&array[start], &array[finish]);
        }

    }
    else
    {
        middle = (start + finish) / 2;
        mergesort(array, start, middle, count);
        mergesort(array,middle + 1,finish,count);
        merge(array,start,finish,count);

    }

}

void merge(int *array, int start, int finish,int *count)
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
        (*count)++;
        if(array[i] < array[j])
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

void quicksort(int *array, int start, int finish,int *count)
{

    int pos;                                // Guide Point

    if(start < finish)
    {

        pos = partition(array,start,finish,count);
        quicksort(array,start,pos - 1, count);
        quicksort(array,pos + 1, finish ,count);
    }

}

int partition(int *array,int start,int finish,int *count)      // Sorts elements smaller than pivot to the left pivot and bigger to the right
{

    int pivot = array[start];
    int i = start + 1;
    int j = finish;

    while(1)
    {
        (*count)++;
        while(array[i] <= pivot && i <= finish)
        {
            i++;
            (*count)++;

        }

        while(array[j] > pivot && j >= start)
        {
            j--;
            (*count)++;
        }


        if(i < j)
            swap(&array[i], &array[j]);

        else
        {
            swap(&array[start], &array[j]);
            return j;
        }
    }

}