//#include <Windows.h>
//#include <System.Windows.Forms.h>
//
//using namespace System;
//using namespace System::Windows::Forms;
//
//namespace Project7 {
//    // Предварительные объявления классов
//    ref class DicCreate;
//    ref_class DicChoice;
//    ref_class MyForm;
//
//    public ref class wins {
//    public:
//        static void OpenDicCreate();
//        static void OpenDicChoice();
//        static void OpenMainForm();
//    };
//}
//
//// wins.cpp
//#include "wins.h"
//#include "DicCreate.h" // Включите заголовок DicCreate
//#include "DicChoice.h" // Включите заголовок DicChoice
//#include "MyForm.h"    // Включите заголовок MyForm
//
//namespace Project7 {
//    void wins::OpenDicCreate() {
//        DicCreate^ adForm1 = gcnew DicCreate();
//        adForm1->ShowDialog(); // Используйте ShowDialog() для модального окна
//    }
//
//    void wins::OpenDicChoice() {
//        DicChoice^ adForm1 = gcnew DicChoice();
//        adForm1->ShowDialog(); // Используйте ShowDialog() для модального окна
//    }
//
//    void wins::OpenMainForm() {
//        MyForm^ adForm1 = gcnew MyForm();
//        adForm1->ShowDialog(); // Используйте ShowDialog() для модального окна
//    }
//}
