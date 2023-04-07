#include <iostream>
#include <string>
#include <vector>
#include <thread>

using namespace std;

// Helper Functions

string toUpper(string str) {
	// Convert each character of the string to uppercase
	for (int i = 0; i < str.length(); i++) {
		str[i] = toupper(str[i]);
	}

	return str;
}


void displayWelcomeScreen(string text, int repeat) {
	// Loop through and display the text the desired number of times
	for (int i = 0; i < repeat; i++) {
		cout << "+----------------------------------------------+" << endl;
		cout << "|            Welcome to " << text << "         |" << endl;
		cout << "+----------------------------------------------+" << endl;
	}
}

void displayMessage(string text) {

	cout << "+----------------------------------------------+" << endl;
	cout << "              " << text << endl;
	cout << "+----------------------------------------------+" << endl;

}

void displayLoadingAnimation() {
	const int animationDelay = 200; // The delay between frames in milliseconds
	const int numFrames = 10; // The number of frames in the animation
	const string animationFrames[numFrames] = { "|", "/", "-", "\\", "|", "/", "-", "\\", "|", " " }; // The frames of the animation

	// Loop through the frames of the animation
	for (int i = 0; i < numFrames; i++) {
		cout << "\rAuthenticating " << animationFrames[i] << " "; // \r clears the line and \b moves the cursor back
		cout.flush(); // Flush the output buffer
		this_thread::sleep_for(std::chrono::milliseconds(animationDelay)); // Wait for the specified delay
	}
	cout << "\rAuthentication successful!    " << endl; // Clear the line and print the final message
}

void displayShutdownAnimation() {
	const int animationDelay = 200; // The delay between frames in milliseconds
	const int numFrames = 10; // The number of frames in the animation
	const string animationFrames[numFrames] = { "|", "/", "-", "\\", "|", "/", "-", "\\", "|", " " }; // The frames of the animation

	// Loop through the frames of the animation
	for (int i = 0; i < numFrames; i++) {
		cout << "\rLogging OFF & Shutting Down " << animationFrames[i] << " "; // \r clears the line and \b moves the cursor back
		cout.flush(); // Flush the output buffer
		this_thread::sleep_for(std::chrono::milliseconds(animationDelay)); // Wait for the specified delay
	}
	cout << "\rLog off Successful.    " << endl; // Clear the line and print the final message
}

void tableCreationAnimation(string tablename) {
	const int animationDelay = 200; // The delay between frames in milliseconds
	const int numFrames = 10; // The number of frames in the animation
	const string animationFrames[numFrames] = { "|", "/", "-", "\\", "|", "/", "-", "\\", "|", " " }; // The frames of the animation

	// Loop through the frames of the animation
	for (int i = 0; i < numFrames; i++) {
		cout << "\rCreating Table " << tablename << " " << animationFrames[i] << " "; // \r clears the line and \b moves the cursor back
		cout.flush(); // Flush the output buffer
		this_thread::sleep_for(std::chrono::milliseconds(animationDelay)); // Wait for the specified delay
	}
	cout << "\rTable Creation successful!    " << endl; // Clear the line and print the final message
}

bool checkInt(string input) //Int Check V2
{

	if (input.size() == 0)
		return false;

	if (input[0] == '-')
		return false;

	for (int i = 0; i < input.size(); i++)
	{
		if (!isdigit(input[i])) // -100
			return false;
	}

	return true;
}

void printDebugLog(string username, string password, string luckynumber) {
	//Input logs for debug
	cout << endl << endl;
	cout << "Debug Info\n" << " username: " << username << " password : " << password << " Lucky Number : " << luckynumber << endl;
	cout << endl << endl;

}

void writeLineNew(string text) {
	cout << text << endl;
}
void writeLine(string text) {
	cout << text;
}
void makeSpace(int spaceCount) {
	for (int i = 0; i < spaceCount; i++)
	{
		cout << endl;
	}
}

