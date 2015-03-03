//
//  SplashScene.cpp
//  MyGame
//
//  Created by Leiyou Who on 3/3/15.
//
//

#include "SplashScene.h"
#include "ConstUtil.h"
#include "MenuScene.h"
USING_NS_CC;

Scene* SplashScene::createScene()
{
    auto scene = Scene::create();
    auto layer = SplashScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool SplashScene::init()
{
    if (!Layer::init()) {
        return false;
    }

    visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    /**
     初始化动画精灵
    */
    initMoveSprite();
    
    /**
     *  场景开始1秒后动画开始播放
     */
    scheduleOnce(schedule_selector(SplashScene::startMoveSprite), 1.0f);
    
    return true;
}

void SplashScene::initMoveSprite()
{
    /**
     *  调用Sprite::create方法创建cheng 、mai 、 ke、 ji四个精灵
     */
    cheng_sprite = Sprite::create(CHENG_IMAGE);
    mai_sprite   = Sprite::create(MAI_IMAGE);
    ke_sprite    = Sprite::create(KE_IMAGE);
    ji_sprite    = Sprite::create(JI_IMAGE);
    
    /**
     *  给动画尺寸赋值，每张动画尺寸大小都一样。
     */
    spriteSize = cheng_sprite->getContentSize();
    
    /**
     *  从左到右放置精灵图片,顺序为：迈科计成
     */
    mai_sprite->setPosition(visibleSize.width/2 - spriteSize.width*2,visibleSize.height/2 );
    ke_sprite->setPosition(visibleSize.width/2 - spriteSize.width,visibleSize.height/2);
    ji_sprite->setPosition(visibleSize.width/2,visibleSize.height/2);
    cheng_sprite->setPosition(visibleSize.width/2 + spriteSize.width,visibleSize.height/2);
    
    /**
     *  把精灵锚点都设置为（0,0.5），这样保证四张图片可以居中排列在窗口位置
     */
    mai_sprite->setAnchorPoint(Vec2(0, 0.5));
    ke_sprite->setAnchorPoint(Vec2(0, 0.5));
    ji_sprite->setAnchorPoint(Vec2(0, 0.5));
    cheng_sprite->setAnchorPoint(Vec2(0, 0.5));
    
    this->addChild(mai_sprite);
    this->addChild(ke_sprite);
    this->addChild(ji_sprite);
    this->addChild(cheng_sprite);

}

/**
*  调整精灵顺序，使迈科计诚，变为诚迈科技
*/
void SplashScene::startMoveSprite(float dt)
{
    MoveBy* moveChengToLeft1 = MoveBy::create(0.5f,Vec2(-spriteSize.width,0));
    cheng_sprite->runAction(moveChengToLeft1);

    MoveBy* moveJiToright = MoveBy::create(MOVE_SPEED,Vec2(spriteSize.width,0));
    
    CallFunc* callFunc = CallFunc::create(CC_CALLBACK_0(SplashScene::moveKeSpriteToLeft, this));
    
    ji_sprite->runAction(Sequence::create(moveJiToright,callFunc,NULL));
    
}

void SplashScene::moveKeSpriteToLeft()
{
    MoveBy* moveChengToLeft2 = MoveBy::create(MOVE_SPEED,Vec2(-spriteSize.width,0));
    cheng_sprite->runAction(moveChengToLeft2);
    
    MoveBy* ke_Sprite_MoveBy = MoveBy::create(MOVE_SPEED,Vec2(spriteSize.width,0));
    CallFunc* callFunc2 = CallFunc::create(CC_CALLBACK_0(SplashScene::moveMaiSpriteToLeft, this));
    ke_sprite->runAction(Sequence::create(ke_Sprite_MoveBy,callFunc2,NULL));
    
}
void SplashScene::moveMaiSpriteToLeft()
{
    MoveBy* moveChengToLeft3 = MoveBy::create(MOVE_SPEED,Vec2(-spriteSize.width,0));
    cheng_sprite->runAction(moveChengToLeft3);
    
    MoveBy* mai_Sprite_MoveBy = MoveBy::create(MOVE_SPEED,Vec2(spriteSize.width,0));
    CallFunc* callFunc3 = CallFunc::create(CC_CALLBACK_0(SplashScene::SpriteFadeOut, this));
    mai_sprite->runAction(Sequence::create(mai_Sprite_MoveBy,callFunc3,NULL));
}


void SplashScene::SpriteFadeOut()
{
    /**
     *  定义4个消失的FadeOut动画，持续时间2秒
     */
    FadeOut* fadeOut1 = FadeOut::create(2.0f);
    FadeOut* fadeOut2 = FadeOut::create(2.0f);
    FadeOut* fadeOut3 = FadeOut::create(2.0f);
    FadeOut* fadeOut4 = FadeOut::create(2.0f);
    mai_sprite->runAction(fadeOut1) ;
    ke_sprite->runAction(fadeOut2) ;
    ji_sprite->runAction(fadeOut3) ;
    
    /**
     *  动画结束后调用gotoMenuScene()方法进入MenuScene场景界面
     */
    CallFunc* callFunc4 = CallFunc::create(CC_CALLBACK_0(SplashScene::goToMenuScene, this));
    cheng_sprite->runAction(Sequence::create(fadeOut4,callFunc4,NULL));
}

void SplashScene::goToMenuScene()
{
    log("gotoMenuScene");
    Director::getInstance()->replaceScene(MenuScene::createScene());
}





















