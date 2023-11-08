//Myesha Mahazabeen
#include "carray.hpp"

int main()
{
    int a[2]= {7, 2}; // Testing for int data type
    CheckedArray<int> i_ca= CheckedArray<int>(2, a);    
    cout<< "created CheckedArray<int> i_ca , size=2\n";
    try 
    {
        // accessing index: -1 of i_ca 
        cout<< "i_ca[-1]: "<< i_ca[-1]<< endl;
    }
    catch(CheckedArray<int>::ArrayOutOfRangeError& err)
    {
        cout<< err.getErrorMsg()<< endl;;
    }
    catch(out_of_range& err)
    {
        /* since ArrayOutOfRange is a subclass of out_of_range error,
        this catch statement will catch ArrayOutOfRange throws as well */
        cout<< err.what()<< endl;
    }
    
    try
    {
        // accessing 0 to 4 index of i_ca
        for(int i=0; i<5; i++)
            cout<< "i_ca["<< to_string(i)<< "]: "<< i_ca[i]<< endl;
    }
    catch(CheckedArray<int>::ArrayOutOfRangeError& err)
    {
        cout<< err.getErrorMsg()<< endl;;
    }
    catch(out_of_range& err)
    {
        /* since ArrayOutOfRange is a subclass of out_of_range error,
        this catch statement will catch ArrayOutOfRange throws as well */
        cout<< err.what()<< endl;
    }

    cout<< endl;


    char c[]= {'a', 'b', 'c', 'd'};//Testing for character data type
    CheckedArray<char> c_ca= CheckedArray<char>(sizeof(c)/sizeof(char) , c);
    cout<< "created CheckedArray<char> c_ca , size=4\n";
    try
    {
        // accessing index: -1 from c_ca
        cout<< "c_ca[-1]: "<< c_ca[-1]<< endl;
    }
    catch(CheckedArray<char>::ArrayOutOfRangeError& err)
    {
        cout<< err.getErrorMsg()<< endl;;
    }
    catch(out_of_range& err)
    {
        /* since ArrayOutOfRange is a subclass of out_of_range error,
        this catch statement will catch ArrayOutOfRange throws as well */
        cout<< err.what()<< endl;
    }

    try
    {
        // accessing 0 to 10 index of c_ca 
        for(int i=0; i<10; i++)
            cout<< "c_ca["<< to_string(i)<< "]: "<< c_ca[i]<< endl;
    }
    
    catch(CheckedArray<char>::ArrayOutOfRangeError& err)
    {
        cout<< err.getErrorMsg()<< endl;;
    }
    catch(out_of_range& err)
    {
        /* since ArrayOutOfRange is a subclass of out_of_range error,
        this catch statement will catch ArrayOutOfRange throws as well */
        cout<< err.what()<< endl;
    }
    
}
