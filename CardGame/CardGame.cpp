// CardGame.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "CardGame.h"
#include"CARD.h"

CARD cards;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK About(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,
                   PSTR lpCmdLine,int nCmdShow)
{
	MSG msg;
	HWND hWnd;
	WNDCLASS wc;
	TCHAR * szAppName = _T("CardGame");

	wc.style = CS_VREDRAW | CS_HREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
	wc.lpszClassName = szAppName;
	wc.lpszMenuName = MAKEINTRESOURCE(IDC_CARDGAME);

	if (!RegisterClass(&wc))
	{
		MessageBox(NULL, _T("This program requires Windows NT!"), szAppName, MB_OK);
		return false;
	}

	hWnd = CreateWindow(szAppName, _T("纸牌游戏"),
		WS_OVERLAPPEDWINDOW,
		100, 30, 1600, 1000,
		NULL, NULL, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{		
		TranslateMessage(&msg);
		DispatchMessage(&msg);		
	}

	return (int) msg.wParam;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HINSTANCE hInst;

	switch (message)
	{
	case WM_CREATE:
		hInst = (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE);
		cards.InitHinst(hWnd);
		break;

	case WM_SIZE:
		cards.ClientSize(lParam);
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDM_DEAL:;
			cards.StartGame();
			cards.SetRandNum();
			break;

		case IDM_STARTGAME:
			cards.JudgePlayer();
			break;

		case BUTTON1:
			cards.BtnMsg();
			break;

		case BUTTON2:
			cards.BtnMsg2();
			break;

		case CHOOSE_BTN:
			cards.BtnChoose();
			break;

		case CHOOSE_BTN2:
			cards.BtnChoose2();
			break;

		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;

		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		}
		break;

	case WM_LBUTTONDOWN:
		cards.OnLeftButton(lParam);
		break;

	case WM_PAINT:
		cards.Paint();
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;	
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}

BOOL CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
		return TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		}
		break;
	}
	return FALSE;
}
