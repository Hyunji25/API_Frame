#pragma once

extern HWND g_hWnd;

const int COUNT = 128;

#define WIDTH 1500
#define HEIGHT 900

const int KEYID_UP = 0x00000001;
const int KEYID_DOWN = 0x00000002;
const int KEYID_LEFT = 0x00000004;
const int KEYID_RIGHT = 0x00000008;
const int KEYID_RETURN = 0x00000010;
const int KEYID_SPACE = 0x00000020;
const int KEYID_ESCAPE = 0x00000040;
const int KEYID_CONTROL = 0x00000080;

const int STATEID_HIT = 0x00000001;
const int STATEID_ATTACK = 0x00000002;
const int STATEID_JUMP = 0x00000004;