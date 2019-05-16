#include <iostream>
#include <vector>

int landPerimeter(std::string is[]);

//esme nuo daugiau kaimynniu, tuo maziau perimetro tures pati sala
//is 4 atimamas kaimynu skaicius ir viskas sudedama

int main() {
	std::string islands[5] = {"XOOO",
		"XOXO",
		"XOXO",
		"OOXX",
		"OOOO"
};

	std::cout << landPerimeter(islands) << std::endl;

	return 0;
}
int landPerimeter(std::string is[]) {
	int per = 0;
	int cnt;
	int neighboours;

	for (int i = 0; i < is[0].length()-1; ++i) {
		cnt = 0;

		for (int j = 0; j < is[0].length() -1; ++j) {
			neighboours = 0;
			if (is[i][j] == 'X') {
				if ((i == 0) && (j == 0)) { //corner check
					if (is[i][j + 1] == 'X')
						++neighboours;
					if (is[i + 1][j] == 'X')
						++neighboours;
				}
				else if ((i == 0) && (j == is[0].length()-1)) { //corner check
					if (is[i][j - 1] == 'X')
						++neighboours;
					if (is[i + 1][j] == 'X')
						++neighboours;
				}

				else if ((i == is[0].length()-1) && (j == 0)) { //corner check
					if (is[i-1][j] == 'X')
						++neighboours;
					if (is[i][j + 1] == 'X')
						++neighboours;
				}
				else if ((i == j) && (i == is[0].length() -1)) { //corner check
					if (is[i-1][j] == 'X')
						++neighboours;
					if (is[i][j - 1] == 'X')
						++neighboours;
				}
				else if (i == 0) { //edge check
					if (is[i + 1][j] == 'X')
						++neighboours;
					if (is[i][j - 1] == 'X')
						++neighboours;
					if (is[i][j + 1] == 'X')
						++neighboours;
				}
				else if (j == 0) { //edge check
					if (is[i][j + 1])
						++neighboours;
					if (is[i-1][j])
						++neighboours;
					if (is[i+1][j])
						++neighboours;
				}
				else if (i == is[0].length()-1) {

				}
				else { //all other areas
					if (is[i-1][j] == 'X')
						++neighboours;
					if (is[i][j-1] == 'X')
						++neighboours;
					if (is[i+1][j] == 'X')
						++neighboours;
					if (is[i][j + 1] == 'X')
						++neighboours;
				}
				per += (4 - neighboours);
			}
		}
	}

	return per;
}