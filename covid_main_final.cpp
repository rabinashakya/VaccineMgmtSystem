//COVID-19 Vaccination management system
//ALL FILE MERGED

#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<iomanip>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<sstream>
using namespace std;
int n=3;

void front()
{
	cout<<"\t\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\t                             **    COVID-19 VACCINE MANAGEMENT SYSTEM   **";
	cout<<"\t\n------------------------------------------------------------------------------------------------------------------------\n";

	cout<<"\t\t\t\n        				* * * * * * * * * * * * * * * *";         
	cout<<"\t\t\t\n        				*         CREATED BY:         *";
	cout<<"\t\t\t\n        				*                             *";
	cout<<"\t\t\t\n        				*        Rabina Shakya        *";
	cout<<"\t\t\t\n        				* * * * * * * * * * * * * * * * \n\n";

	cout<<"\t\n\n Press any key to continue.............  "<<endl;
	getch();
}

class covid_vaccine
{
	int age;
	char gender;
	string name;
	string address;
	string mobile_number;
	int admin_code;
	
	public:
		void menu();
		void admin();
		int code;
		string data;
		int gaps;
		string quantity;
		ofstream file;
   
		void user_login();
		void ulogin();
		void uregistration();
		void forgot();
		void alogin();
		void aregistration();
		void show1();
		
		//FOR ADMIN
		void show();
		void add_new_vaccine();
		void update_vaccine_quantity();
		void admin_login();
		void admin_details();
		
		void search_vaccine();
		void show_vaccine_list();
		void check_vaccine_status();
		void delete_vaccine();
		
		string ruserId;
	    string rpassword;
		
		//FOR USER
		void user_option();
		void add_new_record();
		void vaccine_registration();
		void pick_vaccine();
		void view_your_details();
		void date1();
		void date2();
		
};

//-------------------------------FIRST PAGE---------------------------------
void covid_vaccine::menu()
{
	int choice;
	//MAIN MENU
	cout<<"\t\n        * * * * * * * * * * * * * * * *";         
	cout<<"\t\n        *          MAIN MENU          *";
	cout<<"\t\n        * * * * * * * * * * * * * * * * \n\n";
	cout<<endl;
	cout << "\t|   1. ADMIN     |" << endl;
	cout << "\t|   2. USER      |" << endl;
	cout << "\t|   3. EXIT      |" << endl;	
	cout << "\n\t Please Enter Your Choice: ";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			admin();
			break;
		case 2:
			user_login();
			break;
		case 3:
			system("cls");
	        cout << "\n\n\t\t\t COVID-19 VACCINE MANAGEMENT SYSTEM";
	        Sleep(10);
		default:
			cout << "\n\n\t\t\t Invalid Choice... Please Try Again....";
	        cout << "\n\n Press Any Key To Continue: ";
	        getch();
	        menu();		
	}
}

//--------------------------ADMIN MAIN LOGIN------------------------------------
void covid_vaccine::admin_login()
{
	int choice;
	cout<<"\t\n        * * * * * * * * * * * * * * * *";         
	cout<<"\t\n        *          ADMIN PAGE         *";
	cout<<"\t\n        * * * * * * * * * * * * * * * * \n\n";
	cout<<endl;
	cout << "\t|   1. LOGIN          |" << endl;
	cout << "\t|   2. REGISTRATION   |" << endl;
	cout << "\n\t Enter Your Choice: ";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			alogin();
			break;
		case 2:
			aregistration();
			break;
		default:
			cout << "Invalid Choice.";
			getch();
			admin_login();
    }
}

//-----------------------------------ADMIN ONLY-----------------------------------
void covid_vaccine::admin()
{
	
	cout << "CODE : ";
string pass ="";
   	char ch;
   	ch = _getch();
   	while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   	}
	if(pass=="5678")
	{
		cout<<endl<<"-----------------------------------------------------------------------------"<<endl;
		admin_login();
	}
	
	else
	{
		cout << "**************** Incorrect code ****************" << endl;
		menu();
	}
}

