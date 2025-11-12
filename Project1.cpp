#include <iostream>
#include <iomanip>
#include <string>
#include "MyLib.h"
#include <vector>
#include <cctype>
#include <fstream>

using namespace std;
string ClientFilePath = "Client.txt";
string UsersFilePath = "Users.txt";


enum enMenuChoices { ClientList = 1, AddNewClient = 2, DeleteClient = 3, UpdateClient = 4,
    FindClient = 5, Transaction = 6, ManageUsers = 7, LogOut = 8
};

enum enTransactionOption { Diposit = 1, WithDraw = 2, TotalBalance = 3, BackToMainMenu = 4 };

struct stClientData
{
    string AccountNumber = "";
    string PinCode = "";
    string ClientName = "";
    string PhoneNumber = "";
    int AccountBalance = 0;

};
struct stUserInfo
{
    string UserName = "";
    string Password = "";
    short Permisstion = 0;
};
void SaveUsersDataToFile(vector <stUserInfo>& vUsers);
int ReadPositiveNumberInRange(string message, string ErrorMessage, int From, int To) {
    int number = 1;
    do {

        cout << message;
        cin >> number;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
            cin >> number;
        }
    } while (number < From || number > To);


    return number;
}
vector <string> SplitText(string& text, string Dilimiter = " #//# ")
{
    vector <string> vString;

    string word = "";
    short position = 0;

    while ((position = text.find(Dilimiter)) != string::npos)
    {
        word = text.substr(0, position);
        if (!word.empty())
        {
            vString.push_back(word);

            word.clear();
        }
        text.erase(0, position + Dilimiter.length());
    }
    if (!text.empty())
    {
        vString.push_back(text);

    }
    return vString;
}
string ReadString(string Message)
{
    string S1;
    cout << Message << '\n';
    getline(cin >> ws, S1);
    return S1;
}
int ReadPositiveNumber(string message, string ErrorMessage) {
    int number = 1;
    do {

        cout << message;
        cin >> number;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
            cin >> number;
        }
    } while (number < 0);


    return number;
}
char ReadLetter(string Message) 
{
    char letter;
    cout << Message << endl;
    cin >> letter;
    return letter;
}
void LoadFileDataToVector(const string& FilePath, vector<string>& vlines)
{
    vlines.clear();
    fstream Myfile(FilePath, ios::in);
    string Line;

    if (Myfile.is_open())
    {
        while (getline(Myfile, Line))
        {
            vlines.push_back(Line);
        }
        Myfile.close();
    }
    else
    {
        cout << "Error: Could not open file \"" << FilePath << "\" for reading.\n";
        return;
    }
}
void SaveVectorToFile(const string& FilePath, vector <string>& vlines)
{
    fstream Myfile(FilePath, ios::out);//append mod
    if (Myfile.is_open())
    {
        for (string& i : vlines)
        {
            if (!i.empty())
                Myfile << i << endl;
        }
        Myfile.close();

    }
    else
    {
        cout << "Error: Could not open file \"" << FilePath << "\" for writing.\n";
    }

}

void UpdateRecordInFile(const string& FilePath, string Record, string UpdatedRecord)
{
    vector <string> vlines;
    LoadFileDataToVector(FilePath, vlines);
    for (string& i : vlines)
    {
        if (i == Record)
        {
            i = UpdatedRecord;
            break;
        }
    }
    SaveVectorToFile(FilePath, vlines);
}

enMenuChoices ReadMenuChoice()
{

    int choice = ReadPositiveNumberInRange("Choose what do you want to do? [1-8]: ", "Invalid input!, r-enter your choice: ", 1, 8);
    return static_cast<enMenuChoices>(choice);
}
stClientData ConvertLineToRecord(vector <string>& vClientLinesData)
{
    stClientData ClientData;
    ClientData.AccountNumber = vClientLinesData.at(0);
    ClientData.PinCode = vClientLinesData.at(1);
    ClientData.ClientName = vClientLinesData.at(2);
    ClientData.PhoneNumber = vClientLinesData.at(3);
    ClientData.AccountBalance = stod(vClientLinesData.at(4));

    return ClientData;
}
vector <stClientData> LoadFileDataToVector()
{
    vector <stClientData> vClients;
    vector <string> vClientLinesData;
    fstream MyFile(::ClientFilePath, ios::in);
    string Line;
    stClientData Client;
    if (MyFile.is_open())
    {
        while (getline(MyFile, Line))
        {
            vClientLinesData = SplitText(Line);
            Client = ConvertLineToRecord(vClientLinesData);
            vClients.push_back(Client);
        }
        MyFile.close();

    }
    else
    {
        cout << "Error: Could not open file \"" << ClientFilePath << "\" for reading.\n";

    }
    return vClients;
}

