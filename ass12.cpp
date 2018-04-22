/*Assignment No:12
Title-Implementation of Direct Access File
*/
/*---Code----*/
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string.h>
#include<stdlib.h>

using namespace std;

class EMP_CLASS
{
	 typedef struct EMPLOYEE
	 {
		 char name[10];
		 int emp_id;
		 int salary;
		 int link;
		 int loc;
	 }Rec;
	 
	 Rec Records;
public:
	  int size;
	  int Chain_tab[10][10];
	  EMP_CLASS();
	  void Insert();
	  void init();
	  void Display();
	  void Search();
	  void set_chain(int);
	  friend int Hash(int);
};
EMP_CLASS::EMP_CLASS()
{
	   strcpy(Records.name,"");
	   Records.emp_id=-1;
	   Records.salary=-1;
	   Records.link=-1;
}
void EMP_CLASS::init()
{
	 fstream seqfile;
	 seqfile.open("EMP.DAT",ios::out|ios::binary);
	 
	 cout<<"\n Enter the Hash table size ";
	 cin>>size;
	 
	 for(int i=0;i<size;i++)
	 {
		  strcpy(Records.name,"");
		  Records.emp_id=-1;
		  Records.salary=-1;
		  Records.link=-1;
		  Records.link=i;
		  seqfile.write((char*)&Records,sizeof(Records));
		  for(int i=0;i<size;i++)
		  for(int j=0;j<size;j++)
		  Chain_tab[i][j]=-1;
	 }
	 
	 cout<<"\n\n Hash table is initialised...";
	 cout<<"\n Now, insert the records in the hash table";
	 seqfile.close();
}
int Hash(int num)
{
	 int key;
	 key=num%10;
	 return key;
}
void EMP_CLASS::set_chain(int x)
{
	 fstream seqfile;
	 int i,j,h,offset;
	 seqfile.open("EMP.DAT",ios::in|ios::out|ios::binary);
	 for(i=0;i<size;i++)
	 {
	 	 h=i;
		  for(j=0;j<size;j++)
		  {
			   if(Chain_tab[i][j]==x)
			   {
				    offset=h*sizeof(Records);
				    seqfile.seekg(offset);
				    seqfile.read((char*)&Records,sizeof(Records));
				    seqfile.seekp(offset);
				    Records.link=j;
				    seqfile.write((char*)&Records,sizeof(Records));
				    h=j;
			   }
		  }
	 }
	 seqfile.close();
}
void EMP_CLASS::Insert()
{
	 int i,h,x;
	 char ch='y';
	 char new_name[10];
	 int new_emp_id;
	 int new_salary;
	 fstream seqfile;
	 init();
	 seqfile.open("EMP.DAT",ios::in|ios::out|ios::binary);
	 do
	 {
		  cout<<"\n Enter Name: ";
		  cin>>new_name;
		  cout<<"\n Enter Emp_ID: ";
		  cin>>new_emp_id;
		  cout<<"\n Enter Salary: ";
		  cin>>new_salary;
		  h=Hash(new_emp_id);
		  x=h;
		  int offset,flag1=0;
		  offset=h*sizeof(Records);
		  seqfile.seekg(offset);
		  seqfile.read((char*)&Records,sizeof(Records));
		  seqfile.seekp(offset);
		  if(Records.emp_id==-1)
		  {
			    strcpy(Records.name,new_name);
			    Records.emp_id=new_emp_id;
			    Records.salary=new_salary;
			    Records.link=-1;
			    Records.loc=h;
			    seqfile.write((char*)&Records,sizeof(Records))<<flush;
			   
		  }
		  else
		  {
			  int flag=0;
			  int prev_link=Records.loc;
			  
			  if((Records.emp_id)%size==h)
			       flag1=1;
			       
			  do
			  {
				   h++;
				   if(h>size+1)
				   {
					   cout<<"\n The hash table is Full, Can't insert record!!!";
					   return;
				   }
				   offset=h*sizeof(Records);
				   seqfile.seekg(offset);
				   seqfile.read((char*)&Records,sizeof(Records));
				   if(Records.emp_id==-1)
				   {
					    seqfile.seekp(offset);
					    strcpy(Records.name,new_name);
					    Records.emp_id=new_emp_id;
					    Records.salary=new_salary;
					    Records.link=-1;
					    Records.loc=h;
					    seqfile.write((char*)&Records,sizeof(Records))<<flush; 
					    if(flag1==1)
					    {
						 Chain_tab[prev_link][h]=x;
					    }
					    flag=1;
				   }
			  }while(flag==0);
			}
			  cout<<"\nDo you want to add more records(y\n))?";
			  cin>>ch;
			  set_chain(x);
	 }while(ch=='y');
	 seqfile.close();
}
void EMP_CLASS::Display()
{
	 fstream seqfile;
	 seqfile.open("EMP.DAT",ios::in|ios::out|ios::binary);
	 seqfile.seekg(0,ios::beg);
	 cout<<"\n The Contents of file are ..."<<endl;
	 cout<<"\nLoc.      Name         Emp_ID      Salary        Link    ";
	 while(seqfile.read((char *)&Records,sizeof(Records)))
	 {

		   if(strcmp(Records.name,"")!=0)//not displaying empty slots
		   {
		   cout<<"\n--------------------------------------------------------\n";
		   cout<<Records.loc<<"       "<<Records.name<<flush<<"      "<<Records.emp_id;
		   cout<<"          "<<Records.salary<<"          "<<Records.link;

		 }
	 }
	seqfile.close();
}
void EMP_CLASS::Search()
{
	 fstream seqfile;
	 int key,h,offset,flag=0;
	 cout<<"\n Enter the Emp_ID for searching the record ";
	 cin>>key;
	 seqfile.open("EMP.DAT",ios::in|ios::binary);
	 h=Hash(key);
	 while(seqfile.eof()==0)
	 {         offset=h*sizeof(Records);
		  seqfile.seekg(offset,ios::beg);
		  seqfile.read((char *)&Records,sizeof(Records));
		  if(key==Records.emp_id)
		  {
			   cout<<"\n The Record is present in the file and it is...";
			   cout<<"\n Name: "<<Records.name;
			   cout<<"\n Emp_ID: "<<Records.emp_id;
			   cout<<"\n Salary: "<<Records.salary;
			   flag=1;
			   return;	
		  }
		  else
		  {
			   h=Records.link;
			   if(h==-1)
			   {
			       cout<<"\n The Record is not present in the file\n";
			       return;
			   }
			   
		  }
	 }
	  if(flag==0)
	  cout<<"\n The Record is not present in the file";
	  seqfile.close();
}
int main()
{
	 EMP_CLASS List;
	 int choice,key;
	 do
	 {
		  cout<<"\nMenu";
		  cout<<"\n 1.Insert";
		  cout<<"\n 2.Display";
		  cout<<"\n 3.Search";
		  cout<<"\n 4.Exit";
		  cout<<"\n Enter your choice: ";
		  cin>>choice;
		  switch(choice)
		  {
			  case 1:List.Insert();
			      break;
			  case 2:List.Display();
			      break;
			  case 3:List.Search();
			      break;
		  }
	}while(choice!=4); 
}

