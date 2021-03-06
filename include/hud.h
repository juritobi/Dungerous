#ifndef HUD_H
#define HUD_H
#import <vector>
#import <SFML/Graphics.hpp>

class hud
{
    public:
        static hud* getHud();
        sf::Sprite getPseta();
        int getPsetaNum();
        std::vector<sf::Sprite> getLife();
        std::vector<sf::Sprite> getPup();
        sf::Text getTxtPseta();
        sf::Text getTxtCrono();
        void loseLife(int i);
        void setLife(int i);
        void setPup(int i);
        void setPseta(int i);
        bool setCrono(sf::Clock c, int i);
        void loseCrono();
        void comprobarReloj();
        sf::Time sumaTiempo;
        sf::Clock tiempoPausa;

        void restart();


    private:
        static hud* hudo;
        bool        relojACero;
        hud();
        sf::Texture tLife;
        sf::Texture tPseta;
        sf::Texture tVida;
        sf::Texture tFuerza;
        sf::Texture tVel;
        sf::Font    mFont;
        sf::Text    txtCrono;
        sf::Text    txtPseta;
        int         numPseta;
        sf::Clock   mClock;//esto es provisional, deberia tener uno cada sala
        sf::Sprite  sPseta;
        sf::Sprite  sVida;
        sf::Sprite  sVel;
        sf::Sprite  sFuerza;
        int         vVida;
        int         vVel;
        int         vFuerza;
        int         tiempo; //provisional
        int         posAdd;
        std::vector<sf::Sprite> sLife;
        std::vector<sf::Sprite> sPup;
};

#endif // HUD_H
