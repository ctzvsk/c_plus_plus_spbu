#include <iostream>
#include <ctime>
#include <cstring> 
using namespace std;

const int init_len = 180;
const int length = 100;

void array_swap(int& el1, int& el2)
{
    int tmp = el1;
    el1 = el2;
    el2 = tmp;
}

void array_shuffle(int* arr, int arr_length)
{
    srand(time(0));
    for (int k = arr_length - 1; k >= 0; k--)
        array_swap(arr[k], arr[rand() % 100]);
}

int array_sum(int* arr, int arr_length)
{
    int res = 0;
    for (int k = 0; k < arr_length; k++)
        res += arr[k];

    return res;
}

long long int array_neg_product(int* arr, int arr_length)
{
    int res = 1;
    for (int k = 0; k < arr_length; k++)
        if (arr[k] < 0)
            res *= arr[k];

    return res;
}

int array_even_count(int* arr, int arr_length)
{
    int count = 0;
    for (int k = 0; k < arr_length; k++)
        if ((arr[k] & 1) == 0)
            count++;

    return count;
}

int array_minimum_element(int* arr, int arr_length, int& index_min)
{
    int min = 100;
    index_min = -1;
    for (int k = 0; k < arr_length; k++)
        if (arr[k] < min)
        {
            min = arr[k];
            index_min = k;
        }

    return min;
}

int array_maximum_element(int* arr, int arr_length, int& index_max)
{
    int max = -100;
    index_max = -1;
    for (int k = 0; k < arr_length; k++)
        if (arr[k] > max)
        {
            max = arr[k];
            index_max = k;
        }
    return max;
}

int array_second_minimum(int* arr, int arr_length, int& index_second_min)
{
    int index_min = -1;
    int min = array_minimum_element(arr, arr_length, index_min);
    int second_min = 100;
    index_second_min = -1;

    for (int k = 0; k < arr_length; k++)
        if (k != index_min)
            if (arr[k] < second_min)
            {
                second_min = arr[k];
                index_second_min = k;
            }

    return second_min;
}

void array_pair_swap(int* arr, int arr_length)
{
    if (arr_length != 1)
        for (int k = 0; k < arr_length; k += 2)
            array_swap(arr[k], arr[k + 1]);
}

void array_reverse(int* arr, int arr_length) 
{
    for (int k = 0; k < arr_length / 2; k++)
        array_swap(arr[k], arr[arr_length - k - 1]);
}

void array_delete_between_min_max(int* arr, int& arr_length)
{
    int index_min = -1;
    int index_max = -1;

    array_minimum_element(arr, arr_length, index_min);
    array_maximum_element(arr, arr_length, index_max);

    int start = index_min < index_max ? index_min : index_max;
    int end = index_max > index_min ? index_max : index_min;

    if (start + 1 <= end - 1)
    {
        memmove(arr + start + 1, arr + end,
            sizeof(arr[0]) * (arr_length - end + start));
        arr_length = arr_length - end + start + 1;
    }
}

void array_zero_insert(int* arr, int& arr_length)
{
    if (arr_length == 1) return;
    memmove(arr + arr_length / 2 + 1, arr + arr_length / 2, sizeof(arr[0]) * (arr_length / 2));
    arr[arr_length / 2] = 0;
    arr_length++;
}

void array_output(int* arr, int arr_length)
{
    for (int k = 0; k < arr_length; k++)
        cout << arr[k] << ", ";
    cout << endl;
}

int main(void)
{
    int arr[init_len] = { 0 };
    for (int k = 10; k < 100; k++)
        arr[k - 10] = k;
    for (int k = 100; k < init_len + 10; k++)
        arr[k - 10] = 90 - k;
    array_shuffle(arr, init_len);

    int length = 100;
    cout << "Enter length of an array (between 1 and 100) ";
    cin >> length;
    array_output(arr, length);

    cout << "Sum of all elements == " << array_sum(arr, length) << endl;
    cout << "Product of all negative numbers == " << array_neg_product(arr, length) << endl;
    cout << "Count of even numbers == " << array_even_count(arr, length) << endl;

    int index_second_min = -1;
    int second_minimum = 100;
    second_minimum = array_second_minimum(arr, length, index_second_min);
    cout << "Second minimum == arr[" << index_second_min << "] == " << second_minimum << endl;

    array_pair_swap(arr, length);
    cout << "After swapping in pairs: " << endl;
    array_output(arr, length);

    array_reverse(arr, length);
    cout << "After reversing: " << endl;
    array_output(arr, length);

    array_delete_between_min_max(arr, length);
    cout << "After deleting all elements between minimum and maximum: " << endl;
    array_output(arr, length);

    array_zero_insert(arr, length);
    cout << "After inserting zero: " << endl;
    array_output(arr, length);

    return EXIT_SUCCESS;
}
