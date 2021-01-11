object Fmusuario: TFmusuario
  Left = 540
  Top = 105
  Width = 396
  Height = 238
  Caption = 'Modificar usuario'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Reference Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnKeyPress = FormKeyPress
  PixelsPerInch = 96
  TextHeight = 15
  object Label3: TLabel
    Left = 17
    Top = 108
    Width = 128
    Height = 15
    Caption = 'Confirmar Contrase'#241'a'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Reference Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 17
    Top = 76
    Width = 106
    Height = 15
    Caption = 'Contrase'#241'a Nueva'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Reference Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label1: TLabel
    Left = 17
    Top = 20
    Width = 110
    Height = 15
    Caption = 'Nombre de Usuario'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Reference Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 17
    Top = 48
    Width = 105
    Height = 15
    Caption = 'Contrase'#241'a Actual'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Reference Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object CBadmin: TCheckBox
    Left = 56
    Top = 144
    Width = 97
    Height = 17
    Caption = 'Es Admin'
    Ctl3D = False
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Reference Sans Serif'
    Font.Style = []
    ParentCtl3D = False
    ParentFont = False
    TabOrder = 4
  end
  object Button1: TButton
    Left = 224
    Top = 136
    Width = 97
    Height = 33
    Caption = 'Aceptar'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Reference Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = Button1Click
  end
  object Epassword2: TEdit
    Left = 160
    Top = 104
    Width = 161
    Height = 21
    BevelInner = bvNone
    BevelKind = bkFlat
    BevelOuter = bvNone
    Ctl3D = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Reference Sans Serif'
    Font.Style = []
    ParentCtl3D = False
    ParentFont = False
    PasswordChar = '#'
    TabOrder = 3
  end
  object Epassword1: TEdit
    Left = 160
    Top = 72
    Width = 161
    Height = 21
    BevelInner = bvNone
    BevelKind = bkFlat
    BevelOuter = bvNone
    Ctl3D = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Reference Sans Serif'
    Font.Style = []
    ParentCtl3D = False
    ParentFont = False
    PasswordChar = '#'
    TabOrder = 2
  end
  object Eusuario: TEdit
    Left = 160
    Top = 16
    Width = 161
    Height = 21
    BevelInner = bvNone
    BevelKind = bkFlat
    BevelOuter = bvNone
    Ctl3D = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Reference Sans Serif'
    Font.Style = []
    ParentCtl3D = False
    ParentFont = False
    TabOrder = 0
  end
  object Eoldpassword: TEdit
    Left = 160
    Top = 44
    Width = 161
    Height = 21
    BevelInner = bvNone
    BevelKind = bkFlat
    BevelOuter = bvNone
    Ctl3D = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Reference Sans Serif'
    Font.Style = []
    ParentCtl3D = False
    ParentFont = False
    PasswordChar = '#'
    TabOrder = 1
  end
end