//------------------------------------ADMIN LOGIN-----------------------------------------
void covid_vaccine::alogin()
{
	int count=0, s=0;
	char userId[20], password[20];
	string id, pass;

	char p;
	system("cls");
	cout<<endl;
	cout<<"\t\n        * * * * * * * * * * * * * * * *";         
	cout<<"\t\n        *          ADMIN LOGIN         *";
	cout<<"\t\n        * * * * * * * * * * * * * * * * \n\n";
	cout<<endl;
	cout << "\t Please enter username and password. " << endl;
	cout << "\t USERNAME: ";
	cin >> userId;
	
	cout << "\t PASSWORD: ";
	while (p != 13)
    {
      p = _getch();
      if (p != 13)
      {
        putch('*');
        password[s] = p;
        s++;
      }
    }
    password[s] = '\0';
	ifstream input("D:\\CSIT\\3rd Sem\\C++project\\covid-19\\admin_login.txt");
	
	while(input>>id>>pass)
	{
		char id1[id.length()+1];
	    char pass1[pass.length()+1];
		strcpy(id1,id.c_str());
		strcpy(pass1,pass.c_str());

    if(strcmp(id1,userId)==0 && strcmp(pass1,password)==0)
		{
			count = 1;
			system("cls");
		}
	}
	input.close();
	
	if(count==1)
	{
		cout << "UserId: " << userId << "\nYour Login is Successful \nThanks for logging in! \nPress any key.";
		getch();
		admin_details();
	}
	else
	{
		cout << "\nLOGIN ERROR !! \nPlease check your username and password \n";
		getch();
		alogin();
	}
}

//-----------------------------ADMIN REGISTRATION-----------------------------------
void covid_vaccine::aregistration()
{
	string ruserId, rpassword, rid, rpass;
	system("cls");
	cout<<"\t\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\t                             **    COVID-19 VACCINE MANAGEMENT SYSTEM   **";
	cout<<"\t\n------------------------------------------------------------------------------------------------------------------------\n";
	cout<<endl;
	cout<<"\t\n        * * * * * * * * * * * * * * * *";         
	cout<<"\t\n        *      ADMIN REGISTRATION     *";
	cout<<"\t\n        * * * * * * * * * * * * * * * * \n\n";
	cout<<endl;
	cout << "\t Enter username: ";
	cin >> ruserId;
	cout << "\t Enter password: ";
	cin >> rpassword;
	
	ofstream f1("D:\\CSIT\\3rd Sem\\C++project\\covid-19\\admin_login.txt", ios::app);
	f1 << ruserId << ' ' << rpassword << endl;
	system("cls");
	cout << "\n\t Registration is Successful.\n\t Please login!!!\n";
	admin_login();
}

//-----------------------------ADMIN MENU OPTION-----------------------------
void covid_vaccine::admin_details()
{
A:	
	system("cls");
	int admin_choice;
	cout<<endl;
	cout<<"\t\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\t                             **    COVID-19 VACCINE MANAGEMENT SYSTEM   **";
	cout<<"\t\n------------------------------------------------------------------------------------------------------------------------\n";
	cout<<endl;
	cout<<"\t\n       * * * * * * * * * * * * * * * * * * * *";         
	cout<<"\t\n       *            ADMIN MAIN MENU          *";
	cout<<"\t\n       * * * * * * * * * * * * * * * * * * * *\n\n";
	cout<<endl;
    cout << "\t|   1. Add New Vaccine          |" << endl;
	cout << "\t|   2. Search Vaccine           |" << endl;	
	cout << "\t|   3. Show Vaccine List        |" << endl;
	cout << "\t|   4. Delete Vaccine           |" << endl;
	cout << "\t|   5. Update Vaccine Quantity  |" << endl;
	cout << "\t|   6. Exit                     |" << endl;
	cout << "\n\t Please Enter Your Choice: ";
	cin>>admin_choice;
	cout<<"\n-------------------------------------------------------------\n";
	switch(admin_choice)
	{
		case 1:
			add_new_vaccine();
			goto A;
			break;
		case 2:
			search_vaccine();
			goto A;
			break;	
		case 3:
			show_vaccine_list();
			goto A;
			break;	
		case 4:
			delete_vaccine();
			goto A;
			break;	
		case 5:
			update_vaccine_quantity();
			goto A;
			break;
		case 6:
			cout << "Thank you." << endl;
			getch();
	//		admin_login();
			break;
		default:
			cout << "Invalid Choice.";
			getch();
			admin_details();
			break;
	}
}

