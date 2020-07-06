#include <bits/stdc++.h>
using namespace std;
class Student{
public:
      string name;
      int Rollno;
       int Year;
      double cgpa;
      int marks[5];


 Student(){
  cout  << "Default Constructor"<<endl;
  name="Rajesh";
  Rollno=25;
  Year=3;
  cgpa=9.5;

  }

 int TotalMarks(int m[5]){
  int i,t,sum;
  sum=0;
  for(t=0;t<5;t++){
   sum=sum+*(m+t);
  }
  cout << "Total Marks Obtained are:" << sum <<endl;
  return sum;

   }
  void calculate(int t){
   double temp;
   temp=t/5;
   cgpa=temp/9.5; //This formula was obtained from Internet
   cout << "Your cgpa is" << cgpa <<endl;
  }

 void Input(){
  cout << "Enter the Important Details:"<<endl;
  cout << "Name" <<endl;
  cin >> name;
  cout << "Roll no:" << endl;
  cin >> Rollno;
  cout << "Year" << endl;
  cin >> Year;

 }
 void Display(){
  cout << "Name: " << name <<endl;
  cout << "Roll no: " << Rollno <<endl;
  cout << "Cgpa: " << cgpa <<endl;
  cout << "Year: " << Year <<endl;
 }
 };
  int main(){
  int i,total;

  Student s1;
  s1.Input();
  int *arr=new int[5];

 cout << "Enter your Marks";
   for(i = 0; i < 5; i++)
   {
       cin >> *(arr+i);
   }

  for(i = 0; i < 5; i++)
   {
       s1.marks[i]=*(arr+i);
   }
total=s1.TotalMarks(s1.marks);
 s1.calculate(total);
 s1.Display();
 return 0;
 }
