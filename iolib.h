#include <iostream>
#include <string>
#include <vector>

namespace ioGen{
	
	
	class ioGenerator{
	private:
		
		//fisrt class bank 
		//refresher on first class banks(this are variables whose data is set to precisely known values by myself)
		
		//second class banks
		std::vector <char> lowerCaseCharSet; // lowercase letters only
		std::vector <char> upperCaseCharSet; // uppercase letters only
		std::vector <char> numericalCharSet; // numbers from 0- 9  only
		
		std::vector <char> specialCharSet;
		
		std::vector <unsigned int> ioCombination;
		
		//third class banks []
		
		std::vector <std::string> ioStringSet;
		
		std::vector <char> ioCharSet;
		
		
		//first class utility data     ^#
		 
		unsigned int minLen; //user defined minimum length
		unsigned int maxLen; //user defined maximum length
		
		//second class utility data ^#
		unsigned int ioBase; //number base. it's the size of the vector for input set
		
		//first class references @#
		
		std::vector <unsigned int> *ioCombinationAddr;
		
		std::vector <std::string> *ioBuffer__i;
		std::vector <std::string> *ioBuffer__ii;
		
		//second class references @#
		std::vector <std::string> *readingBuffer;
		std::vector <std::string> *writingBuffer;
		
		//first class switch
		bool isCharGenerator;
		
		bool ioBufferSwitch;
		
		//second class switch 
		bool ioBuffer__iRefreshed;
		bool ioBuffer__iiRefreshed;
		
		//first class functions
		
		bool ioGenerate(); //okay
		
		bool isIoGeneratable(); //okay
		
		
		//second class functions
		
		bool setInitialGenState(std::vector<unsigned int> __tmpGenState);
		
		
	public:
		ioGenerator(unsigned int __minLen, unsigned int __maxLen, std::string ioCharOptionSet); // the ioCharSet needs to be initialized with data from ioCharOptionSet
		ioGenerator(unsigned int __minLen, unsigned int __maxLen, std::vector <char> __ioCharSet); 
		ioGenerator(unsigned int __minLen, unsigned int __maxLen, std::vector <std::string> __ioStringSet);
	};
	
}