//
//  MenuScene.h
//  MyGame
//
//  Created by Leiyou Who on 3/3/15.
//
//

#ifndef __MyGame__MenuScene__
#define __MyGame__MenuScene__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "ConstUtil.h"

USING_NS_CC;
USING_NS_CC_EXT;

const int Btn_Width  = 222;
const int Btn_Height = 50;
const int Btn_FontSize = 20;
const int Quit_Dialog_Size_Width = 400;
const int Quit_Dialog_Size_Height = 220;
//const int Btn_Padding = 60;
const int Btn_Single_Game_TAG = 10001;
const int Btn_Multi_Game_TAG = 10002;
const int Btn_Music_TAG = 10003;
const int Btn_Quit_Game_TAG = 10004;
const int Btn_Quit_OK_TAG = 10005;
const int Btn_Quit_Cancel_TAG = 10006;

class MenuScene : public LayerColor {
public:
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(MenuScene);
private:
    /**
     *  窗口尺寸
     */
    Size visibleSize;
    /**
     *  场景文字
     */
    Label* settingsGameTTF;
    
    /**
     *  Menu点击回调方法
     */
    void MenuTouchDown(Object* pSender, Control::EventType event);
    /**
     *  添加场景背景方法
     */
    void addBackgroundSprite();
    /**
     *  添加Menu方法
     */
    void addMenuSprite();
};

#endif /* defined(__MyGame__MenuScene__) */
