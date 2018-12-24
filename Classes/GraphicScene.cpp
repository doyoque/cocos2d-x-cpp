#include "GraphicScene.h"

USING_NS_CC;

Scene* GraphicScene::createScene()
{
    auto scene = Scene::create();
    auto layer = GraphicScene::create();
   scene->addChild(layer);
    
    return scene;
}

bool GraphicScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    // [238x57] [layout 12c0,238x57,0,0{119x57,0,0[119x28,0,0,0,119x28,0,29,2],118x57,120,0,1}]

    auto sprite = Sprite::create("decepticon.png");
    auto sprite2 = Sprite::create("autobot.png");
    sprite->setAnchorPoint(Vec2(0.0,0.0));
    sprite2->setAnchorPoint(Vec2(0.0, 0.0));

    sprite->addChild(sprite2);
   
    sprite->setPosition(100, 100);
    sprite2->setPosition(0, 0);
   
    this->addChild(sprite, 0);
    
    return true;
}