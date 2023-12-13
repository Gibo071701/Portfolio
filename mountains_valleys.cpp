#include <iostream>
#include "functions.h"
#include "functions.cpp"

using std::cout, std::cin, std::endl;
 
int a, b;

int main() {
	// Main function the calls supporting functions while waiting on inputs

	do {
		cout << "Enter numbers 10 <= a <= b < 10000: ";
		cin >> a >> b;
		if(is_valid_range(a, b)){
			count_valid_mv_numbers(a, b);
			break;
		}else{
		cout << "Invalid Input" << endl;
		} 
	}while (a && b);

	
	return 0;
}