void choicePrompter() {

	makeSpace(2);
	writeLineNew("What would you like to do ? :");
	writeLineNew("0 - > Logoff & Shutdown Program");
	writeLineNew("1 - > List All Records");
	writeLineNew("2 - > List Specific Record");
	writeLineNew("3 - > Add New Row Record");
	makeSpace(2);
	writeLine("Please Choose a process to continue : ");
}
int main() {

	//Global Variables
	string userName = "";
	string passWord = "";
	string luckyNumber = "";
	string userNameEntered = "";
	string passwordEntered = "";
	string columnInput = "";
	string rowInput = "";
	string tableName = "";
	string newInput = "";
	string searchID = ""; 
	string checkrowSize = "";
	string checkColumnSize = "";

	int loginErrorCounter = 3;
	int recoveryInput;
	int recoveryLuckNumber;

	int columnSize = 0;
	int rowSize;
	int processChoice = 0;

	bool programRun = true;
	bool loggedIn = false;
	bool getLucky = true;
	bool recoveryMode = false;
	bool isLoginSuccessful = false;
	bool recordFound = false;
	bool getColumnSize = true;
	bool getRowSize = true;

	//Account creation
	writeLineNew("Welcome to Admin Panel Account Creation");
	writeLine("Please Choose a Username : ");
	cin >> userName;
	writeLine("Please Choose a Password : ");
	cin >> passWord;
	writeLine("Please Choose a Lucky Number : ");
	cin >> luckyNumber;
	//Input check for int size

	while (getLucky)
	{
		if (!checkInt(luckyNumber))
		{
			writeLineNew("You have entered wrong input. You must enter an integer");
			writeLine("Please Choose a Lucky Number : ");
			cin >> luckyNumber;
		}
		else
		{
			cout << "the number is : " << luckyNumber << endl;
			getLucky = false;
		}

	}


	printDebugLog(userName, passWord, luckyNumber);
	writeLine("Please Enter Username to Login: ");
	cin >> userNameEntered;

	while (loginErrorCounter > 0) //Login check with login attemps
	{
		if (userName == userNameEntered) //Correct username -> password check
		{

			writeLineNew("Username Accepted.");
			writeLine("Please enter your password : ");
			cin >> passwordEntered;

			if (passWord == passwordEntered && loginErrorCounter > 0) //Correct password + login error count -> done
			{
				displayLoadingAnimation();
				loginErrorCounter = 3;
				loggedIn = true;
				break;
			}
			else { //Wrong password -> try again.
				loginErrorCounter--;
				cout << "Wrong password. You can try again " << loginErrorCounter << " time(s) before system shutdowns." << endl;
			}
		}
		else { //Wrong username -> recovery options.
			writeLineNew("Wrong Username. Please Get in Touch with Support or Enter Your Lucky Number to Recover Username");
			writeLineNew("1. Contact Support");
			writeLineNew("2. Username Recovery with Lucky Number");
			makeSpace(2);
			writeLine("Please Choose an Option : ");
			cin >> recoveryInput;
			recoveryMode = true;
			while (recoveryMode)
			{
				switch (recoveryInput)
				{
				case 1: //option 1 -> text mail address.
					writeLineNew("You can reach Support via support@support.com");
					recoveryMode = false;
					break;
				case 2:	//option 2 -> recover with Luck Number.
					writeLine("Pleae Enter Your Lucky Number : ");
					cin >> recoveryLuckNumber;
					getLucky = true;
					while (getLucky)
					{
						if (!checkInt(luckyNumber))
						{
							writeLineNew("You have entered wrong input. You must enter an integer");
							writeLine("Please Choose a Lucky Number : ");
							cin >> luckyNumber;
						}
						else
						{
							cout << "the number is : " << luckyNumber << endl;
							getLucky = false;
						}

					}
					if (recoveryLuckNumber == stoi(luckyNumber)) //Recovery successful
					{
						cout << "Your username is : " << userName << " Please DO NOT forget next time. " << endl;
						recoveryMode = false;

					}
					else //Recovery failed
					{
						writeLineNew("Sorry, Wrong Luck Number. Please Get in touch with support via support@support.com");
						recoveryMode = false;
					}
				default: //Wrong recovery option choosen -> break
					writeLineNew("Wrong Recovery Option.Please try later.");
					recoveryMode = false;
					break;
				}
			}
			break;
		}
	}


	while (loggedIn)
	{
		displayWelcomeScreen("Navras Akademi", 1);
		writeLineNew("You have now access to database as Administrator.");
		writeLineNew("You do not have a previous database table, please specify you first table.");

		writeLine("Please Choose A Table Name : ");
		cin >> tableName;
		tableName = toUpper(tableName);
		tableCreationAnimation(tableName);

		writeLineNew("Now you need to specify how many columns you need for this table.");
		writeLine("Please specify number of columns : ");
		cin >> checkColumnSize;
		while (getColumnSize)
		{
			if (!checkInt(checkColumnSize))
			{
				writeLineNew("You have entered wrong input. You must enter an integer");
				writeLine("Please specify number of columns : ");
				cin >> checkColumnSize;
			}
			else
			{
				writeLineNew("Column size confirmed!");
				columnSize = stoi(checkColumnSize);
				getColumnSize = false;
			}

		}

		vector<string> columns(columnSize);

		for (int i = 0; i < columnSize; i++) {
			cout << "Please specify column name " << i + 1 << "  : ";
			cin >> columnInput;
			columnInput = toUpper(columnInput);
			columns[i] = columnInput;
		}

		displayMessage("Columns Created");
		writeLineNew("Table Updated");
		displayMessage("Columns Summary");
		makeSpace(1);
		for (int i = 0; i < columns.size(); i++) {
			cout << columns[i] << " | ";
		}
		makeSpace(2);
		writeLineNew("+----------------------------------------------+");


		writeLineNew("Now you need to specify how many rows you need for this table.");
		writeLine("Please specify number of rows : ");

		cin >> checkrowSize; 

		while (getRowSize)
		{
			if (!checkInt(checkrowSize))
			{
				writeLineNew("You have entered wrong input. You must enter an integer");
				writeLine("Please specify number of rows : ");
				cin >> checkrowSize;
			}
			else
			{
				writeLineNew("Row size confirmed!");
				rowSize = stoi(checkrowSize);
				getRowSize = false;
			}

		}

		
		vector<vector<string>> datatable(rowSize, vector<string>(columns.size()));

		for (int i = 0; i < datatable.size(); i++) {
			for (int j = 0; j < datatable[i].size(); j++) {
				cout << "Enter " << columns[j] << " data for row number " << i + 1 << " : ";
				cin >> rowInput;
				datatable[i][j] = rowInput;
				cout << endl;
			}
		}

		displayMessage("Printing All Records");

		for (int i = 0; i < datatable.size(); i++) {
			for (int j = 0; j < datatable[i].size(); j++) {
				cout << columns[j] << " value of " << "row number " << i + 1 << " is : " << datatable[i][j] << endl;
			}
		}
		vector<string> newRow(columns.size()); 
		choicePrompter();

		do
		{
			cin >> processChoice;
			switch (processChoice)
			{
			case 0:
				displayShutdownAnimation();
				displayMessage("Program Shutdown.");
				programRun = false;
				loggedIn = false;
				break;
			case 1:
				displayMessage("Printing All Records");
				for (int i = 0; i < datatable.size(); i++) {
					for (int j = 0; j < datatable[i].size(); j++) {
						cout << columns[j] << " value of " << "row number " << i + 1 << " is : " << datatable[i][j] << endl;
					}
				}
				choicePrompter();
				break;
			case 2:
				cout << "Enter " << columns[0] << " value of the records for details : ";
				cin >> searchID;
				writeLineNew("+----------------------------------------------+");
				cout << "List of Records Matches with : " << searchID;
				makeSpace(2);
				for (int i = 0; i < datatable.size(); i++) {
					for (int j = 0; j < datatable[i].size(); j++)
					{
						if (datatable[i][j] == (searchID)) {
							recordFound = true;
							displayMessage("Query Result");
							for (int k = 0; k < columns.size(); k++) {
								cout << columns[k] << " : " << datatable[i][k] << endl;
							}
						}
					}

				}
				
				if (!recordFound) {
					displayMessage("No Records Found");
					choicePrompter();
					break;
				}
				choicePrompter();
				break;
			case 3:
							
				displayMessage("Adding New Row Record");
				
				for (int i = 0; i < newRow.size(); i++) {
					cout << columns[i] << " Enter Value : ";
					cin >> newInput;
					newRow[i] = newInput;
				}

				datatable.push_back(newRow);

				displayMessage("New Row Record Successful");
				choicePrompter();
				break;
			default:
				displayShutdownAnimation();
				displayMessage("Wrong Choice - Program Shutdown.");
				programRun = false;
				loggedIn = false;
				break;
			}
			} while (programRun);

		}
	}


