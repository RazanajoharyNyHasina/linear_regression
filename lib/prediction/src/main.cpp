#include <iostream>
#include <fstream>
#include <sstream>

int main(void)
{
	std::ifstream input_file("./training_data.txt");

	double theta0 = 0.0;
	double theta1 = 0.0;
	double mileage_input = 0.0;

	if (not input_file.is_open())
	{
		std::cerr << "prediction_program: input_file.open(): can't open training_data.txt\n";
		exit(1);
	}

	std::string line;
	if (not std::getline(input_file, line))
	{
		std::cerr << "prediction_program: std::getline() : failed to get line\n";
		exit(1);
	}

	if (line.empty())
	{
		std::cerr << "prediction_program: main() : bad format\n";
		exit(1);
	}

	std::stringstream ss(line);
	std::string tmp;
	char *errorCheck = nullptr;

	std::getline(ss, tmp, ',');
	theta0 = std::strtod(tmp.c_str(), &errorCheck);
	if (*errorCheck != '\0')
	{
		std::cerr << "prediction_program: input_file.open(): bad format\n";
		exit(1);
	}

	std::getline(ss, tmp, ',');
	theta1 = std::strtod(tmp.c_str(), &errorCheck);
	if (*errorCheck != '\0')
	{
		std::cerr << "prediction_program: input_file.open(): bad format\n";
		exit(1);
	}

	std::cout << "Enter the mileage: ";
	while (!(std::cin >> mileage_input))
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cerr << "Invalid input. Try again: ";
	}

	std::cout << "The estimated price for a mileage of " << mileage_input << " are " << theta0 + (theta1 * mileage_input) << std::endl;
	return (0);
}