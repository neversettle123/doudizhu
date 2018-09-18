#include "stdafx.h"
#include "CARD.h"

CARD::CARD()
{
	_hWnd = NULL;
	_hdcMem = NULL;
	_hInst = NULL;
	_Btn1 = _Btn2 = NULL;
	_hBtn1 = _hBtn2 = NULL;

	_FirstPaint = FALSE;	
	_StartSwitch = FALSE;
	_IsYourTurn = FALSE;	
	_PlayerTurn1 = FALSE;
	_PlayerTurn2 = FALSE;

	_GetLanLoad = FALSE;
	_WantLoad1 = FALSE;
	_WantLoad2 = FALSE;
	_WantLoad3 = FALSE;

	ShowCard1 = FALSE;
	ShowYourself = FALSE;
	ShowCard2 = FALSE;
	
	_CardOpt = 0;
	_cxPos = _cyPos = 0;
	_cxClient = _cyClient = 0;
	
	for (int i = 0; i < CARD_SIZE; i++)
		bi[i].hbmp = NULL;
	
	_temp.clear();
	_Player1.clear();
	_Player2.clear();
	_Yourself.clear();
	_ChooseCard.clear();
	_ChooseCard2.clear();
	_ChooseCard3.clear();

	ci[0].RcID = IDB_BITMAP1, ci[0].Color = REDHEART, ci[0].nValue = 3;
	ci[1].RcID = IDB_BITMAP2, ci[1].Color = SPADE, ci[1].nValue = 3;
	ci[2].RcID = IDB_BITMAP3, ci[2].Color = BLOSSOM, ci[2].nValue = 3;
	ci[3].RcID = IDB_BITMAP4, ci[3].Color = DIAMOND, ci[3].nValue = 3;
	ci[4].RcID = IDB_BITMAP5, ci[4].Color = REDHEART, ci[4].nValue = 4;
	ci[5].RcID = IDB_BITMAP6, ci[5].Color = SPADE, ci[5].nValue = 4;
	ci[6].RcID = IDB_BITMAP7, ci[6].Color = BLOSSOM, ci[6].nValue = 4;
	ci[7].RcID = IDB_BITMAP8, ci[7].Color = DIAMOND, ci[7].nValue = 4;
	ci[8].RcID = IDB_BITMAP9, ci[8].Color = REDHEART, ci[8].nValue = 5;
	ci[9].RcID = IDB_BITMAP10, ci[9].Color = SPADE, ci[9].nValue = 5;
	ci[10].RcID = IDB_BITMAP11, ci[10].Color = BLOSSOM, ci[10].nValue = 5;
	ci[11].RcID = IDB_BITMAP12, ci[11].Color = DIAMOND, ci[11].nValue = 5;
	ci[12].RcID = IDB_BITMAP13, ci[12].Color = REDHEART, ci[12].nValue = 6;
	ci[13].RcID = IDB_BITMAP14, ci[13].Color = SPADE, ci[13].nValue = 6;
	ci[14].RcID = IDB_BITMAP15, ci[14].Color = BLOSSOM, ci[14].nValue = 6;
	ci[15].RcID = IDB_BITMAP16, ci[15].Color = DIAMOND, ci[15].nValue = 6;
	ci[16].RcID = IDB_BITMAP17, ci[16].Color = REDHEART, ci[16].nValue = 7;
	ci[17].RcID = IDB_BITMAP18, ci[17].Color = SPADE, ci[17].nValue = 7;
	ci[18].RcID = IDB_BITMAP19, ci[18].Color = BLOSSOM, ci[18].nValue = 7;
	ci[19].RcID = IDB_BITMAP20, ci[19].Color = DIAMOND, ci[19].nValue = 7;
	ci[20].RcID = IDB_BITMAP21, ci[20].Color = REDHEART, ci[20].nValue = 8;
	ci[21].RcID = IDB_BITMAP22, ci[21].Color = SPADE, ci[21].nValue = 8;
	ci[22].RcID = IDB_BITMAP23, ci[22].Color = BLOSSOM, ci[22].nValue = 8;
	ci[23].RcID = IDB_BITMAP24, ci[23].Color = DIAMOND, ci[23].nValue = 8;
	ci[24].RcID = IDB_BITMAP25, ci[24].Color = REDHEART, ci[24].nValue = 9;
	ci[25].RcID = IDB_BITMAP26, ci[25].Color = SPADE, ci[25].nValue = 9;
	ci[26].RcID = IDB_BITMAP27, ci[26].Color = BLOSSOM, ci[26].nValue = 9;
	ci[27].RcID = IDB_BITMAP28, ci[27].Color = DIAMOND, ci[27].nValue = 9;
	ci[28].RcID = IDB_BITMAP29, ci[28].Color = REDHEART, ci[28].nValue = 10;
	ci[29].RcID = IDB_BITMAP30, ci[29].Color = SPADE, ci[29].nValue = 10;
	ci[30].RcID = IDB_BITMAP31, ci[30].Color = BLOSSOM, ci[30].nValue = 10;
	ci[31].RcID = IDB_BITMAP32, ci[31].Color = DIAMOND, ci[31].nValue = 10;
	ci[32].RcID = IDB_BITMAP33, ci[32].Color = REDHEART, ci[32].nValue = 11;
	ci[33].RcID = IDB_BITMAP34, ci[33].Color = SPADE, ci[33].nValue = 11;
	ci[34].RcID = IDB_BITMAP35, ci[34].Color = BLOSSOM, ci[34].nValue = 11;
	ci[35].RcID = IDB_BITMAP36, ci[35].Color = DIAMOND, ci[35].nValue = 11;
	ci[36].RcID = IDB_BITMAP37, ci[36].Color = REDHEART, ci[36].nValue = 12;
	ci[37].RcID = IDB_BITMAP38, ci[37].Color = SPADE, ci[37].nValue = 12;
	ci[38].RcID = IDB_BITMAP39, ci[38].Color = BLOSSOM, ci[38].nValue = 12;
	ci[39].RcID = IDB_BITMAP40, ci[39].Color = DIAMOND, ci[39].nValue = 12;
	ci[40].RcID = IDB_BITMAP41, ci[40].Color = REDHEART, ci[40].nValue = 13;
	ci[41].RcID = IDB_BITMAP42, ci[41].Color = SPADE, ci[41].nValue = 13;
	ci[42].RcID = IDB_BITMAP43, ci[42].Color = BLOSSOM, ci[42].nValue = 13;
	ci[43].RcID = IDB_BITMAP44, ci[43].Color = DIAMOND, ci[43].nValue = 13;
	ci[44].RcID = IDB_BITMAP45, ci[44].Color = REDHEART, ci[44].nValue = 1;
	ci[45].RcID = IDB_BITMAP46, ci[45].Color = SPADE, ci[45].nValue = 1;
	ci[46].RcID = IDB_BITMAP47, ci[46].Color = BLOSSOM, ci[46].nValue = 1;
	ci[47].RcID = IDB_BITMAP48, ci[47].Color = DIAMOND, ci[47].nValue = 1;
	ci[48].RcID = IDB_BITMAP49, ci[48].Color = REDHEART, ci[48].nValue = 2;
	ci[49].RcID = IDB_BITMAP50, ci[49].Color = SPADE, ci[49].nValue = 2;
	ci[50].RcID = IDB_BITMAP51, ci[50].Color = BLOSSOM, ci[50].nValue = 2;
	ci[51].RcID = IDB_BITMAP52, ci[51].Color = DIAMOND, ci[51].nValue = 2;
	ci[52].RcID = IDB_BITMAP53, ci[52].Color = BLACKJOKER, ci[52].nValue = BLACKJOKER_VALUE;
	ci[53].RcID = IDB_BITMAP54, ci[53].Color = REDJOKER, ci[53].nValue = REDJOKER_VALUE;
}

