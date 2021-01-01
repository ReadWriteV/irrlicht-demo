#include <irrlicht.h>

int main(int argc, char const *argv[])
{
    auto *device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(640, 480), 16, false, false, false, 0);

    if (device == nullptr)
    {
        return 1;
    }

    auto driver = device->getVideoDriver();
    auto smgr = device->getSceneManager();

    auto mesh = smgr->getMesh("D:/SDK/irrlicht-1.8.4/media/sydney.md2");
    auto node = smgr->addAnimatedMeshSceneNode(mesh);

    if (node != nullptr)
    {
        node->setMD2Animation(irr::scene::EMAT_ATTACK);
        node->setAnimationSpeed(25);
        node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        node->setMaterialTexture(0, driver->getTexture("D:/SDK/irrlicht-1.8.4/media/sydney.bmp"));
    }

    smgr->addCameraSceneNode(0, irr::core::vector3df(0, 30, -40), irr::core::vector3df(0, 5, 0));
    while (device->run())
    {
        driver->beginScene(true, true, irr::video::SColor(255, 255, 255, 255));
        smgr->drawAll();
        driver->endScene();
    }
    device->drop();
    return 0;
}