// Clients List Part :
void PrintHeader(short ClientNumber)
{
    cout << "                                        Client List (" << ClientNumber << ")                                 " << endl;
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
    cout << "|" << left << setw(20) << " Account Number" << right << " |" << left << setw(15) << " Pin code" << right << " |" << left << setw(30) << " Client Name" << right << " |" << left << setw(15) << " Phone" << right << " |" << left << setw(15) << " Balance" << right << "|" << endl;
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
}
void PrintClientCard(stClientData& ClientData)
{
    cout << "| " << left << setw(20) << ClientData.AccountNumber << right << "| " << left << setw(15) << ClientData.PinCode << right << "| " << left << setw(30) << ClientData.ClientName << right << "| " << left << setw(15) << ClientData.PhoneNumber << right << "| " << left << setw(14) << ClientData.AccountBalance << right << "|" << endl;

}
void ShowClientsList(vector <stClientData>& vClients)
{
    for (stClientData& i : vClients)
    {
        PrintClientCard(i);
    }
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
}
void ShowMainMenuScreen()
{
    system("cls");
    cout << "=====================================================\n";
    cout << setw(30) << "Main Menu\n";
    cout << "=====================================================\n\n";
    cout << "\t" << "[1] Show Clients List.\n";
    cout << "\t" << "[2] Add New Client.\n";
    cout << "\t" << "[3] Delete Client.\n";
    cout << "\t" << "[4] Update Client Data.\n";
    cout << "\t" << "[5] Find Client.\n";
    cout << "\t" << "[6] Transaction.\n";
    cout << "\t" << "[7] Manage Users.\n";
    cout << "\t" << "[8] LogOut.\n\n";
    cout << "=====================================================\n";

}

// Adding New Client Part :
void PrintAddingClientHeader()
{
    cout << "------------------------------------------------\n\n";
    cout << setw(32) << "***Add Client***";
    cout << "\n\n------------------------------------------------\n\n";
}
int IsAccountNumberExists(string& AccountNumber, vector <stClientData>& vClients, stClientData& Client)
{

    for (int i = 0; i < vClients.size(); i++)
    {

        if (AccountNumber == vClients.at(i).AccountNumber)
        {
            Client = vClients.at(i);
            return i;
        }
    }
    return -1;
}
stClientData ReadNewClientData(vector <stClientData>& vClients)
{
    stClientData NewClientData;
    NewClientData.AccountNumber = ReadString("Enter new client number: ");

    while ((IsAccountNumberExists(NewClientData.AccountNumber, vClients, NewClientData)) != -1)
    {
        cout << "Client with number [" << NewClientData.AccountNumber << "] already exists, ";
        NewClientData.AccountNumber = ReadString("Enter new client number: ");
    }
    NewClientData.PinCode = ReadString("Enter new client pin code: ");
    NewClientData.ClientName = ReadString("Enter new client name: ");
    NewClientData.PhoneNumber = ReadString("Enter new client phone number: ");
    NewClientData.AccountBalance = ReadPositiveNumber("Enter new client bank balance: ", "Invalid input, r-enter your balance: ");
    return NewClientData;
}
string ConvertRecordToLine(stClientData& NewClient, string Dilimiter = " #//# ")
{
    string Line = "";
    Line += NewClient.AccountNumber + Dilimiter;
    Line += NewClient.PinCode + Dilimiter;
    Line += NewClient.ClientName + Dilimiter;
    Line += NewClient.PhoneNumber + Dilimiter;
    Line += to_string(NewClient.AccountBalance);
    return Line;
}
void SaveClientsDataToFile(vector <stClientData> &vClients);
void PushNewClientToVector(vector <stClientData>& vClients)
{
    char AddMore = 'n';
    vector <string> vClientToAdd;
    do
    {
        if (toupper(AddMore) == 'Y')
        {
            system("cls");
        }

        vClientToAdd.clear();
        stClientData NewClient = ReadNewClientData(vClients);
        vClients.push_back(NewClient);
        SaveClientsDataToFile(vClients);
        AddMore = ReadLetter("Do you wnat to add more clients? [Y/N]: ");

    } while (toupper(AddMore) == 'Y');
}

