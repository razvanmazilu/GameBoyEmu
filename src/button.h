#pragma once
#include<raylib.h>
#include<string>
#include"common.h"

class Button {
public:
    void SetName(std::string _name);
    std::string GetName();
    void SetPosition(Vector2 _pos);
    Vector2 GetPosition();
    void SetState(bool _state);
    bool GetState();

    void Push();
    bool IsPressed();
    void Draw();
    void DebugInfo(int verbosityLVL);

private:
    std::string name;
    Vector2 position;
    bool state;


};