//-----------------------------ADD NEW VACCINE--------------------------------
void covid_vaccine::add_new_vaccine()
{
	int gaps;
		ofstream file;
		file.open("D:\\CSIT\\3rd Sem\\C++project\\covid-19\\data.txt",ios::app);
		cout<<endl<<"Enter vaccine code: ";
		cin>>code;
		cout<<endl<<"Enter the name of vaccine: ";
		cin>>name;
		cout<<endl<<"Enter initial quantity: ";
		cin>>quantity;
		cout<<endl<<"Enter the gaps between two doses: ";
		cin>>gaps;
		file<<code<<setw(15)<<name<<setw(15)<<quantity<<setw(15)<<gaps<<endl;
		n =n+1;
		file.close();
		cout<<endl<<" New Vaccine record added successfully.";
		cout << "\n\n\nPress Any Key To Continue..";
        getch();        	
}

//-----------------------------UPDATE VACCINE------------------------------------------
void covid_vaccine::update_vaccine_quantity()
{
	ifstream fin;
    ofstream fout;
    int search;
    int count = 0;
    int newq;
    fin.open("data.txt");
    cout<<"Enter code of a vaccine to be updated: ";
    cin>>search;
    fout.open("data1.txt", ios::app | ios::out);
    for(int i=0;i<n;i++)
    {
        fin>>code>>name>>quantity>>gaps;
        if(search == code)
        {
            count++;
            cout<<"New Quantity : ";
            cin>>newq;
            fout<<code<<setw(15)<<name<<setw(15)<<newq<<setw(15)<<gaps<<endl;
        }
        else
        {
            fout<<code<<setw(15)<<name<<setw(15)<<quantity<<setw(15)<<gaps<<endl;
        }

    }
    
    fout.close();
    fin.close();
    remove("data.txt");
    rename("data1.txt","data.txt");
    getch();
    cout<<endl<<"Quantity updated. Please check the vaccine list.";
    
    if(count == 0)
    {
   		getch();
    	cout<<"\n\nRecord not found.";
    }
}

//---------------------------------SEARCH VACCINE---------------------------------------
void covid_vaccine::search_vaccine()
{
	ifstream file;
	int search;
	int count = 0;
	cout<<"Enter code of a vaccine to be searched: ";
	cin>>search;
	file.open("data.txt",ios::in);
	show();
	while(!file.eof())
	{
		if(search == code)
		{
			cout<<"\n";
			cout<<code<<setw(15)<<name<<setw(15)<<quantity<<setw(15)<<gaps<<setw(15);	
			count++;
		}
		file>>code>>name>>quantity>>gaps;
	}
	file.close();
	if(count == 0)
		cout<<"\n\nRecord not found.";
	getch();
}

//-----------------------------------VACCINE LIST----------------------------------
void covid_vaccine::show_vaccine_list()
{
	fstream file;
	file.open("data.txt",ios::in);
	cout<<"\n\t\tList of all vaccine"<<endl;
	cout<<"\n";
	cout<<"Code"<<setw(15)<<"Name"<<setw(15)<<"Quantity"<<setw(15)<<"Gaps\n"<<setw(15);
	if(file.is_open())
	{
		while(getline(file,name))
		{
			cout<<name<<"\n";
		}
		file.close();
		getch();
	}
}

