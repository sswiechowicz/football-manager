
#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>
#include <string>

int main()
{
    // Tworzenie okna gry
    sf::RenderWindow window(
        sf::VideoMode({1000, 700}),
        "FOOTBALL MANAGER"
    );

    window.setFramerateLimit(60);

    // Dane gracza
    int grass = 0;
    int grassPerClick = 1;

    // Czcionka
    sf::Font font;

    if (!font.openFromFile("C:/Windows/Fonts/arial.ttf"))
    {
        std::cout << "Nie udalo sie zaladowac czcionki!\n";
        return 1;
    }

    // Licznik trawki
    sf::Text grassText(font);
    grassText.setCharacterSize(32);
    grassText.setFillColor(sf::Color::White);
    grassText.setPosition({30.f, 25.f});

    // Informacja o klikaniu
    sf::Text infoText(font);
    infoText.setString("Klikaj pilke, aby zdobywac trawe!");
    infoText.setCharacterSize(22);
    infoText.setFillColor(sf::Color::White);
    infoText.setPosition({3020.f, 620.f});

    // Piłka
    sf::CircleShape ball(110.f);
    ball.setFillColor(sf::Color::White);
    ball.setOutlineThickness(6.f);
    ball.setOutlineColor(sf::Color::Black);
    ball.setOrigin({110.f, 110.f});
    ball.setPosition({500.f, 330.f});

    // Sklep
    sf::RectangleShape shopButton({220.f, 65.f});
    shopButton.setFillColor(sf::Color(40, 100, 220));
    shopButton.setPosition({740.f, 25.f});

    sf::Text shopText(font);
    shopText.setString("SKLEP");
    shopText.setCharacterSize(28);
    shopText.setFillColor(sf::Color::White);
    shopText.setPosition({805.f, 38.f});

    // Pętla gry
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            // Kliknięcie myszką
            if (const auto* mouse =
                event->getIf<sf::Event::MouseButtonPressed>())
            {
                if (mouse->button == sf::Mouse::Button::Left)
                {
                    sf::Vector2f mousePosition(
                        static_cast<float>(mouse->position.x),
                        static_cast<float>(mouse->position.y)
                    );

                    // Kliknięcie piłki
                    if (ball.getGlobalBounds().contains(mousePosition))
                    {
                        grass += grassPerClick;
                    }
                }
            }
        }

        // Aktualizacja licznika
        grassText.setString(
            "TRAWA: " + std::to_string(grass) +
            "\nZa klikniecie: " + std::to_string(grassPerClick)
        );

        // Rysowanie
        window.clear(sf::Color(30, 110, 55));

        window.draw(grassText);
        window.draw(infoText);
        window.draw(ball);
        window.draw(shopButton);
        window.draw(shopText);

        window.display();
    }

    return 0;
}
