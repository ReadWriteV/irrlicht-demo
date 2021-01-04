#include <irrlicht.h>
#include <driverChoice.h>

int main(int argc, char const *argv[])
{

    irr::video::E_DRIVER_TYPE driverType = irr::driverChoiceConsole();
    if (driverType == irr::video::EDT_COUNT)
    {
        return 1;
    }

    auto *device = irr::createDevice(driverType, irr::core::dimension2d<irr::u32>(640, 480), 16, false, true);

    if (device == nullptr)
    {
        return 1;
    }

    auto driver = device->getVideoDriver();
    auto smgr = device->getSceneManager();

    auto mesh = smgr->getMesh("D:/SDK/irrlicht-1.8.4/media/room.3ds");
    smgr->getMeshManipulator()->makePlanarTextureMapping(mesh->getMesh(0), 0.004f);

    irr::scene::ISceneNode *node = smgr->addAnimatedMeshSceneNode(mesh);
    node->setMaterialTexture(0, driver->getTexture("D:/SDK/irrlicht-1.8.4/media/wall.jpg"));
    node->getMaterial(0).SpecularColor.set(0, 0, 0, 0);
    node = smgr->addLightSceneNode(0, irr::core::vector3df(0, 0, 0), irr::video::SColorf(1.0f, 0.6f, 0.7f, 1.0f));

    auto anim = smgr->createFlyCircleAnimator(irr::core::vector3df(0, 150, 0), 250.0f);
    node->addAnimator(anim);
    anim->drop();

    node = smgr->addBillboardSceneNode(node, irr::core::dimension2d<irr::f32>(50, 50));
    node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    node->setMaterialTexture(0, driver->getTexture("D:/SDK/irrlicht-1.8.4/media/particlewhite.bmp"));

    mesh = smgr->getMesh("D:/SDK/irrlicht-1.8.4/media/dwarf.x");
    auto anode = smgr->addAnimatedMeshSceneNode(mesh);
    anode->setPosition(irr::core::vector3df(-50, 20, -60));
    anode->setAnimationSpeed(25);

    anode->addShadowVolumeSceneNode();
    smgr->setShadowColor(irr::video::SColor(150, 0, 0, 0));

    anode->setScale(irr::core::vector3df(2, 2, 2));
    anode->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, true);

    auto camera = smgr->addCameraSceneNodeFPS();
    camera->setPosition(irr::core::vector3df(-50, 50, -150));
    camera->setFarValue(10000.0f);

    device->getCursorControl()->setVisible(false);

    irr::s32 lastFPS = -1;

    while (device->run())
    {
        if (device->isWindowActive())
        {
            driver->beginScene(true, true, 0);
            smgr->drawAll();
            driver->endScene();

            const irr::s32 fps = driver->getFPS();
            if (lastFPS != fps)
            {
                irr::core::stringw str = L"Irrlicht Engine - Special example [";
                str += driver->getName();
                str += "] FPS:";
                str += fps;

                device->setWindowCaption(str.c_str());
                lastFPS = fps;
            }
        }
    }
    device->drop();
    return 0;
}
