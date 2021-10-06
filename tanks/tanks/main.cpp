#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{
    RenderWindow window(VideoMode(640, 480), "Tanks");
    Image tank;
    tank.loadFromFile("images/t.png");
    //tank.createMaskFromColor(Color(255, 255, 255));

    Texture tanktexture;
    tanktexture.loadFromImage(tank);

    Sprite tanksprite;
    tanksprite.setTexture(tanktexture);
    tanksprite.setPosition(0, 0);
    tanksprite.setTextureRect(IntRect(0, 0, 16, 16));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Left)) { tanksprite.move(-0.01, 0); tanksprite.setTextureRect(IntRect(32, 0, 16, 16));};
        if (Keyboard::isKeyPressed(Keyboard::Right)) { tanksprite.move(0.01, 0); tanksprite.setTextureRect(IntRect(96, 0, 16, 16));};
        if (Keyboard::isKeyPressed(Keyboard::Up)) { tanksprite.move(0, -0.01); tanksprite.setTextureRect(IntRect(0, 0, 16, 16));};
        if (Keyboard::isKeyPressed(Keyboard::Down)) { tanksprite.move(0, 0.01); tanksprite.setTextureRect(IntRect(64, 0, 16, 16));};

        window.clear();
        window.draw(tanksprite);
        window.display();
    }

    return 0;
}