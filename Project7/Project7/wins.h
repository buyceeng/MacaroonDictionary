#pragma once

using namespace System;
using namespace System::Windows::Forms;

namespace Project7 {
    // Предварительные объявления классов
    ref class DicCreate;
    ref class DicChoice;
    ref class MyForm;

    public ref class wins {
    public:
        static void OpenDicCreate();
        static void OpenDicChoice();
        static void OpenMainForm();
    };
}
