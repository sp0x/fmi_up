#include <iostream>
#include <cctype>
#include <cmath>
#include <stack>

using namespace std;
bool isPrime (int num);
template <typename TStackType>
int* toArray(stack<TStackType> stk, int & size);
char * toBinary(int num);
class Op2{
public:
	void zad1(){
		char c;
		cin >> c;
		string result;
		if (isdigit(c)){
			result = "number";
		}
		else{
			result = isupper(c) ? "Upper-case letter" : "Lower-case letter";
		}
		cout << result.c_str();
	}


	/**
	* Check if input was a isPrime number
	*/
	void zad2(){
		int number;
		cin >> number;
		cout << isPrime(number) ? "prime" : "not prime";
	}
	bool isPrime(int num)
	{
		if (num <= 1)
			return false;
		else if (num == 2)
			return true;
		else if (num % 2 == 0)
			return false;
		else
		{
			bool isPrime = true;
			int divisor = 3;
			double num_d = static_cast<double>(num);
			int upperLimit = static_cast<int>(sqrt(num_d) + 1);

			while (divisor <= upperLimit)
			{
				if (num % divisor == 0)
					isPrime = false;
				divisor += 2;
			}
			return isPrime;
		}
	}



	stack<int> zad3(int number){
		if (number == 0) number = 1234;
		std::stack<int> stk;
		std::stack<int> stkCopy;
		do{
			int rem = number % 10;
			number = number / 10;
			stk.push(rem);
		} while (number > 1);
		stkCopy = stk;
		while (stk.size() > 0){
			cout << (int)stk.top() << "\n"; stk.pop();
		}
		return stkCopy;
	}

	void zad4(){
		cout << "1-  One digit number\n";
		cout << "2-  Two digits numbers\n";
		cout << "3-  Three digits number\n";
		cout << "4-  Four digits number\n";
		cout << "5-  Five digits number\n";
		int numDigits; cin >> numDigits;
		cout << "Enter your number: ";
		int num; cin >> num;
		zad3(num);
	}
	/**
	* Checks for palindroms
	**/
	void zad5(){
		int palindrom; cin >> palindrom;
		int sz = 0;
		int * pNums = toArray<int>(zad3(palindrom), sz);
		bool isInvalid = false;
		if (sz % 2 != 0){
			cout << "Not a palindrome\n"; return;
		}
		for (int i = 0; i<sz; i++){
			if (pNums[i] != pNums[sz - i]){
				isInvalid = true;
			}
		}
		cout << palindrom << " Is " << (isInvalid ? "not" : "a") << " palindrome!";
	}

	void zad6(){
		int num; cin >> num;
		cout << toBinary(num);
	}


	void zad7(){
		cout << "Number of contendors: ";
		int nContendors; cin >> nContendors;


	}

	void zad8(){
		int n; cout << "Enter N: "; cin >> n;
		int tmpI = 0;
		char c; cout << "Enter triangle char: "; cin >> c;
		for (int i = 0; i < n; i++) cout << c << " ";
		for (int i = n - 1; i>0; i--){
			for (int j = 0; j < n; j++){
				cout << ((j == (i + 1) || j == ((n * 2 - 1) - i)) ? c : ' ');
				//       + + + + +    
				//        +     +
				//         +   +
				//          + +
				//           +
			}
		}
	}

	char * toBinary(int num){
		char buff[8];
		if (num>256){
			cout << "NOT IMPLEMENTED";
		}
		else{
			for (int i = 7; i > -1; i--){
				buff[i] = num % (int)pow(2, i) == 0;
				num = num / pow(2, i);
			}
		}
		return buff;
	}

	template <typename TStackType>
	int* toArray(stack<TStackType> stk, int & size){
		size = stk.size();
		int * ret = new int[size];
		int pos = 0;
		while (stk.size() > 0){
			ret[pos++] = stk.top(); stk.pop();
		}
		return ret;
	}
};