// Finding client Part: 
void PrintSearchingClientHeader()
{
    cout << "------------------------------------------------\n\n";
    cout << setw(35) << "***Search For Client***";
    cout << "\n\n------------------------------------------------\n\n";
}
void ClientCard(stClientData& Client)
{
    cout << "\n\nThere are the following the client detaile:\n\n";
    cout << "----------------------------------\n";
    cout << "Account number: " << Client.AccountNumber << endl;
    cout << "Pin code: " << Client.PinCode << endl;
    cout << "Client name: " << Client.ClientName << endl;
    cout << "Phone number: " << Client.PhoneNumber << endl;
    cout << "Account balance: " << Client.AccountBalance << endl << endl;
    cout << "----------------------------------\n";
}
void FindClientByAccountNumber(vector <stClientData>& vClients)
{
    string AccountToSearch = ReadString("Enter account number to search: ");
    stClientData ClientFound;
    int isExists = IsAccountNumberExists(AccountToSearch, vClients, ClientFound);
    if (isExists != -1)
    {
        ClientCard(ClientFound);

    }
    else if (isExists == -1)
    {
        cout << "Client with account number [" << AccountToSearch << "] not found!\n\n";
    }

}


// Deleting Client Part:
void SaveClientsDataToFile(vector<stClientData>& vClients);

void PrintDeletingClientHeader()
{
    cout << "------------------------------------------------\n\n";
    cout << setw(32) << "***Delete Client***";
    cout << "\n\n------------------------------------------------\n\n";
}
void DeleteClientByAccountNumber(vector <stClientData>& vClients)
{
    string AccountToSearch = ReadString("Enter account number to search: ");
    stClientData ClientToDelete;
    int isExists = IsAccountNumberExists(AccountToSearch, vClients, ClientToDelete);

    if (isExists != -1)
    {
        ClientCard(ClientToDelete);
        if (toupper(ReadLetter("Are you sure you want delete this client with number [" + AccountToSearch + "]? [Y/N]: ")) == 'Y')
        {
            vClients.erase(vClients.begin() + isExists);
            SaveClientsDataToFile(vClients);
            cout << "The client with number [" + AccountToSearch + "] was deleted successfully!\n";
        }
    }
    else if (isExists == -1)
    {
        cout << "Client with account number [" << AccountToSearch << "] not found!\n";
    }


}

// Updating Client Data Part:
stClientData NewClientData(stClientData &ClientToUpdate)
{
    

    ClientToUpdate.PinCode = ReadString("Enter new pin code: ");
    ClientToUpdate.ClientName = ReadString("Enter new client name: ");
    ClientToUpdate.PhoneNumber = ReadString("Enter new phone number: ");
    ClientToUpdate.AccountBalance = ReadPositiveNumber("Enter account balance: ", "Invalid input, r-enter account balance: ");

    return ClientToUpdate;
}
void PrintUpdatingClientHeader()
{
    cout << "------------------------------------------------\n\n";
    cout << setw(32) << "***Update Client***";
    cout << "\n\n------------------------------------------------\n\n";
}


void UpdateClientDataByAccountNumber(vector <stClientData>& vClients)
{
    string AccountToSearch = ReadString("Enter account number to search: ");
    stClientData ClientToUpdate;

    int isExists = IsAccountNumberExists(AccountToSearch, vClients, ClientToUpdate);
    string RecordToUpdate = "";
    string UpdatedRecord = "";

    if (isExists != -1)
    {
        ClientCard(ClientToUpdate);
        RecordToUpdate = ConvertRecordToLine(ClientToUpdate);

        if (toupper(ReadLetter("Are you sure you want update this client with number [" + AccountToSearch + "]? [Y/N]: ")) == 'Y')
        {
            ClientToUpdate = NewClientData(vClients.at(isExists));
            UpdatedRecord = ConvertRecordToLine(ClientToUpdate);
            UpdateRecordInFile(::ClientFilePath, RecordToUpdate, UpdatedRecord);

            cout << "The client with number [" + AccountToSearch + "] was updated successfully!\n";
        }
    }
    else if (isExists == -1)
    {
        cout << "Client with account number [" << AccountToSearch << "] not found!\n";
    }

}


