#include <iostream>
#include <cmath>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include "stdlib.h"

using namespace std;

class Compl        
{
  private:
    double reg, mnim;

  public:
  
  // ������������ 
  Compl ()
  {};

  Compl (double r)   
  {
    reg = r;
    mnim = 0;
  }

  Compl (double r, double i)
  {
    reg = r;
    mnim = i;
  }

  Compl (const Compl &c)   // �����������
  {
    reg = c.reg;
    mnim = c.mnim;
  }

  // ����������
  ~Compl ()
  {}

  // ������������
  Compl& operator = (Compl &c)   
  {
    reg = c.reg;
    mnim = c.mnim;
    return (*this);
  }

  // �������� +=
  Compl& operator += (Compl &c)   
  {
    reg += c.reg;
    mnim += c.mnim;
    return *this;
  }

  // �������� -=
  Compl& operator -= (Compl &c)   
  {
    reg -= c.reg;
    mnim -= c.mnim;
    return *this;
  }

  // �������� ��������
  Compl operator + (const Compl &c)   
  {
    return Compl (reg + c.reg, mnim + c.mnim);
  }

  // �������� ���������
  Compl operator - (const Compl &c)   
  {
    return Compl(reg - c.reg, mnim - c.mnim);
  }

  // �������� ���������
  Compl operator * (const Compl &c)   
  {
    return Compl(reg * c.reg - mnim * c.mnim, reg * c.mnim + mnim * c.reg);
  }

  // �������� �������
  Compl operator / (const Compl &c)   
  {
    Compl temp;

    double r = c.reg * c.reg + c.mnim * c.mnim;
    temp.reg = (reg * c.reg + mnim * c.mnim) / r;
    temp.mnim = (mnim * c.reg - reg * c.mnim) / r;

    return temp;
  }

  //��������� ������� ������ � private ������
  friend ostream & operator<< (ostream &, const Compl &);   
  friend istream & operator>> (istream &, Compl &);         

};


ostream& operator<< (ostream &out, const Compl &c)
{
  out << c.reg << " + i*" << c.mnim;
  return out;
}


istream& operator>> (istream &in, Compl &c)
{
  in >> c.reg >> c.mnim;
  return in;
}

int
main ()
{
 
  Compl a (10.4, 4.003);
  Compl b (9, -10.482);
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "a + b = " << a + b << endl;
  cout << "a - b = " << a - b << endl;
  cout << "a * b = "<< a * b << endl;
  cout << "a / b = "<< a / b << endl;
getch ();
  return 0;
}