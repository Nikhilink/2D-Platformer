#pragma once

#include "pch.h"

class WindowOptions
{
    public:
        std::string title;
        int width;
        int height;

        bool resizable;      // Raylib
        bool vSync;

        int fps;

        WindowOptions()
        {
            title = "Game";
            width = 1280;
            height = 720;
            resizable;
            vSync;
            fps = 60;
        }

        WindowOptions(std::string title, int width, int height): title(title),
                                                                 width(width),
                                                                 height(height)
        {
            resizable = true;
            vSync = true;

            fps = 60;
        }

        WindowOptions(std::string title, int width, int height, bool resizable, bool v_sync): title(title),
                                                                 width(width),
                                                                 height(height),
                                                                 resizable(resizable),
                                                                 vSync(v_sync)
        {
           fps = 60; 
        }

        WindowOptions(std::string title, int width, int height, int fps): title(title),
                                                                 width(width),
                                                                 height(height),
                                                                 fps(fps)
        {
            resizable = true;
            vSync = true;
        }                                                        
};