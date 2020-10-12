/******************************************************************************

Bridget Naylor
Date: 10/12/2020

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

int readData( int *&arr )
{
    //open file
    int size;
    ifstream inputFile;
    inputFile.open("data.txt");
    inputFile>>size;
    
    cout<<size;
    
    // //allocate the memory for the pointer arrat
    arr = new int[size];
    // //read reast of dta into array 

    for ( int i = 0; i < size; i++)
    {
        inputFile>>*(arr + i);
        cout<<"in read "<<arr[i]<<endl;
    }
    inputFile.close();
    return size;
}
void sorting(int * arr, int size) 
{
    bool swapped = true;
    while ( swapped )
    {
        swapped = false;
        for ( int i = 0; i < size - 1; i++)
        {
            if ( *(arr + i) > *(arr + i + 1) )
            {
                //cout<<"first "<<*(arr + i)<<" second "<<*(arr + i + 1)<<endl;
                int temp = *(arr + i);
                *(arr + i) = *(arr + i + 1);
                *(arr + i + 1) = temp;
                swapped = true;
                //cout<<"firstafter "<<*(arr + i)<<" secondafter "<<*(arr + i + 1)<<endl;
            }
        }
    }
    
    //testing
    // for ( int p = 0; p < size; p++)
    // {
    //     cout<<*(arr + p)<<endl;
    // }
}

void writeToConsole( int * arr, int size )
{
    cout << "Contents of array:" << endl;
    for ( int j = 0; j < size; j ++)
    {
        cout<<*(arr + j)<<endl;
    }
}


int main()
{
    int *numbers;
    
    int size = readData(numbers);
    sorting( numbers, size );
    writeToConsole( numbers, size );
    return 0;
}
