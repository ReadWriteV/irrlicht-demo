#include <irrKlang.h>
#include <iostream>

int main(int argc, char const *argv[])
{
    auto engine = irrklang::createIrrKlangDevice();

    if (engine == nullptr)
    {
        return 0;
    }

    engine->play2D("D:\\SDK\\irrKlang-1.6.0\\media\\getout.ogg", true);

    char i = 0;
    while (i != 'q')
    {
        std::cout << "input 'q' to quit" << std::endl;
        engine->play2D("D:\\SDK\\irrKlang-1.6.0\\media\\bell.wav");
        std::cin >> i;
    }

    engine->drop();
    return 0;
}
