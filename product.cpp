#include <format>      // на відміну від стандартних бібліотек, що підключаються <>, 
#include "product.h";  // власні бібліотеки підключаються ""

// реалізуємо методи структури через доступ "struct::method"
bool Product::load_from_file(std::ifstream& file) {
	std::getline(file, name);
	if (name.empty()) {
		return false;
	}
	std::string line;
	std::getline(file, line);
	price = std::stof(line);

	std::getline(file, line);
	stock = std::stoi(line);

	std::getline(file, line);
	discount_percent = std::stoi(line);

	return true;
}

void Product::save_to_file(std::ofstream& file) const {
	file << name << "\n"
		<< price << "\n"
		<< stock << "\n"
		<< discount_percent << "\n";
}

std::string Product::to_string() {
	return name + ", $" + std::format("{:.2f}", price)
		+ " (discount " + std::to_string(discount_percent)
		+ "), available " + std::to_string(stock) + " pcs";
}