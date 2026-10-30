#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void ShowMainMenue(sClient& Client);

enum enChoose
{
	enQuickDraw = 1, enNormalDraw = 2, enDeposite = 3, enBalance = 4, enLogout = 5
};

struct sClient
{
	string FirstName;
	string LastName;
	string Email;
	string phone;
	string AccoutnNumber;
	string PinCode;
	double Balance;
};

static vector<string> Split(string S1, string Delim)
{

	vector<string> vString;

	short pos = 0;
	string sWord; // define a string variable  

	// use find() function to get the position of the delimiters  
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); // store the word   
		// if (sWord != "")
		// {
		vString.push_back(sWord);
		//}

		S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
	}

	if (S1 != "")
	{
		vString.push_back(S1); // it adds last word of the string.
	}

	return vString;

}

sClient ConverteLineToClient(string s, string Sep = "#//#")
{
	sClient Client;
	vector <string> vClient = Split(s, "#//#");
	Client.FirstName = vClient[0];
	Client.LastName = vClient[1];
	Client.Email = vClient[2];
	Client.phone = vClient[3];
	Client.AccoutnNumber = vClient[4];
	Client.PinCode = vClient[5];
	Client.Balance = stoi(vClient[6]);
	return Client;
}

vector <sClient> LoadDataFromFile()
{
	vector<sClient> vClient;

	fstream MyFile;
	MyFile.open("Clients.txt", ios::in);// read Mode
	if (MyFile.is_open())
	{
		string line;

		while (getline(MyFile, line))
		{
			sClient Client = ConverteLineToClient(line);
			vClient.push_back(Client);
		}
		MyFile.close();
	}
	return vClient;
}

bool FindByAccountNumber(string AccountNumber, vector <sClient> vClients, sClient& C)
{
	for (sClient Client : vClients)
	{
		if (Client.AccoutnNumber == AccountNumber)
		{
			C = Client;
			return true;
		}
	}
	return false;
}

void GoBackToMainMenue()
{
	cout << "Press any key to go back to Main Menue ...";
	system("pause > 0");
	ShowMainMenue();
}

void QuickWithDraw(sClient& Client)
{
	int x;
	cin >> x;
	if (x <= Client.Balance)
	{
		char Ans;
		cout << "\n\nAre You Sure You Want to Perform this Transaction ? (y/n) ";
		cin >> Ans;
		if (Ans == 'y' || Ans == 'Y')
		{
			switch (x)
			{
			case(1):Client.Balance -= 20;
			case(2):Client.Balance -= 50;
			case(3):Client.Balance -= 100;
			case(4):Client.Balance -= 200;
			case(5):Client.Balance -= 400;
			case(6):Client.Balance -= 600;
			case(7):Client.Balance -= 800;
			case(8):Client.Balance -= 1000;
			}
			cout << "\nDone Succefully, Your Balance is : " << Client.Balance;
		}
		else
		{

		}
	}
}

void ShowQuickWithDraw(sClient& Client)
{
	cout << "====================================\n";
	cout << "          Quick With Draw\n";
	cout << "====================================\n";
	cout << "      [1] 20         [2] 50 \n";
	cout << "      [3] 100        [4] 200 \n";
	cout << "      [5] 400        [6] 600 \n";
	cout << "      [7] 800        [8] 1000 \n";
	cout << "====================================\n";
	cout << "Your Balance is : " << Client.Balance << endl;
	cout << "Choose How Much To Withdraw from [1 to 8] : ";
	QuickWithDraw(Client);
}

void ReadWhatDoYouWanatToDo(sClient& Client)
{
	int Choose;
	cin >> Choose;
	switch (Choose)
	{
	case(enChoose::enQuickDraw):
	{
		system("cls");
		ShowQuickWithDraw(Client);
		GoBackToMainMenue();
	}
	case(enChoose::enNormalDraw):
	{
		system("cls");
		cout << "Soon ...\n";
		GoBackToMainMenue();
	}
	case(enChoose::enDeposite):
	{
		system("cls");
		cout << "Soon ...\n";
		GoBackToMainMenue();
	}
	case(enChoose::enBalance):
	{
		system("cls");
		cout << "Soon ...\n";
		GoBackToMainMenue();
	}
	case(enChoose::enLogout):
	{
		system("cls");
		cout << "Soon ...\n";
		GoBackToMainMenue();
	}
	}

}

void ShowMainMenue(sClient& Client)
{
	system("cls");
	cout << "========================================\n";
	cout << "           Main Menue Screen\n";
	cout << "========================================\n";
	cout << "         [1] Quick With Draw.\n";
	cout << "         [2] Normal With Draw.\n";
	cout << "         [3] Deposite.\n";
	cout << "         [4] Check Balance.\n";
	cout << "         [5] Logout.\n";
	cout << "========================================\n";
	cout << "Choose What Do You Want To Do [1 to 5] :";
	ReadWhatDoYouWanatToDo(Client);
}

void LoginScreen()
{

	string AccoutnNumber, Pin;
	vector <sClient> vClients = LoadDataFromFile();
	cout << "===============================\n";
	cout << "           Login Screen\n";
	cout << "===============================\n";

	sClient Client;
	cout << "Enter Account Number : ";
	cin >> AccoutnNumber;
	cout << "Enter Pin Code : ";
	cin >> Pin;
	while (!FindByAccountNumber(AccoutnNumber, vClients, Client) || Pin != Client.PinCode)
	{
		cout << "Invalid Account Number / Pin Code, Try Again !\n";
		cout << "Enter Account Number : ";
		cin >> AccoutnNumber;
		cout << "Enter Pin Code : ";
		cin >> Pin;
	}
	ShowMainMenue(Client);

}

int main()
{
	LoginScreen();
}