#include <irrlicht.h>

int main(int argc, char const *argv[])
{
    irr::IrrlichtDevice *device = irr::createDevice(irr::video::EDT_SOFTWARE, irr::core::dimension2d<irr::u32>(640, 480), 16, false, false, false, 0);

    if (device == nullptr)
    {
        return 1;
    }

    device->sleep(2000);
    device->drop();
    return 0;
}