// Transaction Part: 
void ShowTransactionMenu()
{
    system("cls");
    cout << "=====================================================\n";
    cout << setw(30) << "Transaction Menu\n";
    cout << "=====================================================\n\n";
    cout << "\t" << "[1] Diposit.\n";
    cout << "\t" << "[2] WithDraw.\n";
    cout << "\t" << "[3] Show Total Balance.\n";
    cout << "\t" << "[4] Go Back To Main Menu.\n";
    cout << "\n=====================================================\n";
}
enTransactionOption ReadTransactionUserChoice()
{
    int choice = ReadPositiveNumberInRange("Choose what do you want to do? [1-4]: ", "Invalid input!, r-enter your choice: ", 1, 4);
    return static_cast<enTransactionOption>(choice);
}

// Diposit Part: 
void PrintDipositHeader()
{
    cout << "------------------------------------------------\n\n";
    cout << setw(32) << "***Diposit Money***";
    cout << "\n\n------------------------------------------------\n\n";
}
void DipositToAccount(vector <stClientData>& vClients)
{
    stClientData ClientToDiposit;
    string AccountToDiposit = ReadString("Enter account number to diposit: ");
    int isExists = IsAccountNumberExists(AccountToDiposit, vClients, ClientToDiposit);

    if (isExists != -1)
    {
        ClientCard(ClientToDiposit);
        do
        {
            vClients.at(isExists).AccountBalance += ReadPositiveNumber("How much do you want to diposit: ", "Invalid input, r-enter money ammount: ");
            SaveClientsDataToFile(vClients);
            cout << "Balance Become: " << vClients.at(isExists).AccountBalance << endl;

        } while (toupper(ReadLetter("Do you want to diposit again? [Y/N]: ")) == 'Y');

    }
    else
        cout << "Client with account number [" << AccountToDiposit << "] not found!\n";
}

// WithDraw Part: 
void PrintWithDrawHeader()
{
    cout << "------------------------------------------------\n\n";
    cout << setw(32) << "***WithDraw Money***";
    cout << "\n\n------------------------------------------------\n\n";
}
bool isOverBalance(int& AccountBalance, int& AmmountToWithDraw)
{

    return AmmountToWithDraw > AccountBalance;
}
void WithDrawFromAccount(vector <stClientData>& vClients)
{
    stClientData ClientToWithDraw;
    string AccountToWithDraw = ReadString("Enter account number to WithDraw: ");
    int isExists = IsAccountNumberExists(AccountToWithDraw, vClients, ClientToWithDraw);
    int AmountToWithDraw = 0;
    bool isOver = false;
    if (isExists != -1)
    {
        ClientCard(ClientToWithDraw);

        do
        {
            do
            {
                if (isOver)
                {
                    cout << "The amount you want to withdraw is greater than what is available in your account\n";
                }
                AmountToWithDraw = ReadPositiveNumber("How much do you want WithDraw: ", "Invalid input, r-enter money amount: ");
                isOver = isOverBalance(vClients.at(isExists).AccountBalance, AmountToWithDraw);
            } while (isOver);

            vClients.at(isExists).AccountBalance -= AmountToWithDraw;
            SaveClientsDataToFile(vClients);
            cout << "Balance Become: " << vClients.at(isExists).AccountBalance << endl;

        } while (toupper(ReadLetter("Do you want to WithDraw again? [Y/N]: ")) == 'Y' && vClients.at(isExists).AccountBalance > 0);

    }
    else
        cout << "Client with account number [" << AccountToWithDraw << "] not found!\n";
}

// show total balance part: 
int CalculateTotalBalance(vector <stClientData>& vClients)
{
    int TotalBalance = 0;

    for (stClientData& i : vClients)
    {

        TotalBalance += i.AccountBalance;

    }
    return TotalBalance;
}
void ShowClientsTotalBalance(vector <stClientData>& vClients)
{
    PrintHeader(vClients.size());
    ShowClientsList(vClients);
    cout << "Clients Total Balance is: " << CalculateTotalBalance(vClients) << endl;
}

