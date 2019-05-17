#include "../include/Proyectil.h"
#include "../include/App.h"
/*
Proyectil::Proyectil(float x, float y, float ndireccion, sf::Vector2f posInicial):
animationHachaBoss( 0.1f,sf::Vector2u(4, 1),"flechas")
,animationBolaFuego(0.1f,sf::Vector2u(5,1),"fireball")
,calculado(false)
{
    firstState=posInicial;
    lastState=firstState;
    tipoBala=ndireccion;
    body.setScale(sf::Vector2f(0.5,0.5));
    body.setPosition(posInicial);
    body.setTexture(AssetManager::getAssetManager()->GetTexture("flechas"));
    varx = 0;
    vary = 0;
}
*/
Proyectil::Proyectil(float ndireccion, sf::Vector2f posInicial, int dirx, int diry):
Boss(0.1f,sf::Vector2u(4, 1),"fuego")
,Hacha(0.1f,sf::Vector2u(4, 1),"flechas")
,BolaFuego(0.1f,sf::Vector2u(5, 1),"fireball")
,calculado(false)
{

    firstState.x=posInicial.x;
    firstState.y=posInicial.y;
    lastState=firstState;
    tipoBala=ndireccion;
    //body.setScale(sf::Vector2f(4,4));
    speed=500.0f;
    existe=true;
    body.setPosition(posInicial);
    varx=dirx;
    vary=diry;


     if(tipoBala>=1 && tipoBala<5){
        body.setTexture(AssetManager::getAssetManager()->GetTexture("flechas"));
        body.setOrigin(50.0f,50.0f);
     }
     else if(tipoBala==5 || tipoBala==6){
        body.setTexture(AssetManager::getAssetManager()->GetTexture("fuego"));
        body.setOrigin(17.5f,17.5f);
     }
     else if(tipoBala==0){
        body.setTexture(AssetManager::getAssetManager()->GetTexture("fireball"));
        body.setOrigin(20.0f,15.5f);
     }


}
/*
Proyectil::Proyectil(sf::Vector2f pos):
animationHachaBoss( 0.1f,sf::Vector2u(4, 1),"flechas")
,animationBolaFuego(0.1f,sf::Vector2u(5,1),"fireball")
,direccion(sf::Vector2f(0,0))
{
    calculado=false;
    firstState=sf::Vector2f(pos.x,pos.y);
    lastState=firstState;
    body.setPosition(pos);
    body.setTexture(AssetManager::getAssetManager()->GetTexture("fireball"));
    speed=500.0f;
    derecha=true;
    existe=true;
    body.scale(sf::Vector2f(3.0f,3.0f));
    tipoBala=0;

}
*/
sf::Sprite Proyectil::getBody(){
    return body;
}

void Proyectil::Update(sf::Time elapsedTime){

    bool derecha=false;

    firstState=lastState;

    sf::Vector2f movement(0.f, 0.f);
    if(tipoBala>0){
        if(tipoBala == 1.0f){
            movement.y -= 500.0f;
        }
        else if(tipoBala == 2.0f){
            movement.y += 500.0f;
        }
        else if(tipoBala == 4.0f){
            movement.x -= 500.0f;

        }
        else if(tipoBala == 3.0f){
            movement.x += 500.0f;
            derecha=true;

        }
        else if(tipoBala == 5.0f){

            if(vary>0){
                movement.y +=300.0f;
            }
            else if (vary<0){
                movement.y -=300.0f;
            }
            if(varx>0){
                movement.x +=300.0f;
                derecha=true;
            }
            else if(varx<0){
                movement.x -=300.0f;
            }
        }
        else if(tipoBala ==6.0f ){
            Mover();

        }

     lastState += movement* elapsedTime.asSeconds();




     if(tipoBala>=1 && tipoBala<=4){
     Hacha.animar(0,elapsedTime,derecha, false);
     body.setTextureRect(Hacha.uvRect);
     }
     else if(tipoBala==5 || tipoBala==6){
     Boss.animar(0,elapsedTime,derecha, false);
     body.setTextureRect(Boss.uvRect);
     }

    }
    else if(tipoBala==0){
        Animar();
        Mover();
    }


}

void Proyectil::Render(float tick){
    body.setPosition(firstState.x*(1-tick)+lastState.x*tick,firstState.y*(1-tick)+lastState.y*tick);
}

void Proyectil::Animar()
{


     fila=0;
     BolaFuego.animar(fila, App::getApp()->getElapsedTime(), derecha, false);
     body.setTextureRect(BolaFuego.uvRect);



}

void Proyectil::Mover(){

    firstState=lastState;
    sf::Time elapsedTime = App::getApp()->getElapsedTime();

    sf::Vector2f movement(0.f, 0.f);

    if(calculado==false){
    direccion=Game::getGame()->getPlayer()->getHitb().getPosition() - body.getPosition() - Game::getGame()->getPlayer()->getHitb().getSize();
    direccion=App::getApp()->normalizar(direccion);
    calculado=true;
    }


    movement=direccion*speed;

    lastState += movement * elapsedTime.asSeconds();

}


void Proyectil::setexiste()
{
existe=false;
}

bool Proyectil::getexiste()
{
return existe;
}
