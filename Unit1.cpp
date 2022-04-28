//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit1.h"
#include "Unit2.h"
#include "cmath"
#include <vector>
#include <fstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
using namespace std;
Graphics::TBitmap
					*kadr_temp1 = new Graphics::TBitmap(),
					*kadr_temp2 = new Graphics::TBitmap(),
					*kadr1 = new Graphics::TBitmap(),
					*kadr2 = new Graphics::TBitmap(),
				*fon = new Graphics::TBitmap();
vector <Graphics::TBitmap*> kadr;
vector <TRect> pr_kadr;
vector <int> x;
vector <double> y;
vector <bool> line;
vector <int> k;
double w, h;
double v0;
bool kost = true;
double u;
double i = 0;
int k1 = 81;
int k2 = 87;
int k3 = 69;
int k4 = 82;
int n,m=4;
int y_temp = -1350;
bool line1=false;
extern int theme;
extern int key;
extern int mode;
double t=0;
bool pr = false;
bool start = true;
TRect pr_kadr1, pr_temp,pr_kadr2,pr_kadr3;
void add_kadr(Graphics::TBitmap & s)
	{
		kadr.push_back(&s);
	}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}

//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	for (int i=0;i<n;i++)
	{
		Image1 -> Canvas -> Draw(x[i], y[i], kadr[i]);
		y[i]+=9.8;
	if (line[i] == true)
	{
		pr_kadr[i]=Bounds(x[i], y[i], w, h);
		kadr[i] -> Canvas -> CopyRect(pr_kadr1, fon -> Canvas,  pr_kadr[i]);
		Image1 -> Canvas -> Draw(x[i], y[i], kadr2);
	}
	else
	{
	 pr_kadr[i]=Bounds(x[i], y[i], w, h);
		kadr[i] -> Canvas -> CopyRect(pr_kadr1, fon -> Canvas,  pr_kadr[i]);
		Image1 -> Canvas -> Draw(x[i], y[i], kadr1);
	}
	}


}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	for (int i=0; i<n;i++)
	{
		if (mode == 1)
		{
			if (Key == k[i] && y[i] >= 400 && y[i] <= 800)
				{
					line[i] = true;
				}
		}
	}
}
//---------------------------------------------------------------------------




void __fastcall TForm1::SpeedButton3Click(TObject *Sender)
{
	Timer1->Enabled = false;
	start=false;
	int y_temp = -1350;
	MediaPlayer1->Stop();
	MediaPlayer1->FileName="D:\\проект final\\Win32\\Debug\\sound.wav";
 MediaPlayer1->Open();
	for (int i=0; i<y.size();i++)
	{
	y[i]=y_temp;
	y_temp-=200;
	line[i]=false;

	}
	Image1->Visible=false;
	SpeedButton2 -> Visible = false;
	SpeedButton3 -> Visible = false;
	SpeedButton4 -> Visible = false;
	Form1->Close();


}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
	MediaPlayer1->Pause();
   Timer1->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
if (start)
{
	 MediaPlayer1->FileName="D:\\проект final\\Win32\\Debug\\sound.wav";
 MediaPlayer1->Open();
 MediaPlayer1->Play();
 start=false;
}
else
MediaPlayer1->Play();
Image1->Visible=true;
if (key == 1)
	{
		 k1 = 81;
		 k2 = 87;
		k3 = 69;
		k4 = 82;
	}
	if (key == 2)
	{
		 k1 = 49;
		 k2 = 50;
		k3 = 51;
		k4 = 52;
	}
	if (key == 3)
	{
		 k1 = 65;
		 k2 = 83;
		k3 = 68;
		k4 = 70;
	}
ifstream fin;
	string path = "level1.txt";
	fin.open(path);
	fin >> n;
	vector < vector <int> > a(n, vector <int> (m) );
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			fin >> a[i][j];
		}
	for (int i = n-1; i >= 0; i--)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 1)
				{
					if (j==0)
					{
						 x.push_back(0);
						 k.push_back(k1);
					}

					if (j==1)
					{
						x.push_back(150);
						k.push_back(k2);
					}

					if (j==2)
					{
						 x.push_back(300);
						 k.push_back(k3);
					}

					if (j==3)
					{
						x.push_back(450);
						k.push_back(k4);
					}

					y.push_back(y_temp);
					line.push_back(false);
				}
		}
		y_temp=y_temp-200;
	}
	fin.close();
	SpeedButton2 -> Visible = true;
	SpeedButton3 -> Visible = true;
	SpeedButton4 -> Visible = true;

	if (theme == 1)
	{
		fon -> LoadFromFile("pole2.bmp");
	}
	if (theme == 2)
	{
		fon -> LoadFromFile("pole1.bmp");
	}
	if (theme == 3)
	{
		fon -> LoadFromFile("pole3.bmp");
	}
	Image1 -> Picture -> Assign(fon);
	if (theme == 1)
	{
		kadr1 -> LoadFromFile("kletka.bmp");
		kadr2 -> LoadFromFile("kletka2.bmp");
	}
	if (theme == 2)
	{
		kadr1 -> LoadFromFile("kletka.bmp");
		kadr2 -> LoadFromFile("kletka2.bmp");
	}
	if (theme == 3)
	{
		kadr1 -> LoadFromFile("kletka3.bmp");
		kadr2 -> LoadFromFile("kletka4.bmp");
	}
	w = kadr1 -> Width;
	h = kadr1 -> Height;
   pr_kadr1 = Bounds(0, 0, w, h);
   for (int i=0;i<n;i++)
   {
	   pr_kadr.push_back(Bounds(x[i], y[i], w, h));
   }
   for (int i=0;i<n;i++)
   {
   Graphics::TBitmap *kadr_temp = new Graphics::TBitmap();
   kadr_temp -> Width = w;
   kadr_temp -> Height = h;
		kadr_temp -> Canvas -> CopyRect(pr_kadr1, fon -> Canvas,  pr_kadr[i]);
		add_kadr(*kadr_temp);
   }
   Timer1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton4Click(TObject *Sender)
{
int y_temp = -1350;
MediaPlayer1->Stop();
MediaPlayer1->FileName="D:\\проект final\\Win32\\Debug\\sound.wav";
 MediaPlayer1->Open();
for (int i=0; i<y.size();i++)
{
	y[i]=y_temp;
	y_temp-=200;
	line[i] = false;

}
}
//---------------------------------------------------------------------------