CARD::~CARD()
{
	DeleteDC(_hdcMem);

	for (int i = 0; i < CARD_SIZE; i++)
		DeleteObject(bi[i].hbmp);

	_temp.clear();
	_Player1.clear();
	_Player2.clear();
	_Yourself.clear();
	_ChooseCard.clear();
	_ChooseCard2.clear();
	_ChooseCard3.clear();
}


void CARD::InitHinst(HWND hWnd)
{
	_hWnd = hWnd;
	_hInst = (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE);

	_Btn1 = CreateWindow(L"button", L"出牌", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		0, 0, 0, 0, _hWnd, (HMENU)BUTTON1, _hInst, NULL);

	_Btn2 = CreateWindow(L"button", L"不出", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		0, 0, 0, 0, _hWnd, (HMENU)BUTTON2, _hInst, NULL);

	_hBtn1 = CreateWindow(L"button", L"抢地主", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		0, 0, 0, 0, _hWnd, (HMENU)CHOOSE_BTN, _hInst, NULL);

	_hBtn2 = CreateWindow(L"button", L"不抢", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		0, 0, 0, 0, _hWnd, (HMENU)CHOOSE_BTN2, _hInst, NULL);
}

void CARD::ClientSize(LPARAM lParam)
{
	_cxClient = LOWORD(lParam);
	_cyClient = HIWORD(lParam);	

	if (_GetLanLoad)
	{
		if (_IsYourTurn)
		{
			MoveWindow(_hBtn1, (_cxClient - 220) / 2, _cyClient - 250,
				60, 30, TRUE);
			MoveWindow(_hBtn2, (_cxClient - 220) / 2 + 100,
				_cyClient - 250, 60, 30, TRUE);
		}
	}
	else
	{
		if (_IsYourTurn)
		{
			if (_WantLoad2)
			{
				MoveWindow(_Btn1, (_cxClient - 220) / 2, _cyClient - 250, 60, 30, TRUE);
				MoveWindow(_Btn2, (_cxClient - 220) / 2 + 100, _cyClient - 250, 60, 30, TRUE);
			}
		}
	}
}

