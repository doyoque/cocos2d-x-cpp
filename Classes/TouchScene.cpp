#include "TouchScene.h"

USING_NS_CC;

Scene* TouchScene::createScene()
{
    auto scene = Scene::create();
    auto layer = TouchScene::create();
    scene->addChild(layer);

   return scene;
}

bool TouchScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto sprite = Sprite::create("HelloWorld.png");
    sprite->setPosition(Vec2(Director::getInstance()->getVisibleSize().width/2, Director::getInstance()->getVisibleSize().height/2));

    //Add a "touch" event listener to our sprite
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = [](Touch* touch, Event* event) -> bool {
      auto bounds = event->getCurrentTarget()->getBoundingBox();

      if(bounds.containsPoint(touch->getLocation())) {
        std::stringstream touchDetails;
        touchDetails << "Touched at OpenGL coordinates: " <<
          touch->getLocation().x << "," << touch->getLocation().y << std::endl <<
          "touched at UI coordinates: " <<
          touch->getLocationInView().x << "," << touch->getLocationInView().y << std::endl <<
          "touched at local coordinates: " <<
          event->getCurrentTarget()->convertToNodeSpace(touch->getLocation()).x << "," <<
          event->getCurrentTarget()->convertToNodeSpace(touch->getLocation()).y << std::endl <<
          "Touch moved by: " << touch->getDelta().x << "," << touch->getDelta().y;

          MessageBox(touchDetails.str().c_str(), "Touched");
      }

      return true;
    };

    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, sprite);
    this->addChild(sprite, 0);

    return true;
}

bool TouchScene::onTouchBegan(Touch* touch, Event* event)
{
   labelTouchInfo->setPosition(touch->getLocation());
   labelTouchInfo->setString("You Touched Here");
   return true;
}

void TouchScene::onTouchEnded(Touch* touch, Event* event)
{
   cocos2d::log("touch ended");
}

void TouchScene::onTouchMoved(Touch* touch, Event* event)
{
   cocos2d::log("touch moved");
}

void TouchScene::onTouchCancelled(Touch* touch, Event* event)
{
   cocos2d::log("touch cancelled");
}