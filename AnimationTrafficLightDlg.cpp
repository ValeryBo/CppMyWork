# CppMyWork
// AnimationTrafficLightDlg.cpp : implementation file
	//
	

	#include "stdafx.h"
	#include "AnimationTrafficLight.h"
	#include "AnimationTrafficLightDlg.h"
	#include "afxdialogex.h"
	

	#ifdef _DEBUG
	#define new DEBUG_NEW
	#endif
	

	

	// CAnimationTrafficLightDlg dialog
	

	

	

	CAnimationTrafficLightDlg::CAnimationTrafficLightDlg(CWnd* pParent /*=NULL*/)
		: CDialog(IDD_ANIMATIONTRAFFICLIGHT_DIALOG, pParent)
	{
		m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	}
	

	void CAnimationTrafficLightDlg::DoDataExchange(CDataExchange* pDX)
	{
		CDialog::DoDataExchange(pDX);
	}
	

	BEGIN_MESSAGE_MAP(CAnimationTrafficLightDlg, CDialog)
		ON_WM_PAINT()
		ON_WM_QUERYDRAGICON()
	END_MESSAGE_MAP()
	

	

	// CAnimationTrafficLightDlg message handlers
	

	BOOL CAnimationTrafficLightDlg::OnInitDialog()
	{
		CDialog::OnInitDialog();
	

		// Set the icon 
	
		SetIcon(m_hIcon, TRUE);			// Set big one
		SetIcon(m_hIcon, FALSE);		// Set small one
	

		// TODO: Add extra initialization here
	

		return TRUE;  
	}
	

	// If you add a minimize button to your dialog, you will need the code below
	


	void CAnimationTrafficLightDlg::OnPaint()
	{
		if (IsIconic())
		{
			CPaintDC dc(this); // device for painting
	

			SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
	

			// Center icon in client rectangle
			int cxIcon = GetSystemMetrics(SM_CXICON);
			int cyIcon = GetSystemMetrics(SM_CYICON);
			CRect rect;
			GetClientRect(&rect);
			int x = (rect.Width() - cxIcon + 1) / 2;
			int y = (rect.Height() - cyIcon + 1) / 2;
	

			// Draw the icon
			dc.DrawIcon(x, y, m_hIcon);
		}
		else
		{
			
			CClientDC dc(this);
			GetClientRect(&rc);
	

			hNew = CreateFont(28, 0, 0, 0, FW_NORMAL, 0, 0, 0,
				ANSI_CHARSET, OUT_DEFAULT_PRECIS,
				CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
				DEFAULT_PITCH | FF_DONTCARE,
				L"Times New Roman Cyr");
			hold = (HFONT)SelectObject(dc, hNew);
	

			dc.FillSolidRect(&rc, RGB(255, 255, 255));
	

			RH = abs(rc.left - rc.right);
			RW = abs(rc.top - rc.bottom);
			cx = RH / 2;
			cy = RW / 2;
	

			cf = RGB(0, 0, 0);
			hPenOxy = CreatePen(PS_SOLID, 3, cf);
			hOldPen = (HPEN)SelectObject(dc, hPenOxy);
	

	

			// TODO Set coordinates; Draw rectangle

	

			x1 = cx - 100+25; y1 = cy - 200;
			x2 = x1 + 200-45; y2 = y1 + 400;
	

			dc.Rectangle(x1, y1, x2, y2);
	

			dy = abs(y2 - y1) / 3;
	
              // Set coordinates for your Ellipses; Creating                                              brushes

			int s1x1, s1y1, s1x2, s1y2;
			int s2x1, s2y1, s2x2, s2y2;
			int s3x1, s3y1, s3x2, s3y2;
			CBrush *ks1, *ks2, *ks3;
	

	

			s1x1 = x1; s1y1 = y1; s1x2 = x2; s1y2=y1 + dy;
			s2x1 = x1; s2y1 = y1 + dy; s2x2 = x2; s2y2= y1 + 2 * dy;
			s3x1 = x1; s3y1 = y1 + 2 * dy; s3x2 = x2; s3y2 = y1 + 3 * dy;
	

	

	

			// Draw three ellipses
			dc.Ellipse(s1x1, s1y1, s1x2, s1y2);
			
			dc.Ellipse(s2x1, s2y1, s2x2, s2y2);
			
			dc.Ellipse(s3x1, s3y1, s3x2, s3y2);
	

			for (i = 0; i < 500; i++)
			{
				// red color
				ks1 = new CBrush(RGB(255, 0, 0));
				dc.SelectObject(*ks1);
				dc.FloodFill(s1x1 + dy / 2, s1y1 + dy / 2, RGB(0, 0, 0));
	

				Sleep(2000);
	

				//yelo color
				ks2 = new CBrush(RGB(255, 221, 0));
				dc.SelectObject(*ks2);
				dc.FloodFill(s2x1 + dy / 2, s2y1 + dy / 2, RGB(0, 0, 0));
	

				Sleep(2000);
	

				// red color
				ks1 = new CBrush(RGB(255, 255, 255));
				dc.SelectObject(*ks1);
				dc.FloodFill(s1x1 + dy / 2, s1y1 + dy / 2, RGB(0, 0, 0));
	

				//yelo color
				ks2 = new CBrush(RGB(255, 255, 255));
				dc.SelectObject(*ks2);
				dc.FloodFill(s2x1 + dy / 2, s2y1 + dy / 2, RGB(0, 0, 0));
	

				//green color
				ks3 = new CBrush(RGB(0, 221, 0));
				dc.SelectObject(*ks3);
				dc.FloodFill(s3x1 + dy / 2, s3y1 + dy / 2, RGB(0, 0, 0));
	

				for (k = 0; k < 10; k++)
				{
	

					//green color
					ks3 = new CBrush(RGB(0, 221, 0));
					dc.SelectObject(*ks3);
					dc.FloodFill(s3x1 + dy / 2, s3y1 + dy / 2, RGB(0, 0, 0));
	

					Sleep(500);
	

					//green color
					ks3 = new CBrush(RGB(255, 255, 255));
					dc.SelectObject(*ks3);
					dc.FloodFill(s3x1 + dy / 2, s3y1 + dy / 2, RGB(0, 0, 0));
	

					Sleep(500);
				}
			}
	

	

			SelectObject(dc, hOldPen);
			DeleteObject(hPenOxy);
			DeleteObject(hNew);
			hold = (HFONT)SelectObject(dc, hbk);
	

			
			
			CDialog::OnPaint();
		}
	}
	

	// The system calls this function to obtain the cursor to display while the user drags
	//  the minimized window.
	HCURSOR CAnimationTrafficLightDlg::OnQueryDragIcon()
	{
		return static_cast<HCURSOR>(m_hIcon);
	}
