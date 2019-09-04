#include "work.h"

CollectionWord::CollectionWord()
{

}

CollectionWord::~CollectionWord()
{
}

void CollectionWord::AddWords(wstring ua, wstring en)
{
	for (auto el : colection) {
		if (el.first == ua) {
			cout << "Word is already exist\n";
		}
		else {
			colection[ua] = en;
		}
	}

	
}

void CollectionWord::DeleteWord(wstring ua)
{
	for (auto el : colection) {
		if (el.first == ua) {
			colection.erase(ua);
		}
	}
}

void CollectionWord::ShowMap()
{
	for (auto el : colection) {
		wcout << el.first << ":::" << el.second << endl;
	}

}

wstring CollectionWord::getWordUa(wstring word)
{

	for (auto el : colection) {
		if (el.second == word) {
			return el.first;
		}
	}
}

wstring CollectionWord::getWordEn(wstring word)
{
	for (auto el : colection) {
		if (el.first == word) {
			return el.second;
		}
	}
}

map<wstring, wstring> CollectionWord::getMap() const
{
	return colection;
}

Translate::Translate(CollectionWord  w):words(w)
{
}

Translate::~Translate()
{
	
}

wstring Translate::EnToUa(wstring en)
{
	return words.getWordEn(en);
}

wstring Translate::UaToEn(wstring ua)
{
	return words.getWordUa(ua);
}

void Translate::setLib(CollectionWord lib)
{
	words = lib;
}

CollectionWord FileWork::Load()
{
	CollectionWord temp;
	wifstream in("base.db");
	in.imbue(locale(in.getloc(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));
	wstring first;
	wstring second;
	if (in.is_open()) {
		while (!in.eof()) {
			in >> first;
			in >> second;
			temp.AddWords(first, second);
		}
	}
	else {
		cout << "Error\n";
	}
	in.close();
	return temp;
}

void FileWork::Write( CollectionWord  lib)
{
	wofstream out("base.db");
	out.imbue(locale(out.getloc(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));
	if (out.is_open()) {
		
		for (auto el :lib.getMap() ) {
			out << el.first<<" "<<el.second;
		}
	}
	out.close();
}

FacadeFileBase::FacadeFileBase(FileWork * filesystem, Translate * translate, CollectionWord  words):filesystem(filesystem),translate(translate),words(words)
{
	this->words=this->filesystem->Load();

}

FacadeFileBase::~FacadeFileBase()
{
	WriteToBase();
	delete filesystem;
	delete translate;
	

}

void FacadeFileBase::AddNewWord(wstring ua, wstring en)
{
	words.ShowMap();
	
	words.AddWords(ua, en);
	
}

void FacadeFileBase::DeleteWord(wstring word)
{
	words.DeleteWord(word);
}

void FacadeFileBase::WriteToBase()
{
	filesystem->Write(words);
}

void FacadeFileBase::TranslateUAtoEN(wstring ua)
{
	wstring temp;
	temp=translate->UaToEn(ua);
	wcout << temp;
	cout << endl;
}

void FacadeFileBase::TranslateEntoUA(wstring en)
{
	wstring temp;
	temp = translate->EnToUa(en);
	wcout << temp;
	cout << endl;
}
