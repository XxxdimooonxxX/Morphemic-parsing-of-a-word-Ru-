// Morfem_Razbor_ver12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

// morfe_rasbor_ver11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

string suff(string vvod, string sr1, string prob) {
	string sr2, suffi = " ",
		suf[34] = { "к", "ик", "ек", "ок", "ин", "ёк", "еньк", "оньк", "ечк", "очк", "ушк", "юшк",
					"ышк", "ник", "чик", "щик", "тель", "ниц", "ист", "ск", "ов", "ев",
					"н", "и", "е", "ова", "ева", "ть", "ти", "чь", "л", "ся", "сь", "чиц" };

	for (int i = 0; i < 34; i++) {
		sr2 = suf[i];
		if (sr2.length() == 4) {
			if (vvod[vvod.length() - sr1.length() - 2] == sr2[sr2.length() - 1]
				&& vvod[vvod.length() - sr1.length() - 3] == sr2[sr2.length() - 2]
				&& vvod[vvod.length() - sr1.length() - 4] == sr2[sr2.length() - 3]
				&& vvod[vvod.length() - sr1.length() - 5] == sr2[sr2.length() - 4]) {
				return vvod.insert(vvod.length() - sr1.length() - sr2.length() - 1, prob);
				suffi = sr2;
			}
		}
		else if (sr2.length() == 3) {
			if (vvod[vvod.length() - sr1.length() - 2] == sr2[sr2.length() - 1]
				&& vvod[vvod.length() - sr1.length() - 3] == sr2[sr2.length() - 2]
				&& vvod[vvod.length() - sr1.length() - 4] == sr2[sr2.length() - 3]) {
				return vvod.insert(vvod.length() - sr1.length() - sr2.length() - 1, prob);
				suffi = sr2;
			}
		}
		else if (sr2.length() == 2) {
			if (vvod[vvod.length() - sr1.length() - 2] == sr2[sr2.length() - 1]
				&& vvod[vvod.length() - sr1.length() - 3] == sr2[sr2.length() - 2]) {
				return vvod.insert(vvod.length() - sr1.length() - sr2.length() - 1, prob);
				suffi = sr2;
			}
		}
		else if (sr2.length() == 1) {
			if (vvod[vvod.length() - sr1.length() - 2] == sr2[sr2.length() - 1]) {
				return vvod.insert(vvod.length() - sr1.length() - sr2.length() - 1, prob);
				suffi = sr2;
			}
		}
	}

	for (int i = 0; i < 34; i++) {
		if (suffi == suf[i]) {
			break;
		}
		else {
			return vvod;
		}
	}

}

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int ch1, ch2;

	string vvod, sr, sr1, sr2, prob, prist, koren, suffi, oko,
		pris[52] = { "без", "бес", "в", "во", "воз", "вос", "возо", "вз", "вс", "вы", "до",
					"за", "из", "ис", "изо", "на", "наи", "недо", "над", "надо", "не", "низ",
					"нис", "низо", "о", "об", "обо", "обез", "обес", "от", "ото", "па",
					"пра", "по", "под", "подо", "пере", "пред", "пре", "предо", "при", "про",
					"раз", "рас", "разо", "с", "со", "су", "через", "черес", "чрез", "у" },
		suf[34] = { "к", "ик", "ек", "ок", "ин", "ёк", "еньк", "оньк", "ечк", "очк", "ушк", "юшк",
					"ышк", "ник", "чик", "щик", "тель", "ниц", "ист", "ск", "ов", "ев",
					"н", "и", "е", "ова", "ева", "ть", "ти", "чь", "л", "ся", "сь", "чиц" },
		okon[92] = { "а", "я", "о", "е", "ь", "ы", "и", "ая", "яя", "ое", "ее", "ой", "ые",
					"ие", "ый", "йй", "ать", "ять", "оть", "еть", "уть", "у", "ю", "ем", "им",
					"ешь", "ишь", "ете", "ите", "ет", "ит", "ут", "ют", "ят", "ал", "ял", "ала",
					"яла", "али", "яли", "ол", "ел", "ола", "ела", "оли", "ели", "ул", "ула", "ули",
					"ам", "ами", "ас", "ax", "ая", "её", "ей", "ем", "еми", "емя",
					"ex", "ею", "ёт", "ёте", "ёх", "ёшь", "и", "ий", "им", "ими", "ит", "ите",
					"их", "ишь", "ию", "м", "ми", "мя", "ов", "ого", "ое", "оё", "ой", "ом", "ому",
					"ою", "у", "ум", "умя", "ут", "ух", "ую", "шь" };
	oko = "     ";
	koren = "          ";
	suffi = "     ";
	prob = char(95);
	cout << "******************************************************************************************************************";
	cout << "\n*------------------------------------------------Ограничения:----------------------------------------------------*";
	cout << "\n*1. Слово должно состоять не меньше 5 символов.                                                                  *";
	cout << "\n*2. Вводите слово с маленькой буквы.                                                                             *";
	cout << "\n*3. В слове должно быть одна - приставка, корень, и если есть суффмкс и(или) окончание, то тоже должно быть одно.*";
	cout << "\n******************************************************************************************************************\n";
	cout << "Введите слово: "; getline(cin, vvod);

	for (int i = 0; i < 52; i++) {//Проверка на приставку
		sr = pris[i];//временная переменная которая принимает приставку и она будет менятся с каждой итерацией
		if (sr.length() == 1) {//если приставка = 1 символу идет проверка на 1 символ, дальше также на 2 символа и т.д.
			for (int j = 0; j < sr.length(); j++) {//это я не знаю ка кэто работает но она проверяет две приставки так что не трогать
				if (vvod[j] == sr[j]) {//если первый символ vvod равен первому символу приставки sr
					vvod.insert(j + 1, prob);
					prist = sr;//присваиваем эту приставку если она будет в слове
				}
			}
		}
		else if (sr.length() == 2) {
			for (int j = 0; j < sr.length(); j++) {
				if (vvod[j] == sr[j] && vvod[j + 1] == sr[j + 1]) {
					vvod.insert(j + 2, prob);
					prist = sr;
				}
			}
		}
		else if (sr.length() == 3) {
			for (int j = 0; j < sr.length(); j++) {
				if (vvod[j] == sr[j] && vvod[j + 1] == sr[j + 1] && vvod[j + 2] == sr[j + 2]) {
					vvod.insert(j + 3, prob);
					prist = sr;
				}
			}
		}
		else if (sr.length() == 4) {
			for (int j = 0; j < sr.length(); j++) {
				if (vvod[j] == sr[j] && vvod[j + 1] == sr[j + 1] && vvod[j + 2] == sr[j + 2] && vvod[j + 3] == sr[j + 3]) {
					vvod.insert(j + 4, prob);
					prist = sr;
				}
			}
		}
		else if (sr.length() == 5) {
			for (int j = 0; j < sr.length(); j++) {
				if (vvod[j] == sr[j] && vvod[j + 1] == sr[j + 1] && vvod[j + 2] == sr[j + 2] && vvod[j + 3] == sr[j + 3] && vvod[j + 4] == sr[j + 4]) {
					vvod.insert(j + 5, prob);
					prist = sr;
				}
			}
		}
	}

	for (int i = 0; i < 92; i++) {//проверка на окончание
		sr1 = okon[i];//объеснение такое же как и с приставокой
		if (sr1.length() == 1) {//также как и с приставкой проверяет количество
			if (vvod[vvod.length() - 1] == sr1[sr1.length() - 1]) {//проверяет на конецу слова окончание с данным количеством символов
				vvod.insert(vvod.length() - sr1.length(), prob);
				vvod = suff(vvod, sr1, prob);//Это вызов функции которая проверяет наличие суффикса
				oko = sr1;//также как и с приставкой
			}
		}
		else if (sr1.length() == 2) {
			if (vvod[vvod.length() - 1] == sr1[sr1.length() - 1] 
				&& vvod[vvod.length() - 2] == sr1[sr1.length() - 2]) {
				vvod.insert(vvod.length() - sr1.length(), prob);
				vvod = suff(vvod, sr1, prob);
				oko = sr1;
			}
		}
		else if (sr1.length() == 3) {
			if (vvod[vvod.length() - 1] == sr1[sr1.length() - 1] 
				&& vvod[vvod.length() - 2] == sr1[sr1.length() - 2] 
				&& vvod[vvod.length() - 3] == sr1[sr1.length() - 3]) {
				vvod.insert(vvod.length() - sr1.length(), prob);
				vvod = suff(vvod, sr1, prob);
				oko = sr1;

			}
		}
	}
	//цикл ниже проверки есть ли у слова окончание
	for (int y = 0; y < 92; y++) {
		if (oko == okon[y]) {
			break;
		}
		else {
			for (int i = 0; i < 34; i++) {//проверка на суффикс если не окончания, p.s. через вызов функции не работает(не знаю почему)
				sr2 = suf[i];
				if (sr2.length() == 4) {
					if (vvod[vvod.length() - sr1.length() - 2] == sr2[sr2.length() - 1]
						&& vvod[vvod.length() - sr1.length() - 3] == sr2[sr2.length() - 2]
						&& vvod[vvod.length() - sr1.length() - 4] == sr2[sr2.length() - 3]
						&& vvod[vvod.length() - sr1.length() - 5] == sr2[sr2.length() - 4]) {
						vvod.insert(vvod.length() - sr2.length() - 1, prob);
					}
				}
				else if (sr2.length() == 3) {
					if (vvod[vvod.length() - sr1.length() - 2] == sr2[sr2.length() - 1]
						&& vvod[vvod.length() - sr1.length() - 3] == sr2[sr2.length() - 2]
						&& vvod[vvod.length() - sr1.length() - 4] == sr2[sr2.length() - 3]) {
						vvod.insert(vvod.length() - sr2.length() - 1, prob);
					}
				}
				else if (sr2.length() == 2) {
					if (vvod[vvod.length() - sr1.length() - 2] == sr2[sr2.length() - 1]
						&& vvod[vvod.length() - sr1.length() - 3] == sr2[sr2.length() - 2]) {
						vvod.insert(vvod.length() - sr2.length() - 1, prob);
					}
				}
				else if (sr2.length() == 1) {
					if (vvod[vvod.length() - sr1.length() - 2] == sr2[sr2.length() - 1]) {
						vvod.insert(vvod.length() - sr2.length() - 1, prob);
					}
				}
			}
		}
	}
	
	for (int i = 0; i < vvod.length(); i++) {//выделение корня для вывода его отдельно
		if (vvod[i] == char(95)) {//начальное значение для выделения корня
			ch1 = i;
			for (int j = ch1 + 1; j < vvod.length() - oko.length() - 1; j++) {
				if (vvod[j] == char(95)) {//конечное значение для выделения корня
					ch2 = j;
					for (int k = 0; k < (ch2 - ch1); k++) {//цикл для вставки корня в отдельную переменную для вывода её отдельно
						koren[k] = vvod[ch1 + k];
					}
				}
			}
		}
	}

	for (int i = prist.length() + 1; i < vvod.length(); i++) {//выделение суффикса для вывода его отдельно
		if (vvod[i] == char(95)) {//тут такоже объяснение, как и с корнем
			ch1 = i;
			for (int j = ch1 + 1; j < vvod.length(); j++) {
				if (vvod[j] == char(95)) {
					ch2 = j;
					for (int k = 0; k < (ch2 - ch1); k++) {
						suffi[k] = vvod[ch1 + k];
					}
				}
			}
		}
	}

	for (int i = 0; i < koren.length(); i++) {//удаляет лишнии пробелы в этой переменной
		if (koren[i] == char(32)) {
			koren.erase(i, 1);
		}
		else if (koren[i] == char(95)) {
			koren.erase(i, 1);
		}
	}

	for (int i = 0; i < suffi.length(); i++) {//удаляет лишнии пробелы в этой переменной
		if (suffi[i] == char(32)) {
			suffi.erase(i, 1);
		}
		else if (suffi[i] == char(95)) {
			suffi.erase(i, 1);
		}
	}

	for (int i = 0; i < oko.length(); i++) {//удаляет лишнии пробелы в этой переменной
		if (oko[i] == char(32)) {
			oko.erase(i, 1);
		}
	}


	cout << "Морфемный разбор - " << vvod << endl;
	cout << "Приставка - " << prist << endl;
	cout << "Корень - " << koren << endl;
	cout << "Суффикс - " << suffi << endl;
	cout << "Окончание - " << oko << endl;

}
