#pragma once

using namespace System;
using namespace System::Windows::Forms;

public ref class DataSourceEventArgs : public EventArgs {
public:
    DataGridView^ DataGridViewSource;
    String^ SourceFile; // ��������� ���������� ��� �������� ���� � �����

    DataSourceEventArgs(DataGridView^ dataGridViewSource, String^ sourceFile) {
        this->DataGridViewSource = dataGridViewSource;
        this->SourceFile = sourceFile; // �������������� ���� � �����
    }
};
