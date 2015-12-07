#include "GameManager.h"
#include "EntityPhysical.h"


GameManager::GameManager()
{
	Running = true;
}


GameManager::~GameManager()
{

}

void GameManager::Init()
{
	//rules, never set Running to true
	//Don't talk about Init
	std::cout << "Init game \n";
	InitGraphics();
	WorldObj = new World();
}
void GameManager::InitGraphics()
{
	std::cout << "Init window \n";
	this->Window.create(sf::VideoMode(800, 600), "My window");
}
void GameManager::MainLoop()
{
	Init();
	while (Running)
	{
		Update();
		Render();
		PollInput();
	}
}

void GameManager::Update()
{
	WorldObj->Update(this);
}

void GameManager::Render()
{
	Window.clear(sf::Color::Black);
	WorldObj->Render(this);
	Window.display();
}


void GameManager::PollInput()
{
	sf::Event event;
	while (Window.pollEvent(event))
	{
		// "close requested" event: we close the window
		if (event.type == sf::Event::Closed)
		{
			Running = false;
			Window.close();
		}
		if (event.type == sf::Event::KeyPressed) {
			this->KeyState[event.key.code] = true;
		}
		if (event.type == sf::Event::KeyReleased) {
			this->KeyState[event.key.code] = false;
		}
		float Force = 100;
		if (this->KeyState[sf::Keyboard::Key::D])
		{
			((EntityPhysical *)this->WorldObj->EntityList[0])->PhyObject->ApplyForceToCenter(b2Vec2(Force, 0), true);
		}
		if (this->KeyState[sf::Keyboard::Key::A])
		{
			((EntityPhysical *)this->WorldObj->EntityList[0])->PhyObject->ApplyForceToCenter(b2Vec2(-Force, 0), true);
		}
	}
}
void GameManager::Delete()
{

}