#include <irrlicht.h>

int main(int argc, char const *argv[])
{
    auto *device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(640, 480), 16, false, false, false, 0);

    if (device == nullptr)
    {
        return 1;
    }

    auto driver = device->getVideoDriver();

    auto image = driver->getTexture("D:/SDK/irrlicht-1.8.4/media/irrlichtlogo2.png");

    while (device->run())
    {
        driver->beginScene(true, true, irr::video::SColor(255, 255, 255, 255));
        driver->draw2DImage(image, irr::core::rect<irr::s32>(50, 50, 100, 450), irr::core::rect<irr::s32>(0, 0, 128, 128), 0, 0, true);
        driver->endScene();
    }

    device->drop();
    return 0;
}