void CARD::StartGame()
{
	_StartSwitch = TRUE;
	_PlayerTurn1 = TRUE;
	_GetLanLoad = TRUE;

	_WantLoad1 = FALSE;
	_WantLoad2 = FALSE;
	_WantLoad3 = FALSE;

	ShowCard1 = FALSE;
	ShowYourself = FALSE;
	ShowCard2 = FALSE;

	_PlayerTurn2 = FALSE;
	_IsYourTurn = FALSE;

	ShowWindow(_Btn1, SW_HIDE);
	ShowWindow(_Btn2, SW_HIDE);
	ShowWindow(_hBtn1, SW_HIDE);
	ShowWindow(_hBtn2, SW_HIDE);
}

void CARD::SetRandNum()
{
	_temp.clear();
	_Player1.clear();
	_Yourself.clear();
	_Player2.clear();
	_ChooseCard.clear();
	_ChooseCard2.clear();
	_ChooseCard3.clear();

	for (int i = 0; i < CARD_SIZE; i++)
		_temp.push_back(i);

	random_shuffle(_temp.begin(), _temp.end());

	int a[CARD_SIZE] = { 0 };	
	for (int i = 0; i < CARD_SIZE; i++)
		a[i] = _temp[i];

	sort(a, a + 17);
	sort(a + 17, a + 34);
	sort(a + 34, a + 51);
	sort(a + 51, a + 54);
	_temp.clear();

	for (int x = 0; x < CARD_SIZE; x++)
	{
		if (x < 17)
			_Player1.push_back(a[x]);
		else if (x < 34)
			_Yourself.push_back(a[x]);
		else if (x < 51)
			_Player2.push_back(a[x]);
		else
			_temp.push_back(a[x]);
	}

	InvalidateRect(_hWnd, NULL, TRUE);
}

