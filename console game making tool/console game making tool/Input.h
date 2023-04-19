#pragma once
#include <conio.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <Windows.h>

using namespace std::chrono;

#define aChar 97
#define AChar 65
#define bChar 98
#define BChar 66
#define cChar 99
#define CChar 67
#define dChar 100
#define DChar 68
#define eChar 101
#define EChar 69
#define fChar 102
#define FChar 70
#define gChar 103
#define GChar 71
#define hChar 104
#define HChar 72
#define iChar 105
#define IChar 73
#define jChar 106
#define JChar 74
#define kChar 107
#define KChar 75
#define lChar 108
#define LChar 76
#define mChar 109
#define MChar 77
#define nChar 110
#define NChar 78
#define oChar 111
#define OChar 79
#define pChar 112
#define PChar 80
#define qChar 113
#define QChar 81
#define rChar 114
#define RChar 82
#define sChar 115
#define SChar 83
#define tChar 116
#define TChar 84
#define uChar 117
#define UChar 85
#define vChar 118
#define VChar 86
#define wChar 119
#define WChar 87
#define xChar 120
#define XChar 88
#define yChar 121
#define YChar 89
#define zChar 122
#define ZChar 90

#define ZeroChar 48
#define OneChar 49
#define TwoChar 50
#define ThreeChar 51
#define FourChar 52
#define FiveChar 53
#define SixChar 54
#define SevenChar 55
#define EightChar 56
#define NineChar 57

#define ExclamationChar 33
#define AtChar 64
#define HashTagChar 35
#define DollarChar 36
#define PercentChar 37
#define PowerChar 94
#define AmpersandChar 38
#define AsteriskChar 42
#define OpeningBracketChar 40
#define ClosingBracketChar 41
#define DownSmallLineChar 92
#define WigglyLineChar 126
#define MinusChar 45
#define UnderScoreChar 95
#define EqualsChar 61
#define PlusChar 43
#define OpeningSquareBracketChar 91
#define EndingSquareBracketChar 93
#define OpeningCurlyBracketChar 123
#define ClosingCurlyBracketChar 125
#define BackSlashChar 92
#define StraightLineChar 124
#define SemiColonChar 59
#define ColonChar 58
#define SingleQuoteChar 39
#define DoubleQuoteChar 34
#define CommaChar 44
#define SmallerThanChar 60
#define BiggerThanChar 62
#define PeriodChar 46
#define SlashChar 47
#define QuestionMarkChar 63

#define Tab 9
#define Backspace 8
#define Esc 27
#define RightArrow 77
#define LeftArrow 75
#define UpArrow 72
#define DownArrow 80
#define Enter 13


class InputManager {
public:
	InputManager();
	~InputManager();
	void Update();
	int GetInputValue() {
		return ASCIIvalue;
	}
	int GetInputValue(DWORD sleepTime) {
		Sleep(sleepTime);
		return ASCIIvalue;
	}
	void reset()
	{
		ASCIIvalue = NULL;
	}
private:
	int ASCIIvalue;
};