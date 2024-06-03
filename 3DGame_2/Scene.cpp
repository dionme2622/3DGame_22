#include "stdafx.h"
#include "Scene.h"
#include "GraphicsPipeline.h"

CScene::CScene(CPlayer* pPlayer)
{
	m_pPlayer = pPlayer;
}

CScene::~CScene()
{
}

void CScene::BuildObjects()
{
	CExplosiveObject::PrepareExplosion();

	float fHalfWidth = 45.0f, fHalfHeight = 45.0f, fHalfDepth = 200.0f;
	CWallMesh* pWallCubeMesh = new CWallMesh(fHalfWidth * 2.0f, fHalfHeight * 2.0f, fHalfDepth * 2.0f, 30);

	m_pWallsObject = new CWallsObject();
	m_pWallsObject->SetPosition(0.0f, 0.0f, 0.0f);
	m_pWallsObject->SetMesh(pWallCubeMesh);
	m_pWallsObject->SetColor(RGB(0, 0, 0));
	m_pWallsObject->m_pxmf4WallPlanes[0] = XMFLOAT4(+1.0f, 0.0f, 0.0f, fHalfWidth);
	m_pWallsObject->m_pxmf4WallPlanes[1] = XMFLOAT4(-1.0f, 0.0f, 0.0f, fHalfWidth);
	m_pWallsObject->m_pxmf4WallPlanes[2] = XMFLOAT4(0.0f, +1.0f, 0.0f, fHalfHeight);
	m_pWallsObject->m_pxmf4WallPlanes[3] = XMFLOAT4(0.0f, -1.0f, 0.0f, fHalfHeight);
	m_pWallsObject->m_pxmf4WallPlanes[4] = XMFLOAT4(0.0f, 0.0f, +1.0f, fHalfDepth);
	m_pWallsObject->m_pxmf4WallPlanes[5] = XMFLOAT4(0.0f, 0.0f, -1.0f, fHalfDepth);
	m_pWallsObject->m_xmOOBBPlayerMoveCheck = BoundingOrientedBox(XMFLOAT3(0.0f, 0.0f, 0.0f), XMFLOAT3(fHalfWidth, fHalfHeight, fHalfDepth * 0.05f), XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f));

	CCubeMesh* pCubeMesh = new CCubeMesh(5.0f, 5.0f, 5.0f);

	m_nObjects = 10;
	m_ppObjects = new CEnemyObject * [m_nObjects];

	CEnemyObject* pEnemyObject = new CEnemyObject(m_pPlayer);
	pEnemyObject ->SetMesh(pCubeMesh);
	pEnemyObject ->SetColor(RGB(255, 0, 0));
	pEnemyObject ->SetPosition(-13.5f, 0.0f, -14.0f);
	pEnemyObject ->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 1.0f));
	pEnemyObject ->SetRotationSpeed(90.0f);
	pEnemyObject ->SetMovingDirection(XMFLOAT3(1.0f, 0.0f, 0.0f));
	pEnemyObject ->SetMovingSpeed(10.5f);
	m_ppObjects[0] = pEnemyObject;

	pEnemyObject = new CEnemyObject(m_pPlayer);
	pEnemyObject->SetMesh(pCubeMesh);
	pEnemyObject->SetColor(RGB(0, 0, 255));
	pEnemyObject->SetPosition(+13.5f, 0.0f, -14.0f);
	pEnemyObject->SetRotationAxis(XMFLOAT3(1.0f, 1.0f, 0.0f));
	pEnemyObject->SetRotationSpeed(180.0f);
	pEnemyObject->SetMovingDirection(XMFLOAT3(-1.0f, 0.0f, 0.0f));
	pEnemyObject->SetMovingSpeed(8.8f);
	m_ppObjects[1] = pEnemyObject;

	pEnemyObject = new CEnemyObject(m_pPlayer);
	pEnemyObject->SetMesh(pCubeMesh);
	pEnemyObject->SetColor(RGB(0, 255, 0));
	pEnemyObject->SetPosition(0.0f, +5.0f, 20.0f);
	pEnemyObject->SetRotationAxis(XMFLOAT3(1.0f, 1.0f, 0.0f));
	pEnemyObject->SetRotationSpeed(30.15f);
	pEnemyObject->SetMovingDirection(XMFLOAT3(1.0f, -1.0f, 0.0f));
	pEnemyObject->SetMovingSpeed(5.2f);
	m_ppObjects[2] = pEnemyObject;

	pEnemyObject = new CEnemyObject(m_pPlayer);
	pEnemyObject->SetMesh(pCubeMesh);
	pEnemyObject->SetColor(RGB(0, 255, 255));
	pEnemyObject->SetPosition(0.0f, 0.0f, 0.0f);
	pEnemyObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 1.0f));
	pEnemyObject->SetRotationSpeed(40.6f);
	pEnemyObject->SetMovingDirection(XMFLOAT3(0.0f, 0.0f, 1.0f));
	pEnemyObject->SetMovingSpeed(20.4f);
	m_ppObjects[3] = pEnemyObject;

	pEnemyObject = new CEnemyObject(m_pPlayer);
	pEnemyObject->SetMesh(pCubeMesh);
	pEnemyObject->SetColor(RGB(128, 0, 255));
	pEnemyObject->SetPosition(10.0f, 0.0f, 0.0f);
	pEnemyObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pEnemyObject->SetRotationSpeed(50.06f);
	pEnemyObject->SetMovingDirection(XMFLOAT3(0.0f, 1.0f, 1.0f));
	pEnemyObject->SetMovingSpeed(6.4f);
	m_ppObjects[4] = pEnemyObject;

	pEnemyObject = new CEnemyObject(m_pPlayer);
	pEnemyObject->SetMesh(pCubeMesh);
	pEnemyObject->SetColor(RGB(255, 0, 255));
	pEnemyObject->SetPosition(-10.0f, 0.0f, -10.0f);
	pEnemyObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pEnemyObject->SetRotationSpeed(60.06f);
	pEnemyObject->SetMovingDirection(XMFLOAT3(1.0f, 0.0f, 1.0f));
	pEnemyObject->SetMovingSpeed(8.9f);
	m_ppObjects[5] = pEnemyObject;

	pEnemyObject = new CEnemyObject(m_pPlayer);
	pEnemyObject->SetMesh(pCubeMesh);
	pEnemyObject->SetColor(RGB(255, 0, 255));
	pEnemyObject->SetPosition(-10.0f, 10.0f, -10.0f);
	pEnemyObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pEnemyObject->SetRotationSpeed(60.06f);
	pEnemyObject->SetMovingDirection(XMFLOAT3(1.0f, 1.0f, 1.0f));
	pEnemyObject->SetMovingSpeed(9.7f);
	m_ppObjects[6] = pEnemyObject;

	pEnemyObject = new CEnemyObject(m_pPlayer);
	pEnemyObject->SetMesh(pCubeMesh);
	pEnemyObject->SetColor(RGB(255, 0, 128));
	pEnemyObject->SetPosition(-10.0f, 10.0f, -20.0f);
	pEnemyObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pEnemyObject->SetRotationSpeed(70.06f);
	pEnemyObject->SetMovingDirection(XMFLOAT3(-1.0f, 1.0f, 1.0f));
	pEnemyObject->SetMovingSpeed(15.6f);
	m_ppObjects[7] = pEnemyObject;

	pEnemyObject = new CEnemyObject(m_pPlayer);
	pEnemyObject->SetMesh(pCubeMesh);
	pEnemyObject->SetColor(RGB(128, 0, 255));
	pEnemyObject->SetPosition(-15.0f, 10.0f, -30.0f);
	pEnemyObject->SetRotationAxis(XMFLOAT3(1.0f, 1.0f, 0.0f));
	pEnemyObject->SetRotationSpeed(90.06f);
	pEnemyObject->SetMovingDirection(XMFLOAT3(0.0f, 0.0f, -1.0f));
	pEnemyObject->SetMovingSpeed(15.0f);
	m_ppObjects[8] = pEnemyObject;

	pEnemyObject = new CEnemyObject(m_pPlayer);
	pEnemyObject->SetMesh(pCubeMesh);
	pEnemyObject->SetColor(RGB(255, 64, 64));
	pEnemyObject->SetPosition(+15.0f, 10.0f, 0.0f);
	pEnemyObject->SetRotationAxis(XMFLOAT3(1.0f, 1.0f, 0.0f));
	pEnemyObject->SetRotationSpeed(90.06f);
	pEnemyObject->SetMovingDirection(XMFLOAT3(-0.0f, 0.0f, -1.0f));
	pEnemyObject->SetMovingSpeed(15.0f);
	m_ppObjects[9] = pEnemyObject;

	pCubeMesh = new CCubeMesh(1.0f, 1.0f, 1.0f);

	m_nWordObjects = 49;
	m_ppWordObjects = new CGameObject * [m_nWordObjects];

	CExplosiveObject* pExplosiveObject = new CExplosiveObject();
	// ----------- S ------------------
	{pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 64, 64));
	pExplosiveObject->SetPosition(-10.0, 5.0, 10.0);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(90.06f);
	m_ppWordObjects[0] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(-9.0f, 5.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 0.0f,	.0f));
	pExplosiveObject->SetRotationSpeed(90.06f);
	m_ppWordObjects[1] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(-8.0f, 5.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, .0f));
	pExplosiveObject->SetRotationSpeed(90.06f);
	m_ppWordObjects[2] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 64, 64));
	pExplosiveObject->SetPosition(-10.0, 4.0, 10.0);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, .0f));
	pExplosiveObject->SetRotationSpeed(90.06f);
	m_ppWordObjects[3] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(-10.0f, 3.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, .0f));
	pExplosiveObject->SetRotationSpeed(90.06f);
	m_ppWordObjects[4] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(-9.0f, 3.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, .0f));
	pExplosiveObject->SetRotationSpeed(90.06f);
	m_ppWordObjects[5] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(-8.0f, 3.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, .0f));
	pExplosiveObject->SetRotationSpeed(90.06f);
	m_ppWordObjects[6] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 64, 64));
	pExplosiveObject->SetPosition(-8.0, 2.0, 10.0);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, .0f));
	pExplosiveObject->SetRotationSpeed(90.06f);
	m_ppWordObjects[7] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(-8.0f, 1.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, .0f));
	pExplosiveObject->SetRotationSpeed(90.06f);
	m_ppWordObjects[8] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(-9.0f, 1.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, .0f));
	pExplosiveObject->SetRotationSpeed(90.06f);
	m_ppWordObjects[9] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(-10.0f, 1.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, .0f));
	pExplosiveObject->SetRotationSpeed(90.06f);
	m_ppWordObjects[10] = pExplosiveObject;
	}
	// ----------- T ------------------
	{pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(-6.0f, 5.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, .0f));
	pExplosiveObject->SetRotationSpeed(-90.0f);
	m_ppWordObjects[11] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(-5.0f, 5.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, .0f));
	pExplosiveObject->SetRotationSpeed(-90.0f);
	m_ppWordObjects[12] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(-4.0f, 5.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, .0f));
	pExplosiveObject->SetRotationSpeed(-90.0f);
	m_ppWordObjects[13] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(-5.0f, 4.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, .0f));
	pExplosiveObject->SetRotationSpeed(-90.0f);
	m_ppWordObjects[14] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(-5.0f, 3.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, .0f));
	pExplosiveObject->SetRotationSpeed(-90.0f);
	m_ppWordObjects[15] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(-5.0f, 2.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, .0f));
	pExplosiveObject->SetRotationSpeed(-90.0f);
	m_ppWordObjects[16] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(-5.0f, 1.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, .0f));
	pExplosiveObject->SetRotationSpeed(-90.0f);
	m_ppWordObjects[17] = pExplosiveObject;
	}
	// ----------- A ------------------
	{pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(-2.0f, 5.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(90.0f);
	m_ppWordObjects[18] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(-2.0f, 4.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(90.0f);
	m_ppWordObjects[19] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(-2.0f, 3.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(90.0f);
	m_ppWordObjects[20] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(-2.0f, 2.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(90.0f);
	m_ppWordObjects[21] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(-2.0f, 1.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(90.0f);
	m_ppWordObjects[22] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(-0.0f, 5.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(90.0f);
	m_ppWordObjects[23] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(-0.0f, 4.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(90.0f);
	m_ppWordObjects[24] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(0.0f, 3.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(90.0f);
	m_ppWordObjects[25] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(-0.0f, 2.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(90.0f);
	m_ppWordObjects[26] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(-0.0f, 1.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(90.0f);
	m_ppWordObjects[27] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(-1.0f, 5.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(90.0f);
	m_ppWordObjects[28] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(-1.0f, 3.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(90.0f);
	m_ppWordObjects[29] = pExplosiveObject;
	}
	// ----------- R ------------------
	{pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(2.0f, 5.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(-90.0f);
	m_ppWordObjects[30] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(2.0f, 4.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(-90.0f);
	m_ppWordObjects[31] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(2.0f, 3.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(-90.0f);
	m_ppWordObjects[32] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(2.0f, 2.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(-90.0f);
	m_ppWordObjects[33] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(2.0f, 1.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(-90.0f);
	m_ppWordObjects[34] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(3.0f, 5.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(-90.0f);
	m_ppWordObjects[35] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(4.0f, 5.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(-90.0f);
	m_ppWordObjects[36] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(4.0f, 4.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(-90.0f);
	m_ppWordObjects[37] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(4.0f, 3.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(-90.0f);
	m_ppWordObjects[38] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(3.0f, 3.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(-90.0f);
	m_ppWordObjects[39] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(3.0f, 2.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(-90.0f);
	m_ppWordObjects[40] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(4.0f, 1.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(0.0f, 1.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(-90.0f);
	m_ppWordObjects[41] = pExplosiveObject;
}
	// ----------- T ------------------
	{pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(6.0f, 5.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(-90.0f);
	m_ppWordObjects[42] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(7.0f, 5.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(-90.0f);
	m_ppWordObjects[43] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(8.0f, 5.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(-90.0f);
	m_ppWordObjects[44] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(7.0f, 4.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(-90.0f);
	m_ppWordObjects[45] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(7.0f, 3.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(-90.0f);
	m_ppWordObjects[46] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(7.0f, 2.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(-90.0f);
	m_ppWordObjects[47] = pExplosiveObject;

	pExplosiveObject = new CExplosiveObject();
	pExplosiveObject->SetMesh(pCubeMesh);
	pExplosiveObject->SetColor(RGB(255, 0, 0));
	pExplosiveObject->SetPosition(7.0f, 1.0f, 10.0f);
	pExplosiveObject->SetRotationAxis(XMFLOAT3(1.0f, 0.0f, 0.0f));
	pExplosiveObject->SetRotationSpeed(-90.0f);
	m_ppWordObjects[48] = pExplosiveObject;
	}

#ifdef _WITH_DRAW_AXIS
	m_pWorldAxis = new CGameObject();
	CAxisMesh* pAxisMesh = new CAxisMesh(0.5f, 0.5f, 0.5f);
	m_pWorldAxis->SetMesh(pAxisMesh);
#endif
}

void CScene::ReleaseObjects()
{ 
	if (CExplosiveObject::m_pExplosionMesh) CExplosiveObject::m_pExplosionMesh->Release();

	for (int i = 0; i < m_nObjects; i++) if (m_ppObjects[i]) delete m_ppObjects[i];
	if (m_ppObjects) delete[] m_ppObjects;

	if (m_pWallsObject) delete m_pWallsObject;

#ifdef _WITH_DRAW_AXIS
	if (m_pWorldAxis) delete m_pWorldAxis;
#endif
}

void CScene::OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{
}

void CScene::OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{
	switch (nMessageID)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		{
			CExplosiveObject* pExplosiveObject = (CExplosiveObject*)m_ppObjects[int(wParam - '1')];
			pExplosiveObject->m_bBlowingUp = true;
			break;
		}
		case 'A':
			for (int i = 0; i < m_nObjects; i++)
			{
				CExplosiveObject* pExplosiveObject = (CExplosiveObject*)m_ppObjects[i];
				pExplosiveObject->m_bBlowingUp = true;
			}
			break;
		case VK_RETURN:
			start = true;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

CGameObject* CScene::PickObjectPointedByCursor(int xClient, int yClient, CCamera* pCamera)	// 마우스 피킹
{
	XMFLOAT3 xmf3PickPosition;
	xmf3PickPosition.x = (((2.0f * xClient) / (float)pCamera->m_Viewport.m_nWidth) - 1) / pCamera->m_xmf4x4PerspectiveProject._11;
	xmf3PickPosition.y = -(((2.0f * yClient) / (float)pCamera->m_Viewport.m_nHeight) - 1) / pCamera->m_xmf4x4PerspectiveProject._22;
	xmf3PickPosition.z = 1.0f;

	XMVECTOR xmvPickPosition = XMLoadFloat3(&xmf3PickPosition);
	XMMATRIX xmmtxView = XMLoadFloat4x4(&pCamera->m_xmf4x4View);

	int nIntersected = 0;
	float fNearestHitDistance = FLT_MAX;
	CGameObject* pNearestObject = NULL;
	for (int i = 0; i < m_nObjects; i++)
	{
		float fHitDistance = FLT_MAX;
		nIntersected = m_ppObjects[i]->PickObjectByRayIntersection(xmvPickPosition, xmmtxView, &fHitDistance);
		if ((nIntersected > 0) && (fHitDistance < fNearestHitDistance))
		{
			fNearestHitDistance = fHitDistance;
			pNearestObject = m_ppObjects[i];
		}
	}
	return(pNearestObject);
}

void CScene::CheckObjectByObjectCollisions()		// 오브젝트와 오브젝트의 충돌검사
{
	for (int i = 0; i < m_nObjects; i++) m_ppObjects[i]->m_pObjectCollided = NULL;
	for (int i = 0; i < m_nObjects; i++)
	{
		for (int j = (i + 1); j < m_nObjects; j++)
		{
			if (m_ppObjects[i]->m_xmOOBB.Intersects(m_ppObjects[j]->m_xmOOBB))
			{
				m_ppObjects[i]->m_pObjectCollided = m_ppObjects[j];
				m_ppObjects[j]->m_pObjectCollided = m_ppObjects[i];
			}
		}
	}
	for (int i = 0; i < m_nObjects; i++)
	{
		if (m_ppObjects[i]->m_pObjectCollided)
		{
			XMFLOAT3 xmf3MovingDirection = m_ppObjects[i]->m_xmf3MovingDirection;
			float fMovingSpeed = m_ppObjects[i]->m_fMovingSpeed;
			m_ppObjects[i]->m_xmf3MovingDirection = m_ppObjects[i]->m_pObjectCollided->m_xmf3MovingDirection;
			m_ppObjects[i]->m_fMovingSpeed = m_ppObjects[i]->m_pObjectCollided->m_fMovingSpeed;
			m_ppObjects[i]->m_pObjectCollided->m_xmf3MovingDirection = xmf3MovingDirection;
			m_ppObjects[i]->m_pObjectCollided->m_fMovingSpeed = fMovingSpeed;
			m_ppObjects[i]->m_pObjectCollided->m_pObjectCollided = NULL;
			m_ppObjects[i]->m_pObjectCollided = NULL;
		}
	}
}

void CScene::CheckObjectByWallCollisions()
{
	for (int i = 0; i < m_nObjects; i++)
	{
		ContainmentType containType = m_pWallsObject->m_xmOOBB.Contains(m_ppObjects[i]->m_xmOOBB);
		switch (containType)
		{
		case DISJOINT:
		{
			int nPlaneIndex = -1;
			for (int j = 0; j < 6; j++)
			{
				PlaneIntersectionType intersectType = m_ppObjects[i]->m_xmOOBB.Intersects(XMLoadFloat4(&m_pWallsObject->m_pxmf4WallPlanes[j]));
				if (intersectType == BACK)
				{
					nPlaneIndex = j;
					break;
				}
			}
			if (nPlaneIndex != -1)
			{
				XMVECTOR xmvNormal = XMVectorSet(m_pWallsObject->m_pxmf4WallPlanes[nPlaneIndex].x, m_pWallsObject->m_pxmf4WallPlanes[nPlaneIndex].y, m_pWallsObject->m_pxmf4WallPlanes[nPlaneIndex].z, 0.0f);
				XMVECTOR xmvReflect = XMVector3Reflect(XMLoadFloat3(&m_ppObjects[i]->m_xmf3MovingDirection), xmvNormal);
				XMStoreFloat3(&m_ppObjects[i]->m_xmf3MovingDirection, xmvReflect);
			}
			break;
		}
		case INTERSECTS:
		{
			int nPlaneIndex = -1;
			for (int j = 0; j < 6; j++)
			{
				PlaneIntersectionType intersectType = m_ppObjects[i]->m_xmOOBB.Intersects(XMLoadFloat4(&m_pWallsObject->m_pxmf4WallPlanes[j]));
				if (intersectType == INTERSECTING)
				{
					nPlaneIndex = j;
					break;
				}
			}
			if (nPlaneIndex != -1)
			{
				XMVECTOR xmvNormal = XMVectorSet(m_pWallsObject->m_pxmf4WallPlanes[nPlaneIndex].x, m_pWallsObject->m_pxmf4WallPlanes[nPlaneIndex].y, m_pWallsObject->m_pxmf4WallPlanes[nPlaneIndex].z, 0.0f);
				XMVECTOR xmvReflect = XMVector3Reflect(XMLoadFloat3(&m_ppObjects[i]->m_xmf3MovingDirection), xmvNormal);
				XMStoreFloat3(&m_ppObjects[i]->m_xmf3MovingDirection, xmvReflect);
			}
			break;
		}
		case CONTAINS:
			break;
		}
	}
}

void CScene::CheckPlayerByWallCollision()
{
	BoundingOrientedBox xmOOBBPlayerMoveCheck;
	m_pWallsObject->m_xmOOBBPlayerMoveCheck.Transform(xmOOBBPlayerMoveCheck, XMLoadFloat4x4(&m_pWallsObject->m_xmf4x4World));
	XMStoreFloat4(&xmOOBBPlayerMoveCheck.Orientation, XMQuaternionNormalize(XMLoadFloat4(&xmOOBBPlayerMoveCheck.Orientation)));

	if (!xmOOBBPlayerMoveCheck.Intersects(m_pPlayer->m_xmOOBB)) m_pWallsObject->SetPosition(m_pPlayer->m_xmf3Position);
}

void CScene::CheckObjectByBulletCollisions()
{
	CBulletObject** ppBullets = ((CAirplanePlayer*)m_pPlayer)->m_ppBullets;
	for (int i = 0; i < m_nObjects; i++)
	{
		for (int j = 0; j < BULLETS; j++)
		{
			if (ppBullets[j]->m_bActive && m_ppObjects[i]->m_xmOOBB.Intersects(ppBullets[j]->m_xmOOBB))
			{
				CExplosiveObject* pExplosiveObject = (CExplosiveObject*)m_ppObjects[i];
				pExplosiveObject->m_bBlowingUp = true;
				ppBullets[j]->Reset();
			}
		}
	}
	for (int i = 0; i < m_nObjects; ++i)
	{
		ppBullets = ((CEnemyObject*)m_ppObjects[i])->m_ppBullets;	// 3중 포인터??
		for (int j = 0; j < 1; ++j)
		{
			if (ppBullets[j]->m_bActive && ((CAirplanePlayer*)m_pPlayer)->m_xmOOBB.Intersects(ppBullets[j]->m_xmOOBB))					// 적의 총알과 플레이어의 충돌처리
			{
				ppBullets[j]->Reset();
				if (!((CAirplanePlayer*)m_pPlayer)->m_barrier_swtich) {
					((CAirplanePlayer*)m_pPlayer)->m_hp--;
					//((CAirplanePlayer*)m_pPlayer)->SetColor(RGB(0, 0, 0));
				}


				if (((CAirplanePlayer*)m_pPlayer)->m_hp == 0) exit(0);
			}
		}

	}
}

void CScene::Animate(float fElapsedTime)
{
	m_pWallsObject->Animate(fElapsedTime);

	if (start) {
		for (int i = 0; i < m_nObjects; i++) {
			m_ppObjects[i]->Animate(fElapsedTime);
			//m_ppObjects[i]->FireBullet(m_pLockedObject);
 
		}
	}

	else for (int i = 0; i < m_nWordObjects; i++) m_ppWordObjects[i]->Animate(fElapsedTime);

	CheckPlayerByWallCollision();

	CheckObjectByWallCollisions();

	CheckObjectByObjectCollisions();

	CheckObjectByBulletCollisions();
}

void CScene::Render(HDC hDCFrameBuffer, CCamera* pCamera)
{
	CGraphicsPipeline::SetViewport(&pCamera->m_Viewport);

	CGraphicsPipeline::SetViewPerspectiveProjectTransform(&pCamera->m_xmf4x4ViewPerspectiveProject);
	if (!start)
	{
		for (int i = 0; i < m_nWordObjects; i++) m_ppWordObjects[i]->Render(hDCFrameBuffer, pCamera);
	}
	else
	{
		m_pWallsObject->Render(hDCFrameBuffer, pCamera);		// 벽을 Render 한다.
		for (int i = 0; i < m_nObjects; i++) m_ppObjects[i]->Render(hDCFrameBuffer, pCamera);	// 큐브들을 그린다
		
	}
	if (m_pPlayer) m_pPlayer->Render(hDCFrameBuffer, pCamera);	// 플레이어 객체를 그린다
//UI
#ifdef _WITH_DRAW_AXIS
	CGraphicsPipeline::SetViewOrthographicProjectTransform(&pCamera->m_xmf4x4ViewOrthographicProject);
	m_pWorldAxis->SetRotationTransform(&m_pPlayer->m_xmf4x4World);
	m_pWorldAxis->Render(hDCFrameBuffer, pCamera);
#endif
}
