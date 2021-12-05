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
	//First is the Oxygen Rating, second is the C02 Rating.
	return FindValuableBitset(1, ComparisonType::MOST_COMMON) * FindValuableBitset(0, ComparisonType::LEAST_COMMON);
}

int Problem3::FindValuableBitset(int valuableBit, ComparisonType comparisonType)
{
	std::vector<std::bitset<BITS_NUMBER>> bitsetsDataCopy = bitsetsData;

	for (int i = 0; i < BITS_NUMBER; i++) {
		//We need this because when we access to bitset[i], we are accessing the position from "back" to "start", NOT as when
		//we access a vector. In "00101", bitset[0] = 1, no 0.
		int nextBitIndex = BITS_NUMBER - i - 1;

		int valuableBitAppearance = 0;


		//First, we search for the number of valuable bits appearances.
		for (int j = 0; j < bitsetsDataCopy.size(); j++) {
			if (bitsetsDataCopy[j][nextBitIndex] == valuableBit) {
				valuableBitAppearance++;
			}
		}


		//Here, we determine the most or least repeated valuable bit in the loop.
		int compareToBit;

		//The following valuableBitAppearance * 2 is done to avoid the integer rounding on division. 
		if (comparisonType == ComparisonType::LEAST_COMMON) {
			compareToBit = (valuableBitAppearance * 2 <= (bitsetsDataCopy.size())) ? valuableBit : 1 - valuableBit;
		}
		else {
			compareToBit = (valuableBitAppearance * 2 >= (bitsetsDataCopy.size())) ? valuableBit : 1 - valuableBit;
		}


		//Then, we clean the data. The MOST COMMON for Oxygen.
		bitsetsDataCopy.erase(
			std::remove_if(bitsetsDataCopy.begin(), bitsetsDataCopy.end(),
				[nextBitIndex, compareToBit](std::bitset<BITS_NUMBER> bitset) {
					return bitset[nextBitIndex] != compareToBit;
				}),

			bitsetsDataCopy.end()
		);

		if (bitsetsDataCopy.size() == 1) {
			break;
		}
	}


	//Finally, we process the result.
	std::bitset<BITS_NUMBER> finalBitset = bitsetsDataCopy[0];

	return finalBitset.to_ulong();
}

void Problem3::Resolve()
{
	std::cout << "The final value of the power consumption is " << PowerConsumption() << std::endl;
	std::cout << "The final value of the life support rating is " << LifeSupportRating() << std::endl;
}