void SaveClientsDataToFile(vector<stClientData>& vClients) {
    fstream MyFile(ClientFilePath, ios::out);
    if (MyFile.is_open()) {
        for (stClientData& client : vClients) {
            MyFile << ConvertRecordToLine(client) << endl;
        }
        MyFile.close();
    }
}
void GoBackToMainMenu()
{
    cout << "Press any key to go back Main menu...";
    system("pause>0");
}
void GoBackToTransationMenu()
{
    cout << "Press any key to go back Transation menu...";
    system("pause>0");
}
void ResetFileData(string FilePath)
{
    if (toupper(ReadLetter("Are you sure you want reset the File with path \"" + FilePath + "\" [Y/N]: ") == 'Y'))
    {
        fstream MyFile(FilePath, ios::out);
        if (MyFile.is_open())
        {

            MyFile.close();
        }
        else
        {
            cout << "Could not open the file is path: " << FilePath << " !\n";
        }
    }
    else
        GoBackToMainMenu();
}
void StartTransactionMenu(vector <stClientData>& vClients)
{
    enTransactionOption Choice;

    do
    {
        ShowTransactionMenu();
        Choice = ReadTransactionUserChoice();

        switch (Choice)
        {
        case Diposit:
            system("cls");
            PrintDipositHeader();
            DipositToAccount(vClients);
            GoBackToTransationMenu();
            break;
        case WithDraw:
            system("cls");
            PrintWithDrawHeader();
            WithDrawFromAccount(vClients);
            GoBackToTransationMenu();
            break;
        case TotalBalance:
            system("cls");
            ShowClientsTotalBalance(vClients);
            GoBackToTransationMenu();
            break;
        case BackToMainMenu:
            break;
        default:
            break;
        }
    } while (Choice != 4);


}
// Manage users part: 
enum enUsersChoices { UsersList = 1, AddUser, DelteUser, UpdateUser, FindUser, MainMenu };

void ShowManageUsersMenu()
{
    system("cls");
    cout << "=====================================================\n";
    cout << setw(30) << "Manage Users Menu\n";
    cout << "=====================================================\n\n";
    cout << "\t" << "[1] List Users.\n";
    cout << "\t" << "[2] Add New User.\n";
    cout << "\t" << "[3] Delete User.\n";
    cout << "\t" << "[4] Update User.\n";
    cout << "\t" << "[5] Find User.\n";
    cout << "\t" << "[6] Main Menu.\n";
    cout << "\n=====================================================\n";
}

enMenuChoices ReadManageChoice()
{
    int choice = ReadPositiveNumberInRange("Choose what do you want to do? [1-6]: ", "Invalid input!, r-enter your choice: ", 1, 6);
    return static_cast<enMenuChoices>(choice);
}
void PrintUsersHeader(short UsersNumber)
{
    cout << "                                        Client List (" << UsersNumber << ")                                 " << endl;
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
    cout << "|" << left << setw(20) << " User Name" << right << " |" << left << setw(15) << " Password" << right << " |" << left << setw(30) << " Permission" << endl;
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
}
void PrintUserInfo(stUserInfo &UserDate)
{
    cout << "| " << left << setw(20) << UserDate.UserName << right << "| " << left << setw(15) << UserDate.Password << right << "| " << left << setw(30) << UserDate.Permisstion << endl;

}
void ShowUsersList(vector <stUserInfo>& vUsers)
{
    for (stUserInfo& i : vUsers)
    {
        PrintUserInfo(i);
    }
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
}

