#include <iostream>
#include <cstdlib>
#include "menu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
//if (Keyboard::isKeyPressed(Keyboard::Escape)) window.close();
void menu(RenderWindow& window )
{
    Music music;
    music.openFromFile("../Sound/March.ogg");
    music.play();

    Image     menubackground;       menubackground.loadFromFile("../Images/menu/menu.jpg");
    //run.createMaskFromColor(Color(41, 33, 59));
    Texture   menutexture;          menutexture.loadFromImage(menubackground);
    Sprite    menusprite;           menusprite.setTexture(menutexture);
    menusprite.setPosition(0, 0);



    Image     run;              run.loadFromFile("../Images/menu/Start.jpg");
    //run.createMaskFromColor(Color(0, 0, 0));
   // run.createMaskFromColor(Color(41, 33, 59));
    Texture   runtexture;       runtexture.loadFromImage(run);
    Sprite    runsprite;        runsprite.setTexture(runtexture);
    runsprite.setPosition(150, 150);
    runsprite.setScale(0.3f, 0.3f);

    //-------------------------------------------------------level made

    Image     exitgame;             exitgame.loadFromFile("../Images/menu/exit.png");

    Texture   exitgametexture;      exitgametexture.loadFromImage(exitgame);
    Sprite    exitgamesprite;       exitgamesprite.setTexture(exitgametexture);
    exitgamesprite.setPosition(600, 120);
    exitgamesprite.setScale(0.15f, 0.15f);

    /*//-------------------------------------------------exit made

    Image     info;             info.loadFromFile("../Images/menu/about.png");
    Texture   infotexture;      infotexture.loadFromImage(info);
    Sprite    infosprite;       infosprite.setTexture(infotexture);
    infosprite.setPosition(1100, 10);
*/
    //-------------------------------------------------about made
    music.setLoop(true);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
            if (event.type == Event::Closed)
                window.close();

        int menuNum = 0;

        //--------------------------------------------making color when aiming

            if (IntRect(150, 150, 240, 180).contains(Mouse::getPosition(window))) { runsprite.setColor(Color::Green); menuNum = 0; }

        if (IntRect(600, 120, 240, 240).contains(Mouse::getPosition(window))) { exitgamesprite.setColor(Color::Red); menuNum = 1; }

        //-------------------------------------------clearing color when out
        if (!IntRect(150, 150, 240, 180).contains(Mouse::getPosition(window))) { runsprite.setColor(Color::White); }

        if (!IntRect(600, 120, 240, 240).contains(Mouse::getPosition(window))) { exitgamesprite.setColor(Color::White); }


        if (Mouse::isButtonPressed(Mouse::Left))
        {
            switch (menuNum)
            {
                case 0:
                {   music.pause();
                    RenderWindow new_window(VideoMode(1920, 1080), "LEVEL");
                    window.close();

                   start_menu_levels(new_window);
                    new_window.close();

                    std::cout<<"level1";
                    break;
                }


                case 1:
                    window.close();
                    break;

                default:
                    break;
            }
            if (menuNum ==0)
            {
                RenderWindow after_window(VideoMode(1920, 1080), "IGRA");
                menu(after_window);
            }


        }
        window.clear();
        window.draw(menusprite);
        window.draw(runsprite);
        window.draw(exitgamesprite);


        window.display();
    }
}

    void start_menu_levels(RenderWindow& window1)
{

    Image     level1;             level1.loadFromFile("../Images/menu/level1.png");
    Texture   level1texture;      level1texture.loadFromImage(level1);
    Sprite    level1sprite;       level1sprite.setTexture(level1texture);
    level1sprite.setPosition(0, 0);
    Image     level2;             level2.loadFromFile("../Images/menu/level2.png");
    Texture   level2texture;      level2texture.loadFromImage(level2);
    Sprite    level2sprite;       level2sprite.setTexture(level2texture);
    level2sprite.setPosition(0, 250);
    Image     level3;             level3.loadFromFile("../Images/menu/level3.png");
    Texture   level3texture;      level3texture.loadFromImage(level3);
    Sprite    level3sprite;       level3sprite.setTexture(level3texture);
    level3sprite.setPosition(0, 500);
    Image     leveld;             leveld.loadFromFile("../Images/menu/leveld.jpg");
    Texture   leveldtexture;      leveldtexture.loadFromImage(leveld);
    Sprite    leveldsprite;       leveldsprite.setTexture(leveldtexture);
    leveldsprite.setPosition(0, 0);




    while (window1.isOpen())
    {
        Event event1;
        while (window1.pollEvent(event1))
            if (event1.type == Event::Closed)
                window1.close();
        int level=0;
        if (IntRect(0, 0, 216, 87).contains(Mouse::getPosition(window1))) { level1sprite.setColor(Color::Green); level = 0; }
        if (IntRect(0, 250, 215, 87).contains(Mouse::getPosition(window1))) { level2sprite.setColor(Color::Blue); level = 1; }
        if (IntRect(0, 500, 215, 87).contains(Mouse::getPosition(window1))) { level3sprite.setColor(Color::Red); level = 2; }
        if (!IntRect(0, 0, 216, 87).contains(Mouse::getPosition(window1))) { level1sprite.setColor(Color::White);  }
        if (!IntRect(0, 250, 215, 87).contains(Mouse::getPosition(window1))) { level2sprite.setColor(Color::White); }
        if (!IntRect(0, 500, 215, 87).contains(Mouse::getPosition(window1))) { level3sprite.setColor(Color::White);  }

        if (Mouse::isButtonPressed(Mouse::Left))
        {
            switch (level)
            {
                case 0:
                {
                    RenderWindow new_window(VideoMode(1920, 1080), "level1");
                    window1.close();
                    run_level(new_window, 1);
                    break;
                }


                case 1:
                {   RenderWindow new_window(VideoMode(1920, 1080), "level2");
                    window1.close();
                    run_level(new_window, 2);
                    break;
                }
                case 2:
                {
                    RenderWindow new_window(VideoMode(1920, 1080), "level3");
                    window1.close();
                    run_level(new_window, 3);
                    break;
                }
                default:
                    break;

            }


        }

        window1.clear();
        window1.draw(leveldsprite);
        window1.draw(level1sprite);
        window1.draw(level2sprite);
        window1.draw(level3sprite);

        // window.draw(textsprite);
        window1.display();
    }






};
void run_level(RenderWindow& window,int i)
{window.close();
    std::cout<<i;

}

