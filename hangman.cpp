#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

string chooseWord();
void renderGame(string guessedWord, int badGuessCount);
string update(string guessedWord, string secretWord, char guess);
char readAGuess();
bool contains(string secretWord, char guess);

int main() {
	srand(time(0));
	string secretWord = chooseWord();
	string guessedWord = string(secretWord.length(), '-');
	int badGuessCount = 0;
	const int MAX_BAD_GUESSES = 7;
	const string WORD_LIST[] = {"angle", "ant", "apple", "arch", "arm", "army",
        "baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry",
        "bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
        "brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
        "cake", "camera", "card",  "cart", "carriage", "cat", "chain", "cheese", "chest",
        "chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
        "cow", "cup", "curtain", "cushion",
        "dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
        "face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
        "foot", "fork", "fowl", "frame",
        "garden", "girl", "glove", "goat", "gun",
        "hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
        "hospital", "house",
        "island", "jewel",
        "kettle", "key", "knee", "knife", "knot",
        "leaf", "leg", "library", "line", "lip", "lock",
        "map", "match", "monkey", "moon", "mouth", "muscle",
        "nail", "neck", "needle", "nerve", "net", "nose", "nut",
        "office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
        "pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
        "rail", "rat", "receipt", "ring", "rod", "roof", "root",
        "sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
        "shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
        "square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
        "store", "street", "sun",
        "table", "tail", "thread", "throat", "thumb", "ticket", "toe", "tongue", "tooth",
        "town", "train", "tray", "tree", "trousers",
        "umbrella",
        "wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm"};
	
	do {
		renderGame(guessedWord, badGuessCount);
		char guess = readAGuess();
		if (contains(secretWord, guess))
			guessedWord = update(guessedWord, secretWord, guess);
		else badGuessCount++;
	}
	while (badGuessCount < MAX_BAD_GUESSES && secretWord != guessedWord);
	
	renderGame(guessedWord, badGuessCount);
	
	if (badGuessCount < MAX_BAD_GUESSES) cout << "Congratulations! You win!";
	else cout << "You lost. The correct word is " << secretWord;
	return 0;
}

string chooseWord() {
	int randomIndex = rand() % sizeof(WORD_LIST);
	return WORD_LIST[randomIndex];
}

void renderGame(string guessedWord, int badGuessCount) {
	cout << guessedWord << endl;
	cout << "Number of wrong guesses: " << badGuessCount << endl;
}

string update(string guessedWord, string secretWord, char guess) {
	for (int i = secretWord.length() - 1; i >= 0; i--) {
		if (secretWord[i] == guess) {
			guessedWord[i] = guess;
		}
	}
	return guessedWord;
}

char readAGuess() {
	char guess;
	cout << "Guess a letter: ";
	cin >> guess;
	return guess;
}

bool contains(string secretWord, char guess) {
	for (int i = 0; i < secretWord.length(); i++) {
		if (guess == secretWord[i]) return true;
	}
	return false;
}
