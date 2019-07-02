#include<iostream>

using namespace std;

class Train { int number; //train number
int seats_1;//total seats in first class
int seats_2;// total seats in second class
int seats_3;//total seats in third class
public:
Train(int i,int j, int k, int l)
{ number = i; seats_1 = j;
seats_2=k ; seats_3 = l;
}
int getnum(void)
{ return number;}
int getseats_1(void)
{ return seats_1;}
int getseats_2(void)
{ return seats_2;}
int getseats_3(void)
{ return seats_3;}
};
class Reservation :public Train
{ int bkd_1;// seats reserved in 1st class
int bkd_2;//seats reserved in 2nd class
int bkd_3;// seats reserved in 3rd class
public:
int i,j,k,l;
Reservation (int i,int j,int k,int l):Train(i,j,k,l)
{ bkd_1=bkd_2=bkd_3=0;}
void book(char type,int num);
void cancel(char type,int num);
void disp_status(void);
};
void Reservation::book(char type,int num)
{ switch(type)
{ case'1': bkd_1+=num; //add num to bkd_1
break;
case'2': bkd_2+=num;//add num to bkd_2
break;
case'3': bkd_3+=num;//add num to bkd_3
break;
default: cout<<"wrong class\n";
}
}


void Reservation :: cancel(char type, int num)
{ switch(type)
{ case'1':bkd_1-=num;
break;
case'2':bkd_2-=num;
break;
default:cout<<"wrong class\n";
}
}
void Reservation::disp_status(void)
{ cout<<"\t\t Train number:"<<getnum()<<"\n";
cout<<"Class\tTotal seats\tReseved\tUn reserved\n";
int val;
val=getseats_1();
cout<<"1\t"<<val<<"\t"<<bkd_1<<"\t"<<val-bkd_1<<"\n";
val=getseats_2();
cout<<"2\t"<<val<<"\t"<<bkd_2<<"\t"<<val-bkd_2<<"\n";
val=getseats_3();
cout<<"3\t"<<val<<"\t"<<bkd_3<<"\t"<<val-bkd_3<<"\n";
}

int main()
{
int num ;
cout<<"Enter Train Number:\n";
cin>>num;
cout<<"\n Enter total Number Of seats in 1st class\n";
int s1;
cin>>s1;
cout<<"\n Enter total number of seats in 2nd class\n";
int s2;
cin>>s2;
cout<<"\n Enter total number of seats in 3rd class\n";
int s3;
cin>>s3;
Reservation Tr(num,s1,s2,s3);
char cl_type;
int choice,seats;
do
{ cout<<"\n Main Menu\n";
cout<<"1.Reservation\n";
cout<<"2.Cancellation\n";
cout<<"3.Display Status\n";
cout<<"4.Exit\n";
cout<<"Enter your choice:";
cin>>choice;
cout<<"\n";
switch(choice)
{ case 1: cout<<"which class?(1/2/3):";
cin>>cl_type;
cout<<"\n How many seats?";
cin>>seats;
cout<<"\n";
Tr.book(cl_type,seats);
break;
case 2:cout<<"Which class?(1/2/3):";
cin>>cl_type;
cout<<"\n How many seats?";
cin>>seats;
cout<<"\n";
Tr.cancel(cl_type,seats);
break;
case 3:Tr.disp_status();
break;
case 4:break;
default : cout<<"Wrong choice!!\n";
}; //end of switch
} while(choice>=1&&choice<=3);
}
