#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;

//Переводим все слова в нижний регистр
string str_tolower(string s)
{
	for (int i = 0; i < s.length(); i++)
		s[i] = tolower(s[i]);
	return s;
}

set<string> set_word(string s) //Строка в слова
{
	set<string> set_s;
	if (!s.empty() && s.back() != ' ')
		s += " "; //Если строка не пустая и последний символ не пробел, добавляем пробел в конец строки
	while (!s.empty()) {
		set_s.insert(str_tolower(s.substr(0, s.find(' ')))); 
		s.erase(0, s.find(' ') + 1);
	}
	return set_s;
}

int main()
{
	string s;
	getline(cin, s);
	set<string> res, pov, voskl, vopr, s0;

	size_t pos = 0;
	while (pos != string::npos) {
		size_t next_pos = s.find_first_of(".!?", pos); //Ищем позицию знака препинания
		string pr;
		if (next_pos != string::npos) { 
			pr = s.substr(pos, next_pos - pos); //Получаем подстроку между текущей и след. позициями знака препинания
			pos = next_pos + 1; // Обновление позиции для следующей итерации
		}
		else {
			pr = s.substr(pos); // Если больше нет знаков препинания, выделяем остаток строки
			pos = next_pos; // Устанавливаем позицию на конец строки, чтобы выйти из цикла
		}
		s0 = set_word(pr); //Получаем все множество из подстроки
		pov.insert(s0.begin(), s0.end()); //Добавляем в множество повест.

		if (next_pos != string::npos) {
			if (s[next_pos] == '!') {
				voskl.insert(s0.begin(), s0.end()); // Добавление слов в множество восклицательных предложений
			}
			else if (s[next_pos] == '?') {
				vopr.insert(s0.begin(), s0.end()); // Добавление слов в множество вопросительных предложений
			}
		}
	}

	for (const string& word : pov) {
		if (voskl.count(word) && vopr.count(word)) {
			res.insert(word); //Находим пересечения
		}
	}

	for (const string& word : res)
		cout << word << " ";
}
