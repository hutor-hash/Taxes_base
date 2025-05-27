#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class User{
public:
	int pasword_check(int login, int passwd) {
		int check = 0;
		std::ifstream ipass("ipass.txt");
		int flogin, fpasswd; //сделай проверку пароллей через файл
		
		if (login == flogin)
			check++;
		if (passwd == fpasswd)
			check++;
		if (check == 2)
			return 1;
		return 0;
}
}

class tax_payer : public User {
public:
	int 
};

int main() {

	return 0;
}
