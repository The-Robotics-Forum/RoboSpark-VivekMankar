#include<bits/stdc++.h>
using namespace std;
class Personal{
protected:
 string name;
 string surname;
 string address;
 long long int mobile_no;
 string dob;
public:
 Personal(){
 name= "Sam";
 surname= "Paul";
 address= "Harrison road, UK";
mobile_no = 15879635612;
dob="20/09/1998";
 }
 void get_personal();
 };
 class Professional{
protected:
 string name_of_organization;
 string job_profile;
 string project;
public:
 Professional(){
 name_of_organization="John Deere";
 job_profile="Engineer";
 project="Flow Control";
  }
  void get_professional();
 };
 class Academic{
protected:
 int year_of_passing;
 double cgpa;
 string college_name;
 string branch;
public:
 Academic(){
 year_of_passing=2017;
 cgpa=8.5;
 college_name="MIT";
 branch="Mechanical";
 }
 void get_academic();
 };
 class Biodata:public Personal,Professional,Academic{
  public:
  void display_biodata();
  void initialize(){
  get_personal();
  get_professional();
  get_academic();
  }
 void display_personal();
 void display_professional();
 void display_academic();
  };

 void Personal::get_personal(){
 cout << "Enter the following details:"<<endl;
  cout << "Enter your name:"<<endl;
  cin>>name;
   cout << "Enter your surname:"<<endl;
  cin>>surname;
 cout << "Enter your address:"<<endl;
  getline(cin,address);
   getline(cin,address);
   cout << "Enter your mobile number:"<<endl;
  cin>>mobile_no;
  cout<<"Enter your date of birth:"<<endl;
  cin >> dob;
 }
 void Professional::get_professional(){
 cout << "Enter the following details:"<<endl;
  cout << "Enter your name of organization:"<<endl;
 getline(cin,name_of_organization);
   cout << "Enter your job profile:"<<endl;
  cin>>job_profile;
 cout << "Enter your name of project:"<<endl;
  getline(cin,project);
  getline(cin,project);
 }

 void Academic::get_academic(){
 cout << "Enter the following details:"<<endl;
  cout << "Enter your year of passing:"<<endl;
  cin>>year_of_passing;
   cout << "Enter your Cgpa:"<<endl;
  cin>>cgpa;
 cout << "Enter your college name:"<<endl;
  getline(cin,college_name);
   getline(cin,college_name);
  cout << "Enter your branch:"<<endl;
  cin>>branch;
 }

 void Biodata::display_biodata(){
  cout << "Your Personal details are:"<<endl;
  cout << "Name:"<<name<<endl;
  cout << "Surname:"<<surname<<endl;
  cout << "Address:"<<address<<endl;
  cout << "Mobile number:"<<mobile_no<<endl;
  cout << "Date of Birth:"<<dob<<endl;
  cout <<endl;
  cout << "Your Professional details are:"<<endl;
  cout << "Name of Organization:"<<name_of_organization<<endl;
  cout << "Job profile:"<<job_profile<<endl;
  cout << "Name of Project:"<<project<<endl;
  cout <<endl;
  cout << "Your Academic details are:"<<endl;
  cout << "Year of passing:"<<year_of_passing<<endl;
  cout << "Cgpa:"<<cgpa<<endl;
  cout << "College Name:"<<college_name<<endl;
  cout << "Branch:"<<branch<<endl;
 }
 void Biodata::display_personal(){
  get_personal();
  cout << "Your Personal details are:"<<endl;
  cout << "Name:"<<name<<endl;
  cout << "Surname:"<<surname<<endl;
  cout << "Address:"<<address<<endl;
  cout << "Mobile number:"<<mobile_no<<endl;
  cout << "Date of Birth:"<<dob<<endl;
  cout <<endl;}

  void Biodata::display_professional(){
  get_professional();
  cout << "Your Professional details are:"<<endl;
  cout << "Name of Organization:"<<name_of_organization<<endl;
  cout << "Job profile:"<<job_profile<<endl;
  cout << "Name of Project:"<<project<<endl;
  cout <<endl;
  }
  void Biodata::display_academic(){
  get_academic();
  cout << "Your Academic details are:"<<endl;
  cout << "Year of passing:"<<year_of_passing<<endl;
  cout << "Cgpa:"<<cgpa<<endl;
  cout << "College Name:"<<college_name<<endl;
  cout << "Branch:"<<branch<<endl;
  }

 int main(){
Biodata b1,b2;

b1.initialize();
b1.display_biodata();//displays all the details


b2.display_personal();//for accessing just personal details
b2.display_professional();//for accessing just professional details
b2.display_academic();//for accessing just academic details
 return 0;
 }
