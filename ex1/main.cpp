#include <irrlicht.h>

int main(int argc, char const *argv[])
{
    irr::IrrlichtDevice *device = irr::createDevice(irr::video::EDT_SOFTWARE, irr::core::dimension2d<irr::u32>(640, 480), 16, false, false, false, 0);

    if (device == nullptr)
    {
        return 1;
    }

    device->setWindowCaption(L"Test Window");

    irr::video::IVideoDriver *driver = device->getVideoDriver();
    irr::scene::ISceneManager *smgr = device->getSceneManager();
    irr::gui::IGUIEnvironment *gui = device->getGUIEnvironment();

    while (device->run())
    {
        driver->beginScene(true, true, irr::video::SColor(255, 255, 255, 255));
        smgr->drawAll();
        gui->drawAll();
        driver->endScene();
    }

    device->drop();
    return 0;
}
