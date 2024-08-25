#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

char askLetter();
bool trueLetter(char letter, string THE_WORD);
string numberAsk(string num);
string num(string text);
int num(int number);

int main()
{
	system("chcp 1251>nul");
	locale loc("Russian_Russia");


	// chapter 1

	// 1
	int survivos, lives, score;
	int i, b, x;

	// 2
	cout << "Seven divided by three is " << 7 / 3 << endl;
	cout << "Seven divided by three is " << 7.0 / 3 << endl;
	cout << "Seven divided by three is " << 7.0 / 3.0 << endl;

	// 3 
	int scoreOne = 0, scoreTwo = 0, scoreTree = 0, averageValue = 0;
	cout << "\n\nEnter the points for the first attempt\n";
	cin >> scoreOne;
	cout << "Enter the points for the second attempt\n";
	cin >> scoreTwo;
	cout << "Enter the points for the third attempt\n";
	cin >> scoreTree;
	averageValue = (scoreOne + scoreTwo + scoreTree) / 3;
	cout << "The average value is: " << averageValue;



	// chapter 2

	// 1
	enum level {Easy, Normal, Hard};
	cout << "Difficulty Levels\n\n";
	cout << "1 - Easy\n";
	cout << "2 - Normal\n";
	cout << "3 - Hard\n\n";
	int choice;
	cout << "Choice: ";
	cin >> choice;
	switch (choice-1)
	{
	case level::Easy:
		cout << "You picked Easy\n";
		break;
	case level::Normal:
		cout << "You picked Normal\n";
		break;
	case level::Hard:
		cout << "You picked Hard\n";
		break;
	default:
		cout << "You made an illegal choice\n";
		break;
	}

	// 2
	int x = 0; // True - int x = 1;
	while (x)
	{
		++x;
		cout << x << endl;
	}

	// 3
	srand(static_cast<unsigned int>(time(0)));
	int secretNumber, tries = 0, guessedNumber;
	int arr[100];
	cout << "\tWelcome to Guess My Number\n\n";
	cout << "Enter an odd number: ";
	cin >> secretNumber;
	do {
		guessedNumber = rand() % 101;
		tries++;
		cout << "\ntry " << tries << " Number: " << guessedNumber << endl;
		if (guessedNumber == secretNumber) {
			cout << "\nPC win";
			break;
		}
	} while (true);



	//	 chapter 3

	// 1
	srand(static_cast<unsigned int>(time(0)));
	int point = 0;
	enum fields { WORD, HINT, NUM_FIELDS };
	const int NUM_WORDS = 5;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{"wall", "Do you feel you're banging your head against something?"},
		{"glasses", "These might help you see the answer."},
		{"labored", "Going slowly, is it?"},
		{"persistent", "Keep at it."},
		{"jumble", "It's what the game is all about."}
	};
	int choice = (rand() % NUM_WORDS);
	string theWord = WORDS[choice][WORD];
	string theHint = WORDS[choice][HINT];
	string jumble = theWord;
	int length = jumble.size();
	for (int i = 0; i < length; ++i)
	{
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}

	cout << "\t\tWelcom to Word Jumble!\n\n";
	cout << "Unscramble the letters to make a word.\n";
	cout << "Enter 'hint' fot a hint.\n";
	cout << "Enter 'quit' to quit the game.\n";
	cout << "The jumble is: " << jumble;
	string guess;
	cout << "\n\nTour guess: ";
	cin >> guess;

	while ((guess != theWord) && (guess != "quit")) {
		if (guess == "hint") {
			cout << theHint;
			point -= 2;
		}
		else {
			cout << "Sorry, that's not it.";
		}
		cout << "\n\nYour guess: ";
		cin >> guess;
	}
	if (guess == theWord) {
		point += theWord.size();
		cout << "\nThat's it! You guessed it! You scored: " << point << " points\n";
	}
	cout << "\nThanks for plaing.";

	// 2
	string phrase = "Game";
	for (int i = 0; i < phrase.size(); ++i) // false - <=
	{
		cout << "Character at position " << i+1 << " is: " << phrase[i] << endl; // false - i
	}

	// 3
	const int ROWS = 2;
	const int COLUMNS = 3;
	char board[ROWS][COLUMNS] = //the values are mixed up
	{
		{'O', 'X', 'O'},
		{' ', 'X', 'X'}
	};



	//	 chapter 4

	// Hangman (game)
	const int MAX_WRONG = 8;
	vector<string> words;
	words.push_back("УГАДАТЬ");
	words.push_back("ПАЛАЧ");
	words.push_back("ТРУДНЫЙ");
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());
	const string THE_WORD = words[0];
	int wrong = 0;
	string soFar(THE_WORD.size(), '-');
	string used = "";
	cout << "Welcom to Hangman. Good Luck!\n";

	while ((wrong < MAX_WRONG) && (soFar != THE_WORD)) {
		cout << "\n\nУ тебя осталось " << (MAX_WRONG - wrong);
		cout << " неверных догадок.\n";
		cout << "\nВы использовали следующие буквы:\n" << used << endl;
		cout << "\nПока что это слово звучит так:\n" << soFar << endl;
		char guess;
		cout << "\n\nВведите свое предположение: ";
		cin >> guess;
		guess = toupper(guess);

		while (used.find(guess) != string::npos) {
			cout << "\nВы уже вводили данныое предположение " << guess << endl;
			cout << "\n\nВведите свое предположение: ";
			cin >> guess;
			guess = toupper(guess);
		}
		used += guess;
		if (THE_WORD.find(guess) != string::npos) {
			cout << "Это верно! " << guess << " есть в слове.\n";
			for (int i = 0; i < THE_WORD.length(); ++i)
			{
				if (THE_WORD[i] == guess) {
					soFar[i] = guess;
				}
			}
		}
		else {
			cout << "Извините, " << guess << " нет в слове.\n";
			++wrong;
		}
	}

	if (wrong == MAX_WRONG) {
		cout << "\nТебя повесили!";
	}
	else {
		cout << "\nВы угадали слово!";
	}
	cout << "\nЭто слово было " << THE_WORD << endl;


	// 1
	vector<string> myGames;
	vector<string>::iterator iter;
	while (true)
	{
		cout << "\nВыберете действие:\n1. Добавить игру\n2. Удалить игру\n3. Посмотреть игры\n";
		int choice;
		cin >> choice;
		if (choice == 1) {
			string addGames;
			cout << "Введите название игры: ";
			getline(cin, addGames);
			getline(cin, addGames);
			myGames.push_back(addGames);
		}
		else if (choice == 2) {
			int i = 1;
			cout << "\nВаша библиотека: \n";
			for (iter = myGames.begin(); iter != myGames.end(); ++iter) {
				cout << i << " " << *iter << endl;
				++i;
			}
			cout << "\nВведите цифру игры, которую хотите удалить: ";
			int deleteGame;
			cin >> deleteGame;
			if (deleteGame == 1) {
				myGames.erase(myGames.begin());
			}
			else {
				myGames.erase((myGames.end() - deleteGame));
			}
		}
		else if (choice == 3) {
			int i = 1;
			cout << "\nВаша библиотека: \n";
			for (iter = myGames.begin(); iter != myGames.end(); ++iter) {
				cout << i << " " << *iter << endl;
				++i;
			}
		}
	}


	// 2
	vector<int> scores;
	scores.push_back(1);
	scores.push_back(2);
	vector<int>::iterator iter;
	for (iter = scores.begin(); iter != scores.end(); ++iter) {
		*iter+=1;
		cout << *iter << endl;
	}



	//	 chapter 5

	// 2
	const int MAX_WRONG = 8;
	vector<string> words;
	words.push_back("УГАДАТЬ");
	words.push_back("ПАЛАЧ");
	words.push_back("ТРУДНЫЙ");
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());
	const string THE_WORD = words[0];
	int wrong = 0;
	string soFar(THE_WORD.size(), '-');
	string used = "";
	cout << "Welcom to Hangman. Good Luck!\n";

	while ((wrong < MAX_WRONG) && (soFar != THE_WORD)) {
		cout << "\n\nУ тебя осталось " << (MAX_WRONG - wrong);
		cout << " неверных догадок.\n";
		cout << "\nВы использовали следующие буквы:\n" << used << endl;
		cout << "\nПока что это слово звучит так:\n" << soFar << endl;
		char guess = askLetter();

		while (used.find(guess) != string::npos) {
			cout << "\nВы уже вводили данныое предположение " << guess << endl;
			guess = askLetter();
		}
		used += guess;
		if (trueLetter(guess, THE_WORD)) {
			cout << "Это верно! " << guess << " есть в слове.\n";
			for (int i = 0; i < THE_WORD.length(); ++i)
			{
				if (THE_WORD[i] == guess) {
					soFar[i] = guess;
				}
			}
		}
		else {
			cout << "Извините, " << guess << " нет в слове.\n";
			++wrong;
		}
	}

	if (wrong == MAX_WRONG) {
		cout << "\nТебя повесили!";
	}
	else {
		cout << "\nВы угадали слово!";
	}
	cout << "\nЭто слово было " << THE_WORD << endl;

	// 3
	string number;
	cout << "Enter number: ";
	cin >> number;
	cout << numberAsk(number);

	int numb;
	string text;
	cout << "\nEnter number: ";
	cin >> number;
	cin >> text;
	cout << endl << num(text) << num(number);

	system("pause>nul");
	return 0;
}


//	 chapter 5

// 2
char askLetter() {
	char letter;
	cout << "\n\nВведите свое предположение: ";
	cin >> letter;
	letter = toupper(letter);
	return letter;
}

inline bool trueLetter(char letter, string THE_WORD) {
	if (THE_WORD.find(letter) != string::npos) {
		return true;
	}
	else {
		return false;
	}
}

// 3
string numberAsk(string num) {
	string text = "You're number: ";
	text += num;
	return text;
}

string num(string text) {
	string txt = text;
	txt += " ";
	return txt;
}
int num(int number) {
	return number;
}