void CARD::Paint()
{
	HDC hdc;
	PAINTSTRUCT ps;

	if (_StartSwitch)
	{
		hdc = BeginPaint(_hWnd, &ps);
		_hdcMem = CreateCompatibleDC(hdc);

		for (int i = 0; i < _Player1.size(); i++)
		{
			bi[_Player1[i]].hbmp = LoadBitmap(_hInst, MAKEINTRESOURCE(ci[_Player1[i]].RcID));  //用户1
			SelectObject(_hdcMem, bi[_Player1[i]].hbmp);

			if (_ChooseCard.size()>0)
			{				
				BitBlt(hdc, 20, (_cyClient - (_Player1.size() - 1) * 40 - CARD_HEIGTH) / 2 + 40 * i,
					CARD_WIDTH, CARD_HEIGTH, _hdcMem, 0, 0, SRCCOPY);

				if (ShowCard1)
				{
					for (int s = 0; s < _ChooseCard.size(); s++)
					{
						bi[_ChooseCard[s]].hbmp = LoadBitmap(_hInst, MAKEINTRESOURCE(ci[_ChooseCard[s]].RcID));
						SelectObject(_hdcMem, bi[_ChooseCard[s]].hbmp);

						BitBlt(hdc, CARD_WIDTH + 50 + 40 * s, (_cyClient - CARD_HEIGTH) / 2,
							CARD_WIDTH, CARD_HEIGTH, _hdcMem, 0, 0, SRCCOPY);
					}						
				}				
			}
			else
				BitBlt(hdc, 20, (_cyClient - (_Player1.size() - 1) * 40 - CARD_HEIGTH) / 2 + 40 * i,
				CARD_WIDTH, CARD_HEIGTH, _hdcMem, 0, 0, SRCCOPY);

			if (_FirstPaint)
			{
				//PlayMP3();
				Sleep(100);
			}
		}

		for (int a = 0; a < _Yourself.size(); a++)
		{
			bi[_Yourself[a]].hbmp = LoadBitmap(_hInst, MAKEINTRESOURCE(ci[_Yourself[a]].RcID));			
			SelectObject(_hdcMem, bi[_Yourself[a]].hbmp);
			
			if (_ChooseCard2.size()>0)
			{
				if (IfHasInt(_Yourself[a]))         //卡牌点击起来									
					BitBlt(hdc, (_cxClient - (_Yourself.size() - 1) * 40 - CARD_WIDTH) / 2 + 40 * a,
					_cyClient - CARD_HEIGTH - 50, CARD_WIDTH, CARD_HEIGTH, _hdcMem, 0, 0, SRCCOPY);				
				else
				{
					BitBlt(hdc, (_cxClient - (_Yourself.size() - 1) * 40 - CARD_WIDTH) / 2 + 40 * a,
						_cyClient - CARD_HEIGTH, CARD_WIDTH, CARD_HEIGTH, _hdcMem, 0, 0, SRCCOPY);

					if (ShowYourself)     //显示出牌内容
					{
						for (int w = 0; w < _ChooseCard2.size(); w++)
						{
							bi[_ChooseCard2[w]].hbmp = LoadBitmap(_hInst, MAKEINTRESOURCE(ci[_ChooseCard2[w]].RcID));
							SelectObject(_hdcMem, bi[_ChooseCard2[w]].hbmp);

							BitBlt(hdc, (_cxClient - (_ChooseCard2.size() - 1) * 50 - CARD_WIDTH) / 2 + 50 * w,
								_cyClient - 330, CARD_WIDTH, CARD_HEIGTH, _hdcMem, 0, 0, SRCCOPY);
						}
					}
				}
			}
			else
				BitBlt(hdc, (_cxClient - (_Yourself.size() - 1) * 40 - CARD_WIDTH) / 2 + 40 * a,
				_cyClient - CARD_HEIGTH, CARD_WIDTH, CARD_HEIGTH, _hdcMem, 0, 0, SRCCOPY);			

			if (_FirstPaint)
				Sleep(100);
		}

		for (int x = 0; x < _Player2.size(); x++)
		{
			bi[_Player2[x]].hbmp = LoadBitmap(_hInst, MAKEINTRESOURCE(ci[_Player2[x]].RcID));
			SelectObject(_hdcMem, bi[_Player2[x]].hbmp);

			if (_ChooseCard3.size()>0)
			{				
				BitBlt(hdc, _cxClient - CARD_WIDTH - 20, (_cyClient - (_Player2.size() - 1) * 40 -
					CARD_HEIGTH) / 2 + 40 * x, CARD_WIDTH, CARD_HEIGTH, _hdcMem, 0, 0, SRCCOPY);

				if (ShowCard2)
				{
					for (int i = 0; i < _ChooseCard3.size(); i++)
					{
						bi[_ChooseCard3[i]].hbmp = LoadBitmap(_hInst, MAKEINTRESOURCE(ci[_ChooseCard3[i]].RcID));
						SelectObject(_hdcMem, bi[_ChooseCard3[i]].hbmp);

						BitBlt(hdc, _cxClient - (_ChooseCard3.size() - 1) * 40 - 2 * CARD_WIDTH - 50 + 40 * i, (_cyClient - CARD_HEIGTH) / 2,
							CARD_WIDTH, CARD_HEIGTH, _hdcMem, 0, 0, SRCCOPY);
					}
				}				
			}
			else
				BitBlt(hdc, _cxClient - CARD_WIDTH - 20, (_cyClient - (_Player2.size() - 1) * 40 -
				CARD_HEIGTH) / 2 + 40 * x, CARD_WIDTH, CARD_HEIGTH, _hdcMem, 0, 0, SRCCOPY);

			if (_FirstPaint)
				Sleep(100);			
		}

		for (int i =0; i < _temp.size(); i++)
		{
			bi[_temp[i]].hbmp = LoadBitmap(_hInst, MAKEINTRESOURCE(ci[_temp[i]].RcID));
			SelectObject(_hdcMem, bi[_temp[i]].hbmp);

			BitBlt(hdc, (_cxClient - CARD_WIDTH * 3) / 2 + CARD_WIDTH * i,
				0, CARD_WIDTH, CARD_HEIGTH, _hdcMem, 0, 0, SRCCOPY);
		}

		_FirstPaint = FALSE;
		DeleteDC(_hdcMem);
		EndPaint(_hWnd, &ps);
	}
}

bool CARD::IfHasInt(int x)         
{
	if (_IsYourTurn)
	{
		for (int i = 0; i < _ChooseCard2.size(); i++)
		{
			if (x == _ChooseCard2[i])
				return true;
		}
	}

	return false;
}

void CARD::PlayMP3()
{
	MCI_OPEN_PARMS m_mciOpen;
	MCI_PLAY_PARMS m_mciPlay;

	m_mciOpen.lpstrDeviceType = L"mpegvideo";
	m_mciOpen.lpstrElementName = L"周杰伦+-+我不配.mp3";
	MCIERROR mcierror = mciSendCommand(0, MCI_OPEN, 
		MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&m_mciOpen);

	if (mcierror)
		return;
	else
	{
		m_mciPlay.dwCallback = (DWORD)NULL;
		m_mciPlay.dwFrom = (DWORD)0;
		mciSendCommand(m_mciOpen.wDeviceID, MCI_PLAY, 
			MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&m_mciPlay);
	}
}