// Add user part:
void PrintAddUserHeader()
{
    cout << "------------------------------------------------\n\n";
    cout << setw(32) << "***Add User***";
    cout << "\n\n------------------------------------------------\n\n";
}
int IsUserExists(vector <stUserInfo>& vUsers,string &UserName, stUserInfo& TheUser)
{
    for (int i = 0; i < vUsers.size(); i++)
    {
        if (UserName == vUsers.at(i).UserName)
        {
            TheUser = vUsers.at(i);
            return i;
        }

    }
    return -1;
}
stUserInfo NewUserInfo(vector <stUserInfo>& vUsers)
{
    stUserInfo NewUser;
    NewUser.UserName = ReadString("Enter User Name: ");
    while (IsUserExists(vUsers, NewUser.UserName, NewUser) != -1)
    {
        cout << "User with UserName [" << NewUser.UserName << "] already exist!\n";
        NewUser.UserName = ReadString("Enter User Name: ");
    }
    NewUser.Password = ReadString("Enter Password: ");
    return NewUser;
}
enum enUserPermission
{
    ShowList=1,
    Add=2,
    Delete=4,
    Update=8,
    Find=16,
    transaction=32,
    Manage=64
};
string ConvertUserRecordToLine(stUserInfo User, string Dilimiter = " #//# ")
{
    string Line = "";
    Line += User.UserName + Dilimiter;
    Line += User.Password + Dilimiter;
    Line += to_string(User.Permisstion);
    return Line;
}
short GiveUserPermission(stUserInfo &NewUser)
{
    NewUser.Permisstion = 0;
    if (toupper(ReadLetter("Do you want to give [" + NewUser.UserName + "] full acsses? [Y/N]: ")) == 'Y')
        return NewUser.Permisstion = -1;

    if (toupper(ReadLetter("Do you want to give [" + NewUser.UserName + "] acsses to show client list? [Y/N]: ")) == 'Y')
        NewUser.Permisstion |= enUserPermission::ShowList;
    if (toupper(ReadLetter("Do you want to give [" + NewUser.UserName + "] acsses to add new client? [Y/N]: ")) == 'Y')
        NewUser.Permisstion |= enUserPermission::Add;
    if (toupper(ReadLetter("Do you want to give [" + NewUser.UserName + "] acsses to delete client? [Y/N]: ")) == 'Y')
        NewUser.Permisstion |= enUserPermission::Delete;
    if (toupper(ReadLetter("Do you want to give [" + NewUser.UserName + "] acsses to update client data? [Y/N]: ")) == 'Y')
        NewUser.Permisstion |= enUserPermission::Update;
    if (toupper(ReadLetter("Do you want to give [" + NewUser.UserName + "] acsses to search client? [Y/N]: ")) == 'Y')
        NewUser.Permisstion |= enUserPermission::Find;
    if (toupper(ReadLetter("Do you want to give [" + NewUser.UserName + "] acsses to transaction? [Y/N]: ")) == 'Y')
        NewUser.Permisstion |= enUserPermission::transaction;
    if (toupper(ReadLetter("Do you want to give [" + NewUser.UserName + "] acsses to Manage Users? [Y/N]: ")) == 'Y')
        NewUser.Permisstion |= enUserPermission::Manage;

    return NewUser.Permisstion;
    
}
void SaveUsersDataToFile(vector <stUserInfo>& vUsers) {

    fstream MyFile(::UsersFilePath, ios::out);
    if (MyFile.is_open()) {
        for (stUserInfo& i : vUsers) {
            MyFile << ConvertUserRecordToLine(i) << endl;
        }
        MyFile.close();
    }
}
void PushNewUserToVector(vector <stUserInfo>& vUsers)
{
    char AddMore = 'n';
   
    do
    {
        if (toupper(AddMore) == 'Y')
        {
            system("cls");
        }

        stUserInfo NewUser = NewUserInfo(vUsers);
        NewUser.Permisstion = GiveUserPermission(NewUser);
        vUsers.push_back(NewUser);
        SaveUsersDataToFile(vUsers);
        cout << "User added successfully!\n";
        AddMore = ReadLetter("Do you wnat to add more Users? [Y/N]: ");

    } while (toupper(AddMore) == 'Y');
}
void UserCard(stUserInfo& User)
{
    cout << "\n\nThere are the following the user detaile:\n\n";
    cout << "----------------------------------------------\n";
    cout << "UserName: " << User.UserName << endl;
    cout << "Password: " << User.Password << endl;
    cout << "Permission: " << User.Permisstion << endl;
    cout << "----------------------------------------------\n";
}

// Delete user part:
void PrintDeleteUserHeader()
{
    cout << "------------------------------------------------\n\n";
    cout << setw(32) << "***Delete User***";
    cout << "\n\n------------------------------------------------\n\n";
}


void DeleteUser(vector <stUserInfo>& vUsers)
{
    string UserNameToSearch = ReadString("Enter UserName to search: ");
    if (UserNameToSearch == "Admin")
    {
        cout << "You can't delete this user!\n";
        return;
    }
    stUserInfo UserToDelete;
    int isExists = IsUserExists(vUsers, UserNameToSearch, UserToDelete);

    if (isExists != -1)
    {
        UserCard(UserToDelete);
       
        if (toupper(ReadLetter("Are you sure you want delete this user with UserName [" + UserNameToSearch + "]? [Y/N]: ")) == 'Y')
        {
            vUsers.erase(vUsers.begin() + isExists);
            SaveUsersDataToFile(vUsers);
            cout << "The user with UserName [" + UserNameToSearch + "] was deleted successfully!\n";
        }
    }
    else if (isExists == -1)
    {
        cout << "User with UserName [" << UserNameToSearch << "] not found!\n";
    }


}

