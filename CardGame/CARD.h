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
	SINGLE_CARD = 10,    //单张
	THREE_CARD,          //三个不带
	FOUR_CARD,           //三带一
	THREE_DOUBLE,        //三带二
	BOMB_CARD,           //炸弹
	JOCKER_BOMB,         //王炸
	DOUBLE_CARD,         //一对
	THREE_COUPLE,        //三连对
	FOUR_COUPLE,         //四连对
	FIVE_COUPLE,         //五连对
	SIX_COUPLE,          //六连对
	SEVEN_COUPLE,        //七连对
	EIGHT_COUPLE,        //八连对
	NINE_COUPLE,         //九连对
	TEN_COUPLE,          //十连对
	PLANE_CARD,          //飞机不带
	PLANE_SINGLE,        //飞机带两个
	PLANE_DOUBLE,        //飞机带一对
	PLANE_THREE_NONE,    //三飞机不带
	PLANE_THREE_SINGLE,  //三飞机带三个
	PLANE_THREE_DOUBLE,  //三飞机带三对
	PLANE_FOUR_SINGLE,   //四飞机带四个
	PLANE_FOUR_DOUBLE,   //四飞机带四对
	STRAIGHT_FIVE,       //五顺子
	STRAIGHT_SIX,        //六顺子
	STRAIGHT_SEVEN,      //七顺子
	STRAIGHT_EIGHT,      //八顺子
	STRAIGHT_NINE,       //九顺子
	STRAIGHT_TEN,        //十顺子
	STRAIGHT_ELEVEN,     //十一顺子
	STRAIGHT_TWELVE      //十二顺子
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

	//开始发牌
	BOOL _FirstPaint;
	BOOL _StartSwitch;

	//到谁出牌
	BOOL _IsYourTurn;
	BOOL _PlayerTurn1;
	BOOL _PlayerTurn2;
		
	//抢地主
	BOOL _GetLanLoad;
	BOOL _WantLoad1;
	BOOL _WantLoad2;
	BOOL _WantLoad3;

	//显示出的牌
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



