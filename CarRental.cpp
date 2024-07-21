#include<iostream>
#include<fstream>
#include<unistd.h>
#include<iomanip>
#include<ctime>

using namespace std;

class Customer{
	protected:
		string customer_Name;
		int car_model;
		string car_Number;
};

class Rent: public Customer{
	private:
		int NumberOfDays;
		int Rent_Fee;
		char str[200];
		
	public:
		
		Rent();
		void welcome();
		void fileReader(char carFile[20]);
		void data();
		void invoiceAmount();
		void invoiceRecord();
};

Rent::Rent(){
	
	NumberOfDays=0;
	Rent_Fee=0;
}

void Rent::welcome(){
	
	ifstream inputFile("welcome.txt");
	if(!inputFile){
		cout<<"Cannot open input file.\n";
	}
	char str[1000];
	while(inputFile){
		inputFile.getline(str, 1000);
		if(inputFile)
		    cout<<str<<endl;
	}
	inputFile.close();
	sleep(1);
	cout<<"\nStarting the program please wait....."<<endl;
	sleep(1);
	cout<<"\nLoading up files......."<<endl;
	sleep(1);
	system("CLS");
}
void Rent::fileReader(char carFile[20]){
	ifstream inputFile;
	inputFile.open(carFile);
	if(!inputFile){
		cout<<"Error.. File not found!!"<<endl;
	}
	while(inputFile){
		inputFile.getline(str, 200);
		if(inputFile)
		    cout<<str<<endl;
	}
}

void Rent::data(){
	cout<<"\n\n\t\t\tPlease Enter your Name: ";
	cin>>customer_Name;
	cout<<endl;
	do{
		cout << "\t\t\t\t__________________________________________________________________"<<endl;
	    cout << "\t\t\t\tChoose a Car from the options below. \n ";
	    cout <<	"\t\t\t\tChoose a number corresponding to the car you want to Select." << endl; 
	    cout << "\t\t\t\t__________________________________________________________________"<<endl;
		cout << "\t\t\t\t1. Toyota 2021."<<endl;
	    cout << "\t\t\t\t2. Hyundai 2019."<<endl;
	    cout << "\t\t\t\t3. Ford 2020."<<endl;
	    cout << endl;
	    cout << "\t\t\t\t__________________________________________________________________"<<endl;
	    cout << "\n\t\t\t\tChoose: ";
	    cin >> car_model;
	    cout << endl;
	    
		switch(car_model){
		
		    case 1:
		        system("CLS");
		        cout<<"You have choosen Toyota model 2021"<<endl;
		        fileReader("Toyota.txt");
		        sleep(2);
		        break;
		        
		    case 2:
			    system("CLS");
				cout<<"You have choosen Hyundai model 2019"<<endl;
				fileReader("Hyundai.txt");
				sleep(2);
				break;
				
			case 3:
			    system("CLS");
				cout<<"You have choosen Ford model 2020"<<endl;
				fileReader("Ford.txt");
				sleep(2);
				break;
				
			default:
			    cout<<"Invalid carModel. Please try again!"<<endl; 
		}
	}
	while(car_model<1 && car_model>3);
	cout<<"________________________________________________________________________________________________"<<endl;
  	cout << "Please provide following information:"<<endl; 
  	
  	cout<<"Please select car number: ";
  	cin>>car_Number;
  	cout<<"Number of days of rent: ";
  	cin>>NumberOfDays;
  	cout<<endl;
}

void Rent::invoiceAmount(){
	sleep(1);
	system("CLS");
	cout<<"Calculating rent. Please wait....."<<endl;
	sleep(2);
	if(car_model==1)
	    Rent_Fee=NumberOfDays*150;
	if(car_model==2)
	    Rent_Fee=NumberOfDays*160;
	if(car_model==3)
	    Rent_Fee=NumberOfDays*175;
}

void Rent::invoiceRecord(){
	time_t now=time(0);
	char *date= ctime(&now);
	cout<<setw(80)<<date<<endl;
	cout << "\n\t\t                       CAR RENTAL - CUSTOMER INVOICE                  "<<endl;
	cout << "\t\t	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t	| Invoice No.  "<<"					|"<< setw(10) <<"#1001"<<" |"<<endl;  
	cout << "\t\t	| Customer Name "<<"				|"<< setw(10) <<customer_Name<<" |"<<endl;
	cout << "\t\t	| Car Model  "<<"					|"<< setw(10) <<car_model<<" |"<<endl;     
	cout << "\t\t	| Car No.  "<<"					|"<< setw(10) <<car_Number<<" |"<<endl;
	cout << "\t\t	| Number of days  "<<"				|"<< setw(10) <<NumberOfDays<<" |"<<endl;
	cout << "\t\t	| Rental Amount  "<<"				|"<< setw(10) <<Rent_Fee<<" |"<<endl;
	cout << "\t\t	| Caution Money  "<<"				|"<< setw(10) <<"0"<<" |"<<endl;       
	cout << "\t\t	| Advanced  "<<"					|"<< setw(10) <<"0"<<" |"<<endl;		 
	cout << "\t\t	|___________________________________________________________|"<<endl;
	cout << "\t\t	| Total Rental Amount    "<<"			|"<<setw(6)<<"R " << Rent_Fee<<" |"<<endl;
	cout << "\t\t	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t	 NOTE: This is a computer generated invoce. "<<endl;
	cout << "\t\t	       It does not require an authorised signture."<<endl;
	cout << "\t\t	***********************************************************" << endl;
	cout << "\t\t	You are advised to pay up the amount before due date."<<endl;
	cout << "\t\t	Otherwise penalty fee will be applied"<<endl;
	cout << "\t\t	***********************************************************" << endl;
	
	system("PAUSE");
	system("CLS");
	fileReader("thanks.txt");
}

int main(){
	
	Rent rent;
	rent.welcome();
	rent.data();
	rent.invoiceAmount();
	rent.invoiceRecord();
	
	return 0;
}
