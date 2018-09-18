#pragma once
#include<windows.h>
#include<time.h>
#include<algorithm>
#include<vector>
#include<mmsystem.h>
#include <Digitalv.h>
#include"resource.h"
#pragma comment(lib,"winmm.lib")
using namespace std;

#define CARD_SIZE 54
#define BLACKJOKER_VALUE 99
#define REDJOKER_VALUE 100

#define BUTTON1 200
#define BUTTON2 201
#define CHOOSE_BTN 202
#define CHOOSE_BTN2 203
#define STATIC_TEXT 204

#define CARD_WIDTH 105
#define CARD_HEIGTH 150

enum CardColor
{
	REDHEART = 1, SPADE, BLOSSOM, DIAMOND, BLACKJOKER, REDJOKER
};

enum CardNum
{
	SINGLE_CARD = 10,    //����
	THREE_CARD,          //��������
	FOUR_CARD,           //����һ
	THREE_DOUBLE,        //������
	BOMB_CARD,           //ը��
	JOCKER_BOMB,         //��ը
	DOUBLE_CARD,         //һ��
	THREE_COUPLE,        //������
	FOUR_COUPLE,         //������
	FIVE_COUPLE,         //������
	SIX_COUPLE,          //������
	SEVEN_COUPLE,        //������
	EIGHT_COUPLE,        //������
	NINE_COUPLE,         //������
	TEN_COUPLE,          //ʮ����
	PLANE_CARD,          //�ɻ�����
	PLANE_SINGLE,        //�ɻ�������
	PLANE_DOUBLE,        //�ɻ���һ��
	PLANE_THREE_NONE,    //���ɻ�����
	PLANE_THREE_SINGLE,  //���ɻ�������
	PLANE_THREE_DOUBLE,  //���ɻ�������
	PLANE_FOUR_SINGLE,   //�ķɻ����ĸ�
	PLANE_FOUR_DOUBLE,   //�ķɻ����Ķ�
	STRAIGHT_FIVE,       //��˳��
	STRAIGHT_SIX,        //��˳��
	STRAIGHT_SEVEN,      //��˳��
	STRAIGHT_EIGHT,      //��˳��
	STRAIGHT_NINE,       //��˳��
	STRAIGHT_TEN,        //ʮ˳��
	STRAIGHT_ELEVEN,     //ʮһ˳��
	STRAIGHT_TWELVE      //ʮ��˳��
};

enum Option
{
	GIVECARD = 50
};

struct BmpInfo
{
	HBITMAP hbmp;
};

struct CardInfo
{
	int RcID;
	int Color;
	int nValue;
};

class CARD
{
private:
	vector<int>_temp;
	vector<int>_Player1;	
	vector<int>_Player2;
	vector<int>_Yourself;
	vector<int>_ChooseCard;
	vector<int>_ChooseCard2;
	vector<int>_ChooseCard3;
	BmpInfo bi[CARD_SIZE];
	CardInfo ci[CARD_SIZE];
			
	HWND _hWnd;
	HDC _hdcMem;
	HWND _Btn1, _Btn2;
	HWND _hBtn1, _hBtn2;
	
	HINSTANCE _hInst;

	//��ʼ����
	BOOL _FirstPaint;
	BOOL _StartSwitch;

	//��˭����
	BOOL _IsYourTurn;
	BOOL _PlayerTurn1;
	BOOL _PlayerTurn2;
		
	//������
	BOOL _GetLanLoad;
	BOOL _WantLoad1;
	BOOL _WantLoad2;
	BOOL _WantLoad3;

	//��ʾ������
	BOOL ShowCard1;
	BOOL ShowYourself;
	BOOL ShowCard2;
	
	int _CardOpt;
	int _cxPos, _cyPos;
	int _cxClient, _cyClient;

public:
	CARD();
	~CARD();
	void StartGame();
	void InitHinst(HWND hWnd);
	void ClientSize(LPARAM lParam);
	
	void SetRandNum();
	void PlayMP3();
	void Paint();
	void JudgePlayer();

	void BtnMsg();
	void BtnMsg2();
	void BtnChoose();
	void BtnChoose2();
	void ResortVector();

	bool IfHasInt(int x);
	void JudgeCardType(vector<int>Vec);
	void ShowPlayerCard1();
	void ShowPlayerCard2();
	
	void OnLeftButton(LPARAM lParam);
};



