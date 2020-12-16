#pragma once

#define PI 3.141592

//===============================================================
// 싱글톤 클래스 생성 ver.1
//===============================================================
#define SINGLE(className) public: \
						  static className* GetInst() \
						  {\
							  static className mgr;\
							  return &mgr;\
						  }\
						  private:\
							  className();\
							  ~className();

//===============================================================
// 싱글톤 클래스 생성 ver.2
// 프로그램 종료시 싱글톤 클래스 삭제 순서 충돌이 일어날 경우
// ver2를 적용하여 삭제 순서를 정해줄 수 있음
//===============================================================
#define SINGLE_DYNAMIC(className) private:\
									  static className*	m_pThis;\
								  public:\
									  static className* GetInst()\
									  {\
										  if (nullptr == m_pThis)\
											  m_pThis = new className;\
										  return m_pThis;\
									  }\
									  static void Destroy()\
									  {\
										  SAFE_DELETE(m_pThis);\
									  }\
								  private:\
									  className();\
									  ~className();

#define SINGLE_DYNAMIC_INIT(className) className* className::m_pThis = nullptr; // 스태틱 멤버로 생성하기때문에 cpp에서 초기화를 해주어야 함

//===================================
// 다수의 포인터를 일괄 삭제 처리 할 때
//===================================
#define SAFE_DELETE(p) if(nullptr != p) {delete p; p = nullptr;}

//============================================
// 1프레임시간(DeltaTime)을 얻어 올 수 있는 함수
//============================================
#define DT CTimeMgr::GetInst()->DeltaTime()

//=============================
// 키 입력을 확인 할 수 있다.
// 사용예시
// KEYHOLD(KEY_TYPE::KEY_SPACE)
//=============================
#define KEYHOLD(type) CKeyMgr::GetInst()->GetKeyState(type, KEY_STATE::HOLD) // 전 프레임에 이어 키를 계속 누르고 있는지
#define KEYAWAY(type) CKeyMgr::GetInst()->GetKeyState(type, KEY_STATE::AWAY) // 이번 프레임에 키를 뗐는지
#define KEYTAB(type) CKeyMgr::GetInst()->GetKeyState(type, KEY_STATE::TAB)   // 이번 프레임에 처음 눌렀는지
#define KEYNONE(type) CKeyMgr::GetInst()->GetKeyState(type, KEY_STATE::NONE) // 안누르고 있는지

enum class KEY_STATE
{
	TAB,	// 최초 눌린 시점
	HOLD,   // 누르고 있는 중
	AWAY,   // 키를 막 뗀 시점
	NONE,   // 안눌림	
};

enum class KEY_TYPE
{
	KEY_1 = 0,
	KEY_2,
	KEY_3,
	KEY_4,
	KEY_5,
	KEY_6,
	KEY_7,
	KEY_8,
	KEY_9,
	KEY_0,
	KEY_Q,
	KEY_W,
	KEY_E,
	KEY_R,
	KEY_T,
	KEY_Y,
	KEY_U,
	KEY_I,
	KEY_O,
	KEY_P,
	KEY_A,
	KEY_S,
	KEY_D,
	KEY_F,
	KEY_G,
	KEY_H,
	KEY_J,
	KEY_K,
	KEY_L,
	KEY_Z,
	KEY_X,
	KEY_C,
	KEY_V,
	KEY_B,
	KEY_N,
	KEY_M,
	KEY_F1,
	KEY_F2,
	KEY_F3,
	KEY_F4,
	KEY_F5,
	KEY_F6,
	KEY_F7,
	KEY_F8,
	KEY_F9,
	KEY_F10,
	KEY_F11,
	KEY_F12,
	KEY_CTRL,
	KEY_ALT,
	KEY_LSHIFT,
	KEY_RSHIFT,
	KEY_TAB,
	KEY_CAP,
	KEY_ENTER,
	KEY_ESC,
	KEY_SPACE,
	KEY_UP,
	KEY_DOWN,
	KEY_LEFT,
	KEY_RIGHT,
	KEY_NUM1,
	KEY_NUM2,
	KEY_NUM3,
	KEY_NUM4,
	KEY_NUM5,
	KEY_NUM6,
	KEY_NUM7,
	KEY_NUM8,
	KEY_NUM9,
	KEY_NUM0,
	KEY_LBTN,
	KEY_RBTN,
	KEY_BACKSPACE,
	END,
};


enum class OBJ_LAYER
{
	BACKGROUND = 0,
	TILE,
	UI,
	END
};

enum class SCENE_TYPE
{
	START,
	MAIN,
	SCORE,
	END
};