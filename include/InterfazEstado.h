#pragma once

class InterfazEstado
{
public:
    virtual void Init() = 0;   //initialize the state
        virtual void HandleInput() = 0;  //Handle all input on this particular state
        virtual void Update(float dt) = 0;  //update any variables and update game
        virtual void Draw(float dt) = 0;  //DT = delta : time difference between frames

        virtual void Pause(){}   //pause the game
        virtual void Resume(){}
};