//------------------------------------DELETE VACCINE-------------------------------------
void covid_vaccine::delete_vaccine()
{
	fstream file;
	file.open("data.txt");
	while(!file.eof())
	{
		getline(file,data);
		cout<<data<<endl;
	}

	file.close();
	int num;
	file.open("data.txt");
	file.clear();
	fstream f1;
	int codetodelete;
	f1.open("new.txt",ios::out|ios::trunc);
	cout<< "Enter the code of a vaccine to be deleted: ";
	cin>>codetodelete;
	while(file.good())
	{
		getline(file,data);
		if(file)
		{
			int n = 0;
			istringstream(data)>>num;
			if(num != codetodelete)
			{
				f1<<data<<endl;	
			} 
		}
	}
	n=n-1;
	file.close();
	f1.close();
	remove("data.txt");
	rename("new.txt","data.txt");
	cout<<"Record deleted successfully.";
	getch();
	
}
//------------------------------USER MAIN LOGIN---------------------------------------
void covid_vaccine::user_login()
{
	int choice;
	cout<<endl;

	cout<<"\t\n        * * * * * * * * * * * * * * * *";         
	cout<<"\t\n        *          USER PAGE          *";
	cout<<"\t\n        * * * * * * * * * * * * * * * * \n\n";
	cout<<endl;
	cout << "\t|   1. LOGIN           |" << endl;
	cout << "\t|   2. REGISTRATION    |" << endl;
	cout << "\t|   3. FORGOT          |" << endl;	
	cout << "\t|   4. EXIT            |" << endl;
	cout << "\n\n\t Please Enter Your Choice: ";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			ulogin();
			break;
		case 2:
			uregistration();
			break;
		case 3:
			forgot();
			break;
		case 4:
			cout << "\t\t\t Thank You!! " << endl;
			break;
		default:
			system("cls");
			cout << "Please enter a valid number." << endl;
			user_login();
	}
	menu();
}

//---------------------------------USER LOGIN-----------------------------------
void covid_vaccine::ulogin()
{
    int count=0, s=0;
	char userId[20], password[20];
	string id, pass;

	char p;
	system("cls");
	cout<<endl;
	cout<<"\t\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\t                             **    COVID-19 VACCINE MANAGEMENT SYSTEM   **";
	cout<<"\t\n------------------------------------------------------------------------------------------------------------------------\n";
	cout<<endl;
	cout<<endl;
	cout<<"\t\n        * * * * * * * * * * * * * * * *";         
	cout<<"\t\n        *          USER LOGIN         *";
	cout<<"\t\n        * * * * * * * * * * * * * * * * \n\n";
	cout<<endl;
	cout << "\t Please enter username and password: " << endl;
	cout << "\t USERNAME: ";
	cin >> userId;
	
	cout << "\t PASSWORD: ";
	while (p != 13)
    {
      p = _getch();
      if (p != 13)
      {
        putch('*');
        password[s] = p;
        s++;
      }
    }
    password[s] = '\0';
	ifstream input("user_records.txt");
	
	while(input>>id>>pass)
	{
		char id1[id.length()+1];
	    char pass1[pass.length()+1];
		strcpy(id1,id.c_str());
		strcpy(pass1,pass.c_str());

    	if(strcmp(id1,userId)==0 && strcmp(pass1,password)==0)
			{
				count = 1;
				system("cls");
			}
	}
	input.close();
	
	if(count==1)
	{
		cout << "UserId: " << userId << "\nYour Login is Successful \nThanks for logging in! \n";
		getch();
		user_option();
	}
	else
	{
		cout << "\nLOGIN ERROR !! \nPlease check your username and password \n";
		getch();
		ulogin();
	}
}

//-------------------------USER REGISTRATION-----------------------------------------
void covid_vaccine::uregistration()
{
	string ruserId, rpassword, rid, rpass;
	system("cls");
		cout<<"\t\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\t                             **    COVID-19 VACCINE MANAGEMENT SYSTEM   **";
	cout<<"\t\n------------------------------------------------------------------------------------------------------------------------\n";
	cout<<endl;
	cout<<"\t\n        * * * * * * * * * * * * * * * *";         
	cout<<"\t\n        *       USER REGISTRATION     *";
	cout<<"\t\n        * * * * * * * * * * * * * * * * \n\n";
	cout<<endl;
	cout << "\t Enter username: ";
	cin >> ruserId;
	cout << "\t Enter password: ";
	cin >> rpassword;
	
	ofstream f1("user_records.txt", ios::app);
	f1 << ruserId << ' ' << rpassword << endl;
	system("cls");
	cout << "\n\t Registration is Successful. \n";
	user_login();
}