void CARD::ResortVector()   //vector重新排序
{
	int x[20] = { 0 };

	if (_WantLoad1)
	{
		for (int i = 0; i < 20; i++)
			x[i] = _Player1[i];
		_Player1.clear();

		sort(x, x + 20);
		for (int i = 0; i < 20; i++)
			_Player1.push_back(x[i]);
	}

	if (_WantLoad2)
	{
		for (int i = 0; i < 20; i++)
			x[i] = _Yourself[i];
		_Yourself.clear();

		sort(x, x + 20);
		for (int i = 0; i < 20; i++)
			_Yourself.push_back(x[i]);
	}

	if (_WantLoad3)
	{
		for (int i = 0; i < 20; i++)
			x[i] = _Player2[i];
		_Player2.clear();

		sort(x, x + 20);
		for (int i = 0; i < 20; i++)
			_Player2.push_back(x[i]);
	}

	InvalidateRect(_hWnd, NULL, TRUE);
}

void CARD::JudgePlayer()    //判断玩家出牌
{
	if (_GetLanLoad)
	{
		if (_PlayerTurn1)
		{
			srand(time(0));
			_WantLoad1 = rand() % 2;
			if (_WantLoad1)
			{
				for (int i = 0; i < _temp.size(); i++)     //抢得地主
					_Player1.push_back(_temp[i]);
				ResortVector();

				ShowPlayerCard1();

				_GetLanLoad = FALSE;
				_PlayerTurn1 = FALSE;
				_IsYourTurn = TRUE;
				JudgePlayer();
			}
			else
			{
				_IsYourTurn = TRUE;
				_PlayerTurn1 = FALSE;
				MoveWindow(_hBtn1, (_cxClient - 220) / 2, _cyClient - 250,
					60, 30, TRUE);
				MoveWindow(_hBtn2, (_cxClient - 220) / 2 + 100, 
					_cyClient - 250, 60, 30, TRUE);
				ShowWindow(_hBtn1, SW_NORMAL);
				ShowWindow(_hBtn2, SW_NORMAL);
			}
		}
	}
	else
	{
		if (_IsYourTurn)
		{
			_ChooseCard2.clear();
			MoveWindow(_Btn1, (_cxClient - 220) / 2, _cyClient - 250, 60, 30, TRUE);
			MoveWindow(_Btn2, (_cxClient - 220) / 2 + 100, _cyClient - 250, 60, 30, TRUE);
			ShowWindow(_Btn1, SW_NORMAL);
			ShowWindow(_Btn2, SW_NORMAL);
			ShowYourself = FALSE;
		}
	}
}

void CARD::BtnChoose()  //抢地主
{
	if (_GetLanLoad)
	{
		_WantLoad2 = TRUE;
		_GetLanLoad = FALSE;

		for (int i = 0; i < _temp.size(); i++)
			_Yourself.push_back(_temp[i]);
		ResortVector();
		
		InvalidateRect(_hWnd, NULL, TRUE);

		ShowWindow(_hBtn1, SW_HIDE);
		ShowWindow(_hBtn2, SW_HIDE);
		MoveWindow(_Btn1, (_cxClient - 220) / 2, _cyClient - 250, 60, 30, TRUE);
		MoveWindow(_Btn2, (_cxClient - 220) / 2 + 100, _cyClient - 250, 60, 30, TRUE);
		ShowWindow(_Btn1, SW_NORMAL);
		ShowWindow(_Btn2, SW_NORMAL);
	}
}

void CARD::BtnChoose2()    //不抢
{
	if (_GetLanLoad)
	{
		_WantLoad3 = TRUE;
		_IsYourTurn = FALSE;
		_PlayerTurn2 = TRUE;
		ShowWindow(_hBtn1, SW_HIDE);
		ShowWindow(_hBtn2, SW_HIDE);

		for (int i = 0; i < _temp.size(); i++)
			_Player2.push_back(_temp[i]);
		ResortVector();

		ShowPlayerCard2();
		_GetLanLoad = FALSE;
	}
}

