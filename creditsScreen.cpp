//
// Created by joseph on 4/21/17.
//

#include "creditsScreen.h"

CreditsScreen::CreditsScreen() {
    if (!classicFont.loadFromFile("Resources/menu/8bit.ttf"))
    {
        std::cerr << "Error loading 8bit.ttf" << std::endl;
    }

    creditsFile.open("Resources/credits.txt");

    backgroundMusic.openFromFile("Resources/credits.ogg");
    backgroundMusic.setLoop(true);
    backgroundMusic.setVolume(100);

    if (creditsFile.is_open()) {
        while (getline(creditsFile, line)) {
            creditsStr += line + "\n";
        }
        creditsFile.close();
    } else {
        creditsStr = "ERROR: COULDN'T OPEN CREDITS.TXT";
    }

}

int CreditsScreen::run(sf::RenderWindow &window, sf::Texture &pauseScreen, Options *gameOptions) {
    const int SCREEN_WIDTH = window.getSize().x;
    const int SCREEN_HEIGHT = window.getSize().y;
    const float scale = 0.8; /// I used 0.8 so you have space for the title(top) and a "back" button (bottom)
    const float invScale = 1 / scale; /// 1.25 in the example

    backgroundMusic.play();

    creditsView.setSize(SCREEN_WIDTH,SCREEN_HEIGHT);
    creditsView.setCenter(SCREEN_WIDTH / 2, SCREEN_HEIGHT/ 2);
    creditsView.setViewport(sf::FloatRect(0, (1 - scale) / 2, scale, scale));

    ///Title
    sf::Text titleCredit("Credits", classicFont, SCREEN_HEIGHT / 12);
    titleCredit.setPosition( ( SCREEN_WIDTH - titleCredit.getGlobalBounds().width) / 2, 0);
    titleCredit.setColor(sf::Color::White);

    ///Credits themselves. You can read it from a file using fstreams. The credits are centered, and each text is left aligned.
    ///However, each one isn't centered.
    ///If you want each to be centered you have to create a sf::Text for each one.
    sf::Text creditText(creditsStr, classicFont, SCREEN_WIDTH / 16);
    creditText.setPosition( ( SCREEN_WIDTH * invScale - creditText.getGlobalBounds().width) / 2, SCREEN_HEIGHT);
    creditText.setColor(sf::Color::White);


    while (running) {
        while (window.pollEvent(event)){
            // Window closed
            if (event.type == sf::Event::Closed) {
                backgroundMusic.stop();
                return 0;
            }
            if (event.type == sf::Event::KeyPressed) {
                backgroundMusic.stop();
                return 0;
            }
        }

        time = clock.getElapsedTime();

        ///Move the credits upward. You may want this to be tied to a sf::Clock/sf::Time and move it taking into account the delta time
        creditsView.move(0, SCREEN_HEIGHT * 0.00015 * time.asMilliseconds());
        ///Reset the view if they go "too far"
        if(creditsView.getCenter().y > SCREEN_HEIGHT * 2 + creditText.getGlobalBounds().height + creditText2.getGlobalBounds().height){
            creditsView.setCenter(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
        }

        window.clear();
        ///set the view for the credits, and then show them
        window.setView(creditsView);
        window.draw(creditText);
        ///set the default view, so that the title doesn't get moved and then show the title
        window.setView(window.getDefaultView());
        window.draw(titleCredit);
        window.draw(creditText);
        ///display all
        clock.restart().asMilliseconds();
        window.display();


    }

    return 0;
}
