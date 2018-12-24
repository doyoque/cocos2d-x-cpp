#include "AppDelegate.h"
// #include "HelloWorldScene.h"
// #include "GraphicScene.h"
// #include "TouchScene.h"
#include "KeyboardScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::create("Graphic Scene");
        glview->setFrameSize(640, 480);
        director->setOpenGLView(glview);
    }

    auto scene = KeyboardScene::createScene();
    director->runWithScene(scene);

    return true;
}

void AppDelegate::applicationDidEnterBackground() {
}

void AppDelegate::applicationWillEnterForeground() {
}