//---------------------------------USER FORGOT PASSWORD-----------------------------
void covid_vaccine::forgot()
{
	int option;
	system("cls");
	cout << "\t\t Forgot Password? \n\n";
	cout << "\t|   1. SEARCH ID BY USERNAME     |" << endl;
	cout << "\t|   2. GO BACK TO MAIN PAGE      |" << endl;
	cout << "\n\t Please Enter Your Choice: ";
	cin >> option;
	
	switch(option)
	{
		case 1:
			{
				int count = 0;
				string suserId, sId, spass;
				cout << "\n\tEnter the username which you remember: ";
				cin >> suserId;
				
				ifstream f2("user_records.txt");
				while(f2>>sId>>spass)
				{
					if(sId==suserId)
					{
						count = 1;
					}
				}
				f2.close();
				
				if(count==1)
				{
					cout << "\n\n Your account is found! \n";
					cout << "\n\n Enter Password: " << spass;
					add_new_record();
				}
				else
				{
					cout << "\n\t Sorry, your account was not found! \n";
					user_login();
				}
				break;
			}
			
			case 2:
				{
					user_login();
				}
				default:
					cout << "\t Wrong Choice! Please try again" << endl;
					forgot();
	}
}

//------------------------------------------SHOW PART--------------------------------------------
void covid_vaccine::show()
{
	cout<<"\n";
	cout<<"Code"<<setw(15)<<"Name"<<setw(15)<<"Quantity\n"<<setw(15);
}


//-----------------------------------------1ST DOSE DATE----------------------------------------
void covid_vaccine::date1()
{
	time_t currenttime = time(0);
	tm*ltm = localtime(&currenttime);
	
	int year = 1900 + ltm -> tm_year;
	int month = 1 + ltm -> tm_mon;
	int month1 = 1 + ltm -> tm_mon;
	int day = ltm -> tm_mday;
	int day1 = ltm -> tm_mday + 02;
	cout<<endl;
	cout<<"\t\n------------------------------------------------------------------------------------------------------------------------";
	cout<<endl;
	cout << "\n\t Date for Vaccine: " << month1 << "/" << day1 << "/" << year << endl;
}

//----------------------------------2nd dose date-------------------------------------
void covid_vaccine::date2()
{
	time_t t = time(NULL);
	tm* tPtr = localtime(&t);
	int cur_day = (tPtr->tm_mday);
	int cur_month = (tPtr->tm_mon)+1;
	int cur_year = (tPtr->tm_year)+1900;
	int month,day,year;
	cout<<endl;
	cout<<"\t\n------------------------------------------------------------------------------------------------------------------------";
	cout<<endl;
	cout<<"\n\t Enter the date of your 1st dose(YYYY MM DD) = ";
	cin>>year>>month>>day;
	cout<<endl;
	int year1=year;
	int month1=month;
	int day1=day;
	cout<<"\t Entered Date = "<<year<<"/"<<month<<"/"<<day<<endl;
	if((day1+15)>30){
		month1++;
		day1=(day1+15)-30;
		if(month1>12){
			year1++;
			month1=month1-12;
		}
	}
	else
	{
		day1+=15;
	}
	cout<<endl;
	cout<<"\t 2nd dose Vaccine Date: "<<year1<<"/"<<month1<<"/"<<day1<<endl;
}



