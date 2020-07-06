#include <bits/stdc++.h>
using namespace std;
class Student{
public:
      string name;
      int Rollno;
       int Year;
      double cgpa;

 void Input(){
  cout << "Enter the Important Details:"<<endl;
  cout << "Name:" <<endl;
  cin >> name;
  cout << "Roll no:" << endl;
  cin >> Rollno;
  cout << "Year:" << endl;
  cin >> Year;
   cout << "Cgpa:" << endl;
  cin >> cgpa;

 }
 void Display(){
  cout << "Name: " << name <<endl;
  cout << "Roll no: " << Rollno <<endl;
  cout << "Cgpa: " << cgpa <<endl;
  cout << "Year: " << Year <<endl;
 }
};
void showRank(int r){
 cout << "Your Rank is:" << r<<endl;;
}
void showRank(Student t){
 t.Display();
 cout << "No Rank"<<endl;
}
void showRank(Student p, int a){
 p.Display();
 cout << "Your Rank is:"<<a<<endl;
}
int main(){
 Student b;
 b.Input();
 cout << "This is condition1->"<<endl;
 showRank(4);
 cout << "This is condition 2->"<<endl;
 showRank(b);
 cout << "This is condition 3->"<<endl;
 showRank(b,5);
 return 0;
}
