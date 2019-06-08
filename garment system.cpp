#include<iostream>
#include<windows.h>
#include<string>
#include<fstream>
#include<stdio.h>
#include<conio.h>
using namespace std;
void purchase();
void show();
int choose();
void pants();
void shirts();
void bill();
int price=0;
void search();
void deleteFile();
void welcome()
{
	cout<<"\n\n\t\t\tWelcome To Garments Shop Management System\n";
}
void menu()
{
	again:
	int choice;
	system("cls");
	welcome();
	cout<<"\n\t1-Purchase\n\t2-Show \n\t3-Make Bill\n\t4-Exit\nEnter: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			purchase();
		break;
		case 2:
			show();
		break;
		case 3:
			bill();
		break;
		case 4:
			exit(0);
		break;
		default:
			{
				cout<<"Invalid Input Enter Again...";
				Sleep(2000);
				goto again;
			}
	}
	goto again;
}
void show()
{
	loop:
	int choice;
	system("cls");
	cout<<"\n\n\t\tPlease choose:\n\n\t1-Search Any Bill\n\t2-Delete Any Bill\n\t3-Back";
	cout<<"\nEnter: ";
	cin>>choice;
	if(choice==1)
	{
		search();
		getch();
	}
	else if(choice==2)
	{
		deleteFile();
		getch();
	}
	else if(choice==3)
	{
		menu();
	}
	else
	{
		cout<<"Invalid Input Enter again...";
		Sleep(2000);
		goto loop;
	}	
}
void search()
{
	string billNo="",fileName="";
	cout<<"Enter Bill No. ";
	cin>>billNo;
	fileName=billNo+".txt";
	fstream f;
	f.open(fileName.c_str(),ios::in);
	if(f)
	{
		char ch;
		while(f.get(ch))
		{
			cout<<ch;
		}
	}
	else
	{
		cout<<"Bill Not found";
		Sleep(2000);
		menu();
	}
}
void deleteFile()
{
	string billNo="",fileName="";
	cout<<"Enter Bill No. ";
	cin>>billNo;
	fileName=billNo+".txt";
	fstream f;
	f.open(fileName.c_str(),ios::in);
	if(f)
	{
		f.close();
		remove(fileName.c_str());
		cout<<"Bill has been removed. Successfully!";
		Sleep(2000);
	}
	else
	{
		cout<<"Bill Not found";
		Sleep(2000);
		menu();
	}
}
void logIn()
{
	loop:
	welcome();
	string name,pass;
	cout<<"\n\tEnter User Name:";
	cin>>name;
	cout<<"\n\tEnter Password:";
	cin>>pass;
	if(name!="waseem" && pass!="waseem")
	{
		cout<<"\n\n\tInvalid user name or password \n\tEnter Again...";
		Sleep(2000);
		system("cls");
		goto loop;
	}
}
int choose()
{
	int choice;
	system("cls");
	cout<<"\n\n\tPlease choose:\n\n\t\t1-Pants\n\t\t2-Shirts\n\t\t3-Back\nEnter: ";
	cin>>choice;
	return choice;
}
void bill()
{
	string billNo,bill="",date,fileName;
	cout<<"Enter Bill No.";
	cin>>billNo;
	bill+="\n\t\tGarments Management System\n\nBill No. "+billNo+"\nPrice "+std::to_string(price);
	bill+="\nDate ";
	cout<<"Enter Date(DD-MM-YYYY): ";
	cin>>date;
	bill+=date;
	fileName=billNo+".txt";
	fstream f;
	f.open(fileName.c_str(),ios::out);
	if(f)
	{
		f<<bill;
	}
}
void pants()
{
	loop:
	system("cls");
	int waist,choice;
	cout<<"\n\n\tPlease choose:\n\n\t\t1-Jeans Pants\n\t\t2-Dress pants\n\t\t3-Back\nEnter: ";
	cin>>choice;
	if(choice==1)
	{
		again:
		cout<<"\n\n\tPlease Enter your Waist: ";
		cin>>waist;
		if(isdigit(waist))
		{
			cout<<"Invalid Input Enter again...";
			Sleep(2000);
			goto again;
		}
		if(waist<30 || waist>38)
		{
			cout<<"Sorry this waist Pant is not available..";
			goto loop;
		}
		else 
		{
			char ch;
			cout<<"\n\n\t\t\tPants are available\n\n";
			cout<<"\twaist: "<<waist<<" \n\tPant Type: Jeans\n\tLength= 42\n\tColour: Blue, Balck\n\tPrice: 1000";
			cout<<"\n\n\tYou want to Buy?(Y/N)\n";
			cin>>ch;
			if(ch=='y' || ch=='Y')
			{
				price+=1000;
				goto loop;
			}
			else
			goto loop;
		}
	}
	else if(choice==2)
	{
		labelagain:
		cout<<"\n\n\tPlease Enter your Waist: ";
		cin>>waist;
		if(isdigit(waist))
		{
			cout<<"Invalid Input Enter again...";
			Sleep(2000);
			goto labelagain;
		}
		if(waist<30 || waist>38)
		{
			cout<<"Sorry this waist Pant is not available..";
			goto loop;
		}
		else 
		{
			char ch;
			cout<<"\n\n\t\t\tPants are available\n\n";
			cout<<"\twaist: "<<waist<<" \n\tPant Type: Dress Pants\n\tLength= 40\n\tColour: Blue, Balck\n\tPrice: 1500";
			cout<<"\n\n\tYou want to Buy?(Y/N)\n";
			cin>>ch;
			if(ch=='y' || ch=='Y')
			{
				price+=1500;
				goto loop;
			}
			else
			goto loop;
		}
	}
	else if(choice==3)
	{
		return;
	}
	else
	{
		cout<<"Invalid Input Enter again...";
		Sleep(2000);
		goto loop;
	}
}
void shirts()
{
	sh:
	string size="";
	system("cls");
	int waist,choice;
	cout<<"\n\n\tPlease choose:\n\n\t\t1-Casual Shirt\n\t\t2-Dress Shirt\n\t3-Back\nEnter: ";
	cin>>choice;
	if(choice==1)
	{
		again:
		cout<<"\n\n\tPlease Enter your size(M,L,XL): ";
		cin>>size;
		if(!(size=="m" ||size=="M" || size=="L" || size=="l"|| size=="xl" || size=="XL"))
		{
			cout<<"Sorry this size is not available..";
			goto sh;
		}
		else 
		{
			char ch;
			cout<<"\n\n\t\t\tShirt is Available\n\n";
			cout<<"\tSize: "<<size<<" \n\tShirt Type:Casual Shirt\n\tLength= 30\n\tColour: Blue, Balck\n\tPrice: 1000";
			cout<<"\n\n\tYou want to Buy?(Y/N)\n";
			cin>>ch;
			if(ch=='y' || ch=='Y')
			{
				price+=1000;
				goto sh;
			}
			else
			goto sh;
		}
	}
	else if(choice==2)
	{
		lab:
		cout<<"\n\n\tPlease Enter your size(M,L,XL): ";
		cin>>size;
		if(!(size=="m" ||size=="M" || size!="L" || size=="l"|| size=="xl" || size=="XL"))
		{
			cout<<"Sorry this size is not available..";
			goto lab;
		}
		else 
		{
			char ch;
			cout<<"\n\n\t\t\tShirt is Available\n\n";
			cout<<"\tSize: "<<size<<" \n\tShirt Type:Casual Shirt\n\tLength= 30\n\tColour: Blue, Balck\n\tPrice: 1000";
			cout<<"\n\n\tYou want to Buy?(Y/N)\n";
			cin>>ch;
			if(ch=='y' || ch=='Y')
			{
				price+=1000;
				goto sh;
			}
			else
			goto sh;
		}
	}
	else if(choice==3)
	{
		return;
	}
	else
	{
		cout<<"Invalid Input Enter again...";
		Sleep(2000);
		goto sh;
	}
}
void purchase()
{
	loop:
	int choice=choose();
	if(choice==1)
	{
		pants();
	}
	else if(choice==2)
	{
		shirts();
	}
	else if(choice==3)
	{
		menu();
	}
	else
	{
		cout<<"Invalid Input Enter again...";
		Sleep(2000);
		goto loop;
	}
}
int main()
{
	logIn();
	menu();
}

