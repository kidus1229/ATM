#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <ctime>


using namespace std;
class atm
{
  public:
string Fname,Lname;
int account_no,trans_account,pin_no,option,pino, P;
int account_No[100] ;
int Pin[100];

double check,amount, atm,atmCash  ,bal[100];

    string FirstName,LastName;
	string firstname[100];
	string lastname[100];
    string a=" ";
    
//#####################
//#      balance      #
//#####################

   double balance(int account_no, int pin_no)
   {
   	ifstream File;
	File.open("accounts.txt");
	int z=0;
	while (!File.eof())
	{
		File>> *(account_No+z)  >> Pin[z]>>bal[z]>>firstname[z]>>lastname[z];
	if (account_no == *(account_No+z) && pin_no==Pin[z])
	{
   	  return bal[z];
   	  
   }

   }
 }
 
//#################################
//#    get amount cash in ATM     # 
//#################################

 double atm_cash()
{
  ifstream File;
  File.open("atm_cash.txt");
  while (!File.eof())
  {
    File>>atmCash;
    }
    File.close();
    return atmCash;
}

//#####################################
//#   update amount of cash in ATM    #
//#####################################

void update_atm(double atm)
{
  ofstream file;
  file.open("atm_cash.txt");
  file<<atm;

    file.close();
}

//#####################
//#      withdraw     #
//#####################

void withdraw(int account_no, int pin_no, double amount)
{
  atm=atm_cash();
  if(atm<amount)
  {
    cout<<"ATM is out of cash";
    exit(1);
  }
    ifstream File;
  File.open("accounts.txt");
  int i=0;
  while (!File.eof())
  {
    File>> *(account_No+i)  >> Pin[i]>>bal[i]>>firstname[i]>>lastname[i];
  if (account_no == *(account_No+i) && pin_no==Pin[i])
  {
  	Fname=firstname[i];
  	Lname=lastname[i];
    if(bal[i]<amount)
    {
    	
      cout<<"you only have "<<bal[i]<<" birr\n\n";
    
    }
    else
    {
    	bal[i] -= amount;
    		atm-=amount;
update_atm(atm);

	time_t tt;
	      struct tm * ti;
          time (&tt) ;
		  ti = localtime (&tt) ;
       	  cout << "Transaction time: "
    	  << asctime (ti) << endl;

ofstream file;
	file.open("Log.txt",ios::app);
	file<<Fname<<a<<Lname<<" withdraw "<<amount<<a<<"birr "<<asctime (ti);
	file.close();
	cout<<"you have successfully withdraw "<<amount<<" birr\n\n";
	}
    
  }
  ++i;


}
File.close();

    ofstream file;
  file.open("accounts.txt");
  for(int j=0;j<i-1;j++){
    file<<*(account_No+j)<<a<<Pin[j]<<a<<bal[j]<<a<<firstname[j]<<a<<lastname[j]<<endl;
    bal[i] -= amount;
  }
  file.close();





}

//#####################
//#      Deposit      #
//#####################

void deposit(int account_no, int pin_no ,double amount)
{

    ifstream File;
  File.open("accounts.txt");
  int i=0;
  while (!File.eof())
  {
    File>> *(account_No+i)  >> Pin[i]>>bal[i]>>firstname[i]>>lastname[i];
  if (account_no == *(account_No+i) && pin_no==Pin[i])
  {
    Fname=firstname[i];
  	Lname=lastname[i];
    bal[i] += amount;
  }
  ++i;
}
File.close();

    ofstream file;
  file.open("accounts.txt");
  for(int j=0;j<i-1;j++){
    file<<*(account_No+j)<<a<<Pin[j]<<a<<bal[j]<<a<<firstname[j]<<a<<lastname[j]<<endl;
  }
  file.close();


  atm=atm_cash();
atm+=amount;
update_atm(atm);

time_t tt;
	      struct tm * ti;
          time (&tt) ;
		  ti = localtime (&tt) ;
       	  cout << "Transaction time: "
    	  << asctime (ti) << endl;


	file.open("Log.txt",ios::app);
	file<<Fname<<a<<Lname<<" deposit "<<amount<<a<<"birr "<<asctime (ti);
	file.close();

}

//#########################
//#    check account      #
//#########################

bool isTrue(int account_no, int pino)
{
	ifstream File;
	File.open("accounts.txt");
	int x=0 ;
	while (!File.eof()){              // end of file
		File>>account_No[x]>>Pin[x]>>bal[x]>>firstname[x]>>lastname[x];
	if (account_no==account_No[x] && pino==Pin[x] )
	{
		
		return true;
	}
	++x;

}
system("cls");
cout<<"\n\n\n\n\n\n\t\t\t";
cout << "Error! Your account number and pin does not match! "<< "\n\n\t\t\tPlease try again! \n";
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t";
system("pause");
return false;
}

//#######################
//#      Change pin     #
//#######################

void change_Pin(int account_no, int pin_no, int P )
{

	ifstream File;
	File.open("accounts.txt");
	int i=0;
	while (!File.eof())
	{
		File>> *(account_No+i)  >> Pin[i]>>bal[i]>>firstname[i]>>lastname[i];
	if (account_no == *(account_No+i) && pin_no==Pin[i])
	{
        Fname=firstname[i];
  	    Lname=lastname[i]; 
		Pin[i] = P ;
	}
	++i;
}
File.close();

    ofstream file;
	file.open("accounts.txt");
	for(int j=0;j<i-1;j++){
		file<<*(account_No+j)<<a<<Pin[j]<<a<<bal[j]<<a<<firstname[j]<<a<<lastname[j]<<endl;

	}
	file.close();
	 
	 
	 time_t tt;
	      struct tm * ti;
          time (&tt) ;
		  ti = localtime (&tt) ;
       	  cout <<"You pin has been changed to "<<P<<" at: "
    	  << asctime (ti) << endl;


	file.open("Log.txt",ios::app);
	file<<Fname<<a<<Lname<<" changed pin to "<<P<<a<<asctime (ti);
	file.close();
}

//#################################
//#  check Pin and change pin     #
//#################################

void checkPin(int account_no, int pin_no , int p)
    {
    	START1:
    		system("cls");
    	int p1,p2;
	    cout<<"Please select a new 4-digit numerical PIN"<<endl<<"# ";
        cin>>p1;
       while(p1 < 1000 || p1 > 9999)
            {
            	system("cls");
                cout<<"Please Select only 4-digit numerical PIN"<<endl<<"# ";
                cin>>p1;
                goto START1 ;
            }


				cout<<"Please type your new PIN again"<<endl<<"# ";
				cin>>p2;

			while(p1!=p2)
			{
				cout<<"please Enter same PIN\n";
				system("pause");
				goto START1;
			}

        change_Pin(account_no,pin_no, p2 );
    }
    
//############################
//#        transfer          #
//############################

