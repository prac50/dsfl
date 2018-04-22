/*
Assignment No:11
Title:Department maintains a student information. The file contains roll number, name, division and
	address. Write a program to create a sequential file to store and maintain student data. It
	should allow the user to add, delete information of student. Display information of particular
	employee. If record of student does not exist an appropriate message is displayed. If student
	record is found it should display the student details.
*/
/*----CODE------*/
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#define MAX 20
using namespace std;

class student
{
     int roll_no;
     char name[MAX];
     char add[MAX];
     char div;
  public:
     int get_roll()
     {
        return roll_no;
     }
     
     student()
     {
        roll_no=0;
        strcpy(name,"\0");
        strcpy(add,"\0");
        div='\0';
     }
     
     void get_data();
     void put_data();
};

void student::get_data()
{
     cout<<"\nStudent Details\nEnter Roll No::";
      cin>>roll_no;
     cout<<"\nEnter Name::";
      cin>>name;
     cout<<"\nEnter Address::";
      cin>>add;
     cout<<"\nEnter Div::";
      cin>>div;
}

void student::put_data()
{
    cout<<"\nStudent Deatils";
    cout<<"\nRoll No::"<<roll_no;
    cout<<"\nName::"<<name;
    cout<<"\nAddress::"<<add;
    cout<<"\nDiv::"<<div;
}

class seq_file
{
     char file_name[MAX];
  public:
     seq_file(char f[MAX]);
     void create();
     void display();
     void add();
     void del_rec(int roll_no);
     void modify(int roll_no);
     void search(int roll_no);
};

seq_file::seq_file(char f[MAX])
{
     ofstream file1;
     strcpy(file_name,f);
     file1.open(file_name);
     if(file1)
     {
       cout<<"\nFile opened successfully\n";
     }
     else
     {
       cout<<"\nFile cannot open\n";
     }
     file1.close();
};

void seq_file::create()
{
     ofstream file1;
     student s;
     file1.open(file_name);
     s.get_data();
     file1.write((char *)(&s),sizeof(s));
     file1.close();
}

void seq_file::display()
{
     ifstream file1;
     file1.open(file_name);
     student s;
     file1.read((char *)(&s),sizeof(s));
     while(!file1.eof())
     {
        s.put_data();
        file1.read((char *)(&s),sizeof(s));
     }
     file1.close();
}

void seq_file::add()
{
     ofstream file1;
     student s;
     file1.open(file_name,ios::app);
     s.get_data();
     file1.write((char *)(&s),sizeof(s));
     file1.close();
}

void seq_file::del_rec(int roll_no)
{
     int found=0;
     ifstream file1;
     ofstream temp;
     student s;
     file1.open(file_name);
     temp.open("temp.DAT");
     file1.read((char *)(&s),sizeof(s));
     while(!file1.eof())
     {
        if(s.get_roll()==roll_no)
        {
           found=1;
           s.put_data();
        }
        else
           temp.write((char *)(&s),sizeof(s));
        file1.read((char *)(&s),sizeof(s));
        
     }
     if(found==0)
     {
       cout<<"\nRecord Not Found\n";
     }
     file1.close();
     temp.close();
     remove(file_name);
     rename("temp.DAT",file_name);
}

void seq_file::modify(int roll_no)
{
     int found=0;
     ifstream file1;
     ofstream temp;
     student s;
     file1.open(file_name);
     temp.open("temp.DAT");
     file1.read((char *)(&s),sizeof(s));
     while(!file1.eof())
     {
        if(s.get_roll()==roll_no)
        {
            found=1;
            s.get_data();
            temp.write((char *)(&s),sizeof(s));
        }
        else
            temp.write((char *)(&s),sizeof(s));
               file1.read((char *)(&s),sizeof(s));
        
     }
     if(found==0)
     {
       cout<<"\nRecord Not Found\n";
     }
     file1.close();
     temp.close();
     remove(file_name);
     rename("temp.DAT",file_name);
}

void seq_file::search(int roll_no)
{
      student s;
      ifstream file1;
      int found=0;
      file1.open(file_name);
      file1.read((char *)(&s),sizeof(s));
      while(!file1.eof())
      {
         if(s.get_roll()==roll_no)
         {
            found=1;
            cout<<"\n Record Found";
            s.put_data();
            break;
         }
      }
      if(found==0)
      {
            cout<<"\nRecord Not Found";
      }
      file1.close();
}

int main()
{
      int roll,choice;
      char fname[MAX];
      student s;
      cout<<"\nEnter the file name:\t";
        cin>>fname;
      seq_file sf(fname);
      do
      {
         cout<<"\n\nMENU\n";
         cout<<"\n1.Create\n2.Add a Record\n3.Delete a Record\n4.Modify a Record\n5.Search a Record\n6.Display\n7.Exit\nEnter your choice::";
           cin>>choice;
           switch(choice)
           {
              case 1:sf.create();
                     break;
                     
              case 2:sf.add();
                     break;
                     
              case 3:cout<<"\nEnter a Roll No to be deleted::";
                       cin>>roll;
                     sf.del_rec(roll);
                     break;
                    
              case 4:cout<<"\nEnter a Roll No to be Modify::";
                       cin>>roll;
                     sf.modify(roll);
                     break;
                     
              case 5:cout<<"\nEnter a Roll No to be Search::";
                       cin>>roll;
                     sf.search(roll);
                     break;
                     
              case 6:sf.display();
                     break;
                     
              case 7:exit(0);
            }
       }while(choice!=7);
} 

/*---OUTPUT---*/
/*

*/
                      
