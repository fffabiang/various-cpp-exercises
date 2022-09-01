/*
You are given an array of non-negative integers numbers. You are allowed to choose any number from this array and swap any two digits in it. If after the swap operation the number contains leading zeros, they can be omitted and not considered (eg: 010 will be considered just 10).

Your task is to check whether it is possible to apply the swap operation at most once, so that the elements of the resulting array are strictly increasing.

*/

#include <vector>
#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

vector<int> convertIntToArr(int a)
{
    vector<int> val;
    while (a>0)
    {
        val.insert(begin(val), a % 10);
        a/=10;
    }
    return val;
}

void printArray(vector<int> vec)
{
    for(int value : vec)
    {
        cout<<value<<" ";
    }
    cout<<endl;
}

int convertArrToInt(vector<int> vec)
{
    int i=0, j=vec.size()-1;
    int value=0;
    while (i<vec.size())
    {
        value *= 10;
        value += vec[i];
        i++;
    }
    return value;
}

bool foundLowerValue(int a, int& b)
{
    
    vector<int> vec = convertIntToArr(b);
    int lowerValuePossible = (int) INFINITY;
    
    for (int i=0;i<vec.size();i++)
    {
        for (int j=i+1;j<vec.size();j++)
        {
            
            /*cout<<"Comparing this vector ";
            printArray(vec);*/
            swap(vec[i], vec[j]);
            /*cout<<" to this vector ";
            printArray(vec);*/

            int possibleValue = convertArrToInt(vec);
            if (possibleValue < a && possibleValue < lowerValuePossible)
            {
                //cout << "possibleSwap of " << b << " = " << possibleValue << " | " << i<< " with " << j << endl;
                lowerValuePossible = possibleValue;
            }
            
            swap(vec[i], vec[j]);
        }
    }
    
    if (lowerValuePossible < a)
    {
        b = lowerValuePossible;
        return true;    
    }else {
        return false;
    }
    
}

bool solution(vector<int> numbers) {

    bool swappedOnce = false;
        
    for (int i=0;i<numbers.size();i++)
    {
        if (i<numbers.size()-1)
        {
            
            if (numbers[i]<numbers[i+1])
            {
                //cout<<numbers[i]<<" es menor que "<<numbers[i+1]<<endl;
            }
            else
            //not increasing, try to update 
            {
                if (!swappedOnce){
                    //cout << "will start looking for possible swapped value" << endl;
                    int swappedValue = numbers[i];
                    if (foundLowerValue(numbers[i+1],swappedValue))
                    {
                        swappedOnce = true;
                        //cout << "old=" << numbers[i] << " new=" << swappedValue << endl;
                        numbers[i] = swappedValue;
                    }else {
                        return false;
                    }
                }else
                {
                    return false;
                }
            }
            
        }
    }
    return true;

}

int main()
{

    vector<int> values = {1, 3, 21, 11};
    cout << "RESULT = " << solution(values) << endl;

    return 0;
}