  void Transfer(int account_no,int trans_account,double trans_amount)
{
	string TransFname , TransLname ;
	ifstream File;
	File.open("accounts.txt");
	int b=0;
	while (!File.eof())
	{
		File>>account_No[b]>>Pin[b]>>bal[b]>>firstname[b]>>lastname[b];
		if(account_no==account_No[b])
		{
			Fname=firstname[b];
            Lname=lastname[b]; 
		}
	    if (trans_account==account_No[b])
	    {
		bal[b] += trans_amount;

		TransFname = firstname [b] ;
		TransLname = lastname [b] ;
	    }
	    ++b;
    }
File.close();

    ofstream file;
	file.open("accounts.txt");
	for(int j=0;j<b-1;j++)
	{
		file<<account_No[j]<<a<<Pin[j]<<a<<bal[j]<<a<<firstname[j]<<a<<lastname[j]<<endl;
	}
	file.close();
	cout << "And transfered to "<< TransFname << " "<< TransLname << endl;
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t";
atm=atm_cash();
atm+=trans_amount;
update_atm(atm);
  	
  	time_t tt;
	      struct tm * ti;
          time (&tt) ;
		  ti = localtime (&tt) ;
       	  

	file.open("Log.txt",ios::app);
	file<<trans_amount<<" birr was deposited to "<<TransFname<<a<<TransLname<<a<<asctime (ti);
	file.close();
	
}

//##########################
//#    create account      #
//##########################

void create_account()
{
int account_no,no;
  int pin,PIN;
  double bal,initial;
  string FirstName,LastName,firstname,lastname;
  string a=" ";
  cout<<"Enter your First Name: ";
  cin>>FirstName;
  cout<<"Enter your Last Name: ";
  cin>>LastName;
  do
  {
    cout<<"Enter the initial saving amount(>=25): ";
        cin>>initial;

        ifstream File("accounts.txt");
  while(File>>no>>PIN>>bal>>firstname>>lastname){
    account_no=no+1;
      pin=PIN+10;
  }
  File.close();

  }while(initial<25);
  ofstream file("accounts.txt",ios::app);
  file<<"\n"<<account_no<<a<<pin<<a<<initial<<a<<FirstName<<a<<LastName;
  file.close();
    
    cout<< "Your Account Number is: "<<account_no<<endl;
    cout<< "Your Pin Number is: "<<pin<< endl;
    cout<< "Your balance is: "<<initial << " birr\n";
  atm=atm_cash() ;
  atm+=initial;
  update_atm(atm); 
  
  	time_t tt;
	      struct tm * ti;
          time (&tt) ;
		  ti = localtime (&tt) ;
       	  cout << "Account created: "
    	  << asctime (ti) << endl;


	file.open("Log.txt",ios::app);
	file<<"account was created for \""<<FirstName<<a<<LastName<<"\""<<a<<asctime (ti);
	file.close();
  
}

};
//the above all is class until this comment!




 int main ()

    {
    atm ATM;
    
  system("color 0c");
  int account_no,pin_no,option, ch1;
  string First_name, Last_name;
  double amount,update;

  
  

cout << "\t\t\t\t  " <<setw (50) << setfill ('*') << "*" << endl;
  cout<<"\t\t\t\t\tWELCOME TO COMMERCIAL BANK OF ETHIOPIA!!!\n";
  	cout << "  \t\t\t\t  " <<setw (50) << setfill ('*') << "*" << endl;
  	cout<<"\n\n";
               cout<<"\t         ____________________        ___________                     ____________________ \n"    ;
	           cout<<"\t        /                    |      |           \\                   /                    | \n"   ;   
	           cout<<"\t       /                     |      |     ___     \\                /                     | \n" ;       
	           cout<<"\t      /      ________________|      |    |    \\     \\             /      ________________|  \n" ;           
	           cout<<"\t     /      /                       |    |     \\      \\          /      /            \n";
	           cout<<"\t    /      /                        |    |     /      /         /      /              \n";
	           cout<<"\t   /      /                         |    |___ /     /          /      /                \n";
	           cout<<"\t  /      /                          |             /           /      /____________        \n";
	           cout<<"\t /      /                           |           /            /                    |\n";
               cout<<"\t/      /                            |           \\           /                     | \n";
	           cout<<"\t\\      \\                            |     ____    \\         \\        _____________|    \n"     ;
	           cout<<"\t \\      \\                           |    |     \\    \\        \\      \\       \n";
	           cout<<"\t  \\      \\                          |    |      \\     \\       \\      \\      \n";
	           cout<<"\t   \\      \\                         |    |       \\      \\      \\      \\     \n";
	           cout<<"\t    \\      \\                        |    |       /      /       \\      \\       \n"   ;
	           cout<<"\t     \\      \\________________       |    |      /     /          \\      \\________________   \n";
               cout<<"\t      \\                      |      |    |____ /    /             \\                      |\n";
               cout<<"\t       \\                     |      |             /                \\                     |\n";
               cout<<"\t        \\____________________|      |___________/                   \\____________________| \n";
cout<<"\n\n\n\n\t\t\t\t\t\t\t\t\t\t";

 system ("pause");
   START:
    system("cls");
   
    cout<<"\n\n\n\n" ;   
    cout << "\t\t\t " << setw (30)<< setfill ('*') <<"*" << "\n";
    cout<<"\t\t\t|*|\t1. Login" << setw(12)<<left<<setfill (' ')<< " "<< "|*|\n"  ;
    cout << "\t\t\t|*| " <<"                        " <<"|*|" << "\n";
    cout << "\t\t\t|*| " <<"                       " <<(' ') <<"|*|" << "\n";     
    cout << "\t\t\t|*| " <<"                       " <<(' ') <<"|*|" << "\n";
    cout<<"\t\t\t|*|\t2. Exit" << setw(13)<<setfill (' ')<< " "<< "|*|\n"  ;
    cout << "\t\t\t " <<setw(30) <<setfill ('*') <<"*" << "\n";

cout<<"\n\n";
    cout << "\t\tEnter Your choice\t";
     cin >> ch1;


    system("cls");
    switch (ch1)
	{

 case 1:
 do
 {

system("cls");
    cout<<"\n\n\n\n\n\n\n\n\t\t\t";
    cout << "Enter your Account Number:  ";
    cin >> account_no ;
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\t\t\t";
    cout << "Enter Your pin:  ";
	cin >> pin_no ;
}while (!ATM.isTrue(account_no , pin_no )) ;





      START2:
      	system("cls") ;
      	cout<<"\n\n\n\n\t\t\t";
    cout << "\t" << setw (36)<< setfill ('*')<< "*" << endl;
    cout<<"\t\t\t";
             cout << "\t"  << setw (1)<< setfill ('*')<< "*" <<left << setw(34) << setfill(' ')

             <<" "  << setw(1) << setfill ('*') << "*" <<endl;
           cout<<"\t\t\t";
             cout << "\t"  << setw (1)<< setfill ('*')<< "*" <<left << setw(28) << setfill(' ')

             <<"\t   1.Check Balance"  << setw(1) << setfill ('*') << "*" <<endl;
             cout<<"\t\t\t";
             cout << "\t"  << setw (1)<< setfill ('*')<< "*" <<left << setw(34) << setfill(' ')

             <<" "  << setw(1) << setfill ('*') << "*" <<endl;
             cout<<"\t\t\t";
             
              cout << "\t"  << setw (1)<< setfill ('*')<< "*" <<left << setw(28) << setfill(' ')
             <<"\t   2.Withdrawal"  << setw(1) << setfill ('*') << "*" << endl ;
             cout<<"\t\t\t";
             cout << "\t"  << setw (1)<< setfill ('*')<< "*" <<left << setw(34) << setfill(' ')

             <<" "  << setw(1) << setfill ('*') << "*" <<endl;
             cout<<"\t\t\t";
             cout << "\t"  << setw (1)<< setfill ('*')<< "*" <<left << setw(28) << setfill(' ')
             <<"\t   3.Deposit"  << setw(1) << setfill ('*') << "*" <<endl;
             cout<<"\t\t\t";
             cout << "\t"  << setw (1)<< setfill ('*')<< "*" <<left << setw(34) << setfill(' ')

             <<" "  << setw(1) << setfill ('*') << "*" <<endl;
             cout<<"\t\t\t";
              cout << "\t"  << setw (1)<< setfill ('*')<< "*" <<left << setw(28) << setfill(' ')




			 <<"\t   4.Transfer"  << setw(1) << setfill ('*') << "*" <<endl;
			 cout<<"\t\t\t";
             cout << "\t"  << setw (1)<< setfill ('*')<< "*" <<left << setw(34) << setfill(' ')

             <<" "  << setw(1) << setfill ('*') << "*" <<endl;
			 cout<<"\t\t\t";
			  cout << "\t"  << setw (1)<< setfill ('*')<< "*" <<left << setw(28) << setfill(' ')
			 <<"\t   5.Change Pin"  << setw(1) << setfill ('*') << "*" <<endl;
			 cout<<"\t\t\t";
             cout << "\t"  << setw (1)<< setfill ('*')<< "*" <<left << setw(34) << setfill(' ')

             <<" "  << setw(1) << setfill ('*') << "*" <<endl;
			 cout<<"\t\t\t";
			  cout << "\t"  << setw (1)<< setfill ('*')<< "*" <<left << setw(28) << setfill(' ')
			 <<"\t   6.Main Menu"  << setw(1) << setfill ('*') << "*" <<endl;
			 cout<<"\t\t\t";
             cout << "\t"  << setw (1)<< setfill ('*')<< "*" <<left << setw(34) << setfill(' ')

             <<" "  << setw(1) << setfill ('*') << "*" <<endl;
			 cout<<"\t\t\t";
             cout << "\t"  << setw (36)<< setfill ('*')<< "*" << endl;
             
             cout << "\n\t\t   Enter Your Choice:   ";
             cin >> option ;






        switch (option)
		{
        	case 1 :
            system("cls");
            cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t";
        	cout <<"\tYou have "<<	ATM.balance(account_no, pin_no) << " birr \n\n\n";
        	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t";
        	system ("pause") ;
        	goto START2;
        	break ;

        	case 2 :
        		system("cls");
        		cout<<"\n\n\n\n\n\n\t\t\t";
        		cout << "Enter the amount of money you want to withdraw:  ";
        		
        		cin >> amount ;
        		system("cls");
        		ATM.withdraw (account_no , pin_no , amount) ;
        		
        	system ("pause") ;
        	goto START2;

        	break ;

        	case 3 :
        		system("cls");
        		cout<<"\n\n\n\n\n\n\t\t";
        	cout << "Enter the amount of money you want to deposit:  ";
        		cin >> amount ;
            system("cls");
        		ATM.deposit (account_no, pin_no,amount);
        		
        			cout << "You have successfully Depossited " << amount << " birr\n";
        		cout << "Your balance is "<< ATM.balance(account_no, pin_no) << " birr now.\n\n\n" ;



        		system ("pause") ;
        		goto START2;
             	break ;

        	case 4:
        		system("cls");
        		cout<<"\n\n\n\n\n\n\t\t";
    		cout<<"Enter the account number you want to transfer to:  ";
			     cin>> ATM.trans_account;
			     system("cls");
	     cout<<"\n\n\n\n\n\n\t\t";
			cout<<"\tEnter the amount to transfer:  ";
			     cin>>amount;
			     system("cls");
			ATM.withdraw(account_no , pin_no,amount);
			ATM.Transfer(account_no,ATM.trans_account,amount);
			     system ("pause") ;
        	     goto START2;
        	break ;

            case 5 :

				if (ATM.isTrue(account_no , pin_no))
			{
					ATM.checkPin (account_no, pin_no,pin_no) ;
			}
					system ("pause") ;
        			goto START;
        		break ;

        	case 6:
        		goto START;

        	default : cout << "Please enter the correct value!\n\n" ;
        	system ("pause") ; goto START2 ;
                   break ;
        	break;
		}

 case 1229:
 	  int o;
 	cout<<"\n\n\n\n" ;   
    cout << "\t\t\t " << setw (30)<< setfill ('*') <<"*" << "\n";
    cout<<"\t\t\t|*|\t1. Create Account" << setw(4)<<setfill (' ')<< " "<< "|*|\n"  ;
    cout << "\t\t\t|*| " << "                         " <<"|*|" << "\n";
    cout<<"\t\t\t|*|\t2. ATM cash update" << setw(3)<<setfill (' ')<< " "<< "|*|\n"  ;
    cout << "\t\t\t " <<setw(30) <<setfill ('*') <<"*" << "\n";
    cout << "\n\t\tEnter Your choice  ";
	      cin>>o;
	      switch (o)
	      {
	      	case 1:
	      			ATM.create_account () ;
                    system ("pause") ;
                    goto START;
                    break ;
            case 2:
            		cout<<"\n\n\n\n" ;
            	    cout<<"\t\tEnter the amount of money to add:  ";
            	    
					 cin>>update;
					 update+=ATM.atm_cash();
            	    ATM.update_atm(update);
            	    cout<<"ATM cash successfully updated";
            	    exit(1);
          default : cout << "Please Enter the proper value!\n\n";
                   system ("pause") ; goto START;
                   break ;
		  }
 

case 2:
goto END ;

    default : cout << "Please Enter the proper value!\n\n";
                   system ("pause") ; goto START;
                   break ;
    }
END:
	cout<<"\n\n\n\n\n\n\n\n";
cout << "\t\t\t  " <<setw (60) << setfill ('*') << "*" << endl;
  cout<<"\t\t\t\tTHANKYOU FOR USING COMMERCIAL BANK OF ETHIOPIA!!!\n";
  	cout << "  \t\t\t  " <<setw (60) << setfill ('*') << "*" << endl;
  		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t";
  	system("pause");
  	system("cls");
    return 0;
    }



