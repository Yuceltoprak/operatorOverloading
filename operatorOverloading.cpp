#include <iostream>
using namespace std;

class myComplex {
  private:
    int real, imag;
  public: 
    myComplex()
    {
      real=0;
      imag=0;
    }
    myComplex(int _a, int _b)
    {
      real=_a;
      imag=_b;
    }
    void setReal(int n)
    {
      this->real = n;
    }
    void setImag(int n)
    {
      this->imag = n;
    }
    void print()
    {
      cout << this->real << " " << this->imag<< "i"<<endl;
    }
    int getReal()
    {
      return this->real;
    }
    int getImage()
    {
      return this->imag;
    }
    //myComplex & operator=(const myComplex &);
    myComplex & operator+(const myComplex &c);
    myComplex & operator-(const myComplex &v);
    myComplex operator*(int);
};

/*myComplex & myComplex::operator=(const myComplex &c)
{
  real = c.real;
  imag = c.imag;
  return *this;
} */

myComplex & myComplex::operator+(const myComplex &x){
    myComplex c;
    c.real = this->real + x.real;
    c.imag = this->imag + x.imag;
    return c;
}
myComplex & myComplex::operator-(const myComplex &x){
    myComplex c;
    c.real = this->real - x.real;
    c.imag = this->imag - x.imag;
    return c;
}
myComplex myComplex::operator*(int sayi){
    myComplex c;
    c.real = sayi*real;
    c.imag = sayi*imag;
    return c;
}

int main() {
  myComplex c1(3,5),c2,c3;  // c2 = c3 = 0 + 0i
                            // c1 = 3 + 5i
  c2.setReal(2);
  c2.setImag(3);            // c2 = 2 + 3i
  c3 = c1 + c2;
  c3.print();
  c3.print();               // c3 = 5 + 8i
  c3 = c1 - c2;
  c3.print();               // c3 = 1 + 2i
  c3 = c1 - c2*2; //c2*2 çalısıyor??
  c3.print();               // c3 = -1 - i
  c2.setReal(3);            // c2 = 3 + 3i
  c3 = c1 - c2;             // c3 = 2i
  c3.print();               
  cout<<"Real:"<<c3.getReal()<<", Imag:"<<c3.getImage()<<endl;
                            // Real:0, Image:2
}
