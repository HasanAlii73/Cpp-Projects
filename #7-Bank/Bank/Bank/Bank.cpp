#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;
struct sClient
{
	string AccountNumber = "0";
	string PinCode = "0";
	string ClientName = "x";
	string Phone = "000";
	double Balance = 0;
};
// [1]
void ShowOneClientInfo(sClient client)
{
	cout << "|  " << setw(17) << left << client.AccountNumber;
	cout << "|  " << setw(10) << left << client.PinCode;
	cout << "|  " << setw(30) << left << client.ClientName;
	cout << "|  " << setw(17) << left << client.Phone;
	cout << "|  " << setw(9)  << left << client.Balance;
}
void ShowClientsList(vector <sClient> vClient)
{
	cout << "                    Clients List (" << vClient.size() << ") Client(s).\n";
	cout << "-------------------------------------------------------------------------------------------------\n";
	cout << "|  " << left << setw(17) << "Account Number";
	cout << "|  " << left << setw(10) << "PIN code";
	cout << "|  " << left << setw(30) << "Client Name ";
	cout << "|  " << left << setw(17) << "Phone " ;
	cout << "|  " << left << setw(9)  << "Balance\n" ;
	for (sClient& i : vClient)
	{
		ShowOneClientInfo(i);
		cout << endl;
	}
	cout << "---------------------------------------------------------------------------------------------\n\n\n";
	cout << "Press any key to go back to main menue ... ";
	system("pause>0");
	system("cls");
}
// [2]
bool AccNumberExistenceChecker(string accNumber, vector <sClient> vClient, sClient& C)
{
	for (sClient& i : vClient)
	{
		if (i.AccountNumber == accNumber)
		{
			C = i;
			return true;
		}
	}
	return false;
}
sClient Readnewclient(string accNumber = "")
{
	sClient client;
	if(accNumber == "")
	{
		cout << "Enter Account Number : ";
		getline(cin >> ws, client.AccountNumber);
	}
	else
	{
		client.AccountNumber = accNumber;
	}
	cout << "Enter PIN code : ";
	getline(cin >> ws, client.PinCode);
	cout << "Enter Client Name : ";
	getline(cin, client.ClientName);
	cout << "Enter phone Number : ";
	getline(cin, client.Phone);
	cout << "Enter Account Balance : ";
	cin >> client.Balance;
	return client;
}
void AddNewClient(vector <sClient>& vClient)
{
	char ans = 'y';
	do
	{
			system("cls");
			sClient TempCLient;
			cout << "=========================================\n";
			cout << "             Adding Clients List\n";
			cout << "=========================================\n";
			cout << "Adding New Client : \n\n";
			cout << "Enter Account Number : ";
			string Temp;
			cin >> Temp;
			sClient Empty;
			while(AccNumberExistenceChecker(Temp, vClient, Empty))
			{
				cout << "Client with [" << Temp << "] is Alredy Exists, Enter Another Account Number : ";
				cin >> Temp;
			}
				TempCLient.AccountNumber = Temp;
				TempCLient = Readnewclient(Temp);
				vClient.push_back(TempCLient);

				cout << "Client Added Successfully, Do you Want to Add More ? (y/n) ";
			
			cin >> ans;
	} while (ans == 'y' || ans == 'Y');

	cout << "Press any key to go back to main menue ... ";
	system("pause>0");
	system("cls");
}
// [3]
void PrintClientInfo(sClient client)
{
	cout << "This is the Client Info : \n";
	cout << "Client Number : " << client.AccountNumber << "\n";
	cout << "Client pincode : " << client.PinCode << "\n";
	cout << "Client clientname : " << client.ClientName << "\n";
	cout << "Client phone : " << client.Phone << "\n";
	cout << "Client AccountBalance : " << client.Balance << "\n";
}
vector <sClient> DeleteClientFromAccountNumber(string accNumber, vector <sClient> vClient)
{
	sClient c;
	vector<sClient> v2Client;
	if (AccNumberExistenceChecker(accNumber, vClient, c))
	{
		PrintClientInfo(c);
		cout << "Are you Sure you want to Delete this Client ? (y/n) :";
		char a;
		cin >> a;
		if (a == 'y' || a == 'Y')
		{
			for (sClient i : vClient)
			{
				if (i.AccountNumber != accNumber)
					v2Client.push_back(i);
			}
			cout << "Client with Account Number [" << accNumber << "] Deleted Successfully\n";
		}
	}
	else
	{
		cout << "Client With this Account Number Not Found!\n";
	}

	return v2Client;
}
void DeleteClient(vector <sClient>& vClient)
{
	string accnumber;
	cout << "=========================================\n";
	cout << "           Delete Client Screen\n";
	cout << "=========================================\n\n";
	cout << "Enter Client Account Number : ";
	cin >> accnumber;
	vClient = DeleteClientFromAccountNumber(accnumber, vClient);
	cout << "Press any key to go back to main menue ... ";
	system("pause>0");
	system("cls");
}
// [4]
void EditTheClient(vector <sClient>& vClient, string accnumber)
{
	for (sClient& client : vClient)
	{
		if(client.AccountNumber == accnumber)
		{

			cout << "Enter PIN code : ";
			getline(cin >> ws, client.PinCode);
			cout << "Enter Client Name : ";
			getline(cin, client.ClientName);
			cout << "Enter phone Number : ";
			getline(cin, client.Phone);
			cout << "Enter Account Balance : ";
			cin >> client.Balance;
		}
	}
}
void EditClient(vector <sClient>& vClient)
{
	string accnumber;
	sClient client;
	cout << "=========================================\n";
	cout << "            Edit Client Screen\n";
	cout << "=========================================\n\n";
	cout << "Enter Client Account Number : ";
	cin >> accnumber;
	if (AccNumberExistenceChecker(accnumber, vClient, client))
	{
		EditTheClient(vClient, accnumber);
		cout << "Client Witn Account Number [" << accnumber << "] Edited Successfully \n";
	}
	else
	{
		cout << "No Client With this Account Number \n";
	}
	cout << "Press any key to go back to main menue ... ";
	system("pause>0");
	system("cls");
}
// [5]
void FindClient(vector <sClient> vClient)
{
	string accnumber;
	sClient client;
	cout << "=========================================\n";
	cout << "            Find Client Screen\n";
	cout << "=========================================\n\n";
	cout << "Enter Client Account Number : ";
	cin >> accnumber;
	if (AccNumberExistenceChecker(accnumber, vClient, client))
		PrintClientInfo(client);
	else
		cout << "This Account Number Isnot Existed :(\n";
	cout << "Press any key to go back to main menue ... ";
	system("pause>0");
	system("cls");
}
// [6]
void EndProgram()
{
	cout << "=========================================\n";
	cout << "            Program Ended :)\n";
	cout << "=========================================\n\n";
	cout << "Press any key to go back to Exist ... ";
	system("pause>0");
}
// Main Menue
void MainMenu(vector <sClient> &vClient)
{
	cout << "=========================================\n";
	cout << "              Main Menue\n";
	cout << "=========================================\n";
	cout << "          [1] Show Client List.\n";
	cout << "          [2] Add New Ckuent.\n";
	cout << "          [3] Delete Client.\n";
	cout << "          [4] Edit Client Data.\n";
	cout << "          [5] Find Client.\n";
	cout << "          [6] Exit.\n";
	cout << "=========================================\n";
	cout << "Choose What Do You Want To Do ? [1 to 6] :  ";
	short answer;
	cin >> answer;
	if (answer == 1)
	{
		system("cls");
		ShowClientsList(vClient);
		MainMenu(vClient);
	}
	else if (answer == 2)
	{
		system("cls");
		AddNewClient(vClient);
		MainMenu(vClient);
	}
	else if (answer == 3)
	{
		system("cls");
		DeleteClient(vClient);
		MainMenu(vClient);
	}
	else if (answer == 4)
	{
		system("cls");
		EditClient(vClient);
		MainMenu(vClient);
	}
	else if (answer == 5)
	{
		system("cls");
		FindClient(vClient);
		MainMenu(vClient);
	}
	else
	{
		system("cls");
		EndProgram();
	}
}
int main()
{
	vector <sClient> vClient;
	MainMenu(vClient);
}