#include <iostream>
#include <fstream>
#include <string>
#include <vector>                 //necesary bibliotecas
#include <cstdlib>
#include <windows.h>
#include <gtest/gtest.h>

class account {                                         //main class
protected: 
    std::string log = "0";
    std::string password="0";
    std::string income="0";
    std::string home="0";
    std::string age="0";
public:
    virtual void input_data() {                               //data input
        std::cout << "Enter login: ";
        std::cin >> log;                                
        std::cout << "Enter password: ";
        std::cin >> password;
        std::cout << "Enter income: ";
        std::cin >> income;
        std::cout << "Enter home (square meters): ";
        std::cin >> home;
        std::cout << "Enter age: ";
        std::cin >> age;
    }
    virtual void calculate_taxes() = 0;
    virtual void account_info() const = 0;
	virtual ~account() = default;                         //intialize subclass for main class
    std::string get_login() const { return log; }
    std::string get_password() const { return password; }
};

class pl : public account {
public:
    std::string income_taxes;                      //necesary variables
    std::string estate_taxes;

    void calculate_taxes() override {                   //calculate tax for poland
        double incomepl = std::stod(income);
        double estatepl = std::stod(home);
        if (std::stod(age) >= 26) {
            if (incomepl < 120000) {
                income_taxes = std::to_string(incomepl * 0.12) + " PLN";
            } else {
                income_taxes = std::to_string(incomepl * 0.32) + " PLN";
            }
            estate_taxes = std::to_string(estatepl * 1.18) + " PLN";
        } else {
            income_taxes = "0 PLN";
            estate_taxes = "0 PLN";
        }
    }

	void account_info() const override { 			 //print account info   
        std::cout << "COuntry: Poland\n";
        std::cout << "Income: " << income << "\n";
        std::cout << "Income tax: " << income_taxes << "\n";
        std::cout << "Estate tax: " << estate_taxes << "\n";
    }
};

class ua : public account {                         //ua account tax class
public:
    std::string income_taxes;
    std::string estate_taxes;

    void calculate_taxes() override {
        double incomeua = std::stod(income);
        double estateua = std::stod(home);
        if (std::stod(age) > 18) {
            income_taxes = std::to_string(incomeua * 0.18) + " UAH";
            estate_taxes = std::to_string(estateua * 0.5) + " UAH";
        } else {
            income_taxes = "0 UAH";
            estate_taxes = "0 UAH";
        }
    }

    void account_info() const override {
        std::cout << "Country: Ukraine\n";
        std::cout << "Income: " << income << "\n";
        std::cout << "Incom tax: " << income_taxes << "\n";
        std::cout << "Estate tax: " << estate_taxes << "\n";
    }
};



int main() {
    std::string bulshit;
    int exit = 0;
    while (!exit) {
        std::string prog;                                   //main variable
        std::cout << "What do you want today?\n";
        std::cout << "login - enter person datails\n";

        std::cout << "exit - exit\n";
        std::cin >> prog;
        system("cls");

        if (prog == "login") {
            std::string country;
            std::cout << "choose country (pl/ua): ";
            std::cin >> country;
            account* user = nullptr;
            if (country == "pl") {
                user = new pl();
            } else if (country == "ua") {
                user = new ua();
            } else {
                std::cout << "Idk that country.\n";
                continue;
            }
            user->input_data();
                user->calculate_taxes();                //tax info output
                user->account_info();
                delete user;
                std::cout << "\n\nType e to exit";
                std::cin >> bulshit;
                system("cls");
        } else if (prog == "exit") {
            exit = 1;
        } else {
            std::cout << "There is no such command\n";
        }
    }
    return 0;
}
TEST(AccountTest, InputData) {  
   account* test_account = new pl(); // Создаем объект класса pl или ua  
   test_account->input_data();  
   EXPECT_EQ("0", test_account->get_login()); // Используем метод get_login() для проверки  
   delete test_account;  
}
TEST(PLTests, CalculateTaxesTest) {
    pl user;
    user.input_data();
    user.calculate_taxes();
    EXPECT_EQ(user.income_taxes, "14400 PLN"); // Пример проверки
}
TEST(UATests, CalculateTaxesTest) {
    ua user;
    user.input_data();
    user.calculate_taxes();
    EXPECT_EQ(user.income_taxes, "1800 UAH"); // Пример проверки
}
int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
