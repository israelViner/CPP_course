#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

sf::CircleShape create_circle()
{
    sf::CircleShape circle(30.f);

    float x = (std::rand() % 870) + 50;
    float y = (std::rand() % 470) + 50;

    circle.setOrigin(sf::Vector2f(-x, -y));
    circle.setFillColor(sf::Color(255, 204, 204));
    circle.setOutlineThickness(4.f);
    circle.setOutlineColor(sf::Color::Red);
    return circle;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML window");

    sf::RectangleShape rectangle(sf::Vector2f(1000.f, 600.f));
    rectangle.setFillColor(sf::Color(153, 255, 255));
    rectangle.setOutlineThickness(-15.f);
    rectangle.setOutlineColor(sf::Color::Blue);

    sf::CircleShape circle(30.f);
    circle.setPosition(sf::Vector2f(rectangle.getPosition().x - rectangle.getOutlineThickness(), rectangle.getPosition().y - rectangle.getOutlineThickness()));
    circle.setFillColor(sf::Color(255, 204, 204));
    circle.setOutlineThickness(4.f);
    circle.setOutlineColor(sf::Color::Red);

    sf::Clock clock;    

    sf::Vector2f dir(0.3f, 0.3f);

    std::vector<sf::CircleShape> circles_vector;

    sf::Music music;
    if (!music.openFromFile("sound/background1.ogg"))
        return EXIT_FAILURE;
    music.play();

    sf::SoundBuffer buffer;    
    if (!buffer.loadFromFile("sound/laser.ogg")) {
        return EXIT_FAILURE;
    }
    sf::Sound sound;
    sound.setBuffer(buffer);

    while (window.isOpen()) {
        
        sf::Event event;
        window.pollEvent(event);
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }        

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && clock.getElapsedTime().asSeconds() > 1) {
            sf::CircleShape new_circle = create_circle();
            circles_vector.push_back(new_circle);
            clock.restart();
        }

        if (circle.getPosition().x < rectangle.getPoint(0).x - rectangle.getOutlineThickness() || circle.getPosition().x + circle.getPoint(9).x >=  rectangle.getPoint(2).x + rectangle.getOutlineThickness()) {
            dir.x *= -1;
        }
        if (circle.getPosition().y < rectangle.getPoint(0).y - rectangle.getOutlineThickness() || circle.getPosition().y + circle.getRadius() * 2 >= rectangle.getPoint(2).y + rectangle.getOutlineThickness()) {
            dir.y *= -1;
        }

        circle.move(dir);

        sf::FloatRect boundingBox = circle.getGlobalBounds();

        auto start_it = circles_vector.begin();
        auto end_it = circles_vector.end();
        while (start_it != end_it) {
            if (boundingBox.intersects((*start_it).getGlobalBounds())) {
                circles_vector.erase(start_it);
                dir.x *= -1;
                dir.y *= -1;
                
                sound.play();           
        }             
                      
            ++start_it;
        }
        window.clear();

        window.draw(rectangle);
        window.draw(circle);


       
        start_it = circles_vector.begin();
        while (start_it != end_it) {
            window.draw(*start_it);
            ++start_it;
        }

        window.display();
    }
    return EXIT_SUCCESS;
}