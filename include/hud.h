#ifndef HUD_H
#define HUD_H
#import <vector>
#import <SFML/Graphics.hpp>
class hud
{
    public:
        hud();
        sf::Sprite getPseta();
        std::vector<sf::Sprite> getLife();
        std::vector<sf::Sprite> getPup();
        sf::Text getTxtPseta();
        sf::Text getTxtCrono();
        void loseLife();

    private:
        sf::Text    txtCrono;
        sf::Text    txtPseta;

        sf::Sprite  sPseta;

        std::vector<sf::Sprite> sLife;
        std::vector<sf::Sprite> sPup;
};

#endif // HUD_H