//----------------------------------USER MAIN MENU---------------------------------
void covid_vaccine::user_option()
{
//	user_login();
	system("cls");
	int user_choice;

	cout<<"\t\n      * * * * * * * * * * * * * * * * * * * *";         
	cout<<"\t\n      *            USER MAIN MENU           *";
	cout<<"\t\n      * * * * * * * * * * * * * * * * * * * *\n";
	
	cout << "\t|   1. Add New Record         |" << endl;
	cout << "\t|   2. Vaccine Registration   |" << endl;
	cout << "\t|   3. View Your Details      |" << endl;
	cout << "\t|   4. Exit                   |" << endl;
	cout << "\n\t Please Enter Your Choice: ";
	cin>>user_choice;
	
	switch(user_choice)
	{
		case 1:
			add_new_record();
			break;
		case 2:
		    vaccine_registration();
			break;
		case 3:
			view_your_details();
			break;	
		case 4:
			user_login();
			break;	
		default:
			cout << "Please Enter a valid number." << endl;
			user_option();
	}
}

//------------------------DETAILS OF USER------------------------------
void covid_vaccine::add_new_record()
{
	string f, l, ag, a, g, cn;
	system("cls");
	
	ofstream myfile("users_data.txt", ios::app);
    
    cout<<"\t\n                                * * * * * * * * * * * * * * * * * ";         
	cout<<"\t\n                                *          ADD NEW RECORD       *";
	cout<<"\t\n                                * * * * * * * * * * * * * * * * *\n";
	cout << endl;

    cout << "First Name: ";
	cin >> f;
	
	cout << "\nLast Name: ";
	cin >> l;
	
	cout << "\nAddress: ";
	cin >> a;
	
	cout << "\nAge: ";
	cin >> ag;
	
	cout << "\nGender: ";
	cin >> g;
	
	cout << "\nPlease enter a profile id number (maximum 5 digit).";
	cout << "\nProfile Id Number: ";
	cin >> cn;
	
	myfile << f << setw(15) << l << setw(15) << a << setw(15) << ag << setw(15) << g << setw(15) << cn << setw(15) << endl;
	myfile.close();
	
	cout << "\nDetails has been successfully registered!!" << endl;
	getch();
	user_option();
}

//-------------------------VACCINE REGISTRATION----------------------------------
void covid_vaccine::vaccine_registration()
{
	int x;
	cout<<endl;
	cout<<"\t\n------------------------------------------------------------------------------------------------------------------------";
	cout<<endl;
    cout<<"\t\n      * * * * * * * * * * * * * * * * * * * * * * * *";         
	cout<<"\t\n      *             VACCINE  REGISTRATION           *";
	cout<<"\t\n      * * * * * * * * * * * * * * * * * * * * * * * * \n";
	cout << endl;
	cout << "\t|  Press 1 for Vaccine Type   |" << endl;	
	cout << "\t|  Press 2 to Exit            |" << endl;
	cout << "\n\t Please Enter Your Choice: ";
	cin >> x;
	cout << endl;
	
	switch(x)
	{
		case 1:
			pick_vaccine();
			break;
		case 2:
			cout << "\t\t\t Thank You!! " << endl;
			break;
		default:
			system("cls");
			cout << "Please enter a valid number." << endl;
		    vaccine_registration();
	}
	getch();
	user_option();
}

