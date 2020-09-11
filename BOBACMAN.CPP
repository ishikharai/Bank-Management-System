#include<fstream.h>
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
class bank
{
  char name[100];
  int account_no;
  char type[30];
  int dep;
  char phone_no[10];
  char addr[100];

 public:
  int number;
  int i;
  float amount;
  float balance;
  float newbal;
  void account_details()
  {
    char ch;
    cin.get(ch);
    cout<<"\n|---------------------------------------------------------|";
    cout<<"\n|                 Account Holder Details                  |";
    cout<<"\n|---------------------------------------------------------|";
    cout<<"\n|Enter Account Number:                                    |";
    cout<<"\n";
    cin>>account_no;
    cout<<"\n|Enter Name Of Account Holder:                            |";
    cout<<"\n";
    gets(name);
    cout<<"\n|Enter the type of account(current/savings):              |";
    cout<<"\n";
    gets(type);
    cout<<"\n|Enter the closing Balance in your account:               |";
    cout<<"\n";
    cin>>balance;
    cout<<"\n|Enter Phone number:                                      |";
    cout<<"\n";
    cin>>phone_no;
    cout<<"\n|Enter Address:                                           |";
    cout<<"\n";
    gets(addr);
    cout<<"\n|---------------------------------------------------------|";
  }

  void show_account_details()
  {
    cout<<"Account Number:"<<account_no<<"\nAccount holder name:"<<name
    <<"\nAccount Type:"<<type<<"\nClosing Balance:"<<balance<<"\nPhone No.:"
    <<phone_no<<"\nAddress:"<<addr<<cout<<"\n";
  }

  void modify()
  {
    cout<<"ACCOUNT NUMBER:"<<account_no<<"\t";
    cout<<"NAME:"<<name
    <<"\tTYPE:"<<type<<"\tADDRESS:"<<addr;
    cout<<"\nENTER NEW DETAILS:-\n";
    char nm[50]=" ";
    char tp[20]=" ";
    char adr[100]=" ";
    cout<<"NEW NAME:(enter '.' to retain old one)\n";
    cin>>nm;
    cout<<"NEW TYPE:(press'.' to retain old one)\n";
    cin>>tp;
    cout<<"NEW Address:(press'.' to retain old one)\n";
    cin>>adr;
    if(strcmp(nm,".")!=0)
      strcpy(name,nm);
    if(strcmp(tp,".")!=0)
      strcpy(type,tp);
    if(strcmp(adr,".")!=0)
      strcpy(addr,adr);
  }

  int getacno()
  {
    return account_no;
  }

}acc[3],ac,s,s2;

//Function To Deposit Amount
void newdeposit()
{
  int acNum;
  long p_no;
  char found='n';
  ifstream fii("bank.txt",ios::in);
  cout<<"Enter Account number to seached\n";
  cin>>s.number;
  while(!fii.eof())
  {
    fii.read((char*)&ac,sizeof(ac));
    if(ac.getacno()==s.number)
    {
      ac.show_account_details();
      found='y';
      break;
    }
  }
  if(found=='n')
  {
    cout<<"Wrong account number entered\n";
  }
  fii.close();
   cout<<"Enter Pan Card Number:\n";
   cin>>p_no;
   cout<<"Balance Present:\n";
   cin>>s.balance;
   cout<<"Enter account number to deposit amount\n";
   cin>>acNum;
   cout<<"\nEnter amount to be deposited:";
   cin>>s.amount;
   s.newbal= s.balance+s.amount;
   cout<<"\nAmount Rs"<<s.amount<<"\-";
   cout<<"\n Transferred to account Number"<<acNum;
   cout<<"\ncurrent balance in your acccount is"<<s.newbal;

}
void newwithdrwal()
{
  int acNum;
  long p_no;
  char found='f';
  ifstream fiii("bank.txt",ios::in);
  cout<<"Enter Account number to seached\n";
  cin>>s.number;
  while(!fiii.eof())
  {
    fiii.read((char*)&ac,sizeof(ac));
    if(ac.getacno()==s.number)
    {
      ac.show_account_details();
      found='o';
      break;
    }
  }
  if(found=='f')
  {
    cout<<"Wrong account number entered\n";
  }
  fiii.close();
   cout<<"PAN CARD NUMBER:\n";
   cin>>p_no;
   cout<<"\nbalance present:";
   cin>>s.balance;
   cout<<"\nEnter amount to be withdrawn:";
   cin>>s.amount;
   s.newbal= s.balance-s.amount;
   cout<<"\nAmount Rs"<<s.amount<<"\-withdrawn from your account";
   cout<<"\ncurrent balance in your acccount is"<<s.newbal;
}

