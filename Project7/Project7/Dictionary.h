#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
using namespace System::IO;

public ref class DictionaryOW {
private:
    System::String^ name;       // Управляемое строковое поле
    System::String^ filePath;   // Поле для хранения имени файла источника
    int id;                     // Поле для хранения идентификатора

    static List<DictionaryOW^>^ dictionaries; // Вектор для хранения словарей

public:
    // Статический конструктор для инициализации списка словарей
    static DictionaryOW() {
        dictionaries = gcnew List<DictionaryOW^>();
        String^ file = "data.csv";
        if (File::Exists("last.txt")) {
            file = File::ReadAllText("last.txt")->Trim();
        }
        else file = "data.csv";
        myDictionary = gcnew DictionaryOW("My Dictionary", file, 1); // Инициализация здесь
    }

    // Конструктор
    DictionaryOW(System::String^ initialName, System::String^ initialSourceFile, int initialId) {
        name = initialName;
        filePath = initialSourceFile;
        id = initialId;

        try {
            dictionaries->Add(this); // Добавляем текущий экземпляр в список
        }
        catch (Exception^ ex) {
            Console::WriteLine("Ошибка при добавлении в словарь: {0}", ex->Message);
        }
    }

    // Метод для получения имени
    System::String^ GetName() {
        return name;
    }

    // Метод для установки имени
    void SetName(System::String^ newName) {
        name = newName;
    }

    // Метод для получения файла источника
    System::String^ GetSourceFile() {
        return filePath;
    }

    // Метод для установки файла источника
    void SetSourceFile(System::String^ newSourceFile) {
        filePath = newSourceFile;
    }

    // Метод для получения идентификатора
    int GetId() {
        return id;
    }

    // Метод для установки идентификатора
    void SetId(int newId) {
        id = newId;
    }

    // Метод для получения всех словарей
    static List<DictionaryOW^>^ AllDictionaries() {
        return dictionaries;
    }


private:
    static DictionaryOW^ myDictionary; // Теперь это приватное статическое поле

public:

    static DictionaryOW^ GetCurrent() {
        return myDictionary;
    }
};
