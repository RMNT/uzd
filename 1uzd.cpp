#include <iostream>
#include <string>

void readData(std::string score[], int*, int*);
int countPoints(int*, int*);

const int MATCHES = 10;

int main() {
	std::string scores[MATCHES] = { "3:1", "2:2", "0:1", "4:2", "1:1", "0:3", "4:4", "3:1", "1:3", "4:2"};
	int* home = new int[MATCHES];
	int* opp = new int[MATCHES];

	readData(scores, home, opp);
	std::cout << "Points: " << countPoints(home, opp) << std::endl;

	delete home;
	delete opp;

	return 0;
}

void readData(std::string score[], int* h, int* opp) {
	int ch;
	bool cont;
	std::string temp;

	for (int i = 0; i < MATCHES; ++i) {
		ch = 0;
		temp = "";
		cont = true;
		
		while (isdigit(score[i][ch])) {
			//if (score[i][ch] >= 0 && score[i][ch] <= 4) {
				temp += score[i][ch];
				++ch;
			/*}
			else {
				cont = false;
				break;
			}*/
		}
		h[i] = stoi(temp);	

		temp = "";
		++ch;
		
		while (isdigit(score[i][ch]) && cont) {
			//if (score[i][ch] >= 0 && score[i][ch] <= 4) {
				temp += score[i][ch];
				++ch;
			/*}
			else
				cont = false;*/
		}
		//if (cont)
			opp[i] = stoi(temp);
		//else
			//opp[i] = INT_MAX;
	}
}
int countPoints(int* h, int* opp) {
	int sum = 0;

	for (int i = 0; i < MATCHES; ++i) {
		if (h[i] > opp[i])
			sum += 3;
		else if (h[i] == opp[i])
			++sum;
	}
	return sum;
}