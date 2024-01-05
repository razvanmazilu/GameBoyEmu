#pragma once
#include<raylib.h>
#include<string>
#include"common.h"

class Button {
public:
    void SetName(String _name);
    String GetName();
    void SetPosition(Vector2 _pos);
    Vector2 GetPosition();
    void SetState(bool _state);
    bool GetState();

    void Push();
    bool IsPressed();
    void Draw();
    void DebugInfo(int verbosityLVL);

private:
    String name;
    Vector2 position;
    bool state;


};