// Update user part: 
void PrintUpdateUserHeader()
{
    cout << "------------------------------------------------\n\n";
    cout << setw(32) << "***Update User***";
    cout << "\n\n------------------------------------------------\n\n";
}
stUserInfo NewUserData(stUserInfo& UserToUpdate)
{

    UserToUpdate.Password = ReadString("Enter New Password: ");
    UserToUpdate.Permisstion = GiveUserPermission(UserToUpdate);
    return UserToUpdate;
}
void UpdateUserByUserName(vector <stUserInfo>& vUsers)
{
    string UserNameToSearch = ReadString("Enter UserName to search: ");
    stUserInfo UserToUpdate;

    if (UserNameToSearch == "Admin")
    {
        cout << "This user can't be updated!\n";
        return;
    }

    int isExists = IsUserExists(vUsers, UserNameToSearch, UserToUpdate);
    string RecordToUpdate = "";
    string UpdatedRecord = "";

    if (isExists != -1)
    {
        UserCard(UserToUpdate);

        if (toupper(ReadLetter("Are you sure you want update this client with number [" + UserNameToSearch + "]? [Y/N]: ")) == 'Y')
        {
            RecordToUpdate = ConvertUserRecordToLine(UserToUpdate);
            UserToUpdate = NewUserData(vUsers.at(isExists));
            UpdatedRecord = ConvertUserRecordToLine(UserToUpdate);
            UpdateRecordInFile(::UsersFilePath, RecordToUpdate, UpdatedRecord);
            cout << "The User with username [" + UserNameToSearch + "] was updated successfully!\n";
        }
    }
    else if (isExists == -1)
    {
        cout << "User with UserName [" << UserNameToSearch << "] not found!\n";
    }

}


// finding user part:
void PrintFindUserHeader()
{
    cout << "------------------------------------------------\n\n";
    cout << setw(32) << "***Find User***";
    cout << "\n\n------------------------------------------------\n\n";
}
void FindUserByUserName(vector <stUserInfo>& vUsers)
{
    string UserToSearch = ReadString("Enter UserName to search: ");
    stUserInfo UserToFind;
    int isExists = IsUserExists(vUsers, UserToSearch, UserToFind);
    if (isExists != -1)
    {
        UserCard(UserToFind);

    }
    else if (isExists == -1)
    {
        cout << "User with UserName [" << UserToSearch << "] not found!\n\n";
    }

}

void GoBackToManageUsersMenu()
{
    cout << "Press any key to go back to Manage Users menu...";
    system("pause>0");
}

void StartManageUsers(vector <stUserInfo>& vUsers)
{
    enMenuChoices Choice;
    do
    {
        ShowManageUsersMenu();
        Choice = ReadManageChoice();
        switch (Choice)
        {
        case UsersList:
            system("cls");
            PrintUsersHeader(vUsers.size());
            ShowUsersList(vUsers);
            GoBackToManageUsersMenu();
            break;
        case AddUser:
            system("cls");
            PrintAddUserHeader();
            PushNewUserToVector(vUsers);
            GoBackToManageUsersMenu();
            break;
        case DelteUser:
            system("cls");
            PrintDeleteUserHeader();
            DeleteUser(vUsers);
            GoBackToManageUsersMenu();
            break;
        case UpdateUser:
            system("cls");
            PrintUpdateUserHeader();
            UpdateUserByUserName(vUsers);
            GoBackToManageUsersMenu();
            break;
        case FindUser:
            system("cls");
            PrintFindUserHeader();
            FindUserByUserName(vUsers);
            GoBackToManageUsersMenu();
            break;
        case MainMenu:
            break;
        default:
            break;
        }
    } while (Choice != 6);
    
}

// Seting Login System: 
void PrintLogInScreenHeader()
{
    cout << "------------------------------------------------\n\n";
    cout << setw(35) << "***Login Screen***";
    cout << "\n\n------------------------------------------------\n\n";
}
stUserInfo ConvertUsersLineToRecord(vector <string>& vUsersLinesData)
{
    stUserInfo UserData;
    UserData.UserName = vUsersLinesData.at(0);
    UserData.Password = vUsersLinesData.at(1);
    UserData.Permisstion = stoi(vUsersLinesData.at(2));
   

    return UserData;
}
vector <stUserInfo> LoadUsersFileDataToVector()
{
    vector <stUserInfo> vUsers;
    vector <string> vUsersLinesData;
    fstream MyFile(UsersFilePath, ios::in);
    string Line;
    stUserInfo Users;
    if (MyFile.is_open())
    {
        while (getline(MyFile, Line))
        {
            vUsersLinesData = SplitText(Line);
            Users = ConvertUsersLineToRecord(vUsersLinesData);
            vUsers.push_back(Users);
        }
        MyFile.close();

    }
    else
    {
        cout << "Error: Could not open file \"" << UsersFilePath << "\" for reading.\n";

    }
   
    return vUsers;
}
int IsUserNameAndPasswordCorrect(string &UserName,string &Password,vector <stUserInfo> &vUsers)
{

    for (int i = 0; i < vUsers.size(); i++)
    {

        if (UserName == vUsers.at(i).UserName && Password == vUsers.at(i).Password)
        {
            return i;
        }
    }
    return -1;
}

