 /*
Assignment No:: 2
Title :: Implement priority queue as ADT using single linked list for servicing patients in an hospital
		with priorities as i) Serious (top priority) ii) medium illness (medium priority) iii) General (Least priority).
Name :: Sanket Nale
Roll No. :: 3174516		Class:: SE-B-IT		Batch:B3
*/
/*---CODE---*/
  #include<iostream>
  #include<string.h>
  #include<stdlib.h>
  using namespace std;

  typedef struct node
  {
     int srno;
     char name[30];
     int age;
     string dis;
     int severity;
     struct node *next;
  }node;

  class queue
  {
     public:
       node *f,*r;
     public:
       queue()
       {
         f=r=NULL;
       }
       void enque(node);
       void disp();
       void dequeue();
       int isempty()
       {
          if(f==NULL)
            return 1;
          else
            return 0;
       }
  };

  void queue::enque(node x)
  {
      if(isempty()==1)
        r=f=new node(x);
      else
      {
        r->next=new node(x);
        r=r->next;
      }
      r->next=NULL;
  }

  void queue::dequeue()
  {
     node *temp;
     if(isempty()==1)
       cout<<"\nNo patients\n";
     else
     {
        temp=f;
        f=f->next;
        free(temp);
     }
  }

  void queue::disp()
  {
     node *temp;
      temp=f;
     if(temp==NULL)
     {
       cout<<"\nNo Patients\n";
       return;
     }
     while(temp!=NULL)
     {
       cout<<"\nSr no.:\t"<<temp->srno<<"\nName:\t"<<temp->name<<"\nAge:\t"<<temp->age<<"\nDisease: "<<temp->dis<<"\n";
       temp=temp->next;
     }
  }

  class pq:public queue
  {
      queue q[4];
    public:
      void arrival();
      void service();
      void display();
  };

  void pq::arrival()
  {
     node temp;
     cout<<"\nEnter the Sr no. of patient::";
     cin>>temp.srno;
     cout<<"\nEnter the Name of the patient::";
     cin>>temp.name;
     cout<<"\nEnter the age::";
     cin>>temp.age;
     cout<<"\n1.Heart Attack \n2 Brain Tumer \n3 SwineFlu \n4 Major Accident\n5. Maleria \n6 Dengue \n7 Typhoid\n8 Vomitting \n9 Fever \n10 Cough \n11 Chicken Pox\n12.Other";
	 cout<<"\nEnter the disease::";
		int ch2;
		cin>>ch2;
		switch(ch2)
		{	
			case 1 : temp.dis="Heart Attack";
				break;
			case 2: temp.dis="Brain Tumer";
				break;
			case 3: temp.dis="SwineFlu";
				break;
			case 4 :temp.dis="Major Accident";
				break;
			case 5: temp.dis="Maleria";
				break;
			case 6: temp.dis="Dengue";
				break;
			case 7: temp.dis="Typhoid";
				break;
			case 8: temp.dis="Vomitting";
				break;
			case 9: temp.dis="Fever";
				break;
			case 10: temp.dis="Cough";
				break;
			case 11: temp.dis="Chicken Pox";
			        break;
			default:cout<<"\n Enter Name disease\n";
			    cin>>temp.dis;
			    break;
		}
       switch(ch2)
       {
			case 1 : temp.severity=0;
				break;
			case 2: temp.severity=0;
				break;
			case 3: temp.severity=0;
				break;
			case 4 :temp.severity=0;
				break;
			case 5: temp.severity=1;
				break;
			case 6: temp.severity=1;
				break;
			case 7: temp.severity=1;
				break;
			case 8: temp.severity=2;
				break;
			case 9: temp.severity=2;
				break;
			case 10: temp.severity=2;
				break;
			case 11:temp.severity=2;
				break;
			default:temp.severity=3;
        }
       switch(temp.severity)
       {
          case 0:q[0].enque(temp);
                 break;

          case 1:q[1].enque(temp);
                 break;

          case 2:q[2].enque(temp);
                 break;

          default:q[3].enque(temp);
                 break;
        }
  }

  void pq::display()
  { 
	     cout<<"\n\t\tSerious Patients\n";
	     q[0].disp();
	     cout<<"\n\t\tMedium Illness\n";
	     q[1].disp();
	     cout<<"\n\t\tGeneral Illness\n";
	     q[2].disp();
	     cout<<"\n\t\tOther Illness\n";
	     q[3].disp();
   }

  void pq::service()
  {
  		int sch;
  		do{
	     	cout<<"\n\tMENU\n1.Treatment\n2.Exit ";
	     	cout<<"Enter your choice::";
	     	cin>>sch;
	     	switch(sch)
	     	{
	     		case 1:
	     			q[0].disp();
	     			q[0].dequeue();
	     			cout<<"\nSerious Patients Tretment is Completed ";
	     			q[1].disp();
					q[1].dequeue();
					cout<<"\nMedium Illnesss Patients Tretment is Completed ";
					q[2].disp();
					q[2].dequeue();  
					cout<<"\nGenral Illness Patients Tretment is Completed ";
					q[3].disp();
					q[3].dequeue();  
					cout<<"\nOther Illness Patients Tretment is Completed ";
					break;
			 }
		}while(sch!=2);
  }

  int main()
  {
    int ch,another=1;
    pq q;
    do
    {
      cout<<"\n\tMENU\n";
      cout<<"\n1.Arrival\n2.Service\n3.Display\n4.Exit\nEnter your choice::";
       cin>>ch;
      switch(ch)
      {
        case 1:q.arrival();
               break;

        case 2:q.service();
               break;

        case 3:q.display();
               break;
      }
     }while(ch!=4);
  }

/*---OUTPUT---*/
/*

*/
