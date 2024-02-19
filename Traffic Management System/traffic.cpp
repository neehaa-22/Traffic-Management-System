#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <time.h>
#include <iomanip>
#include <cstdlib>
#include <string.h>
#include <stdio.h>
int i, choice, dd=0, mm=0, yy=0, hr=0, mint=0, sound=0;
void gotoxy(int x, int y);
void date_time() 
{
	time_t t = time(NULL);
  	struct tm tm = *localtime(&t);
  	dd = tm.tm_mday; 
	mm = tm.tm_mon + 1;
	yy = tm.tm_year + 1900-2000;
  	hr = tm.tm_hour; 
	mint = tm.tm_min;
}
using namespace std;
class display
{
	public:
		void authentication();
		void menu();		
};
class features
{
	public:
		void record_veh();
		void booths();
		void helpline();
		void control();
};
class Dataveh
{
    private:
	   unsigned long long int owner_no;
		int seater, generation, RTO_no;
		char veh_type[10], owner_name[50], des_pat[10], address[100], issued_date[20], veh_no[15];
	public:
		Dataveh()
		{
		    strcpy(veh_no, "ABXXXXXXXX");
		}
		void read();
		int stores();
		void view();
		void show();
		void top();	
		void search(char *);
		void deletes(char *);
		void update(char *);
};
void Dataveh::top() 
{
	
	cout << endl;
	cout<<setw(13)<<"Vehicle No"<<setw(15)<<"Vehicle Type"<<setw(18)<<"Owner Name"<<setw(18)<<"Phone Number"<<setw(10)<<"Seater"<<setw(15)<<"Generation"<<setw(10)<<"Fuel"<<setw(10)<<"RTO No"<<setw(20)<<"Issued Date"<<setw(35)<<"Address\n";
	int i;
	for(i=0; i<=170; i++)
		cout << "_";
	    cout<< endl;
}
void Dataveh::show() 
{
	cout<<"\n\n"<<setw(13)<<veh_no<<setw(15)<<veh_type<<setw(18)<<owner_name<<setw(18)<<owner_no<<setw(10)<<seater<<setw(15)<<generation<<setw(10)<<des_pat<<setw(10)<<RTO_no<<setw(20)<<issued_date<<setw(35)<<address;
}
void features::record_veh() 
{
	display d1;
	Dataveh vh;
	char get[15];gotoxy(90,20);
	system("cls");gotoxy(90,21);
	cout << "\xB2\xB2\xB2\xB2  Choose Option  \xB2\xB2\xB2\xB2"<<endl;gotoxy(90,22); 
	cout << "\xB2  1. Add a Record      \xB2"<<endl;gotoxy(90,23);
	cout << "\xB2  2. Delete a Record   \xB2"<<endl;gotoxy(90,24);
	cout << "\xB2  3. Update a Record   \xB2"<<endl;gotoxy(90,25); 
	cout << "\xB2  4. Back to Main Menu \xB2"<<endl;gotoxy(90,26); 
	cout<< "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;gotoxy(90,27); 
	while(choice !=4)
	{
		cout << "Enter your choice : ";
		cin >> choice;
		switch(choice) 
		{
			case 1 :
				{
					vh.read();
					vh.stores();
					break;
				}
			case 2 :
			    {
			   	    system("cls"); 
				    cout << "\xB2\xB2 Delete Record \xB2\xB2\n\n";
				    cout << "Enter the Vehicle No to delete : ";
				    cin.ignore();
    			    cin.getline(get, 14);
				    vh.deletes(get);
				    break;
			    }	
			case 3 :
			    {
					system("cls"); 
				    cout << "\xB2\xB2 update Record \xB2\xB2\n\n";
				    cout << "Enter the Vehicle No to update : ";
				    cin.ignore();
    			    cin.getline(get, 14);
				    vh.update(get);
				    break;			
				}    
			case 4 :
				d1.menu();
		}
	}
}
int Dataveh::stores()
{
	features f1;
	if(veh_no == 0) 
	{
		cout<<"\nData Not intialized";
//		return 0;
	} 
	else 
	{
		ofstream store;
		store.open("dataf.dat", ios::app|ios::binary);
		store.write((char*)this, sizeof(*this));
		store.close();
		cout << "\n\tData stored Successfully";
//		return 1;
	}
	cout << "\n\tPress any key to continue...";
	getch();
	f1.record_veh();
}
void Dataveh::read() 
{
    system("cls");
	cout<< "\xB2\xB2 Please enter the details \xB2\xB2\n\n";
    int type;
	cout << "\n\tVehicle No : ";
    cin.ignore();
    cin.getline(veh_no, 14);
	cout << "\n\t1. Two Wheeler (eg. Bike)\t2. Three Wheeler (eg. Auto)\t3. Four Wheeler (eg. Car)\n\n\tVehicle Type : ";
	cin >> type;
	if(type==1) 
	    strcpy(veh_type, "2 Wheeler");
	else if (type==2) 
	    strcpy(veh_type, "3 Wheeler");
	else if(type==3) 
	    strcpy(veh_type, "4 Wheeler");
	else 
	    strcpy(veh_type, "None");
	
	cout << "\tOwner Name: ";
    cin.ignore();
    cin.getline(owner_name, 49);
    cout << "\tMobile No : ";
    cin >> owner_no;
    cout << "\tSeater : ";
    cin >> seater;
    cout << "\tGeneration : ";
    cin >> generation;
    cout << "\tDesiel / Petrol : ";
    cin.ignore();
    cin.getline(des_pat, 9);
    cout << "\tRTO No : ";
    cin >> RTO_no;
	cout << "\tAddress : ";
    cin.ignore();
    cin.getline(address, 99);
	//Date and Time
	date_time();
	sprintf(issued_date, "%d:%d %d/%d/%d", hr, mint, dd, mm, yy);	
}
void Dataveh::view() 
{
	system("cls");
	display d1;
	cout << "\xB2\xB2 Record of Challans Done \xB2\xB2\n\n";
	top();
	ifstream view;
	view.open("dataf.dat", ios::in|ios::binary);
	if(!view)
		cout << "\nFile Not Found !";
	else 
	{
		view.read((char*)this, sizeof(*this));
		while(!view.eof()) 
		{
			show();
			view.read((char*)this, sizeof(*this));	
		}
		view.close();
	}
	
	cout << "\n\n\n\nPress any key to continue...";
	getch();
	d1.menu();    
}
void Dataveh::deletes(char *t) 
{
	features f1;
	int counter=0;
	ifstream view;    //read
	ofstream store;   //write
	view.open("dataf.dat", ios::in|ios::binary);   //in-read mode
	if(!view)
		cout << "\nFile NOT Found";
	else 
	{
		store.open("tempFile.dat", ios::out|ios::binary);    //out-write mode
		view.read((char*)this, sizeof(*this));
		while(!view.eof()) 
		{
			if(strcmp(t, veh_no)) 
			{
				store.write((char*)this, sizeof(*this)); 
				counter++;   
			}
			view.read((char*)this, sizeof(*this));   
		}
		view.close();
		store.close();
		remove("dataf.dat");
		rename("tempFile.dat", "dataf.dat");
		if(counter==0)
		cout<<"Unable to Delete";
		else
		cout<<"\n\tDeleted Successfully";
	}
	cout<<"\n\tPress any key to continue...";
	getch();
	f1.record_veh();
}
void Dataveh::update(char *t)
{
	features f;
	int found=0;
	fstream file;
	file.open("dataf.dat", ios::in|ios::out|ios::ate|ios::binary);
	file.seekg(0);
	file.read((char*)this, sizeof(*this));
	while(!file.eof()) {
		if(!strcmp(t, veh_no)){
			read();
			int pos = (int)file.tellg()-sizeof(*this);
			file.seekg(pos, ios::beg);
			file.write((char*)this, sizeof(*this));
			found++;
		}
		file.read((char*)this, sizeof(*this));
	}
	file.close();
	if(found==0)
		cout << "\n\tUnable to Update";
	else
		cout << "\n\tUpdated Successfully";
	cout << "\n\tPress any key to continue...";
	getch();
	f.record_veh();
	
}
void Dataveh::search(char *t) 
{
	display d1;
	cout << "\xB2\xB2 Search Record \xB2\xB2\n\n";
	top();
	int counter=0;
	ifstream view;
	view.open("dataf.dat", ios::in|ios::binary);
	if(!view)
	cout << "\nFile NOT Found !";
	else 
	{
		view.read((char*)this, sizeof(*this));
		while(!view.eof()) 
		{
			if(!strcmp(t, veh_no)) 
			{
				show();
				counter++;
			}
			view.read((char*)this, sizeof(*this));
		}
		if(counter==0)
		cout << "\nRecord NOT Found";
		view.close();
	}
	cout << "\n\nPress any key to continue...";
    getch();
	d1.menu();
}
void features::booths()
{
	system("cls");system("color 6");
	display d;
	gotoxy(95, 3);
	cout << "\xB2\xB2\xB2\xB2  Traffic Control Booth  \xB2\xB2\xB2\xB2\n\n\n"; 
	char ch;
	ifstream fin;
	fin.open("control_booth.txt");
	while(!fin.eof()) {
		ch = fin.get();
		if(ch == '*') cout << "\xB2";
		else cout << ch;
	}
	fin.close();
	cout << "\n\n\n\t\tPress any key to continue...";
	getch();
	d.menu();
}
void features::helpline()
{
	system("cls");
	display d;
	gotoxy(95, 3);
	cout << "\xB2\xB2\xB2\xB2  Helpline and Hospital Services  \xB2\xB2\xB2\xB2\n\n\n"; 
	char ch;
	ifstream fin;
	fin.open("helpline.txt");
	while(!fin.eof()) {
		ch = fin.get();
		if(ch == '*') cout << "\xB2";
		else cout << ch;
	}
	fin.close();
	cout << "\n\n\n\t\tPress any key to continue...";
	getch();
	d.menu();
}
void features::control()
{
	system("cls");
    display d;
	gotoxy(60, 3);
	cout << "\xB2\xB2\xB2\xB2  Control of Traffic  \xB2\xB2\xB2\xB2\n\n\n"; 
	char ch;
	ifstream fin;
	fin.open("control.txt");gotoxy(50, 4);
	while(!fin.eof()) {
		ch = fin.get();
		if(ch == '*') cout << "\xB2";
		else cout << ch;
	}
	fin.close();
	cout << "\n\n\n\t\tPress any key to continue...";
	getch();
	d.menu();
	
}
void display::menu()
{
	features f1;
	Dataveh vh;
	char srch[15];
	system("cls");gotoxy(90,7);
	system("color 9");gotoxy(90,8);
	for(i=0; i<40; i++)gotoxy(90,9);
	cout << "\xB2"; gotoxy(90,10);
	cout << "Smart Traffic Management System";gotoxy(90,11);	
	for(i=0; i<40; i++)gotoxy(90,12);
	cout << "\xB2"; gotoxy(90,13);
	cout << endl;gotoxy(90,14);
	cout << "1. Keep the record of vehicles\n";	gotoxy(90,15);
	cout << "2. Record of vehicles\n";	gotoxy(90,16);
	cout << "3. Search the record of vehicles\n"; 	gotoxy(90,17);
	cout << "4. Display information of traffic control booths\n";gotoxy(90,18);
	cout << "5. Helpline information and nearby hospitals\n";gotoxy(90,19);	
	cout << "6. Control the traffic\n";	gotoxy(90,20);
	cout << "7. Exit"<<endl;	
	while(choice!=7) 
	{
		gotoxy(90,21);
		cout<<"Enter Your Choice : ";
		cin>>choice;
		switch(choice) 
		{
			case 1:	
			     gotoxy(90,10);
	            f1.record_veh();
				break;
			case 2:	
			     gotoxy(90,10);
			    vh.view(); 
			    break;
				
			case 3:	
			{
				system("cls");gotoxy(90,10);
				cout << "Enter the Vehicle No to search : ";gotoxy(90,11);
				cin.ignore();gotoxy(90,12);
    			cin.getline(srch, 14);gotoxy(90,13);
    			system("cls");gotoxy(90,13);
				vh.search(srch);
				break;
			}
			case 4:	
			{
				
			    f1.booths();gotoxy(40,5);
			    break;
			}
			case 5:	
		   {
			    
			    f1.helpline(); gotoxy(40,5);
			    break;
		   }
			case 6:
			{
					
			    f1.control();gotoxy(40,5); 
			    break;
			}
			case 7: 
			{
                system("cls");gotoxy(40,10);
				cout << "Thanks for using our Service";gotoxy(40,11);
				getch();gotoxy(40,12);
				exit(0);
				break;
			}
		} 
	}
}
void display::authentication()
{
	int pass = 123456;
    int input ;
    char a;
	for(i=3;i>0;i--)
	{
		gotoxy(90, 55);
		cout<<"Enter the Pin :";
	    cin>>input;gotoxy(90, 40);
		if(input==pass)
		{
			
			system("color 0A");
			break;
		}
		else 
		{
			
			system("color 4");gotoxy(50,41);
			cout << "wrong password"<<endl;gotoxy(50,42);
		    cout << "Attempts left "<<i<<endl;gotoxy(50,43);
		}
	}
	if (i==0)
	{
		system("color 4");gotoxy(50,44);
		cout<<endl<<"Sorry, you are not authorised...";gotoxy(50,45);

	}
	else 
	{
		system("cls");
        int r,q;gotoxy(100,20);
        cout << "Loading..."<<endl;gotoxy(90,21);
        for(r=1; r<=30; r++) 
	    {
			
            for(q=0; q<=90000000; q++); //to display the character slowly
            printf("%c", 177);	
        }
        system("cls");
	    menu();			
	}
}
int main() 
{
	cout<<endl;
	cout<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t@ @ @ @ @"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t    @      @ @ @ @       @        @ @ @ @ @  @ @ @ @ @  @ @ @ @ @   @ @ @ @"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t    @     @       @     @ @       @       @  @       @      @      @       "<<endl;	
    cout<<"\t\t\t\t\t\t\t\t\t    @     @       @    @   @      @          @              @      @       "<<endl;	
    cout<<"\t\t\t\t\t\t\t\t\t    @     @  @ @ @    @ @ @ @     @ @ @      @ @ @          @      @       "<<endl;	
    cout<<"\t\t\t\t\t\t\t\t\t    @     @ @        @       @    @          @              @      @       "<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t    @     @  @      @         @   @          @              @      @       "<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t    @     @    @   @           @  @          @          @ @ @ @ @   @ @ @ @";
	cout<<endl;
	cout<<"\t\t\t\t\t\t@         @"<<endl;	
	cout<<"\t\t\t\t\t\t@ @     @ @       @       @ @       @         @        @ @ @ @ @ @  @ @ @ @ @ @  @         @  @ @ @ @ @ @  @ @       @  @ @ @ @ @ @"<<endl;	
	cout<<"\t\t\t\t\t\t@  @   @  @      @ @      @  @      @        @ @       @            @            @ @     @ @  @            @  @      @       @     "<<endl;
    cout<<"\t\t\t\t\t\t@   @ @   @     @   @     @   @     @       @   @      @            @            @  @   @  @  @            @   @     @       @     "<<endl;	
	cout<<"\t\t\t\t\t\t@    @    @    @ @ @ @    @    @    @      @ @ @ @     @   @ @ @ @  @ @ @ @ @    @    @    @  @ @ @ @ @    @    @    @       @     "<<endl;	
	cout<<"\t\t\t\t\t\t@         @   @       @   @     @   @     @       @    @         @  @            @         @  @            @     @   @       @     "<<endl;	
	cout<<"\t\t\t\t\t\t@         @  @         @  @      @  @    @         @   @         @  @            @         @  @            @      @  @       @     "<<endl;
	cout<<"\t\t\t\t\t\t@         @ @           @ @       @ @   @           @  @ @ @ @ @ @  @ @ @ @ @ @  @         @  @ @ @ @ @ @  @       @ @       @     "<<endl;
	cout<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t  @ @ @ @    "<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t@           @       @    @ @ @ @ @   @ @ @ @ @ @  @ @ @ @ @ @  @          @"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t@            @     @   @                  @       @            @ @      @ @"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t@             @   @    @                  @       @            @   @  @   @"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t @ @ @ @       @ @      @ @ @ @ @         @       @ @ @ @ @    @     @    @"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t         @      @                @        @       @            @          @"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t         @      @                @        @       @            @          @"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t         @      @                @        @       @            @          @"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t @ @ @ @        @       @ @ @ @ @         @       @ @ @ @ @ @  @          @"<<endl;
	display d1;
	d1.authentication();
	return 0;
}
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
