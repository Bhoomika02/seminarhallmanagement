#include<bits/stdc++.h>
#include <ctime>
#include <cstring>
#include <string>
#include<vector>
#include<fstream>
#include<ctype.h>
#include<iomanip>
#include<conio.h>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

class seminar
{
	public:
		string date,time,branch,disc;
		
		void enter_data1();
        void search1();
		void pack1();
		
		void enter_data2();
        void search2();
		void pack2();
		
		void enter_data3();
        void search3();
		void pack3();
}s1;

struct index
{
	string date,time,branch,disc;
	int addr;
}i1[100],i2[100],i3[100],temp1,temp2,temp3;

int cnt1,cnt2,cnt3;
fstream fp;
fstream temp;

void create_index1();
void sort_index1();
int bin_srch1(string);
void del1();
void display1();

void create_index2();
void sort_index2();
int bin_srch2(string);
void del2();
void display2();

void create_index3();
void sort_index3();
int bin_srch3(string);
void del3();
void display3();

void error(int);



int main()
{
	char ch;
	int ch1, ch2, ch3;
	
	do
	{
		system("cls");
        cout<<" \n Seminar Hall names \n"<<"\n-----------------------------------------------------------------------------------------\n";
		cout<<" \n Seminar Hall 1 NAME\n";
		cout<<" \n Seminar Hall 2 NAME\n";
		cout<<" \n Seminar Hall 3 NAME\n";
		cout<<"\n EXIT 4 \n";
		cout<<"\nSelect Your Option : ";
		cin>>ch;
		system("cls");
		switch(ch)
		{
		case '1':
			
			system("cls");
	        cout<<" \nSeminar Hall names 1 MENU\n"<<"\n-----------------------------------------------------------------------------------------\n";
			cout<<"\n\n\t01. ADD ";
			cout<<"\n\n\t02. DISPLAY ";
			cout<<"\n\n\t03. SERCH BY DATE ";
			cout<<"\n\n\t04. DELETE";
			cout<<"\n\n\t05. EXIT";
			cout<<"\n\n\tSelect Your Option : ";
			cin>>ch1;
			system("cls");
			switch(ch1)
			{
			case 1:
				fp.open("record1.txt",ios::out|ios::app);
				fp.close();
				create_index1();
				s1.enter_data1();
				fp.open("record1.txt",ios::out|ios::app);
				if(!fp)
					error(1);
				s1.pack1();
				fp.close();
				break;
				
			case 2:
				display1();
				break;
				
			case 3:
				s1.search1();
				break;
				
			case 4:
				del1();
				break;
				
			 case 5:
				cout<<"\n\n\t Exiting seminar hall 1 BYE!!!!";
				break;
			}
		break;
			
		case '2':
			system("cls");
	        cout<<" \nSeminar Hall 2 NAME MENU\n"<<"\n-----------------------------------------------------------------------------------------\n";
			cout<<"\n\n\t01. ADD ";
			cout<<"\n\n\t02. DISPLAY ";
			cout<<"\n\n\t03. SERCH BY DATE ";
			cout<<"\n\n\t04. DELETE";
			cout<<"\n\n\t05. EXIT";
			cout<<"\n\n\tSelect Your Option : ";
			cin>>ch2;
			system("cls");
			switch(ch2)
			{
			case 1:
				fp.open("record2.txt",ios::out|ios::app);
				fp.close();
				create_index2();
				s1.enter_data2();
				fp.open("record2.txt",ios::out|ios::app);
				if(!fp)
					error(1);
				s1.pack2();
				fp.close();
				break;
				
			case 2:
				display2();
				break;
				
			case 3:
				s1.search2();
				break;
				
			case 4:
				del2();
				break;
				
			 case 5:
				cout<<"\n\n\t Exiting seminar hall 2 BYE!!!!";
				break;
			}	
		break;
			
		case '3':
			
			system("cls");
	        cout<<" \nSeminar Hall 3 NAME MENU\n"<<"\n-----------------------------------------------------------------------------------------\n";
			cout<<"\n\n\t01. ADD ";
			cout<<"\n\n\t02. DISPLAY ";
			cout<<"\n\n\t03. SERCH BY DATE ";
			cout<<"\n\n\t04. DELETE";
			cout<<"\n\n\t05. EXIT";
			cout<<"\n\n\tSelect Your Option : ";
			cin>>ch3;
			system("cls");
			switch(ch3)
			{
			case 1:
				fp.open("record3.txt",ios::out|ios::app);
				fp.close();
				create_index3();
				s1.enter_data3();
				fp.open("record3.txt",ios::out|ios::app);
				if(!fp)
					error(1);
				s1.pack3();
				fp.close();
				break;
				
			case 2:
				display3();
				break;
				
			case 3:
				s1.search3();
				break;
				
			case 4:
				del3();
				break;
				
			 case 5:
				cout<<"\n\n\t Exiting seminar hall 3 BYE!!!!";
				break;
			}	
			break;
			
		 case '4':
			cout<<"\n\n\t Exiting BYE!!!!";
			break;
		 default :cout<<"\a";
		}
		getch();
    }while(ch!='5');
	return 0;
	
}

