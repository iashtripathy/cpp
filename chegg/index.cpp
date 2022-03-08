#include<bits/stdc++.h>
using namespace std;

//structure declaration
struct numberList{
    int sno,decimal,octal,hexadecimal;
    long long int binary;
};

//insSort function to sort the vector
void insSort(vector <int> &vec, int n)
{
    int i, temp, j;
    for (i = 1; i < n; i++)
    {
        temp = vec[i];
        j = i - 1;
        while (j >= 0 && vec[j] > temp)
        {
            vec[j + 1] = vec[j];
            j = j - 1;
        }
        vec[j + 1] = temp;
    }
}

//convert from decimal to binary and return the value of type long long int
long long int convertToBinary(int n){
        
    long long binaryNum = 0;
    int i = 1,rem;
    while (n != 0) {
        rem = n % 2;
        n = n / 2;
        binaryNum += rem*i;
        i*=10;
    }
    return binaryNum;
}

//convert from decimal to octal and return the value of type int
int convertToOctal(int n){
    int rem, i = 1, octalNumber = 0;
    while (n != 0)
    {
        rem = n % 8;
        n /= 8;
        octalNumber += rem * i;
        i *= 10;
    }
    return octalNumber;   
}

//convert from decimal to hexadecimal and return the value of type int
int convertToHexadecimal(int n){
    int rem, i = 1, hexNumber = 0;
    while (n != 0)
    {
        rem = n % 16;
        n /= 16;
        hexNumber += rem * i;
        i *= 10;
    }
    return hexNumber;
}


int main(){

    fstream file;
    int val;
    /* unordered set because the numbers.txt file may contain duplicate values and hence we need to remove duplicates in our final answer*/
    unordered_set <int> unOrder;
    /*myFileName should have the path to the numbers.txt i.e the location where numbers.txt is present*/
    string myFileName = "numbers.txt";
    //opening the file
    file.open(myFileName.c_str());
    /*readindg from the file and inserting each value one by one in unordered map.By default duplicate values are not inserted*/
    while(file >> val){
        unOrder.insert(val);
    }
    /*calculate the no of decimal values present in the numbers.txt */
    int size = unOrder.size();
    /*Inserting all the numbers from unordered set to vector one by one */
    vector <int> vec;
    for(auto &x:unOrder){
        vec.push_back(x);
    }

    //sorting the vector using insertion Sort
    insSort(vec,size);

    int count = 1;

    /*Creating the structure ststObject to print the output in the required table format*/
    struct numberList stObj[size];
    for(auto &i:vec){
        stObj[count-1].sno = count;
        stObj[count-1].decimal = i;
        stObj[count-1].binary = convertToBinary(i);
        stObj[count-1].octal = convertToOctal(i);
        stObj[count-1].hexadecimal = convertToHexadecimal(i);
        ++count;        
    }

    //displaying the result in the required format
    cout<<"The whole number list:"<<endl;
    cout<<"No."<<"\t"<<"Decimal"<<"\t"<<"Binary"<<"\t"<<"Octal"<<"\t"<<"Hexadecimal"<<endl;
    for(auto &iterate:stObj){
        cout<<iterate.sno<<"."<<"\t"<<iterate.decimal<<"\t"<<iterate.binary<<"\t"<<iterate.octal<<"\t"<<iterate.hexadecimal<<endl;
    }
    return 0;
}