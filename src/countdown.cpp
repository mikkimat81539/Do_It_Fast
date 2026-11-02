#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int main(){
	// Store the number seconds
	int seconds = 100;

	// loop to coundown each seconds
	while(seconds > 0){
		cout << "Seconds: " + to_string(seconds) << endl; // out seconds	

		clock_t stop = clock() + CLOCKS_PER_SEC;
		while(clock() < stop){}
	
		seconds--;
	}

	return 0;
}
