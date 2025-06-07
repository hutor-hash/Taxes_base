#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cstring>
#include <filesystem>

struct account {
	int log;
	int password;
};

int main() {
	std::string prog = "1";
	//std::ofstream logp1("ipass.txt");            //file reader
	int logp = 001, pass = 231, attempts=3, info=34; //instead of numbers attach txt files
	int login, paswd, acces = 0;
	std::cout << "What do you want today?\nType login to acces you account and check taxes\nType exit to shut down program\nType create to create an account\n";
	std::cin >> prog;                 //stting prog wiil be the main control word
	system("cls");
	if (prog == "login") {
		std::cout << "Enter login: ";
		std::cin >> login;
		while (attempts > 0) {
			if (logp == login) {                       //checks login
				std::cout << "\nEnter password: ";
				std::cin >> paswd;
				if (pass == paswd) {                     //checks password
					acces = 1;
					attempts = -1;
				}
				else {
					attempts = attempts - 1;
					std::cout << "Incorect password.\nAttempts left: " << attempts << "\n";
				}
				if (attempts == -1) {
					prog = "aproved";                     //assign to main control access state
					system("cls");
				}
			}
			else
			{
				std::cout << "There is no such user in data base, or you make a mistake in login.\nTry again\n";
				std::cin >> login;
			}
			system("cls");
		}
	}

	else if (prog == "exit" || prog == "e" || prog == "ex") {                //just ends the program
		return 0;
	}
	else if (prog == "create" || prog == "Create" || prog == "creat" || prog == "c") {
		account a;
		std::cout << "enter your new login: ";
		std::cin >> a.log;
		std::cout << "\nEnter your new password: ";
		std::cin >> a.password;

		std::ifstream counter("accs/counter.txt");
		int counte;
		counter >> counte;
		counte = counte + 1;										//+1 user everytime
		counter.close();
		remove("accs/counter.txt");									//removes old file
		std::ifstream check("accs/counter.txt");
		if (!check) {
			std::cout << "\nThe counter has been updated!\n";       //checks if file reomoved
		}
		else {
			std::cout << "\nSomething went wrong";
		};

		std::ofstream counter1("accs/counter.txt", std::ios::trunc); //and creates new one with updated user count
		counter1 << counte;
		counter1.close();

		std::cout << "you are " << counte << " user in system!";
		std::string mainname = "user.bin";
		std::string way = "accs/";                                   //necesary extensions for file creation
		std::string filename = way + std::to_string(counte) + mainname; //constructing dile name
		std::cout << "\nfilename: " << filename;
		std::ofstream outfile(filename, std::ios::binary);           //creates bin file

		if (!outfile)
			std::cout << "cannot opne file\n";
		outfile.write(reinterpret_cast<char*>(&a), sizeof(account));
		outfile.close();
		std::ifstream itfile(filename, std::ios::binary);
		itfile.read(reinterpret_cast<char*>(&a), sizeof(account));   //I've created it just for test of reading bin files
		outfile.close();

		std::cout << "\nYour log: " << a.log << "\nYour password: " << a.password;

	}
	else {
		std::cout << "there is no such command\n";
	};
	

	if (prog == "aproved") {
		std::cout << "Taxes needed to be payed: " << info << "\nTo close the program type exit\n"; //attach the data bast .txt
		std::cin >> prog;                                       //will acces your data base
	}
return 0;
}