void CARD::OnLeftButton(LPARAM lParam)    //鼠标点击事件
{
	_cxPos = LOWORD(lParam);
	_cyPos = HIWORD(lParam);
	
	if (_IsYourTurn)
	{
		int i = 0;

		if (!_GetLanLoad)
		{					
			i = (_cxPos - (_cxClient - (_Yourself.size() - 1) * 40 - CARD_WIDTH) / 2) / 40;
			if (i >= 0)
			{
				if (_cxPos < (_cxClient - (_Yourself.size() - 1) * 40 - CARD_WIDTH) / 2 + (_Yourself.size() - 1) * 40 + CARD_WIDTH)
				{
					if (i>_Yourself.size() - 1)
						i = _Yourself.size() - 1;

					if (_ChooseCard2.size() > 0)
					{						
						if (!IfHasInt(_Yourself[i]))
						{
							if (_cyPos > _cyClient - CARD_HEIGTH&&_cyPos<_cyClient)							
								_ChooseCard2.push_back(_Yourself[i]);							
						}
						else
						{
							if (_cyPos > _cyClient - CARD_HEIGTH - 50 && _cyPos < _cyClient - 50)
							{
								for (int x = 0; x < _ChooseCard2.size(); x++)
								{
									if (_ChooseCard2[x] == _Yourself[i])
										_ChooseCard2.erase(_ChooseCard2.begin() + x);									
								}
							}
						}
					}
					else
					{
						if (_cyPos > _cyClient - CARD_HEIGTH&&_cyPos < _cyClient)
							_ChooseCard2.push_back(_Yourself[i]);
					}	

					InvalidateRect(_hWnd, NULL, TRUE);
				}
			}			
		}
	}
}

void CARD::BtnMsg()       //出牌
{
	ShowWindow(_Btn1, SW_HIDE);
	ShowWindow(_Btn2, SW_HIDE);

	ShowYourself = TRUE;
	_IsYourTurn = FALSE;
	_PlayerTurn2 = TRUE;

	for (int i = 0; i < _ChooseCard2.size(); i++)          //删除出出去的牌
	{
		for (int a = 0; a < _Yourself.size(); a++)
		{
			if (_ChooseCard2[i] == _Yourself[a])
				_Yourself.erase(_Yourself.begin() + a);
		}
	}
	InvalidateRect(_hWnd, NULL, TRUE);

	ShowPlayerCard2();
	ShowPlayerCard1();
	JudgePlayer();
}

void CARD::BtnMsg2()   //不出
{
	_IsYourTurn = FALSE;
	_PlayerTurn2 = TRUE;

	ShowPlayerCard2();
	ShowPlayerCard1();
	JudgePlayer();
}

void CARD::JudgeCardType(vector<int>Vec)
{
	if (Vec.size() == 1)
	{
		_CardOpt = SINGLE_CARD;
	}
	else if (Vec.size() == 2)
	{
		if (ci[Vec[0]].nValue == BLACKJOKER&&ci[Vec[1]].nValue == REDJOKER)
			_CardOpt = JOCKER_BOMB;
		else
			_CardOpt = DOUBLE_CARD;

	}
	else if (Vec.size() == 3)
	{
		_CardOpt = THREE_CARD;
	}
	else
	{
		int a = 0;
		for (int i = 0; i < Vec.size() - 1; i++)
		{
			if (ci[Vec[i]].nValue == ci[Vec[i + 1]].nValue)
				a++;
		}

		if (Vec.size() == 4)
		{
			if (a == 3)
				_CardOpt = BOMB_CARD;   //炸弹
			else if (a == 2)
				_CardOpt = FOUR_CARD;   //三带一
		}
		else if (Vec.size() == 5)
		{
			if (a == 0)
				_CardOpt = STRAIGHT_FIVE;  //五顺子
			else if (a == 3)
				_CardOpt = THREE_DOUBLE;   //三带一对
		}
		else if (Vec.size() == 6)
		{
			if (a == 0)
				_CardOpt = STRAIGHT_SIX;    //六顺子
			else if (a == 3)
				_CardOpt = THREE_COUPLE;      //三连对
			else if (a == 4)
				_CardOpt = PLANE_CARD;       //飞机
		}
		else if (Vec.size() == 7)
		{
			if (a == 0)
				_CardOpt = STRAIGHT_SEVEN;    //七顺子
		}
		else if (Vec.size() == 8)
		{
			if (a == 0)
				_CardOpt = STRAIGHT_EIGHT;    //八顺子
			else if (a == 4)
				_CardOpt = FOUR_COUPLE;       //四连对
			else
				_CardOpt = PLANE_SINGLE;    //飞机带两个
		}
		else if (Vec.size() == 9)
		{
			if (a == 0)
				_CardOpt = STRAIGHT_NINE;   //九顺子
		}
		else if (Vec.size() == 10)
		{
			if (a == 0)
				_CardOpt = STRAIGHT_TEN;   //十顺子
			else if (a == 5)
				_CardOpt = FIVE_COUPLE;      //五连对
			else
				_CardOpt = PLANE_DOUBLE;    //飞机带两对
		}
		else if (Vec.size() == 11)
		{
			if (a == 0)
				_CardOpt = STRAIGHT_ELEVEN;    //十一顺子
		}
		else if (Vec.size() == 12)
		{
			if (a == 0)
				_CardOpt = STRAIGHT_TWELVE;    //十二顺子
			else if (a == 6)
				_CardOpt = SIX_COUPLE;         //六连对
			else
				_CardOpt = PLANE_THREE_SINGLE;       //三飞机带三个
		}
		else if (Vec.size() == 15)
		{
			_CardOpt = PLANE_THREE_DOUBLE;         //三飞机带三对
		}
		else if (Vec.size() == 16)
		{
			if (a == 8)
				_CardOpt = EIGHT_COUPLE;
			else
				_CardOpt = PLANE_FOUR_SINGLE;
		}
		else if (Vec.size() == 18)
			_CardOpt = NINE_COUPLE;
		else if (Vec.size() == 20)
		{
			if (a == 10)
				_CardOpt = TEN_COUPLE;
			else
				_CardOpt = PLANE_FOUR_DOUBLE;
		}
	}
}

