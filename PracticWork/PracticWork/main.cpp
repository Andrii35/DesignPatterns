#include"work.h"

int main() {
	setlocale(LC_ALL, "ru");
	CollectionWord w;
	Translate*tr = new Translate(w);
	FileWork*fw = new FileWork();
	FacadeFileBase file(fw, tr, w);
	int choise = 100;
	while (choise != 0) {
		cout << "1. Add new Word\n";
		cout << "2. Delete word\n";
		cout << "3. Write  to data base\n";
		cout << "4. Translate ua to en\n";
		cout << "5. Translate en to ua\n";
		cout << "0. Exit\n";
		cin >> choise;
		switch (choise) {
		case 1:
		{
			wstring ua;
			wstring en;
			cout << "Enter a word\n";
			wcin >> ua;
			cout << "Enter translation\n";
			wcin >> en;
			file.AddNewWord(ua, en);
			
			break;
		}
		case 2: {
			wstring word;
			cout << "Enter a word, witch must be deleted\n";
			wcin >> word;
			file.DeleteWord(word);
			break;
		}
		case 3: {
			file.WriteToBase();
			break;
		}
		case 4: {
			wstring word;
			cout << "Enter a word in ua\n";
			wcin >> word;
			file.TranslateUAtoEN(word);
			break;
		}
		case 5: {
			wstring word;
			cout << "Enter a word in en\n";
			wcin >> word;
			file.TranslateEntoUA(word);
			break;
		}
		}
	}

	system("pause");

}