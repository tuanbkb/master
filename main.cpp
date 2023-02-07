#include <iostream>
#include <cstdlib>

using namespace std;

int guessNumber(int low, int high);
char checkAnswer(int number);

int main(int argc, char *argv[]) {
	cout << "Choose your number. ";
	system("pause");
	
	int low = 1;
	int high = 100;
	int number;
	char result;
	
	do {
		number = guessNumber(low, high);
		result = checkAnswer(number);
		if (result == '>') low = number;
		else if (result == '<') high = number;
		else cout << "Your number is " << number << "!";
	}
	while (result != '=');
	
	return 0;
}

int guessNumber(int low, int high) {
	return (low + high)/2;
}

char checkAnswer(int number) {
	cout << "Is your number " << number << "? (>/</=)\n";
	char check;
	cin >> check;
	return check;
}
