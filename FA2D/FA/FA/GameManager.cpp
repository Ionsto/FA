#include "GameManager.h"

GameManager::GameManager()
{
	Running = true;
	WindowSize = Vector();
	MousePosition = Vector();
}


GameManager::~GameManager()
{
	delete WorldObj;
	delete Mainmenu;
}

void GameManager::Init()
{
	//rules, never set Running to true
	//Don't talk about Init
	std::cout << "Init game \n";
	InitGraphics();
	WorldObj = new World();
	WindowSize.X = Window.getSize().x;
	WindowSize.Y = Window.getSize().y;
	Mainmenu = new MainMenu();

}
void GameManager::InitGraphics()
{
	std::cout << "Init window \n";
	this->Window.create(sf::VideoMode(1600, 900), "My window");
}
void GameManager::MainLoop()
{
	while (Running)
	{
		Update();
		Render();
		PollInput();
	}
}

void GameManager::Update()
{
	if (GameState == StateMainMenu)
	{
		//web_core->Update();
		Mainmenu->Update(this);
	}
	if (GameState == StateGame)
	{
		if (WorldObj->Player != NULL)
		{
			MousePosition.X = sf::Mouse::getPosition(Window).x;
			MousePosition.Y = sf::Mouse::getPosition(Window).y;
			WindowSize.X = Window.getSize().x;
			WindowSize.Y = Window.getSize().y;
			WorldObj->Player->MousePosition.X = MousePosition.X - (WindowSize.X / 2);
			WorldObj->Player->MousePosition.Y = MousePosition.Y - (WindowSize.Y / 2);
		}
		WorldObj->Update(this);
	}
}

void GameManager::Render()
{
	Window.clear(sf::Color::Black);
	if (GameState == StateMainMenu)
	{
		Mainmenu->Render(this);
	}
	if (GameState == StateGame)
	{
		WorldObj->Render(this);
	}
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
	}
	float Force = 10;
	if (this->KeyState[sf::Keyboard::Key::D])
	{
		(this->WorldObj->Player)->MoveLeft();
	}
	if (this->KeyState[sf::Keyboard::Key::A])
	{
		(this->WorldObj->Player)->MoveRight();
	}
	if (this->KeyState[sf::Keyboard::Key::S])
	{
		(this->WorldObj->Player)->MoveBackward();
	}
	if (this->KeyState[sf::Keyboard::Key::W])
	{
		(this->WorldObj->Player)->MoveForward();
	}
	if (this->KeyState[sf::Keyboard::Key::Space])
	{
		//Create bond between nearest object and self
		//((EntityPhysical *)this->WorldObj->EntityList[0])->PhyObject->ApplyForceToCenter(b2Vec2(-Force, 0), true);
	}
	WorldObj->CameraLoc = (WindowSize * 0.5) - this->WorldObj->Player->PosOld;
}
void GameManager::Delete()
{

}