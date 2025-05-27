#include <iostream>
#include <fstream>
#include <string>




void create_plist(int logpass) {
std::string text;
std::ifstream names("names_sub.txt");
while (getline(names, text)) {
		std::cout << text;
	}

}

int main() {
	std::ofstream ipass("ipass.txt");
	ipass << 1 << std::endl;
	ipass.close();
	int logs = 0;
	create_plist(logs);
}
