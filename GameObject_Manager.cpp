#pragma once
#include "GameObject_Manager.h"
#include "Player.h"
#include "Scout.h"
#include "UnitControl.h"
#include "SparkHUD.h"
#include "Terrain.h"
#include "InputHandler.h"


GameObject_Manager::GameObject_Manager()
{
}


GameObject_Manager::~GameObject_Manager()
{
	_objects.clear();
}


void GameObject_Manager::selectObject(int x, int y)
{
	for (auto &object : _objects)
	{
		if (object->containsPoint(x, y))
			object->select();
	}
}

void GameObject_Manager::update()
{
	for (auto &object : _objects)
		object->update();
}

void GameObject_Manager::render()
{
	for (auto &object : _objects)
		object->render();
}

void GameObject_Manager::createObject(GameObject::ObjectID type, int x, int y)
{
	switch (type)
	{
		case(GameObject::Player) :
			_objects.push_back(new Player(x, y));
			break;
		case(GameObject::Scout) :
			_objects.push_back(new Scout(x, y));
			break;
		case(GameObject::UnitControl) :
			_objects.push_back(new UnitControl(x, y));
			break;
		case(GameObject::SparkHUD) :
			_objects.push_back(new SparkHUD(x, y));
			break;
		case(GameObject::Terrain) :
			_objects.push_back(new Terrain(x, y));
			break;
	}
}