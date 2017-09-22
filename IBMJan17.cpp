#include <algorithms>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> generate_denominators(max_factors = 13){
	int denominator = 1, number_of_twos, number_of_fives;
	vector<int> denominators;
	for (int number_of_factors = 1; number_of_factors < max_factors; number_of_factors++){
		number_of_twos = number_of_factors;
		number_of_fives = 0;
		for (int j = 0; j < number_of_factors + 1; j++){
			for (int i = 0; i < number_of_twos; i++){
				denominator *= 2;
			}
			for (int i = 0; i < number_of_fives; i++){
				denominator *= 5;
			}
			denominators.push_back(denominator);
			number_of_twos--;
			number_of_fives++;
			denominator = 1;
		}
		denominator = 1;
	}
	sort (denominators.begin(),denominators.end());
	return denominators;
}

vector<int> test_denominators(){

}

int main(){
    cout denominators[denominators.size()];
}
