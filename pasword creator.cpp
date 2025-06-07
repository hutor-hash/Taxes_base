#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>

struct account {
	int log;
	int password;
};

void create_plist() {
	account a;
	std::cin>>a.log;
	std::cout << "\n";
	std::cin >> a.password;
	std::ofstream outfile("ipass.bin", std::ios::binary);
	if (!outfile)
		std::cout << "cannot opne file\n";
	outfile.write(reinterpret_cast<char*>(&p), sizeof(account));
	outfile.close();
	std::cout<<"\nnice"
}