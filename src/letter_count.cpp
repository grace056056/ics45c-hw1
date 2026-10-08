#include <iostream>

#include<string>

#include "letter_count.hpp"

using namespace std;

int main(){
	int counts[N_CHARS]={};
	string line;
	while (getline(cin, line)) {
        count(line, counts);
    }
    print_counts(counts, N_CHARS);
    return 0;
}
