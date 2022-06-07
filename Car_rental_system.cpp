#include <iostream>
#include <fstream>
#include <conio.h>
#include <unistd.h>
#include <iomanip> 
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
using namespace std;
class customer //customer class
{
	private:
	public: //variables defined in this class in public mode.
	char customername[50], address[50];
    string carmodel, carmodel_nm, confirm;
    int contact, carnumber, invoice_no, drivernumber;
};
class rent:public customer //inherited class from customer class
{
	public:
	int days,rentalfee,driverfee,totalfee; //additional int variables
	char driver;
	void data()
	{
	int login();
	login();	
	cout<<"\t\t\tEnter Your Name: "; //taking name from the user
    cin.getline(customername,49);
    fflush(stdin);
    cout<<"\t\t\tEnter Your Address: "; //taking address from the user
    cin.getline(address,49);
    cout<<"\t\t\tEnter Your Mobile number: "; //taking contact number from the user
    cin>>contact;
    do
    {   start0: 
        cout<<"\n\n\t\t\tPlease Select a Car"<<endl; //giving user a choice to select among different models
        cout<<"\n\t\t\tEnter 1 : for Tesla Model S.\n\t\t\tRent(per day) : Rs.5000"<<endl;
        cout<<"\n\t\t\tEnter 2 : for Hyundai i10.\n\t\t\tRent(per day) : Rs.1000"<<endl;
        cout<<"\n\t\t\tEnter 3 : for Ford Mustang.\n\t\t\tRent(per day) : Rs.3000"<<endl;
        cout<<"\n\t\t\tEnter 4 : for Mercedes Benz E-Class.\n\t\t\tRent(per day) : Rs.4000"<<endl;
        cout<<"\n\t\t\tEnter 5 : for Toyota Fortuner.\n\t\t\tRent(per day) : Rs.2000"<<endl;
        cout<<endl;
        cout<<"\t\t\tChoose a Car from the above options: ";
        cin>>carmodel;
        cout<<"\n\n\t\t\t--------------------------------------------------------------------------\n\n"<<endl;
        system("CLS");
        fstream Cars;
    if(carmodel=="1")    	
        Cars.open("Tesla.txt",ios::in);
    if(carmodel=="2")
        Cars.open("Hyundai.txt",ios::in);
    if(carmodel=="3")
		Cars.open("Ford.txt",ios::in);
    if(carmodel=="4")
		Cars.open("Mercedes.txt",ios::in);
    if(carmodel=="5")
		Cars.open("Toyota.txt",ios::in);
	if(Cars.is_open())
	{
		string car;
		while(getline(Cars, car))
		cout<<car<<endl;
	    Cars.close();
	}
      if(carmodel!="1" && carmodel!="2" && carmodel!="3" && carmodel!="4" && carmodel!="5")
      cout<<"\n\n\t\t\tInvaild Car Model. Please try again!"<<endl;
    }
    while(carmodel!="1" && carmodel!="2" && carmodel!="3" && carmodel!="4" && carmodel!="5");
    cout<<"\n\n\t\t\t-------------------------------------------------------------------\n"<<endl;
    sleep(1);
    cout<<"\n\t\t\tPlease confirm:"<<endl;
	cout<<"\n\t\t\tEnter 'Y' to confirm or 'N' to select again. To exit Car Rental System enter any other alphabet."<<endl;
    cout<<"\n\t\t\tAre you sure you want to rent this car: ";
	cin>>confirm;
    if(confirm=="N"||confirm=="n") 
	{
    goto start0;
    system("CLS");
    }
    else if(confirm=="Y"||confirm=="y")
    {
    cout<<"\n\t\t\tPlease provide following information : "<<endl; //getting data from user related to rental service
	start1:
    cout<<"\n\t\t\tPlease select number of cars required : ";
    cin>>carnumber;
    if(carnumber<1 || carnumber>25)
    {
	cout<<"\n\t\t\tSorry!!! Our Company cannot provide "<<carnumber<<" cars.\n\t\t\tPlease enter a number between 1 to 25."<<endl;
    goto start1;
    }
    cout<<"\n\t\t\tNumber of days you wish to rent the car : ";
    cin>>days;
    start2:
    cout<<"\n\t\t\tDriver Rent : Rs.2000 per day\n\t\t\tDo you need driver (Y/N) : ";
    cin>>driver;
    if(driver=='Y'||driver=='y')
    drivernumber=carnumber;
    else if(driver=='N'||driver=='n')
    drivernumber=0;
    else
    {
    	cout<<"\n\t\t\tPlease give valid response...\n";
    	goto start2;
	}
	}
	else
	{
		system("CLS");
		exit(0);
	}
    }
	void calculate()
	{
		sleep(1);
		system ("CLS");
		cout<<"\n\t\t\tCalculating rent. Please wait......"<<endl;
		sleep(2);
		if(carmodel == "1")
        {
		rentalfee=days*carnumber*5000;
        carmodel_nm="Tesla Model S";
        }
        if(carmodel == "2")
        {
        rentalfee=days*carnumber*1000;
        carmodel_nm="Hyundai i10";
        }
        if(carmodel == "3")
        {
        rentalfee=days*carnumber*3000;
        carmodel_nm="Ford Mustang";
        }
        if(carmodel == "4")
        {
        rentalfee=days*carnumber*4000;
        carmodel_nm="Mercedes Benz E-Class";
        }
        if(carmodel == "5")
        {
        rentalfee=days*carnumber*2000;
        carmodel_nm="Toyota Fortuner";
        }
        driverfee=2000*days*drivernumber;
		totalfee=rentalfee+driverfee;
    }
    void showrent()
    {
    fstream Invoice;
    Invoice.open("Invoice.txt",ios::out);
    if(!Invoice)
    cout<<"File creation failed";
    else
    {
    for(int i=100000;i<999999;i++)
    invoice_no = (rand() % 100000) + 1;
    time_t now = time(0);
	char* dt = ctime(&now);
	Invoice << "\n\t\t                       Car Rental - Customer Invoice                  "<<endl;
    Invoice << "\t\t	////////////////////////////////////////////////////////////////\n"<<endl;
    Invoice << "\t\t	Date and Time of Invoice : "<<dt<<endl;
    Invoice << "\t\t	| Invoice Number :"<<"---------------|"<<setw(30)<<invoice_no<<" |"<<endl;
    Invoice << "\t\t	| Customer Name:"<<"-----------------|"<<setw(30)<<customername<<" |"<<endl;
    Invoice << "\t\t	| Customer Address:"<<"--------------|"<<setw(30)<<address<<" |"<<endl;
    Invoice << "\t\t	| Customer Contact Number:"<<"-------|"<<setw(30)<<contact<<" |"<<endl;
    Invoice << "\t\t	| Car Model Number:"<<"--------------|"<<setw(30)<<carmodel_nm<<" |"<<endl;
    Invoice << "\t\t	| Number of Cars :"<<"---------------|"<<setw(30)<<carnumber<<" |"<<endl;
    Invoice << "\t\t	| Number of Days :"<<"---------------|"<<setw(30)<<days<<" |"<<endl;
    Invoice << "\t\t	| Car Rental Amount is :"<<"---------|"<<setw(30)<<rentalfee<<" |"<<endl;
    Invoice << "\t\t	| Driver Rental Amount is :"<<"------|"<<setw(30)<<driverfee<<" |"<<endl;
    Invoice << "\t\t	 _____________________________________________________________\n"<<endl;
    Invoice << "\t\t	| Total Rental Amount is :"<<"-------|"<<setw(30)<<totalfee<<" |"<<endl;
    Invoice << "\t\t	 _____________________________________________________________\n"<<endl;
    Invoice << "\t\t	     This is a computer generated invoice and it does not"<<endl;
    Invoice << "\t\t	               require an authorised signture "<<endl;
    Invoice << "\n\t\t	////////////////////////////////////////////////////////////////\n"<<endl;
    Invoice << "\t\t	     You are advised to pay up the amount before due date."<<endl;
    Invoice << "\t\t	               Otherwise penelty fee will be applied.\n"<<endl;
    Invoice << "\t\t	///////////////////////////////////////////////////////////////\n"<<endl;
    Invoice.close();
    Invoice.open("Invoice.txt", ios::in);
    if(Invoice.is_open())
    {
    	string inv;
    	while(getline(Invoice,inv))
    		cout<<inv<<endl;
		Invoice.close();
	}
    }
	int f;
    system("PAUSE");    
    system ("CLS");    
    ifstream inf("Thanks.txt");
     char str[300];
     while(inf) 
     {
        inf.getline(str, 300);
        if(inf) cout << str << endl;
     }
     inf.close();
     }
};
class Welcome //Welcome class
{
	public:
	int welcome()
	{
    ifstream in("Welcome.txt"); //displaying Welcome ASCII image text on output screen
    if(!in) 
    cout << "Cannot open input file.\n";
    char str[1000];
    while(in)
	{
    in.getline(str, 1000);  // delim defaults to '\n' cp
    if(in) cout << str << endl;
    }
  in.close();
  sleep(1);
  cout<<"\nStarting the program please wait....."<<endl;
  sleep(1);
  cout<<"\nLoading up files and data....."<<endl;
  sleep(1); 
  cout<<"\nOpening Car Rental System....."<<endl;
  sleep(1); //function which waits for (n) seconds
  system ("CLS"); //cleares screen
}
};
int main()
{
Welcome obj1; //object created for Welcome class
obj1.welcome(); //welcome function is called
rent obj2; 
//object created for rent class and further member functions are called
obj2.data();
obj2.calculate();
obj2.showrent();
return 0; //end of the program
}
int login()
{
   string pass ="";
   char ch;
   cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t       CAR RENTAL SYSTEM \n\n";
   cout<<"\t\t\t\t\t------------------------------";
   cout<<"\n\t\t\t\t\t\t     LOGIN \n";	
   cout<<"\t\t\t\t\t------------------------------\n\n";	
   cout<<"\t\t\t\t\tEnter Password: ";
   ch = getch();
   while(ch != 13)
   {  //character 13 is enter
   pass.push_back(ch);
   cout << '*';
   ch = getch();
   }
   if(pass == "pass")
   {
      cout << "\n\n\n\t\t\t\t\t\tAccess Granted! \n";
      system("PAUSE");
      system ("CLS");
   }
   else
   {
      cout << "\n\n\t\t\t\t\t\t\tAccess Aborted...\n\t\t\t\t\t\t\tPlease Try Again\n\n";
      system("PAUSE");
      system("CLS");
      login();
   }
}
