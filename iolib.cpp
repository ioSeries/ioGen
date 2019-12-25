#include "iolib.h"

#include <cctype>

ioGen::ioGenerator::ioGenerator(unsigned int __minLen, unsigned int __maxLen, std::string ioCharOptionSet)
:
 minLen{__minLen},
 maxLen{__maxLen},
 
 ioCombinationAddr{nullptr},
 ioBuffer__i{nullptr},
 ioBuffer__ii{nullptr},
 
 isCharGenerator{true},
 ioBufferSwitch{false}
 
 {
	
	//we generate the chars needed from the ioCharOptionSet and store append them to ioCharSet
	unsigned int __ioCharExpectedSize__{0}; //holds the expected size of ioCharSet. must coinside to ioCharSet.size()
	
	for(char tmpChar: ioCharOptionSet){
		
		switch(std::tolower(tmpChar)){
			case 'l': for(unsigned int i = 97; i < 97 + 26; i++){this->ioCharSet.push_back(i);} __ioCharExpectedSize__ += 26; break;
			case 'u': for(unsigned int i = 65; i < 65 + 26; i++){this->ioCharSet.push_back(i);} __ioCharExpectedSize__ += 26; break;
			case 'n': for(unsigned int i = 48; i < 48 + 10; i++){this->ioCharSet.push_back(i);} __ioCharExpectedSize__ += 10; break;
			default: break;
		}
		
	}
	
	//ioCharSet by here must be populated with the right characters
	
	//now we have to test for ioCharSet.size() which must coincide to the value of __ioCharExpectedSize__
	
	if(static_cast<unsigned int> (this->ioCharSet.size()) == static_cast<unsigned int>(__ioCharExpectedSize__)){
		
	}else{
		std::cout << "this is displayed just for testing purposes" << std::endl;
	}
	
	//
	for(char tmpChar: this->ioCharSet){
		std::cout << tmpChar << std::endl;
	}
	std::cout << __ioCharExpectedSize__ << " is the expected size of ioCharSet " << std::endl;
	std::cout << this->ioCharSet.size() << " is the actual size of ioCharSet" << std::endl;
 
 }

ioGen::ioGenerator::ioGenerator(unsigned int __minLen, unsigned int __maxLen, std::vector <char> __ioCharSet)
:minLen{__minLen},
 maxLen{__maxLen},
 
 ioCombinationAddr{nullptr},
 ioBuffer__i{nullptr},
 ioBuffer__ii{nullptr},
 
 isCharGenerator{true},
 ioBufferSwitch{false}
 
 {}

ioGen::ioGenerator::ioGenerator(unsigned int __minLen, unsigned int __maxLen, std::vector <std::string> __ioStringSet)
:minLen{__minLen},
 maxLen{__maxLen},
 
 ioCombinationAddr{nullptr},
 ioBuffer__i{nullptr},
 ioBuffer__ii{nullptr},
 
 isCharGenerator{false},
 ioBufferSwitch{false}

{}