void create_index1()
{
	int pos1, i;
	string seg, cidbuf;
	cnt1 = -1;
	fp.open("record1.txt", ios::in);
	if(!fp)
		error(1);
	while(fp)
	{
		cidbuf.erase();
		pos1 = fp.tellg();
		getline(fp, cidbuf, '|');
		getline(fp,seg);
		if(cidbuf[0] == '*'||cidbuf.length()==0)
			continue;
		cnt1++;
		i1[cnt1].date = cidbuf;
		i1[cnt1].addr = pos1;
	}
	fp.close();
	sort_index1();
}

void sort_index1()
{
    for(int i=0; i<=cnt1; i++)
    {
		for(int j=i+1; j<=cnt1; j++)
			if(i1[i].date>i1[j].date)
            {
                temp1.date = i1[i].date;
		        temp1.addr = i1[i].addr;

	        	i1[i].date = i1[j].date;
		        i1[i].addr = i1[j].addr;

	        	i1[j].date = temp1.date;
		        i1[j].addr = temp1.addr;
            }
	}
}

void seminar::enter_data1()
{
	cout<<"\n Enter date (dd/mm/yyyy) : ";
	cin>>date;
	cout<<"\n Enter time (hh.mm-hh.mm): ";
	cin>>time;
    cout<<"\n Enter branch : ";
    cin>>branch;
    cout<<"\n Enter dics : ";
	cin>>disc;
}	

void seminar::pack1()
{
    fp.seekg(0,ios::end);
	int pos1 = fp.tellg();
	string buf = date + "|" + time + "|" + branch + "|" + disc + "|"; 
	fp<<buf<<endl;
	cnt1++;
	i1[cnt1].date = date;
    i1[cnt1].addr = pos1;
	sort_index1();
}

int bin_srch1(string d_srch)
{
	int l=0, h = cnt1, mid;
	while(l<=h)
	{
		mid = (l+h)/2;
		if(i1[mid].date == d_srch) 
                {
              return mid;
                }
	
		if(i1[mid].date<d_srch)
             l = mid +1;
		if(i1[mid].date>d_srch) 
               h = mid -1;
	}
	return -1;
}

void seminar::search1()
{
	string d_srch, buf;
	cout<<"\nEnter the date to be found (dd/mm/yyyy) : \n";
	cin>>d_srch;
	int pos1 = bin_srch1(d_srch);
	if(pos1 == -1)
	{
		cout<<"\n \n Record Not Found \n \n ";
		return;

	}
	cout<<"\n \n Record found \n \n ";
	cout<<"date|time|branch|disc"<<endl;
	fp.open("record1.txt",ios::in);
	if(!fp)
		error(1);
	fp.seekg(i1[pos1].addr, ios::beg);
	getline(fp, buf);
	fp.close();

	cout<<buf<<endl;
}

void del1()
{
	string date;
	int w=0;
	int t=0;
	int position;
	string line;
	fp.open("record1.txt",ios::in);
	temp.open("temp.txt",ios::out|ios::app);
	cout<<" 	Enter the date (dd/mm/yyyy) : ";
	cin>>date;
	while(getline(fp,line))
	{
		position=line.find(date);
	
		if(position!=0)
		{
			temp<<line<<endl;
		}
		
	}
	fp.close();
	temp.close();
	fp.open("record1.txt",ios::in);
	while(getline(fp,line))
	{
		w++;					
	}
	w--;
	temp.open("temp.txt",ios::in);
	while(getline(temp,line))
	{
		t++;
	}
	t--;
	if(w==t)
	{
		cout<<"\n no record found ! ! !"<<endl;
	}
	else{
		cout<<"\n record deleted successfully !"<<endl;
	}
	fp.close();
	temp.close();
	remove("record1.txt");
	rename("temp.txt","record1.txt");
}

