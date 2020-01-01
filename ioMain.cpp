#include "iolib.h"


int main(){
	ioGen::ioGenerator objExample{2, 3, std::string{"n"}};
	ioGen::ioGenerator objExample2{2, 4, std::vector<char>{'a','b','c','d'}};
	ioGen::ioGenerator objExample3{3, 4, std::vector<std::string>{"a","b","c","d"}};
	return 0;

}