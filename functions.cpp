#include <iostream>
#include "functions.h"

using std::cout, std::endl;

//Some comments were code used to debug.

bool is_valid_range(int a, int b) {
	//Checking if the range between a and be are valid.
	if(a >= 10 && b < 10000 && a <= b){
		return true;
	} else{
		return false;
	}
}

int numLength = 0;

char classify_mv_range_type(int number) {
    //peels 'number' to compare each digit stored in temporary variables to see what is greater, lesser, or the same.
    
    //cout << "Your input: " << number << endl;//
    char rangeType = 'N';
    numLength = -1;
    int totalDivider = 1;
    for(int i = number; i > 0; i /= 10){
        numLength += 1;
    }
    if(numLength != 0) {
        for (int i = 1; i <= numLength; i++){
            totalDivider *= 10;    
        }
    //cout << "NumLength: " << numLength +1  << endl;//
    }
    int tempL = number;
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