//Function to enter data
void getdata()
{
  int i;
  fstream filin;
  filin.open("bank.txt",ios::in|ios::out);
  if(!filin)
  {
    cout<<"\nCannot open file!!\n";
  }
  cout<<"\nEnter details\n";
  for(i=0;i<3;i++)
  {
    acc[i].account_details();
    filin.write((char*)&acc[i],sizeof(acc[i]));
  }
  filin.seekg(0);
  cout<<"\nShow details:\n";
  for(i=0;i<3;i++)
  { filin.read((char*)&acc[i],sizeof(acc[i]));
    acc[i].show_account_details();

  }
  filin.close();
}

//function to add data to file
void add_details()
{
  char ans='y';
  ofstream fo("bank.txt",ios::app);
   while(ans=='y')
  {
    ac.account_details();
    fo.write((char*)&ac,sizeof(ac));
    cout<<"\nAccount added to file\n";
    cout<<"\nWant to add more account\n...";
    cin>>ans;
  }
  fo.close();
}
//Function To Search an Account
void search()
{
  char found='n';
  ifstream fi("bank.txt",ios::in);
  cout<<"Enter account number to be searched:\n";
  cin>>s.number;
  while(!fi.eof())
  {
    fi.read((char*)&ac,sizeof(ac));
    if(ac.getacno()==s.number)
    {
      ac.show_account_details();
      found='y';
      break;
    }
  }
  if(found=='n')
  {
    cout<<"Wrong account number entered\n";
  }
  fi.close();
}

//Function to Delete data from file
void delete_acc()
{
   ifstream fill("bank.txt",ios::in);
   ofstream foll("bank234.txt",ios::out);
   char last='p',confirm='y';
   cout<<"enter account number whose account is to be deleted:\n";
   cin>>s.number;
   while(!fill.eof())
   {
     fill.read((char*)&ac,sizeof(ac));
     if(ac.getacno()==s.number)
     {
       ac.show_account_details();
       last='q';
       cout<<"\nAre you sure, you want to delete this account(y/n)...\n";
       cin>>confirm;
       if(confirm=='y')
       foll.write((char*)&ac,sizeof(ac));
     }
     else
     {
       foll.write((char*)&ac,sizeof(ac));
     }
  }
   if(last=='p')
   cout<<"RECORD NOT FOUND\n";
   fill.close();
   foll.close();
   remove("bank.txt");
   rename("bank234.txt","bank.txt");
   fill.open("bank.txt",ios::in);
   cout<<"FILE NOW CONTAINS\n";
   while(!fill.eof())
   {
   fill.read((char*)&s,sizeof(s));
   //if(fill.eof())
   //break;
   s.show_account_details();
   }
   fill.close();
}
//function to modify data
void modify_acc()
{
 fstream fiio("bank.txt",ios::in|ios::out);
 long pos;
 char second='s';
 cout<<"Enter account number whose record is to be modified\n";
 cin>>s.number;
 while(!fiio.eof())
 {
   pos=fiio.tellg();
   fiio.read((char*)&ac,sizeof(ac));
   if(ac.getacno()==s.number)
   {
    ac.modify();
    fiio.seekg(pos);
    fiio.write((char*)&ac,sizeof(ac));
    second='r';
    break;
   }
}
 if(second=='s')
   {
     cout<<"RECORD NOT FOUND\n";
   }
   fiio.seekg(0);
   cout<<"NOW FILE CONTAINS\n";
  while(!fiio.eof())
  {
   fiio.read((char*)&s2,sizeof(s2));
   s2.show_account_details();
  }
 fiio.close();
}