void display1()
{
	string line;
	ifstream out("record1.txt");
	cout<<"\nThe Seminar hall details are :\n"<<endl;
	cout<<"date|time|branch|disc|"<<endl;
	while(getline(out,line))
	{
		cout<< line << endl;
	}
	out.close();
	
}

/*seminar hall 2*/
void create_index2()
{
	int pos2, i;
	string seg, regnobuf;
	cnt2 = -1;
	fp.open("record2.txt", ios::in);
	if(!fp)
		error(1);
	while(fp)
	{
		regnobuf.erase();
		pos2 = fp.tellg();
		getline(fp, regnobuf, '|');
		getline(fp,seg);
		if(regnobuf[0] == '*'||regnobuf.length()==0)
			continue;
		cnt2++;
		i2[cnt2].date = regnobuf;
		i2[cnt2].addr = pos2;
	}
	fp.close();
	sort_index2();
}

void sort_index2()
{
    for(int i=0; i<=cnt2; i++)
    {
		for(int j=i+1; j<=cnt2; j++)
			if(i2[i].date>i2[j].date)
            {
                temp2.date = i2[i].date;
		        temp2.addr = i2[i].addr;

	        	i2[i].date = i2[j].date;
		        i2[i].addr = i2[j].addr;

	        	i2[j].date = temp2.date;
		        i2[j].addr = temp2.addr;
            }
	}
}

void seminar::enter_data2()
{
	cout<<"\n Enter date (dd/mm/yyyy) : ";
	cin>>date;
	cout<<"\n Enter time (hh.mm-hh.mm) : ";
	cin>>time;
    cout<<"\n Enter branch : ";
    cin>>branch;
    cout<<"\n Enter dics : ";
	cin>>disc;
}	

void seminar::pack2()
{
    fp.seekg(0,ios::end);
	int pos2 = fp.tellg();
	string buf = date + "|" + time + "|" + branch + "|" + disc + "|"; 
	fp<<buf<<endl;
	cnt2++;
	i2[cnt2].date = date;
      i2[cnt2].addr = pos2;
	sort_index2();
}

int bin_srch2(string d_srch)
{
	int l=0, h = cnt2, mid;
	while(l<=h)
	{
		mid = (l+h)/2;
		if(i2[mid].date == d_srch) 
                {
              return mid;
                }
	
		if(i2[mid].date<d_srch)
             l = mid +1;
		if(i2[mid].date>d_srch) 
               h = mid -1;
	}
	return -1;
}

void seminar::search2()
{
	string d_srch, buf;
	cout<<"\nEnter the date to be found (dd/mm/yyyy) : \n";
	cin>>d_srch;
	int pos2 = bin_srch2(d_srch);
	if(pos2 == -1)
	{
		cout<<"\n Record Not Found \n";
		return;

	}
	cout<<"\n \n Record found \n \n ";
	cout<<"date|time|branch|disc"<<endl;
	fp.open("record2.txt",ios::in);
	if(!fp)
		error(1);
	fp.seekg(i2[pos2].addr, ios::beg);
	getline(fp, buf);
	fp.close();
	cout<<buf<<endl;
}

void del2()
{
	string date;
	int w=0;
	int t=0;
	int position;
	string line;
	fp.open("record2.txt",ios::in);
	temp.open("temp.txt",ios::out|ios::app);
	cout<<" 	Enter the date (dd/mm/yyyy) : ";
	cin>>date;
	while(getline(fp,line))
	{
		position=line.find(date);
	
		if(position!=0)
		{
			temp<<line<<endl;
		}
		
	}
	fp.close();
	temp.close();
	fp.open("record2.txt",ios::in);
	while(getline(fp,line))
	{
		w++;					
	}
	w--;
	temp.open("temp.txt",ios::in);
	while(getline(temp,line))
	{
		t++;
	}
	t--;
	if(w==t)
	{
		cout<<"\n no record found ! ! !"<<endl;
	}
	else{
		cout<<"\n record deleted successfully !"<<endl;
	}
	fp.close();
	temp.close();
	remove("record2.txt");
	rename("temp.txt","record2.txt");
}

void display2()
{
	string line;
	ifstream out("record2.txt");
	cout<<"\n The Seminar hall details are :\n"<<endl;
	cout<<"date|time|branch|disc|"<<endl;
	while(getline(out,line))
	{
		cout<< line << endl;
	}
	out.close();
	
}

