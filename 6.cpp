#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;


int main(void){
	
	char str[256];
	cout << "Enter the string: ";
	gets(str);
	int len = strlen(str);
	cout << "The length of the line: " << len << endl;
	char *word = new char, *min = new char, *max = new char;
	*(max) = '\0';
	for(int j = 0; j < len+1; j++) *(min+j) = 'a';
	*(min+len+1) = '\0';
	
	cout << "strlen(min): " << strlen(min) << "  strlen(max): " << strlen(max) << endl;
	cout << endl;
	*(word) = '\0';
		for(int i = 0; i < len; i++) {
			int wordlen = strlen(word);
			switch (str[i]) {
				case ' ':
					if ((str[i+1] == ' ') or (str[i+1] == '.')) break;
				case '.':
					//Слово закончилось - сравниваем его с min и max
					cout << "I see the word '" << word << "'" << endl;
					cout << "wordlen: " << wordlen << "   strlen(min): " << strlen(min) << "   strlen(max): " << strlen(max) << endl;
					if (wordlen < strlen(min)) {
						for(int j = 0; j < wordlen; j++) *(min + j) = *(word + j);
						*(min + wordlen) = '\0';
						cout << "'" << word << "'- Newest short word" << endl;
					}
					if (wordlen > strlen(max)) {
						for(int j = 0; j < wordlen; j++) *(max + j) = *(word + j);
						*(max + wordlen) = '\0';
						cout << "'" << word << "'- New longest word" << endl;
					}
					*(word) = '\0';
				break;
				default:
					*(word+wordlen) = str[i];
					*(word+wordlen+1) = '\0';
				break;
			}
		}
	cout << endl << "The shortest word: " << min << endl << "The longest word: "  << max << endl << endl << endl;
	return 0;
}
