//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
int theme = 1;
int key = 1;
int mode = 1;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	if (ComboBox1->Text == "Light")
		theme = 1;
	if (ComboBox1->Text == "Minimal")
		theme = 2;
	if (ComboBox1->Text == "Christmas")
		theme = 3;
	if (ComboBox2->Text == "qwer")
		key = 1;
	if (ComboBox2->Text == "1234")
		key = 2;
	if (ComboBox2->Text == "asdf")
		key = 3;
	Form2->Close();
}
//---------------------------------------------------------------------------

