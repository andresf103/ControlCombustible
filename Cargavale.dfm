object Form1: TForm1
  Left = 735
  Top = 143
  Width = 418
  Height = 467
  Caption = 'Vale de Combustible'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel
    Left = 64
    Top = 144
    Width = 37
    Height = 13
    Caption = 'Patente'
  end
  object Label3: TLabel
    Left = 64
    Top = 176
    Width = 34
    Height = 13
    Caption = 'Solicita'
  end
  object Label4: TLabel
    Left = 64
    Top = 208
    Width = 64
    Height = 13
    Caption = 'Destino/Obra'
  end
  object Label5: TLabel
    Left = 64
    Top = 240
    Width = 30
    Height = 13
    Caption = 'Fecha'
  end
  object Label6: TLabel
    Left = 64
    Top = 263
    Width = 81
    Height = 13
    Caption = 'Cantidad en litros'
  end
  object Ltitulo: TLabel
    Left = 64
    Top = 48
    Width = 295
    Height = 37
    Caption = 'Vale de Combustible'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsUnderline]
    ParentFont = False
  end
  object Epatente: TComboBox
    Left = 160
    Top = 136
    Width = 145
    Height = 21
    CharCase = ecUpperCase
    ItemHeight = 13
    TabOrder = 0
  end
  object Echofer: TComboBox
    Left = 160
    Top = 168
    Width = 145
    Height = 21
    CharCase = ecUpperCase
    ItemHeight = 13
    TabOrder = 1
  end
  object Edestino: TComboBox
    Left = 160
    Top = 200
    Width = 145
    Height = 21
    CharCase = ecUpperCase
    ItemHeight = 13
    TabOrder = 2
  end
  object Efecha: TEdit
    Left = 160
    Top = 230
    Width = 145
    Height = 21
    CharCase = ecUpperCase
    TabOrder = 3
  end
  object Elitros: TEdit
    Left = 160
    Top = 258
    Width = 145
    Height = 21
    CharCase = ecUpperCase
    TabOrder = 4
  end
  object Btguardar: TButton
    Left = 48
    Top = 320
    Width = 337
    Height = 97
    Caption = 'Guardar'
    TabOrder = 5
  end
end
