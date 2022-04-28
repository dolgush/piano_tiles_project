//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
Graphics::TBitmap *fon = new Graphics::TBitmap();
bool check = false;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
	fon -> LoadFromFile("menu.bmp");
	Image1 -> Picture -> Assign(fon);

}
//---------------------------------------------------------------------------

void __fastcall TForm3::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	if (Y >= 37 && Y <= 187 && X>=135 && X<=435)
		 Form1->Show();
	if (Y >= 408 && Y <= 558 && X>=135 && X<=435)
		Form3->Close();
	if (Y >= 221 && Y <= 371 && X>=135 && X<=435)
		Form2->Show();
}
//---------------------------------------------------------------------------

