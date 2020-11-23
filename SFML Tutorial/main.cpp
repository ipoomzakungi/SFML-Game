#include <SFML\Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Platform.h"
#include "Mons.h"


static const float VIEW_HEIGHT = 768;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(1366, 768), "SFML Tutorial", sf::Style::Close | sf::Style::Resize);
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
    sf::View minimapView;
    minimapView.setViewport(sf::FloatRect(0.75f, 0, 0.25f, 0.25f));
    minimapView.setSize(2732, 1536);
    
    
    //player.setFillColor(sf::Color::Red);
    //player.setOrigin(50.0f, 50.0f);
    sf::Texture playerTexture;
    sf::Texture playerAttack;
    sf::Texture mapTop;
    sf::Texture mapMiddle;
    sf::Texture mapBottom;
    sf::Texture mapSide2Right;
    sf::Texture mapSide2Left;
    sf::Texture mapTopMid;
    sf::Texture mapMiddle2;
    sf::Texture monsterMushroom;
    sf::Texture slashEffect;
    sf::Texture testTexture;

    {
        playerTexture.loadFromFile("tux_from_linux.png");
        playerAttack.loadFromFile("playerattack.png");
        mapTop.loadFromFile("maptop.png");
        mapMiddle.loadFromFile("mapmiddle.png");
        mapBottom.loadFromFile("mapbottom.png");
        mapSide2Left.loadFromFile("mapside2left.png");
        mapSide2Right.loadFromFile("mapside2right.png");
        mapTopMid.loadFromFile("maptopmid.png");
        mapMiddle2.loadFromFile("mapmiddle2.png");
        monsterMushroom.loadFromFile("monsterMushroom.png");
        slashEffect.loadFromFile("slashEffect.png");
        testTexture.loadFromFile("testTexture.png");
    }
    
    sf::RectangleShape slash(sf::Vector2f(82.4f, 86.4f));
    slash.setOrigin(slash.getSize() / 2.0f);
    slash.setTexture(&slashEffect);
    

    
    mapTop.setRepeated(true);
    mapMiddle.setRepeated(true);
    mapBottom.setRepeated(true);
    mapSide2Left.setRepeated(true);
    mapSide2Right.setRepeated(true);
    mapTopMid.setRepeated(true);
    mapMiddle2.setRepeated(true);
    testTexture.setRepeated(true);

   


    ResizeView(window, view);
    
    Mons monsterMush(&monsterMushroom, sf::Vector2u(3, 1), 0.2f, 160.0f,200,50.0f, sf::Vector2f(66.0f, 60.0f), sf::Vector2f(400.0f, 800.0f));
    Player player(&playerTexture, sf::Vector2u(5, 3), 0.2f, 800.0f, 200,100); //speed 450.0f
    
    Player playerattack(&playerAttack, sf::Vector2u(3, 1), 0.15f, 800.0f, 200,100);

    std::vector<Platform> platforms;
    //std::vector<Mons> monsterMush;

    {
        
        //platforms.push_back(Platform(nullptr, sf::Vector2f(300.0f, 1100.0f), sf::Vector2f(0.0f, 1000.0f)));
        /*platforms.push_back(Platform(nullptr, sf::Vector2f(300.0f, 1100.0f), sf::Vector2f(-300.0f, 1000.0f)));
        platforms.push_back(Platform(nullptr, sf::Vector2f(1100.0f, 800.0f), sf::Vector2f(666.0f, 1313.0f)));
        platforms.push_back(Platform(nullptr, sf::Vector2f(4040.0f, 250.0f), sf::Vector2f(3630.0f, 1113.0f)));
        platforms.push_back(Platform(nullptr, sf::Vector2f(1500.0f, 600.0f), sf::Vector2f(1300.0f, 2000.0f)));
        platforms.push_back(Platform(nullptr, sf::Vector2f(500.0f, 600.0f), sf::Vector2f(2200.0f, 2250.0f)));
        platforms.push_back(Platform(nullptr, sf::Vector2f(1500.0f, 600.0f), sf::Vector2f(3150.0f, 2000.0f)));
        platforms.push_back(Platform(nullptr, sf::Vector2f(1500.0f, 600.0f), sf::Vector2f(3500.0f, 2200.0f)));
        platforms.push_back(Platform(nullptr, sf::Vector2f(1500.0f, 600.0f), sf::Vector2f(3850.0f, 2400.0f)));
        platforms.push_back(Platform(nullptr, sf::Vector2f(1500.0f, 600.0f), sf::Vector2f(4600.0f, 2600.0f)));
        platforms.push_back(Platform(nullptr, sf::Vector2f(300.0f, 1700.0f), sf::Vector2f(5500.0f, 2050.0f)));

        platforms.push_back(Platform(nullptr, sf::Vector2f(1200.0f, 1800.0f), sf::Vector2f(6600.0f, 2050.0f)));
        platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 2000.0f), sf::Vector2f(7300.0f, 1000.0f)));
        platforms.push_back(Platform(nullptr, sf::Vector2f(750.0f, 420.0f), sf::Vector2f(6500.0f, 600.0f)));
        platforms.push_back(Platform(nullptr, sf::Vector2f(600.0f, 1.0f), sf::Vector2f(7300.0f, 0.0f)));


        platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f)));
        platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f)));
        platforms.push_back(Platform(nullptr, sf::Vector2f(1500.0f, 200.0f), sf::Vector2f(400.0f, 375.0f)));*/
        platforms.push_back(Platform(&mapMiddle2, sf::Vector2f(630.0f, 180.0f), sf::Vector2f(-630.0f, 640.0f)));
        platforms.push_back(Platform(&mapMiddle2, sf::Vector2f(630.0f, 180.0f), sf::Vector2f(-630.0f, 820.0f)));

        platforms.push_back(Platform(&mapMiddle2, sf::Vector2f(630.0f, 180.0f), sf::Vector2f(0.0f, 460.0f)));
        platforms.push_back(Platform(&mapMiddle2, sf::Vector2f(630.0f, 180.0f), sf::Vector2f(630.0f, 460.0f)));

        platforms.push_back(Platform(&mapMiddle2, sf::Vector2f(630.0f, 180.0f), sf::Vector2f(0.0f, 1000.0f)));
        platforms.push_back(Platform(&mapMiddle2, sf::Vector2f(630.0f, 180.0f), sf::Vector2f(630.0f, 1000.0f)));
        platforms.push_back(Platform(&mapMiddle2, sf::Vector2f(630.0f, 180.0f), sf::Vector2f(0.0f, 1180.0f)));
        platforms.push_back(Platform(&mapMiddle2, sf::Vector2f(630.0f, 180.0f), sf::Vector2f(630.0f, 1180.0f)));

        platforms.push_back(Platform(&mapMiddle2, sf::Vector2f(630.0f, 180.0f), sf::Vector2f(1500.0f, 900.0f)));
        platforms.push_back(Platform(&mapMiddle2, sf::Vector2f(630.0f, 180.0f), sf::Vector2f(1860.0f, 900.0f)));

    }
    
   
    //monsterMush.push_back(Mons(&monsterMushroom, sf::Vector2u(3, 1), 0.2f, 450.0f, 200, sf::Vector2f(66.0f,60.0f), sf::Vector2f(400.0f, 800.0f)));

    float deltaTime = 0.0f;
    int playerstatus = 0;
    float attackSwitch = 0.0f;
    
    sf::Clock clock;

    

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        if (deltaTime > 1.0f / 20.0f)
            deltaTime = 1.0f / 20.0f;


        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
            case sf::Event::Closed: 
                window.close();
                break;
            case sf::Event::Resized:
                ResizeView(window, view);
                break;
            case sf::Event::TextEntered:
                if (evnt.text.unicode < 128)
                {
                    printf("%c", evnt.text.unicode);
                }

            }
           
        }

 

        
        /*if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            player.setPosition((float)mousePos.x, static_cast<float>(mousePos.y));
        }*/
        
        

        sf::Vector2f direction;

        //Collider playerCollision = player.GetCollider();


        

        for (Platform& platform : platforms)
        {
            Collider playerCollision = player.GetCollider();
            
            if (platform.GetCollider().CheckCollision(playerCollision, direction, 1.0f, 1))
            {
                player.OnCollision(direction, deltaTime, 0);
            }

            Collider playerattackCollision = playerattack.GetCollider();
            if (platform.GetCollider().CheckCollision(playerattackCollision, direction, 1.0f, 1))
            {
                playerattack.OnCollision(direction, deltaTime, 0);
            }

            /*Collider mushroomCollision = monsterMush.GetCollider();
            if (platform.GetCollider().CheckCollision(mushroomCollision, direction, 1.0f,1))
                monsterMush.OnCollision(direction, deltaTime,0);*/
            
            
        }

        

        
            
        Collider playerCollision = player.GetCollider();

        /*if (monsterMush.GetCollider().CheckCollision(playerCollision, direction, 1.0f, 0))
        {
            player.OnCollision(direction, deltaTime, 1);
   
        }*/

        
        


        view.setCenter(player.GetPosition());
        minimapView.setCenter(player.GetPosition());
        

        window.clear(sf::Color(150,150,150));

        window.setView(view);
        for (Platform& platform : platforms)
            platform.Draw(window);

       /* sf::Sprite mapSide2Right1;
        {
            mapSide2Right1.setTexture(mapSide2Right);
            mapSide2Right1.setPosition(sf::Vector2f(125.0f, -200.0f));
            mapSide2Right1.setTextureRect(sf::IntRect(0, 0, 42, 1500));
            window.draw(mapSide2Right1);
            mapSide2Right1.setPosition(sf::Vector2f(1185.0f, 907.0f));
            mapSide2Right1.setTextureRect(sf::IntRect(0, 0, 42, 1000));
            window.draw(mapSide2Right1);
            mapSide2Right1.setPosition(sf::Vector2f(2013.0f, 1700.0f));
            mapSide2Right1.setTextureRect(sf::IntRect(0, 0, 42, 250));
            window.draw(mapSide2Right1);
        }

        sf::Sprite mapTop1;
        {
            mapTop1.setTexture(mapTop);
            mapTop1.setPosition(sf::Vector2f(1216.0f, 1695.0f));
            mapTop1.setTextureRect(sf::IntRect(0, 0, 834, 39));
            window.draw(mapTop1);
            mapTop1.setPosition(sf::Vector2f(2050.0f, 1945.0f));
            mapTop1.setTextureRect(sf::IntRect(0, 0, 350, 39));
            window.draw(mapTop1);
            mapTop1.setPosition(sf::Vector2f(2400.0f, 1695.0f));
            mapTop1.setTextureRect(sf::IntRect(0, 0, 1500, 39));
            window.draw(mapTop1);
            mapTop1.setPosition(sf::Vector2f(3900.0f, 1895.0f));
            mapTop1.setTextureRect(sf::IntRect(0, 0, 350, 39));
            window.draw(mapTop1);

        }

        sf::Sprite mapMiddle1;
        {
            mapMiddle1.setTexture(mapMiddle);
            mapMiddle1.setPosition(sf::Vector2f(-20.0f, 1006.0f));
            mapMiddle1.setTextureRect(sf::IntRect(0, 0, 1208, 180));
            window.draw(mapMiddle1);
            

        }

        sf::Sprite mapMiddleH2;
        {
            mapMiddleH2.setTexture(mapMiddle2);
            mapMiddleH2.setPosition(sf::Vector2f(-600.0f, 1006.0f));
            mapMiddleH2.setTextureRect(sf::IntRect(0, 0, 1788, 800));
            window.draw(mapMiddleH2);
            mapMiddleH2.setPosition(sf::Vector2f(316.0f, 1734.0f));
            mapMiddleH2.setTextureRect(sf::IntRect(0, 0, 1734, 800));
            window.draw(mapMiddleH2);
            mapMiddleH2.setPosition(sf::Vector2f(-713.0f, 0.0f));
            mapMiddleH2.setTextureRect(sf::IntRect(0, 0, 867, 1010));
            window.draw(mapMiddleH2);
            mapMiddleH2.setPosition(sf::Vector2f(127.0f, 0.0f));
            mapMiddleH2.setTextureRect(sf::IntRect(0, 0, 1030, 480));
            window.draw(mapMiddleH2);
            
        }

        sf::Sprite mapTopMid1;
        {
            mapTopMid1.setTexture(mapTopMid);
            mapTopMid1.setPosition(sf::Vector2f(100.0f, 907.0f));
            mapTopMid1.setTextureRect(sf::IntRect(0, 0, 1118, 99));
            window.draw(mapTopMid1);
            mapTopMid1.setPosition(sf::Vector2f(1605.0f, 995.0f));
            mapTopMid1.setTextureRect(sf::IntRect(0, 0, 4044, 99));
            window.draw(mapTopMid1);


        }*/


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        {
            playerattack.Draw(window);
            playerstatus = 1;
            
            if (!player.SlashFaceRight())
            {
                slash.setPosition(player.GetPosition().x + 42.4f, player.GetPosition().y);
                slash.setRotation(180.0f);
            }
            else
            {
                slash.setPosition(player.GetPosition().x - 42.4f, player.GetPosition().y);
                slash.setRotation(0.0f);

            }
            
            attackSwitch += deltaTime;
            //printf("%.2f\n", attackSwitch);
            window.draw(slash);
            if (attackSwitch > 0.45f)
            {
                
                Collider mushroomCollision = monsterMush.GetCollider();
                
                /*if (Collider(slash).CheckCollision(mushroomCollision, direction, 0.0f, 1))
                {
                    monsterMush.OnCollision(direction, deltaTime,1);
                    if (player.GetPosition().x >= monsterMush.GetPosition().x)
                    {
                        monsterMush.monsGetHitFrom(true);
                    }
                       
                    else
                        monsterMush.monsGetHitFrom(false);
                    printf("HIT\n");
                }
                    
                attackSwitch -= 0.45f;*/
            }
            
        }
        else
        {
            player.Draw(window);
            playerstatus = 0;
        }
        
        
        monsterMush.Draw(window);

        window.setView(minimapView);

        for (Platform& platform : platforms)
            platform.Draw(window);

        player.Draw(window);

        

        
        






        
        
        player.Update(deltaTime, playerstatus);
        playerattack.Update(deltaTime, playerstatus);

        //monsterMush.Update(deltaTime, sf::Vector2f(190.0f, 190.0f));
       
       
       
       

        window.display();
    }

    return 0;
}