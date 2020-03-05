#include<iostream>
using namespace std;

class Complex
{
    int first, second;
public:
    void getdata(int x, int y)
    {
        first = x;
        second = y;
    }
    void showdata();
    Complex add(Complex c)
    {
        Complex temp;
        temp.first = first + c.first;
        temp.second = second + c.second;
        return temp;
    }

};

void Complex::showdata()
{
    cout<<"first ="<<first<<"\nSecond ="<<second<<endl;
}

int main()
{
    Complex c1,c2,c3;
    c1.getdata(5,10);
    c2.getdata(25,15);
    c3=c1.add(c2);
    c3.showdata();
    return 0;
}
