#include "hero.h"
#include "transform.h"
#include "HeroControllerComponent.h"
#include"spriteComponent.h"
#include "kinematicComponent.h"
#include "renderer.h"
#include "aabbComponent.h"
#include "explosion.h"
#include "eventManager.h"
#include "animationComponent.h"
#include "inputManager.h"

void Hero::Create(const Vector2D & position)
{
	SetTag("hero");
	m_transform.position = position;
	m_transform.scale = Vector2D(5.0f, 5.0f);

	KinematicComponent* kinematic = AddComponent<KinematicComponent>();
	kinematic->Create(800.0f, 0.3f, false);

	HeroControllerComponent* heroControllerComponent = AddComponent<HeroControllerComponent>();
	heroControllerComponent->Create(50.0f);
	
	SpriteComponent* spritecomponent01 = AddComponent<SpriteComponent>();
	spritecomponent01->Create("", Vector2D(0.5f, 0.5f));
	spritecomponent01->SetDepth(100);

	AnimationComponent* animationComponent = AddComponent<AnimationComponent>();
	std::vector<std::string> textureNames = { "sprites//knight_m_idle_anim_f0.png","sprites//knight_m_idle_anim_f1.png" ,"sprites//knight_m_idle_anim_f2.png" ,"sprites//knight_m_idle_anim_f3.png" };
	animationComponent->Create(textureNames, 1.0f / 10.0f, AnimationComponent::ePlayback::LOOP);

	AABBComponent* aabbComponent = AddComponent<AABBComponent>();
	aabbComponent->Create();
}

void Hero::Update()
{
	Entity::Update();

	if ((InputManager::Instance()->GetActionButton("left") == InputManager::eButtonState::PRESSED) ||
		(InputManager::Instance()->GetActionButton("left") == InputManager::eButtonState::HELD)|| 
		(InputManager::Instance()->GetActionButton("up") == InputManager::eButtonState::PRESSED) ||
		(InputManager::Instance()->GetActionButton("up") == InputManager::eButtonState::HELD) ||
		(InputManager::Instance()->GetActionButton("down") == InputManager::eButtonState::PRESSED) ||
		(InputManager::Instance()->GetActionButton("down") == InputManager::eButtonState::HELD) ||
		(InputManager::Instance()->GetActionButton("right") == InputManager::eButtonState::PRESSED) ||
		(InputManager::Instance()->GetActionButton("right") == InputManager::eButtonState::HELD))
	{
		std::vector<std::string> textureNames = { "sprites//knight_m_run_anim_f0.png","sprites//knight_m_run_anim_f1.png" ,"sprites//knight_m_run_anim_f2.png" ,"sprites//knight_m_run_anim_f3.png" };
	}
	else {
		std::vector<std::string> textureNames = { "sprites//knight_m_idle_anim_f0.png","sprites//knight_m_idle_anim_f1.png" ,"sprites//knight_m_idle_anim_f2.png" ,"sprites//knight_m_idle_anim_f3.png" };
		this->GetComponent<AnimationComponent>()->Create(textureNames, 1.0f / 10.0f, AnimationComponent::ePlayback::LOOP);
	}

	Vector2D size = Renderer::Instance()->GetSize();
	m_transform.position.x = Math::Clamp(m_transform.position.x, 16.0f, size.x-16.0f);
	m_transform.position.y = Math::Clamp(m_transform.position.y, 16.0f, size.y-16.0f);
}

void Hero::OnEvent(const Event & event)
{
	if (event.eventID == "collision") {
		if (event.sender->GetTag() == "Dragon") {

		}
		else if (event.sender->GetTag() == "Item") {

		}
	}
}