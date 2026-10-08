//letter_count.hpp
#include <cctype>
#include <string>

constexpr int N_CHARS = 26;

int char_to_index(char n){
	if(n>='a' && n<='z'){
		return n - 'a';
	}
	return n - 'A';
}

char index_to_char(int i){
	return 'A'+i;
}

void count(std::string s, int counts[]){
	for(char c:s){
		if((c>='a'&&c<='z')||(c>='A'&&c<='Z')){
			int i = char_to_index(c);//which counter belongs to this letter?
			++counts[i]; //increment that counter by 1
		}
	}
}

void print_counts(int counts[], int len){
	for(int i=0; i<len; i++){
		std::cout<<index_to_char(i)<<' '<<counts[i]<<'\n';
	}
}


