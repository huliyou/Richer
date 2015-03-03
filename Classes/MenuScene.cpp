//
//  MenuScene.cpp
//  MyGame
//
//  Created by Leiyou Who on 3/3/15.
//
//

#include "MenuScene.h"
USING_NS_CC;

Scene* MenuScene::createScene()
{
    Scene *scene = Scene::create();
    Layer *layer = MenuScene::create();
    scene->addChild(layer);
    return scene;
}

bool MenuScene::init()
{
    if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255))) {
        return false;
    }
    visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    
    addBackgroundSprite();
    addMenuSprite();
    
    return true;
}

void MenuScene::addBackgroundSprite()
{
    /**
     *  添加大富翁背景图片，居中显示
     */
    Sprite* menuLogoSprite = Sprite::create(MENU_LOGO);
    menuLogoSprite->setPosition(Vec2(visibleSize.width/2,visibleSize.height));
    menuLogoSprite->setAnchorPoint(Vec2(0.5,1));
    menuLogoSprite->setScale(0.6);
    addChild(menuLogoSprite);
    
    /**
     *  添加左边彩虹图片
     */
    Sprite* rainbowSprite = Sprite::create(RAINBOW);
    rainbowSprite->setPosition(Vec2(5,visibleSize.height-20));
    rainbowSprite->setAnchorPoint(Vec2(0, 1));
    rainbowSprite->setScale(0.3f);
    addChild(rainbowSprite);
    
    /**
     *  让彩虹左右移动
     */
    auto rainbowMoveLeft  = MoveBy::create(0.6f, Vec2(200,0));
    auto rainbowMoveRight = rainbowMoveLeft->reverse();
    auto seq              = Sequence::create(rainbowMoveLeft,rainbowMoveRight, NULL);
    rainbowSprite->runAction(RepeatForever::create(seq));
}


