object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Settings'
  ClientHeight = 229
  ClientWidth = 323
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 120
    Top = 8
    Width = 92
    Height = 33
    Caption = 'Theme'
    Color = clHighlight
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clHighlight
    Font.Height = 33
    Font.Name = 'MarigoldPS'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object Label2: TLabel
    Left = 99
    Top = 88
    Width = 126
    Height = 33
    Caption = 'Key binds'
    Color = clHighlight
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clHighlight
    Font.Height = 33
    Font.Name = 'MarigoldPS'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object ComboBox1: TComboBox
    Left = 88
    Top = 47
    Width = 145
    Height = 21
    TabOrder = 0
    Text = 'Light'
    Items.Strings = (
      'Light'
      'Minimal'
      'Christmas')
  end
  object ComboBox2: TComboBox
    Left = 88
    Top = 127
    Width = 145
    Height = 21
    TabOrder = 1
    Text = 'qwer'
    Items.Strings = (
      'qwer'
      '1234'
      'asdf')
  end
  object Button1: TButton
    Left = 120
    Top = 195
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 2
    OnClick = Button1Click
  end
end
