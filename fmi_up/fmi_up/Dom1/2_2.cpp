//2_2.cpp
#include <iostream>
#include <cctype>
#include <cmath>
using namespace std;


bool isPrime(int num);
void zad2();
void main(){
    zad2();
}
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
            double num_d = (double)(num);
            int upperLimit = (int)(sqrt(num_d) + 1);

            while (divisor <= upperLimit)
            {
                if (num % divisor == 0)
                    isPrime = false;
                divisor += 2;
            }
            return isPrime;
        }
    }