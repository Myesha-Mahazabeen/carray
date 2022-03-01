//Myesha Mahazabeen, 
#include<iostream>
#include<vector>
#include<exception>

#ifndef HM5_P1_Mahazabeen_24005884_carray_hpp
#define HM5_P1_Mahazabeen_24005884_carray_hpp

using namespace std;

class ArrayOutOfRange : public out_of_range
{
protected:
    int sizeOfArray;
    int attemptedIndex;

public:
    explicit ArrayOutOfRange (const string& errorMsg, int sz, int idx ):out_of_range(errorMsg)
    {
        this->sizeOfArray= sz;
        this->attemptedIndex= idx;
    }
    const char* what() const noexcept;
};
 
const char* ArrayOutOfRange :: what() const noexcept
{
    static string msg;
    msg.clear();
    msg=  (string(out_of_range::what()) + " (" + to_string(attemptedIndex) + " , " + to_string(sizeOfArray) + ")");

    return msg.c_str();
}


template<typename T1>
class CheckedArray
{
protected:
    int size;
    T1* array;

public:
    CheckedArray(int n, T1* arr);   // taking pointer to an array and it's size in constructor
    T1 operator[](int idx);

    // class ArrayOutOfRangeError() is inside class CheckedArray
    class ArrayOutOfRangeError
    {
        string ErrorMsg;
    public:
        ArrayOutOfRangeError(string s= "Array Out Of Range Error"){ this->ErrorMsg= s; }    // s="Array Out Of Range Error" if no  arguement
        string getErrorMsg() { return this->ErrorMsg; }
    };
};

template<typename T1>
CheckedArray<T1> :: CheckedArray(int n, T1* arr)
{
    this->array= new T1[n];
    this->array= arr;
    this->size= n;
}


template<typename T1>
T1 CheckedArray<T1> :: operator[](int idx)
{   
    if(idx>=size || idx<0)  // checking if index is invalid
    { 
        /* 1. throwing an object of ArrayOutOfRangeError() */
         throw ArrayOutOfRangeError();

        /* 2. throwing an exception of out_of_range which is a subclass of logic_error
        which itself is a subclass of exception class. Line 72 and 81 will be commented while running no 2. */
        
        // throw out_of_range("out_of_range_exception");

        /* 3. throwing an exception ArrayOutOfRange, which is a subclass of out_of_index. Line 72 and 77 will be commented while running no 3. */
        
        //throw ArrayOutOfRange("Array Out Of Range", this->size, idx);
    }

    return array[idx];  // returning the element if the index is valid 
}


#endif
