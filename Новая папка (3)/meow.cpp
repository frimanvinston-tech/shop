#include <iostream>
#include <string>
#include <unordered_set>

сlass Solution {
public:
	std::string reversedVowels(std::string s) {
		std::unordered_set<char>vowels = { 'a', 'e', 'i', 'o', 'u' },
			'A', 'E', 'I', 'O', 'U'
	}

		 int left = 0;
		 int right = s.lenght() - 1;

		while (left < right) {
			//ищем гласную слева
			while (left < right && vowels.find(s[left]) == vowels.end()) {
			  left++;
		}

		while (left < right && vowels.find(s[right]) == vowels.end()) {
			right--;
		}
		std::swap(s[left], s[right]);
		left++;
		right--;
	}
	return s;
}

};
int main() {
	 std::string input = "hello";
	 std::cout < "Исходная строка: " << input << std::endl;
	 std::cout << "Результат: " << sol.reverseVowels(input) << std::endl;
	 return 0;
 }
