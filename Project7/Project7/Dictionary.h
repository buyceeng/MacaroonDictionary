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
    System::String^ name;       // ����������� ��������� ����
    System::String^ filePath;   // ���� ��� �������� ����� ����� ���������
    int id;                     // ���� ��� �������� ��������������

    static List<DictionaryOW^>^ dictionaries; // ������ ��� �������� ��������

public:
    // ����������� ����������� ��� ������������� ������ ��������
    static DictionaryOW() {
        dictionaries = gcnew List<DictionaryOW^>();
        String^ file = "data.csv";
        if (File::Exists("last.txt")) {
            file = File::ReadAllText("last.txt")->Trim();
        }
        else file = "data.csv";
        myDictionary = gcnew DictionaryOW("My Dictionary", file, 1); // ������������� �����
    }

    // �����������
    DictionaryOW(System::String^ initialName, System::String^ initialSourceFile, int initialId) {
        name = initialName;
        filePath = initialSourceFile;
        id = initialId;

        try {
            dictionaries->Add(this); // ��������� ������� ��������� � ������
        }
        catch (Exception^ ex) {
            Console::WriteLine("������ ��� ���������� � �������: {0}", ex->Message);
        }
    }

    // ����� ��� ��������� �����
    System::String^ GetName() {
        return name;
    }

    // ����� ��� ��������� �����
    void SetName(System::String^ newName) {
        name = newName;
    }

    // ����� ��� ��������� ����� ���������
    System::String^ GetSourceFile() {
        return filePath;
    }

    // ����� ��� ��������� ����� ���������
    void SetSourceFile(System::String^ newSourceFile) {
        filePath = newSourceFile;
    }

    // ����� ��� ��������� ��������������
    int GetId() {
        return id;
    }

    // ����� ��� ��������� ��������������
    void SetId(int newId) {
        id = newId;
    }

    // ����� ��� ��������� ���� ��������
    static List<DictionaryOW^>^ AllDictionaries() {
        return dictionaries;
    }


private:
    static DictionaryOW^ myDictionary; // ������ ��� ��������� ����������� ����

public:

    static DictionaryOW^ GetCurrent() {
        return myDictionary;
    }
};
