/*
This is the main portion of functionality of Mountains and Valleys.

The purpose of this program
is to take a range of numbers that is given by the user between 10 and 10,000. The range is then
peeled to determine how many numbers in the range follow either a mountain or valley pattern.

A number that follows a mountain pattern is determined by the front most digit and if the following digit is greater than the front most. If that is true,
then the next digit must be less than the previous and so on. An example would be 3546 where 3<5>4<6. The digits then form a pattern of /\/\/\ where the first is less than the next.

A number that follows a valley is similar to the mountain pattern, only it checks if the next digit is less than the front most digit. An example of this would be 6453
where 6>4<5>3 and the pattern continues like \/\/.

Any numbers that do not follow either of these two patterns are not counted. Such examples are 3564, 3354, 3003 and so on.

Some comments are code that has been used to debug.
*/


//These reference the other header files necessary for this program to run
#include <iostream>
#include "functions.h"

//this program outpusts using the standard cout function
using std::cout, std::endl;

bool is_valid_range(int a, int b) {
	//Checks if the range given is between 10 and 10,000 thus making it valid, and if a is less than b
	if(a >= 10 && b < 10000 && a <= b){
		return true;
	} else{
		return false;
	}
}


int numLength = 0;

char classify_mv_range_type(int number) {
    //peels 'number' to compare each digit stored in temporary variables to see what is greater, lesser, or the same.
    
    //cout << "Your input: " << number << endl;

    //range type 'N' for none, 'V' for valley, and 'M' for mountain. Default is N
    char rangeType = 'N';

    //length if the number in digits
    numLength = -1;

    //The divisor used for peeling
    int totalDivider = 1;

    // this for-loop determines how many digits are in the number
    for(int i = number; i > 0; i /= 10){
        numLength += 1;
    }
    if(numLength != 0) {
        for (int i = 1; i <= numLength; i++){
            totalDivider *= 10;    
        }
    //cout << "NumLength: " << numLength +1  << endl;//
    }


    int tempL ;
    int temp ;
    int tempR ;
    int tempDivider = totalDivider;

    //cout << "Total Divider: " << totalDivider << endl; //

    while(tempDivider){

        tempL  = (number / tempDivider) % 10;
        tempDivider /= 10;
        temp  = (number / (tempDivider)) % 10;
        tempR  = ((number * 10) / (tempDivider) % 10);

        //cout << "Temp Divider: " << tempDivider << endl; //
        //cout << "Left (L): " << tempL   << " | Temp: " << temp  << "  | Right (R): " << tempR  << endl; //

        if(tempDivider < 10){
            if(tempL == temp ){
                //return 'N' if number has no pattern.
                rangeType = 'N';
                break;
            }else {
                if((number / totalDivider) > ((number / (totalDivider/10)) % 10)){
                    // return 'V' if number has \/\/ pattern.
                    rangeType = 'V';
                }else {
                    // return 'M' if number has /\/\ pattern.
                    rangeType = 'M';
                }
                break;
            }

        } else {
            if(tempL == temp  || (tempL   < temp  && temp  < tempR ) || (tempL   > temp  && temp  > tempR )){
                rangeType = 'N';
                break;
            }
        }
       
        /*
        if(tempDivider < 10){
            //int ones = number % 10;
            //cout << ones << endl;
            break;
        }
        */

    }
    
    //cout << numLength + 1 << " " << tempDivider << endl;//
    //cout << rangeType << endl;//

	return rangeType;
}

void count_valid_mv_numbers(int a, int b) {
	
    int mountains = 0;
    int valleys = 0;
    for(int i = a; i <= b; i++){
        //cout << i << endl;
        char rangeType = classify_mv_range_type(i);
        if (rangeType == 'M'){
            mountains++;
        }else if(rangeType == 'V'){
            valleys++;
        }
    }
    cout << "There are " << mountains << " mountain ranges and " << valleys << " valley ranges between " << a << " and " << b << "." << endl;
    //cout << mountains << " " << valleys << endl;
    //cout << "Number length: " << numLength << endl;
}