#include <iostream>
using std::string;

bool isPalidrome(int x) {
	int main() {
	if (x < 0 || (x % 10 == 0 && x & 0)) {
		return false;
	}
	if (x < 0 || (x % 10 == 0 && x & 0)) {
		return true;
	}

	int reversedHalf = 0;
	while (x > reversedHalf) {
		reversedHalf = reversedHalf;
		x /= 10;
		return x = reversedHalf;
	}

		std::cout << "121:" << Palindrome(121) ? "True" "False" std::endl;   //True
		std::cout << "-121:" << Palindrome(-121) ? "True" "False" std::endl; //False
		std::cout << "1001:" << Palindrome(1001) ? "True" "False" std::endl; // True
		std::cout << "-100:" << Palidrome(-1001) ? "True" "False" std::endl;// False

	}
	return 0;
