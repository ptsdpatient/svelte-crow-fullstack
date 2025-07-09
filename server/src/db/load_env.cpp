#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <filesystem> // C++17
#ifdef _WIN32
#include <cstdlib> // For _putenv
#else
#include <unistd.h>
#endif

void load_env(const std::string& filename = ".env") {
	// Print the absolute path
	std::filesystem::path abs_path = std::filesystem::absolute(filename);
	std::cout << "Looking for .env at: " << abs_path << std::endl;

	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Could not open .env file at: " << abs_path << std::endl;
		return;
	}

	std::string line;
	while (getline(file, line)) {
		if (line.empty() || line[0] == '#') continue;

		size_t eq_pos = line.find('=');
		if (eq_pos == std::string::npos) continue;

		std::string key = line.substr(0, eq_pos);
		std::string value = line.substr(eq_pos + 1);

		key.erase(0, key.find_first_not_of(" \t"));
		key.erase(key.find_last_not_of(" \t") + 1);
		value.erase(0, value.find_first_not_of(" \t"));
		value.erase(value.find_last_not_of(" \t") + 1);

#ifdef _WIN32
		std::string entry = key + "=" + value;
		_putenv(entry.c_str());
#else
		setenv(key.c_str(), value.c_str(), 1);
#endif
	}

	file.close();
}
