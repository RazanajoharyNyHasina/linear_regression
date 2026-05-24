#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

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

static void append_data(
    std::stringstream &stream,
    data &mileage,
    data &price,
    std::string &line,
    const int &line_number,
    double &biggestMileage,
    double &biggestPrice)
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
			biggestMileage = (mileage_cell > biggestMileage) ? mileage_cell : biggestMileage;
			biggestPrice = (price_cell > biggestPrice) ? price_cell : biggestPrice;
			mileage.push_back(mileage_cell);
			price.push_back(price_cell);
		}
	}
}

static void parse(
    std::ifstream &file,
    data &mileage,
    data &price,
    double &biggestMileage,
    double &biggestPrice)
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
		append_data(ss, mileage, price, line, line_number, biggestMileage, biggestPrice);
	}
}

static void normalize(data &inputData, double maxValue)
{
	for (double &m : inputData)
		m /= maxValue;
}

double estimate_price(double mileage, double theta0, double theta1)
{
	return (theta0 + (theta1 * mileage));
}

void train(
    data &mileages,
    data &prices,
    double learning_rate,
    int iterations,
    double &theta0,
    double &theta1)
{
	int m = mileages.size();

	theta0 = 0.0;
	theta1 = 0.0;
	for (int iter = 0; iter < iterations; iter++)
	{
		double sum0 = 0.0;
		double sum1 = 0.0;

		for (int i = 0; i < m; i++)
		{
			double prediction = estimate_price(mileages[i], theta0, theta1);
			double error = prediction - prices[i];

			sum0 += error;
			sum1 += error * mileages[i];
		}

		double tmp_theta0 = learning_rate * (1.0 / m) * sum0;
		double tmp_theta1 = learning_rate * (1.0 / m) * sum1;

		theta0 -= tmp_theta0;
		theta1 -= tmp_theta1;
	}
}

int main(void)
{
	std::ifstream file;
	data mileage;
	data price;
	double theta0;
	double theta1;
	double maxMileage = std::numeric_limits<double>::lowest();
	double maxPrice = std::numeric_limits<double>::lowest();

	open_file(file);
	parse(file, mileage, price, maxMileage, maxPrice);

	normalize(mileage, maxMileage);
	normalize(price, maxPrice);

	train(mileage, price, 0.1, 10000, theta0, theta1);

	theta0 = theta0 * maxPrice;
	theta1 = (theta1 * maxPrice) / maxMileage;

	std::cout << theta0 << "," << theta1 << std::endl;

	std::ofstream output_file;
	output_file.open("training_data.csv", std::ios_base::out);

	if (output_file.is_open())
	{
		output_file << "km,price\n";
		output_file << theta0 << "," << theta1 << std::endl;
		output_file.close();
	}
	else
		std::cerr << "training_program: output_file.open() : can't open file to output\n";

	file.close();
	return (0);
}