//-----------------------------------PICK VACCINE---------------------------------
void covid_vaccine::pick_vaccine()
{
	int pv;
	cout<<endl;
	cout<<"\t\n------------------------------------------------------------------------------------------------------------------------";
	cout<<endl;
	cout<<"\t\n        * * * * * * * * * * * * * * * *";         
	cout<<"\t\n        *         PICK VACCINE        *";
	cout<<"\t\n        * * * * * * * * * * * * * * * * \n\n";
	cout<<endl;

	cout << "\t|  1. CoronaVac       |" << endl;
	cout << "\t|  2. Verocell        |" << endl;
	cout << "\t|  3. CovidShield     |" << endl;	
	cout << "\t|  4. Covaxin         |" << endl;
	cout << "\n\t Please Enter Your Choice: ";
	cin >> pv;
	cout << endl;
	cout<<"\t\n------------------------------------------------------------------------------------------------------------------------";
	int vn;
	cout<<"\t\n        * * * * * * * * * * * * * * * *";         
	cout<<"\t\n        *    WHICH DOSE 1st OR 2nd?   *";
	cout<<"\t\n        * * * * * * * * * * * * * * * * \n\n";
	cout<<endl;
	cout << "\t|  1. 1st Dose        |" << endl;
	cout << "\t|  2. 2nd Dose        |" << endl;
	cout << "\n\t Please Enter Your Choice: ";
	cin >> vn;
	cout << endl;
	
	ofstream myfile1("user_vaccine1.txt", ios::app);

	if(pv==1)
	{
		if(vn==1)
		{
			cout << "\t You have successfully registered your 1st dose vaccine for CoronaVac.";
			myfile1 << pv << setw(15) << vn << setw(15) << endl;
	        myfile1.close();
	        date1();
		}
		else
		{
	        cout << "\t You have successfully registered your 2nd dose vaccine for CoronaVac.";
	        myfile1 << pv << setw(15) << vn << setw(15) << endl;
	        myfile1.close();
			date2();
		}
	}
	
	else if(pv==2)
	{
		if(vn==1)
		{
			cout << "\t You have successfully registered your 1st dose vaccine for Verocell.";
			myfile1 << pv << setw(15) << vn << setw(15) << endl;
	        myfile1.close();
	        date1();
		}
		else
		{
			cout << "\t You have successfully registered your 2nd dose vaccine for Verocell.";
			myfile1 << pv << setw(15) << vn << setw(15) << endl;
	        myfile1.close();
			date2();
		}
	}
	
	else if(pv==3)
	{
		if(vn==1)
		{
			cout << "\t You have successfully registered your 1st dose vaccine for CovidShield.";
			myfile1 << pv << setw(15) << vn << setw(15) << endl;
	        myfile1.close();
	        date1();
		}
		else
		{
			cout << "\t You have successfully registered your 2nd dose vaccine for CovidShield.";
			myfile1 << pv << setw(15) << vn << setw(15) << endl;
	        myfile1.close();
			date2();
		}
	}
	
	else if(pv==4)
	{
		if(vn==1)
		{
			cout << "\t You have successfully registered your 1st dose vaccine for Covaxin.";
			myfile1 << pv << setw(15) << vn << setw(15) << endl;
	        myfile1.close();
	        date1();
		}
		else
		{
			cout << "\t You have successfully registered your 2nd dose vaccine for Covaxin.";
			myfile1 << pv << setw(15) << vn << setw(15) << endl;
	        myfile1.close();
			date2();
		}
	}
	else
	{
		cout << "Please enter a valid number." << endl;
		pick_vaccine();
	}
	
	myfile1 << pv << setw(15) << vn << setw(15) << endl;
	myfile1.close();
}

//---------------------------------------------show1 part--------------------------------------

void covid_vaccine::show1()
{
	cout<<"\n\t  ";
	cout<<"FirstName"<<setw(15)<<"LastName"<<setw(15)<<"Address"<<setw(15)<<"Age"<<setw(15)<<"Gender"<<setw(15)<<"IdNumber\n"<<setw(15);
}

//-------------------------------------view your detail------------------------------------------
void covid_vaccine::view_your_details()
{
	string f,l,a,ag,g;
	int cn;
	ifstream file;
	int search;
	int count = 0;
	cout<<"\tEnter your profile Id number: ";
	cin>>search;
	file.open("users_data.txt",ios::in);
	show1();
	while(!file.eof())
	{
		if(search == cn)
		{
			cout<<"\n\t  ";
				cout << f << setw(15) << l << setw(15) << a << setw(15) << ag << setw(15) << g << setw(15) << cn << endl;
			count++;
		}
			file >> f >> setw(15) >> l >> setw(15) >> a >> setw(15) >> ag >> setw(15) >> g >> setw(15) >> cn;
	}
	file.close();
	if(count == 0)
		cout<<"\n\nRecord not found.";
	getch();
	user_option();
}

//************************************MAIN*******************************************
int main()
{
	
	front();
	system("cls");
	cout<<"\t\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\t                             **    COVID-19 VACCINE MANAGEMENT SYSTEM   **";
	cout<<"\t\n------------------------------------------------------------------------------------------------------------------------\n";
	covid_vaccine system;
	system.menu();
}


