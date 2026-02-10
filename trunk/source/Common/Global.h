#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <stdint.h>

#include <vector>
#include <list>

#if defined (_WIN32)

#include <atlbase.h>
#include <WinUser.h>
#include <WinDef.h>
#include <WinNT.h>

#define WM_THREAD_INFO		WM_USER + 1 // �̷߳�����Ϣ
#define WP_WORKING			WM_USER + 2 // ��ʼ����
#define WP_FINISHED			WM_USER + 3 // �߳����
#define WP_STOPPED			WM_USER + 4 // �߳�ֹͣ(δ���)
#define WP_REFRESH_TEXT		WM_USER + 5 // ˢ���ı���
#define WP_PROG				WM_USER + 6 // �ļ�������
#define WP_PROG_WHOLE		WM_USER + 7 // ȫ�ֽ�����

#define WM_CUSTOM_MSG		WM_USER + 16 // �Զ�����Ϣ
#define WM_HYPEREDIT_MENU	WM_USER + 17 // HyperEdit �����˵���Ϣ

#else

#define WINAPI

#endif

#include "Common/strhelper.h"

class UIBridgeBase;

struct ResultData;

typedef std::vector<sunjwbase::tstring> TStrVector;
typedef std::vector<uint64_t> ULLongVector;
typedef std::list<ResultData> ResultList;

#define MAX_FILES_NUM 8192

enum ResultState
{
	RESULT_NONE = 0,
	RESULT_PATH,
	RESULT_META,
	RESULT_ALL,
	RESULT_ERROR
};

struct ResultData // ������
{
	ResultState enumState; // State
	sunjwbase::tstring tstrPath; // ·��
	uint64_t ulSize; // ��С
	sunjwbase::tstring tstrMDate; // �޸�����
	sunjwbase::tstring tstrVersion; // �汾
	sunjwbase::tstring tstrMD5; // MD5
	sunjwbase::tstring tstrSHA1; // SHA1
	sunjwbase::tstring tstrSHA256; // SHA256
	sunjwbase::tstring tstrSHA512; // SHA512
	sunjwbase::tstring tstrError; // Error string
};

struct ThreadData // ��������̵߳���Ϣ
{
	UIBridgeBase *uiBridge;

	bool threadWorking; // �߳��Ƿ��ڹ���
	bool stop; // ������Ҫ��ֹͣ����
	bool pause; // pause calculation

	bool uppercase; // �Ƿ��д
	uint64_t totalSize; // �����ļ���С

	uint32_t nFiles; // �ļ�����
	TStrVector fullPaths; // ������������ļ�·��

	ResultList resultList;
};

#endif