void MenuScene::addMenuSprite()
{
    //  添加单机游戏Menu
    /**
     *  设置菜单normal图片
     */
    Scale9Sprite* btnNormal1     = Scale9Sprite::create(NORMAL_MENU);
    /**
     *  设置菜单press图片
     */

    Scale9Sprite* btnPress1      = Scale9Sprite::create(PRESS_MENU);

    //创建菜单所需的Label对象
    LabelTTF* singleGameTTF      = LabelTTF::create(SINGLE_GAME, FONT_MENU, Btn_FontSize);
    //创建controlButton
    ControlButton *singleGameBtn = ControlButton::create(singleGameTTF, btnNormal1);
    //添加singleButton菜单的press效果图片
    singleGameBtn->setBackgroundSpriteForState(btnPress1, Control::State::SELECTED);
    //设置位置
    singleGameBtn->setPosition(visibleSize.width/2, visibleSize.height-200);
    //设置大小
    singleGameBtn->setPreferredSize(Size(Btn_Width, Btn_Height));

    //设置点击回调方法
    singleGameBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(MenuScene::MenuTouchDown), Control::EventType::TOUCH_DOWN);
    singleGameBtn->setTag(Btn_Single_Game_TAG);
    addChild(singleGameBtn);

    
    //添加多人游戏按钮
    Scale9Sprite* btnNormal2    = Scale9Sprite::create(NORMAL_MENU);
    Scale9Sprite* btnPress2     = Scale9Sprite::create(PRESS_MENU);
    LabelTTF* multiGameTTF      = LabelTTF::create(MULTI_GAME, FONT_MENU, Btn_FontSize);
    ControlButton* multiGameBtn = ControlButton::create(multiGameTTF,btnNormal2);
    multiGameBtn->setBackgroundSpriteForState(btnPress2, Control::State::SELECTED);
    multiGameBtn->setPosition(visibleSize.width/2,visibleSize.height - 260);
    multiGameBtn->setPreferredSize(Size(Btn_Width, Btn_Height));
    multiGameBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(MenuScene::MenuTouchDown), Control::EventType::TOUCH_DOWN);
    multiGameBtn->setTag(Btn_Multi_Game_TAG);
    addChild(multiGameBtn);
    
    
    //音乐设置
    Scale9Sprite* btnNormal3 = Scale9Sprite::create(NORMAL_MENU);
    Scale9Sprite* btnPress3  = Scale9Sprite::create(PRESS_MENU);
    bool music_on = UserDefault::getInstance()->getBoolForKey(MUSIC_ON_KEY, true);
    LabelTTF* settingsGameTTF;
    if (music_on) {
        settingsGameTTF = LabelTTF::create(MUSIC_ON,FONT_MENU,Btn_FontSize);
    }else{
        settingsGameTTF = LabelTTF::create(MUSIC_OFF,FONT_MENU,Btn_FontSize);
    }
    ControlButton* settingsGameBtn = ControlButton::create(settingsGameTTF,btnNormal3);
    settingsGameBtn->setBackgroundSpriteForState(btnPress3, Control::State::SELECTED);
    
    settingsGameBtn->setPosition(ccp(visibleSize.width/2,visibleSize.height-320));
    settingsGameBtn->setPreferredSize(Size(Btn_Width,Btn_Height));
    settingsGameBtn->addTargetWithActionForControlEvents(this,cccontrol_selector(MenuScene:: MenuTouchDown),Control::EventType::TOUCH_DOWN);//添加setting回调
    settingsGameBtn->setTag(Btn_Music_TAG);
    addChild(settingsGameBtn);
    
    Scale9Sprite* btnNormal4 = Scale9Sprite::create(NORMAL_MENU);
    Scale9Sprite* btnPress4 = Scale9Sprite::create(PRESS_MENU);
    LabelTTF* quitGameTTF = LabelTTF::create(QUIT_GAME,FONT_MENU,Btn_FontSize);
    ControlButton* quitGameBtn = ControlButton::create(quitGameTTF,btnNormal4);
    quitGameBtn->setBackgroundSpriteForState(btnPress4, Control::State::SELECTED);
    
    quitGameBtn->setPosition(ccp(visibleSize.width/2,visibleSize.height-380));
    quitGameBtn->setPreferredSize(Size(Btn_Width,Btn_Height));
    quitGameBtn->addTargetWithActionForControlEvents(this,cccontrol_selector(MenuScene::MenuTouchDown),Control::EventType::TOUCH_DOWN);
    quitGameBtn->setTag(Btn_Quit_Game_TAG);
    addChild(quitGameBtn);
}


void MenuScene:: MenuTouchDown(Object* pSender,Control::EventType event)
{
    log("single touched");
    ControlButton* button = (ControlButton*)pSender;
    int tag = button->getTag();
    switch(tag)
    {
        case Btn_Single_Game_TAG:
        {
            log("single game");
            //Director::getInstance()->pushScene(MapChooseScene::createScene());
        }
            
        case Btn_Multi_Game_TAG:
        {
            log("multi game");
            break;
        }
            
        case Btn_Music_TAG:
        {
            bool music_on = UserDefault::getInstance()->getBoolForKey(MUSIC_ON_KEY,true);
            
            if(music_on)
            {
                UserDefault::getInstance()->setBoolForKey(MUSIC_ON_KEY,false);//设置音效关
                button->setTitleForState(MUSIC_OFF,Control::State::NORMAL);//让menu文字显示off
            }else
            {
                UserDefault::getInstance()->setBoolForKey(MUSIC_ON_KEY,true);//设置音效开
                button->setTitleForState(MUSIC_ON,Control::State::NORMAL);// 让menu文字显示on
            }
            
            break;
        }
        case Btn_Quit_Game_TAG:
        {
            log("quit game");
            //popupLayer();弹出退出对话框，代码较多，后续编写
            break;
        }
        default:  
            break;
    }
}
