void CARD::ShowPlayerCard1()
{
	if (_GetLanLoad)
	{
		if (_WantLoad1)
		{
			for (int i = 0; i < _Player1.size() - 3; i++)
			{
				if (ci[_Player1[i]].nValue == ci[_Player1[i + 1]].nValue)
				{
					if (ci[_Player1[i]].nValue == ci[_Player1[i + 2]].nValue)
					{
						if (ci[_Player1[i]].nValue == ci[_Player1[i + 3]].nValue)
						{
							i = i + 3;
						}
						else
						{							
							for (int a = 0; a < 3; a++)
							{
								_ChooseCard.push_back(_Player1[i]);
								_Player1.erase(_Player1.begin() + i);
							}

							for (int q = 0; q < _Player1.size() - 1; q++)
							{
								if (q == 0)
								{
									if (ci[_Player1[q]].nValue != ci[_Player1[q + 1]].nValue)
									{
										_ChooseCard.push_back(_Player1[q]);
										_Player1.erase(_Player1.begin() + q);
										break;
									}
								}
								else
								{
									if (ci[_Player1[q]].nValue != ci[_Player1[q + 1]].nValue
										&&ci[_Player1[q]].nValue != ci[_Player1[q - 1]].nValue)
									{
										_ChooseCard.push_back(_Player1[q]);
										_Player1.erase(_Player1.begin() + q);
										break;
									}
								}
							}
						}
					}
					else
					{
						for (int r = 0; r < 2; r++)
						{
							_ChooseCard.push_back(_Player1[i]);
							_Player1.erase(_Player1.begin() + i);
						}
						break;
					}
				}
				else
				{
					_ChooseCard.push_back(_Player1[i]);
					_Player1.erase(_Player1.begin() + i);
					break;
				}
				break;
			}
		}
	}
	else
	{
		_ChooseCard.clear();

		if (_ChooseCard3.size() > 0)
			JudgeCardType(_ChooseCard3);
		else if (_ChooseCard2.size() > 0)
			JudgeCardType(_ChooseCard2);
		

		if (_ChooseCard3.size())
		if (_CardOpt == SINGLE_CARD)
		{
			for (int i = 0; i < _Player1.size() - 1; i++)
			{				
				if (i == 0)
				{
					if (ci[_Player1[i]].nValue != ci[_Player1[i + 1]].nValue)
					{
						_ChooseCard.push_back(_Player1[i]);
						_Player1.erase(_Player1.begin() + i);
						break;
					}
				}
				else
				{
					if (ci[_Player1[i]].nValue != ci[_Player1[i + 1]].nValue
						&&ci[_Player1[i]].nValue != ci[_Player1[i - 1]].nValue)
					{
						_ChooseCard.push_back(_Player1[i]);
						_Player1.erase(_Player1.begin() + i);
						break;
					}
				}				
			}
		}
		else if (_CardOpt == DOUBLE_CARD)
		{
			for (int a = 0; a < _Player1.size() - 2; a++)
			{									
				if (ci[_Player1[a]].nValue == ci[_Player1[a + 1]].nValue
					&&ci[_Player1[a]].nValue != ci[_Player1[a + 2]].nValue)
				{
					for (int x = 0; x < 2; x++)
					{
						_ChooseCard.push_back(_Player1[a]);
						_Player1.erase(_Player1.begin() + a);
					}
					break;
				}			
			}
		}
		else if (_CardOpt == THREE_CARD)
		{


		}
		else if (FOUR_CARD)
		{


		}



	}

	ShowCard1 = TRUE;
	_IsYourTurn = TRUE;
	_PlayerTurn1 = FALSE;
	InvalidateRect(_hWnd, NULL, TRUE);
}