bool HasPermisstion(stUserInfo& UserPermission,short Permission)
{
    return UserPermission.Permisstion & Permission || UserPermission.Permisstion == -1;
}

void ShowAccessMessage()
{
    system("cls");
    cout << "----------------------------\n";
    cout << "Access denide,\ncontact your Admin.\n";
    cout << "----------------------------\n";
}
void StartMainMenu(vector <stUserInfo> &vUsers, stUserInfo &UserInfo)
{
    vector <stClientData> vClients = LoadFileDataToVector();
    enMenuChoices choice;
    do
    {

        ShowMainMenuScreen();
        choice = ReadMenuChoice();

        switch (choice)
        {
        case ClientList:
            if (HasPermisstion(UserInfo,enUserPermission::ShowList))
            {
                system("cls");
                PrintHeader(vClients.size());
                ShowClientsList(vClients);
            }
            else
                ShowAccessMessage();

            GoBackToMainMenu();
            break;
        case AddNewClient:
            if (HasPermisstion(UserInfo, enUserPermission::Add))
            {
            system("cls");
            PrintAddingClientHeader();
            PushNewClientToVector(vClients);
            }
            else
                ShowAccessMessage();
            GoBackToMainMenu();

            break;
        case DeleteClient:
            if (HasPermisstion(UserInfo, enUserPermission::Delete))
            {
            system("cls");
            PrintDeletingClientHeader();
            DeleteClientByAccountNumber(vClients);
            }
            else
                ShowAccessMessage();
            GoBackToMainMenu();

            break;
        case UpdateClient:
            if (HasPermisstion(UserInfo, enUserPermission::Update))
            {
            system("cls");
            PrintUpdatingClientHeader();
            UpdateClientDataByAccountNumber(vClients);
            }
            else
                ShowAccessMessage();
            GoBackToMainMenu();
            break;
        case FindClient:
            if (HasPermisstion(UserInfo, enUserPermission::Find))
            {
            system("cls");
            PrintSearchingClientHeader();
            FindClientByAccountNumber(vClients);
            }
            else
                ShowAccessMessage();
            GoBackToMainMenu();

            break;
        case Transaction:
            if (HasPermisstion(UserInfo, enUserPermission::transaction))
            {

            StartTransactionMenu(vClients);
            }
            else
                ShowAccessMessage();
            GoBackToMainMenu();
            break;

        case ManageUsers:
            if (HasPermisstion(UserInfo, enUserPermission::Manage))
            {

            StartManageUsers(vUsers);
            }
            else
            {
                ShowAccessMessage();
                GoBackToMainMenu();
            }
            break;

        case LogOut:
            break;
        default:
            break;
        }
    } while (choice != 8);
}
stUserInfo ReadLoginInfo()
{
    stUserInfo UserInfo;
    UserInfo.UserName = ReadString("Enter UserName: ");
    UserInfo.Password = ReadString("Enter Password: ");
    return UserInfo;
}

void ShowIncorrectUserScreen()
{
    cout << "Invalid UserName or Password!\n";
}
void Login()
{
    stUserInfo UserInfo;
    vector <stUserInfo> vUsers = LoadUsersFileDataToVector();
    int isUserExist;
    PrintLogInScreenHeader();

    while (true)
    {

        UserInfo = ReadLoginInfo();
        isUserExist = IsUserNameAndPasswordCorrect(UserInfo.UserName, UserInfo.Password, vUsers);
        if (isUserExist != -1)
        {
            StartMainMenu(vUsers, vUsers.at(isUserExist));
            system("cls");
            PrintLogInScreenHeader();

            continue;
        }
        else
        {
            system("cls");
            PrintLogInScreenHeader();
            ShowIncorrectUserScreen();

            continue;
        }
    }

}

int main()
{
    Login();
    return 0;
}