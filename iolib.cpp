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
		//now let's prepare ioCombination for for incrementation
		for (unsigned int counter{0}; counter < this->minLen; counter++){
			this->ioCombination.push_back(0);
		}
		std::cout << "the sizes are coherent" << std::endl;
		
		if(this->isGeneratable()){
			std::cout << "this instace of ioGenerator is generatable" << std::endl;
		}else{
			std::cout << "this guy is not generatable" << std::endl;
		}
		
	}else{
		std::cout << "this is displayed just for testing purposes" << std::endl;
	}
 }

ioGen::ioGenerator::ioGenerator(unsigned int __minLen, unsigned int __maxLen, std::vector <char> __ioCharSet)
:minLen{__minLen},
 maxLen{__maxLen},
 
 ioCombinationAddr{nullptr},
 ioBuffer__i{nullptr},
 ioBuffer__ii{nullptr},
 
 isCharGenerator{true},
 ioBufferSwitch{false}
 
 {
	
	this->ioCharSet = std::vector<char>{__ioCharSet};
	
	unsigned int __ioCharExpectedSize__{static_cast<unsigned int> (__ioCharSet.size())};
	
	if(static_cast <unsigned int> (this->ioCharSet.size()) == static_cast <unsigned int> (__ioCharExpectedSize__)){
		//by here , ioCharSet must have been populated with the right data
		std::cout << "coherent sizes" << std::endl;
		
		if(this->isGeneratable()){
			std::cout << "this instace of ioGenerator is generatable" << std::endl;
		}else{
			std::cout << "this guy is not generatable" << std::endl;
		}
	}else{
		std::cout << "incoherrent ioCharSet sizes" << std::endl;
		std::cout << "this is a provoqued error" << std::endl; 	
	}
	
	
	
 }

ioGen::ioGenerator::ioGenerator(unsigned int __minLen, unsigned int __maxLen, std::vector <std::string> __ioStringSet)
:minLen{__minLen},
 maxLen{__maxLen},
 
 ioCombinationAddr{nullptr},
 ioBuffer__i{nullptr},
 ioBuffer__ii{nullptr},
 
 isCharGenerator{false},
 ioBufferSwitch{false}

 {
	
	this->ioStringSet = std::vector<std::string> {__ioStringSet};
	
	unsigned int __ioStringExpectedSize__{static_cast <unsigned int> (__ioStringSet.size())};
	
	if(static_cast <unsigned int> (this->ioStringSet.size()) == static_cast <unsigned int> (__ioStringExpectedSize__)){
		std::cout << "sizes corresponds" << std::endl;
		
		
		if(this->isGeneratable()){
			std::cout << "this instace of ioGenerator is generatable" << std::endl;
		}else{
			std::cout << "this guy is not generatable" << std::endl;
		}
		
		
	}else{
		std::cout << "incoherent size of ioStringSet" << std::endl;
	}
 }

bool ioGen::ioGenerator::ioGenerate(){
	
	bool tmpStatus{false};
	
	if (this->isIoGeneratable()){

        int cursor{static_cast<int>(this->ioCombination.size()) - 1};

		while (cursor >= 0){

			if (this->ioCombination.at(cursor) < (this->ioBase - 1)){ //if the digit at the cursor is incrementable

				this->ioCombination.at(cursor) += 1;
				tmpStatus = true;
				break;

			}else{

				//at this point no incrementation took place
				//but this->ioCombination is incrementable

				if(this->ioCombination.at(cursor) == (this->ioBase - 1)){
					this->ioCombination.at(cursor) = 0;

					cursor -= 1;

				}

			}

		}
	}else {
		if(this->ioCombination.size() < this->maxLen){
			this->ioCombination.insert(this->ioCombination.begin(), 1);
			for (unsigned int i = 0; i < static_cast<unsigned int>(this->ioCombination.size()); i++){
                this->ioCombination.at(i) = 0;
			}

			//this->ioIncrement();

		}else if(this->ioCombination.size() == this->maxLen) tmpStatus = false;
	}
	
	return tmpStatus;
	
}

bool ioGen::ioGenerator::isIoGeneratable(){
	bool tmpStatus {false};
	if(this->ioCombination != std::vector <unsigned int> (this->maxLen, ioBase - 1))tmpStatus = true;
	return tmpStatus;
}