void CARD::ShowPlayerCard2()
{
	if (_GetLanLoad)
	{
		if (_WantLoad3)        //地主是玩家2
		{
			for (int i = 0; i < _Player2.size(); i++)
			{
				if (ci[_Player2[i]].nValue == 3)
					_ChooseCard3.push_back(_Player2[i]);
			}

			for (int a = 0; a < _ChooseCard3.size(); a++)
			{
				for (int i = 0; i < _Player2.size(); i++)
				{
					if (_ChooseCard3[a] == _Player2[i])
						_Player2.erase(_Player2.begin() + i);
				}
			}
		}
	}
	else
	{
		_ChooseCard3.clear();

		if (_ChooseCard2.size()>0)
			JudgeCardType(_ChooseCard2);
		else if (_ChooseCard.size()>0)
			JudgeCardType(_ChooseCard);

		if (_CardOpt == SINGLE_CARD)
		{
			for (int i = 0; i < _Player2.size() - 1; i++)
			{
				if (ci[_Player2[i]].nValue>ci[_ChooseCard2[0]].nValue)
				{
					if (ci[_Player2[i]].nValue != ci[_Player2[i + 1]].nValue
						&&ci[_Player2[i]].nValue != ci[_Player2[i - 1]].nValue)
					{
						_ChooseCard3.push_back(_Player2[i]);
						_Player2.erase(_Player2.begin() + i);
						break;
					}
				}
			}
		}
		else if (_CardOpt == DOUBLE_CARD)
		{
			for (int i = 0; i < _Player2.size() - 3; i++)
			{
				if (ci[_Player2[i]].nValue>ci[_ChooseCard2[0]].nValue)
				{
					if (ci[_Player2[i]].nValue == ci[_Player2[i + 1]].nValue)
					{
						if (ci[_Player2[i]].nValue == ci[_Player2[i + 2]].nValue)
						{
							if (ci[_Player2[i]].nValue == ci[_Player2[i + 3]].nValue)
							{
								i = i + 3;
							}
							else
							{
								i = i + 2;
							}
						}
						else
						{								
							for (int a = 0; a < 2; a++)
							{
								_ChooseCard3.push_back(_Player2[i]);
								_Player2.erase(_Player2.begin() + i);
							}
							break;
						}
					}
				}
			}
		}
		else if (_CardOpt == THREE_CARD)
		{
			for (int i = 0; i < _Player2.size() - 3; i++)
			{
				if (ci[_Player2[i]].nValue == ci[_Player2[i + 1]].nValue)
				{
					if (ci[_Player2[i]].nValue == ci[_Player2[i + 2]].nValue)
					{
						if (ci[_Player2[i]].nValue == ci[_Player2[i + 3]].nValue)
						{
							i = i + 3;
						}
						else
						{								
							for (int a = 0; a < 3; a++)
							{
								_ChooseCard3.push_back(_Player2[i]);
								_Player2.erase(_Player2.begin() + i);
							}
						}
					}
				}
			}
		}
		else if (_CardOpt == FOUR_CARD)
		{
			for (int i = 0; i < _Player2.size() - 3; i++)
			{
				if (ci[_Player2[i]].nValue>ci[_ChooseCard2[0]].nValue)
				{
					if (ci[_Player2[i]].nValue == ci[_Player2[i + 1]].nValue)
					{
						if (ci[_Player2[i]].nValue == ci[_Player2[i + 2]].nValue)
						{
							if (ci[_Player2[i]].nValue == ci[_Player2[i + 3]].nValue)
							{
								i = i + 3;
							}
							else
							{									
								for (int a = 0; a < 3; a++)     //三个同样的牌
								{
									_ChooseCard3.push_back(_Player2[i]);
									_Player2.erase(_Player2.begin() + i);
								}

								for (int w = 0; w < _Player2.size() - 1; w++)    //单张
								{
									if (w == 0)
									{
										if (ci[_Player2[w]].nValue != ci[_Player2[w + 1]].nValue)
										{
											_ChooseCard3.push_back(_Player2[w]);
											_Player2.erase(_Player2.begin() + w);
											break;
										}
									}
									else
									{
										if (ci[_Player2[w]].nValue != ci[_Player2[w + 1]].nValue
											&&ci[_Player2[w]].nValue != ci[_Player2[w - 1]].nValue)
										{
											_ChooseCard3.push_back(_Player2[w]);
											_Player2.erase(_Player2.begin() + w);
											break;
										}

									}
								}
							}
						}
					}
				}
			}

		}
		
	}

	ShowCard2 = TRUE;
	_PlayerTurn1 = TRUE;
	_PlayerTurn2 = FALSE;
	InvalidateRect(_hWnd, NULL, TRUE);
}











































