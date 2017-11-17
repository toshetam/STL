#include <iostream>
using namespace std;

int main()
{
    int n=100, sum = 0;

    

    for (int i = 1; i <= n; ++i) {
        sum += i;
    }


int y=n+1;
y= n*y;
y=y/2;

if (y=sum)
cout << "the value of loop addition is: "<< sum <<" and gauss formula is: "<< y <<". Hence, both are same";
else
cout<<"error in formula";
    return 0;
}
