#include "stdafx.h"
#include "BobombBattlefield.h"

#include "Materials/DiffuseMaterial.h"

void BobombBattlefield::Initialize()
{
	auto& physX = PxGetPhysics();
	auto pStandardMaterial = physX.createMaterial(.5f, .5f, .2f);

	//Ground plane
	GameSceneExt::CreatePhysXGroundPlane(*this, pStandardMaterial);

	//Create new instance of color material
	DiffuseMaterial* pMaterial = MaterialManager::Get()->CreateMaterial<DiffuseMaterial>();
	pMaterial->SetDiffuseTexture(L"Textures/Bob-omb-Battlefield/1B46C8C_c.png");

	m_pLevel = new GameObject();
	m_pLevel->AddComponent<ModelComponent>(new ModelComponent(L"Meshes/Bomb-omb-Battlefield.ovm", false))->SetMaterial(pMaterial);

	const auto pTriangleMesh = ContentManager::Load<PxTriangleMesh>(L"Meshes/Bomb-omb-Battlefield.ovpt");
	const auto triangleGeometry{ PxTriangleMeshGeometry{pTriangleMesh} };

	m_pLevel->AddComponent<RigidBodyComponent>(new RigidBodyComponent(false))->AddCollider(triangleGeometry, *pStandardMaterial);
	m_pLevel->GetComponent<RigidBodyComponent>()->SetKinematic(true);


	m_pLevel->GetTransform()->Translate(0.0f, 0.0f, 0.0f);

	AddChild(m_pLevel);
}

void BobombBattlefield::Update()
{
}

void BobombBattlefield::Draw()
{
}

void BobombBattlefield::OnGUI()
{
}
