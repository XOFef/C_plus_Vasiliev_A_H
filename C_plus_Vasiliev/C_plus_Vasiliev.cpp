#include <iostream>
#include <cmath>
using namespace std;

// ГЛАВА 1

// Задание 10
double perevod(int km)
{
	int result;
	return km / 3.6;
}


// Задание 11
double perevod_1(int ms)
{
	int result;
	return ms * 3.6;
}

// Задание 12
double perevod_2(int a, int b)
{
	return a + b;
}



// ГЛАВА 2

// Задание 15
int Sum(int a) {
	int sum = 0;
	for (int i = 1; i <= a; i++) {
		if (a % i == 0)
			sum += i;
	}
	return sum;
}



int main()
{
	system("chcp 1251>nul");
	srand(time(0));

	// ГЛАВА 1


	// Задание 1
	int num = 1;
	while (num <= 10) {
		cout << num << endl;
		num++;
	}


	// Задание 2
	while (num < 10)
	{
		cout << num << endl;
		num += 2;
	}


	// Задание 3
	int num1, res;
	cout << "Введите число: ";
	cin >> num1;
	res = 4 * num1 + 3;
	cout << "\nРезультат: " << res;


	//Задание 4
	int res, cyc, num1 = 1, num2 = 1;
	cout << "Введите количество выводимых чисел: ";
	cin >> cyc;
	while (cyc > 0)
	{

		res = num1 + num2;
		cout << res << endl;
		num2++;
		cyc--;
		while (cyc > 0)
		{
			res = num1 + num2;
			cout << res << endl;
			num1 = num2;
			num2 = res;
			cyc--;
		}
	}


	//Задание 8
	float fathom;
	float meter = 2.16, result;
	cout << "Ведите количество саженей: ";
	cin >> fathom;
	result = fathom * meter;
	cout << "В " << fathom << " саженях " << result << " метров";


	//Задание 9
	float fathom, arshina, result,
		fathom_meter = 2.16,
		fathom_cm = fathom_meter * 100,
		arshina_meter = fathom_meter / 3,
		arshina_cm = fathom_meter / 3 * 100;
	int choise1, choise2;
	cout << "Выберите, какую величину хотите ввести:" << endl << "1. сажень" << endl << "2. аршина" << endl;
	cin >> choise1;
	while (choise1 < 1 or choise1 > 2)
	{
		cout << "Неверно введено число! Введите еще раз" << endl;
		cout << "Выберите, какую величину хотите ввести: " << endl << "1. сажень" << endl << "2. аршина" << endl;
		cin >> choise1;
	}

	cout << "Выберите величину в которую хотите перевести:" << endl << "1. метр" << endl << "2. сантиметр" << endl;
	cin >> choise2;
	while (choise2 < 1 or choise2 > 2)
	{
		cout << "Неверно введено число! Введите еще раз" << endl;
		cout << "Выберите величину в которую хотете перевести:" << endl << "1. метр" << endl << "2. сантиметр" << endl;
		cin >> choise2;
	}

	if (choise1 == 1 and choise2 == 1)
	{
		cout << "Введите количество саженей: ";
		cin >> fathom;
		result = fathom * fathom_meter;
		cout << "Результат: " << result;
	}
	else if (choise1 == 1 and choise2 == 2)
	{
		cout << "Введите количество саженей: ";
		cin >> fathom;
		result = fathom * fathom_cm;
		cout << "Результат: " << result;
	}
	else if (choise1 == 2 and choise2 == 1)
	{
		cout << "Введите количество аршин: ";
		cin >> arshina;
		result = arshina * arshina_meter;
		cout << "Результат: " << result;
	}
	else if (choise1 == 2 and choise2 == 2)
	{
		cout << "Введите количество аршин: ";
		cin >> arshina;
		result = arshina * arshina_cm;
		cout << "Результат: " << result;
	}

	// Задание 10
	int km;
	cout << "Введите вашу скорость: ";
	cin >> km;
	int result = perevod(km);
	cout << "При переводе " << km << " км/ч в м/с получается: " << result << " м/с";


	// Задание 11
	float ms;
	cout << "Введите вашу скорость: ";
	cin >> ms;
	float result = perevod_1(ms);
	cout << "При переводе " << ms << " м/с в км/ч получается: " << result << " км/ч";


	// Задание 12
	int num1, num2;
	cout << "Введите первую цифру: ";
	cin >> num1;
	cout << "Введите вторую цифру: ";
	cin >> num2;
	int result = perevod_2(num1, num2);
	cout << "Cумма двух цифр: " << result;


	// Задание 16
	int nums[5],
		result,
		step = 0;

	for (int i = 0; i < 6; i++)
	{
		cout << "Введите число " << i << ": ";
		cin >> nums[i];
		result = nums[i] * step;
		cout << result << endl;
		step += 1;
	}


	// Задание 17
	int nums[5],
		result,
		step = 0;

	for (int i = 0; i < 6; i++)
	{
		nums[i + 1] = 2;
		result = nums[i] * step;
		cout << result << endl;
		step += 1;
	}


	// Задание 18
	int mas[5];
	int res, cyc = 5, num1 = 1, num2 = 1;

	for (int i = 0; i < 5; i++)
	{

		res = num1 + num2;
		mas[i + 1] = res;
		cout << mas[i + 1] << endl;
		num2++;
		cyc--;

		for (int i = 0; i < 5; i++)
		{
			res = num1 + num2;
			num1 = num2;
			num2 = res;
			mas[i + 1] = res;
			cout << mas[i + 1] << endl;
			cyc--;
		}
	}


	// Задание 19
	int mas[11];
	int num = 0, res;

	for (int i = 0; i < 11; i++)
	{
		if (num % 2 == 0)
		{
			mas[i + 1] = num;
		}
		else
		{
			res = num * num;
			mas[i + 1] = res;
		}
		num += 1;
	}
	for (int i = 0; i < 11; i++)
	{
		cout << mas[i + 1] << endl;
	}


	// Задание 20
	int nums[5];

	for (int i = 0; i < 5; i++)
	{
		cout << "Введите число " << i << ": ";
		cin >> nums[i + 1];
		cout << nums[i + 1] << endl;
	}



	// ГЛАВА 2


	// Задание 4
	int a, b;
	cin >> a >> b;
	while (a > 0 && b > 0)
	{
		if (a > b) a = a % b;
		else b = b % a;
	}
	cout << a + b;




	// Задание 15

	int b;
	cin >> b;
	cout << Sum(b);







	// Задание 16
	int choose;
	string fib = "×èñëî Ôèáîíà÷è", nofib = "×èñëî íå ÿâëÿåòñÿ ÷èñëîì Ôèáîíà÷è";
	cin >> choose;
	switch (choose)
	{
	case 1:
	case 2:
	case 3:
	case 5:
	case 8:
		cout << fib;
		break;
	case 4:
	case 6:
	case 7:
	case 9:
	case 10:
		cout << nofib;
		break;
	default:
		cout << "Ââåäåíî íåâåðíîå ÷èñëî!";
		break;
	}


	// Задание 17
	srand(time(0));
	int arr[10];
	for (int& i : arr) {
		i = rand() % 100 + 1;
		cout << i << ' ';
	}
	for (int j = 0; j < 10 - 1; j++) {
		for (int i = 0; i < 10 - 1; i++) {
			if (arr[i] < arr[i + 1]) {
				int a = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = a;
			}
		}
	}
	for (int& i : arr) {
		cout << endl;
		cout << i << endl;
	}


	// Задание 18
	srand(time(0));
	const int size = 10;
	int A[size]{};

	for (size_t i = 0; i < size; i++)
	{
		A[i] = rand() % 101;
		cout << A[i] << " ";
	}
	cout << endl;
	for (size_t i = 0; i < size / 2; i++)
	{
		A[i] += A[size - i - 1];
		A[size - i - 1] = A[i] - A[size - i - 1];
		A[i] = A[i] - A[size - i - 1];
	}
	for (size_t i = 0; i < size; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;


	// ГЛАВА 3

	// 1
	const int SIZE = 5;
	int arrOne[SIZE] = { 1,2,3,4,5 };
	int arrTwo[SIZE] = { 1,2,3,4,5 };
	for (int i = 0; i < SIZE; i++)
	{
		cout << i + 1 << ". " << arrOne[i] + arrTwo[i] << endl;
	}

	// 2
	const int SIZE = 5;
	int arr[SIZE] = { 1,2,3,4,5 };
	int sum = 0;
	for (int i = 0; i < SIZE; i++)
	{
		sum += pow(arr[i], 2);
	}
	cout << sum;

	 3
	const int SIZE = 2;
	int arr[SIZE][SIZE] = {
		{2, 2},
		{2, 2}
	};
	int sum = 0;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++) {
			sum += pow(arr[i][j], 2);
		}
	}
	cout << sum;

	 4
	const int SIZE = 3;
	int matrix[SIZE][SIZE] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < SIZE; i++) {
		for (int j = i + 1; j < SIZE; j++) {
			swap(matrix[i][j], matrix[j][i]);
		}
	}
	cout << endl << endl;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	// 5
	const int SIZE = 3;
	int matrix[SIZE][SIZE];

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			matrix[i][j] = rand() % 10; 
		}
	}

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	int** newMatrix = new int* [SIZE];
	for (int i = 0; i < SIZE; i++) {
		newMatrix[i] = new int[SIZE];
	}
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			newMatrix[j][i] = matrix[i][j];
		}
	}

	cout << endl << endl;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << newMatrix[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < SIZE; i++) {
		delete[] newMatrix[i];
	}
	delete[] newMatrix;
	




	system("pause>nul");
	return 0;
}