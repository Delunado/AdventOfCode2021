#include "Problem3.h"

Problem3::Problem3(std::string filepath) : bitsetsData(std::vector<std::bitset<BITS_NUMBER>>())
{
	LoadProblem(filepath);
}

void Problem3::LoadProblem(std::string filepath)
{
	std::fstream file;
	file.open(filepath);

	if (file) {
		while (!file.eof()) {
			std::string nextBitsetStr;
			file >> nextBitsetStr;

			std::bitset<BITS_NUMBER> nextBitset(nextBitsetStr);

			bitsetsData.push_back(nextBitset);
		}

		file.close();
	}
	else {
		std::cout << "Can't open file " << filepath << std::endl;
	}
}

int Problem3::PowerConsumption()
{
	//Here we will count all the appearances of the bit '0'.
	int bits0appearance[BITS_NUMBER]{ 0 };

	for (int i = 0; i < bitsetsData.size(); i++) {
		for (int j = 0; j < bitsetsData[i].size(); j++) {
			if (bitsetsData[i][j] == 0) {
				bits0appearance[j]++;
			}
		}
	}

	std::bitset<BITS_NUMBER> gammaRate;

	for (int i = 0; i < BITS_NUMBER; i++) {
		int bit0appearance = bits0appearance[i];

		gammaRate[i] = bit0appearance > bitsetsData.size() / 2 ? 0 : 1;
	}

	std::bitset<BITS_NUMBER> epsilonRate(gammaRate);
	epsilonRate.flip();

	return gammaRate.to_ulong() * epsilonRate.to_ulong();
}

int Problem3::LifeSupportRating() {
	return CalculateOxygenRating() * CalculateC02Rating();
}

int Problem3::CalculateOxygenRating()
{
	std::vector<std::bitset<BITS_NUMBER>> bitsetsDataOxygen = bitsetsData;

	int bit0appearance = 0;
	int mostRepeatedBit = 0;

	for (int i = 0; i < BITS_NUMBER; i++) {

		//First, we search for the number of 0s.
		for (int j = 0; j < bitsetsDataOxygen.size(); j++) {
			if (bitsetsDataOxygen[j][i] == 0) {
				bit0appearance++;
			}
		}

		//Here, we determine the most repeated bit in the loop
		if (bit0appearance <= bitsetsDataOxygen.size() / 2) {
			mostRepeatedBit = 1;
		}


		//Then, we clean the data. The MOST COMMON for Oxygen.
		for (int j = bitsetsDataOxygen.size() - 1; j >= 0; j--) {
			if (bitsetsDataOxygen[j][i] != mostRepeatedBit) {
				bitsetsDataOxygen.erase(bitsetsDataOxygen.begin() + j); //Posible error?
			}
		}

		bit0appearance = 0;
		mostRepeatedBit = 0;

		if (bitsetsDataOxygen.size() == 1) {
			break;
		}
	}

	//Finally, we process the result.
	std::bitset<BITS_NUMBER> oxygenBitset = bitsetsDataOxygen[0];
	std::cout << oxygenBitset << std::endl;

	return oxygenBitset.to_ulong();
}

int Problem3::CalculateC02Rating()
{
	std::vector<std::bitset<BITS_NUMBER>> bitsetsDataC02 = bitsetsData;

	int bit0appearance = 0;
	int leastRepeatedBit = 1;

	for (int i = 0; i < BITS_NUMBER; i++) {

		//First, we search for the most repeated value.
		for (int j = 0; j < bitsetsDataC02.size(); j++) {
			if (bitsetsDataC02[j][i] == 0) {
				bit0appearance++;
			}
		}

		//Here, we determine the least repeated bit in the loop
		if (bit0appearance <= bitsetsDataC02.size() / 2) {
			leastRepeatedBit = 0;
		}

		//Then, we clean the data. The LEAST COMMON for CO2.
		for (int j = bitsetsDataC02.size() - 1; j >= 0; j--) {
			if (bitsetsDataC02[j][i] != leastRepeatedBit) {
				bitsetsDataC02.erase(bitsetsDataC02.begin() + j); //Posible error?
			}
		}

		bit0appearance = 0;
		leastRepeatedBit = 1;

		if (bitsetsDataC02.size() == 1) {
			break;
		}
	}

	//Finally, we process the result.
	std::bitset<BITS_NUMBER> C02Bitset = bitsetsDataC02[0];
	std::cout << C02Bitset << std::endl;

	return C02Bitset.to_ulong();
}

void Problem3::Resolve()
{
	std::cout << "The final value of the power consumption is " << PowerConsumption() << std::endl;
	std::cout << "The final value of the life support rating is " << LifeSupportRating() << std::endl;
}