#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <exception>

typedef std::vector<double> data;

static void open_file(std::ifstream &file)
{
	file.open("./data.csv", std::ios_base::in);

	if (not file.is_open())
	{
		std::cerr << "training_program: file.open() : can't open data.csv\n";
		exit(1);
	}
	else if (file.bad())
	{
		std::cerr << "training_program: file.open() : an error occured when opening the file\n";
		exit(1);
	}
}

static void append_data(std::stringstream &stream, data &mileage, data &price, std::string &line, const int &line_number)
{
	std::string tmp;
	double mileage_cell;
	double price_cell;
	char *errorCheck = NULL;
	bool found_error = false;

	std::getline(stream, tmp, ',');
	mileage_cell = std::strtod(tmp.c_str(), &errorCheck);
	if (*errorCheck != '\0')
	{
		std::cerr << "training_program: parse() -> append_data() : strtod() : parsing error : line " << line_number << " : '" << line << "' LINE SKIPPED\n";
		found_error = true;
	}

	if (not found_error)
	{
		std::getline(stream, tmp, ',');
		price_cell = std::strtod(tmp.c_str(), &errorCheck);
		if (*errorCheck != '\0')
		{
			std::cerr << "training_program: parse() -> append_data() : strtod() : parsing error : line " << line_number << " : '" << line << "' LINE SKIPPED\n";
			found_error = true;
		}
		if (not found_error)
		{
			mileage.push_back(mileage_cell);
			price.push_back(price_cell);
		}
	}
}

static void parse(std::ifstream &file, data &mileage, data &price)
{
	std::string line;
	std::string tmp;
	int line_number = 0;

	while (std::getline(file, line))
	{
		std::stringstream ss(line);

		if (++line_number == 1)
			continue;

		if (line.empty())
			continue;
		append_data(ss, mileage, price, line, line_number);
		line_number++;
	}
}

int main(void)
{
	std::ifstream file;
	data mileage;
	data price;

	open_file(file);
	parse(file, mileage, price);

	for (size_t i = 0; i < mileage.size(); i++)
		std::cout << mileage[i] << "," << price[i] << std::endl;

	file.close();
	return (0);
}