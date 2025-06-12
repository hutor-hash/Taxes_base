#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cstring>
#include <windows.h>
#include <cstdlib>
#include <ctime>

class account {
private:
	std::string log;
	std::string password;
public:
	std::string income;
	std::string home;
	std::string age;
	void account_info() {
		std::cout << "\nYour taxes dependened on your income and home location.\n";
		//write acc info
	}
};

class pl : public account {
public:
	std::string income_taxes;
	std::string estate_taxes;
	void calculate_tpl() {
		double incomepl = std::stod(income);
		double estatepl = std::stod(home);
		if (std::stod(age) > 26) {
			if (incomepl < 120000) {
				income_taxes = std::to_string(incomepl * 0.12) + "PLN"; //12% tax for income below 120000
			}
			else {
				income_taxes = std::to_string(incomepl * 0.32) + "PLN"; //32% tax for income above 120000
			}
			estate_taxes = std::to_string(estatepl * 1.18) + "PLN"; //calculates HOME square meters taxes
		}
		else {
			income_taxes = "0 PLN";
			estate_taxes = "0 PLN"; //if user is below 26 years old, he doesn't pay taxes
		}
	}
	void pl_info() {
		std::cout << "You'r now in Poland\nYour income is: " << income << "\nYour income taxes: "<<income_taxes<<"\nYour esatate taxes: "<<estate_taxes;
		
	}
};


int main() {
	srand(time(0));
	std::string accounttlog;
	int exit = 0;
	while (exit == 0) {
		std::string prog = "1";
		int attempts = 3;
		std::string login, paswd;
		int acces = 0;
		std::cout << "What do you want today?\nType login to acces you account and check taxes\nType exit to shut down program\nType create to create an account\n";
		std::cin >> prog;                 //setting prog wiil be the main control word
		system("cls");
		int accnumer;
		if (prog == "login") {
			std::cout << "Enter login: ";
			std::cin >> login;
			while (attempts > 0) {
				int accnumb;
				std::ifstream counter("accs/counter.txt");
				counter >> accnumb; //reading number of accounts from file
				counter.close();
				std::string mainnam = "user.bin";
				std::string way = "accs/";
				account a;
				for (int i = 0; i <= accnumb; i++) {
					std::string filenam = way + std::to_string(i) + mainnam; //constructing file name
					
					std::ifstream accheck(filenam, std::ios::binary); //opening file for reading
					
					accheck.read(reinterpret_cast<char*>(&a), sizeof(account));
					if (a.log == login) {
						std::cout << "Enter password: ";
						accnumer = i;
						std::cin >> paswd;
						if (a.password == paswd) {
							account a = a;
							system("cls");
							std::cout << "Welcome!";
							Sleep(1500);
							system("cls");
							attempts = -1;
							accheck.close();
						}
						else {
							attempts = attempts - 1;
							std::cout << "Password is incorrect. You have " << attempts << " attempts left.\n";
						}
						if (attempts == -1) {
							prog = "aproved";
							acces = 1;
						}
						else if (attempts == 0) {
							std::cout << "You have no attempts left. Program will be closed in 5 seconds.\n";
							Sleep(2000);
							system("cls");
						}
						
					}
					accheck.close();
				}
			}
		}

		else if (prog == "exit" || prog == "e" || prog == "ex") {                //just ends the program
			exit = 1;
		}
		else if (prog == "create" || prog == "Create" || prog == "creat" || prog == "c") {
			account a;
			std::cout << "enter your new login: ";
			std::cin >> a.log;
			system("cls");

			std::cout << "\nEnter your new password: ";
			std::cin >> a.password;
			double randtax = rand() % 1000 + 1; //random tax for user;
			a.taxes = std::to_string(randtax); //assigning random tax to user
			system("cls");

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
			std::cout << "\nThat tab will be closed in 5 seconds\n";
			Sleep(5000);
			system("cls");
		}
		else {
			std::cout << "there is no such command\n";
		};


		if (prog == "aproved") {
			if (acces == 1) {
				account a;
				std::string mainname = "user.bin";
				std::string way = "accs/";
				std::string filename = way + std::to_string(accnumer) + mainname;
				std::ifstream infoacc(filename, std::ios::binary);

				if (!infoacc) {
					std::cout << "Cannot open file: " << filename << "\n";
					return 1;
				}

				infoacc.read(reinterpret_cast<char*>(&a), sizeof(account));
				infoacc.close();

				system("cls");
				std::cout << "Welcome back user!\nYour taxes needed to be paid: " << a.taxes;

				return 0;
			}
			else {
				std::cout << "You're not allowed to use this command.\n please create your own account\n\nGoodbye!";
				return 0;
			}
		}
	}
}

// ошибка компиляции кода после логина исправь!
// полиморфизм относительно зарплат и налогов к ним и остальных галогов, кто человек, кем работает, возраст, 