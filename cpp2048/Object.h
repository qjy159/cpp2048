#pragma once

class CTexture;

// ���� ���ӿ�����Ʈ�� �� Ŭ������ ����Ͽ� �����.
// update �Լ��� �� �����Ӹ��� ���� ��ȭ���� ����Ѵ�.
// render �Լ��� �� �����Ӹ��� ���� ���� �ڽ��� �׸���.
class CObject
{
protected:
	Vec2		m_vPos;
	Vec2		m_vScale;
	CTexture*	m_pTex;

public:
	// �ʱ�ȭ �Լ� �ʿ��ϸ� �������̵��Ͽ� ����
	virtual void init() {}
	// update �Լ��� �ݵ�� �������̵� �ؾ���(���������Լ�)
	virtual int update() = 0;
	// render �Լ��� �׷��� �� �ؽ��İ� �ִ� ������Ʈ�� �������̵� �Ͽ� ����
	virtual void render(HDC _dc);

public:
	const Vec2& GetPos() { return m_vPos; }
	const Vec2& GetScale() { return m_vScale; }
	void SetPos(const Vec2& _vPos) { m_vPos = _vPos; }
	void SetScale(const Vec2& _vScale) { m_vScale = _vScale; }

	virtual void SetTexture(CTexture* _pTex) { m_pTex = _pTex; }
	virtual CTexture* GetTexture() { return m_pTex; }

public:
	CObject();
	virtual ~CObject();
};
