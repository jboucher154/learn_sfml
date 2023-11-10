#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

void    moveCircle( sf::CircleShape& circle, float delta, sf::Keyboard::Key key) {

    sf::Vector2 speed(400,400);
    sf::Vector2 position(0.0f, 0.0f);

    // position.x = speed.x * delta;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        std::cout << "Circle should move" << std::endl;//
        position.y  -= speed.y * delta;
    }
    // }
    if (key == sf::Keyboard::W) {
        // std::cout << "Circle should move" << std::endl;//
        position.y  -= speed.y * delta;
    }
    if (key == sf::Keyboard::S) {
        position.y  += speed.y * delta;
        // std::cout << "Circle should move" << std::endl;//
    }
    // position.x += circle.getPosition().x;
    // position.y += circle.getPosition().y;
    // circle.setPosition(position);
    circle.move(position);
}

int main()
{
    auto window = sf::RenderWindow{ { 920u, 1080u }, "My game!" };
    window.setFramerateLimit(144);
    sf::Clock   clock;
    float       delta_time = 0.0f;

    
    sf::CircleShape circle(100.f);
    circle.setFillColor(sf::Color::Green);
    circle.setOrigin(circle.getLocalBounds().width / 2, circle.getLocalBounds().height / 2);
    circle.setPosition(window.getSize().x / 2, window.getSize().y / 2);

    while (window.isOpen())
    {
        delta_time = clock.restart().asSeconds();
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) {
                std::cout << "Key was pressed!" << std::endl;
                if (event.key.code == sf::Keyboard::W) 
                    std::cout << "W!" << std::endl;
                if (event.key.code == sf::Keyboard::S) 
                    std::cout << "S!" << std::endl;
                moveCircle(circle, delta_time, event.key.code);
            }
        }
        window.clear();
        window.draw(circle);
        window.display();
    }
}
