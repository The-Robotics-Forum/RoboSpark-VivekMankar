#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
class String1{
 public:
char st1[25];
char st2[25];
String1(){
}
String1(char str1[],char str2[]){
strcpy(this->st1,str1);
strcpy(this->st2,str2);
}
void display();
void operator+();
void operator *(int val);
friend void operator*(int val,String1 str);
friend istream& operator  >> (istream &cin, String1 &str);
friend ostream& operator  << (ostream &out, String1& str);

};

istream& operator >> (istream &cin,String1 & str){
 cout << "Enter first string";
 cin >> str.st1;
 cout <<"Enter second string";
 cin>>str.st2;
 return cin;
}

ostream& operator <<(ostream &out,String1 & str){
out << "First string is: "<< str.st1<<endl;
out << "Second string is: "<<str.st2<<endl;
return out;
}
void String1::display()
{

 cout << "Strings entered are:"<<st1<<" "<<st2<<endl;

}
void String1::operator+(){
 string f=string(st1);
 string g=string(st2);
  cout << "Concatenated strings are:" << f.append(g)<<endl;
}
void String1::operator*(int val){
cout << "String repetition are as follows:"<<endl;
for(int i=0;i<val;i++){
cout << st1;
}
cout << endl;


}

void operator*(int val, String1 str){
 cout << "Friend function"<<endl;
  for(int i=0;i<val;i++){
 cout <<str.st1;
}
}


int main(){
String1 s2("HI","MEGHA");
 cin >>s2;
cout << s2;
 +s2;
 s2*2;
 2*s2;
s2.display();

return 0;
}