//----------------------------main function--------------------------
int main()
{
start:
clrscr();
int choice;
cout<<"\n|------------------------------------------------|";
cout<<"\n|                   BANK OF BARODA               |";
cout<<"\n|------------------------------------------------|";
cout<<"\n|   WELCOME TO ACCOUNT MANAGEGMENT SYSTEM        |";
cout<<"\n|------------------------------------------------|";
cout<<"\n|           1.Show Account Details               |";
cout<<"\n|           2.Add New Account Detail             |";
cout<<"\n|           3.Search An Account                  |";
cout<<"\n|           4.Withdraw Amount                    |";
cout<<"\n|           5.Deposit Amount                     |";
cout<<"\n|           6.Modify An Account                  |";
cout<<"\n|           7.Close An Account                   |";
cout<<"\n|------------------------------------------------|";
cout<<"\nEnter Your Choice:";
cin>>choice;
switch(choice)
{
  case 1:
    clrscr();
    cout<<"\n|---------------------------------------------------|";
    cout<<"\n|            SHOW ACCOUNT DETAILS                   |";
    cout<<"\n|---------------------------------------------------|";
    cout<<"\n";
    getdata();
    break;
  case 2:
    clrscr();
    cout<<"\n|---------------------------------------------------|";
    cout<<"\n|              ADD NEW ACCOUNT                      |";
    cout<<"\n|---------------------------------------------------|";
    cout<<"\n";
    add_details();
    break;
  case 3:
    clrscr();
    cout<<"\n|---------------------------------------------------|";
    cout<<"\n|            SEARCH ACCOUNT DETAILS                 |";
    cout<<"\n|---------------------------------------------------|";
    cout<<"\n";
    search();
    break;
  case 4:
    clrscr();
    cout<<"\n|---------------------------------------------------|";
    cout<<"\n|              WITHDRAW AMOUNT                      |";
    cout<<"\n|---------------------------------------------------|";
    cout<<"\n";
    newwithdrwal();
    break;
  case 5:
    clrscr();
    cout<<"\n|---------------------------------------------------|";
    cout<<"\n|              DEPOSIT AMOUNT                       |";
    cout<<"\n|---------------------------------------------------|";
    cout<<"\n";
    newdeposit();
    break;
  case 6:
    clrscr();
    cout<<"\n|---------------------------------------------------|";
    cout<<"\n|            UPDATE ACCOUNT DETAILS                 |";
    cout<<"\n|---------------------------------------------------|";
    cout<<"\n";
    modify_acc();
    break;
  case 7:
    clrscr();
    cout<<"\n|---------------------------------------------------|";
    cout<<"\n|            DELETE ACCOUNT DETAIL                  |";
    cout<<"\n|---------------------------------------------------|";
    cout<<"\n";
    delete_acc();
    break;
    default:
    cout<<"\nWrong choice entered\n";
    break;
}
cout<<"\n|---------------------------------------------|\n";
cout<<"\n|             DO YOU WANT TO CONTINUE         |\n";
cout<<"\n|---------------------------------------------|\n";
cout<<"1.Continue\n";
cout<<"2.Exit\n";
cin>>choice;
    switch(choice)
    {
     case'1':
       goto start;
     case'2':
       cout<<"THANK YOU TO USE OUR SERVICE\n";
       getch();
       exit(0);
     default:
       cout<<"Invalid choice\n";
       break;
    }
return  0;
}
