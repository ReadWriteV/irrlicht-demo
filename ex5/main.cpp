#include <irrlicht.h>

int main(int argc, char const *argv[])
{
    auto *device = irr::createDevice(irr::video::EDT_SOFTWARE, irr::core::dimension2d<irr::u32>(640, 480), 16, false, false, false, 0);

    if (device == nullptr)
    {
        return 1;
    }

    auto driver = device->getVideoDriver();
    auto smgr = device->getSceneManager();

    auto mesh = smgr->getMesh("D:/SDK/irrlicht-1.8.4/media/sydney.md2");
    if (mesh == nullptr)
    {
        device->drop();
        return 1;
    }

    auto node = smgr->addAnimatedMeshSceneNode(mesh);
    auto node1 = smgr->addAnimatedMeshSceneNode(mesh);

    if (node != nullptr && node1 != nullptr)
    {
        node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        node->setMD2Animation(irr::scene::EMAT_RUN);
        node->setMaterialTexture(0, driver->getTexture("D:/SDK/irrlicht-1.8.4/media/sydney.bmp"));

        node1->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        node1->setMD2Animation(irr::scene::EMAT_RUN);
        node1->setMaterialTexture(0, driver->getTexture("D:/SDK/irrlicht-1.8.4/media/sydney.bmp"));

        node->addChild(node1);

        node1->setPosition(irr::core::vector3df(-30, 0, 40));
    }

    smgr->addCameraSceneNode(0, irr::core::vector3df(110, 120, 50), irr::core::vector3df(0, 50, 0));
    auto anim = smgr->createFlyStraightAnimator(irr::core::vector3df(0.0f, 0.8f, 0.0f), irr::core::vector3df(100.0f, 100.8f, 0.0f), 4000, true, true);
    node->addAnimator(anim);
    while (device->run())
    {
        driver->beginScene(true, true, irr::video::SColor(255, 255, 255, 255));
        smgr->drawAll();
        driver->endScene();
    }
    device->drop();
    return 0;
}
