#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

int main() {
	std::string prog = "1";
	std::ofstream logp1("ipass.txt");            //file reader
	while(logp1)
	int logp = 001, pass = 231, attempts=3, info=34; //instead of numbers attach txt files
	int login, paswd, acces = 0;
	std::cout << "What do you want today?\nType login to acces you account and check taxes\nType exit to shut down program\n";
	std::cin >> prog;                 //stting prog wiil be the main control word
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
					//system("cls");
				}
			}
			else
			{
				std::cout << "There is no such user in data base, or you make a mistake in login.\nTry again\n";
				std::cin >> login;
			}
			//system("cls");
		}
	}
	if (prog == "aproved") {
		std::cout <<"Taxes needed to be payed: " << info<<"\nTo close the program type exit\n"; //attach the data bast .txt
		std::cin >> prog;                                       //will acces your data base
	}
	if (prog == "exit" || prog == "e" || prog == "ex")                //just ends the program
		return 0;
return 0;
}