/* Seminar hall 3*/


void create_index3()
{
	int pos3, i;
	string seg, regnobuf;
	cnt3 = -1;
	fp.open("record3.txt", ios::in);
	if(!fp)
		error(1);
	while(fp)
	{
		regnobuf.erase();
		pos3 = fp.tellg();
		getline(fp, regnobuf, '|');
		getline(fp,seg);
		if(regnobuf[0] == '*'||regnobuf.length()==0)
			continue;
		cnt3++;
		i3[cnt3].date = regnobuf;
		i3[cnt3].addr = pos3;
	}
	fp.close();
	sort_index3();
}

void sort_index3()
{
    for(int i=0; i<=cnt3; i++)
    {
		for(int j=i+1; j<=cnt3; j++)
			if(i3[i].date>i3[j].date)
            {
                temp3.date = i3[i].date;
		        temp3.addr = i3[i].addr;

	        	i3[i].date = i3[j].date;
		        i3[i].addr = i3[j].addr;

	        	i3[j].date = temp3.date;
		        i3[j].addr = temp3.addr;
            }
	}
}

void seminar::enter_data3()
{
	cout<<"\n Enter date (dd/mm/yyyy) : ";
	cin>>date;
	cout<<"\n Enter time (hh.mm-hh.mm) : ";
	cin>>time;
    cout<<"\n Enter branch : ";
    cin>>branch;
    cout<<"\n Enter dics : ";
	cin>>disc;
}	

void seminar::pack3()
{
    fp.seekg(0,ios::end);
	int pos3 = fp.tellg();
	string buf = date + "|" + time + "|" + branch + "|" + disc + "|"; 
	fp<<buf<<endl;
	cnt3++;
	i3[cnt3].date = date;
      i3[cnt3].addr = pos3;
	sort_index3();
}

int bin_srch3(string d_srch)
{
	int l=0, h = cnt3, mid;
	while(l<=h)
	{
		mid = (l+h)/2;
		if(i3[mid].date == d_srch) 
                {
              return mid;
                }
	
		if(i3[mid].date<d_srch)
             l = mid +1;
		if(i3[mid].date>d_srch) 
               h = mid -1;
	}
	return -1;
}

void seminar::search3()
{
	string d_srch, buf;
	cout<<"\n Enter the date to be found (dd/mm/yyyy) : \n";
	cin>>d_srch;
	int pos3 = bin_srch3(d_srch);
	if(pos3 == -1)
	{
		cout<<"\n Record Not Found \n";
		return;

	}
	cout<<"\n\n  Record found \n\n";
	cout<<"date|time|branch|disc"<<endl;
	fp.open("record3.txt",ios::in);
	if(!fp)
		error(1);
	fp.seekg(i3[pos3].addr, ios::beg);
	getline(fp, buf);
	fp.close();
	cout<<buf<<endl;
}

void del3()
{
	string date;
	int w=0;
	int t=0;
	int position;
	string line;
	fp.open("record3.txt",ios::in);
	temp.open("temp.txt",ios::out|ios::app);
	cout<<" 	Enter the date (dd/mm/yyyy) : ";
	cin>>date;
	while(getline(fp,line))
	{
		position=line.find(date);
	
		if(position!=0)
		{
			temp<<line<<endl;
		}
		
	}
	fp.close();
	temp.close();
	fp.open("record3.txt",ios::in);
	while(getline(fp,line))
	{
		w++;					
	}
	w--;
	temp.open("temp.txt",ios::in);
	while(getline(temp,line))
	{
		t++;
	}
	t--;
	if(w==t)
	{
		cout<<"\n no record found ! ! !"<<endl;
	}
	else{
		cout<<"\n record deleted successfully !"<<endl;
	}
	fp.close();
	temp.close();
	remove("record3.txt");
	rename("temp.txt","record3.txt");
}

void display3()
{
	string line;
	ifstream out("record3.txt");
	cout<<"\nThe Seminar hall details are :\n"<<endl;
	cout<<"date|time|branch|disc|"<<endl;
	while(getline(out,line))
	{
		cout<< line << endl;
	}
	out.close();
	
}




void error(int error_type)
{
	switch(error_type)
	{
		case 1: cout<<"\nFATAL ERROR!: Unable to open the record File\n";
			exit(0);		
	}
}

