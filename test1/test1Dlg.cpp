
// test1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "test1.h"
#include "test1Dlg.h"
#include "afxdialogex.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);// DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Ctest1Dlg 对话框




Ctest1Dlg::Ctest1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ctest1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	c=180;
	c1=174;
}

void Ctest1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Ctest1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON1, &Ctest1Dlg::OnBnClickedButton1)
	//ON_BN_CLICKED(IDC_BUTTON2, &Ctest1Dlg::OnBnClickedButton2)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON3, &Ctest1Dlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// Ctest1Dlg 消息处理程序

BOOL Ctest1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	SetTimer(1,1000,NULL);
	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Ctest1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Ctest1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Ctest1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctest1Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	MessageBox(L"Up Up");

	CDialogEx::OnLButtonUp(nFlags, point);
}


void Ctest1Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	TRACE("x=%d,y=%d",point.x,point.y);
	if(point.x<10&&point.y<10)
		MessageBox(L"hello");

	CDialogEx::OnMouseMove(nFlags, point);
}


void Ctest1Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	/*if(nIDEvent==1)
		MessageBox(L"Hi Timer 1111");
	if(nIDEvent==2)
		MessageBox(L"Hi Timer 2222");*/
	int r=80,x,y,x1,y1,ox=150,oy=150;
	CDC *pDC;
	CPen newpen,*oldpen;
	newpen.CreatePen(PS_SOLID,1,RGB(255,255,255));
	pDC=GetDC();
	oldpen=pDC->SelectObject(&newpen);
	x=ox+r*sin(c*3.1415926/180);
	y=oy+r*cos(c*3.1415926/180);
	pDC->MoveTo(ox,oy);
	pDC->LineTo(x,y);
	c=c-6;
	CDC *pDC1;
	CPen newpen1,*oldpen1;
	newpen1.CreatePen(PS_SOLID,1,RGB(0,0,0));
	pDC1=GetDC();
	oldpen1=pDC1->SelectObject(&newpen1);
	x1=ox+r*sin(c1*3.1415926/180);
	y1=oy+r*cos(c1*3.1415926/180);
	pDC1->MoveTo(ox,oy);
	pDC1->LineTo(x1,y1);
	c1=c1-6;
	CDialogEx::OnTimer(nIDEvent);
}


void Ctest1Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	KillTimer(1);
}


void Ctest1Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	KillTimer(2);
}


void Ctest1Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	KillTimer(1);
}


void Ctest1Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CClientDC dc(this);
	dc.SetWindowOrg(0-150,0-150);
	CPen *oldpen;
	CPen pen(PS_SOLID,2,RGB(0,0,0));
	oldpen=dc.SelectObject(&pen);
	dc.Ellipse(-100,100,100,-100);
	dc.Ellipse(-1,-1,1,1);
	dc.TextOutW(90,-8,L"3");
	dc.TextOutW(-98,-8,L"9");
	dc.TextOutW(-8,-99.5,L"12");
	dc.TextOutW(-2,83,L"6");
	for(int i=0;i<12;i++)
	{
		double l=90,ag=i*3.1415926/6;
		double a=l*sin(ag)+1,b=-l*cos(ag)+1,c=l*sin(ag)-1,d=-l*cos(ag)-1;
		dc.Ellipse(a,b,c,d);
	}
}
