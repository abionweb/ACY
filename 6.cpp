#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;


int main(void){
	
	char str[256];
	cout << "Введите строку: ";
	gets(str); // считать строку из стандартного потока ввода
	int len = strlen(str);
	cout << "Длина строки: " << len << endl;
	char *word = new char, *min = new char, *max = new char;
	*(max) = '\0';
	for(int j = 0; j < len+1; j++) *(min+j) = 'a';
	*(min+len+1) = '\0';
	
	cout << "strlen(min): " << strlen(min) << "  strlen(max): " << strlen(max) << endl;
	cout << endl;
	
		for(int i = 0; i < len; i++) {
			int wordlen = strlen(word);
			switch (str[i]) {
				case ' ':
					if ((str[i+1] == ' ') or (str[i+1] == '.')) break;
				case '.':
					//Слово закончилось - сравниваем его с min и max
					cout << "Вижу слово '" << word << "'" << endl;
					cout << "wordlen: " << wordlen << "   strlen(min): " << strlen(min) << "   strlen(max): " << strlen(max) << endl;
					if (wordlen < strlen(min)) {
						for(int j = 0; j < wordlen; j++) *(min + j) = *(word + j);
						*(min + wordlen) = '\0';
						cout << "'" << word << "' - новое самое короткое слово" << endl;
					}
					if (wordlen > strlen(max)) {
						for(int j = 0; j < wordlen; j++) *(max + j) = *(word + j);
						*(max + wordlen) = '\0';
						cout << "'" << word << "' - новое самое длинное слово" << endl;
					}
					*(word) = '\0';
				break;
				default:
					*(word+wordlen) = str[i];
					*(word+wordlen+1) = '\0';
				break;
			}
		}
	cout << endl << "Самое короткое слово: " << min << endl << "Самое длинное слово: "  << max << endl << endl << endl;
	return 0;
}
