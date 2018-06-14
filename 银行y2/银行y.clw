; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=DengLu
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "银行y.h"

ClassCount=7
Class1=CYApp
Class2=CYDlg
Class3=CAboutDlg

ResourceCount=7
Resource1=IDD_DIALOG2
Resource2=IDR_MAINFRAME
Resource3=IDD_DIALOG_CUNKUAN
Class4=DengLu
Resource4=IDD_Y_DIALOG
Class5=Ziliao
Resource5=IDD_ABOUTBOX
Class6=SAVE
Resource6=IDD_DIALOG1
Class7=Zhuce
Resource7=IDD_DIALOG3

[CLS:CYApp]
Type=0
HeaderFile=银行y.h
ImplementationFile=银行y.cpp
Filter=N
LastObject=CYApp

[CLS:CYDlg]
Type=0
HeaderFile=银行yDlg.h
ImplementationFile=银行yDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CYDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=银行yDlg.h
ImplementationFile=银行yDlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177294
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_Y_DIALOG]
Type=1
Class=CYDlg
ControlCount=10
Control1=IDCANCEL,button,1342242816
Control2=IDC_BUTTON_Ziliao,button,1342242816
Control3=IDC_BUTTON_Cunkuan,button,1342242816
Control4=IDC_BUTTON_Chaxun,button,1342242816
Control5=IDC_STATIC,static,1342308993
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342177294
Control8=IDC_STATIC,static,1342177294
Control9=IDC_STATIC,static,1342177294
Control10=IDC_STATIC,static,1342177294

[DLG:IDD_DIALOG1]
Type=1
Class=DengLu
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_Name,edit,1350631552
Control5=IDC_EDIT_Password,edit,1350631584
Control6=IDC_STATIC,static,1342177294
Control7=IDC_STATIC,static,1342177294
Control8=IDC_STATIC,static,1342308364
Control9=IDC_ZHUCE,button,1342242816

[CLS:DengLu]
Type=0
HeaderFile=DengLu.h
ImplementationFile=DengLu.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_ZHUCE

[DLG:IDD_DIALOG2]
Type=1
Class=Ziliao
ControlCount=15
Control1=IDCANCEL,button,1342242816
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_Zhanghu,edit,1350631552
Control7=IDC_Mima,edit,1350631584
Control8=IDC_Xingming,edit,1350631552
Control9=IDC_Zhuzhi,edit,1350631552
Control10=IDC_BAOCUN,button,1342242816
Control11=IDC_STATIC,static,1342177294
Control12=IDC_STATIC,static,1342177294
Control13=IDC_STATIC,static,1342177294
Control14=IDC_STATIC,static,1342177294
Control15=IDC_STATIC,static,1342308353

[CLS:Ziliao]
Type=0
HeaderFile=Ziliao.h
ImplementationFile=Ziliao.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_BAOCUN
VirtualFilter=dWC

[DLG:IDD_DIALOG_CUNKUAN]
Type=1
Class=SAVE
ControlCount=9
Control1=IDC_BUTTON_QUEREN,button,1342242816
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_CUN,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_YUE,edit,1350633600
Control7=IDC_STATIC,static,1342177294
Control8=IDC_STATIC,static,1342177294
Control9=IDC_STATIC,static,1342308353

[CLS:SAVE]
Type=0
HeaderFile=SAVE.h
ImplementationFile=SAVE.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_BUTTON_QUEREN

[DLG:IDD_DIALOG3]
Type=1
Class=Zhuce
ControlCount=15
Control1=IDCANCEL,button,1342242816
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_Zhanghu,edit,1350631552
Control7=IDC_Mima,edit,1350631584
Control8=IDC_Xingming,edit,1350631552
Control9=IDC_Zhuzhi,edit,1350631552
Control10=IDC_BAOCUN,button,1342242816
Control11=IDC_STATIC,static,1342177294
Control12=IDC_STATIC,static,1342177294
Control13=IDC_STATIC,static,1342177294
Control14=IDC_STATIC,static,1342177294
Control15=IDC_STATIC,static,1342308353

[CLS:Zhuce]
Type=0
HeaderFile=Zhuce.h
ImplementationFile=Zhuce.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_Mima

