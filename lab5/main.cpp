
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
 using namespacestd;
 
void main()
{

 char ch = ',';
 char b[250]="\0";
 char a[250]="\0";
ifstream out ("D:\\read.txt");
  while (!out.eof())
   {
     out.getline(b, sizeof(b));
     for (int i=0; i<=sizeof(b)/4; i++)
        {
           if (ch!=b[i]) 
		{
			a[i] = b[i];
		}
           else
            {
              for (int j=0; j<=250; j++) {a[j]='\0';}
              cout<<"Stroka: Imeet zapajtie!";
              break;
              }
           }
cout<<a<<endl;
}
out.close();
getch();
 
}