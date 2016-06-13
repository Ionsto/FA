#include "GameManager.h"

GameManager::GameManager()
{
	Running = true;
	WindowSize = Vector();
	MouseState = MouseData();
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
	InitWorld();
	WindowSize.X = Window.getSize().x;
	WindowSize.Y = Window.getSize().y;
	Mainmenu = new MainMenu();

}
void GameManager::InitGraphics()
{
	std::cout << "Init window \n";
	this->Window.create(sf::VideoMode(800, 800), "Entry");
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
		Window.setMouseCursorVisible(true);
		//web_core->Update();
		Mainmenu->Update(this);
	}
	if (GameState == StateGame)
	{
		Window.setMouseCursorVisible(false);
		if (WorldObj->Player != NULL)
		{
			WindowSize.X = Window.getSize().x;
			WindowSize.Y = Window.getSize().y;
			WorldObj->Player->MousePosition.X = MouseState.MousePosition.X - (WindowSize.X / 2);
			WorldObj->Player->MousePosition.Y = MouseState.MousePosition.Y - (WindowSize.Y / 2);
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
	if (MouseState.LeftMouseState == 2)
	{
		MouseState.LeftMouseState = 0;
	}
	if (MouseState.RightMouseState == 2)
	{
		MouseState.RightMouseState = 0;
	}
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
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == 0)
			{
				MouseState.LeftMouseState = 1;
			}
			if (event.mouseButton.button == 1)
			{
				MouseState.RightMouseState = 1;
			}
		}
		if (event.type == sf::Event::MouseButtonReleased)
		{
			if (event.mouseButton.button == 0)
			{
				MouseState.LeftMouseState = 2;
			}
			if (event.mouseButton.button == 1)
			{
				MouseState.RightMouseState = 2;
			}
		}
		MouseState.MousePosition.X = sf::Mouse::getPosition(Window).x;
		MouseState.MousePosition.Y = sf::Mouse::getPosition(Window).y;
	}
	if (this->GameState = StateGame)
	{
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
		if (this->KeyState[sf::Keyboard::Key::LShift])
		{
			(this->WorldObj->Player)->SetSpeed(25);
		}
		else
		{
			(this->WorldObj->Player)->SetSpeed(10);
		}
		if (this->MouseState.LeftMouseState == 1)
		{
			(this->WorldObj->Player)->UseWeapon();
		}
		if (this->KeyState[sf::Keyboard::Key::Space])
		{
			//Create bond between nearest object and self
			//((EntityPhysical *)this->WorldObj->EntityList[0])->PhyObject->ApplyForceToCenter(b2Vec2(-Force, 0), true);
		}
		WorldObj->CameraLoc = (WindowSize * 0.5) - this->WorldObj->Player->PosOld;
	}
}
void GameManager::Delete()
{

}
void GameManager::InitWorld()
{
	WorldObj = new World();
	//Entrance
	WorldObj->AddWorldCollision(Vector(0, 0), Vector(20, 200));
	WorldObj->AddWorldCollision(Vector(0, 0), Vector(200, 20));
	WorldObj->AddWorldCollision(Vector(0, 180), Vector(200, 20));
	WorldObj->AddWorldCollision(Vector(178, 20), Vector(20, 20));
	WorldObj->AddWorldCollision(Vector(178, 160), Vector(20, 20));
	//Corridor
	WorldObj->AddEntity(new EntityPlayer(WorldObj));
	WorldObj->Player = (EntityPlayer*)WorldObj->EntityList[0];
	WorldObj->AddEntity(new EntityLiving(WorldObj));
	WorldObj->EntityList[0]->SetPosition(Vector(50, 50));
	WorldObj->EntityList[1]->SetPosition(Vector(50, 90));
}