#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void create_plist(int* logpass) {
std::string text;
std::ifstream names("names_sub.txt");
char lettersb[52] = { 'q','w','e','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m','Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M' };
srand(time(0));
int rando = rand() % 20;
std::cout << rando;
for (int i = 0; i < 21; ++i) {
	getline(names, text);
	if (i == rando) {
		std::cout << text;
	}
	for (int i = 0; i < text.length(); ++i) {
		int zerc = text.length() - 11;
		
		for (int i = 0; i < zerc; ++i)
		{
			logpass[i] = 0;
			std::cout << logpass[i];
		}
	}
}

}

int main() {
	std::ofstream ipass("ipass.txt");
	ipass << 1 << std::endl;
	ipass.close();
	std::vector<int> logs(1);
	create_plist(logs);
}
