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

    if (!device->getFileSystem()->addFileArchive("D:/SDK/irrlicht-1.8.4/media/map-20kdm2.pk3"))
    {
        device->drop();
        return 1;
    }
    auto mesh = smgr->getMesh("20kdm2.bsp");
    if (mesh == nullptr)
    {
        device->drop();
        return 1;
    }

    auto node = smgr->addOctreeSceneNode(mesh->getMesh(0), 0);
    if (node == nullptr)
    {
        device->drop();
        return 1;
    }
    node->setPosition(irr::core::vector3df(-1350, -130, -1400));

    irr::SKeyMap keyMap[4];
    keyMap[0].Action = irr::EKA_MOVE_FORWARD;
    keyMap[0].KeyCode = irr::KEY_KEY_W;
    keyMap[1].Action = irr::EKA_MOVE_BACKWARD;
    keyMap[1].KeyCode = irr::KEY_KEY_S;
    keyMap[2].Action = irr::EKA_STRAFE_LEFT;
    keyMap[2].KeyCode = irr::KEY_KEY_A;
    keyMap[3].Action = irr::EKA_STRAFE_RIGHT;
    keyMap[3].KeyCode = irr::KEY_KEY_D;

    auto fps_camera = smgr->addCameraSceneNodeFPS(0, 100, 1.2f, -1, keyMap, 8);
    fps_camera->setPosition(irr::core::vector3df(50, 50, -60));
    fps_camera->setTarget(irr::core::vector3df(-70, 30, -60));
    device->getCursorControl()->setVisible(false);

    auto node1 = smgr->addAnimatedMeshSceneNode(smgr->getMesh("D:/SDK/irrlicht-1.8.4/media/ninja.b3d"));
    node1->setScale(irr::core::vector3df(10));
    node1->setPosition(irr::core::vector3df(-75, -66, -30));
    node1->setRotation(irr::core::vector3df(0, 90, 0));
    node1->setAnimationSpeed(8.f);
    node1->getMaterial(0).NormalizeNormals = true;
    node1->getMaterial(0).Lighting = true;

    while (device->run())
    {
        driver->beginScene(true, true, irr::video::SColor(255, 255, 255, 255));
        smgr->drawAll();
        driver->endScene();
    }
    device->drop();
    return 0;
}
