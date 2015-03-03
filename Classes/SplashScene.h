//
//  SplashScene.h
//  MyGame
//
//  Created by Leiyou Who on 3/3/15.
//
//

#ifndef  __MyGame__SplashScene__
#define  __MyGame__SplashScene__

#include <stdio.h>
#include "cocos2d.h"
#include "ConstUtil.h"
USING_NS_CC;

//动画播放的速度
const double MOVE_SPEED = 0.5f;

class SplashScene : public Layer {
public:
    static Scene* createScene();
    virtual bool init();
    
    //定义ke.png精灵向左移动
    void moveKeSpriteToLeft();
    //定义mai.png精灵向左移动
    void moveMaiSpriteToLeft();
    //初始化图片方法
    void initMoveSprite();
    //开始移动精灵
    void startMoveSprite(float dt);
    //动画结束后进入MenuScene场景
    void goToMenuScene();
    //动画逐渐消失
    void SpriteFadeOut();

    CREATE_FUNC(SplashScene);
private:
    Sprite* cheng_sprite;
    Sprite* mai_sprite;
    Sprite* ke_sprite;
    Sprite* ji_sprite;
    //窗口大小
    Size visibleSize;
    //精灵大小
    Size spriteSize;
    
};

#endif /* defined(__MyGame__SplashScene__) */
