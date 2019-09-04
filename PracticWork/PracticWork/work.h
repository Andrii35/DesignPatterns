#pragma once
#include<iostream>
#include<string>
#include<map>
#include<fstream>
#include<codecvt>
#include<locale>
#include<Windows.h>


using namespace std;


class CollectionWord {
	
	map<wstring, wstring>colection;
public:
	CollectionWord();
	~CollectionWord();
	void AddWords(wstring ua, wstring en);
	void DeleteWord(wstring ua);
	void ShowMap();
	wstring getWordUa(wstring word);
	wstring getWordEn(wstring word);
	map<wstring, wstring> getMap()const;

};

class Translate {
	CollectionWord words;
public:
	Translate(CollectionWord w);
	~Translate();
	wstring EnToUa(wstring en);
	wstring UaToEn(wstring ua);
	void setLib(CollectionWord lib);
};

class FileWork {
public:
	CollectionWord Load();
	void Write(CollectionWord lib);
};

class FacadeFileBase {
	FileWork* filesystem;
	Translate* translate;
	CollectionWord words;
public:
	FacadeFileBase(FileWork* filesystem, Translate* translate, CollectionWord words);
	~FacadeFileBase();
	void AddNewWord(wstring ua, wstring en);
	void DeleteWord(wstring word);
	void WriteToBase();
	void TranslateUAtoEN(wstring ua);
	void TranslateEntoUA(wstring en);
};