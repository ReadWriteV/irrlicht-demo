#include <irrlicht.h>

class irrTest
{
private:
    irr::IrrlichtDevice *irrDevice;
    irr::video::IVideoDriver *irrDriver;
    irr::scene::ISceneManager *irrSceneMgr;
    irr::gui::IGUIEnvironment *irrGui;
    irr::scene::ICameraSceneNode *irrCamera;
    irr::f32 bg_r, bg_g, bg_b;
    bool fadeOut;
    int lastFPS;
    irr::u32 then;
    irr::f32 fadeRate;

    void create();
    void destroy();
    void initScene();
    void endScene();
    void loopScene();
    void addAModel();
    void addNormalCamera();

public:
    irrTest();
    ~irrTest();
};

irrTest::irrTest()
{
    create();
}

irrTest::~irrTest()
{
    destroy();
}

void irrTest::create()
{
    irrDevice = irr::createDevice(irr::video::EDT_SOFTWARE, irr::core::dimension2d<irr::u32>(640, 480), 16, false, false, false, 0);
    irrDriver = irrDevice->getVideoDriver();
    irrSceneMgr = irrDevice->getSceneManager();
    irrGui = irrDevice->getGUIEnvironment();
    initScene();
    while (irrDevice->run() && irrDevice)
    {
        loopScene();
    }
    endScene();
}

void irrTest::destroy()
{
    irrDevice->drop();
}

void irrTest::initScene()
{
    irrDevice->setWindowCaption(L"Hello World");
    bg_r = 255.0f;
    bg_g = 255.0f;
    bg_b = 255.0f;
    fadeOut = true;
    lastFPS = -1;
    then = irrDevice->getTimer()->getTime();
    fadeRate = 0.1f;
    addAModel();
    addNormalCamera();
}

void irrTest::endScene()
{
}

void irrTest::loopScene()
{
    const irr::u32 now = irrDevice->getTimer()->getTime();
    const irr::f32 frameDeltaTime = (irr::f32)(now - then);
    then = now;
    if (bg_r <= 0.0f)
    {
        fadeOut = false;
    }
    else if (bg_r >= 255.0f)
    {
        fadeOut = true;
    }
    if (fadeOut)
    {
        bg_r -= fadeRate * frameDeltaTime;
        bg_g -= fadeRate * frameDeltaTime;
        bg_b -= fadeRate * frameDeltaTime;
    }
    else
    {
        bg_r += fadeRate * frameDeltaTime;
        bg_g += fadeRate * frameDeltaTime;
        bg_b += fadeRate * frameDeltaTime;
    }

    irrDriver->beginScene(true, true, irr::video::SColor(255, (irr::u32)bg_r, (irr::u32)bg_g, (irr::u32)bg_b));
    // irrSceneMgr->drawAll();
    // irrGui->drawAll();
    // irrDriver->draw2DLine(irr::core::vector2di(0, 0), irr::core::vector2di(640, 480), irr::video::SColor(255, 255, 0, 0));
    // irrDriver->draw2DPolygon(irr::core::vector2di(320, 240), 200, irr::video::SColor(255, 0, 255, 0), 4);
    // irrDriver->draw2DLine(irr::core::vector2di(320, 240 - 200), irr::core::vector2di(320, 240 + 200), irr::video::SColor(255, 0, 0, 255));
    irrDriver->endScene();
}

void irrTest::addAModel()
{
}
void irrTest::addNormalCamera()
{
}

int main(int argc, char const *argv[])
{
    irrTest test;
    return 0;
}
