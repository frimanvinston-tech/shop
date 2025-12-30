#include <iostream>
#include <vector>
#include <string>


struct Musics {
	std::string text;
	std::string avtor;
	std::string name;



	void add() {
		std::cout << "\nНапиши название песни\n";
		std::getline(std::cin, name);

		std::cout << "\nНапиши автора песни\n";
		std::getline(std::cin, avtor);

		std::cout << "\nНапиши текст песни\n";
		std::getline(std::cin, text);

		std::cout << "\nДанные занесены\n";

		
	}

	void print_music() {
		std::cout << "Название песни- " << name;
		std::cout << "Автор песни- " << avtor;
		std::cout << "Текст песни- " << text;
	}

	
};

struct Music_Man {
	std::vector<Musics> music;
	void add_in_vector(){
		Musics new_music;
		new_music.add();
		music.push_back(new_music);

	}

	void print_all() {
		if (music.empty()) {
			std::cout << "Список дел пуст!\n";
			return;
		}
		for (size_t i = 0; i < music.size(); ++i) {
			music[i].add(i + 1);
		}
	}
};










int main() {

	return 0;
}