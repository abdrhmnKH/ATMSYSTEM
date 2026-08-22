#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
void PressAnyKeyToContinue() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	system("pause > nul");
}
const string ClientsFileName = "Clients.txt";
struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
	bool MarkForUpdate = false;
};
vector<string> SplitString(string S1, string Delim)
{
	vector<string> vString;
	short pos = 0;
	string sWord; // define a string variable
	// use find() function to get the position of the delimiters
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); // store the word
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "")
	{
		vString.push_back(S1); // it adds last word of the string.
	}
	return vString;
}
sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{

	sClient Client;
	vector<string> vClientData;

	vClientData = SplitString(Line, Seperator);

	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]);//cast string to double


	return Client;

}
string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{

	string stClientRecord = "";

	stClientRecord += Client.AccountNumber + Seperator;
	stClientRecord += Client.PinCode + Seperator;
	stClientRecord += Client.Name + Seperator;
	stClientRecord += Client.Phone + Seperator;
	stClientRecord += to_string(Client.AccountBalance);

	return stClientRecord;

}
vector <sClient> SaveCleintsDataToFile(string FileName, vector <sClient> vClients)
{

	fstream MyFile;
	MyFile.open(FileName, ios::out);//overwrite

	string DataLine;

	if (MyFile.is_open())
	{

		for (sClient C : vClients)
		{

			if (C.MarkForDelete == false)
			{
				//we only write records that are not marked for delete.  
				DataLine = ConvertRecordToLine(C);
				MyFile << DataLine << endl;

			}

		}

		MyFile.close();

	}

	return vClients;

}
vector <sClient> LoadCleintsDataFromFile(string FileName)
{

	vector <sClient> vClients;

	fstream MyFile;
	MyFile.open(FileName, ios::in);//read Mode

	if (MyFile.is_open())
	{

		string Line;
		sClient Client;

		while (getline(MyFile, Line))
		{

			Client = ConvertLinetoRecord(Line);

			vClients.push_back(Client);
		}

		MyFile.close();

	}

	return vClients;

}
sClient Login(sClient& Client) {
	cout << "Enter AccountNumber? ";
	cin >> Client.AccountNumber;
	cout << "\nEnter Pincode? ";
	cin >> Client.PinCode;
	return Client;
}
bool FindClientByAccountNumber(string AccountNumber,string PinCode,vector <sClient> vClients, sClient& Client)
{

	for (sClient C : vClients)
	{

		if (C.AccountNumber == AccountNumber && C.PinCode==PinCode)
		{
			Client = C;
			return true;
		}

	}
	return false;

}
bool Loginscreen(sClient &Client, vector <sClient>& vClients) {
	cout << "====================================================\n";
	cout << setw(25) << "Login Screen\n";
	cout << "====================================================\n";
	Login(Client);
	while (!FindClientByAccountNumber(Client.AccountNumber,Client.PinCode,vClients, Client)) {
		cout << "Invalid AccountNumber/Password\n";
		Login(Client);
	}
	return true;
}
int ShowOperationScreen() {
	int selection=0;
	cout << "==================================================================\n";
	cout << setw(20) << "ATM Main Menue Screen" << endl;
	cout << "==================================================================\n";
	cout << setw(10) << "[1] Quick Withdraw." << endl;
	cout << setw(10) << "[2] Normal Withdraw." << endl;
	cout << setw(10) << "[3] Deposit." << endl;
	cout << setw(10) << "[4] Check Balance." << endl;
	cout << setw(10) << "[5] Logout." << endl;
	cout << "==================================================================\n";
	cout << "Choose What Do you want to do ?[1 to 5]? ";
	cin >> selection;
	return selection;
}
void QuickWithdraw(sClient &Client, vector<sClient> &vClients) {
	int withdrawselection = 0;
	char ans = 'n';
	cout << "==================================================================\n";
	cout << setw(20) << "Quick Withdraw Screen" << endl;
	cout << "==================================================================\n";
	cout << setw(9) << "[1] 20" << setw(20) << "[2] 50\n";
	cout << setw(10) << "[3] 100" << setw(20) << "[4] 200\n";
	cout << setw(10) << "[5] 400" << setw(20) << "[6] 600\n";
	cout << setw(10) << "[7] 800" << setw(21) << "[8] 1000\n";
	cout << setw(13) << "[9] Exit.\n";
	cout << "==================================================================\n";
	cout << "Your Balance is : " << Client.AccountBalance << endl;
	cout << "Choose What to withdraw from [1] to [9]? ";
	cin >> withdrawselection;
	if (withdrawselection == 9) {
		return;
	}
	cout << "\nAre you sure you want to perform this transaction? (y/n)? ";
	cin >> ans;
	if (ans == 'y' || ans == 'Y') {
		for (sClient& C : vClients) {
			if (C.AccountNumber == Client.AccountNumber) {
				switch (withdrawselection) {
				case 1: {
					if (Client.AccountBalance >= 20)
						Client.AccountBalance -= 20;
					break;
				}
				case 2: {
					if (Client.AccountBalance >= 50)
						Client.AccountBalance -= 50;
					break;
				}
				case 3: {
					if (Client.AccountBalance >= 100)
						Client.AccountBalance -= 100;
					break;
				}
				case 4: {
					if (Client.AccountBalance >= 200)
						Client.AccountBalance -= 200;
					break;
				}
				case 5: {
					if (Client.AccountBalance >= 400)
						Client.AccountBalance -= 400;
					break;
				}
				case 6: {
					if (Client.AccountBalance >= 600)
						Client.AccountBalance -= 600;
					break;
				}
				case 7: {
					if (Client.AccountBalance >= 800)
						Client.AccountBalance -= 800;
					break;
				}
				case 8: {
					if (Client.AccountBalance >= 1000)
						Client.AccountBalance -= 1000;
					break;
				}
				}
				SaveCleintsDataToFile(ClientsFileName, vClients);
				cout << "Done Successfully.New Balance is : " << Client.AccountBalance << endl;
			}
		}
	}
	else
		cout << "Withdraw Operation Failed\n";

}
void Withdraw(sClient& Client, vector<sClient>& vClients) {
	int withdrawamount = 0;
	char ans = 'n';
	cout << "==================================================================\n";
	cout << setw(20) << "Normal Withdraw Screen" << endl;
	cout << "==================================================================\n";
	do {
		cout << "Enter an amount multiple of 5's ? ";
		cin >> withdrawamount;
	} while ((withdrawamount % 5 != 0));
	cout << "\nAre you sure you want to perform this transaction? (y/n)? ";
	cin >> ans;
	if ((ans == 'y' || ans == 'Y')) {
		for (sClient& C : vClients) {
			if (C.AccountNumber == Client.AccountNumber) {
				if (C.AccountBalance >= withdrawamount) {
					C.AccountBalance -= withdrawamount;
					Client = C;
					SaveCleintsDataToFile(ClientsFileName, vClients);
					cout << "Done Successfully.New Balance is : " << Client.AccountBalance << endl;
				}
				else
					cout << "The amount exceeds your balance , make another choice.\n";
			}
			break;
		}
	}
	else
		cout << "Withdraw Operation Failed\n";
}
void Deposit(sClient &Client, vector<sClient> &vClients) {
	int Depositamount = 0;
	char ans = 'n';
	cout << "==================================================================\n";
	cout << setw(20) << "Deposit Screen" << endl;
	cout << "==================================================================\n";
	do {
		cout << "Enter Positive Amount ? ";
		cin >> Depositamount;
	} while (Depositamount <= 0);
	cout << "\nAre you sure you want to perform this transaction? (y/n)? ";
	cin >> ans;
	if ((ans == 'y' || ans == 'Y')) {
		for (sClient& C : vClients) {
			if (C.AccountNumber == Client.AccountNumber) {
				C.AccountBalance += Depositamount;
				Client = C;
				SaveCleintsDataToFile(ClientsFileName, vClients);
				cout << "Done Successfully.New Balance is : " << Client.AccountBalance << endl;
			}
			break;
		}
	}
	else
		cout << "Deposit Operation Failed\n";
}
void CheckBalance(sClient &Client, vector<sClient> &vClients) {
	cout << "==================================================================\n";
	cout << setw(10) << "Check Balance Screen\n";
	cout << "==================================================================\n";
	cout << "Tour Balance is : " << Client.AccountBalance << endl;

}
bool SwitchOperation(sClient &Client, vector<sClient> &vClients) {
	int selection = ShowOperationScreen();
	if (selection == 5) {
		cout << "Logged Out Successfully.\n";
		return true;
	}
	switch (selection) {
	case 1: {
		system("cls");
		QuickWithdraw(Client,vClients);
		cout << "Press any key to return to the main page...";
		PressAnyKeyToContinue();
		return false;
	}
	case 2: {
		system("cls");
		Withdraw(Client, vClients);
		cout << "Press any key to return to the main page...";
		PressAnyKeyToContinue();
		return false;
	}
	case 3: {
		system("cls");
		Deposit(Client, vClients);
		cout << "Press any key to return to the main page...";
		PressAnyKeyToContinue();
		return false;
	}
	case 4: {
		system("cls");
		CheckBalance(Client,vClients);
		cout << "Press any key to return to the main page...";
		PressAnyKeyToContinue();
		return false;
	}
	}
	return false;
}
int main() {
	sClient Client;
	fstream clientfile;
	vector<sClient> vBank;
	vector<sClient> vClients;
	int selection;
	vClients = LoadCleintsDataFromFile(ClientsFileName);
	if (Loginscreen(Client, vClients)) {
		while (true)
		{
			system("cls");
			if (SwitchOperation(Client, vClients))
				break;
		}
	}
	return 0;
}
