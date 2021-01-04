#include <irrlicht.h>

int main(int argc, char const *argv[])
{
    auto *device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1366, 768), 16, false, false, false, nullptr);

    if (device == nullptr)
    {
        return -1;
    }

    auto driver = device->getVideoDriver();
    auto smgr = device->getSceneManager();
    auto ps = smgr->addParticleSystemSceneNode(false);
    auto pEmitter = ps->createBoxEmitter(irr::core::aabbox3d<irr::f32>(-5.0f, 0.0f, -5.0f, 5.0f, 1.0f, 5.0f), irr::core::vector3df(0.0f, 0.1f, 0.0f), 50, 200, irr::video::SColor(0, 0, 0, 255), irr::video::SColor(0, 255, 255, 255), 800, 1000, 0, irr::core::dimension2df(10.0f, 10.0f), irr::core::dimension2df(20.0f, 20.0f));

    ps->setEmitter(pEmitter);
    pEmitter->drop();

    ps->setPosition(irr::core::vector3df(0.0f, -10.0f, 0.0f));
    ps->setScale(irr::core::vector3df(2.0f, 2.0f, 2.0f));
    ps->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    ps->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
    ps->setMaterialTexture(0, driver->getTexture("D:/SDK/irrlicht-1.8.4/media/fireball.bmp"));
    ps->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);

    auto camera = smgr->addCameraSceneNodeFPS(nullptr, 100.0f, 0.2f);
    camera->setPosition(irr::core::vector3df(50.0f, 20.0f, 50.0f));
    camera->setTarget(irr::core::vector3df(0, 0, 0));

    device->getCursorControl()->setVisible(false);

    while (device->run())
    {
        driver->beginScene(true, true, irr::video::SColor(255, 100, 101, 140));
        smgr->drawAll();
        driver->endScene();
    }
    device->drop();
    return 0;
}
