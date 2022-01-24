#include <SFML/Graphics.hpp>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    sf::RectangleShape rectangle(sf::Vector2f(128.0f, 128.0f));
    rectangle.setFillColor(sf::Color::White);
    rectangle.setPosition(320, 240);
    int inc = 0;
    int number=4;
    int x = 0;
    int y = 0;
    int size = 1;
    int lastSize = 0;
    int storage;
    // run the program as long as the window is open
    
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        while (inc != number) {
            rectangle.setPosition(x, y);
            window.draw(rectangle); // Drawing our shape.
            rectangle.setSize(sf::Vector2f(size, size));
            storage = lastSize;
            size = size + lastSize;
            lastSize = storage;
            x = 0 + size;
            inc++;
        }

        // draw everything here...
        // window.draw(...);
        // end the current frame
        window.display();
    }

    return 0;
}